#include <stdlib.h>
#include <string.h>

/**
 * find_substring - finds substrings
 * @s: is the string to scan
 * @words: array of words all substrings must be a concatenation arrangement of
 * @nb_words: number of elements in the array 'words'
 * @n: address at which to store the number of elements in the returned array
 * Return: array containing indexes
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	char *temp = NULL, *p = NULL;
	int slen, len = 0, count = 0, wordlen, i, j, k;
	int *pmark = NULL;

	slen = strlen(s);
	wordlen = strlen(words[0]);
	len = wordlen * nb_words;
	temp = calloc((len + 1), sizeof(char));
	pmark = calloc((slen + 1), sizeof(char));
	for (i = 0; i <= slen - len;)
	{
		strncpy(temp, &s[i], len);
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < len;)
			{
				p = strstr(temp + k, words[j]);
				if (p != NULL && ((p - temp) % wordlen) == 0)
					break;
				else if (p != NULL)
				{
					k = p - temp + 1;
					p = NULL;
				}
				else if (p == NULL)
					goto nextseg;
			}
			if (p != NULL)
				memset(p, '.', wordlen);
			else
				goto nextseg;
		}
		if (slen != 0 && len != 0)
			pmark[count++] = i;
nextseg:
		i++;
	}
	free(temp);
	*n = count;
	return (pmark);
}
