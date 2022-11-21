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

void SCAN(int req[], int head, int dir){
	int seekCount = 0;
    int distance, curTrack;
    int left[noOfRequests], right[noOfRequests], seekSequence[noOfRequests];

    for(int i=0;i < noOfRequests; i++){
        left[i] = 9999;
        right[i] = 9999;
    }

    if (dir == 0){
        left[0] = 0;
    }
    if (dir == 1){
        right[0] = diskSize - 1;
    }

    int leftIndex = 1, rightIndex = 1;
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

    int run = 2;
    int index = -1;

    while (run--) {
		if (dir == 0) {
		    for (int i = nLeft; i >= 0; i--) {
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
		    dir = 1;
		}
		else if (dir == 1) {
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
			dir = 0;
		}
	}
 
    printf("Total number of seek operations = %d\n", seekCount);
    printf("Seek Sequence is: \n");
    for (int i = 0; i < index; i++) {
        printf("%d ", seekSequence[i]);
    }
}

int main(){
	int requests[] = { 176, 79, 34, 60, 92, 11, 41, 114};
    int headPosition = 50;
    int direction = 0;
    SCAN(requests, headPosition, direction);
	return 0;
}

