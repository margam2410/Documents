/* to find cpu limits */
#include<stdio.h>
#include<sys/types.h>
#include<sys/resource.h>
#include<sys/time.h>
#include<error.h>
int main()
{
	struct rlimit limit;
	if(getrlimit(RLIMIT_CPU,&limit)<0)
	
		fprintf(stderr,"%s \n",strerror(errno));
	else
	
		printf("%-14s","RLIMIT_CPU");
	
	if(limit.rlim_cur == RLIM_INFINITY)
		printf("(infinity)");
	else
		printf("%10ld",limit.rlim_cur);
	if(limit.rlim_max == RLIM_INFINITY)
		printf("(infinity)\n");
	else
		printf("10ld \n",limit.rlim_max);
		return 0;
}
