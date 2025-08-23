#include<bits/stdc++.h>
using namespace std;

int itrative(vector<int> &nums, int target){
    int start = 0;
    int end = nums.size() - 1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    return -1;
}

int recursive(vector<int>& nums, int target, int st, int end){
        if(st <= end){
            int mid  = st + (end - st)/2;
            if(nums[mid] == target){ 
                return mid;
            }
            else if(nums[mid] < target){
                return recursive(nums, target, mid+1, end);
            }
            else{
                return recursive(nums, target, st, mid-1);
            }
        }

        return -1;
    }

int main(){
    vector<int> arr = {1,3,4,7,10,33,54,62,77};
    int target = 62;
    cout << target << " is at index "<< recursive(arr, target, 0, arr.size()) << endl;

    cout << target << " is at index "<< itrative(arr,target) << endl;
    return 0;
}