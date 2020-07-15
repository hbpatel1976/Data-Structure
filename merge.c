/* Merge Sort */
#include <stdio.h> 
#include <stdlib.h> 
  
void merge(int A[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int nL = mid - left + 1; 
    int nR = right - mid; 
  
    int L[nL], R[nR]; 
  
    for (i = 0; i < nL; i++) 
        L[i] = A[left + i]; 
    for (j = 0; j < nR; j++) 
        R[j] = A[mid + 1 + j]; 
  
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = left; // Initial index of merged subarray 
    while (i < nL && j < nR) 
	{ 
        if (L[i] <= R[j]) 
		{ 
            A[k] = L[i]; 
            i++; 
        } 
        else 
		{ 
            A[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < nL) 
	{ 
        A[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < nR) 
	{ 
        A[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int A[], int left, int right) 
{ 
    if (left < right) 
	{ 
        int mid = left + (right - left) / 2; 
  
        mergeSort(A, left, mid); 
        mergeSort(A, mid + 1, right); 
  
        merge(A, left, mid, right); 
    } 
} 
  
int main() 
{ 
    int i, A[] = {66, 33, 40, 22, 55, 88, 11, 80, 20, 50, 44, 77, 30}, size=13;
  
    mergeSort(A, 0, size - 1); 
  
    for(i=0; i<size; ++i)printf("%d ",A[i]);
	return 0; 
}
