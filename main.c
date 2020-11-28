/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 08:29:35 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/28 12:06:33 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <libc.h>
#include <ctype.h>
#include "libft.h"

char	func_mapi(unsigned int i, char c)
{
	return (i + c);
}

int	 main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	const int BSIZE = 10;
	char		b1[BSIZE];
	char		b2[BSIZE];
	char		*r1;
	char		*r2;

	printf("ft_memset\n");
	// memset(NULL, 'A', -1);
	// ft_memset(NULL, 'A', -1);
	// memset(b1, 'A', 0);
	ft_memset(b1, 'A', 0);
	printf("%s\n", b1);
	memset(b1, 'B', BSIZE);
	memset(b1, 'B', BSIZE);
	memset(b1, 'A', 10);
	ft_memset(b2, 'A', 10);
	if (memcmp(b1 ,b2, BSIZE))
		printf("memset basic error!\n");
	memset(b1, '\257', 10);
	ft_memset(b2, '\257', 10);
	if (memcmp(b1 ,b2, BSIZE))
		printf("memset unsigned char error!\n");
	r1 = memset("", 'A', (0));
	r2 = ft_memset("", 'A', 0);
	if (memcmp(r1 ,r2, BSIZE))
		printf("memset bsize error!\n");

	printf("\nft_bzero\n");
	// bzero(b1, 0);
	ft_bzero(b2, 0);
	printf("[%s] [%s]\n", b1, b2);
	bzero(b1, 10);
	ft_bzero(b2, 10);
	if (memcmp(b1, b2, BSIZE))
		printf("bzero basic function error!\n");

	printf("\nft_memcpy\n");
	memcpy(b1, "ABC", 0);
	ft_memcpy(b2, "ABC", 0);
	if (memcmp(b1, b2, BSIZE))
		printf("memcpy length 0 error!\n");
	memcpy(b1, "ABC", 3);
	ft_memcpy(b2, "ABC", 3);
	if (memcmp(b1, b2, BSIZE))
		printf("memcpy basic error!\n");
	memcpy(b1, "", 3);
	ft_memcpy(b2, "", 3);
	if (memcmp(b1, b2, BSIZE))
		printf("memcpy basic error!\n");
	
	printf("\nft_memccpy\n");
	ft_memccpy(b2, "abc123", 'c', 0);
	memccpy(b1, "abc123", 'c', 5);
	ft_memccpy(b2, "abc123", 'c', 5);
	if (memcmp(b1, b2, BSIZE))
		printf("memccpy c error!\n");
	memccpy(b1, "abc123", 'x', 5);
	ft_memccpy(b2, "abc123", 'x', 5);
	if (memcmp(b1, b2, BSIZE))
		printf("memccpy non c error!\n");
	memccpy(b1, "", 'x', 5);
	ft_memccpy(b2, "", 'x', 5);
	if (memcmp(b1, b2, BSIZE))
		printf("memccpy blank error!\n");
	
	printf("\nft_memmove\n");
	ft_memmove(b2, "123", 0);
	memmove(b1, "123", 5);
	ft_memmove(b2, "123", 5);
	if (memcmp(b1, b2, BSIZE))
		printf("memmove basic error!\n");
	memmove(b1, b1, 5);
	ft_memmove(b2, b2, 5);
	if (memcmp(b1, b2, BSIZE))
		printf("memmove duplicate start error!\n");
	memmove(b1+5, b1, 5);
	ft_memmove(b2+5, b2, 5);
	printf("b1:%s b2:%s\n", b1, b2);
	if (memcmp(b1, b2, BSIZE))
		printf("memmove duplicate area error!\n");
//全て後ろ側からのコピーにした時になぜエラーになるか？
	memmove(b1, b1+6, 5);
	ft_memmove(b2, b2+6, 5);
	printf("b1:[%s] b2:[%s]\n", b1, b2);
	if (memcmp(b1, b2, BSIZE))
		printf("memmove duplicate area rev error!\n");

	printf("\nft_memchr\n");
	ft_memcpy(b1, "abcde", 5);
	r1 = memchr(b1, 'c', 0);
	r2 = ft_memchr(b1, 'c', 0);
	printf("[%s] [%s]\n",r1 ,r2);
	r1 = memchr(b1, 'c', 5);
	r2 = ft_memchr(b1, 'c', 5);
	printf("[%s] [%s]\n",r1 ,r2);
	if (memcmp(r1, r2, BSIZE))
		printf("memchr len 0 error!\n");
	// int		i = 12345;
	// int		*intp1 = &i;
	// r1 = memchr(intp1, 3, 5);
	// r2 = ft_memchr(intp1, 3, 5);
	// if (memcmp(r1, r2, BSIZE))
	// 	printf("memchr len 0 error!");

	printf("\nft_memcmp\n");
	if (memcmp(b1, b1, 0) != ft_memcmp(b1, b1, 0))
		printf("memcmp len 0 error!\n");
	if (memcmp(b1, b1, 3) != ft_memcmp(b1, b1, 3))
		printf("memcmp basic error!\n");
	if (memcmp("12345", "a3", 3) != ft_memcmp("12345", "a3", 3))
		printf("memcmp dif error!\n");
	printf("memcmp:%d ft_:%d\n", memcmp("12345", "a3", 3), ft_memcmp("12345", "a3", 3));
	
	printf("\nft_strlen\n");
	if (strlen(b1) != ft_strlen(b1))
		printf("strlen basic error!\n");
	// i = strlen(NULL);
	// j = ft_strlen(NULL);
	// if (i != j)
	// 	printf("strlen NULL error!");

	printf("\nft_isalpha\n");
	if (isalpha('s') != ft_isalpha('s'))
		printf("isalpha basic error!\n");
	if (isalpha(' ') != ft_isalpha(' '))
		printf("isalpha blank error!\n");

	printf("\nft_isascii\n");
	if (isascii('\200') != ft_isascii('\200'))
		printf("isascii non ascii error!\n");
	if (isascii(' ') != ft_isascii(' '))
		printf("isascii blank error!\n");

	printf("\nft_isprint\n");
	if (isprint('\n') != ft_isprint('\n'))
		printf("isprint non ascii error!\n");
	if (isprint(' ') != ft_isprint(' '))
		printf("isprint blank error!\n");
	
	printf("\nft_toupper\n");
	if (toupper('a') != ft_toupper('a'))
		printf("toupper basic error!\n");
	if (toupper('A') != ft_toupper('A'))
		printf("toupper uppercase error!\n");
	if (toupper('!') != ft_toupper('!'))
		printf("toupper nochange error!\n");

	printf("\nft_strchr\n");
	memcpy(b1, "AABBC", 5);
	if (strchr(b1, 'A') != ft_strchr(b1, 'A'))
		printf("strchr basic error!\n");
	// r1 = strchr(NULL, 'A');
	// r2 = ft_strchr(NULL, 'A');
	if (strchr(b1, '\200') != ft_strchr(b1, '\200'))
		printf("strchr nonascii error!\n");
	if (strchr(b1, '\0') != ft_strchr(b1, '\0'))
		printf("strchr null char error!\n");

	printf("\nft_strrchr\n");
	if (strrchr(b1, 'B') != ft_strrchr(b1, 'B'))
		printf("strrchr basic error!\n");
	// r1 = strchr(NULL, 'A');
	// r2 = ft_strchr(NULL, 'A');
	if (strrchr(b1, '\200') != ft_strrchr(b1, '\200'))
		printf("strrchr nonascii error!\n");
	if (strrchr(b1, '\0') != ft_strrchr(b1, '\0'))
		printf("strrchr null char error!\n");

	printf("\nft_strncmp\n");
	if (strncmp("abcde", "abcde", 3) != ft_strncmp("abcde", "abcde", 3))
		printf("strncmp basic error!\n");
	// r1 = strchr(NULL, 'A');
	// r2 = ft_strchr(NULL, 'A');
	// if (strncmp(NULL, "abc", 5) != ft_strncmp(NULL, "abc", 5))
	// 	printf("strrchr nonascii error!");
	if (strncmp("abcde", "\0", 3) != ft_strncmp("abcde", "\0", 3))
		printf("strncmp diff error!\n");
		printf("strncmp:%d ft_:%d\n", strncmp("abcde", "\0", 3), ft_strncmp("abcde", "\0", 3));

	printf("\nft_strlcpy\n");
	memset(b1, 'A', 5);
	memset(b2, 'A', 5);
	int i = strlcpy(b1, "123", BSIZE);
	int j = ft_strlcpy(b2, "123", BSIZE);
	printf("basic %d %s %d %s\n", i, b1, j, b2);
	i = strlcpy(b1, "12345", 0);
	j = ft_strlcpy(b2, "12345", 0);
	printf("len0 %d %s %d %s\n", i, b1, j, b2);
	// i = strlcpy(NULL, "12345", 5);
	// j = ft_strlcpy(NULL, "12345", 5);
	printf("parm1 NULL\n");
	// i = strlcpy(b1, NULL, 5);
	// j = ft_strlcpy(b2, NULL, 5);
	printf("parm2 NULL\n");
	// i = strlcpy(NULL, NULL, 5);
	// j = ft_strlcpy(NULL, NULL, 5);
	printf("parm1,2 NULL\n");

	printf("\nft_strlcat\n");
	bzero(b1, BSIZE);
	bzero(b2, BSIZE);
	memset(b1, 'A', 5);
	memset(b2, 'A', 5);
	i = strlcat(b1, "123", BSIZE);
	j = ft_strlcat(b2, "123", BSIZE);
	printf("base_check func:%d %s ft:%d %s\n", i, b1, j, b2);
	i = strlcat(b1, "123", 0);
	j = ft_strlcat(b2, "123", 0);
	printf("len0 func:%d %s ft:%d %s\n", i, b1, j, b2);
	i = strlcat("", "123", 0);
	j = ft_strlcat("", "123", 0);
	printf("dstsize0 len0 func:%d %s ft:%d %s\n", i, b1, j, b2);
	i = strlcat("", "", 0);
	j = ft_strlcat("", "", 0);
	printf("dstsize0 src0 len0 func:%d %s ft:%d %s\n", i, b1, j, b2);
	i = strlcat(b1, "", BSIZE);
	j = ft_strlcat(b2, "", BSIZE);
	printf("src0 func:%d %s ft:%d %s\n", i, b1, j, b2);
	// i = strlcat(NULL, "abc", BSIZE);
	// j = ft_strlcat(NULL, "abc", BSIZE);
	// printf("dst null func:%d %s ft:%d %s\n", i, b1, j, b2);
	// i = strlcat(b1, NULL, BSIZE);
	// j = ft_strlcat(b2, NULL, BSIZE);
	// printf("src null func:%d %s ft:%d %s\n", i, b1, j, b2);

	printf("\nft_strnstr\n");
	if (strnstr(b1, "123", BSIZE) != ft_strnstr(b1, "123", BSIZE))
		printf("basic error %s\n", b1);
	if (strnstr(b1, "123", 0) != ft_strnstr(b1, "123", 0))
		printf("len0 error %s\n", b1);
	// if (strnstr(NULL, "123", BSIZE) != ft_strnstr(NULL, "123", BSIZE))
	// 	printf("heystack NULL error %s\n", b1);
	// if (strnstr(b1, NULL, BSIZE) != ft_strnstr(b1, NULL, BSIZE))
	// 	printf("needle null error %s\n", b1);

	printf("\nft_strnstr\n");
	printf("basic         atoi:%d ft:%d\n", atoi("\t\n\v\r\f      12345"), ft_atoi("\t\n\v\r\f      12345"));
	printf("sign          atoi:%d ft:%d\n", atoi("-12345"), ft_atoi("-12345"));
	printf("int  max      atoi:%d ft:%d\n", atoi("2147483647"), ft_atoi("2147483647"));
	printf("int  min      atoi:%d ft:%d\n", atoi("-2147483648"), ft_atoi("-2147483648"));
	printf("long max      atoi:%d ft:%d\n", atoi("9223372036854775807"), ft_atoi("9223372036854775807"));
	printf("long min      atoi:%d ft:%d\n", atoi("-9223372036854775808"), ft_atoi("-9223372036854775808"));
	printf("long max over atoi:%d ft:%d\n", atoi("9223372036854775900"), ft_atoi("9223372036854775900"));
	printf("long min over atoi:%d ft:%d\n", atoi("-9223372036854775900"), ft_atoi("-9223372036854775900"));
	printf("unsigned long over atoi:%d ft:%d\n", atoi("18446744073709551615000"), ft_atoi("18446744073709551615000"));
	printf("unsigned long over atoi:%d ft:%d\n", atoi("-18446744073709551615000"), ft_atoi("-18446744073709551615000"));
	printf("error              atoi:%d ft:%d\n", atoi("63410682753376583680"), ft_atoi("63410682753376583680"));

	printf("\nft_strdup\n");
	printf("%s\n", strdup("abctest"));
	printf("%s\n", ft_strdup("abctest"));
	// printf("%s\n", strdup(NULL));
	// printf("%s\n", ft_strdup(NULL));

	printf("\n***** part2 *****\n");
	printf("\nft_substr\n");
	printf("basic      [%s]\n", ft_substr("12345", 1, 3));
	printf("start over [%s]\n", ft_substr("12345", 6, 4));
	printf("len0       [%s]\n", ft_substr("12345", 1, 0));
	printf("over len   [%s]\n", ft_substr("12345", 1, 5));
	printf("null       [%s]\n", ft_substr(NULL, 1, 5));
	
	printf("\nft_strjoin\n");
	printf("basic  [%s]\n", ft_strjoin("12345", "abc"));
	printf("blank1 [%s]\n", ft_strjoin("", "abc"));
	printf("blank2 [%s]\n", ft_strjoin("12345", ""));
	printf("null 1 [%s]\n", ft_strjoin(NULL, "abc"));
	printf("null 2 [%s]\n", ft_strjoin("12345", NULL));
	printf("null 3 [%s]\n", ft_strjoin(NULL, NULL));

	printf("\nft_strtrim\n");
	printf("basic    [%s]\n", ft_strtrim("/+*1+/2*3/45+++++*/", "*+/"));
	printf("all sep  [%s]\n", ft_strtrim("/+*+++++*/", "*+/"));
	printf("blank    [%s]\n", ft_strtrim("", "*+/"));
	printf("no sep   [%s]\n", ft_strtrim("/+*1+/2*3/45+++++*/", ""));
	printf("null str [%s]\n", ft_strtrim(NULL, "*+/"));
	printf("null sep [%s]\n", ft_strtrim("/+*1+/2*3/45+++++*/", NULL));

	printf("\nft_split\n");
	printf("basic\n");
	char **split = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
	i = 0;
	while (split[i] != NULL)
	{
		printf("[%s]\n", split[i]);
		i++;
	}
	printf("no split\n");
	split = ft_split("1234567890", 'i');
	i = 0;
	while (split[i] != NULL)
	{
		printf("[%s]\n", split[i]);
		i++;
	}
	printf("null\n");
	split = ft_split(NULL, 'i');

	printf("\nft_itoa\n");
	printf("basic    [%s]\n", ft_itoa(12345));
	printf("sign     [%s]\n", ft_itoa(-12345));
	printf("int min  [%s]\n", ft_itoa(-2147483648));
	printf("int max  [%s]\n", ft_itoa(2147483647));
	printf("10000    [%s]\n", ft_itoa(10000));
	printf("zero     [%s]\n", ft_itoa(0));

	printf("\nft_strmapi\n");
	printf("basic       [%s]\n", ft_strmapi("aaaaa", func_mapi));
	printf("null        [%s]\n", ft_strmapi(NULL, func_mapi));
	// printf("method null [%s]\n", ft_strmapi("aaaaa", NULL));

	printf("\nft_putchar_fd\n");
	ft_putchar_fd('a', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\200', 1);
	ft_putchar_fd('\n', 1);

	printf("\nft_putstr_fd\n");
	ft_putstr_fd("abcde\n", 1);
	ft_putstr_fd(NULL, 1);
	
	printf("\nft_putendl_fd\n");
	ft_putstr_fd("abcde\n", 1);
	ft_putstr_fd(NULL, 1);

	return (0);
}