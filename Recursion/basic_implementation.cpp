#include<bits/stdc++.h>
using namespace std;

void printNum(int n){
    if(n == 1){
        cout <<"1" << endl;
        return;
    }
    cout << n << " ";
    printNum(n-1);
}

int factorial(int n){
    if(n == 1) return 1;
    return n * factorial(n-1);
}

int fibonacci(int n){
    if(n == 1 || n == 0) return n;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    printNum(8);
    int num = 5;
    cout << "factorial of "<< num << " is " << factorial(num) << endl;
    return 0;
}