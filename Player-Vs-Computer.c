#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int i,j;
int a[]={1,2,3,4,5,6,7,8,9};
int p1,p2;
bool check(int p)
{
	for(i=0;i<9;i+=3)
	{
		for(j=0;j<3;j++)
		{
			if(a[i+j] != p) break;
		}
		if(j == 3){
			return true;
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<9;j+=3)
		{
			if(a[i+j] != p) break;
		}
		if(j == 9)
		{
			return true;
		}
	}
	
	for(j=0;j<9;j+=4)
	{
		if(a[j] != p) break;
	}
	if(j > 9)
	{
		return true;
	}
	
	
	for(j=2; j<8; j+=2)
	{
		if(a[j] != p) break;
	}
	if(j == 8)
	{
		return true;
	}
	
	return false;
}
void board()
{
	
	system("cls");
	printf("\n\n\t\t\t  TIC TAC TOE WITH COMPUTER:\n\n");

	int k=0;
	printf("\t\t\t\t-------------\n");
	for(i=0;i<3;i++)
	{	
		printf("\t\t\t\t|");
		for(j=0;j<3;j++)
		{
			if(a[k] == -1) printf(" %c |",'X');
			else if(a[k] == -2) printf(" %c |",'O');
			else printf(" %d |",a[k]);
			k++;
		}
	printf("\n\t\t\t\t-------------\n");
	}
}
void doRandom()
{
	srand(time(0)); 
	while(1)	
	{
		int t = rand()%9;
		// printf("%d\n",t);
		if(a[t] == p1 || a[t] == p2 )continue;
		else
		{
			a[t] = p2;
			return;
		}			
	}
}
void compTurn()
{
	int player = p2;
	int k,pos;
	
	for(int iter = 0; iter<2; iter++,player = p1)
	{
		for(i=0;i<9;i+=3)
		{
			k=0;
			for(j=0;j<3;j++)
			{
				if(a[i+j] != player)
				{
					k++;
					pos = i+j;
				}
			}
			if(k == 1 && a[pos] != p1 && a[pos] != p2)
			{
				a[pos] = p2;
				return;
			}
		}

		for(i=0;i<3;i++)
		{
			k=0;
			for(j=0;j<9;j+=3)
			{
				if(a[i+j] != player) 
				{
					k++;
					pos = i+j;
				}
			}
			if(k == 1 && a[pos] != p1 && a[pos] != p2)
			{
				a[pos] = p2;
				return;
			}
		}

		k=0;
		for(j=0;j<9;j+=4)
		{
			if(a[j] != player)
			{
				k++;
				pos = j;
			}
		}
		if(k == 1 && a[pos] != p1 && a[pos] != p2)
		{
			a[pos] = p2;
			return;
		}

		k=0;
		for(j=2; j<8; j+=2)
		{
			if(a[j] != player)
			{
				k++;
				pos = j;	
			}
		}
		if(k == 1 && a[pos] != p1 && a[pos] != p2)
		{
			a[pos] = p2;
			return;
		}
	}
	printf("randomising\n");
	
	doRandom();
}
bool checkDraw()
{
	for(i=0;i<9;i++)
		if(a[i]>0)return false;
	return true;
}
void start()
{
	
	char c;
	int pos;
	while(1)
	{
		printf("Choose X or O : ");
		scanf("%c",&c);
		if(c == 'X' || c == 'O')break;
		else if(c == 'x')
		{
			c = 'X';
			break;
		}
		else if(c == 'o')
		{
			c = 'O';
			break;
		}
		else printf("Invalid Choice, Try again...\n");
		getchar();
	}
	if(c=='X')
	{
		p1 = -1;
		p2 = -2;
	}
	else
	{
		p2 = -1;
		p1 = -2;
	}
	while(1)
	{
		while(1)
		{
			printf("Enter position: ");
			scanf("%d",&pos);
			if(a[pos-1] == pos)
			{
				a[pos-1]=p1;
				break;
			}
			else printf("Invalid position, Try again...\n");
		}
		if(check(p1))
		{
			system("cls");
			board();
			printf("\n\t\t.................you Won.................\n");
			break;
		}
		if(checkDraw())
		{
			system("cls");
	
			board();
			printf("\n\t\t.................Match Draw.................\n");
			break;
		}
		compTurn();
		if(check(p2))
		{
			system("cls");
			board();
			printf("\n\t\t.................Computer Won.................\n");
			break;
		}
		system("cls");
		board();
	}
}
void main()
{
	board();
	start();
}