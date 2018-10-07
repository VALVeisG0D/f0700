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
	int o1;
	int v9;
	int *v10;
	int v11;
	int v12;
	int v13;
	int v14;
	int v15;
	int a2a;

	v4 = intArrayArgument0;
	v5 = intArgument0;
	v6 = 0;
	v7 = intArrayArgument0[intArgument0];
	v14 = intArrayArgument0[intArgument0 - 1];
	o1 = 0;
	v9 = -1;
	intArrayArgument0[intArgument0 - 1] = 10000;
	v15 = v7;
	intArrayArgument0[intArgument0] = -10000;
	a2a = 0;

	if (intArgument0 > 0)
	{
		v10 = intArrayArgument1;
		do
		{
			v11 = (int)&v4[v6++];
			*v10 = v11;
			v12 = (int)&v4[v6];
			if (v9 * (*(int *)v11 - *(int *)v12) < intArgument1)
			{
				do
				{
					if (v9 * *(int *)v12 > v9 * *(int *)*v10)
						*v10 = v12;
					v13 = *(int *)(v12 + 4);
					v12 += 4;
					++v6;
				} while (v9 * (*(int *)*v10 - v13) < intArgument1);
				v5 = intArgument0;
			}
			++v10;
			v9 = -v9;
			o1 = a2a++ + 1;
		} while (v6 < v5);
	}
	if (o1 % 2)
		--o1;
	v4[v5 - 1] = v14;
	v4[v5] = v15;
	return o1;
}

#endif