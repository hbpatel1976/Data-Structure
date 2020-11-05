/* Double Hashing */
#include <stdio.h>
#define dataSize 10  /* total number of data */
#define hashTableSize 10 /* size of hash table */
/* hashTableSize >= dataSize */
void main()
{
	int data[dataSize]={3,2,9,6,11,14,8,12,70,80};
	int hashTable[hashTableSize],i,location1, location2, position,probes[hashTableSize],counter, elementsInHashTable=1;
	
	/* Set -999 to indicate that the cell is empty */
	for(i=0; i<hashTableSize; ++i)hashTable[i]=-999;
	
	/* Process each data one by one*/
	for(i=0; i<dataSize; ++i)
	{	printf("i=%d\t",i);
		printf("data[i]=%d\t",data[i]);
		location1=hashFunction1(data[i]);
		location2=hashFunction2(data[i]);
		printf("position given by the function =%d\t",location1);
		counter=0;
		while(hashTable[(location1+location2*counter)%hashTableSize]!=-999)
			{
			counter++;
			}
		position=(location1+location2*counter)%hashTableSize;
		printf("position modified after collision =%d\t",position);
		hashTable[position]=data[i];
		printf("hashTable[%d] = %d\n",position, hashTable[position]);
		probes[position]=counter+1;
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
int hashFunction1(int k)
{
	return (2*k*k+3*k-5)%hashTableSize;
}
int hashFunction2(int k)
{
	return (3*k*k-4*k+9)%hashTableSize;
}
