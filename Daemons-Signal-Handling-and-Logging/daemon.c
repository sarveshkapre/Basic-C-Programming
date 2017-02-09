#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

//Timestamo function to calculate date and time and display output in the log file.
char *time_stamp(){

char *timestamp = (char *)malloc(sizeof(char) * 256);
time_t ltime;
ltime=time(NULL);
struct tm *tm;
tm=localtime(&ltime);

sprintf(timestamp,"Date: %04d-%02d-%02d   Time: %02d:%02d:%02d", tm->tm_year+1900, tm->tm_mon, 
    tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
return timestamp;
}


void signal_handler(int signal) {
FILE *fp= NULL;
// Open log file in append mode [ Append; open for writing at end-of-file or create for writing if the 
// file does not exist. ]

fp = fopen ("Log.txt", "a+");

printf("Caught signal %d\t", signal);
if (signal == SIGTSTP)
{ 
	printf("SIGTSTP"); 
	fprintf(fp, "Signal Terminal Stop - SIGTSTP 20 - Terminal stop [suspend] (Ctrl-Z) Timestamp: %s\n",time_stamp());
	
}
else if (signal == SIGQUIT)
{ 
	printf("SIGQUIT");  
	fprintf(fp, "Signal Quit - SIGQUIT 3 - Quit Timestamp: %s\n",time_stamp());
	
	exit(0); 
}
else if (signal == SIGTRAP)
{ 
	printf("SIGTRAP"); 
	fprintf(fp, "Signal Trap- SIGTRAP 5 - Trace/breakpoint trap Timestamp: %s\n",time_stamp());
	
}
else if (signal == SIGABRT)
{ 
	printf("SIGABRT"); 
	fprintf(fp, "Signal Abort - SIGABRT 6 - Process aborted Timestamp: %s\n",time_stamp());
	
	exit(0); 
}
else if (signal == SIGKILL)
{ 
	printf("SIGKILL"); 
	fprintf(fp, "Signal Kill - SIGKILL 9 Kill Timestamp: %s\n",time_stamp());
	
	exit(0); 
}
else if (signal == SIGTERM)
{ 
	printf("SIGTERM"); 
	fprintf(fp, "Signal Terminate - SIGTERM 15 - Termination (sent by kill command) Timestamp: %s\n",time_stamp());
	
	exit(0); 
}
else if (signal == SIGCONT)
{ 
	printf("SIGCONT"); 
	fprintf(fp, "Signal Continue - SIGCONT 18 - Continue if stopped Timestamp: %s\n",time_stamp());
	
}
else if (signal == SIGINT)
{ 
	printf("SIGINT"); 
	fprintf(fp, "Signal Interrupt - SIGINT 2 - Interrupt (Ctrl-C) Timestamp: %s\n",time_stamp());
	
}
printf("\n");

}

//Main fucnton to spawn the daemon 
int main() {
daemon(1,1);
signal(SIGQUIT, signal_handler); 
signal(SIGTSTP, signal_handler); 
signal(SIGTRAP, signal_handler); 
signal(SIGABRT, signal_handler);
signal(SIGKILL, signal_handler); 
signal(SIGTERM, signal_handler); 
signal(SIGCONT, signal_handler);
signal(SIGINT,  signal_handler); 
while(100) {}
}


