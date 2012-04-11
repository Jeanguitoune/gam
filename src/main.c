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
	
	do
        {
                printf("Do you want to begin? (n: no) (y: yes)\n");
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

}

void playerTurn(int playerNb)
{
	int nbHeap, nbSticks;
	
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
	
	if (nbHeap == 1)
		heapA = heapA >> nbSticks;
	if (nbHeap == 2)	
		heapB = heapB >> nbSticks;
	if (nbHeap == 3)
                heapC = heapC >> nbSticks;

}

int validMove(heapNb, nbSticks)
{
	//TODO
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

void conclusion()
{
	if(mode == 1)
	{
		printf("Display winner in Computer mode\n");
	}
	else
	{
		printf("Display winner in  mode\n");
	}


	//printf("Do you want to display full log of the game?\n");
	
}

void main(void)
{
	char begin;
	int toPlay, win;	

	begin = initialization();
	if(begin == 'y')
		toPlay = 1;
	else
		toPlay = 2;
	do
	{
		if(toPlay == 1)
		{
			if(mode == 1 && begin != 'y')
                                computerTurn();
                        else
                                playerTurn(toPlay);
				toPlay == 2;
		}
		else if(toPlay == 2)
		{
			if(mode == 1 && begin == 'y')
				computerTurn();
			else
				playerTurn(toPlay);
			toPlay == 1;
		}
		displayGame();	
	}
	while(endGame() == 1);
	conclusion();
}
