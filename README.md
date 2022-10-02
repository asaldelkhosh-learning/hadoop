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
