#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork();
    if (pid > 0)
    {
        printf("I'm parent \n");

        // wait(0);
    }
    else
    {
        sleep(1);
        printf("I'm children \n");
    }
    return 0;
}