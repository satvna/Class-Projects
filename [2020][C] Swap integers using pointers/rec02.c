#include <stdio.h>
#include <stdlib.h>

int main() {
	int sizeArr = 2;
	int* ptr = (int *)malloc(sizeArr * sizeof(int));
	int tempInt = 0;

	//if malloc fails to allocate memory:
	if (ptr == NULL) {
		printf("Failed to return memory.\n");
		return 0;
	}

	//get integers
	printf("Enter first integer:");
	scanf("%d", ptr);


	printf("Enter second integer:");
	scanf("%d", ptr+1);
	
	//print
	printf("Original values:1st = %d 2nd = %d\n", ptr[0], ptr[1]);
	

	//bitwise swapping
	ptr[0] = ptr[0] ^ ptr[1];
	ptr[1] = ptr[0] ^ ptr[1];
	ptr[0] = ptr[0] ^ ptr[1];

	printf("Swapped values:1st = %d 2nd = %d\n", ptr[0], ptr[1]);
	//free memory
	free(ptr);
	return 0;
}
