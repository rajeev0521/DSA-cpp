#include<bits/stdc++.h>
using namespace std;

void subsets(vector<int> &arr, vector<int> &ans, int i){
    if(i == arr.size()){
        for( int val : ans){
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    // include part
    ans.push_back(arr[i]);
    subsets(arr, ans, i+1);

    ans.pop_back(); // backtrack
    subsets(arr,ans,i+1); //exclude part
}

int main(){
    vector<int> arr = {1,2,3};
    vector<int> ans;
    
    subsets(arr, ans, 0);
}