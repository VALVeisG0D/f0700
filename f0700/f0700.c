#include "stdio.h"
#include "f0700.h"

int main()
{
	for (int i = 0; i < 5400; ++i)
	{
		int a1 = 64;
		int a2[1408];

		srand(time(0));

		for (int i = 0; i < 1407; ++i)
		{
			int temp = rand();

			if (temp % 2)
				temp = -temp;

			if (temp <= 4095 && temp >= -4095)
				a2[i] = temp;
		}

		int a3 = 3;
		int a4[116];

		printf("%d\n", f0700(a1, a2, a3, a4));
		printf("%d\n\n", f0701(a1, a2, a3, a4));
	}

	fgetc(stdin);

	return 0;
}