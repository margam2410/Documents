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
  
   // First get the limit on memory 
   getrlimit (RLIMIT_AS, &rl); 
  
   printf("\n Default value is : %lld\n", (long long int)rl.rlim_cur); 
  
   // Change the limit 
   rl.rlim_cur = 100; 
  
   // Now call setrlimit() to set the  
   // changed value. 
   setrlimit (RLIMIT_AS, &rl); 
  
   // Again get the limit and check 
   getrlimit (RLIMIT_AS, &rl); 
  
   printf("\n Default value now is : %lld\n", (long long int)rl.rlim_cur); 
  
  
   // Try to allocate more memory than the set limit 
   char *ptr = NULL; 
   ptr = (char*) malloc(1024); 
   if(NULL == ptr) 
   { 
       printf("\n Memory allocation failed\n"); 
       return -1; 
   } 
  
  
   free(ptr); 
  
   return 0; 
 }
