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
}