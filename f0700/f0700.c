#include "stdio.h"
#include "f0700.h"

int main()
{
	int numTestFailed = 0;
	int intArrayArgument0[1408];
	int intArrayArgument1[116] = { 0 };
	int intArrayArgument1Copy[116] = { 0 };
	srand(time(0));

	printf("%s\n", "Testing...");

	//	Iterate through the possible values for intArgument0 and intArgument1 [64, 128, 256] and [2, 3, 4, 5,6], respectively.
	//	Randomly generate int values between -4095 and 4095 for each element in intArrayArgument0.
	//	Initialize intArrayArgument1 and its copy with 116 0s.
	//	Check if the output of the updated/refactored code deviates from the original. (The test failes if it does)
	//	Repeat the test for 5000 times for each combination of intArgument0 and intArgument1
	//for (int intArgument0 = 64; intArgument0 <= 256; intArgument0 *= 2)
	for (int intArgument0 = 1; intArgument0 <= 6; ++intArgument0) //intArgument0 cannot be 0
	{
		for (int intArgument1 = 2; intArgument1 <= 6; ++intArgument1)
		{
			for (int i = 0; i < 1000; ++i)
			{
				for (int j = 0; j < 1408; ++j)
				{
					int temp = rand();

					if (rand() % 2)
						temp = -temp;

					if (temp <= 4095 && temp >= -4095)
						intArrayArgument0[j] = temp;
					else
						intArrayArgument0[j] = 0;
				}

				if (f0700(intArgument0, intArrayArgument0, intArgument1, intArrayArgument1) 
					- f0701(intArgument0, intArrayArgument0, intArgument1, intArrayArgument1Copy))
					++numTestFailed;
			}
		}
	}

	for (int i = 0; i < 116; ++i)
		if (intArrayArgument1[i] != intArrayArgument1Copy[i])
		{
			printf("%s\n", "intArrayArgument1 mismatch, test failed");
			fgetc(stdin);

			return 1;
		}

	printf("%s%d\n", "Number of times test failed (New output does not match original output): ", numTestFailed);
	printf("%s", "Press enter to exit.");
	fgetc(stdin);

	return 0;
}