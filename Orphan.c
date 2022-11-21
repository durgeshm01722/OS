// orphan state...
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int a[1000];
int b[1001];
// create function for quick sort...
void quick_sort(int low,int high){
int i,j,pivot,temp;
if(low < high){
pivot = low;
i = low;
j = high;
while(i < j){
while(a[i] <= a[pivot] && i < high){
i++;
}
while(a[j] > a[pivot]){
j--;
}
if(i < j){
temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
temp = a[pivot];
a[pivot] = a[j];
a[j] = temp;
quick_sort(low,j-1);
quick_sort(j+1,high);
}
}
void merging_data(int low_val, int mid_val, int high_val){
int low, mid, i;
for(low = low_val, mid = mid_val + 1, i = low_val; low <= mid_val && mid <= high_val; i++){
if(a[low] <= a[mid]){
b[i] = a[low];
low++;
}
else{
b[i] = a[mid];
mid++;
}
}
while(low <= mid){
b[i] = a[low];
i++;
low++;
}
while(mid <= high_val){
b[i] = a[mid];
i++;
mid++;
}
for(i = low_val; i <= high_val; i++){
a[i] = b[i];
}
}
void sort(int low, int high){
int mid;
if(low < high){
mid = (low + high) / 2;
sort(low, mid);
sort(mid+1, high);
merging_data(low, mid, high);
}
else{
return;
}
}
int main(){
int i,n;
// get input from user....
printf("Enter size of Elements: ");
scanf("%d",&n);
printf("Enter %d Elements: ",n);
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
// before sorting...
printf("Before sorting:\t");
for(i = 0; i < n; i++){
printf("%d ", a[i]);
}
// Creating Process....
int pid = fork();
if(pid == 0){
int t = 30;
wait(&t);
quick_sort(0, n);
}
else if(pid > 0){
sort(0, n);
}
else{
printf("Error..,Sorry Child process is not created..!!");
}
// after sorting...
printf("\nAfter sorting:\t");
for(i = 1; i <= n; i++){
printf("%d ", a[i]);
}
printf("\n");
}