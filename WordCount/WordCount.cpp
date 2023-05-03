#include <stdio.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)
int main(int argc, char* argv[]) {
	char ch;
	if (argc != 3)
	{
		printf("please use '-c' or '-w' + 'fliename'\n");
		return 0;
	}
	int mode;
	if (strcmp(argv[1], "-c") == 0) {
		mode = 1;
	}
	else if (strcmp(argv[1], "-w") == 0)
	{
		mode = 2;
	}
	else
	{
		printf("please use '-c' or '-w'");
			return 0;
	}
	FILE *fp;
	fp = fopen(argv[2],"r");
		if (fp == NULL)
		{
			printf("this file cant open,please change");
			return 0;
		}
	int char_num = 0, word_num = 0;
	int mark = 0;
	while ((ch = fgetc(fp)) != EOF)
	{
		char_num++;
		if (ch == ' ' || ch == ',')
		{
			word_num++;
		}

	}
	fclose(fp);
	if (mode == 1)
	{
		printf("characters number: %d ", char_num);
	}
	else {
		printf("words number: %d ", word_num);
	}
	return 0;
	
}