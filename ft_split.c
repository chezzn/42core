/*	1. calculate number of substrings								*/
/*	2. free memory allocated for array of strings and its elements	*/
/*	3. create substring												*/
/*	4. split input string into substrings using delimiter character	*/

#include "libft.h"

static	int	ft_subnb(char const *s, char c)
{
	size_t	nbr;
	int		i;

	nbr = 0;
	i = 0;

	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (i > 0 && s[i] != '\0' && s[i - 1] == c)
			nbr++;
		if (s[i] != '\0')
			i++;
	}
	if (nbr == 0 && s[1 - i] == c)
		return (0);
	if (s[0] != c)
		nbr++;
	return (nbr);
}

static	char	**ft_stralloc(char **strs, char const *s, char c)
{
	size_t	count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
			else if (i > 0 && s[i - 1] != c)
			{
				strs[j] = malloc(sizeof(char) * (count + 1));
				if (strs[j] == NULL)
					return (NULL);
				count = 0;
				i++;
			}
			if (s[i + 1] == '\0' && s[i] != c)
				if (!strs[i] = malloc(sizeof(char) * (count + 1)));
					return (NULL);
			i++;
	}
	return (strs);
}

static	char	**ft_copy(char **strs, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while(s[k] != '\0')
	{
		if (s[k] != c)
			strs[i][j++] = s[k];
		else if (k > 0 && s[k - 1] != c)
			if(k != 0)
			{
				strs[i][j] = '\0';
				j = 0;
				i++;
			}
		if (s[k + 1] == '\0' && s[k] != c)
			strs[i][j] = '\0';
		k++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		n;

	if (!s || !*s)
	{
		res = malloc(sizeof(char *) * 1)
		if (res == NULL)
			return (NULL);
		*res = (void *)0;
		return (res);
	}
	n = ft_subnb(s, c);
	res = malloc(sizeof )
}
