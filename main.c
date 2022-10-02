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
    createProcess("ls");
    createProcess("ps");
    createProcess("top");

    return 0;
}