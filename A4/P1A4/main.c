#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <pthread.h>

#define SEED 35791246
#define NR_PTS 10000000
#define NR_THREADS 5;

int circleCount;
int totalCount;
float actualPi = 3.14159265358979323846264338327950288419716939937510;
pthread_mutex_t lock;

void* generate_points();

int main(){
   circleCount = 0;
   totalCount = 0;
   double x,y;
   float pi;
   srand(SEED);

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

   //perform the actual calculation that esimates pi
   //it will be 50 million for 5 threads.  do this better later.
   fprintf(stderr,"The amount of valid points (circleCount) is %d\n",circleCount);
   fprintf(stderr,"The total number of points generated is %d\n",totalCount);
   //pi=(float)circleCount/totalCount*4;
   //fprintf(stderr,"Estimate of pi after all threads have exited\n %.20f \n",pi);
   estimate_pi(totalCount);
   fprintf(stderr,"Acutal pi is \n %.20f \n", actualPi);
   
   pthread_mutex_destroy(&lock);
   return 0;
}

void* generate_points(){
   
   int i;
   double x,y,z;
   int count;
   count = 0;

   for ( i=0; i<NR_PTS; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      //fprintf(stderr,"X is %g",x);
      //fprintf(stderr,"Y is %g",y);
      //Square results and check to see if they are less than 1
      z = x*x+y*y;
      //check to see if they are valid, (on the circle)
      if (z<=1){
        count++; 
      }  
   }
   //update circleCount
   pthread_mutex_lock(&lock);
   circleCount += count;
   totalCount +=NR_PTS;
   estimate_pi(totalCount);
   pthread_mutex_unlock(&lock);
}

int estimate_pi(int totalTries){
   float pi;
   pi = (float)circleCount/totalTries*4;
   fprintf(stderr,"Estimate of pi \n %.20f \n",pi);
}