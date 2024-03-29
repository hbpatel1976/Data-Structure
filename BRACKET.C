/* Check Brackets Balancing in an Expression */
#include <stdio.h>
#define size 10
int stack[size],top=-1;
void main()
{
char str[20],ch;
int i=0,flag=0;
void push(char);
char pop(void);
printf("Enter the expression : ");
scanf("%s",str);
while(str[i]!='\0')
	{
	if(str[i]=='{' || str[i]=='(' || str[i]=='<' || str[i]=='[') /* OPENING BRACKET */
		{
		push(str[i]); 
		}
	else if(str[i]=='}' || str[i]==')' || str[i]=='>' || str[i]==']') /* CLOSING BRACKET */
		{
		ch=pop(); 
		if(isPair(ch,str[i])==0)
			{
			flag=1;
			break;
			}
		}
	else /* ANY CHARACTER OTHER THAN BRACKETS (INCLUDING SPACE) */
		{
		flag=2;
		break;
		}
	i++;
	}
if(flag==0)printf("Balanced Brackets\n");
else if(flag==1)printf("Imbalanced Brackets\n");
else if(flag==2)printf("Invalid Input\n");
}
void push(char c)
	{
	stack[++top]=c;
	}
char pop(void)
	{
	return stack[top--];
	}
int isPair(char ch1, char ch2)
	{
	if((ch1=='<' && ch2=='>') || (ch2=='<' && ch1=='>'))return 1;
	if((ch1=='(' && ch2==')') || (ch2=='(' && ch1==')'))return 1;
	if((ch1=='{' && ch2=='}') || (ch2=='{' && ch1=='}'))return 1;
	if((ch1=='[' && ch2==']') || (ch2=='[' && ch1==']'))return 1;
	return 0;
	}
