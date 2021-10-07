#include<iostream>
using namespace std;

int MAX_ARRAY = 5;
// Pointer arithmethics can be used like a for statement in arrays, because they are stored consecutivelly.

void p_arith(){
    int A[] = {2,4,5,8,1};
    printf("%d\n",A);
    printf("%d\n",&A[0]);
    printf("%d\n",A[0]);
    printf("%d\n",*A);
    cout << "End of p_arith, out of for, loop" << endl;
    for(int i = 0; i < MAX_ARRAY; i++){
        printf("Address = %d\n",&A[i]);
        printf("Address = %d\n",A+i);
        printf("Value = %d\n",A[i]);
        printf("Value = %d\n",*(A+i));
    }
    cout << "End of p_arith for loop" << endl;
}

int main(){

    int point[MAX_ARRAY];

    for(int i = 0; i < MAX_ARRAY; i++){
        point[i] = i + 1;
        cout << point[i] << endl;
    }
    cout << "End of main for loop 1" << endl;

    for(int i = 0; i < MAX_ARRAY; i++){
        int* p = &point[i];
        point[i] = i + 1;
        cout << *p << endl;
    }
    cout << "End of main for loop 2" << endl;

    p_arith();
    
}