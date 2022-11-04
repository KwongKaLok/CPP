#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;
    printf("%d\n", getpid());
    pid = fork();
    if (pid == 0)
    {
        printf("%d\n", getpid());
    }

    return 0;
}
