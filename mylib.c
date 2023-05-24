#include "monty.h"

/**
  * _isdigit - check for a digit
  * @c: int to be checked
  *
  * Return: 1 if c is a digit, 0 otherwise
  */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
  * isint - checks if str is int
  * @s: str to be checked
  *
  * Return: 1 if true, 0 if false
  */
char isint(char *s)
{
	if (s && *s == '-')
		s++;
	while (s && *s)
	{
		if (!_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}


/**
  * reverse - reverses a string
  * @str: str to be reversed
  */
void reverse(char str[])
{
	int start = 0;
	int end = strlen(str) - 1;

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}

/**
  * citoa - converts int to str, int > 0
  * @num: num to be converted
  * @str: str buffer
  *
  * Return: str buffer pointer
  */
char *citoa(int num, char *str)
{
	int i = 0;

	while (num != 0)
	{
		int rem = num % 10;

		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num /= 10;
	}
	str[i] = '\0';
	reverse(str);
	return (str);
}
