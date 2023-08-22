#include <stdio.h>

extern int load(int x, int y);

int main()
{
	int result = 0;
	int count =9;
	result = load(0x0,count+1);
	printf("sum of number from 1 to %d in %d\n",count,result);
}
