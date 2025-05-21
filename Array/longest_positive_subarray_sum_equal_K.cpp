#include<iostream>
#include<vector>
using namespace std;
// Given an array of integers nums and an integer k, return the longest subarray whose sum equals to k.

//brute force approach
// using three loops
int longest_subarray(vector<int> &arr, int k ){
    int max = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i; i < n; j++){
            int sum = 0;
            for(int l = i; l <= j; l++){
                sum += arr[l];
            }

            if(sum == k){
                int length = j - i + 1;
                if(length > max){
                    max = length;
                }
            }
        }
    }

    return max;
    // Time complexity: O(n^3)
    // Space complexity: O(1)
}

//optimal approch

int longest_subarray2(vector<int> &arr, int k){
    int left = 0;
    int right = 0;

    int sum = 0;
    int max = 0;

    while(right < arr.size()){
        sum += arr[right];

        while(sum > k){
            sum -= arr[left];
            left++;
        }

        if(sum == k){
            int length = right - left + 1;
            if(length > max){
                max = length;
            }
        }

        right++;
    }
    return max;
    // Time complexity: O(n)
    // Space complexity: O(1)
}

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the elements of array: ";
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    int result = longest_subarray(arr, k);
    cout << "Length of longest subarray with sum equal to k: " << result << endl;

    int result2 = longest_subarray2(arr, k);
    cout << "Length of longest subarray with sum equal to k using optimal approach: " << result2 << endl;

    return 0;

}