#include "x11.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	{
		char in[80];
		char hash[32];
		char res[32];
		// haslist.data contains data in format "Data:[input]Hash:[hash]\n" in binary format getted from cpu dashcoin miner
		FILE* f = fopen("hashlist.data", "rb");
		if (f)
		{
			char buf[128];
			while (1)
			{
				unsigned r = fread(buf, 1, 6, f);
				if (!r)
					break;
				r = fread(in, 1, 80, f);
				if (!r)
					break;
				r = fread(buf, 1, 7, f);
				if (!r)
					break;
				r = fread(hash, 1, 32, f);
				if (!r)
					break;
				r = fread(buf, 1, 2, f);
				if (!r)
					break;
				x11_hash(in, res);
				if (memcmp(res, hash, 32) != 0)
				{
					printf("ERROR, incorrect hash\n");
				}
				else
				{
					printf("Correct hash\n");
				}
			}
			fclose(f);
		}
	}
	return 0;
}