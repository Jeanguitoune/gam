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
	//printf();
	
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
	int begin;
	int win;	

	//========================
	// Initialization
	//========================

	heapA = 0x3f;// 6 sticks heap
	heapB = 0x1f;// 5 sticks heap
	heapC = 0x0f;// 4 sticks heap
	
	do
	{ 
		printf("Do you want to begin? (0: No) (1: Yes)\n");
		scanf("%d", &begin);
	}while(begin != 0 && begin != 1);
	
	if(begin == 1)
		printf("You begin\n");
	else
		printf("The AI begin\n");

	do
	{
	printf("Which heap do you want to remove sticks from?");
	scanf("%d", &nbHeap);
	}while();
	
	do
	{
	printf("How much do you want to remove sticks");
	scanf("%d", &nbSticks);
	}while(nbSticks < 1 && nbSticks > 3);
	
	if (nbHeap == 1)
		heapA = decrementHeap(nbHeap, nbSticks);
	

	/*
	do
	{
		printf();
		scanf();
	

	}while( choosen_heap > 3 || choosen_heap < 1 );
	*/
	
	
}
