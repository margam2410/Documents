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
  
   // First get the limit on open files 
   getrlimit (RLIMIT_NOFILE, &rl); 
  
   printf("\n Default value is : %lld\n", (long long int)rl.rlim_cur); 
  
   // Change the limit 
   rl.rlim_cur = 4; // 3 are for stdin, stdout, stderr and one extra 
  
   // Now call setrlimit() to set the  
   // changed value. 
   setrlimit (RLIMIT_NOFILE, &rl); 
  
   // Again get the limit and check 
   getrlimit (RLIMIT_NOFILE, &rl); 
  
   printf("\n Default value now is : %lld\n", (long long int)rl.rlim_cur); 
  
  
   // Try opening more than one file 
  
   FILE *fp = NULL; 
  
   int i=0; 
  
   for (i=0; i<2; i++) 
   { 
       fp = NULL; 
       fp = fopen("test.txt","r"); 
       if(NULL == fp) 
       { 
           printf("\n fopen failed [%d]\n", i); 
           return -1; 
       } 
   } 
  
   return 0; 
 }

