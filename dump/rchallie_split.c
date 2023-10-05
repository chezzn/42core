#include "libft.h"

// calculate number of substrings in string 's' based on delimiter 'c'
static int	ft_hm(char const *s, char c)
{
	size_t	nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c) // skips over consecutive delimiters
			i++;
		if (i > 0 && s[i] != '\0' && s[i - 1] == c) // counts non-empty substrings
			nbr++;
		if (s[i] != '\0')
			i++;
	}
	if (nbr == 0 && s[i - 1] == c) // returns 0 if there are no non-empty substrings
		return (0);
	if (s[0] != c)
		nbr++;
	return (nbr); // return number of non-empty substrings
}

// allocate memory for an array of strings based on delimiter 'c'
static char	**ft_mal(char **strs, char const *s, char c)
{
	size_t	count; // substring
	int		i; //strs
	int		h; //s

	count = 0;
	i = 0;
	h = 0;
	while (s[h])
	{
		if (s[h] != c) // count characters in the substring
			count++;
		else if (h > 0 && s[h - 1] != c) // end of substring
		{
			strs[i] = malloc(sizeof(char) * (count + 1)); // allocate memory for substring
			if (!strs[i])
				return (0);
			count = 0;
			i++;
		}
		if (s[h + 1] == '\0' && s[h] != c) // reach end of string
			if (!(strs[i] = malloc(sizeof(char) * count + 1)))
				return (0);
		h++;
	}
	return (strs);
}

// copy characters from string to substring
static char	**ft_cpy(char **strs, char const *s, char c)
{
	int i; //
	int j; // 
	int h; // s

	i = 0;
	j = 0;
	h = 0;
	while (s[h])
	{
		if (s[h] != c) // copy string to substring
			strs[i][j++] = s[h];
		else if (h > 0 && s[h - 1] != c) // end of substring
			if (h != 0)
			{
				strs[i][j] = '\0';
				j = 0;
				i++;
			}
		if (s[h + 1] == '\0' && s[h] != c) // end of string
			strs[i][j] = '\0';
		h++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		nbr_w;

	if (!s || !*s) // check if s is NULL or empty
	{
		if (!(result = malloc(sizeof(char *) * 1)))
			return (NULL);
		*result = (void *)0; // set first element to a null pointer
		return (result);
	}
	nbr_w = ft_hm(s, c);
	result = malloc(sizeof(char *) * (nbr_w + 1));
	if (!result)
		return (0);
	if (ft_mal(result, s, c) != 0)
		ft_cpy(result, s, c);
	else
	{
		free(result);
		return (NULL);
	}
	result[nbr_w] = (void *)0;
	return (result);
}