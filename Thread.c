
#include "cmsis_os.h"                                           // CMSIS RTOS header file
#define PI 3.142857
#include <math.h>
#include <stdio.h>

/*
//comment out the first part,to run the second part of the lab

unsigned int countb =0;
unsigned int num = 10; 
unsigned int i, counter,sum = 0;
unsigned int a;
 
  
void Thread1 (void const *argument); // thread function
void Thread2 (void const *argument); // thread function
void Thread3 (void const *argument);

//all threads are of equal priority because implementing round-robin
osThreadId tid_Thread; // thread id
osThreadDef (Thread1, osPriorityNormal, 1, 0);                   // thread object

osThreadId tid2_Thread; // thread id
osThreadDef (Thread2, osPriorityNormal, 1, 0);                   // thread object

osThreadId tid3_Thread; //thread id 
osThreadDef (Thread3, osPriorityNormal,1,0);

int Init_Thread (void) {

  tid_Thread = osThreadCreate (osThread(Thread1), NULL);
	tid2_Thread = osThreadCreate (osThread(Thread2), NULL);
	tid3_Thread = osThreadCreate (osThread(Thread3), NULL);
  if(!tid_Thread) return(-1);
  
  return(0);
}

//thread to considers numbers from 0 to 5 and finds the modulus of each number
//countb indicates whether the number is positive or negative 
void Thread2 (void const *argument) {
			for(;;){
			
    for (i = 0; i < 5 ; i++)
			{
		countb = i % 2;
			
		}
			}
  	
  }

//thread1 indefinitely calculates the value of sum plus num where num is 10 and sum starts with 0
void Thread1 (void const *argument) {
	 for(;;) {
   sum = sum + num;                                        
}
	 }
	 
//thread3 indefinitely increments counter and then adds ten to counter. 
void Thread3 (void const *argument) {
	 for(;;) {
   counter++;
	a = counter + 10;
		                                       
}
	} 
	 */
	 double tAcount, tBcount, tCcount, tEcount;
	 double tDcount = 1;
	 int x =0;
	 int n,nc,g,b,e = 1;
	  int r = 2;
	 
void ThreadA (void const *argument); // thread function
void ThreadB (void const *argument); 
void ThreadC (void const *argument);
void ThreadD (void const *argument);
void ThreadE (void const *argument);


//priority level changes for each thread depending on table 1 from lab3
//threads A and D are of equal priority, thread B and E are of equal priority and thread C is the highest priority
osThreadId tid_Thread; // thread id
osThreadDef (ThreadA, osPriorityNormal, 1, 0);                   // thread object

osThreadId tid2_Thread; // thread id
osThreadDef (ThreadB, osPriorityBelowNormal, 1, 0);                   // thread object

osThreadId tid3_Thread; //thread id 
osThreadDef (ThreadC, osPriorityAboveNormal,1,0);

osThreadId tid4_Thread; //thread id 
osThreadDef (ThreadD, osPriorityNormal,1,0);

osThreadId tid5_Thread; //thread id 
osThreadDef (ThreadE, osPriorityBelowNormal,1,0);

int Init_Thread (void) {

  tid_Thread = osThreadCreate (osThread(ThreadA), NULL);
	tid2_Thread = osThreadCreate (osThread(ThreadB), NULL);
	tid3_Thread = osThreadCreate (osThread(ThreadC), NULL);
	tid4_Thread = osThreadCreate (osThread(ThreadD), NULL);
	tid5_Thread = osThreadCreate (osThread(ThreadE), NULL);
  if(!tid_Thread) return(-1);
  
  return(0);
}
//created a factorial function which can be used to implement thread B and D
double fact (int counter1){
   double counter2 = 1; 
	while ( counter1 > 0){
	 counter2 = counter1 * counter2;
		counter1 = counter1 - 1;
	}
	return counter2;

}
//ThreadA has a sum, tAcount which calculates the sum of (x+ (x+2)) for x =0 to x = 256
//isThreadYield() allows switch between threads and osThreadTerminate(tid_Thread) 
//terminates the thread once total sum is calculated. 
void ThreadA (void const *argument) {
	  
   for (x = 0; x <= 256; x++){
	      tAcount = tAcount + (x + (x+2));
		  osThreadYield();
	 }  
	 osThreadTerminate(tid_Thread);
	 
}

//In threadB, the sum, tBcount is calculated by using the factorial and built in pow functions 
void ThreadB (void const *argument) {
	  
   for (n = 1; n <= 16; n++){
		 
	    tBcount = tBcount + (pow(2.0, (double)(n)))/fact(n);
		    osThreadYield();
	 }   
osThreadTerminate(tid2_Thread);	 
}
//In threadc, the for loop calclates the sum of (n+1)/n for each value of nc from 1 to 16 
void ThreadC (void const *argument) {
	  
   for (nc = 1; nc <= 16; nc++){
	      tCcount = tCcount + (double)(nc+1)/nc;
		    osThreadYield();
	 } 
osThreadTerminate(tid3_Thread);	 
}

//In threadD, the pow and facotiral functions are once again used along with a for loop
//to calculate the sum tDcount 
void ThreadD (void const *argument) {
	  
   for (g =1; g < 6; g++){
	     tDcount = tDcount + pow(5.0, (double)g)/ fact(g);
	     osThreadYield();
	 }
	  
osThreadTerminate(tid4_Thread);	
}
//for threadE, pi was globally defined, and the for loop and pow functions were used 
//to calculate the sum tEcount 
void ThreadE (void const *argument) {
	 
   for ( e = 1; e < 13; e++){
	    tEcount = tEcount + ((double)e *PI * (double)pow(r,2));
		 osThreadYield();
	 }
osThreadTerminate(tid5_Thread);
	 }                                       

