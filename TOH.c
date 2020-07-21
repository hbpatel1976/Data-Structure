#include<stdio.h>
int main() 
{
   int n=3;
   TOH(n,'S','D','T');
}
void TOH(int n, char source, char temp, char dest) 
{
   if(n>0) 
   {
      TOH(n-1,source,dest,temp);
      printf("move disk # %d from %c to %c\n",n,source,temp);
      TOH(n-1,dest,temp,source);
   }
}
