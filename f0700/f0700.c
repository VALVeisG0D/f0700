#include "stdio.h"
#include "f0700.h"

int main()
{
	srand(time(0));

	for (int i = 0; i < 5400; ++i)
	{
		int a1 = 128;
		int a2[1408];

		for (int j = 0; j < 1407; ++j)
		{
			int temp = rand();

			if (rand() % 2)
				temp = -temp;

			if (temp <= 4095 && temp >= -4095)
				a2[j] = temp;
			else
				a2[j] = 0;
		}

		int a3 = 6;
		int a4[116] = { 0 };
		int a5[116] = { 0 };

		printf("%d\n", f0700(a1, a2, a3, a4));
		printf("%d\n\n", f0701(a1, a2, a3, a5));
	}

	fgetc(stdin);

	return 0;
}