#include "stdio.h"
#include "f0700.h"

int main()
{
	int a2[1408];
	int a4[116];

	printf("%d\n", sizeof('A'));
	printf("%d\n", f0700(64, a2, 4, a4));

	fgetc(stdin);

	return 0;
}