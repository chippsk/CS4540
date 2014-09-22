//Kyle Chipps
//Assignment 1
//Question 2

#include <stdio.h>

int main(int argc, char* argv[]){
	//Create an array of 10 ints, assign each a different value
	int array[10] = {0,1,2,3,4,5,6,7,8,9};
	//Display all elements and their addresses in decimal
	int i;
	fprintf(stderr,"Display elements and addresses in decimal\n");
	for(i =0; i<10;i++){
		fprintf(stderr,"The value in the array is %d, and the address is %d\n",array[i],&array[i]);
	}
	fprintf(stderr,"\n");
	//Display all elements and their addresses in hex
	fprintf(stderr,"Display elements and addresses in hex\n");
	for(i =0; i<10;i++){
		fprintf(stderr,"The value in the array is %x, and the address is %x\n",array[i],&array[i]);
	}
	fprintf(stderr,"\n");
	//Declare a pointer to the array
	int *aPtr;
	aPtr = array;
	//Display all elements and their addresses using the pointer
	fprintf(stderr,"Display elements and addresses in decimal\n");
	for(i =0; i<10;i++){
		fprintf(stderr,"The value in the array is %d, and the address is %d\n",*aPtr,&*aPtr);
		aPtr++;
	}
	return 0;
}
