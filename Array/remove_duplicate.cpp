#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

// Function to remove duplicates from a sorted array using set
// Time complexity: O(nlog(n) + n)
// The O(nlog(n)) is for inserting elements into the set, and O(n) is for iterating through the set.
// Space complexity: O(n)
set<int> remove_duplicates1(vector<int>& arr){
    set <int> unique; 
    for(int i = 0; i < arr.size(); i++){
        unique.insert(arr[i]);
    }

    return unique;
}

// Function to remove duplicates from a sorted array using two pointers in case of sorted array
// Time complexity: O(n)    
// Space complexity: O(1)
vector<int> remove_duplicate2(vector<int> &arr){
    if(arr.size() == 0) return arr;
    int j = 0;
    for(int i = 1 ; i < arr.size(); i++){
        if(arr[i] != arr[j]){
            j++;
            arr[j] = arr[i];
        }
    }
    arr.resize(j + 1);
    return arr;
    
}

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr;
    
    cout << "Enter the elements of array: " ;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    set <int> result;

    result = remove_duplicates1(arr);


    // cout << "Array without duplicate: ";
    // for (auto it = result.begin(); it != result.end(); ++it) {
    //     cout << *it << ",";
    // }
    cout << "Array without duplicate using set: ";
    for(auto it : result){
        cout << it << " ";
    }
    cout << endl;

    arr = remove_duplicate2(arr);
    cout << "Array without duplicate using two pointers: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}