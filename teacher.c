
/*  timesup.c  */

   #include <stdio.h>
   #include <stdlib.h>
   #include <sys/signal.h>

     #define  EVER  ;;

     int times_up();
     int controlc_up();

     void main()
     {
        signal (SIGALRM, times_up);         /* go to the times_up function  */
        signal (SIGINT, controlc_up);         /* go to the times_up function  */
                                            /* when the alarm goes off.     */
        alarm (10);                         /* set the alarm for 10 seconds */

        for (EVER)                          /* endless loop.                */
           ;                                /* hope the alarm works.        */
     }

     int times_up(sig)
     int sig;                               /* value of signal              */
     {
        printf("Caught signal #< %d >\n", sig);
        printf("Time's up!  I'm outta here!!\n");
        exit(sig);                          /* return the signal number     */
     }

     int controlc_up(sig)
     int sig;                               /* value of signal              */
     {
        printf("Caught signal #< %d >\n", sig);
        printf("Control-Break was pressed.!\n");
        /*exit(sig);*/                          /* return the signal number     */
     }
