#include <iostream>
using namespace std;

void selection_sort(int arr[], int len){
    for (int i=0;i<len-1;i++){
        int min_index = i;
        for (int j=i+1;j<len;j++){
            if (arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

void printArray(int arr[], int len){ 
    int k; 
    for (k = 0; k < len; k++){
        cout << arr[k] << " "; 
    } 
}

int main()
{
    int arr[] = {11,45,89,2,62,33,101,1,174,264};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    cout<<"Unsorted Array: \t";
    printArray(arr, len);cout<<endl;
    int l = 0;
    selection_sort(arr, len);
    cout<<"Sorted Array: \t\t";
    printArray(arr, len);cout<<endl;
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    return 0;
}