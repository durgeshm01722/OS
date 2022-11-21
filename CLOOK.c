#include <stdio.h>
#include <stdlib.h>

int noOfRequests = 8;
int diskSize = 200;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Sort(int arr[], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - i -1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
		}
	}
}

void CLOOK(int req[], int head){
	int seekCount = 0;
    int distance, curTrack;
    int left[noOfRequests], right[noOfRequests], seekSequence[noOfRequests];

    for(int i=0;i < noOfRequests; i++){
        left[i] = 9999;
        right[i] = 9999;
    }

    int leftIndex = 0, rightIndex = 0;
    for (int i = 0; i < noOfRequests; i++) {
        if (req[i] < head){
        	left[leftIndex++] = req[i];
        }
        if (req[i] > head){
            right[rightIndex++] = req[i];
        }
    }

    int nLeft = 0, nRight = 0;
    for(int i=0;i<noOfRequests;i++){
        if(left[i]!=9999){
            nLeft++;
        }
        if(right[i]!=9999){
            nRight++;
        }
    }

    Sort(left, noOfRequests);
    Sort(right, noOfRequests);
    int index = 0;

    for (int i = 0; i < nRight; i++) {
        curTrack = right[i];
        // appending current track to seek sequence
        seekSequence[index++] = curTrack;
        if(curTrack!=9999){
            // calculate absolute distance
            distance = abs(curTrack - head);
            // increase the total count
            seekCount += distance;
            // accessed track is now new head
            head = curTrack;
        }
    }
    seekCount += abs(head - left[0]);
	head = left[0];
    for (int i = 0; i < nLeft; i++) {
        curTrack = left[i];
        // appending current track to seek sequence
        seekSequence[index++] = curTrack;
        if(curTrack!=9999){
            // calculate absolute distance
            distance = abs(curTrack - head);
            // increase the total count
            seekCount += distance;
            // accessed track is now the new head
            head = curTrack;
        }
    }
 
    printf("Total number of seek operations = %d\n", seekCount);
    printf("Seek Sequence is: \n");
    for (int i = 0; i < index; i++) {
        printf("%d ", seekSequence[i]);
    }
}

int main(){
	int requests[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int headPosition = 50;
    int direction = 0;
    CLOOK(requests, headPosition);
	return 0;
}

