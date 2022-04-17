#include<stdio.h>
#include<stdlib.h>

int main(){
    int a;
    int *p;
    // C
    p = (int*)malloc(sizeof(int));
    *p = 10;
    free(p);
    p = (int*)malloc(20*sizeof(int)); //Allocatio of a 20 position array
    free(p);
    // C++
    p = new int;
    *p = 10;
    delete p;
    p = new int[20];
    delete[] p;
}