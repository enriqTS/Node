#include<stdio.h>
#include<iostream>

int main(){
    int x = 5;
    int* p = &x;
    int** q = &p;
    int*** r = &q;
    printf("Value of p = %d\n", *p);
    printf("Address of q = %d\n", *q);
    printf("Value of q = %d\n", *(*q));
    printf("Address of r = %d\n", *(*r));
    printf("Value of r = %d\n", *(*(*r)));
}