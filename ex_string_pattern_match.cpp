#include "stdafx.h"
#include <stdio.h>

const int SMAX = 256;

static int 
brute_force(const char* ptn, const char* src, int pln, int sln)
{
	// base case:
	if (sln < pln) return 0;

	// general case:
	int ptn_cnt = 0;
	int pidx = 0;
	int sidx = 0;

	while (pidx < pln && sidx < sln)
	{
		if (src[sidx] != ptn[pidx])
		{
			sidx = sidx - pidx;
			pidx = -1;
		}

		sidx += 1;
		pidx += 1;

		if (pidx == pln)
		{
			ptn_cnt++;
			pidx = 0;
		}
	}

	if (sidx == sln && ptn_cnt > 0)
		return ptn_cnt;
	else
		return 0;
}

int main()
{
	freopen("ex_string_pattern_match.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		char PTN[SMAX], SRC[SMAX];
		scanf("%s %s", PTN, SRC);

		int pln, sln;
		for (pln = 0; PTN[pln]; pln++);
		for (sln = 0; SRC[sln]; sln++);

		printf("Pattern count = %d\n", brute_force(PTN, SRC, pln, sln));
	}

	return 0;
}