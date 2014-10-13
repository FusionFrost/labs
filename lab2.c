#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <math.h>
#include "time.h"

void getTime(struct tm **time_f); //функция получение времени в настоящий момент

void getTime(struct tm **time_f)
{
  time_t sec;
  time(&sec);
  *time_f = localtime(&sec);
}


int main() {
   struct tm *time;
   getTime(&time); //получаем время
   int pid; //родительский процесс
   int status, died,i;
   int count_of_process = pow(2,time->tm_hour); //кол-во процессов
   for(i = 0;i< count_of_process; i++)
  {
   pid=fork(); 
   switch(pid) {
   case -1: printf("can't fork\n");
            exit(-1);
   case 0 : 
            getTime(&time);
            //printf("   My PID is %d\n", getpid());
            sin((3.1415 *(time->tm_min) )/ 15 ); //вычисления
      
            exit(0);

   default: 
            
        
      
            if (pid & 1)
               kill(pid,SIGKILL);
            died= wait(&status);
            printf("Process PID and status: %d , %d\n",getpid(),died);
  }

}
return 0;
}
