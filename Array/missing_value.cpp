#include<iostream>
#include<vector>
using namespace std;

int missing_num(vector<int> arr, int n){
    int sum = (n * (n + 1)) / 2;
    int actual_sum = 0;

    for(int i = 0; i < arr.size(); i++){
        actual_sum += arr[i];
    }

    return sum - actual_sum;

    //Time complexity: O(n)
    //space complexity: O(1)
}

int missing_num2(vector<int> arr, int n){
    int N = n-1;
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < N; i++){
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
    //Time complexity: O(n)
    //space complexity: O(1)
}

/*
why xox is better than sum = n*(n+1)/2?
If n is large, n * (n + 1) may overflow
example: for n = 100,000 → n*(n+1)/2 = 5,000,050,000, which exceeds 32-bit int limit.
*/

int main(){
    int n;
    cout <<"Enter the size of array: ";
    cin >> n;


    vector<int> arr;
    cout <<"Enter the elements of array: ";
    for(int i = 0; i < n-1; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int result = missing_num(arr,n);

    cout <<" the missing number is: " << result << endl;

    result = missing_num2(arr,n);
    cout << "the missing number is: " << result <<endl;
}