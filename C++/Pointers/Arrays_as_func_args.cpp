#include<iostream>
#include<stdio.h>

int SumofElements(int *A, int size){
    int i, sum = 0;
    for(i = 0; i<size;i++){
        sum+= A[i];
    }
    return sum;
}

void Double(int*A, int size){
    int i, sum = 0;
    for(i = 0; i<size; i++){
        A[i] = 2*A[i];
    }
}

int main(){
    int A[] = {1,2,3,4,5};
    int size = (sizeof(A)/sizeof(A[0]));
    int total = SumofElements(A,size);
    Double(A,size);
    for(int i = 0; i<size; i++){
        printf("%d ", A[i]);
    }
    std::cout << std::endl;
    printf("Sum of elements = %d\n", total);
    printf("Main -> Size of A = %d, size of A[0] = %d\n",sizeof(A),sizeof(A[0]));
}