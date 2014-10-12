///*************************************************
//* Course: CS 4540 – Fall 2014
//* Assignment 1 - Problem 1
//* Name: Kyle Chipps
//* E-mail: kyle.d.chipps@wmich.edu
//* Submitted: 09/25/14
//
//************************************************* 
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
int main(int argc, char* argv[]){
	//Suppose fred is a double
	double fred;
	//Fred gets a value
	fred = 23;
	//Display value of fred
	fprintf(stderr,"The value of fred is %.0f\n",fred);
	//Declare pointer that points to fred
	double *ptrFred;
	ptrFred = &fred;
	//Display value of fred using pointer
	fprintf(stderr,"The value of fred is %.0f\n",*ptrFred);
	//Display address of fred in decimal and hex
	//With pointer
	fprintf(stderr,"The address of freds pointer is %d\n",&ptrFred);
	fprintf(stderr,"The address of freds pointer is %x\n",&ptrFred);
	fprintf(stderr,"The address of freds pointer is %0lx\n",&ptrFred);
	//without pointer
	fprintf(stderr,"The address of fred is %d\n",&fred);
	fprintf(stderr,"The address of fred is %x\n",&fred);
	fprintf(stderr,"The address of fred is %0lx\n",&fred);
	//Change value of fred using pointer
	*ptrFred = 45;
	//Display new value of fred with pointer
	fprintf(stderr,"The value of fred is %.0f\n",*ptrFred);
	//Without pointer
	fprintf(stderr,"The value of fred is %.0f\n",fred);
	return 0;
}
