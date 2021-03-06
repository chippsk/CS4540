///*************************************************
//* Course: CS 4540 – Fall 2014
//* Assignment 1 - Problem 4
//* Name: Kyle Chipps
//* E-mail: kyle.d.chipps@wmich.edu
//* Submitted: 09/25/14
//
//************************************************* 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 10
#define MAX_ARRAY 100

int* generate_rand(int,int);
int random_func(int,int);
void calculate(int*, int);

int main(int argc, char* argv[]){
	//Ask user for array length
	char buffer[MAX];
	fprintf(stderr,"How large do you want the array? ");
	fgets(buffer,sizeof(buffer),stdin);
	
	fprintf(stderr,"the value is %s",buffer);
	int length = atoi(buffer);	
	fprintf(stderr,"the integer is %d\n",length);
	
	//Generate array with values between 0-100
	int i;
	int *ptrArray;
	//Generate the array and return a pointer.
	ptrArray = generate_rand(length,MAX_ARRAY);
	for(i=0;i<length;i++){
		fprintf(stderr,"Array contents in main at %d, : %d\n",i,ptrArray[i]);
	}
	//Call calculate to get mean and standard devation
	int *calcArray;
	calculate(ptrArray,length);
	return 0;
}

int* generate_rand(int length, int maxSize){
	int *array,i;
	array = malloc(length * sizeof(int));
	int *ptr;
	ptr = array;
	//initialize random seed
	srand(time(NULL));
	for(i=0;i<length;i++){
		array[i]=random_func(0,maxSize);
		fprintf(stderr,"Array contents generate rand at %d : %d\n",i,array[i]);
	}
	
	return ptr;
}

void calculate(int *arrayPtr, int length){
	int ret[1];
	//Caclulate mean
	int i,sum,mean,sd;

	for(i=0;i<length;i++){
		//fprintf(stderr,"Array contents in calc func at %d, : %d\n",i,arrayPtr[i]);
		sum += arrayPtr[i];
		//fprintf(stderr,"sum is : %d\n",sum);
	}
	mean = (sum/length);
	fprintf(stderr,"Mean  is %d\n",mean);

	//Calculate Standard Deviation
	int j,sum_dev,num1,num2;

	for(j=0;j<length;j++){
		sum_dev+=(arrayPtr[j]-mean)*(arrayPtr[j]-mean);
		//fprintf(stderr,"Sum Dev is %d\n",sum_dev);
	}
	sd=sqrt(sum_dev/length);
	fprintf(stderr,"Standard Deviation is %d\n",sd);
	
}
int random_func(int min, int max) {
    return rand() % (max - min + 1) + min;
}
