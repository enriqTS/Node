#include <iostream>
#include <stdio.h>

int main(){
    int a;
    a = 8;
    int *p;
    p = &a;
    std::cout << p << std::endl;
    std::cout << *p << std::endl;
    std::cout << &a << std::endl;
}