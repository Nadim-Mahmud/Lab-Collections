#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_THREADS 1024
#define MAX_RANDOM 65535

int count_member = 0,count_insert = 0,count_delete = 0,n = 0,m = 0,thread_count = 0;

float m_insert_frac = 0.0, m_delete_frac = 0.0, m_member_frac = 0.0;

float m_insert = 0.0, m_delete = 0.0, m_member = 0.0;

struct list_node_s *head = NULL;
pthread_mutex_t mutex;

struct list_node_s {
    int data;
    struct list_node_s *next;
};

int Insert(int value, struct list_node_s **head_pp);

int Delete(int value, struct list_node_s **head_pp);

int Member(int value, struct list_node_s *head_p);

double CalcTime(struct timeval time_begin, struct timeval time_end);

void getInput(int argc, char *argv[]);

void *Thread_Operation();


int main(int argc, char *argv[]) {

    getInput(argc, argv);

    pthread_t *thread_handlers;
    thread_handlers = malloc(sizeof(pthread_t) * thread_count);

    struct timeval time_begin, time_end;
    m_insert = m_insert_frac * m;
    m_delete = m_delete_frac * m;
    m_member = m_member_frac * m;

    int i = 0;
    while (i < n) {
        if (Insert(rand() % 65535, &head) == 1)
            i++;
    }

    pthread_mutex_init(&mutex, NULL);

    gettimeofday(&time_begin, NULL);

    i = 0;
    while (i < thread_count) {
        pthread_create(&thread_handlers[i], NULL, (void *) Thread_Operation, NULL);
        i++;
    }

    i = 0;
    while (i < thread_count) {
        pthread_join(thread_handlers[i], NULL);
        i++;
    }

    gettimeofday(&time_end, NULL);

    pthread_mutex_destroy(&mutex);

    printf("Linked List with a single mutex Time Spent : %.6f secs\n", CalcTime(time_begin, time_end));

    return 0;
}


int Member(int value, struct list_node_s *head_p) {
    struct list_node_s *current_p = head_p;

    while (current_p != NULL && current_p->data < value)
        current_p = current_p->next;

    if (current_p == NULL || current_p->data > value) {
        return 0;
    }
    else {
        return 1;
    }

}

int Insert(int value, struct list_node_s **head_pp) {
    struct list_node_s *curr_p = *head_pp;
    struct list_node_s *pred_p = NULL;
    struct list_node_s *temp_p = NULL;

    while (curr_p != NULL && curr_p->data < value) {
        pred_p = curr_p;
        curr_p = curr_p->next;
    }

    if (curr_p == NULL || curr_p->data > value) {
        temp_p = malloc(sizeof(struct list_node_s));
        temp_p->data = value;
        temp_p->next = curr_p;

        if (pred_p == NULL)
            *head_pp = temp_p;
        else
            pred_p->next = temp_p;

        return 1;
    }
    else
        return 0;
}

int Delete(int value, struct list_node_s **head_pp) {
    struct list_node_s *curr_p = *head_pp;
    struct list_node_s *pred_p = NULL;

    while (curr_p != NULL && curr_p->data < value) {
        pred_p = curr_p;
        curr_p = curr_p->next;
    }

    if (curr_p != NULL && curr_p->data == value) {
        if (pred_p == NULL) {
            *head_pp = curr_p->next;
            free(curr_p);
        }
        else {
            pred_p->next = curr_p->next;
            free(curr_p);
        }

        return 1;
    }
    else
        return 0;
}

void getInput(int argc, char *argv[]) {

    if (argc != 7) {
        printf("Please give the command: ./serial_linked_list <n> <m> <thread_count> <mMember> <mInsert> <mDelete>\n");
        exit(0);
    }

    n = (int) strtol(argv[1], (char **) NULL, 10);
    m = (int) strtol(argv[2], (char **) NULL, 10);
    thread_count = (int) strtol(argv[3], (char **) NULL, 10);

    m_member_frac = (float) atof(argv[4]);
    m_insert_frac = (float) atof(argv[5]);
    m_delete_frac = (float) atof(argv[6]);

    if (thread_count <= 0 || thread_count > MAX_THREADS) {
        printf("Please give provide a valid number of threads in the range of 0 to %d\n", MAX_THREADS);
        exit(0);
    }

    if (n <= 0 || m <= 0 || m_member_frac + m_insert_frac + m_delete_frac != 1.0) {
        printf("Please give the command with the arguements: ./serial_linked_list <n> <m> <mMember> <mInsert> <mDelete>\n");

        if (n <= 0)
            printf("Please provide a valid number of nodes for the linked list (value of n)\n");

        if (m <= 0)
            printf("Please provide a valid number of operations for the linked list (value of m)\n");

        if (m_member_frac + m_insert_frac + m_delete_frac != 1.0)
            printf("Please provide valid fractions of operations for the linked list (value of mMember, mInsert, mDelete)\n");

        exit(0);
    }
}

void *Thread_Operation() {

    int count_tot = 0;

    int finished_member = 0;
    int finished_insert = 0;
    int delete_finished = 0;

    while (count_tot < m) {

        int random_value = rand() % MAX_RANDOM;

        int random_select = rand() % 3;

        if (random_select == 0 && finished_member == 0) {

            pthread_mutex_lock(&mutex);
            if (count_member < m_member) {
                Member(random_value, head);
                count_member++;
            }else
                finished_member =1;
            pthread_mutex_unlock(&mutex);
        }

        if (random_select == 1 && finished_insert == 0) {

            pthread_mutex_lock(&mutex);
            if (count_insert < m_insert) {
                Insert(random_value, &head);
                count_insert++;
            }else
                finished_insert =1;
            pthread_mutex_unlock(&mutex);
        }

        else if (random_select == 2 && delete_finished == 0) {

            pthread_mutex_lock(&mutex);
            if (count_delete < m_delete) {
                Delete(random_value, &head);
                count_delete++;
            }else
                delete_finished =1;
            pthread_mutex_unlock(&mutex);
        }

        count_tot = count_insert + count_member + count_delete;
    }
    return NULL;
}

double CalcTime(struct timeval time_begin, struct timeval time_end) {

    return (double) (time_end.tv_usec - time_begin.tv_usec) / 1000000 + (double) (time_end.tv_sec - time_begin.tv_sec);
}
