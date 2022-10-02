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

void getDataFromChannel(int fd, char *data)
{
    read(fd, data, 100);
}

int createChannel()
{
    int fd[2];

    pipe(fd);

    return fd[0];
}

void closechannel(int fd)
{
    close(fd);
}

int main()
{
    createProcess("ls");
    createProcess("ps");
    createProcess("top");

    return 0;
}