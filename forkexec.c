'#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	char* cmnd="ls";
	char* argument[]={"ls","-l",NULL};
	printf("before execvp()\n");
	pid_t p=fork();
	if(p==0)
	{
		printf("child process\n");
		int status=execvp(cmnd,argument);
		if(status==-1)
		{
			printf("terminated\n");
		}
		else
		{
			printf("parent process\n");
			printf("done\n");
		}
	}
}
