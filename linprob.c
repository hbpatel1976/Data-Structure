#include <stdio.h>
#define dataSize 10  /* total number of data */
#define hashTableSize 10 /* size of hash table */
/* hashTableSize >= dataSize */
int main()
{
	int data[dataSize]={3,2,9,6,11,13,7,23,50,100};
	int hashTable[hashTableSize],i,position;
	
	/* Set -999 to indicate that the cell is empty */
	for(i=0; i<hashTableSize; ++i)hashTable[i]=-999;
	
	/* Process each data one by one*/
	for(i=0; i<dataSize; ++i)
	{	printf("i=%d\t",i);
		printf("data[%d]=%d\t",i,data[i]);
		position=hashFunction(data[i]);
		printf("position given by the function =%d\t",position);
		while(hashTable[position]!=-999)
			{
			position++;
			position=position%hashTableSize;
			}
		printf("position incremented after collision =%d\t",position);
		hashTable[position]=data[i];
		printf("hashTable[%d] = %d\n",position, hashTable[position]);
	}
	/* Display */
	printf("OUTPUT\n");
	for(i=0; i<hashTableSize; ++i)
		{
			printf("Hashtable[%d] = %d\n",i, hashTable[i]);
		}
return 0;
}
int hashFunction(int k)
{
	return (2*k+3)%hashTableSize;
}
