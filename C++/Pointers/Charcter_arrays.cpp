#include <string.h>
#include <iostream>
#include <stdio.h>

void printstr(char* C){
    while(*C != '\0'){
        printf("%c",*C);
        C++;
    }
    printf("\n");
}

int main(){
    char C[20] = "Hello";
    printstr(C);
}