#include<bits/stdc++.h>
using namespace std;

int iterative(int num){
    int fact = 1;
    while( num > 1){
        fact *= num;
        num--;
    }

    return fact;
}

int factorial(int num){
    if(num == 1) return num;
    return num * factorial(num - 1);
}

int main(){

    int num = 3;
    cout << "The factorial of " << num << " is "<<iterative(num) << endl;

    cout << "The factorial of " << num << " is " << factorial(num) <<endl;
    return 0;
}