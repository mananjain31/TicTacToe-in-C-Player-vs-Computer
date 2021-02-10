#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
void put(char pos,char player);
bool check(char player);
// bool test(char pos,char player);
// char testLoop(char player);
char p1 = ' ';
char p2 = ' ';
char p;

int a[3][3]={
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
	};

	
void board()
{
	int i,j;
	
	for(i = 0; i<3; i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%c ",a[i][j]);
		}
		printf("\n");
	}
}
void enter(char player)
{
		char pos;
		printf("Choose Position: ");
		scanf("%c",&pos);
		getchar();
		put(pos,player);
}
void put(char pos,char player)
{
	int i,j;
	for(i = 0; i<3; i++)
	{
		for(j=0;j<3;j++)
		{
			if(pos == a[i][j])
			{
				a[i][j] = player;
				return;
			}
		}
	}
	enter(player);	
}
// void test()
// {
	// int i;
	// int w[20][2]={
		// {'1','3'},{'4','6'},{'7','9'},
		// {}, {}, {},
		// {'1','7'},{'2','8'},{'3','9'},
		// {'1','2'},{'4','5'},{'7','8'},
		// {'2','3'},{'5','6'},{'8','9'},
		// {'1','4'},{'2','5'},{'3','6'},
		// {'4','7'},{'5','8'},{'6','9'},
		// {'1','9'},{'3','7'}
	// };
	// int n = sizeof(w)/sizeof(w[0]);
	// for(i=0;i<n;i++)
	// {
		// if(p2 == w[i][0] && p2 == w[i][1])
		// {
			
		// }
	// }
// }
void main()
{
	char test;
	char pos;
	printf("Choose : X or O : ");
	scanf("%c",&p1);
	getchar();
	p2 = (p1=='X')?'O':'X';
	int exit = 0;
	while(!exit)
	{
		// system("cls");
		board();
		enter(p1);
		if(check(p1))
		{
			printf("Player %c wins \n",p1);
			board();
			exit = 1;
		}
		if(exit == 1) return;
		// system("cls");
		board();
		enter(p2);
		// test(pos);
		if(check(p2))
		{
			printf("Player %c wins\n",p2);
			board();
			exit = 1;
		}
	}
}
bool check(char player)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(a[i][j] != player) break;
		}
		if(j == 3){
			printf("\nhor i %d , j %d \n",i,j);
			return true;
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(a[j][i] != player) break;
		}
		if(j == 3)
		{
			printf("\ver i %d , j %d \n",i,j);
			return true;
		}
	}
	
	for(j=0;j<3;j++)
	{
		if(a[j][j] != player) break;
	}
	if(j == 3)
	{
		printf("\nj dig\n");
		return true;
	}
	
	
	for(i = 2, j = 0; i>-1 ; i--,j++)
	{
		if(a[i][j] != player) break;
	}
	if(i == -1)
	{
		printf("\nij dig\n");
		return true;
	}
	return false;
}

// char testLoop(char pos, char player)
// {
	// int i,j;
	// for(i=0;i<3;i++)
	// {
		// for(j=0;j<3;j++)
		// {
			// if(a[i][j]!='X' && a[i][j]!='O')
			// {
				// a[i][j] = player;
				// if(check(p1))
			// }
		// }
	// }
// }