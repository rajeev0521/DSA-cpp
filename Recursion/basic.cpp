#include<bits/stdc++.h>
using namespace std;
// re<vrse an array using recursion
void revers(vector<int> &arr){
    
}

//Sum of n numbers
int sum(int n){
    if(n == 0) return 0;
    return n + sum(n-1);
}

//print linearly from 1 to N
void printNum(int n){
    if(n == 0) return;
    printNum(n-1);
    cout << n << " ";
}

// print name N times
void printName(int n){
    if(n == 0) return;

    
    cout << "Rajeev" << " ";
    printName(--n);
}

int main(){
    printName(5);
     cout << endl;
    printNum(10);
    cout << endl;

    cout << "sum of n numbers = "<< sum(10);
}