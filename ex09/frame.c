#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		x;
	int		len;
	char	*str;

	x = 0;
	len = 0;
	while (s[x] != '\0')
	{
		len++;
		x++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	x = 0;
	while (s[x])
	{
		str[x] = s[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}


int	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*ft_substr(char const *s, int start, long len)
{
	long	x;
	char	*str;

	x = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	else if ((start + len) >= ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (x < len)
	{
		str[x] = s[start];
		x++;
		start++;
	}
	str[x] = '\0';
	return (str);
}

static int	countlen(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != c && *s)
	{
		++count;
		++s;
	}
	return (count);
}

static int	getwords(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	a = malloc(sizeof(char *) * (getwords(s, c) + 1));
	if (!a)
		return (NULL);
	a[0] = NULL;
	while (*s)
	{
		if (countlen(s, c) != 0)
		{
			a[i] = ft_substr(s, 0, countlen(s, c));
			s += countlen(s, c);
			++i;
		}
		else
			++s;
	}
	a[i] = NULL;
	return (a);
}

void	print_line(int len)
{
	int x;

	x = 0;
	while (x++ < len)
		write(1, "*", 1);
	write(1, "\n", 1);
}

void print_mid(char **arr, int longest)
{
	int x;
	int xtra;

	x = 0;
	xtra = 0;
	while (arr[x])
	{
		write(1, "* ", 2);
		write(1, arr[x], ft_strlen(arr[x]));
		if (ft_strlen(arr[x]) < longest)
			xtra = longest - ft_strlen(arr[x]);
		while (xtra-- > 0)
			write(1, " ", 1);
		write(1, " *", 2);
		write(1, "\n", 1);
		x++;
	}
}

void	free_2d(char **array)
{
	char	**tmp;

	tmp = array;
	while (tmp && *tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(array);
}

int main(int ac, char **av)
{
	int	x;
	int len;
	int	longest;
	char **arr;

	x = 1;
	len = 0;
	if (ac >= 2)
	{
		arr = ft_split(av[1], ' ');
		longest = ft_strlen(arr[0]);
		while (arr[len])
			len++;
		while (x < len)
		{
			if (longest < ft_strlen(arr[x]))
				longest = ft_strlen(arr[x]);
			x++;
		}
		print_line(longest + 4);
		print_mid(arr, longest);
		print_line(longest + 4);
		free_2d(arr);
	}
	return (0);
}