#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int>& nums, int target, int st, int end){
        if(st <= end){
            int mid  = st + (end - st)/2;
            if(nums[mid] == target){ 
                return mid;
            }
            else if(nums[mid] < target){
                return BinarySearch(nums, target, mid+1, end);
            }
            else{
                return BinarySearch(nums, target, st, mid-1);
            }
        }

        return -1;
    }