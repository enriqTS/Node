#include <stdio.h>
#include <iostream>

int main(){
    int a = 1025;
    int *p = &a;
    printf("size of integer is %d bytes\n", sizeof(int));
    printf("Address = %d, value = %d\n",p,*p);
    void *p0;
    p0 = p;
    printf("address = %d",p0);
    // Voids pointers cannot perform any operations or receive values, because it
    // tecnically doesn`t have a type    
}