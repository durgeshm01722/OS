#include <stdio.h>
#include <stdlib.h>

// Calculates difference of each
// track number with the head position
void difference(int requests[], int head, int diff[][2], int n){
	for(int i = 0; i < n; i++){
		diff[i][0] = abs(head - requests[i]);
	}
}

// Find unaccessed track which is
// at minimum distance from head
int findMIN(int diff[][2], int n){
	int index = -1;
	int minimum = 1e9;
	for(int i = 0; i < n; i++){
		if (!diff[i][1] && minimum > diff[i][0]){
			minimum = diff[i][0];
			index = i;
		}
	}
	return index;
}

void SSTF(int requests[], int head, int n){	
	// Create array of objects of class node
	int diff[n][2];
    for(int i=0;i<=n;i++){
        diff[i][0] = 0;
        diff[i][1] = 0;
    }
	
	// Count total number of seek operation
	int seekcount = 0;
	
	// Stores sequence in which disk access is done
	int seekSequence[n+1];

    for(int i=0;i<=n;i++){
        seekSequence[i] = 0;
    }
	
	for(int i = 0; i < n; i++){
		seekSequence[i] = head;
		difference(requests, head, diff, n);
		int index = findMIN(diff, n);
		diff[index][1] = 1;
		// Increase the total count
		seekcount += diff[index][0];
		// Accessed track is now new head
		head = requests[index];
	}
	seekSequence[n] = head;
	
	printf("Total number of seek operations = %d", seekcount);
	printf("Seek sequence is : %d\n");
	// Print the sequence
	for(int i = 0; i <= n; i++){
		printf("%d ", seekSequence[i]);
	}
}

int main(){
	int n = 8;
	int requests[] = { 176, 79, 34, 60, 92, 11, 41, 114 };
	SSTF(requests, 50, n);
	return 0;
}

