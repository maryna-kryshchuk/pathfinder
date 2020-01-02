#include "libmx.h"
/*
static char *mx_trim_char(const char *str, char c) {
    if (!str) return NULL;

    int i = 0;
    int start = 0;
    int end = mx_strlen(str) - 1;

    for(; str[start] == c; start++);
    
    if (start == end + 1)
        return mx_strnew(0);

    for(; str[end] == c; end--);

    char *res = malloc(end - start + 2);

    for (; start != end + 1; i++, start++)
        res[i] = str[start];
    
    res[i] = '\0';
    return res;
}

char **mx_strsplit(const char *s, char c) {
    if (!s) return NULL;
    int words = mx_count_words(s, c);
    printf("words %d\n", words);
    char **res = malloc((words + 1)*sizeof(char *));
    res[words] = NULL;
    int i = 0;
    int ptr = 0;
    char *word = (char *)s;
    char *tmp = NULL;
    
    while (words--) {
        word = mx_trim_char(word, c);
        tmp = word;
        ptr = mx_get_char_index(word, c);
        if (ptr == -1)
            res[i] = mx_strdup(word);
        else
            res[i] = mx_strndup(word, ptr);
        i++;
        word += ptr;
        free(tmp);
    }
    return res;
}
*/


static	int		count_length(int i, char const *s, char c)
{
	int		lengthword;

	lengthword = i;
	while (s[lengthword] != c && s[lengthword] != '\0')
		lengthword++;
	lengthword = lengthword - i;
	return (lengthword);
}

static int		ft_countwords(char const *s, char c)
{
	int	i;
	int	nbwords;

	i = 0;
	nbwords = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			nbwords++;
		}
	}
	return (nbwords);
}

static	char	**do_split(int i, const char *s, char c, char **str)
{
	int		lengthword;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			lengthword = count_length(i, s, c);
			str[j] = (char*)malloc((lengthword + 1) * sizeof(char));
			while (lengthword-- > 0)
			{
				str[j][k++] = s[i++];
			}
			str[j++][k] = '\0';
			k = 0;
			lengthword = 0;
		}
	}
	str[j] = NULL;
	return (str);
}

char			**mx_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;
	int		nbwords;
	char	*str2;

	i = 0;
	j = 0;
	if (c && s)
	{
		nbwords = ft_countwords(s, c);
		str = (char**)malloc((nbwords + 1) * sizeof(char *));
		if (str == 0)
			return (0);
		str = do_split(i, s, c, str);
		return (str);
	}
	else
	{
		str2 = mx_strnew(1);
		return ((char **)str2);
	}
}
