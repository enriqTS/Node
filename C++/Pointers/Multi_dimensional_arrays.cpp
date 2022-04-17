#include<iostream>
#include<stdio.h>

int Func(int (*A)[2][2]){

}

int Func2(int A[][2][2]){

}

int main(){
    int C[3][2][2] = {{{2,5},{7,9}},{{3,4},{6,1}},{{0,8},{11,13}}};
    printf("%d %d %d %d\n", C, *C, C[0], &C[0][0]);
    printf("%d\n",*(C[0][0]+1));
    Func(C);
    Func2(C);
}