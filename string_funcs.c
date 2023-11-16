#include "monty.h"

/**
 *_strlen - Returns the length of a str
 *
 *@s: Pointer to the str
 *
 *Return: Length of the str
 */
int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}

/**
 *_strcpy -Copies a str pointed by source to dest
 *
 *@dest: Pointer to the destination of the copied str
 *@src: Pointer to the source str to be copied
 *
 *Return: Pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 *_strcat - Concantenates two str
 *
 *@dest: Pointer to destination str
 *@src: Pointer to source str
 *
 *Return: Pointer to dest
 */
char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}

/**
 *_strncat - Concantenates two str where n number
 *               of bytes are copied from source
 *
 *@dest: Pointer to destination str
 *@src: Pointer to source str
 *@n: n bytes to copy from src
 *
 *Return: Pointer to dest
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
