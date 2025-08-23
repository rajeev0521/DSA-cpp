#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr){
    int count = 0;
    for(int i = 1; i < arr.size(); i++){
        int key = arr[i];
        int j = i - 1;
        count ++;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
            count++;
        }
        arr[j + 1] = key;
    }

    cout << "Numer of steps  = "<< count << endl;
}

void bubbleSort(vector<int> &arr) {
    int count = 0;
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        count++;
        for(int j = 0; j < n - i - 1; j++) {
            count++;
            count++;
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                count++;
            }
        }
    }

    cout << "Number of steps = " << count << endl;
}

void selectionSort(vector<int> &arr) {
    int count = 0;
    int n = arr.size();

    for(int i = 0; i < n - 1; i++) {
        count++;
        int minIndex = i;
        count++;

        for(int j = i + 1; j < n; j++) {
            count++;
            count++;
            if(arr[j] < arr[minIndex]) {
                count++;
                minIndex = j;
            }
        }

        if(minIndex != i) {
            swap(arr[i], arr[minIndex]);
            count++;
        }
    }

    cout << "Number of steps = " << count << endl;
}

void merg(vector <int> &arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> l(n1), r(n2);
     for (int i = 0; i < n1; i++)
        l[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        r[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            arr[k] = l[i];
            i++;
        }
        else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = l[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = r[j];
        j++;
        k++;
    }
}

void mergSort(vector<int> &arr, int left, int right){
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergSort(arr, left, mid);
    mergSort(arr, mid + 1, right);
    merg(arr, left, mid, right);
}

int partition(vector<int> &arr, int left, int right){
    int pivot = arr[right];
    int i = left - 1;

    for(int j = left; j <= right - 1; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[right]);
    return i + 1;
}

void quickSort(vector<int> &arr, int left, int right){
    if(left < right){
       int q = partition(arr, left, right);
        quickSort(arr, left, q-1);
        quickSort(arr, q + 1, right) ;
    }
}

void printarr(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements of array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // printarr(arr);

    // insertionSort(arr);
    // bubbleSort(arr);
    // selectionSort(arr);

    // mergSort(arr, 0, arr.size() - 1);

    // quickSort(arr, 0, arr.size() - 1);
    printarr(arr);

}