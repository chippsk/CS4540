/* Course: CS 4540 – Fall 2014
Assignment 4 - Problem 1
Name: Kyle Chipps
E-mail: kyle.d.chipps@wmich.edu
Submitted:
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <pthread.h>

#define SEED 35791246
#define NR_PTS 10000000
#define NR_THREADS 5;

/*Variables used by threads */
int circleCount;
int totalCount;

/*Hard coded actual pi value for comparision at the end */
float actualPi = 3.14159265358979323846264338327950288419716939937510;

pthread_mutex_t lock;

void* generate_points();

/*Main will spin up all the threads and calculate an estimation of pi at the end. */
int main(){

   /*Initialize the globals to avoid tomfoolary. */
   circleCount = 0;
   totalCount = 0;
   
   srand(SEED);


   /*Declare all our threads  */
   pthread_t thread1;
   pthread_t thread2;
   pthread_t thread3;
   pthread_t thread4;
   pthread_t thread5;

   /*Initialize mutex lock */
   if(pthread_mutex_init(&lock,NULL) != 0){
      fprintf(stderr,"Mutex init failed\n");
      return -1;
   }

   /*Spin us up some threads */
   if(pthread_create(&thread1,NULL,generate_points,NULL)){
      fprintf(stderr,"Error creating get_avg thread\n");
      return 1;
   }

   if(pthread_create(&thread2,NULL,generate_points,NULL)){
      fprintf(stderr,"Error creating get_avg thread\n");
      return 1;
   }

   if(pthread_create(&thread3,NULL,generate_points,NULL)){
      fprintf(stderr,"Error creating get_avg thread\n");
      return 1;
   }

   if(pthread_create(&thread4,NULL,generate_points,NULL)){
      fprintf(stderr,"Error creating get_avg thread\n");
      return 1;
   }

   if(pthread_create(&thread5,NULL,generate_points,NULL)){
      fprintf(stderr,"Error creating get_avg thread\n");
      return 1;
   }

   /*Join us up some threads */

   if(pthread_join(thread1,NULL)){
      fprintf(stderr,"Error joining thread\n");
      return 2;
   }

   if(pthread_join(thread2,NULL)){
      fprintf(stderr,"Error joining thread\n");
      return 2;
   }

   if(pthread_join(thread3,NULL)){
      fprintf(stderr,"Error joining thread\n");
      return 2;
   }

   if(pthread_join(thread4,NULL)){
      fprintf(stderr,"Error joining thread\n");
      return 2;
   }

   if(pthread_join(thread5,NULL)){
      fprintf(stderr,"Error joining thread\n");
      return 2;
   }

   /*Print statement block that shows number of valid points, total points, the estimate of pi and the actual value of pi */
   fprintf(stderr,"The amount of valid points (circleCount) is %d\n",circleCount);
   fprintf(stderr,"The total number of points generated is %d\n",totalCount);
   //pi=(float)circleCount/totalCount*4;
   //fprintf(stderr,"Estimate of pi after all threads have exited\n %.20f \n",pi);
   estimate_pi(totalCount);
   fprintf(stderr,"Acutal pi is \n %.20f \n", actualPi);
   
   pthread_mutex_destroy(&lock);
   return 0;
}

/*This method is what the threads run when spun up.  It creates two random x,y pairs and uses a global define NR_PTS.  
It checks to see if they are valid, updates a count then updates a global variable within a mutex lock so many threads can run*/
void* generate_points(){
   
   int i;
   double x,y,z;
   int count;
   count = 0;

   for ( i=0; i<NR_PTS; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      /*Using the distance formula to find if they are a valid set of coords */
      z = x*x+y*y;
      if (z<=1){
        count++; 
      }  
   }

   /*Critial Section */
   pthread_mutex_lock(&lock);
   circleCount += count;
   totalCount +=NR_PTS;
   estimate_pi(totalCount);
   pthread_mutex_unlock(&lock);
   /*End Critial Section */

}

/*Esitmates the value of pi based on the total entries givien.  This allows us to calculate at the end of each thread along with a total after
all the threads have executed and exited. */
int estimate_pi(int totalTries){
   float pi;
   pi = (float)circleCount/totalTries*4;
   fprintf(stderr,"Estimate of pi \n %.20f \n",pi);
}