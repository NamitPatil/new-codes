#include<stdio.h> 

int  main()
{
	int buffer[50];
	int bufsize;
	int produce;
	int consume;
	int choice; 
	int full = 0;
	int empty = 0;
	printf("\nEnter Buffer Size : ");
	scanf("%d",&bufsize);
	while(1)
	{
		printf("\n\n1.Produce\n2.Consume\n3.Exit"); 
		printf("\nEnter your choice : ");
		scanf("%d",&choice); 
		switch(choice)
		{
			case 1: 
				if((full+1)%bufsize==empty)
					printf("\nBuffer is Full!!!!");
				else
				{
					printf("\nEnter the value : ");
					scanf("%d", &produce); 
					buffer[full] = produce;
					full = (full+1)%bufsize;
				}
				break;

			case 2:   
				if(full == empty)
					printf("\nBuffer is Empty!!!!");
				else
				{
					consume= buffer[empty];
					printf("\nConsumed value : %d", consume); 
					empty = (empty+1)%bufsize;
				}
				break;
		}
	}
}