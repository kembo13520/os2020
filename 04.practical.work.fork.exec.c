#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int pid1 = fork();
    if(pid1 == 0)
    {
        printf("I am child, execute ps -ef\n");
        char *args[] = {"/bin/ps", "-ef", NULL};
	    execvp(args[0], args);
        int pid2 = fork();
        if(pid2 == 0)
        {
           
		    printf("I am child, execute free -h\n");
            char *args[] = {"/usr/bin/free", "-h", NULL};
            execvp(args[0], args);
        }
        else
        {
            printf("I am father of child process, my child is %d\n",pid2);
            wait(NULL);
        }
    }
    else
    {
        wait(NULL);
        printf("I am father, my 1st child is %d\n",pid1);
    }
    return 0;
}
