#include <stdio.h>
#include <stdlib.h>

void f(); 
int count=0;

int main()
{
	f();
	f();
	f();
	system("pause");
	return 0;
}

void f()
{
	int value;
	int* pValue = (int*)malloc(sizeof(int));
	printf("===================\n");
	printf("count = %d\n", count++);
	printf("&value = %p\n", &value);
	printf("pValue = %p\n", pValue);
	//free(pValue);
}

