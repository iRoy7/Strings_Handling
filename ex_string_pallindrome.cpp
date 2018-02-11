#include "stdafx.h"
#include <stdio.h>
const int SMAX = 256;

inline int char_id_get(char ch)
{
	int ret = -1;
	if (ch >= 'a' && ch <= 'z') ret = ch - 'a';
	else if (ch >= 'A' && ch <= 'Z') ret = ch - 'A';
	return ret;
}

int is_pallindrome2(const char* str)
{
	int odd_cnt = 0;
	int freq[26] = { 0, };
	int cid = 0;

	for (int i = 0; str[i]; i++)
	{
		cid = char_id_get(str[i]);

		if (cid != (-1))
		{
			++freq[cid];
			// IMPORTANT!
			if (freq[cid] % 2) ++odd_cnt;
			else --odd_cnt;
			continue;
		}
		else
		{
			if (str[i] != ' ')
				printf("RoY:> ERRoR!\n");
		}
	}

	// Checking...
	if (odd_cnt <= 1) return 1;
	else return 0;
}

int main()
{
	freopen("ex_string_pallindrome.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		char BUF[SMAX];
		scanf(" %[^\n]\n", BUF);

		printf("Does \"%s\" has a string whose permutation is a pallindrome?\n \
		(1 for ture, 0 for false):\n", BUF);
		printf("Approach 2: %d\n", is_pallindrome2(BUF));
	}

	return 0;
}
