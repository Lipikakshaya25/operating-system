#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
printf("Before fork()\n");
pid_t p=fork();
if(p<0)
{
printf("fork FAILED\n");
}
else if(p==0)
{
printf("my id is:%d\n",getpid());
printf("my parents id is :%d \n",getppid());
}
else
{
printf("my id is:%d\n",getpid());
printf("done");
}}
