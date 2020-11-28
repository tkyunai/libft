/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakami <ktakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:56:30 by ktakami           #+#    #+#             */
/*   Updated: 2020/11/09 23:50:05 by mukobaray        ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	assert(unsigned long expected, unsigned long actual)
{
	if (expected == actual) {
		printf("[ok]\n");
	} else {
		if (expected <= 127 && expected >= 0) {
			printf("[ng]expected: %ld(%c), but: %ld(%c)\n", expected, (char)expected, actual, (char)actual);
		} else {
			printf("[ng]expected: %ld, but: %ld\n", expected, actual);
		}
		exit(1);
	}
}

void	ptr_assert(void *expected, void *actual)
{
	if (expected == actual)
	{
		printf("[ok]\n");
	}
	else
	{
		printf("[ng] lib: %p, my: %p\n", expected, actual);
		exit(1);
	}
}

void	test_strlen(char *str)
{
	unsigned long		(*lib)(const char*);
	size_t				(*my)(const char*);

	lib = strlen;
	my = ft_strlen;
	assert(lib(str), my(str));
}

void	test_strlen_case(void)
{
	printf("strlen test...\n");
	test_strlen("");
	test_strlen("\n");
	test_strlen("0123456789");
	test_strlen("hoge");
}

void	test_memset(char *str, int c, int len)
{
	void*	(*lib)(void*, int, unsigned long);
	void*	(*my)(void*, int, size_t);
	char*	copied_lib;
	char*	copied_my;
	int		str_len;
	char*	res_lib;
	char*	res_my;

	str_len = strlen(str);
	copied_lib = ft_strdup(str);
	copied_my = ft_strdup(str);
	lib = memset;
	my = ft_memset;
	res_lib = memset((void*)copied_lib, c, len);
	res_my = ft_memset((void*)copied_my, c, len);
	assert(0, ft_memcmp(res_lib, res_my, len));
	free(copied_lib);
	free(copied_my);
}

void	test_memset_case(void)
{
	printf("memset test...\n");
	test_memset("", 'a', 4);
	test_memset("hogefuga", 'a', 4);
	test_memset("uga", 'a', 10);
	test_memset("hogefuga", '\n', 1);
	test_memset("hogefuga", '\n', 8);
	test_memset("hogefuga", 'a', 0);
	test_memset("hogefuga", '\0', 0);
	test_memset("hogefuga", '\0', 8);
}

void	test_bzero(char *str, int n)
{
	int		i;
	int		str_len;
	void	(*lib)(void*, unsigned long);
	void	(*my)(void*, size_t);
	char*	copied_lib;
	char*	copied_my;

	str_len = strlen(str);
	copied_lib = ft_strdup(str);//malloc((str_len + 1) * sizeof(char));
	copied_my = ft_strdup(str);//malloc((str_len + 1) * sizeof(char));

	printf("%s, %d\n", str, n);
	lib = bzero;
	my = ft_bzero;
	printf("bzero\n");
	bzero((void*)copied_lib, n);
	printf("ft_bzero\n");
	ft_bzero((void*)copied_my, n);
	i = 0;
	while (i <= str_len)
	{
		assert(copied_lib[i], copied_my[i]);
		i++;
	}
	free(copied_lib);
	free(copied_my);
}

void	test_bzero_case()
{
	printf("bzero test...\n");
	test_bzero("hoge", 2);
	test_bzero("hoge", 0);
	//test_bzero("hoge", -1); segv
	//test_bzero("hoge", -2);
	test_bzero("fugafuga", 8);
}

void	test_memcpy(char *dst, char *src, int n)
{
	void* (*lib)(void*, const void*, unsigned long);
	void* (*my)(void*, const void*, size_t);
	char	*copied_dst_lib;
	char	*copied_src_lib;
	char	*res_lib;
	char	*copied_dst_my;
	char	*copied_src_my;
	char	*res_my;

	lib = memcpy;
	my = ft_memcpy;

	if (dst == NULL && src == NULL)
	{
		res_my  = my(dst, src, n);
		if (res_my == NULL)
		{
			printf("[ok]\n");
		}
		else
		{
			printf("[ng] res_my should be NULL\n");
			exit(1);
		}
		return;
	}
	copied_dst_lib = ft_strdup(dst);
	copied_dst_my = ft_strdup(dst);
	copied_src_lib = ft_strdup(src);
	copied_src_my = ft_strdup(src);
	res_lib = lib(copied_dst_lib, copied_src_lib, n);
	res_my = my(copied_dst_my, copied_src_my, n);
	assert(0, strcmp(res_lib, res_my));
	free(copied_dst_lib);
	free(copied_dst_my);
	free(copied_src_lib);
	free(copied_src_my);
}

void	test_memcpy_case()
{
	printf("memcpy test...\n");
	test_memcpy("hoge", "fabc", 1);
	test_memcpy("hoge", "fabc", 2);
	test_memcpy("hoge", "fabc", 3);
	test_memcpy("hoge", "fabc", 4);
	test_memcpy("hogeads", "fabc", 4);
	test_memcpy(NULL, NULL, 4);
}

void	test_memccpy(char *dst, char *src, int c, int n)
{
	void* (*lib)(void*, const void*, int, unsigned long);
	void* (*my)(void*, const void*, int, size_t);
	char	*copied_dst_lib;
	char	*copied_src_lib;
	char	*res_lib;
	char	*copied_dst_my;
	char	*copied_src_my;
	char	*res_my;

	copied_dst_lib = ft_strdup(dst);
	copied_dst_my = ft_strdup(dst);
	copied_src_lib = ft_strdup(src);
	copied_src_my = ft_strdup(src);
	lib = memccpy;
	my = ft_memccpy;
	res_lib = lib(copied_dst_lib, copied_src_lib, c, n);
	res_my = my(copied_dst_my, copied_src_my, c, n);
	if (res_lib == NULL) {
		if(res_my == NULL)
			printf("[ok]\n");
	} else {
		assert(0, strcmp(res_lib, res_my));
	}
	free(copied_dst_lib);
	free(copied_dst_my);
	free(copied_src_lib);
	free(copied_src_my);
}

void	test_memccpy_case()
{
	printf("memccpy test...\n");
	test_memccpy("hoge", "fuga", 'u', 0);
	test_memccpy("hoge", "fuga", 'u', 1);
	test_memccpy("hoge", "fuga", 'u', 2);
	test_memccpy("hoge", "fuga", 'u', 3);
	test_memccpy("hoge", "fuga", '\n', 0);
	test_memccpy("hoge", "fuga", '\n', 1);
	test_memccpy("hoge", "fuga", '\n', 4);
	test_memccpy("hoge", "fuga", '\n', 5);
	test_memccpy("hoge", "fuga", 'h', 0);
	test_memccpy("hoge", "fuga", 'h', 1);
	test_memccpy("hoge", "fuga", '\0', 0);
	test_memccpy("hoge", "fuga", '\0', 1);
	test_memccpy("hoge", "fuga", '\0', 2);
	test_memccpy("hoge", "fuga", '\0', 3);
	test_memccpy("hoge", "fuga", '\0', 4);
	test_memccpy("h\0oge", "fuga\0", '\0', 0);
	test_memccpy("h\0oge", "fuga\0", '\0', 1);
	test_memccpy("h\0oge", "fuga\0", '\0', 2);
	test_memccpy("h\0oge", "fuga\0", '\0', 3);
	test_memccpy("h\0oge", "fuga\0", '\0', 4);
}

void	test_memmove(char *original, int n, int dst_offset, int src_offset)
{
	void* (*lib)(void*, const void*, unsigned long);
	void* (*my)(void*, const void*, size_t);
	char	*copied_original_lib;
	char	*copied_original_my;
	char	*dst_addr_lib;
	char	*dst_addr_my;
	char	*src_addr_lib;
	char	*src_addr_my;
	void	*res_lib;
	void	*res_my;

	copied_original_lib = ft_strdup(original);
	copied_original_my = ft_strdup(original);
	dst_addr_lib = copied_original_lib + dst_offset;
	dst_addr_my = copied_original_my + dst_offset;
	src_addr_lib = copied_original_lib + src_offset;
	src_addr_my = copied_original_my + src_offset;

	lib = memmove;
	my = ft_memmove;
	res_lib = lib(dst_addr_lib, src_addr_my, n);
	res_my = my(dst_addr_my, src_addr_my, n);
	assert(0, strcmp(res_lib, res_my));
	free(copied_original_lib);
	free(copied_original_my);
}

void	test_memmove_null()
{
	ptr_assert(memmove(NULL, NULL, 0), ft_memmove(NULL, NULL, 0));
	ptr_assert(memmove(NULL, NULL, 1), ft_memmove(NULL, NULL, 1));
}

void	test_memmove_normal(char* dst, char *src, int n)
{
	char	*copied_dst_lib;
	char	*copied_dst_my;
	void	*res_lib;
	void	*res_my;

	copied_dst_lib = ft_strdup(dst);
	copied_dst_my = ft_strdup(dst);
	res_lib = memmove(copied_dst_lib, src, n);
	res_my = ft_memmove(copied_dst_my, src, n);
	assert(0, ft_memcmp(res_lib, res_my, n));
	free(copied_dst_lib);
	free(copied_dst_my);
}

void	test_memmove_case()
{
	printf("memmove...\n");
	test_memmove("0123456789", 0, 0, 0);
	test_memmove("0123456789", 1, 0, 0);
	test_memmove("0123456789", 1, 0, 1);
	test_memmove("0123456789", 1, 1, 0);
	test_memmove("0123456789", 2, 0, 1);
	test_memmove("0123456789", 2, 0, 2);
	test_memmove("0123456789", 2, 0, 3);
	test_memmove("0123456789", 2, 3, 0);
	test_memmove("0123456789", 2, 3, 1);
	test_memmove("0123456789", 2, 3, 2);
	test_memmove("0123456789", 4, 0, 5);
	test_memmove("0123456789", 4, 0, 4);
	test_memmove("0123456789", 4, 0, 3);
	test_memmove("0123456789", 4, 0, 2);
	test_memmove("0123456789", 4, 0, 1);
	test_memmove("0123456789", 4, 5, 0);
	test_memmove("0123456789", 4, 5, 1);
	test_memmove("0123456789", 4, 5, 2);
	test_memmove("0123456789", 4, 5, 3);
	test_memmove("0123456789", 4, 5, 4);
	test_memmove("0123456789", 4, 5, 5);
	test_memmove_normal("abcdef", "ghi", 0);
	test_memmove_normal("abcdef", "ghi", 1);
	test_memmove_normal("abcdef", "ghi", 2);
	test_memmove_normal("abcdef", "ghi", 3);
	test_memmove_normal("abcdef", "ghi", 4);
	test_memmove_normal("abcdef", "ghi", 5);
	test_memmove_normal("abcdef", "ghijkl", 0);
	test_memmove_normal("abcdef", "ghijkl", 1);
	test_memmove_normal("abcdef", "ghijkl", 2);
	test_memmove_normal("abcdef", "ghijkl", 3);
	test_memmove_normal("abcdef", "ghijkl", 4);
	test_memmove_normal("abcdef", "ghijkl", 5);
	test_memmove_normal("abcdef", "ghijkl", 6);
	test_memmove_normal("abcdef", "ghijklmno", 0);
	test_memmove_normal("abcdef", "ghijklmno", 1);
	test_memmove_normal("abcdef", "ghijklmno", 2);
	test_memmove_normal("abcdef", "ghijklmno", 3);
	test_memmove_normal("abcdef", "ghijklmno", 4);
	test_memmove_normal("abcdef", "ghijklmno", 5);
	test_memmove_normal("abcdef", "ghijklmno", 6);
	test_memmove_normal("abcdef", "ghijklmno", 7);
	test_memmove_normal("abcdef", "ghijklmno", 8);
	test_memmove_normal("abcdef", "ghijklmno", 9);
	test_memmove_normal("abcdef", "ghijklmno", 10);
	test_memmove_null();
}

void	test_memchr(char *s, int c, int n)
{
	void *res_lib;
	void *res_my;

	res_lib = memchr(s, c, n);
	res_my = ft_memchr(s, c, n);
	if (res_lib == NULL)
	{
		if (res_my == NULL)
			printf("[ok]\n");
		else
			printf("expected: NULL but %s\n", res_my);
	}
	else
	{
		assert(0, strcmp(res_lib, res_my));
	}
}

void	test_memchr_case()
{
	printf("memchr...\n");
	test_memchr("0123456789", 'a', 10);
	test_memchr("0123456789", '4', 10);
	test_memchr("0123456789", '4', 3);
	test_memchr("0123456789", '4', 4);
	test_memchr("0123456789", '4', 5);
	test_memchr("0123456789", '\0', 5);
	test_memchr("01234567\089", '\0', 0);
	test_memchr("01234567\089", '\0', 1);
	test_memchr("01234567\089", '\0', 2);
	test_memchr("01234567\089", '\0', 3);
	test_memchr("01234567\089", '\0', 4);
	test_memchr("01234567\089", '\0', 5);
	test_memchr("01234567\089", '\0', 6);
	test_memchr("01234567\089", '\0', 7);
	test_memchr("01234567\089", '\0', 8);
	test_memchr("01234567\089", '\0', 9);
}

void	test_memcmp(char *s1, char *s2, int n)
{
	int	res_lib;
	int	res_my;

	res_lib = memcmp(s1, s2, n);
	res_my = ft_memcmp(s1, s2, n);
	assert(res_lib, res_my);
}

void	test_memcmp_case()
{
	printf("memcmp...\n");
	test_memcmp("123456789", "123456789", 0);
	test_memcmp("123456789", "123456789", 1);
	test_memcmp("123456789", "123456789", 4);
	test_memcmp("123456789", "123456789", 9);
	test_memcmp("123456789", "1234ABCDEF", 0);
	test_memcmp("123456789", "1234ABCDEF", 4);
	test_memcmp("123456789", "1234ABCDEF", 5);
	test_memcmp("123456789", "1234ABCDEF", 6);
	test_memcmp("abcd\0\0\0", "abcd\0abc", 0);
	test_memcmp("abcd\0\0\0", "abcd\0abc", 3);
	test_memcmp("abcd\0\0\0", "abcd\0abc", 4);
	test_memcmp("abcd\0\0\0", "abcd\0abc", 5);
	test_memcmp("abcd\0\0\0", "abcd\0abc", 6);
	test_memcmp("abcd\0\0\0", "abcd\0abc", 7);
	test_memcmp("abcd\0\0\0", "abcd\0\0\0", 0);
	test_memcmp("abcd\0\0\0", "abcd\0\0\0", 3);
	test_memcmp("abcd\0\0\0", "abcd\0\0\0", 4);
	test_memcmp("abcd\0\0\0", "abcd\0\0\0", 5);
	test_memcmp("abcd\0\0\0", "abcd\0\0\0", 6);
	test_memcmp("abcd\0\0\0", "abcd\0\0\0", 7);
	test_memcmp("abcd\0", "abcd\0\0\0", 0);
	test_memcmp("abcd\0", "abcd\0\0\0", 3);
	test_memcmp("abcd\0", "abcd\0\0\0", 4);
	test_memcmp("abcd\0", "abcd\0\0\0", 5);
	test_memcmp("abcd\0", "abcd\0\0\0", 6);
	test_memcmp("", "abcd\0\0\0", 0);
	test_memcmp("abcd\0\0\0", "", 0);
}

void	test_ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	char	*copied_dst_lib;
	char	*copied_src_lib;
	char	*copied_dst_my;
	char	*copied_src_my;
	int		res_lib;
	int		res_my;
	size_t	length;
	size_t	i;

	printf("dst: %s, src: %s, dstsize: %ld\n", dst, src, dstsize);
	copied_dst_lib = ft_strdup(dst);
	copied_dst_my = ft_strdup(dst);
	copied_src_lib = ft_strdup(src);
	copied_src_my = ft_strdup(src);
	length = strlen(copied_dst_lib);
	res_lib = strlcpy(copied_dst_lib, copied_src_lib, dstsize);
	res_my = ft_strlcpy(copied_dst_my, copied_src_my, dstsize);
	i = 0;
	while(i < length){
		assert(copied_dst_lib[i], copied_dst_my[i]);
		i++;
	}

	// NULL check
	if (dstsize > 0 && length >= dstsize && ft_strlen(src) >= length)
		assert('\0', copied_dst_my[dstsize - 1]);
	assert(res_lib, res_my);
}

void	test_ft_strlcpy_null()
{
	assert(strlcpy(NULL, NULL, 0), ft_strlcpy(NULL, NULL, 0));
	assert(strlcpy(NULL, NULL, 1), ft_strlcpy(NULL, NULL, 1));
	assert(strlcpy(NULL, NULL, 2), ft_strlcpy(NULL, NULL, 2));
}

void	test_ft_strlcpy_case()
{
	printf("ft_strlcpy...\n");
	// 大きさ dst = src = dstsize
	test_ft_strlcpy("", "", 0);
	test_ft_strlcpy("hoge", "fuga", 4);
	// 大きさ dst < src = dstsize
	test_ft_strlcpy("", "fuga", 4);
	test_ft_strlcpy("hog", "fuga", 4);
	// 大きさ dst = src < dstsize
	test_ft_strlcpy("", "", 4);
	test_ft_strlcpy("hog", "fui", 4);
	test_ft_strlcpy("hog", "fui", 6);
	// 大きさ dst < src < dstsize
	test_ft_strlcpy("", "f", 2);
	test_ft_strlcpy("ho", "fui", 4);
	test_ft_strlcpy("ho", "fuijfdsa", 10);
	//
	// 大きさ dst < dstsize = src(同じのある）
	// 大きさ dst = dstsize < src
	test_ft_strlcpy("", "fuij", 0);
	test_ft_strlcpy("hog", "fuij", 3);
	test_ft_strlcpy("hog", "fuijxafdsaii", 3);
	// 大きさ dst < dstsize < src
	test_ft_strlcpy("ho", "fuij", 3);
	test_ft_strlcpy("ho", "fuijabc", 5);
	test_ft_strlcpy("", "fuij", 2);
	//
	// 大きさ src < dstsize = dst
	test_ft_strlcpy("hoge", "", 4);
	test_ft_strlcpy("hoge", "fu", 4);
	// 大きさ src = dstsize < dst
	test_ft_strlcpy("hoge", "", 0);
	test_ft_strlcpy("hoge", "fu", 2);
	// 大きさ src < dstsize < dst
	test_ft_strlcpy("hoge", "", 1);
	test_ft_strlcpy("hogeab", "", 2);
	test_ft_strlcpy("hoge", "fu", 3);
	test_ft_strlcpy("hogeadsabds", "fu", 5);
	//
	// 大きさ src < dst = dstsize(同じのある)
	// 大きさ src = dst < dstsize
	test_ft_strlcpy("", "", 5);
	test_ft_strlcpy("hoge", "fuja", 5);
	test_ft_strlcpy("hoge", "fuja", 8);
	// 大きさ src < dst < dstsize
	test_ft_strlcpy("ho", "", 5);
	test_ft_strlcpy("hoge", "fuj", 5);
	test_ft_strlcpy("hogeabd", "fuj", 10);
	//
	// 大きさ dstsize = src < dst
	test_ft_strlcpy("hoge", "", 0);
	test_ft_strlcpy("hoge", "fuj", 3);
	test_ft_strlcpy("hogeabd", "fuj", 3);
	// 大きさ dstsize < src = dst
	test_ft_strlcpy("hog", "f", 0);
	test_ft_strlcpy("hogdsa", "f4", 0);
	test_ft_strlcpy("hog", "fuj", 2);
	test_ft_strlcpy("hogadb", "fujklj", 2);
	// 大きさ dstsize < src < dst
	test_ft_strlcpy("hoge", "fu", 0);
	test_ft_strlcpy("hoge61", "fu", 0);
	test_ft_strlcpy("hoge", "fuj", 2);
	test_ft_strlcpy("hogefdsfdsafsad", "fujfdsa", 2);
	//
	// 大きさ dstsize = dst < src
	test_ft_strlcpy("", "fuj", 0);
	test_ft_strlcpy("", "fujdsa", 0);
	test_ft_strlcpy("ho", "fuj", 2);
	test_ft_strlcpy("ho", "fufdsaj", 2);
	// 大きさ dstsize < dst = src(同じのある)
	// 大きさ dstsize < dst < src
	test_ft_strlcpy("hog", "fuje", 0);
	test_ft_strlcpy("hogfdsa", "fujefdsqerqa", 0);
	test_ft_strlcpy("hog", "fuje", 2);
	test_ft_strlcpy("hoguiq", "fujeeqafgsrd", 2);

	test_ft_strlcpy("hoge", "fuga", 1);
	test_ft_strlcpy("hoge", "fuga", 2);
	test_ft_strlcpy("hoge", "fuga", 3);
	test_ft_strlcpy("hoge", "fuo", 0);
	test_ft_strlcpy("hoge", "fuo", 1);
	test_ft_strlcpy("hoge", "fuo", 2);
	test_ft_strlcpy("hoge", "fuo", 3);
	test_ft_strlcpy("hoge", "fuo", 4);
	test_ft_strlcpy("hog", "fuoi", 0);
	test_ft_strlcpy("hog", "fuoi", 1);
	test_ft_strlcpy("hog", "fuoi", 2);
	test_ft_strlcpy("hog", "fuoi", 3);
	test_ft_strlcpy("hog", "fuoi", 4);
	test_ft_strlcpy("hoge", "fugafugafuga", 0);
	test_ft_strlcpy("hoge", "fugafugafuga", 1);
	test_ft_strlcpy("hoge", "fugafugafuga", 2);
	test_ft_strlcpy("hoge", "fugafugafuga", 3);
	test_ft_strlcpy("hoge", "fugafugafuga", 4);
	test_ft_strlcpy("hoge", "fugafugafuga", 5);
	test_ft_strlcpy("hogehogehoge", "fuga", 0);
	test_ft_strlcpy("hogehogehoge", "fuga", 1);
	test_ft_strlcpy("hogehogehoge", "fuga", 2);
	test_ft_strlcpy("hogehogehoge", "fuga", 3);
	test_ft_strlcpy("hogehogehoge", "fuga", 4);
	test_ft_strlcpy("hogehogehoge", "fuga", 12);
	test_ft_strlcpy("hogehogehoge", "fuga", 13);
	test_ft_strlcpy("", "fuga", 0);
	test_ft_strlcpy("", "fuga", 1);
	test_ft_strlcpy("", "fuga", 2);
	test_ft_strlcpy("", "fuga", 3);
	test_ft_strlcpy("", "fuga", 4);
	test_ft_strlcpy("", "", 0);
	test_ft_strlcpy("01234567890", "-2147483648", 11);
	//test_ft_strlcpy_null();
}

void	test_ft_strlcat_dup(char *dst, char *src, int dstsize)
{
	char	*copied_dst_lib;
	char	*copied_src_lib;
	char	*copied_dst_my;
	char	*copied_src_my;
	int		res_lib;
	int		res_my;
	int		length;
	copied_dst_lib = ft_strdup(dst);
	copied_dst_my = ft_strdup(dst);
	copied_src_lib = ft_strdup(src);
	copied_src_my = ft_strdup(src);

	printf("dst: %s,  src: %s size: %d\n", dst, src, dstsize);
	length = strlen(copied_dst_lib);
	res_lib = strlcat(copied_dst_lib, copied_src_lib, dstsize);
	res_my = ft_strlcat(copied_dst_my, copied_src_my, dstsize);
	assert(res_lib, res_my);
}

void	test_ft_strlcat(char *dst, char *src, int dstsize, int bufsize)
{
	char	*copied_dst_lib;
	char	*copied_src_lib;
	char	*copied_dst_my;
	char	*copied_src_my;
	int		res_lib;
	int		res_my;
	int		length;
	int		i;
	int		ng_count;

	printf("dst: %s, src: %s, dstsize: %d\n", dst, src, dstsize);
	copied_dst_lib = calloc(1, sizeof(char) * bufsize);
	strcpy(copied_dst_lib, dst);
	copied_dst_my = calloc(1, sizeof(char) * bufsize);
	strcpy(copied_dst_my, dst);
	copied_src_lib = ft_strdup(src);
	copied_src_my = ft_strdup(src);
	length = strlen(copied_dst_lib);
	res_lib = strlcat(copied_dst_lib, copied_src_lib, dstsize);
	res_my = ft_strlcat(copied_dst_my, copied_src_my, dstsize);
	i = 0;
	ng_count = 0;
	while(i < bufsize){
		ng_count += copied_dst_lib[i] != copied_dst_my[i];
		i++;
	}
	assert(0, ng_count);
	assert(res_lib, res_my);
	test_ft_strlcat_dup(dst, src, dstsize);
}

void	test_strlcat_case()
{
	printf("strlcat...\n");
	printf("ft_strlcat...\n");
	test_ft_strlcat("hoge", "fuga", 0, 100);
	test_ft_strlcat("hoge", "fuga", 1, 100);
	test_ft_strlcat("hoge", "fuga", 2, 100);
	test_ft_strlcat("hoge", "fuga", 3, 100);
	test_ft_strlcat("hoge", "fuga", 4, 100);
	test_ft_strlcat("hoge", "fuga", 5, 100);
	test_ft_strlcat("hoge", "fuga", 6, 100);
	test_ft_strlcat("hoge", "fuga", 7, 100);
	test_ft_strlcat("hoge", "fuga", 8, 100);
	test_ft_strlcat("hoge", "fuga", 9, 100);
	test_ft_strlcat("hoge", "fuga", 10, 100);
	test_ft_strlcat("hoge", "fuga", 11, 100);
	test_ft_strlcat("hoge", "fuo", 0, 100);
	test_ft_strlcat("hoge", "fuo", 1, 100);
	test_ft_strlcat("hoge", "fuo", 2, 100);
	test_ft_strlcat("hoge", "fuo", 3, 100);
	test_ft_strlcat("hoge", "fuo", 4, 100);
	test_ft_strlcat("hoge", "fuo", 5, 100);
	test_ft_strlcat("hoge", "fuo", 6, 100);
	test_ft_strlcat("hoge", "fuo", 7, 100);
	test_ft_strlcat("hoge", "fuo", 8, 100);
	test_ft_strlcat("hoge", "fuo", 9, 100);
	test_ft_strlcat("hoge", "fuo", 10, 100);
	test_ft_strlcat("hog", "fuoi", 0, 100);
	test_ft_strlcat("hog", "fuoi", 1, 100);
	test_ft_strlcat("hog", "fuoi", 2, 100);
	test_ft_strlcat("hog", "fuoi", 3, 100);
	test_ft_strlcat("hog", "fuoi", 4, 100);
	test_ft_strlcat("hog", "fuoi", 5, 100);
	test_ft_strlcat("hog", "fuoi", 6, 100);
	test_ft_strlcat("hog", "fuoi", 7, 100);
	test_ft_strlcat("hog", "fuoi", 8, 100);
	test_ft_strlcat("hog", "fuoi", 9, 100);
	test_ft_strlcat("hog", "fuoi", 10, 100);
	test_ft_strlcat("hoge", "fugafugafuga", 0, 100);
	test_ft_strlcat("hoge", "fugafugafuga", 1, 100);
	test_ft_strlcat("hoge", "fugafugafuga", 2, 100);
	test_ft_strlcat("hoge", "fugafugafuga", 3, 100);
	test_ft_strlcat("hoge", "fugafugafuga", 4, 100);
	test_ft_strlcat("hoge", "fugafugafuga", 5, 100);
	test_ft_strlcat("hoge", "fugafugafuga", 6, 100);
	test_ft_strlcat("hoge", "fugafugafuga", 7, 100);
	test_ft_strlcat("hoge", "fugafugafuga", 8, 100);
	test_ft_strlcat("hoge", "fugafugafuga", 9, 100);
	test_ft_strlcat("hoge", "fugafugafuga", 10, 100);
	test_ft_strlcat("hoge", "fugafugafuga", 11, 100);
	test_ft_strlcat("hoge", "fugafugafuga", 12, 100);
	test_ft_strlcat("hoge", "fugafugafuga", 13, 100);
	test_ft_strlcat("hogehogehoge", "fuga", 0, 100);
	test_ft_strlcat("hogehogehoge", "fuga", 1, 100);
	test_ft_strlcat("hogehogehoge", "fuga", 2, 100);
	test_ft_strlcat("hogehogehoge", "fuga", 3, 100);
	test_ft_strlcat("hogehogehoge", "fuga", 4, 100);
	test_ft_strlcat("hogehogehoge", "fuga", 12, 100);
	test_ft_strlcat("hogehogehoge", "fuga", 13, 100);
	test_ft_strlcat("", "fuga", 0, 100);
	test_ft_strlcat("", "fuga", 1, 100);
	test_ft_strlcat("", "fuga", 2, 100);
	test_ft_strlcat("", "fuga", 3, 100);
	test_ft_strlcat("", "fuga", 4, 100);
	test_ft_strlcat("", "fuga", 5, 100);
	test_ft_strlcat("", "fuga", 6, 100);
	test_ft_strlcat("", "fuga", 7, 100);
	test_ft_strlcat("fuga", "", 0, 100);
	test_ft_strlcat("fuga", "", 1, 100);
	test_ft_strlcat("fuga", "", 2, 100);
	test_ft_strlcat("fuga", "", 3, 100);
	test_ft_strlcat("fuga", "", 4, 100);
	test_ft_strlcat("fuga", "", 5, 100);
	test_ft_strlcat("fuga", "", 6, 100);
	test_ft_strlcat("fuga", "", 7, 100);
	test_ft_strlcat("", "", 0, 100);
	test_ft_strlcat("", "", 1, 100);
	test_ft_strlcat("", "", 2, 100);
	test_ft_strlcat("", "", 3, 100);
	test_ft_strlcat("", "", 4, 100);
}

void	test_strchr(const char *s, int c)
{
	char *res_lib;
	char *res_my;

	printf("c: %d\n", c);
	res_lib = strchr(s, c);
	res_my = ft_strchr(s, c);

	if(res_lib == res_my)
	{
		printf("[ok]: expect: %p, actual: %p\n", res_lib, res_my);
	}
	else
	{
		printf("[ng!!!!!!]: expect: %p, actual: %p\n", res_lib, res_my);
		exit(1);
	}
}

void	test_strchr_case()
{
	printf("ft_strchr...\n");
	test_strchr("abcdefghijklmn", 'a');
	test_strchr("abcdefghijklmn", 'f');
	test_strchr("abcdefghijklmn", 'o');
	test_strchr("abcdefghijklmn", '\0');
	test_strchr("abcdefghijklmn", (1 << 10) + 'f');
	test_strchr("abcdefghijklmn", (1 << 10) + 'o');
	test_strchr("abcdefghijklmn", (1 << 31) + 'f');
	test_strchr("abcdefghijklmn", 2145);
	test_strchr("ghi,", ',');
	test_strchr("abd\0", '\0');
	test_strchr("", '\0');
}

void	test_strrchr(const char *s, int c)
{
	char	*res_lib;
	char	*res_my;

	res_lib = strrchr(s, c);
	res_my = ft_strrchr(s, c);

	if(res_lib == res_my) {
		printf("[ok]: expect: %p, actual: %p\n", res_lib, res_my);
	} else {
		printf("[ng!!!!!!]: expect: %p, actual: %p\n", res_lib, res_my);
		exit(1);
	}
}

void	test_strrchr_case()
{
	printf("ft_strrchr...\n");
	test_strrchr("abcdefghijklmn", 'a');
	test_strrchr("abcdefghijklmn", 'f');
	test_strrchr("abcdefghijklmn", 'o');
	test_strrchr("abcdefghijklmn", '\0');
	test_strrchr("abcdefghijklmn", (1 << 10) + 'f');
	test_strrchr("abcdefghijklmn", (1 << 10) + 'o');
	test_strrchr("abcdefghijklmn", (1 << 31) + 'f');
	test_strrchr("abcdefghijklmn", 2145);

	test_strrchr("abcdefghiajklamn", 'a');
	test_strrchr("abcdefghifjkflmn", 'f');
	test_strrchr("abcdefghijaklmn", 'o');
	test_strrchr("abcdefghij\0klmn", '\0');
	test_strrchr("abcdefghijfklmn", (1 << 10) + 'f');
	test_strrchr("abcdefghijklmn", (1 << 10) + 'o');
	test_strrchr("abcdefghijkflmn", (1 << 31) + 'f');
	test_strrchr("abcdefghijkalmn", 2145);
}

void	test_strncmp(char *s1, char *s2, int n)
{
	int	res_lib;
	int res_my;

	res_lib = strncmp(s1, s2, n);
	res_my = ft_strncmp(s1, s2, n);

	printf("%s, %s, %d\n", s1, s2, n);
	assert(res_lib, res_my);
}

void	test_strncmp_case()
{
	printf("ft_strncmp...\n");
	test_strncmp("", "", 0);
	test_strncmp("", "", 1);
	test_strncmp("", "", 2);
	test_strncmp("", "", 3);
	test_strncmp("", "a", 0);
	test_strncmp("", "a", 1);
	test_strncmp("", "a", 2);
	test_strncmp("", "a", 3);
	test_strncmp("a", "", 0);
	test_strncmp("a", "", 1);
	test_strncmp("a", "", 2);
	test_strncmp("a", "", 3);
	test_strncmp("abc", "abc", 0);
	test_strncmp("abc", "abc", 1);
	test_strncmp("abc", "abc", 2);
	test_strncmp("abc", "abc", 3);
	test_strncmp("abc", "abc", 4);
	test_strncmp("abc", "abc", 5);
	test_strncmp("abc", "abcd", 0);
	test_strncmp("abc", "abcd", 1);
	test_strncmp("abc", "abcd", 2);
	test_strncmp("abc", "abcd", 3);
	test_strncmp("abc", "abcd", 4);
	test_strncmp("abc", "abcd", 5);
	test_strncmp("abcd", "abc", 0);
	test_strncmp("abcd", "abc", 1);
	test_strncmp("abcd", "abc", 2);
	test_strncmp("abcd", "abc", 3);
	test_strncmp("abcd", "abc", 4);
	test_strncmp("abcd", "abc", 5);
	test_strncmp("abcde", "abc", 0);
	test_strncmp("abcde", "abc", 1);
	test_strncmp("abcde", "abc", 2);
	test_strncmp("abcde", "abc", 3);
	test_strncmp("abcde", "abc", 4);
	test_strncmp("abcde", "abc", 5);
	test_strncmp("abcde", "abc", 6);
	test_strncmp("abe", "abefrg", 0);
	test_strncmp("abe", "abefrg", 1);
	test_strncmp("abe", "abefrg", 2);
	test_strncmp("abe", "abefrg", 3);
	test_strncmp("abe", "abefrg", 4);
	test_strncmp("abe", "abefrg", 5);
	test_strncmp("abe", "abefrg", 6);
	test_strncmp("abe", "abefrg", 7);
	test_strncmp("abe", "abefrg", 8);
	test_strncmp("abc", "def", 0);
	test_strncmp("abc", "def", 1);
	test_strncmp("abc", "def", 2);
	test_strncmp("abc", "def", 3);
	test_strncmp("abc", "def", 4);
	test_strncmp("abc", "def", 5);
	test_strncmp("abc", "aef", 0);
	test_strncmp("abc", "aef", 1);
	test_strncmp("abc", "aef", 2);
	test_strncmp("abc", "aef", 3);
	test_strncmp("abc", "aef", 4);
	test_strncmp("abc", "aef", 5);
	test_strncmp("abc", "abf", 0);
	test_strncmp("abc", "abf", 1);
	test_strncmp("abc", "abf", 2);
	test_strncmp("abc", "abf", 3);
	test_strncmp("abc", "abf", 4);
	test_strncmp("abc", "abf", 5);
	test_strncmp("abc", "abfg", 0);
	test_strncmp("abc", "abfg", 1);
	test_strncmp("abc", "abfg", 2);
	test_strncmp("abc", "abfg", 3);
	test_strncmp("abc", "abfg", 4);
	test_strncmp("abc", "abfg", 5);
	test_strncmp("hoge", "foo", 1);
	test_strncmp("hoge", "foo", 2);
	test_strncmp("hoge", "foo", 3);
	test_strncmp("hoge", "foo", 4);
	char *str = "Foo Bar Hoge";
	test_strncmp(str + 4, "Bar", 2);
	test_strncmp(str + 4, "Bar", 3);
	test_strncmp(str + 4, "Bar", 4);
	test_strncmp("\200\179", "ab", 4);
}

void	test_strnstr(const char *haystack, const char *needle, int len)
{
	char	*res_lib;
	char	*res_my;

	//printf("haystack: %s, needle: %s, len: %d\n", haystack, needle, len);
	res_lib = strnstr(haystack, needle, len);
	res_my = ft_strnstr(haystack, needle, len);
	if(res_lib == res_my)
		printf("[ok]: expect: %p, actual: %p\n", res_lib, res_my);
	else {
		printf("haystack: %s, needle: %s, len: %d\n", haystack, needle, len);
		printf("[ng!!!!!!]: expect: %p, actual: %p\n", res_lib, res_my);
		exit(1);
	}
}

void	test_strnstr_case()
{
	printf("ft_strnstr...\n");
	for (int i = 0; i < 20; i++) {
		test_strnstr("Foo Bar Hoge", "Bar", i);
		test_strnstr("Foo Bar Hoge", "Foo Hoge", i);
		test_strnstr("abcabcabc", "abc", i);
		test_strnstr("abcabcabc", "abcd", i);
		test_strnstr("abcabcabc", "ab\0cd", i);
		test_strnstr("abca\0bcabc", "ab\0cd", i);
	}
}

void	test_atoi(const char *str)
{
	int lib;
	int my;

	printf("atoi..:%s\n", str);
	lib = atoi(str);
	my = ft_atoi(str);
	assert(lib, my);
}

void	test_atoi_case()
{
	printf("atoi...\n");
	test_atoi("a");
	test_atoi("\0");
	test_atoi("100\n");
	test_atoi("-1100");
	test_atoi("-");
	test_atoi("  12345  6789");
	test_atoi("  ");
	test_atoi("3456  ");
	test_atoi("\01012346  6789");
	test_atoi("\01112347  6789");
	test_atoi("\01212348  6789");
	test_atoi("\01312349  6789");
	test_atoi("\01412350  6789");
	test_atoi("\01512351  6789");
	test_atoi("\01612352  6789");
	test_atoi("\01712353  6789");
	test_atoi("\010\0102346  6789");
	test_atoi("\011\0112347  6789");
	test_atoi("\012\0122348  6789");
	test_atoi("\013\0132349  6789");
	test_atoi("\014\0142350  6789");
	test_atoi("\015\0152351  6789");
	test_atoi("\016\0162352  6789");
	test_atoi("\017\0172353  6789");
	test_atoi("\t\v\f\r\n \f- \f\t\n\r    06050");
	test_atoi("\t\v\f\r\n \f-06050");
	test_atoi("-123THERE IS A NYANCAT UNDER YOUR BED");
	test_atoi("123456789");
	test_atoi("12345  6789");
	test_atoi("1234\056789");
	test_atoi("2147483648");
	test_atoi("+2147483647");
	test_atoi("2147483647");
	test_atoi("-2147483648");
	test_atoi("-2147483649");
	test_atoi("6442450944");
	test_atoi("4294969344");
	printf("atoi over long max and long min...\n");
	test_atoi("-9223372036854775808");
	test_atoi("9223372036854775807");
	test_atoi("-9223372036854775809");
	test_atoi("9223372036854775808");
	test_atoi("63410682753376583680");
}

void	test_ascii(int (*lib)(int), int (*my)(int), int c)
{
	assert(lib(c), my(c));
}

void	test_ascii_case()
{
	int c;

	c = 0;
	while (c >= 0 && c <= 255)
	{
		test_ascii(isalpha, ft_isalpha, c);
		test_ascii(isdigit, ft_isdigit, c);
		//test_ascii(isspace, ft_isspace, c);
		test_ascii(isalnum, ft_isalnum, c);
		test_ascii(isascii, ft_isascii, c);
		test_ascii(isprint, ft_isprint, c);
		test_ascii(toupper, ft_toupper, c);
		test_ascii(tolower, ft_tolower, c);
		c++;
	}
}

void	test_calloc(int count, int size)
{
	void	*lib_ptr;
	void	*my_ptr;
	int		i;

	lib_ptr = calloc(count, size);
	my_ptr = ft_calloc(count, size);
	i = 0;
	while (i < count * size)
	{
		assert(((char*)lib_ptr)[i], ((char*)my_ptr)[0]);
		i++;
	}
}

void	test_calloc_case()
{
	printf("ft_calloc...\n");
	test_calloc(3, sizeof(char));
	test_calloc(3, sizeof(short));
	test_calloc(3, sizeof(int));
	test_calloc(3, sizeof(long));
	test_calloc(-1, sizeof(long));
	test_calloc(0, 0);
	test_calloc(0, 1);
	test_calloc(1, 0);

	struct Hoge {
		int x0;
		struct Fuga {
			int y0;
			int y1;
			int y2;
		} y;
		int x1;
	};
	test_calloc(5, sizeof(struct Hoge));
}

void	test_strdup(const char *s1)
{
	char	*lib;
	char	*my;
	int		len;
	int		i;

	lib = strdup(s1);
	my = ft_strdup(s1);
	len = ft_strlen(lib);
	i = 0;
	while (i <= len)
	{
		assert(lib[i], my[i]);
		i++;
	}
}

void	test_strdup_case()
{
	printf("ft_strdup...\n");
	test_strdup("");
	test_strdup("\0");
	test_strdup("a\0\0");
	test_strdup("\0a\0");
	test_strdup("abc\n");
	test_strdup("hogeabc\n");
}

void	test_substr(char const *s, unsigned int start, size_t len, char *result)
{
	char	*my;
	int		my_len;
	int		result_len;
	int		i;

	my = ft_substr(s, start, len);
	if (result == NULL)
	{
		if (my == NULL) {
			printf("[ok]\n");
		} else {
			printf("[ng] result should be NULL but my: %s\n", my);
			exit(1);
		}
		return;
	}

	my_len = ft_strlen(my);
	result_len = ft_strlen(result);
	assert(result_len, my_len);
	i = 0;
	while (i <= my_len)
	{
		assert(result[i], my[i]);
		i++;
	}
}

void	test_substr_case()
{
	printf("ft_substr...\n");
	test_substr("", 0, 0, "");
	test_substr("", 0, 1, "");
	test_substr("", 1, 0, "");
	test_substr("", 1, 1, "");
	test_substr("abcdef", 0, 0, "");
	test_substr("abcdef", 0, 1, "a");
	test_substr("abcdef", 0, 6, "abcdef");
	test_substr("abcdef", 0, 7, "abcdef");
	test_substr("abcdef", 0, 5, "abcde");
	test_substr("abcdef", 3, 0, "");
	test_substr("abcdef", 3, 2, "de");
	test_substr("abcdef", 3, 3, "def");
	test_substr("abcdef", 3, 4, "def");
	test_substr("abcdef", 5, 0, "");
	test_substr("abcdef", 5, 1, "f");
	test_substr("abcdef", 5, 2, "f");
	test_substr("abcdef", 6, 0, "");
	test_substr("abcdef", 6, 1, "");
	test_substr("abc\0def", 0, 2, "ab");
	test_substr("abc\0def", 0, 3, "abc");
	test_substr("abc\0def", 0, 4, "abc");
	test_substr("abc\0def", 2, 0, "");
	test_substr("abc\0def", 2, 1, "c");
	test_substr("abc\0def", 2, 2, "c");
	test_substr("abc\0def", 3, 0, "");
	test_substr("abc\0def", 3, 1, "");
	test_substr("abc\0def", 3, 2, "");
	test_substr("abc\0def", 4, 0, "");
	test_substr("abc\0def", 4, 1, "");
	test_substr("abc\0def", 4, 2, "");
	test_substr("abc\0def", 4, 3, "");
	printf("substr NULL\n");
	test_substr(NULL, 4, 4, NULL);
}

void 	test_strjoin(char const *s1, char const *s2, char *result)
{
	char	*my;
	int		len_my;
	int		len_result;
	int		i;

	printf("s1: %s, s2: %s\n", s1, s2);
	my = ft_strjoin(s1, s2);
	if (my == NULL)
	{
		ptr_assert(my, result);
		return;
	}

	len_result = ft_strlen(result);
	len_my = ft_strlen(my);
	assert(len_result, len_my);
	i = 0;
	while (i <= len_result)
	{
		assert(result[i], my[i]);
		i++;
	}
}

void	test_strjoin_case()
{
	printf("strjoin...\n");
	test_strjoin("", "", "");
	test_strjoin("", "abc", "abc");
	test_strjoin("abc", "", "abc");
	test_strjoin("abc", "def", "abcdef");
	test_strjoin("ab", "cdef", "abcdef");
	test_strjoin("abcd", "ef", "abcdef");
	//test_strjoin("abcd", NULL, "abcd");
	//test_strjoin(NULL, "abcd", "abcd");
}

void	test_strtrim(char const *s1, char const *set, char *result)
{
	char	*my;
	int		len_my;
	int		len_result;
	int		i;

	printf("s1: %s, set: %s, result: %s\n", s1, set, result);
	my = ft_strtrim(s1, set);
	len_my = ft_strlen(my);
	len_result = ft_strlen(result);
	printf("result: %s, my: %s\n", result, my);
	assert(len_result, len_my);
	i = 0;
	while (i <= len_my)
	{
		assert(result[i], my[i]);
		i++;
	}
}

void	test_strtrim_null()
{
	ptr_assert(NULL, ft_strtrim(NULL, NULL));
	ptr_assert(NULL, ft_strtrim(NULL, "ABC"));
	ptr_assert(NULL, ft_strtrim(NULL, ""));
}

void	test_strtrim_case()
{
	printf("strtrim...\n");
	char c;
	test_strtrim("abcdefghijkabcdefghijk", "def", "abcdefghijkabcdefghijk");
	test_strtrim("abcdefghijkdefghijkabc", "abc", "defghijkdefghijk");
	test_strtrim("abcdefghijkabcdefghijkabc", "abc", "defghijkabcdefghijk");
	test_strtrim("", "", "");
	test_strtrim("abc", "abc", "");
	//test_strtrim("abc", "abcded", "abc");
	test_strtrim("abc", "a", "bc");
	test_strtrim("abc", "b", "abc");
	test_strtrim("abc", "c", "ab");
	test_strtrim("abcade", "a", "bcade");
	test_strtrim("abcbef", "b", "abcbef");
	test_strtrim("abcccde", "c", "abcccde");
	test_strtrim("abcccde", "e", "abcccd");
	test_strtrim("abcdef", "ghi", "abcdef");
	test_strtrim("abcdef", "ahi", "bcdef");
	test_strtrim("abcdef", "ahf", "bcde");
	test_strtrim("abcdef", "abcdef", "");
	test_strtrim("abcdef", "abcde", "f");
	test_strtrim("abcdef", "abdef", "c");
	test_strtrim("", "abdef", "");
	//test_strtrim("", NULL, "");
	test_strtrim("abc", NULL, "abc");
	test_strtrim(",abc,,,abc,bc", ",a", "bc,,,abc,bc");
	test_strtrim("\0abc,,,abc,bc\0", "\0", "");
	c = ',';
	char	*set = malloc(2 * sizeof(char));
	set[0] = c;
	set[1] = '\0';
	test_strtrim("abc,def,ghi,", set, "abc,def,ghi");
	test_strtrim("abc,def,ghi,", set, "abc,def,ghi");
	test_strtrim("abc,def,ghi,,", set, "abc,def,ghi");
	test_strtrim("abc,def,ghi,,,", set, "abc,def,ghi");
	test_strtrim("abc,def,,ghi,,,", set, "abc,def,,ghi");
	test_strtrim("abc,,def,,ghi,,,", set, "abc,,def,,ghi");
	test_strtrim(",abc,,def,,ghi,,,", set, "abc,,def,,ghi");
	test_strtrim(",,abc,,def,,ghi,,,", set, "abc,,def,,ghi");
	test_strtrim(",,abc,,,def,,ghi,,,", set, "abc,,,def,,ghi");
	test_strtrim(",,abc,,,def,,,ghi,,,", set, "abc,,,def,,,ghi");
	test_strtrim(",,abc,,,def,,,ghi,,,,", set, "abc,,,def,,,ghi");
	free(set);
	test_strtrim(",,,,,,", ",", "");
	test_strtrim_null();
}

int		get_ary_len(char **str_ary)
{
	int	len;

	len = 0;
	if (str_ary == NULL)
		return 0;
	while (*str_ary++ != NULL)
		len++;
	return (len);
}

void	test_ft_split(char const *s, char c, char **result)
{
	char	**my;
	int		len_my;
	int		len_result;
	int		i;
	int		n;
	char	*c_invalid;

	printf("s: %s, c: %c\n", s, c);
	c_invalid = malloc(10 * sizeof(char));
	c_invalid[0] = c;
	for (int i = 0; i < 10; i++)
	{
		c_invalid[1 + i] = 'a' + i;
	}

	printf("start:  %s\n", s);
	len_result = get_ary_len(result);
	printf("len_result: %d\n", len_result);
	printf("c: %s\n", c_invalid);

	my = ft_split(s, *c_invalid);
	printf("finish\n");
	len_my = get_ary_len(my);
	printf("len_my: %d\n", len_my);
	assert(len_result, len_my);

	i = 0;
	while (result[i] != NULL)
	{
		n = ft_strlen(result[i]);
		printf("result: %s my: %s\n", result[i], my[i]);
		assert(ft_strlen(result[i]), ft_strlen(my[i]));
		assert(0, ft_strncmp(result[i], my[i], n));
		// NULL terminate check
		assert(result[i][n], my[i][n]);
		i++;
	}
	i = 0;
	while (my[i] != NULL)
		free(my[i++]);
	free(my);
}

void	test_ft_split_null()
{
	ptr_assert(NULL, ft_split(NULL, 'c'));
}

void	test_ft_split_case()
{
	printf("ft_split...\n");
	test_ft_split_null();
	char* result1[] = {"abc", "def", "ghi", NULL};
	test_ft_split("abc,def,ghi", ',', result1);

	char* result2[] = {"abc", "def", "ghi", NULL};
	test_ft_split("abc,def,ghi,", ',', result2);
	test_ft_split("abc,def,ghi,,", ',', result2);
	test_ft_split("abc,def,ghi,,,", ',', result2);
	test_ft_split("abc,def,,ghi,,,", ',', result2);
	test_ft_split("abc,,def,,ghi,,,", ',', result2);
	test_ft_split(",abc,,def,,ghi,,,", ',', result2);
	test_ft_split(",,abc,,def,,ghi,,,", ',', result2);
	test_ft_split(",,abc,,,def,,ghi,,,", ',', result2);
	test_ft_split(",,abc,,,def,,,ghi,,,", ',', result2);
	test_ft_split(",,abc,,,def,,,ghi,,,,", ',', result2);

	char* result3[] = {"abc", "ghi", NULL};
	test_ft_split("abc,,ghi", ',', result3);

	char* result4[] = {"a", NULL};
	test_ft_split(",,a,", ',', result4);

	char* result5[] = {"abc", "0", "def", NULL};
	test_ft_split("abc#0#def\0#ghi", '#', result5);

	char* result6[] = {"abc", "0", "def", "ghi", "jkl", NULL};
	test_ft_split("abc\n0\ndef\nghi\njkl", '\n',  result6);

	char* result7[] = {NULL};
	test_ft_split(",,,,", ',', result7);

	char* result8[] = {NULL};
	test_ft_split("", ',', result8);

	char* result9[] = {"abc", NULL};
	test_ft_split("abc", ',', result9);

	char* result10[] = {"olol", NULL};
	test_ft_split("                  olol", ' ', result10);

	char* result11[] = {"olol", NULL};
	test_ft_split("olol\0aiai", '\0', result11);

	char* result12[] = { NULL};
	test_ft_split("", '\0', result12);

	char* result13[] = { NULL};
	test_ft_split("\0", '\0', result13);
}

void	test_itoa(int i, char *result)
{
	char *my;

	my = ft_itoa(i);
	//printf("my: %s, result: %s\n", my, result);
	assert(0, strcmp(result, my));
}

void	test_itoa_case()
{
	printf("ft_itoa...\n");
	test_itoa(0, "0");
	test_itoa(1, "1");
	test_itoa(2, "2");
	test_itoa(10, "10");
	test_itoa(99, "99");
	test_itoa(100, "100");
	test_itoa(2147483647, "2147483647");
	test_itoa(-2147483648, "-2147483648");
	test_itoa(-214, "-214");
}

void	test_ft_strmapi(char const *s, char (*f)(unsigned int, char), char *result)
{
	char	*my;
	int		len_my;
	int		len_result;

	my = ft_strmapi(s, f);
	printf("my: %s, result: %s\n", my, result);
	len_my = ft_strlen(my);
	len_result = ft_strlen(result);
	assert(len_result, len_my);
	assert(0, strcmp(my, result));
}

char	move_ascii_byi(unsigned int i, char c)
{
	return (i + c);
}

char	change_odd_to_capital(unsigned int i, char c)
{
	if (i % 2 && c >= 'a' && c <= 'z')
	{
		return c + ('A' - 'a');
	}
	return (c);
}

void	test_ft_strmapi_null(char (*f)(unsigned int, char))
{
	ptr_assert(NULL, ft_strmapi(NULL, f));
}

void	test_ft_strmapi_case()
{
	printf("ft_strmapi...\n");
	test_ft_strmapi("abc", move_ascii_byi, "ace");
	test_ft_strmapi("abcdEfg", change_odd_to_capital, "aBcDEFg");
	test_ft_strmapi_null(move_ascii_byi);
	test_ft_strmapi_null(change_odd_to_capital);
}

void	test_ft_putchar_fd()
{
	char	c;

	c = 0x80;

	while ((unsigned char)c < 0x7F)
	{
		if ((unsigned char)c != 0x07)
			ft_putchar_fd(c, 1);
		c++;
	}
	ft_putchar_fd(c, 1);
}

void	test_ft_putstr_fd()
{
	ft_putstr_fd("abcdef\n", 1);
	ft_putstr_fd("0123456789\n", 1);
}

void	test_ft_putendl_fd()
{
	ft_putendl_fd("abcdefghijklm", 1);
	ft_putendl_fd("", 1);
}

void	test_ft_putnbr_fd()
{
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(42, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);
}

/*
typedef	struct Number {
	int		num;
	char	*dummy;
} Number;

void	show_lst(t_list *lst)
{
	while(lst)
	{
		if (lst->content)
			printf("%d, ", ((Number*)lst->content)->num);
		else
			printf("NULL,");
		lst = lst->next;
	}
	printf("\n");
}

t_list	*create_list_from_str(char *str)
{
	int		i;
	Number	*number;
	char	*dummy;
	char	**splitted;
	t_list	*lst;
	t_list	**init;

	splitted = ft_split(str, ',');
	i = 0;
	init = malloc(sizeof(t_list*));
	dummy = "dummyyyyyy";
	while (splitted[i])
	{
		number = malloc(sizeof(Number));
		number->num =ft_atoi(splitted[i]);
		number->dummy = strdup(dummy);
		lst = ft_lstnew(number);
		if (i == 0)
			*init = lst;
		else
			ft_lstadd_front(init, lst);
		i++;
	}
	if (i == 0)
		return (NULL);
	return (*init);
}

void	test_addfront_test(char *str, int result[], int size)
{
	int		i;
	t_list	*itr;
	t_list	*init;

	init = create_list_from_str(str);
	itr = init;
	i = 0;
	//show_lst(itr);
	while(itr)
	{
		assert(result[i++], ((Number*)(itr->content))->num);
		itr = itr->next;
	}

	// lstsize
	assert(size, ft_lstsize(init));
}

void	test_addfront_case()
{
	printf("ft_addfront...\n");
	test_addfront_test("1, 2, 3, 4, 5, 6, 7, 8, 9", ({ int result[] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; result; }), 9);
	test_addfront_test("1", ({ int result[] = {1}; result; }), 1);
}

void	test_lstsize_null()
{
	assert(0, ft_lstsize(NULL));
}

void	test_lstsize(char *str, int size)
{
	t_list	*lst;

	lst = create_list_from_str(str);
	assert(size, ft_lstsize(lst));
}

void	test_lstsize_case()
{
	printf("ft_lstsize...\n");
	test_lstsize("1, 2, 3, 4", 4);
	test_lstsize("1", 1);
	test_lstsize("", 0);
	test_lstsize_null();
}

void	test_lstlast(char *str)
{
	t_list	*lst;
	t_list	*last;
	int		n;

	n = 42;
	printf("1\n");
	lst = create_list_from_str(str);
	printf("2\n");
	last = ft_lstnew(&n);
	printf("3\n");
	ft_lstadd_back(&lst, last);
	printf("4\n");
	show_lst(lst);
	printf("5\n");
	ptr_assert(last, ft_lstlast(lst));
}

void	test_lstadd_back_null()
{
	t_list	**init;
	t_list	*lst;
	int		n;

	n = 42;
	printf("lstadd_back_null...\n");
	init = calloc(1, sizeof(t_list*));
	lst = ft_lstnew(&n);
	ft_lstadd_back(init, lst);
	ptr_assert(lst, ft_lstlast(*init));
}

void	test_lstlast_null()
{
	t_list	**init;
	t_list	*last;
	int		n;

	n = 42;
	printf("lstlast_null..\n");
	init = malloc(sizeof(t_list*));
	last = ft_lstnew(&n);
	init = &last;
	ft_lstadd_back(NULL, last);
	ft_lstadd_back(init, NULL);
	printf("ft_lstlast null...\n");
	ptr_assert(*init, ft_lstlast(*init));
}

void	test_lstlast_case()
{
	printf("ft_lstlast...\n");
	test_lstlast("1, 2, 3, 4, 5, 7 , 6, 9");
	test_lstlast_null();
	test_lstadd_back_null();
}

void	delete_element_number(void *content)
{
	printf("delete\n");
	free(((Number*)content)->dummy);
	((Number*)content)->dummy = NULL;
	free(content);
}

void	test_lstdelone(char *str, int i)
{
	t_list	*init;
	t_list	*lst;
	t_list	*target;
	void	*content;
	int		j;

	lst = create_list_from_str(str);
	j = 0;
	init = lst;
	while(lst)
	{
		if (j == i)
		{
			target = lst;
			content = target->content;
		}
		lst = lst->next;
		j++;
	}
	ft_lstdelone(target, delete_element_number);
	//printf("target->content\n");
	//ptr_assert(NULL, target->content);
	//printf("content\n");
	//ptr_assert(NULL, ((Number*)content)->dummy);
	//show_lst(init);
}

void	test_lstdelone_case()
{
	printf("ft_lstdelone...\n");
	test_lstdelone("1, 2, 3, 4, 5", 0);
	test_lstdelone("1, 2, 3, 4, 5", 2);
	test_lstdelone("1, 2, 3, 4, 5", 4);
}

void	test_lstclear(char *str, int size)
{
	t_list	*lst;

	lst = create_list_from_str(str);
	assert(size, ft_lstsize(lst));
	ft_lstclear(&lst, delete_element_number);
	assert(0, ft_lstsize(lst));
}

void	test_lstclear_case()
{
	printf("ft_lstclear...\n");
	test_lstclear("1,2,3,4,5,6", 6);
	test_lstclear("0", 1);;
	test_lstclear("", 0);;
}

void	show_element(void *content)
{
	printf("%d(%s), ", ((Number*)content)->num, ((Number*)content)->dummy);
}

void	test_lstiter(char *str)
{
	t_list	*lst;

	lst = create_list_from_str(str);
	ft_lstiter(lst, show_element);
	show_lst(lst);
	printf("\n");
}

void	*applied_function(void *content)
{
	Number	*new;
	new = malloc(sizeof(Number));
	new->num = ((Number*)content)->num + 1;
	new->dummy = ft_strdup(((Number*)content)->dummy);
	return new;
}

void	test_lstmap(char *str, int result[])
{
	t_list	*lst;
	t_list	*itr;
	t_list	*created;
	int		i;

	lst = create_list_from_str(str);
	created = ft_lstmap(lst, applied_function, delete_element_number);
	show_lst(created);
	i = 0;
	itr = created;
	while (itr)
	{
		assert(result[i], ((Number*)itr->content)->num);
		itr = itr->next;
		i++;
	}
}

void	test_lstmap_case()
{
	printf("ft_lstmap...\n");
	test_lstmap("1,2,3,4,5,6,7,8,9", ({int result[] = {10,9,8,7,6,5,4,3,2}; result; }));
	test_lstmap("", ({int result[] = {}; result; }));
}

void	test_lstiter_case()
{
	printf("ft_lstiter...\n");
	test_lstiter("1, 2, 3, 4");
	test_lstiter("1,");
	test_lstiter("");
}
*/
int		main(void)
{
	for(int i = 0; i < 100; i++) {
		
		test_strlen_case();
		test_memset_case();
		test_bzero_case();
		test_memcpy_case();
		test_memccpy_case();
		test_memmove_case();
		test_memchr_case();
		test_memcmp_case();
		test_ft_strlcpy_case();
		test_strlcat_case();
		test_strchr_case();
		test_strrchr_case();
		test_strncmp_case();
		test_strnstr_case();
		test_atoi_case();
		test_ascii_case();
		test_calloc_case();
		test_strdup_case();
		
		test_substr_case();
		test_strjoin_case();
		test_strtrim_case();
		
		test_ft_split_case();
		test_itoa_case();
		test_ft_strmapi_case();
		test_ft_putchar_fd();
		test_ft_putstr_fd();
		test_ft_putendl_fd();
		test_ft_putnbr_fd();
	}
	return (0);
}
