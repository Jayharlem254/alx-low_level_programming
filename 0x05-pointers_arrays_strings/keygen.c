#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random valid passwords for 101-crackme program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char password[84];
	int index, ascii_code;
	int sum = 0;

	srand(time(0));

	for (index = 0; sum < 2772 - 126; index++)
	{
		ascii_code = rand() % 126;
		if (ascii_code == 0)
			continue;
		password[index] = (char)ascii_code;
		sum += ascii_code;
	}

	password[index] = (char)(2772 - sum);
	password[++index] = '\0';

	printf("%s\n", password);

	return (0);
}

