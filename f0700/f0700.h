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

signed int __cdecl f07080(int intArgument0, int *intArrayArgument0, int intArgument1, int *intArrayArgument1)
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

	int arrayIndex0 = 0;	//	Array index for intArrayArgument0.
	int arrayIndex1 = 0;	//	Array index for intArrayArgument1.
	int signChange = -1;	//	Switch value between -1 and 1 after every 
							//		iteration of the outer do while loop
							//		(This effects the condition of the inner 
							//		if and do while statements)
	int output = 0;			//	The value to return from the function.

	//	Sets the condition to exit out of the inner do while loop
	//		without fail
	intArrayArgument0[intArgument0 - 1] = 10000;
	intArrayArgument0[intArgument0] = -10000;

	//	-Initially copy an element from intArrayArgument0 to intArrayArgument1. 
	//	-Then traverse intArrayArgument0 looking for an element with a larger value than that which was copied to intArrayArgument1. 
	//	-If an element in intArrayArgument0 is found to be larger than the copied value in intArrayArgument1, overwrite the copied
	//		value in intArrayArgument1 with the larger value. 
	//	-Repeat until the inner do while loop condition fails.
	//	-The number of iterations of the inner do while loop determines how often the outer do while loop iterates
	//		and thus, how often output is incremented and how much of the elements in intArrayArgument1 contains values from
	//		intArrayArgument0.
	do
	{
		intArrayArgument1[arrayIndex1] = intArrayArgument0[arrayIndex0++];

		if (signChange * (intArrayArgument0[arrayIndex0 - 1] - intArrayArgument0[arrayIndex0]) < intArgument1)
		{
			do
			{
				if (signChange * intArrayArgument0[arrayIndex0] > signChange * intArrayArgument1[arrayIndex1])
					intArrayArgument1[arrayIndex1] = intArrayArgument0[arrayIndex0];

			} while (signChange * (intArrayArgument1[arrayIndex1] - intArrayArgument0[++arrayIndex0]) < intArgument1);
		}

		++arrayIndex1;
		signChange = -signChange;
		++output;
	} while (arrayIndex0 < intArgument0);

	//	If output is odd, decrement output by 1
	if (output % 2)
		--output;

	return output;
}


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

	int intVariable6 = 0;
	int intVariable9 = -1;
	int *intPointer10 = intArrayArgument1;
	int intVariable12;
	int output = 0;

	intArrayArgument0[intArgument0 - 1] = 10000;
	intArrayArgument0[intArgument0] = -10000;
	
	do
	{
		*intPointer10 = (int)&intArrayArgument0[intVariable6++];
		intVariable12 = (int)&intArrayArgument0[intVariable6];

		if (intVariable9 * (intArrayArgument0[intVariable6 - 1] - intArrayArgument0[intVariable6]) < intArgument1)
		{
			do
			{
				if (intVariable9 * intArrayArgument0[intVariable6] > intVariable9 * *(int *)*intPointer10)
					*intPointer10 = intVariable12;

				++intVariable6;
			} while (intVariable9 * (*(int *)*intPointer10 - *(int *)(intVariable12 += 4)) < intArgument1);
		}

		++intPointer10;
		intVariable9 = -intVariable9;
		++output;
	} while (intVariable6 < intArgument0);

	if (output % 2)
		--output;

	return output;
}

//	Original copy of the code for comparison and testing
signed int __cdecl f0701(int a1, int *a2, int a3, int *a4)
{
	// Pre-Condition:
	//    a1: possible input value = [64, 128, 256]
	//    a2: is an int[1408] array
	//        possible input value for each element = [-4095 ... 4095]
	//    a3: possible input value = [2, 3, 4, 5, 6]
	//    a4: is an int[116] array
	//        possible input value for each element = [0]
	//
	// Post-Condition:
	//    a1: value shouldn't change
	//    a2: value shouldn't change
	//    a3: value shouldn't changed
	//    a4: value can changed


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

	v4 = a2;
	v5 = a1;
	v6 = 0;
	v7 = a2[a1];
	v14 = a2[a1 - 1];
	o1 = 0;
	v9 = -1;
	a2[a1 - 1] = 10000;
	v15 = v7;
	a2[a1] = -10000;
	a2a = 0;

	if (a1 > 0)
	{
		v10 = a4;
		do
		{
			v11 = (int)&v4[v6++];
			*v10 = v11;
			v12 = (int)&v4[v6];
			if (v9 * (*(int *)v11 - *(int *)v12) < a3)
			{
				do
				{
					if (v9 * *(int *)v12 > v9 * *(int *)*v10)
						*v10 = v12;
					v13 = *(int *)(v12 + 4);
					v12 += 4;
					++v6;
				} while (v9 * (*(int *)*v10 - v13) < a3);
				v5 = a1;
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