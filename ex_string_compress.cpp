
#include "stdafx.h"
#include <stdio.h>

const int SUCCESS = 1;
const int FAIL = 0;
const int SMAX = 256;
char BUF[SMAX];

int string_compress(const char* str)
{
	for (int i = 0; i < SMAX; i++)
		BUF[i] = 0;

	int sln;
	for (sln = 0; str[sln]; sln++);

	// Base case:
	if (sln < 2) return FAIL;

	// General case:
	int cnt = 1;
	int bidx = 0;

	for (int i = 1; i < sln; i++)
	{
		if (str[i - 1] == str[i])
			cnt++;
		else
		{                   
			BUF[bidx++] = str[i - 1];

			char tmp[5];
			sprintf(tmp, "%d", cnt);

			int tln;
			for (tln = 0; tmp[tln]; tln++);
			for (int j = 0; j < tln; j++)
				BUF[bidx++] = tmp[j];

			cnt = 1;
		}

		//int bln;
		//for (bln = 0; BUF[bln]; bln++);
		//if (bln >= sln) return FAIL;
		if (bidx >= sln) return FAIL;
	}

	//printf("[>> bidx = %d, sln = %d\n", bidx, sln);

	BUF[bidx++] = str[sln - 1];

	if (cnt > 1)
	{
		char tmp[5];
		sprintf(tmp, "%d", cnt);
		
		int tln;
		for (tln = 0; tmp[tln]; tln++);

		//printf("[>>> tmp = %s, tln = %d\n", tmp, tln);

		for (int i = 0; i < tln; i++)
			BUF[bidx++] = tmp[i];

		//int bln;
		//for (bln = 0; BUF[bln]; bln++);
		//printf("[>>>> bln = %d, bidx = %d\n", bln, bidx);
		//if (bln >= sln) return FAIL;
		if (bidx >= sln) return FAIL;
	}

	return SUCCESS;
}

int main()
{
	freopen("ex_string_compress.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		char str[SMAX];
		scanf("%s", str);

		if (string_compress(str) == SUCCESS)
			printf("Compressed: %s\n", BUF);
		else
			printf("Not compressed!\n");
	}

	return 0;
}