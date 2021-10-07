#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int a = 10;
    int *p = &a;
    cout << "Address p is " << p << endl;
    cout << "Value at address p is " << *p << endl;
    cout << "Size of an integer is " << sizeof(int) << " bytes" <<endl;
    cout << "Address in p+1 is " << p+1 << endl;
    cout << "Value at address p+1 is " << *(p+1) << endl;
}