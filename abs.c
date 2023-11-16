#include "monty.h"

/**
 *_absolute - Gets the absolute value of an int
 *
 *@i: Number to get absolute value of
 *
 *Return: Unsigned integer
 */
unsigned int _absolute(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}
