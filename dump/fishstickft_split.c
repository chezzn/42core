#include "libft.h"

// count number of substrings in string 'str' based on delimiter 'c'
static int	count_strings(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c) // skip consecutive delimiters
			i++;
		if (str[i] != '\0') // count substrings
			count++;
		while (str[i] != '\0' && !(str[i] == c)) // skip characters in substring
			i++;
	}
	return (count); // return number of substrings
}

// free memory associated with an array of strings and array itself
static char	**ft_freeup(char **strs)
{
	int	i;

	if (strs)
	{
		i = 0;
		while (strs[i] != NULL)
		{
			free(strs[i]); // free memory for each individual string 
			i++;
		}
		free(strs); // free array itself
	}
	return (NULL); // return NULL to indicate memory has been freed
}

// copy characters from string to substring
/*
1. 
*/
static char	*ft_word(char const *str, char c)
{
	int		len_word;
	int		i;
	char	*word;

	len_word = 0;
	i = 0;
	while (str[len_word] && !(str[len_word] == c))
		len_word++;
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**strings;
	int		i;

	i = 0;
	strings = (char **)malloc(sizeof(char *) * (count_strings(str, c) + 1));
	if (!strings)
		return (NULL);
	while (*str != '\0')
	{
		while (*str != '\0' && (*str == c))
			str++;
		if (*str != '\0')
		{
			strings[i] = ft_word(str, c);
			if (strings[i] == NULL)
				return (ft_freeup(strings));
			i++;
		}
		while (*str && !(*str == c))
			str++;
	}
	strings[i] = 0;
	return (strings);
}