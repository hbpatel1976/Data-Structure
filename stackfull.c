/* complete stack  implementation */
#include<stdio.h>
#define size 5
int S [size], top=-1;
int main()
{
	int choice, element;
	while(choice!=6)
		{
		printf("\n1: Push");
		printf("\n2: Pop");
		printf("\n3: Peep");
		printf("\n4: IsFull");
		printf("\n5: IsEmpty");
		printf("\n6: Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch (choice)
			{
			case 1:
				printf("You have selected PUSH option\n");
				printf("Enter the element to push: ");
				scanf("%d",&element);
				push(element);
				break;
			case 2:
				printf("You have selected POP option\n");
				pop();
				break;
			case 3:
				printf("You have selected PEEP option\n");
				printf("The peeped element is %d\n",peep());
				break;
			case 4:
				printf("You have selected IsFull option\n");
				if(isFull()==1)printf("Stack is Full\n");
				else printf("Stack is NOT Full\n");
				break;
			case 5:
				printf("You have selected IsEmpty option\n");
				if(isEmpty()==1)printf("Stack is empty\n");
				else printf("Stack is NOT empty\n");
				break;
			default:
				printf("Invalid Choice..Please re-enter\n");
			}
		}
	return 0;
}
void push(int x)
{
	if(top==size-1)
		{
			printf("Stack Overflow"); return;
		}
	else
		{
			top++;
			S[top]=x;
			printf("Element pushed : %d\n",S[top]);
		}
}
void pop(void)
{
if(top==-1)
		{
			printf("Stack Underflow"); return;
		}
	else
		{
			printf("Element popped : %d\n",S[top]);
			top--;
		}	
}

int peep(void)
{
	return S[top];
}

int isFull()
{
	if(top==size-1)return 1;
	else return 0;
}

int isEmpty()
{
	if(top==-1)return 1;
	else return 0;
}
