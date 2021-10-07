#include<stdio.h>
#include<stdlib.h>
#include<iostream>

int* Add(int* a, int* b){
    int *c = new int;
    *c = (*a) + (*b);
    return c;
}

int main(){
    int a = 2, b = 4;
    int* ptr = Add(&a,&b);
    std::cout << *ptr << std::endl;
}