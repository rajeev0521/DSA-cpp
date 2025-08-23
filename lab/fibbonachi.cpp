#include<bits/stdc++.h>
using namespace std;

int itrative(int n){
    int first  = 0;
    int second = 1;
    int ans = 0;

    for(int i = 1; i < n; i++){
        ans = first + second;
        first = second;
        second = ans;
    }
     return ans;
}

int recursive(int n){
    if(n == 1 || n == 0) return n;

    return recursive(n-1) + recursive(n-2);
}

int main(){
    cout << itrative(5) <<endl;
    cout << recursive(5) << endl;
    return 0;
}
