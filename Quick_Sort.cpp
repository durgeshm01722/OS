#include <iostream>
using namespace std;

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = (l - 1);                    // Index of smaller element
    for (int j=l;j<=r-1;j++){
        if (arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return (i+1);
}

void quick_sort(int arr[], int l, int r){
    if(r>l){
        // pi or partition_index
        int pi = partition(arr, l, r);
        quick_sort(arr, l, pi-1);
        quick_sort(arr, pi+1, r);
    }
}

void printArray(int arr[], int len){ 
    int k; 
    for (k = 0; k < len; k++){
        cout << arr[k] << " "; 
    } 
}

int main(){
    int arr[] = {11,45,89,2,62,33,101,1,174,264};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    cout<<"Unsorted Array: \t";
    printArray(arr, len);cout<<endl;
    int l = 0;
    quick_sort(arr, l, len-1);
    cout<<"Sorted Array: \t\t";
    printArray(arr, len);cout<<endl;
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    return 0;
}