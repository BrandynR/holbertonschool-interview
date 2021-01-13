#include "regex.h"

/**
* regex_match - function checks whether a given pattern matches a given string
* @str: is the string to scan
* @pattern: is the regular expression
* Return: return 1 if true, 0 if not
*/
int regex_match(char const *str, char const *pattern)
{
	int none = 0;

	if (!str)
		return (none);
	if (!*str)
	{
		if (*(pattern + 1) == '*')
			return (regex_match(str, pattern + 2));
		return (!*pattern);
	}
	if (*(pattern + 1) == '*')
	{
		if (*pattern == '.' || *pattern == *str)
			return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
		return (regex_match(str, pattern + 2));
	}
	if (*pattern == '.' || *pattern == *str)
	{
		return (regex_match(str + 1, pattern + 1));
	}
	return (none);
}
