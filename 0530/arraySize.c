#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void function();

int main()
{
	function();
	system("pause");
	return 0;
}

void function(){
	int array[SIZE];
	int lastItemIndex=SIZE-1;
	array[lastItemIndex] = 50;
	printf("array[%d]=%d", 
			lastItemIndex,
			array[lastItemIndex]);
}

