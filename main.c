#include <stdio.h>
#include <stdlib.h>

int decrementHeap(int heap, int nb)
{
	heap = heap >> nb;
	return heap;	
	// return heap >> nb;
}

void displayGame(int heapA, int heapB, int heapC)
{
	printf("=================================\n");
	printf("heapA: %d\n",heapA);
	printf("heapB: %d\n",heapB);
	printf("heapC: %d\n",heapC);
	printf("=================================\n");
}	

void displayLog()
{

}

int endGame(int heapA, int heapB, int heapC)
{
	
	return 0;
}


void main(void)
{
	unsigned int heapA, heapB, heapC;
	char begin;
	int nbSticks, nbHeap;
	int win;	

	heapA = 0x3f;// 6 sticks heap
	heapB = 0x1f;// 5 sticks heap
	heapC = 0x0f;// 4 sticks heap
	
	do
	{ 
		printf("Do you want to begin? (n: no) (y: yes)\n");
		scanf("%c", &begin);
	}while(begin != 'y' && begin != 'n');
	
	if(begin == 'y')
		printf("You begin\n");
	else
		printf("The AI begin\n");

	displayGame(heapA, heapB, heapC);	
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
		heapA = decrementHeap(heapA, nbSticks);
	if (nbHeap == 2)	
		heapB = decrementHeap(heapB, nbSticks);
	if (nbHeap == 3)
                heapC = decrementHeap(heapC, nbSticks);

	displayGame(heapA, heapB, heapC);	
	/*
	do
	{
		printf();
		scanf();

	}while( choosen_heap > 3 || choosen_heap < 1 );
	*/
	
	
}
