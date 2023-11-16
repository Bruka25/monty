#include "monty.h"


char **strtow(char *str, char *delims);

/**
 *strtow - Takes a str and seperates its words
 *
 *@str: Str to seperate into words
 *@delims: Delimitors to use to delimit words
 *
 *Return: 2D array of pointers to each word
 */

char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = word_count(str, delims);


	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = word_len(str, delims);
		if (is_delimiter(*str, delims))
		{
			str = next_word(str, delims);
		}
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0'; /* set end of str */
		str = next_word(str, delims);
		i++;
	}
	words[i] = NULL; /* last element is null for iteration */
	return (words);
}

/**
 *is_delimiter - Checks if stream has delimitor char
 *
 *@ch: character in stream
 *
 *@delims: Pointer to null terminated array of delimitors
 *
 *Return: 1 (success) 0 (failure)
 */

int is_delimiter(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}
