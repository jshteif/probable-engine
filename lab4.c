// Jessie Shteif
// COP 3502 Lab 6

#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
	if (high >= low)
	{
        // m will be the midpoint
	    int m = low + (high - low)/2;
	    if (numbers[m] == value) // if the specified value is indeed the midpoint
        	return m;
	    if (numbers[m] > value) // if there is an odd amount of items and the midpoint is on the higher side
	    	return search(numbers, low, m-1, value);
        if (numbers[m] < value) // if there is an odd amount of items and the midpoint is on the lower side
	    	return search(numbers, m+1, high, value);
	    
	}
	return -1;
    
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}