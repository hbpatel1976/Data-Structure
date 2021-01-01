/* Quadratic Probing */
#include <stdio.h>
#define dataSize 10  /* total number of data */
#define hashTableSize 10 /* size of hash table */
/* hashTableSize >= dataSize */
void main()
{
	int data[dataSize]={3,2,9,6,11,13,7,12,70,80};
	int hashTable[hashTableSize],i,position, tempPosition, probes[hashTableSize],counter, elementsInHashTable=1;
	
	/* Set -999 to indicate that the cell is empty */
	for(i=0; i<hashTableSize; ++i)hashTable[i]=-999;
	
	/* Process each data one by one*/
	for(i=0; i<dataSize; ++i)
	{	printf("i=%d\t",i);
		printf("data[%d]=%d\t",i,data[i]);
		position=hashFunction(data[i]);
		tempPosition=position;
		printf("position given by the function =%d\t",position);
		counter=1;
		while(hashTable[tempPosition]!=-999)
			{
			tempPosition=position+(counter*counter);
			tempPosition=tempPosition%hashTableSize;
			counter++;
			}
		position=tempPosition;
		printf("position incremented after collision =%d\t",position);
		hashTable[position]=data[i];
		printf("hashTable[%d] = %d\n",position, hashTable[position]);
		probes[position]=counter;
		elementsInHashTable++;
		if(elementsInHashTable>hashTableSize)
			{
			printf("\nHash Table is FULL and hence can not process further %d more data\n",dataSize-hashTableSize);
			break;
			}
	}
	/* Display */
	printf("Status of Hash Table After Mapping the data onto it\n");
	for(i=0; i<hashTableSize; ++i)
	printf("hashTable[%d]=%d => Number of probes = %d\n",i,hashTable[i], probes[i]);
}
int hashFunction(int k)
{
	return (2*k+3)%hashTableSize;
}
