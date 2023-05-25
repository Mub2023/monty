#include "monty.h"
/**
 * strtow - takes a string and separates it words.
 * @str: string to seperate into words
 * @delims: delimitors to use to delimit words
 * Return: 2D array of pointers to each word
 */
char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int w, wordlen, n, x = 0;

	if (str == NULL || !*str)
		return (NULL);
	w = get_word_count(str, delims);

	if (w == 0)
		return (NULL);
	words = malloc((w + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (x < w)
	{
		wordlen = get_word_length(str, delims);
		if (is_delims(*str, delims))
		{
			str = get_next_word(str, delims);
		} words[x] = malloc((wordlen + 1) * sizeof(char));
		if (words[x] == NULL)
		{
			while (x >= 0)
			{
				x--;
				free(words[x]);
			}
			free(words);
			return (NULL);
		} n = 0;
		while (n < wordlen)
		{
			words[x][n] = *(str + n);
			n++;
		}
			words[x][n] = '\0';
			str = get_next_word(str, delims);
			x++;
	} words[x] = NULL;
	return (words);
}
/**
 * is_delims - checks if stream has delimitor char.
 * @ch: char in stream.
 * @delims: pointer to null terminted array
 * Return: 1 (SUCCESS) 0 (FAILURE)
 */
int is_delims(char ch, char *delims)
{
	int x = 0;

	while (delims[x])
	{
		if (delims[x] == ch)
			return (1);
		x++;
	}
	return (0);
}
/**
 * get_word_length - get the words length in str.
 * @str: the pointer of the string.
 * @delims: delimitors to use.
 * Return: word length of str.
 */
int get_word_length(char *str, char *delims)
{
	int wordlen = 0, pending = 1, x = 0;

	while (*(str + x))
	{
		if (is_delims(str[x], delims))
			pending = 1;
		else if (pending)
		{
			wordlen++;
		}
		if (wordlen > 0 && is_delims(str[x], delims))
			break;
		x++;
	}
	return (wordlen);
}
/**
 * get_word_count - gets the word count of a string
 * @str: the pointer of the string
 * @delims: delimitors to use.
 * Return: the word count.
 */
int get_word_count(char *str, char *delims)
{
	int wordC = 0, pending = 1, x = 0;

	while (*(str + x))
	{
		if (is_delims(str[x], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wordC++;
		}
		x++;
	}
	return (wordC);
}
/**
 * get_next_word - gets the next word in a string
 * @str: the pointer of the string
 * @delims: delimitors to use.
 * Return: pointer to first char of next word
 */
char *get_next_word(char *str, char *delims)
{
	int pending = 0, x = 0;

	while (*(str + x))
	{
		if (is_delims(str[x], delims))
			pending = 1;
		else if (pending)
			break;
		x++;
	}
	return (str + x);
}
