#include <stdio.h>

void createProcess(char *cmd)
{
    int pid = fork();
    if (pid == 0)
    {
        execlp(cmd, cmd, NULL);
    }
}

void sendDataOverChannel(int fd, char *data)
{
    write(fd, data, strlen(data));
}

int createChannel()
{
    int fd[2];
    pipe(fd);
    return fd[0];
}

int main()
{
    createProcess("ls");
    createProcess("ps");
    createProcess("top");

    return 0;
}