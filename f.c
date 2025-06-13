#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t   pid;
    int     status;
    char    *args[3];

    pid = fork();
    args[0] = "/bin/ls";
    args[1] = "-la";
    args[2] = NULL;
    if (pid < 0)
        return (perror("fork failed"), 1);
    else if (pid == 0)
    {
        execv("/bin/ls", args); // In child process
        return (perror("execv failed"), 1);
    }
    else
    {
        waitpid(pid, &status, 0); // In parent process
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
            printf("Child executed /bin/ls successfully.\n");
        else
            printf("Child failed to execute /bin/ls.\n");
    }
    return 0;
}
