#include <sys/resource.h> 
 #include <sys/time.h> 
 #include <unistd.h> 
 #include <stdio.h> 
  
 int main () 
 { 
   // Struktur rlimit. 
   struct rlimit rl; 
  
   // Schauen, was Filesize für ein Limit hat
   getrlimit (RLIMIT_FSIZE , &rl); 
  
   printf("\n Default value is : %lld\n", (long long int)rl.rlim_cur); 
  
   // Change File-Size-Limit auf 2kb 
   rl.rlim_cur = 2000; 
  
   // Call setrlimit() um neuen Value zu setten
   setrlimit (RLIMIT_FSIZE , &rl); 
  
   // Gette das Limit und check 
   getrlimit (RLIMIT_FSIZE , &rl); 
  
   printf("\n Default value now is : %lld\n", (long long int)rl.rlim_cur); 
  
   // Simulation für große Datei 
   while (1){
    char sentence[1000];
    FILE *fptr;

    // File in writing-mode öffnen
    fptr = fopen("program.txt", "w");
    // exiting program 
    // if (fptr == NULL) {
    //    printf("Error!");
    //    exit(1);
    //}
    printf("Enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);
    for(int i=0;i<1000;i++){
        fprintf(fptr, "%s", sentence);
    }
    fclose(fptr);
   }
  
   return 0; 
 }