#include <stdio.h>
#include <stdlib.h>

unsigned int heapA;
unsigned int heapB;
unsigned int heapC;
int mode;

char initialization()
{
	heapA = 0x0f;//4 sticks
	heapB = 0x1f;//5 sticks
	heapC = 0x3f;//6 sticks
	char begin;
	
	do
	{
		printf("Play vs computer (1) or human (2)?\n");
		scanf("%d",&mode);
	}while(mode != 1 && mode != 2);
        printf("Do you want to begin? (y: yes) (n: no)\n");
	do
        {
                scanf("%c", &begin);
        }while(begin != 'y' && begin != 'n');
        if(begin == 'y')
                printf("You begin\n");
        else
                printf("The AI begin\n");
	return begin;
}

void computerTurn()
{
	printf("Computer's turn \n");
	//TODO
}

void playerTurn(int playerNb)
{
	int nbHeap, nbSticks;
	do
	{
		printf("Player %d's turn\n", playerNb);
		do
		{
			printf("Which heap do you want to remove sticks from?\n");
			scanf("%d", &nbHeap);
		}while(nbHeap < 1 || nbHeap > 3);
	
		do
		{
			printf("How much do you want to remove sticks\n");
			scanf("%d", &nbSticks);
		}while(nbSticks < 1 || nbSticks > 3);
		
	}while(isValidMove(nbHeap, nbSticks) == 0);
		
	if (nbHeap == 1)
		heapA = heapA >> nbSticks;
	if (nbHeap == 2)	
		heapB = heapB >> nbSticks;
	if (nbHeap == 3)
           	heapC = heapC >> nbSticks;
}

int isValidMove(heapNb, nbSticks)
{
	int valid = 1;
	if(heapNb == 1)
	{
		if(nbSticks == 1 && heapA == 0x00)
			  valid = 0;
		if(nbSticks == 2 && heapA <= 0x01)
			  valid = 0;
		if(nbSticks == 3 && heapA <= 0x03)
			  valid = 0;
	}
	if(heapNb == 2)
	{
		if(nbSticks == 1 && heapB == 0x00)
			  valid = 0;
		if(nbSticks == 2 && heapB <= 0x01)
			  valid = 0;
		if(nbSticks == 3 && heapB <= 0x03)
			  valid = 0;
	}
	if(heapNb == 3)
	{
		if(nbSticks == 1 && heapC == 0x00)
			  valid = 0;
		if(nbSticks == 2 && heapC <= 0x01)
			  valid = 0;
		if(nbSticks == 3 && heapC <= 0x03)
			  valid = 0;
	}
	
	if(valid == 0)
	{
		  printf("Invalid move !\n");
		  return 0;
	}
	return 1;
}

void displayGame()
{
	
	int heap;	

	printf("=================================\n");
	printf("heap 1: ");
	heap = heapA;
	while(heap != 0x00)
	{
		printf("|");
		heap = heap >> 1;
	}
	printf("\nheap 3: ");
	heap = heapB;
	while(heap != 0x00)
	{
		printf("|");
		heap = heap >> 1;
	}
	printf("\nheap 3: ");
	heap = heapC;
	while(heap != 0x00)
	{
		printf("|");
		heap = heap >> 1;	
	}
	printf("\n");
	printf("=================================\n");
}	

void displayLog()
{

}

int endGame()
{
	if(heapA == 0x01 && heapB == 0x00 && heapC == 0x00)
		return 0;
	else if(heapA == 0x00 && heapB == 0x01 && heapC == 0x00)
		return 0;
	else if(heapA == 0x00 && heapB == 0x00 && heapC == 0x01)
		return 0;
	else	
		return 1;
}

void conclusion(int looser)
{
	if(mode == 1)
	{
		if(looser == 3)
			printf("You lost against the computer!");
		else
			printf("You won");
	}
	else
	{
		if(looser == 1)
			printf("Player 1 is the Winner!!\n");
		else
			printf("Player 2 is the Winner!!\n");
	}

	//TODO
	//printf("Do you want to display full log of the game?\n");
	
}

void main(void)
{
	char begin;
	int toPlay, win, looser;	
	int computerPlayed;

	begin = initialization();
	if(begin == 'y')
		toPlay = 1;
	else
		toPlay = 2;
	do
	{
		displayGame();
		if(toPlay == 1)
		{
			if(mode == 1 && begin != 'y')
			{	
				computerTurn();
				computerPlayed = 1;
			}
			else
			{
				playerTurn(toPlay);
				computerPlayed = 0;
			}
			toPlay = 2;
		}
		else if(toPlay == 2)
		{
			if(mode == 1 && begin == 'y')
			{
				computerTurn();
				computerPlayed = 1;
			}
			else
			{
				playerTurn(toPlay);
				computerPlayed = 0;
			}
			toPlay = 1;
		}
		displayGame();	
	}
	while(endGame() == 1);
	if(mode == 1 && computerPlayed == 1)
		looser = 3;
		
	looser = toPlay;
	conclusion(looser);
}
