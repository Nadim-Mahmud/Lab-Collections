Some `MPI` installtion method's for learning purposes(Perallel processing course) provided below, try one after another until succeed. Good Luck guys!

# MPI installation process for Windows :

1. **Niaz's method :** https://youtu.be/0NdRTs_0YpE (it didn't work for me .NET framework related problem may be)

2. Install on Visual Studio (If you are using it already) (Search on you tube)

3. **Install WSL :**
   * WSL is Linux command-line interface in windows .
   * download it from : https://docs.microsoft.com/en-us/windows/wsl/install-manual Then find installation command for power-shell from the bottom of the page.
   * Go to the bottom of the post to know how to install mpi on this(Linux) system.
   * follow this link : "https://medium.com/@amithkk/setting-up-visual-studio-code-and-wsl-for-mpi-develoment-8df55758a31c" to integrate it with VScode.(Optional)

4. **Install virtual box :**
   * install VB
   * install any Linux distro
   * install MPI on Linux as described bellow

# MPI installation process for Linux :

   * use `sudo apt-get update` to update the system 
   * use `sudo apt install openmpi-bin libopenmpi-dev` to install mpi
   * use `echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope` to resolve some problem  (may be only for wsl)
   * go to your projects folder
   * `mpicc name.c -o mpi.o` (compile c file)
   * `mpiCC name.cpp -o mpi.o` (compile cpp file)
   * `mpirun -np 4 ./mpi.o` (run mpi)       

# Additional tricks for WSL :
   * `cd ..` repeatedly until reaching the root folder
   * mnt contains all of your drive
   * use cd to go to your desired folder
