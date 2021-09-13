/* Two Dimensional Arrays */
#include <stdio.h>
#define row 4
#define col 3
void main()
{
	int marks [row][col] = {{45,38,64}, {78,89,92}, {65,58,71}, {79,88,95}};
	/*int marks [row][col] = {45,38,65,78,89,92,65,58,71,79,88,95};*/
	
	printf("%d\n",marks[0][2]); /* 64 */
	printf("%d\n",marks[2][0]); /* 65 */
	printf("%d\n",marks[1][0]); /* 78 */
}
