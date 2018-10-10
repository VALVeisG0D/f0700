#ifndef __f0700_h__
#define __f0700_h__

// *********************************************************************
//
//  Thanks for your interest in this position. In this preliminary 
//  screen process, you are given the following native 32-bit C code:
//
//    1. Refactor/rewrite the code into a SOLID readable code
//       - A READABLE code should allow other programmers to fully 
//         understand what the code is doing, by just glancing over it 
//         (within 3-5 seconds) without having to read through lengthy
//         comments / documentation, thus improving the overall
//         productivity of the team
//       - A READABLE code should be "self-explanatory", short, 
//         consistent, and properly structured that allow seamless 
//         communication across team
//       - Keep in mind, there is no absolutely right/wrong way. But
//         we mostly interested in candidates who can boost the overall
//         productivity of the code review team. Here are few
//         suggestions you may consider:
//         - eliminate unnecessary pointer arithmetics
//         - eliminate unnecessary variables/loop/calculation
//         - keep it super simple, DON'T write code that only hardcore 
//           programmers can understand; DO write high level code that 
//           every programmers one can read
//
//    2. What strategy would you use to verify that your code is correct?
//
//    3. Explain what the code is trying to accomplish intuitively
//
//    4. Please show us how you accomplish all #1, #2, #3:
//       - Setup a project with Visual Studio 2015 (or higher) on Win7
//         so that we can verify that your code is working properly
//       - Version control your steps with Git to help our reviewers 
//         to validate/review your code
//       - Zip your Git repo and email it back to us for further review
//
//  Good Luck!
//
// ********************************************************************


signed int __cdecl f0700(int intArgument0, int *intArrayArgument0, int intArgument1, int *intArrayArgument1)
{
	// Pre-Condition:
	//    intArgument0: possible input value = [64, 128, 256]
	//    intArrayArgument0: is an int[1408] array
	//        possible input value for each element = [-4095 ... 4095]
	//    intArgument1: possible input value = [2, 3, 4, 5, 6]
	//    intArrayArgument1: is an int[116] array
	//        possible input value for each element = [0]
	//
	// Post-Condition:
	//    intArgument0: value shouldn't change
	//    intArrayArgument0: value shouldn't change
	//    intArgument1: value shouldn't changed
	//    intArrayArgument1: value can changed


	int *v4;
	int v5;
	int v6;
	int v7;
	int *intPointer4 = intArrayArgument0;
	int intVariable5 = intArgument0;
	int intVariable6 = 0;
	int intVariable7 = intArrayArgument0[intArgument0];
	int intVariable9 = -1;
	int *intPointer10 = intArrayArgument1;
	int intVariable11;
	int intVariable12;
	int intVariable13;
	int intVariable14 = intArrayArgument0[intArgument0 - 1];
	int intVariable15 = intVariable7;
	int a2a = 0;
	int output = 0;

	intArrayArgument0[intArgument0 - 1] = 10000;
	intArrayArgument0[intArgument0] = -10000;

	do
	{
		intVariable11 = (int)&intPointer4[intVariable6++];
		*intPointer10 = intVariable11;
		intVariable12 = (int)&intPointer4[intVariable6];

		if (intVariable9 * (*(int *)intVariable11 - *(int *)intVariable12) < intArgument1)
		{
			do
			{
				if (intVariable9 * *(int *)intVariable12 > intVariable9 * *(int *)*intPointer10)
					*intPointer10 = intVariable12;
				intVariable13 = *(int *)(intVariable12 + 4);
				intVariable12 += 4;
				++intVariable6;
			} while (intVariable9 * (*(int *)*intPointer10 - intVariable13) < intArgument1);
			intVariable5 = intArgument0;
		}

		++intPointer10;
		intVariable9 = -intVariable9;
		output = a2a++ + 1;
	} while (intVariable6 < intVariable5);

	if (output % 2)
		--output;

	intPointer4[intVariable5 - 1] = intVariable14;
	intPointer4[intVariable5] = intVariable15;

	return output;
}

#endif