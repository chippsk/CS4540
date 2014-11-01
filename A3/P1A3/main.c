/* Course: CS 4540 – Fall 2014
// Assignment 3 - Problem 1
// Name: Kyle Chipps
// E-mail: kyle.d.chipps@wmich.edu
 Submitted: 
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX 25

typedef struct t_list{
	int *array;
	int size;
}List;

void* get_avg(void* pt);
void* get_max(void* pt);
void* get_min(void* pt);
/*Global Variables for average, maximum and minimum*/
int max = 0;
int min = 0;
float avg = 0;

/*Main is responsible for getting user input about how many integers the user
wants to enter.  With that information, main will put it into a struct, and use the 
struct to create threads that calculate the average, minimum and maximum. */
int main(void){
	char buffer[MAX];
	List listNums;
	List *ptrList = &listNums;
	/*Get amount of numbers to be comupted */
	fprintf(stderr,"Enter the amount of integers you want to enter ");
	fgets(buffer,sizeof(buffer),stdin);

	/*Get list of numbers and put them in an array */
	int amount = atoi(buffer);

	/*Must allocate size of struct plus amount of space for array */
	fprintf(stderr,"Size of array is %lu\n", amount * sizeof(int));
	listNums.array = malloc(amount * sizeof(int));
	listNums.size = amount;

	int i;
	for (i=0;i<amount;i++){
		fprintf(stderr,"Enter a value ");
		fgets(buffer,sizeof(buffer),stdin);
		listNums.array[i] = atoi(buffer);
	}

	int j;
	for(j=0;j<amount;j++){
		fprintf(stderr,"Array at location %d is %d\n", j, listNums.array[j]);
	}

	/*Spin us up some threads*/
	pthread_t thread;

	if(pthread_create(&thread,NULL,get_avg,(void*) ptrList)){
		fprintf(stderr,"Error creating get_avg thread");
		return 1;
	}

	if(pthread_create(&thread,NULL,get_max,(void*) ptrList)){
		fprintf(stderr,"Error creating get_max thread");
		return 1;
	}

	if(pthread_create(&thread,NULL,get_min,(void*) ptrList)){
		fprintf(stderr,"Error creating get_max thread");
		return 1;
	}

	/*Join the threads*/
	if(pthread_join(thread,NULL)){
		fprintf(stderr,"Error joining thread\n");
		return 2;
	}
	/*Output from the global variables*/
	fprintf(stderr,"The average is %.6f\n",avg);
	fprintf(stderr,"The minimum is %d\n",min);
	fprintf(stderr,"The maximum is %d\n",max);

	/*Free our memory*/
	free(listNums.array);
}

/*get_avg takes void star pointer, turns it into a struct given by pthread create, calculates average of
all the integers in the struct array.  It then updates the global variable */
void* get_avg(void* pt){
	List *ptr = (List*) pt;
	float sum;
	int i;
	sum = 0.0;

	for(i=0;i<ptr->size;i++){
		sum += ptr->array[i];
	}
	avg = (sum / ptr->size);
	fprintf(stderr,"average in avg is %.6f\n",avg);
}

/*get_max takes void star pointer, turns it into a struct given by pthread create, calculates maximum of
all the integers in the struct array.  It then updates the global variable */
void* get_max(void* pt){
	List *ptr = (List*) pt;
	int largest = ptr->array[0];
	int i;

	for(i=0;i<ptr->size;i++){
		if(largest < ptr->array[i]){
			largest = ptr->array[i];
		}
	}
	max = largest;
	fprintf(stderr,"maximum in max is %d\n",max);
}

/*get_min takes void star pointer, turns it into a struct given by pthread create, calculates minimum of
all the integers in the struct array.  It then updates the global variable */
void* get_min(void* pt){
	List *ptr = (List*) pt;
	int smallest = ptr->array[0];
	int i;

	for(i=0;i<ptr->size;i++){
		if(smallest >  ptr->array[i]){
			smallest = ptr->array[i];
		}
	}
	min = smallest;
	fprintf(stderr,"minimum in min is %d\n",min);
}