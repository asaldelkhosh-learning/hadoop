#include <stdio.h>

void createProcess(char *cmd)
{
    int pid = fork();
    if (pid == 0)
    {
        execlp(cmd, cmd, NULL);
    }
}

int main()
{
    createprocess("ls");
    createprocess("ps");
    createprocess("top");

    return 0;
}