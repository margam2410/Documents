#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
  // Define and object of structure
  // rlimit.
  struct rlimit rl;

  // First get the limit on number of child processes
  getrlimit (RLIMIT_NPROC, &rl);

  printf("\n Default value is : %lld\n", (long long int)rl.rlim_cur);

  // Change the limit
  rl.rlim_cur = 0; // Now we do not want this process to have any child process

  // Now call setrlimit() to set the 
  // changed value.
  setrlimit (RLIMIT_NPROC, &rl);

  // Again get the limit and check
  getrlimit (RLIMIT_NPROC, &rl);

  printf("\n Default value now is : %lld\n", (long long int)rl.rlim_cur);


  // Try creating a process

  if( -1 == fork())
  {
      printf("\n Creating a child process failed\n");
  }

  return 0;
}

