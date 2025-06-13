#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

char *addlst(char *str, char c)
{
	char *new;
	int i;
	int l;

	i = 0;
	l = 0;
	if (!str)
		return NULL;
	while (str[l])
		l++;
	new = malloc(l + 2);
	while (i < l)
	{
		new[i] = str[i];
		i++;
	}
	new[l] = c;
	new[l + 1] = '\0';
	free(str);
	return new;
}

char *gtnxstln(fd)
{
	char	*buff;
	char	*str;
	int		rret;
	int		i;
	int		j;

	buff = NULL;
	str = NULL;
	buff = malloc(2);
	rret = read(fd, buff, 1);
	if (rret <= 0)
	{
		free(buff);
		return NULL;
	}
	buff[1] = '\0';
	str = malloc(2);
	str[0] = buff[0];
	str[1] = '\0';
	i = 1;
	while (rret)
	{
		j = 0;
		rret = read(fd, buff, 1);
		if (rret == 0 || buff[0] == '\n')
			break;
		str = addlst(str, buff[0]);
		i++;
	}
	str = addlst(str, '\n');
	free(buff);
	return str;
}

// int main()
// {
// 	char *dih;
// 	int i;
// 	int fd = open("Makefile", O_RDONLY);
// 	dih = gtnxstln(fd);
// 	printf("%s", dih);
// 	while (dih && i < 72)
// 	{
// 		dih = gtnxstln(fd);
// 		printf("%s", dih);
// 		i++;
// 	}
// }

int succ(char *dih)
{
	int i;

	i = 0;
	while (dih[i])
	{
		write(1, "*", 1);
		i++;
	}
	return (i);
}

void flt(char *gurt, char *yo)
{
	int i;
	int j;

	i = 0;
	while (gurt[i])
	{
		j = 0;
		while (gurt[i + j] && yo[j] && gurt[i + j] == yo[j])
			j++;
		if (yo[j] == '\0')
			i = i + succ(yo);
		else
		{
			write(1, &gurt[i], 1);
			i++;
		}
	}
}

int main(int ac, char **av)
{
	char *str;

	if (ac != 2)
		return(1);
	str = gtnxstln(1);
	if (str)
		flt(str, av[1]);
	while (str)
	{
		str = gtnxstln(1);
		flt(str, av[1]);
		write(1, "\n", 1);
	}
}
