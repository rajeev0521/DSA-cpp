#include<iostream>
#include<vector>
using namespace std;

vector<int> union_of_array(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();

    int i = 0, j = 0;

    vector<int> result;

    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            if(result.empty() || result.back() != arr1[i]){
                result.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(result.empty() || result.back() != arr2[j]){
                result.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i < n){
        if(result.empty() || result.back() != arr1[i]){
            result.push_back(arr1[i]);
        }
        i++;
    }

    while(j < m){
        if(result.empty() || result.back() != arr2[j]){
            result.push_back(arr2[j]);
        }
        j++;
    }

    return result;
}

int main(){
    int n;
    int m;
    cout <<"Enter the size of first array: ";
    cin >> n;
    cout <<"Enter the size of second array: ";
    cin >> m;

    vector<int> arr1;
    vector<int> arr2;

    cout << "Enter the elements of first array: ";
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr1.push_back(temp);
    }

    cout << "Enter the elements of second array: ";
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        arr2.push_back(temp);
    }

    vector<int> result = union_of_array(arr1, arr2);

    cout << "Union of Arrays:" << endl;
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
