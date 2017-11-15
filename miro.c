#include <stdio.h>
#include <Windows.h>
#include <string.h>
int main(){
	SetConsoleOutputCP(1251);
	char str[256],Word[256], minWord[256], maxWord[256];
	int i,j,count=0,inWord=0,maxMin=0;
	while (printf("Enter text.Forend-CTR/Z"),fgets(str, 255, stdin) != NULL)
	{
		i = 0, j = 0;
		for (; str[i]; i++)
		{
			if (inWord == 0)
			{
				if (str[i] != '\n'&&str[i] != '\t'&&str[i] != ' ')
				{
					inWord = 1;
					Word[j++] = str[i];
				}
			}
			else
			{
				if (str[i] != '\n'&&str[i] != '\t'&&str[i] != ' ')
					Word[j++] = str[i];
				else
				{
					Word[j] = '\0';
					j = 0;
						printf("\n%s", Word);
					count++;
					if (maxMin == 0)
					{
						strcpy(maxWord, Word);
						strcpy(minWord, Word);
						maxMin = 1;
					}
					else
					{
						if (strlen(maxWord) < strlen(Word))
							strcpy(maxWord, Word);
						if (strlen(minWord)>strlen(Word))
							strcpy(minWord, Word);
					}
				}
			}
		}
	}
	return 0;
}
