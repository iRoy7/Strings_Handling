
#include "stdafx.h"

const int YES = 1;
const int NO = 0;
const int SMAX = 256;
const int LIMIT = 300;

int VPS_check(const char* str)
{
	//printf("[>  input string %s\n", str);
	// Simple array stack
	int top = -1;
	int STACK[LIMIT] = { 0 };
	int right_err = 0;
	int pair_err = 0;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '(')
			STACK[++top] = 1;
		else if (str[i] == ')')
		{
			if (top == (-1)) right_err++;
			else if (top + 1 > 0)
			{
				if (STACK[top] == 1)
					STACK[top--];
				else
					pair_err++;
			}
		}
	}

	if (top + 1 == (0))
	{
		if (right_err > 0 || pair_err > 0)
			return NO;
		else
			return YES;
	}
	else
		return NO;
}

int main()
{
	freopen("ex_stack_VPS_string_check.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		char str[SMAX];
		scanf("%s", str);

		printf("#%d - %s\n", tc, (VPS_check(str)) ? "YES" : "NO");
		//stk_clean();
	}

	return 0;
}