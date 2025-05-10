#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void left_rotate_array(vector<int>& arr, int d){
    int n = arr.size();
    d = d % n;
    if(arr.empty() || d == 0) return;
    reverse(arr.begin(), arr.begin()+d); //O(d)
    reverse(arr.begin()+d, arr.end());  //O(n-d)
    reverse(arr.begin(), arr.end());   //O(n)

    // Time complexity: O(2n)
    // Space complexity: O(1)

}


int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector <int> arr;

    cout << "Enter the elements of array: ";
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int d;
    cout << "Enter the number of rotations: ";
    cin >> d;

    left_rotate_array(arr, d);

    cout << "Rotated Array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }


    return 0;
}