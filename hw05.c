#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define ERR    (-1)             /* indicates an error condition */

int times_up();
int controlc_up();
void Who();
void Uptime();

void main(){
	signal (SIGALRM, times_up);         /* go to the times_up function  */
    signal (SIGINT, controlc_up);         /* go to the times_up function  */
                                        /* when the alarm goes off.     */
    alarm (10);                         /* set the alarm for 10 seconds */

    for (;;)                          /* endless loop.                */
       ;                                /* hope the alarm works.        */
}

int times_up(sig)
 int sig;                               /* value of signal              */
 {
 	alarm (10);
 	ChildProcess(Who);
 	ChildProcess(Uptime);
 }

 int controlc_up(sig)
 int sig;                               /* value of signal              */
 {
    ChildProcess(Who);
 	ChildProcess(Uptime);
 }

 void ChildProcess( void (*Opt)()){
 	int pid;
 	int exit_sig;
 	if (( pid = fork () ) == ERR)        /* create 1st child   */
	{
	    perror (" ");
	    exit (ERR);
	}

	if( pid == 0 ){
		Opt();
		exit(0);
	}
	else{
		waitpid(pid);
	}

 }

 void Who(){
 	execl ("/usr/bin/who", "who", (char *) NULL);
 }

 void Uptime(){
 	execl ("/usr/bin/uptime", "uptime", (char *) NULL);
 }



