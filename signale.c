 #include <sys/resource.h> 
 #include <sys/time.h> 
 #include <unistd.h> 
 #include <stdio.h>
 #include <signal.h>
 #include <stdlib.h>
  
// Define the function to be called when ctrl-c (SIGINT) signal is sent to process
void signal_callback_handler(int signum)
{
   printf("Signal Nr. %d empfangen!\n",signum);
   switch (signum){
	case 24:
        printf("CPU-Limit erreicht!\n");
        break;
    case 25:
        printf("FileSize-Limit erreicht!\n");
        break;
    case 16:
        printf("StackSize-Limit erreicht!\n");
        break;
    default:
        break;
   }
   // Terminate program
   exit(signum);
}
int main () { 
struct rlimit rl;                    // Struktur rlimit.
char sentence[1000];
FILE *fptr;
int auswahl = 0;
int limitation = 0;

signal(SIGINT, signal_callback_handler);
signal(SIGSTKSZ, signal_callback_handler);
signal(SIGXFSZ, signal_callback_handler);
signal(SIGXCPU, signal_callback_handler);

printf("Limits und Signale\n");
printf("1 - CPU-Time\n");
printf("2 - Stack-Size\n");
printf("3 - File-Size\n");
printf("0 - Abbruch\n");

scanf("%d",&auswahl);

switch (auswahl){
    case 1:
        printf("CPU-Time!\n");
		
        getrlimit (RLIMIT_CPU, &rl);
        
		printf("Auf welchen Wert wollen Sie das Limit setzen?\n");
        scanf("%d",&limitation);
        rl.rlim_cur = limitation;
        setrlimit (RLIMIT_CPU, &rl);
		
        while (1);
        break;
    case 2:
        printf("Stack-Size\n");
		
		getrlimit (RLIMIT_STACK , &rl); 
		printf("\n Aktuelle Stack-Size ist : %lld\n", (long long int)rl.rlim_cur);
		
		printf("Auf welchen Wert wollen Sie das Limit des Stacks in Bytes setzen?\n");		
		scanf("%d",&limitation);
        rl.rlim_cur = limitation; 
		setrlimit (RLIMIT_STACK , &rl);
		
		getrlimit (RLIMIT_STACK, &rl); 
		printf("\n Aktuelle Stack-Size ist : %lld\n", (long long int)rl.rlim_cur); 
        
		while (1){
			/*char zeichen[5];
			strcpy(zeichen, "1234567"); Überlauf*/
		
			int zahl = 0;
			printf("Wie groß soll das Array sein?\n");
			scanf("%d",&zahl);
			int mat[10*zahl][10*zahl];
		
			/*int zahl = 0;
			printf("Wie oft soll sich der Stack erweitern?\n");
			scanf("%d",&zahl);
			char Stack[zahl-2];
		
			for(int i = 0; i<zahl;i++){
				Stack[i] = i;
			}*/
		}		
        break;
    case 3:
        printf("File-Size!\n");
		
        getrlimit (RLIMIT_FSIZE , &rl);     	// Schauen, was Filesize für ein Limit hat
        //printf("\n Aktuelle File-Size ist : %lld\n", (long long int)rl.rlim_cur); 
        
		printf("Auf welchen Wert wollen Sie das Limit der Datei in Bytes setzen?\n");
        scanf("%d",&limitation);
        rl.rlim_cur = limitation;             	// Change File-Size-Limit auf 2kb 
        setrlimit (RLIMIT_FSIZE , &rl);    		// Call setrlimit() um neuen Value zu setten
        
		//getrlimit (RLIMIT_FSIZE , &rl);   	// Gette das Limit und check
        //printf("\n Aktuelle File-Size ist : %lld\n", (long long int)rl.rlim_cur); 
        
		while (1){                        		// Simulation für große Datei 
            fptr = fopen("program.txt", "w");  	// File in writing-mode öffnen
            printf("Gib Satz ein..:\n");
            fgets(sentence, sizeof(sentence), stdin);
            for(int i=1;i<1000;i++){
                fprintf(fptr, "%s", sentence);
            }
            fclose(fptr);
        }
        break;
    case 0:
		printf("PROGRAMMENDE!\n");
        return 0;
    default:
        break;
   }

return 0; 
}
