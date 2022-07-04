#include <sys/resource.h> 
 #include <sys/time.h> 
 #include <unistd.h> 
 #include<stdio.h> 
  
 int main () 
 { 
   // Define and object of structure 
   // rlimit. 
   struct rlimit rl; 
  
   // First get the time limit of Stack 
   getrlimit (RLIMIT_STACK , &rl); 
  
   printf("\n Default value is : %lld\n", (long long int)rl.rlim_cur); 
  
   // Change the stack limit 
   rl.rlim_cur = 100; 
  
   // Now call setrlimit() to set the  
   // changed value. 
   setrlimit (RLIMIT_STACK , &rl); 
  
   // Again get the limit and check 
   getrlimit (RLIMIT_STACK, &rl); 
  
   printf("\n Default value now is : %lld\n", (long long int)rl.rlim_cur); 
  
   // Simulate work 
   while (1); 
  
   return 0; 
 }