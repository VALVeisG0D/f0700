#include "stdio.h"
#include "f0700.h"

int main()
{
	int diff = 0;
	srand(time(0));

	printf("%s\n", "Testing...");

	for (int a1 = 64; a1 <= 256; a1 *= 2)
	{
		for (int a3 = 2; a3 <= 6; ++a3)
		{
			for (int i = 0; i < 5000; ++i)
			{
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

				int a4[116] = { 0 };
				int a5[116] = { 0 };

				if (f0700(a1, a2, a3, a4) - f0701(a1, a2, a3, a5))
					++diff;
			}
		}
	}

	printf("%s%d\n", "Number of times test failed (New output does not match original output): ", diff);
	printf("%s", "Press enter to exit.");
	fgetc(stdin);

	return 0;
}