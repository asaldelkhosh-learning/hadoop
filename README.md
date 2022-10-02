# Process

How to create process in C programming language?

## What do you need?

First you need to use the ```fork``` systemcall to create new process:

```C
int pid = fork();
```

Fork systemcall returns a zero value for child process (which we created right now) so we 
need to control the child and parent flow.

```C
if pid == 0 
{
    // write code here
}
```

Check the example:

```C
void createProcess(char *cmd)
{
    int pid = fork();
    if (pid == 0)
    {
        execlp(cmd, cmd, NULL);
    }
}
```

## Communication between processes

For transfring data between processes, we need to use channels. In channels you can send bytes of data
and get that data in the other end of channel.

### create channel

Create a channel with ```pipe``` systemcall which returns an Id for channel.

```C
int createChannel()
{
    int fd[2];

    pipe(fd);

    return fd[0];
}
```

### send data over channel

Do this with ```write``` systemcall.

```C
void sendDataOverChannel(int fd, char *data)
{
    write(fd, data, strlen(data));
}
```

### read data from channel

Do this with ```read``` systemcall.

```C
void getDataFromChannel(int fd, char *data)
{
    read(fd, data, 100);
}
```

## Run example

```shell
make run
```
