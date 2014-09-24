//Kyle Chipps
//Assignment 1
//Question 3

#include <stdio.h>
#define MAX 25

void display(int* ,int);

int main(int argc, char* argv[]){
	//Ask user to enter postive integer
	char buffer[MAX];
	fprintf(stderr,"Enter a positive integer ");
	fgets(buffer,sizeof(buffer),stdin);

	//Create an array of the size of the input.
	//fprintf(stderr,"the value is %s",buffer);
	int length = atoi(buffer);	
	//fprintf(stderr,"the integer is %d\n",length);
	int array[length];

	//Ask user to input the array with some values
	int i;
	for(i=0;i<length;i++){
		fprintf(stderr,"Enter a value to input into the array ");
		fgets(buffer,sizeof(buffer),stdin);
		array[i]=atoi(buffer);
		fprintf(stderr,"Array at position %d, is %d\n",i,array[i]);
	}

	//Display n elements using array pointer
	int checked = 1;
	int num;
	do{ 
		fprintf(stderr,"How many elements of the array do you want printed? ");
		fgets(buffer,sizeof(buffer),stdin);
		num = atoi(buffer);
		if(num > length){
			//Printing more than the array contains.
			fprintf(stderr,"Input at most the size of the array you created\n");
			//checked = -1;
		}
		else{
			//num < length, input validated
			//fprintf(stderr,"moving on\n");
			checked = 0;

		}
	}
	while(checked==1);
	fprintf(stderr,"Printing %d element(s)\n",num);


	int *ptrArray;
	ptrArray = array;


	display(ptrArray,num);

	return 0;
}

void display(int* array_ptr,int n){
	int i;
	fprintf(stderr,"First %d array values\n",n);
	for(i=0;i<n;i++){
		fprintf(stderr,"Array Contents: %d\n",*array_ptr);
		array_ptr++;
	}
}
