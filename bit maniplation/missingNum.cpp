#include<bits/stdc++.h>
using namespace std;

int missingNum(vector<int>& arr) {
        int ans = 0;
        for(int i = 1; i <= arr.size() + 1; i++){
            ans ^= i;
        }
        for(int i : arr){
            ans ^= i;
        }
        return ans;
}

int main(){
    int n;
    cout << "Enter the sixe of array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the Elements of array";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "missing number is : "<< missingNum(arr);
}