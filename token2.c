#include "monty.h"

/**
 *word_len - Gets the word length of cur word in str
 *
 *@str: Str to get word length from current word
 *@delims: Delimitors to use to delimit words
 *
 *Return: Word length of current word
 */

int word_len(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delimiter(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}

/**
 *word_count - Gets the word count of a str
 *
 *@str: Str to get word count from
 *@delims: Delimitors to use to delimit words
 *
 *Return: Word count of the str
 */

int word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 *next_word - Gets the next word in a str
 *
 *@str: Str to get next word from
 *@delims: Delimitors to use to delimit words
 *
 *Return: Pointer to first char of next word
 */

char *next_word(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
