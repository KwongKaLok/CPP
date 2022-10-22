#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
// fflush(stdout): ensure the output is printed on the console
int main() {
    int x = 0;
    if (fork()!=0) {
        x = x + 1;
        wait(NULL);
        printf("The value x in process 1 is %d\n", x); 
        fflush(stdout);
    } else if (fork() ==0) {
        x = x + 1;
        wait(NULL);
        printf("The value x in process 2 is %d\n", x); 
        fflush(stdout);
    } else {
        x = x + 1;
        printf("The value x in process 3 is %d\n", x); 
        fflush(stdout);
    }
    return 0;
}
