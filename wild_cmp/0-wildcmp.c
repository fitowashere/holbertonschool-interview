#include "holberton.h"

/**
 * wildcmp - compares two strings with wildcard support
 * @s1: first string to compare
 * @s2: second string (can contain '*' wildcards)
 *
 * Description: The '*' character in s2 can match any string
 * Return: 1 if strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* Base cases */
	if (*s2 == '\0')
		return (*s1 == '\0');

	if (*s2 == '*')
	{
		/* Skip consecutive asterisks */
		while (*s2 == '*')
			s2++;

		/* If pattern ends with '*', it matches rest of s1 */
		if (*s2 == '\0')
			return (1);

		/* Try matching '*' with empty string, then with each suffix of s1 */
		while (*s1 != '\0')
		{
			if (wildcmp(s1, s2))
				return (1);
			s1++;
		}

		/* Try matching '*' with empty string at end */
		return (wildcmp(s1, s2));
	}

	/* If current characters don't match and s2 is not '*', no match */
	if (*s1 == '\0' || *s1 != *s2)
		return (0);

	/* Characters match, continue with next characters */
	return (wildcmp(s1 + 1, s2 + 1));
}
