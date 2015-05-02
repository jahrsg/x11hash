#include "x11.h"

int main(int argc, char** argv)
{
	char res[33];
	memset(res, 33, 0);
	if(argc > 1)
		x11_hash(argv[1], res);
	else
	{
		char in[80];
		int i;
		for (i = 0; i < 80; i++)
			in[i] = i;
		x11_hash(in, res);
	}
	printf("%s", res);
	return 0;
}