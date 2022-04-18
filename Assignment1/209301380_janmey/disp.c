#include<stdio.h>

int main()
{
  	int Number, i;
  
  	printf("\n Please Enter any Integer Value  : ");
  	scanf("%d", &Number);
  	
  	printf("\n List of Natural Numbers from 1 to %d are \n", Number);  	
	for(i = 1; i <= Number; i++)
  	{
    	printf(" %d \t", i);
  	}
  
  	return 0;
}
