#include "stdafx.h"
#include <stdio.h>

const int SMAX = 256;
inline int ABS(int a) { return (a < 0) ? (-a) : (a); }

int one_edit_away(const char* str1, const char* str2, int ln1, int ln2)
{
	// Base case:
	if (ABS(ln1 - ln2) > 1) return 0;

	// General cases:
	char SMALL[SMAX], BIG[SMAX];
	int sln, bln;
	if (ln1 < ln2)
	{
		sln = ln1, bln = ln2;
		for (int i = 0; i < sln; i++)
			SMALL[i] = str1[i];
		for (int i = 0; i < bln; i++)
			BIG[i] = str2[i];
	}
	else
	{
		sln = ln2, bln = ln1;
		for (int i = 0; i < sln; i++)
			SMALL[i] = str2[i];
		for (int i = 0; i < bln; i++)
			BIG[i] = str1[i];
	}
	// Checking...
	unsigned int sidx = 0;
	unsigned int bidx = 0;
	int mismatch_done = 0;

	while (sidx < sln && bidx < bln)
	{
		if (SMALL[sidx] != BIG[bidx])
		{
			if (mismatch_done) return 0;

			mismatch_done = 1;

			// IMPORTANT!
			if (sln == bln) ++sidx;
		}
		else ++sidx;

		++bidx;
	}

	return 1;
}


int main()
{
	freopen("ex_string_one_edit_away.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		char BUF1[SMAX], BUF2[SMAX];
		scanf("%s %s", BUF1, BUF2);

		int ln1, ln2;
		for (ln1 = 0; BUF1[ln1]; ln1++);
		for (ln2 = 0; BUF2[ln2]; ln2++);

		if (one_edit_away(BUF1, BUF2, ln1, ln2) == 1)
			printf("\"%s\" and \"%s\" are one edit away!\n", BUF1, BUF2);
		else
			printf("\"%s\" and \"%s\" are NOT one edit away!\n", BUF1, BUF2);
	}

	return 0;
}
