#include "stdafx.h"
const int SMAX = 256;
const int TRUE = 1;
const int FALSE = 0;
char S1[SMAX], S2[SMAX];
char BUF[2 * SMAX];

int search1(const char* src, const char* tar)
{
	int bid = -1;
	int i, j;
	i = j = 0;

	while (src[i] != '\0')
	{
		while (src[i] != tar[0] && src[i] != '\0')
			i++;

		if (src[i] == '\0') return bid;

		bid = i;
		while (src[i] == tar[j] && src[i] != '\0' && tar[j] != '\0')
			i++, j++;
		
		if (tar[j] == '\0') return bid;
		if (src[i] == '\0') return (-1);

		i = bid + 1;
		j = 0;
	}
}

int search2(const char* src, const char* tar, int sln, int tln)
{
	int ret = 0;
	for (int i = 0; i < sln - tln; i++)
	{
		for (int j = i; j < i + tln; j++)
		{
			ret = 1;
			if (src[j] != tar[j - i])
			{
				ret = 0;
				break;
			}
		}

		if (ret == 1) break;
	}
	return ret;
}

int is_rotated_str(const char* src, const char* tar)
{
	int sln, tln;
	for (sln = 0; src[sln]; sln++);
	for(tln = 0; tar[tln]; tln++);
	// Base case: 
	if (sln == 0 || sln != tln) return FALSE;

	// Main logic
	int bid = 0;
	int bln = sln * 2;
	// Creates twice duplicated source string
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < sln; j++)
			BUF[bid++] = src[j];

#if 0
	if (search1(BUF, tar) >= 0)
#else
	if (search2(BUF, tar, bln, tln) > 0)
#endif
		return TRUE;
	else
		return FALSE;
}

int main()
{
	freopen("ex_string_rotate.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%s %s", S1, S2);
		if (is_rotated_str(S1, S2) == TRUE)
			printf("Yes, %s is a rotation of %s.\n", S2, S1);
		else
			printf("No, %s is not a part of source %s string.\n", S2, S1);
	}
	return 0;
}