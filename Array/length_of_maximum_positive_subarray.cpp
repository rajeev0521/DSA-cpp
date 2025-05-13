#include<iostream>
#include<vector>
using namespace std;

//Question : Given an integer array, find the length of the longest contiguous subarray with sum equal to K.
//Topic : Sliding Window
int length_of_maximum_subarray(vector<int> arr, int k){
    int n = arr.size();
    int i = 0, sum = 0, maxi = 0;

    for (int j = 0; j < n; j++) {
        sum += arr[j];

        // Shrink the window from the left if sum is more than k
        while (sum > k && i <= j) {
            sum -= arr[i];
            i++;
        }

        // Check if current window sum is equal to k
        if (sum == k) {
            maxi = max(maxi, j - i + 1);
        }
    }

    return maxi;
    // Time complexicity: O(n)
    // space complexicity: O(1)
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

    int result = length_of_maximum_subarray(arr, k);

    cout << "Length of maximum subarray with sum equal to k: " << result << endl;

    return 0;

}