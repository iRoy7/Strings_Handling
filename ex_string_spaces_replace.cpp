#include "stdafx.h"
#include <stdio.h>

const int SMAX = 256;
char OUT[SMAX];

static void
spaces_replace(const char* str, int ln, int scnt)
{
	for (int i = 0; i < SMAX; i++)
		OUT[i] = 0;

	int nlen = ln + scnt * 2;
	OUT[nlen] = '\0';

	for (int i = ln - 1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			OUT[nlen - 1] = '0';
			OUT[nlen - 2] = '3';
			OUT[nlen - 3] = '%';
			nlen = nlen - 3;
		}
		else
		{
			OUT[nlen - 1] = str[i];
			nlen = nlen - 1;
		}
	}
}

int main()
{
	freopen("ex_string_spaces_replace.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		char BUF[SMAX];
		int ln;
		scanf(" %[^\n]\n", BUF);
		scanf("%d", &ln);

		int spc_cnt = 0;
		for (int i = 0; i < ln; i++)
			if (BUF[i] == ' ')
				spc_cnt++;

		if (spc_cnt > 0)
		{
			spaces_replace(BUF, ln, spc_cnt);
			printf("Replaced string is %s\n", OUT);
		}
		else
			printf("There is no spaces!\n");
	}

	return 0;
}