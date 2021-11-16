#include<bits/stdc++.h>
using namespace std;

#define MX 1000

int ara[MX][3]; // activity and cost table
double cost[MX][5];
double nt[MX][4];  // node info table

int main(){

    int i,j,n,m;

    freopen("part_critical_path.txt", "r", stdin);

    scanf("%d %d",&n, &m);

    for(i = 1; i <= n; i++){
        scanf("%d %d %d %lf", &ara[i][0], &ara[i][1], &ara[i][2], &cost[i][0]);
    }

    // forward pass calculation
    nt[1][1] = 0;
    for(i = 1; i <= n; i++){
        cost[i][1] = nt[ara[i][1]][1]; // est(k) = ent(s(k))
        cost[i][2] = cost[i][1] + cost[i][0]; // eft(k) = est(k) + t(k)
        nt[ara[i][2]][1] = max(nt[ara[i][2]][1], cost[i][2]); // ent(n) = max(lft(all activities terminating on node k))
    }

    // backword pass calculation

    for(i = 0; i <= m ;i++){
        nt[i][2] = INT_MAX;
    }
    nt[m][2] = nt[m][1];

    for(i = n; i >= 1; i--){
        cost[i][4] = nt[ara[i][2]][2]; // lft(k) = lnt(k)
        cost[i][3] = cost[i][4] - cost[i][0]; // lst(k) = lft(k) -t(k)
        nt[ara[i][1]][2] = min(nt[ara[i][1]][2], cost[i][3]); // lnt(n) = min(lst(all activities terminating on node k))
    }

    //  printing section
    puts("| Activity | S(k) | F(k)  | T(k)  | EST(k)  |  EFT(k) |  LST(k) |  LFT(k)  |");
    puts("............................................................................");
    for(i = 1; i <= n ; i++){
        printf("| %3d      | %3d  | %3d   | %5.2lf | %6.3lf  | %6.3lf  | %6.3lf  | %6.3lf   |\n",
               ara[i][0],ara[i][1],ara[i][2],cost[i][0],cost[i][1],cost[i][2],cost[i][3],cost[i][4]);
    }
    puts(".............................................................................\n");

    puts("| Nodes | ENT(k) | LNT(k) |  Slack |");
    puts("....................................");
    for(i = 1; i <= m; i++){
        nt[i][3] = abs(nt[i][2] - nt[i][1]); // calculating slack
        printf("| %3d   | %6.3lf | %6.3lf | %6.3lf |\n",i, nt[i][1],abs(nt[i][2]),nt[i][3]);
    }
    puts("....................................");

    return 0;
}
