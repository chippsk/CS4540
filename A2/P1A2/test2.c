#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* reverse_case(char* str);

int main(){

    char  input[] = "this is THE TiMe to gET thE CoRreCT ANSWERS.";
    int *message;
    int r1, r2;
    printf("%s", input); // Print out original sentance
    printf("\n\n");
    fprintf(stderr,"The new string is \n %s \n", reverse_case(input));
    return (0);
}


char* reverse_case(char* str) {
    if (str) {
        char* p;
        int c;
        for (p = str; ((c=*p)!=0); ++p)
            if (isalpha(c))
                *p = (islower(c)?toupper(c):tolower(c));
    }
    return str;
}