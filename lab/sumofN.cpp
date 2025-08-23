#include<iostream>
using namespace std;

int itrative(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
    }

    return sum;
}

int recursive(int n){
    if(n == 1) return 1;

    return n + recursive(n-1);
}

int main(){
    cout << itrative(3) << endl;
    cout << recursive(3) << endl;
    return 0;
}