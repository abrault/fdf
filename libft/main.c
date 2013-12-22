/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_testor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 23:07:53 by gponsine          #+#    #+#             */
/*   Updated: 2013/11/29 13:46:05 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <xlocale.h>
#include "libft.h"

/*
**	PART ONE
*/
#define MEMSET
#define BZERO
#define MEMCPY
#define MEMCCPY
#define MEMMOVE
#define MEMCHR
#define MEMCMP
#define STRLEN
#define STRDUP
#define STRCPY
#define STRNCPY
#define STRCAT
#define STRNCAT
#define STRLCAT
#define STRCHR
#define STRRCHR
#define STRSTR
#define STRNSTR
#define STRCMP
#define STRNCMP
#define ATOI
#define ISALPHA
#define ISDIGIT
#define ISALNUM
#define ISASCII
#define ISPRINT
#define TOUPPER
#define TOLOWER

/*
**	PART TWO

#define MEMALLOC
#define MEMDEL
#define STRNEW
#define STRDEL
#define STRCLR
#define STRITER
#define STRITERI
#define STRMAP
#define STRMAPI
#define STREQU
#define STRNEQU
#define STRSUB
#define STRJOIN
#define STRTRIM
#define STRSPLIT
#define ITOA
#define PUTCHAR
#define PUTSTR
#define PUTENDL
#define PUTNBR
#define PUTCHAR_FD
#define PUTSTR_FD
#define PUTENDL_FD
#define PUTNBR_FD
*/
#ifdef	STRITERI
void	striteri_printf(unsigned int i, char *s)
{
    printf("&str[%d] = \"%s\"\n", i, s);
}
#endif
#ifdef	STRMAPI
int		strmapi_tolower(unsigned int i, int c)
{
    (void)i;
    return (tolower(c));
}
#endif

int		main(void)
{
    char	str[256];

    printf("\n>--------------------------------------------------------------------<\n\n");
    printf("function: ");
    gets(str);
    ft_putchar('\n');

#ifdef	MEMSET
    if (strcmp(str, "memset") == 0)
    {
        char			b[256];
        char			*b2;
        char			c;
        char			c2;
        int				len;
        int				len2;

        printf("void	*memset(void *b, int c, size_t len);\n");
        printf("b = ");
        gets(b);
        printf("c = ");
        gets(&c);
        printf("len = ");
        len = atoi(gets((char *)&len));
        b2 = strdup(b);
        c2 = c;
        len2 = len;
        printf("\nmemset(\"%s\", '%c', %d) :\n", b, c, len);
        printf("%s\n", (char *)memset(b, c, len));
        printf("b = %s\n", b);
        printf("\nft_memset(\"%s\", '%c', %d) :\n", b2, c2, len2);
        printf("%s\n", (char *)ft_memset(b2, c2, len2));
        printf("b = %s\n", b2);
        if (b2)
            free(b2);
    }
    else
#endif
#ifdef	BZERO
    if (strcmp(str, "bzero") == 0)
    {
        char			s[256];
        char			*s2;
        int				n;
        int				n2;
        int				len;
        int				i;

        printf("void	bzero(void *s, size_t n);\n");
        printf("s = ");
        gets(s);
        printf("n = ");
        n = atoi(gets((char *)&n));
        len = ((int)ft_strlen(s) + 1 > n) ? (int)ft_strlen(s) + 1 : n;
        s2 = strdup(s);
        n2 = n;
        printf("\nbzero(\"%s\", %d) :\n", s, n);
        bzero(s, n);
        i = 0;
        while (i < len)
        {
            printf("s[%d] = '%c'\n", i, s[i]);
            i++;
        }
        printf("\nft_bzero(\"%s\", %d) :\n", s2, n2);
        ft_bzero(s2, n2);
        i = 0;
        while (i < len)
        {
            printf("s[%d] = '%c'\n", i, s2[i]);
            i++;
        }
        if (s2)
            free(s2);
    }
    else
#endif
#ifdef	MEMCPY
    if (strcmp(str, "memcpy") == 0)
    {
        char	s1[256];
        char	*s12;
        char	s2[256];
        char	*s22;
        int		n;
        int		n2;

        printf("void	*memcpy(void *s1, const void *s2, size_t n);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        printf("n = ");
        n = atoi(gets((char *)&n));
        s12 = strdup(s1);
        s22 = strdup(s2);
        n2 = n;
        printf("\nmemcpy(\"%s\", \"%s\", %d) :\n", s1, s2, n);
        printf("%s\n", (char *)memcpy(s1, s2, n));
        printf("s1 = %s\n", s1);
        printf("s2 = %s\n", s2);
        printf("\nft_memcpy(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
        printf("%s\n", (char *)ft_memcpy(s12, s22, n2));
        printf("s1 = %s\n", s12);
        printf("s2 = %s\n", s22);
        if (s12)
            free(s12);
        if (s22)
            free(s22);
    }
    else
#endif
#ifdef	MEMCCPY
    if (strcmp(str, "memccpy") == 0)
    {
        char	s1[256];
        char	*s12;
        char	s2[256];
        char	*s22;
        char	c;
        char	c2;
        int		n;
        int		n2;

        printf("void	*memccpy(void *s1, const void *s2, int c, size_t n);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        printf("c = ");
        gets(&c);
        printf("n = ");
        n = atoi(gets((char *)&n));
        s12 = strdup(s1);
        s22 = strdup(s2);
        c2 = c;
        n2 = n;
        printf("\nmemccpy(\"%s\", \"%s\", '%c', %d) :\n", s1, s2, c, n);
        printf("%s\n", (char *)memccpy(s1, s2, c, n));
        printf("s1 = %s\n", s1);
        printf("s2 = %s\n", s2);
        printf("\nft_memccpy(\"%s\", \"%s\", '%c', %d) :\n", s12, s22, c2, n2);
        printf("%s\n", (char *)ft_memccpy(s12, s22, c2, n2));
        printf("s1 = %s\n", s12);
        printf("s2 = %s\n", s22);
        if (s12)
            free(s12);
        if (s22)
            free(s22);
    }
    else
#endif
#ifdef	MEMMOVE
    if (strcmp(str, "memmove") == 0)
    {
        char	s1[256];
        char	*s12;
        char	s2[256];
        char	*s22;
        int		n;
        int		n2;

        printf("void	*memmove*(void *s1, const void *s2, size_t n);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        printf("n = ");
        n = atoi(gets((char *)&n));
        s12 = strdup(s1);
        s22 = strdup(s2);
        n2 = n;
        printf("\nmemmove(\"%s\", \"%s\", %d) :\n", s1, s2, n);
        printf("%s\n", (char *)memmove(s1, s2, n));
        printf("s1 = %s\n", s1);
        printf("s2 = %s\n", s2);
        printf("\nft_memmove(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
        printf("%s\n", (char *)ft_memmove(s12, s22, n2));
        printf("s1 = %s\n", s12);
        printf("s2 = %s\n", s22);
        if (s12)
            free(s12);
        if (s22)
            free(s22);
    }
    else
#endif
#ifdef	MEMCHR
    if (strcmp(str, "memchr") == 0)
    {
        char			s[256];
        char			*s2;
        char			c;
        char			c2;
        int				n;
        int				n2;

        printf("void	*memchr(void *s, int c, size_t n);\n");
        printf("s = ");
        gets(s);
        printf("c = ");
        gets(&c);
        printf("n = ");
        n = atoi(gets((char *)&n));
        s2 = strdup(s);
        c2 = c;
        n2 = n;
        printf("\nmemchr(\"%s\", '%c', %d) :\n", s, c, n);
        printf("%s\n", (char *)memchr(s, c, n));
        printf("s = %s\n", s);
        printf("\nft_memchr(\"%s\", '%c', %d) :\n", s2, c2, n2);
        printf("%s\n", (char *)ft_memchr(s2, c2, n2));
        printf("s = %s\n", s2);
        if (s2)
            free(s2);
    }
    else
#endif
#ifdef	MEMCMP
    if (strcmp(str, "memcmp") == 0)
    {
        char	s1[256];
        char	*s12;
        char	s2[256];
        char	*s22;
        int		n;
        int		n2;

        printf("int	memcmp(const void *s1, const void *s2, size_t n);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        printf("n = ");
        n = atoi(gets((char *)&n));
        s12 = strdup(s1);
        s22 = strdup(s2);
        n2 = n;
        printf("\nmemcmp(\"%s\", \"%s\", %d) :\n", s1, s2, n);
        printf("%d\n", memcmp(s1, s2, n));
        printf("s1 = %s\n", s1);
        printf("s2 = %s\n", s2);
        printf("\nft_memcmp(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
        printf("%d\n", ft_memcmp(s12, s22, n2));
        printf("s1 = %s\n", s12);
        printf("s2 = %s\n", s22);
        if (s12)
            free(s12);
        if (s22)
            free(s22);
    }
    else
#endif
#ifdef	STRLEN
    if (strcmp(str, "strlen") == 0)
    {
        char	s[256];
        char	*s2;

        printf("size_t	strlen(const char *s);\n");
        printf("s = ");
        gets(s);
        s2 = strdup(s);
        printf("\nstrlen(\"%s\") :\n", s);
        printf("%d\n", (int)strlen(s));
        printf("s = %s\n", s);
        printf("\nft_strlen(\"%s\") :\n", s2);
        printf("%d\n", (int)ft_strlen(s2));
        printf("s = %s\n", s2);
        if (s2)
            free(s2);
    }
    else
#endif
#ifdef	STRDUP
    if (strcmp(str, "strdup") == 0)
    {
        char	s1[256];
        char	*s12;
        char	*sdup;

        printf("char	*strdup(const char *s1);\n");
        printf("s1 = ");
        gets(s1);
        s12 = strdup(s1);
        printf("\nstrdup(\"%s\") :\n", s1);
        printf("%s\n", sdup = strdup(s1));
        if (sdup)
            free(sdup);
        printf("\nft_strdup(\"%s\") :\n", s12);
        printf("%s\n", sdup = ft_strdup(s12));
        if (sdup)
            free(sdup);
    }
    else
#endif
#ifdef	STRCPY
    if (strcmp(str, "strcpy") == 0)
    {
        char	s1[256];
        char	*s12;
        char	s2[256];
        char	*s22;

        printf("char	*strcpy(char *s1, const char *s2);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        s12 = strdup(s1);
        s22 = strdup(s2);
        printf("\nstrcpy(\"%s\", \"%s\") :\n", s1, s2);
        printf("%s\n", strcpy(s1, s2));
        printf("s1 = %s\n", s1);
        printf("s2 = %s\n", s2);
        printf("\nft_strcpy(\"%s\", \"%s\") :\n", s12, s22);
        printf("%s\n", ft_strcpy(s12, s22));
        printf("s1 = %s\n", s12);
        printf("s2 = %s\n", s22);
        if (s12)
            free(s12);
        if (s22)
            free(s22);
    }
    else
#endif
#ifdef	STRNCPY
    if (strcmp(str, "strncpy") == 0)
    {
        char	s1[256];
        char	*s12;
        char	s2[256];
        char	*s22;
        int		n;
        int		n2;

        printf("char	*strncpy(char *s1, const char *s2, size_t n);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        printf("n = ");
        n = atoi(gets((char *)&n));
        s12 = strdup(s1);
        s22 = strdup(s2);
        n2 = n;
        printf("\nstrncpy(\"%s\", \"%s\") :\n", s1, s2);
        printf("%s\n", strncpy(s1, s2, n));
        printf("s1 = %s\n", s1);
        printf("s2 = %s\n", s2);
        printf("\nft_strncpy(\"%s\", \"%s\") :\n", s12, s22);
        printf("%s\n", ft_strncpy(s12, s22, n2));
        printf("s1 = %s\n", s12);
        printf("s2 = %s\n", s22);
        if (s12)
            free(s12);
        if (s22)
            free(s22);
    }
    else
#endif
#ifdef	STRCAT
    if (strcmp(str, "strcat") == 0)
    {
        char	s1[256];
        char	*s12;
        char	s2[256];
        char	*s22;

        printf("char	*strcat(char *s1, const char *s2);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        s12 = strdup(s1);
        s22 = strdup(s2);
        printf("\nstrcat(\"%s\", \"%s\") :\n", s1, s2);
        printf("%s\n", strcat(s1, s2));
        printf("s1 = %s\n", s1);
        printf("s2 = %s\n", s2);
        printf("\nft_strcat(\"%s\", \"%s\") :\n", s12, s22);
        printf("%s\n", ft_strcat(s12, s22));
        printf("s1 = %s\n", s12);
        printf("s2 = %s\n", s22);
        if (s12)
            free(s12);
        if (s22)
            free(s22);
    }
    else
#endif
#ifdef	STRNCAT
    if (strcmp(str, "strncat") == 0)
    {
        char	s1[256];
        char	*s12;
        char	s2[256];
        char	*s22;
        int		n;
        int		n2;

        printf("char	*strncat(char *s1, const char *s2, size_t n);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        printf("n = ");
        n = atoi(gets((char *)&n));
        s12 = strdup(s1);
        s22 = strdup(s2);
        n2 = n;
        printf("\nstrncat(\"%s\", \"%s\", %d) :\n", s1, s2, n);
        printf("%s\n", strncat(s1, s2, n));
        printf("s1 = %s\n", s1);
        printf("s2 = %s\n", s2);
        printf("\nft_strncat(\"%s\", \"%s\", %d) :\n", s12, s22, n);
        printf("%s\n", ft_strncat(s12, s22, n2));
        printf("s1 = %s\n", s12);
        printf("s2 = %s\n", s22);
        if (s12)
            free(s12);
        if (s22)
            free(s22);
    }
    else
#endif
#ifdef	STRLCAT
    if (strcmp(str, "strlcat") == 0)
    {
        char	dst[256];
        char	*dst2;
        char	src[256];
        char	*src2;
        int		size;
        int		size2;

        printf("size_t	strlcat(char *dst, const char *src, size_t size);\n");
        printf("dst = ");
        gets(dst);
        printf("src = ");
        gets(src);
        printf("size = ");
        size = atoi(gets((char *)&size));
        dst2 = strdup(dst);
        src2 = strdup(src);
        size2 = size;
        printf("\nstrlcat(\"%s\", \"%s\", %d) :\n", dst, src, size);
        printf("%d\n", (int)strlcat(dst, src, size));
        printf("dst = %s\n", dst);
        printf("src = %s\n", src);
        printf("\nft_strlcat(\"%s\", \"%s\", %d) :\n", dst2, src2, size2);
        printf("%d\n", (int)ft_strlcat(dst2, src2, size));
        printf("dst = %s\n", dst2);
        printf("src = %s\n", src2);
        if (dst2)
            free(dst2);
        if (src2)
            free(src2);
    }
    else
#endif
#ifdef	STRCHR
    if (strcmp(str, "strchr") == 0)
    {
        char			s[256];
        char			*s2;
        char			c;
        char			c2;

        printf("char	*strchr(const char *s, int c);\n");
        printf("s = ");
        gets(s);
        printf("c = ");
        gets(&c);
        s2 = strdup(s);
        c2 = c;
        printf("\nstrchr(\"%s\", '%c') :\n", s, c);
        printf("%s\n", strchr(s, c));
        printf("s = %s\n", s);
        printf("\nft_strchr(\"%s\", '%c') :\n", s2, c2);
        printf("%s\n", ft_strchr(s2, c2));
        printf("s = %s\n", s2);
        if (s2)
            free(s2);
    }
    else
#endif
#ifdef	STRRCHR
    if (strcmp(str, "strrchr") == 0)
    {
        char			s[256];
        char			*s2;
        char			c;
        char			c2;

        printf("char	*strrchr(const char *s, int c);\n");
        printf("s = ");
        gets(s);
        printf("c = ");
        gets(&c);
        s2 = strdup(s);
        c2 = c;
        printf("\nstrrchr(\"%s\", '%c') :\n", s, c);
        printf("%s\n", strrchr(s, c));
        printf("s = %s\n", s);
        printf("\nft_strrchr(\"%s\", '%c') :\n", s2, c2);
        printf("%s\n", ft_strrchr(s2, c2));
        printf("s = %s\n", s2);
        if (s2)
            free(s2);
    }
    else
#endif
#ifdef	STRSTR
    if (strcmp(str, "strstr") == 0)
    {
        char			s1[256];
        char			*s12;
        char			s2[256];
        char			*s22;

        printf("char	*strstr(const char *s1, const char *s2);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        s12 = strdup(s1);
        s22 = strdup(s2);
        printf("\nstrstr(\"%s\", \"%s\") :\n", s1, s2);
        printf("%s\n", strstr(s1, s2));
        printf("s1 = %s\n", s1);
        printf("s2 = %s\n", s2);
        printf("\nft_strstr(\"%s\", \"%s\") :\n", s12, s22);
        printf("%s\n", ft_strstr(s12, s22));
        printf("s1 = %s\n", s12);
        printf("s2 = %s\n", s22);
        if (s22)
            free(s22);
    }
    else
#endif
#ifdef	STRNSTR
    if (strcmp(str, "strnstr") == 0)
    {
        char			s1[256];
        char			*s12;
        char			s2[256];
        char			*s22;
        int				n;
        int				n2;

        printf("char	*strnstr(const char *s1, const char *s2, size_t n);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        printf("n = ");
        n = atoi(gets((char *)&n));
        s12 = strdup(s1);
        s22 = strdup(s2);
        n2 = n;
        printf("\nstrnstr(\"%s\", \"%s\", %d) :\n", s1, s2, n);
        printf("%s\n", strnstr(s1, s2, n));
        printf("s1 = %s\n", s1);
        printf("s2 = %s\n", s2);
        printf("\nft_strnstr(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
        printf("%s\n", ft_strnstr(s12, s22, n2));
        printf("s1 = %s\n", s12);
        printf("s2 = %s\n", s22);
        if (s22)
            free(s22);
    }
    else
#endif
#ifdef	STRCMP
    if (strcmp(str, "strcmp") == 0)
    {
        char			s1[256];
        char			*s12;
        char			s2[256];
        char			*s22;

        printf("int	strcmp(const char *s1, const char *s2);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        s12 = strdup(s1);
        s22 = strdup(s2);
        printf("\nstrcmp(\"%s\", \"%s\") :\n", s1, s2);
        printf("%d\n", strcmp(s1, s2));
        printf("s1 = %s\n", s1);
        printf("s2 = %s\n", s2);
        printf("\nft_strcmp(\"%s\", \"%s\") :\n", s12, s22);
        printf("%d\n", ft_strcmp(s12, s22));
        printf("s1 = %s\n", s12);
        printf("s2 = %s\n", s22);
        if (s22)
            free(s22);
    }
    else
#endif
#ifdef	STRNCMP
    if (strcmp(str, "strncmp") == 0)
    {
        char			s1[256];
        char			*s12;
        char			s2[256];
        char			*s22;
        int				n;
        int				n2;

        printf("int	strncmp(const char *s1, const char *s2, size_t n);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        printf("n = ");
        n = atoi(gets((char *)&n));
        s12 = strdup(s1);
        s22 = strdup(s2);
        n2 = n;
        printf("\nstrncmp(\"%s\", \"%s\", %d) :\n", s1, s2, n);
        printf("%d\n", strncmp(s1, s2, n));
        printf("s1 = %s\n", s1);
        printf("s2 = %s\n", s2);
        printf("\nft_strncmp(\"%s\", \"%s\", %d) :\n", s12, s22, n2);
        printf("%d\n", ft_strncmp(s12, s22, n2));
        printf("s1 = %s\n", s12);
        printf("s2 = %s\n", s22);
        if (s22)
            free(s22);
    }
    else
#endif
#ifdef	ATOI
    if (strcmp(str, "atoi") == 0)
    {
        char			s[256];
        char			*s2;

        printf("int	atoi(const char *str);\n");
        printf("s = ");
        gets(s);
        s2 = strdup(s);
        printf("\natoi(\"%s\") :\n", s);
        printf("%d\n", atoi(s));
        printf("\nft_atoi(\"%s\") :\n", s2);
        printf("%d\n", ft_atoi(s2));
    }
    else
#endif
#ifdef	ISALPHA
    if (strcmp(str, "isalpha") == 0)
    {
        char			c;
        char			c2;

        printf("int	isalpha(int c);\n");
        printf("c = ");
        gets(&c);
        c2 = c;
        printf("\nisalpha('%c') :\n", c);
        printf("%d\n", isalpha(c));
        printf("\nft_isalpha('%c') :\n", c2);
        printf("%d\n", ft_isalpha(c2));
    }
    else
#endif
#ifdef	ISDIGIT
    if (strcmp(str, "isdigit") == 0)
    {
        char		c;
        char		c2;

        printf("int	isdigit(int c);\n");
        printf("c = ");
        gets(&c);
        c2 = c;
        printf("\nisdigit('%c') :\n", c);
        printf("%d\n", isdigit(c));
        printf("\nft_isdigit('%c') :\n", c2);
        printf("%d\n", ft_isdigit(c2));
    }
    else
#endif
#ifdef	ISALNUM
    if (strcmp(str, "isalnum") == 0)
    {
        char		c;
        char		c2;

        printf("int	isalnum(int c);\n");
        printf("c = ");
        gets(&c);
        c2 = c;
        printf("\nisalnum('%c') :\n", c);
        printf("%d\n", isalnum(c));
        printf("\nft_isalnum('%c') :\n", c2);
        printf("%d\n", ft_isalnum(c2));
    }
    else
#endif
#ifdef	ISASCII
    if (strcmp(str, "isascii") == 0)
    {
        char		c;
        char		c2;

        printf("int	isascii(int c);\n");
        printf("c = ");
        gets(&c);
        c2 = c;
        printf("\nisascii('%c') :\n", c);
        printf("%d\n", isascii(c));
        printf("\nft_isascii('%c') :\n", c2);
        printf("%d\n", ft_isascii(c2));
    }
    else
#endif
#ifdef	ISPRINT
    if (strcmp(str, "isprint") == 0)
    {
        char		c;
        char		c2;

        printf("int	isprint(int c);\n");
        printf("c = ");
        gets(&c);
        c2 = c;
        printf("\nisprint('%c') :\n", c);
        printf("%d\n", isprint(c));
        printf("\nft_isprint('%c') :\n", c2);
        printf("%d\n", ft_isprint(c2));
    }
    else
#endif
#ifdef	TOUPPER
    if (strcmp(str, "toupper") == 0)
    {
        char		c;
        char		c2;

        printf("int toupper(int c);\n");
        printf("c = ");
        gets(&c);
        c2 = c;
        printf("\ntoupper('%c') :\n", c);
        printf("%c\n", (char)toupper(c));
        printf("c = %c\n", c);
        printf("\nft_toupper('%c') :\n", c2);
        printf("%c\n", (char)ft_toupper(c2));
        printf("c = %c\n", c2);
    }
    else
#endif
#ifdef	TOLOWER
    if (strcmp(str, "tolower") == 0)
    {
        char		c;
        char		c2;

        printf("int tolower(int c);\n");
        printf("c = ");
        gets(&c);
        c2 = c;
        printf("\ntolower('%c') :\n", c);
        printf("%c\n", (char)tolower(c));
        printf("c = %c\n", c);
        printf("\nft_tolower('%c') :\n", c2);
        printf("%c\n", (char)ft_tolower(c2));
        printf("c = %c\n", c2);
    }
    else
#endif
#ifdef	MEMALLOC
    if (strcmp(str, "memalloc") == 0)
    {
        char	*ptr;
        int		size;
        int		i;

        printf("void	*ft_memalloc(size_t size);\n");
        printf("size = ");
        size = atoi(gets((char *)&size));
        printf("\nft_memalloc(%d) :\n", size);
        ptr = (char *)ft_memalloc(size);
        i = 0;
        if (ptr)
            while (i < size)
            {
                printf("ptr[%d] = '%c'\n", i, ptr[i]);
                i++;
            }
        else
            printf("%s\n", ptr);
        if (ptr)
            free(ptr);
    }
    else
#endif
#ifdef	MEMDEL
    if (strcmp(str, "memdel") == 0)
    {
        char	*ptr;

        ptr = malloc(sizeof(char) * 256);
        printf("void	ft_memdel(void	**ap);\n");
        printf("*ap = ");
        gets(ptr);
        printf("\nft_memdel(&ptr) :\n");
        ft_memdel((void **)&ptr);
        printf("*ap = %s\n", ptr);
    }
    else
#endif
#ifdef	STRNEW
    if (strcmp(str, "strnew") == 0)
    {
        char	*str;
        int		size;
        int		i;

        printf("char	*ft_strnew(size_t size);\n");
        printf("size = ");
        size = atoi(gets((char *)&size));
        printf("\nft_strnew(%d) :\n", size);
        str = ft_strnew(size);
        i = 0;
        if (str)
            while (i < size + 1)
            {
                printf("str[%d] = '%c'\n", i, str[i]);
                i++;
            }
        else
            printf("%s\n", str);
        if (str)
            free(str);
    }
    else
#endif
#ifdef	STRDEL
    if (strcmp(str, "strdel") == 0)
    {
        char	*str;

        str = malloc(sizeof(char) * 256);
        printf("void	ft_strdel(void	**as);\n");
        printf("str = ");
        gets(str);
        printf("\nft_strdel(&str) :\n");
        ft_memdel((void **)&str);
        printf("str = %s\n", str);
    }
    else
#endif
#ifdef	STRCLR
    if (strcmp(str, "strclr") == 0)
    {
        char	str[256];
        int		len;
        int		i;

        printf("void	ft_strclr(char *s);\n");
        printf("str = ");
        gets(str);
        printf("\nft_strclr(\"%s\") :\n", str);
        len = strlen(str);
        ft_strclr(str);
        i = 0;
        while (i < len)
        {
            printf("str[%d] = '%c'\n", i, str[i]);
            i++;
        }
    }
    else
#endif
#ifdef	STRITER
    if (strcmp(str, "striter") == 0)
    {
        char	s[256];

        printf("void	ft_striter(char *s, void (*f)(char *));\n");
        printf("s = ");
        gets(s);
        printf("*f = printf\n");
        printf("\nft_striter(\"%s\", (void *)printf) :\n", s);
        ft_striter(s, (void *)printf);
        putchar('\n');
    }
    else
#endif
#ifdef	STRITERI
    if (strcmp(str, "striteri") == 0)
    {
        char			s[256];

        printf("void	ft_striteri(char *s, void (*f)(unsigned intchar *));\n");
        printf("s = ");
        gets(s);
        printf("*f = striteri_printf\n");
        printf("\nft_striteri(\"%s\", (void *)striteri_printf) :\n", s);
        ft_striteri(s, (void *)striteri_printf);
    }
    else
#endif
#ifdef	STRMAP
    if (strcmp(str, "strmap") == 0)
    {
        char	s[256];
        char	*smap;

        printf("char	*ft_strmap(char const *s, char (*f)(char));\n");
        printf("*f = tolower\n");
        printf("s = ");
        gets(s);
        printf("\nft_strmap(\"%s\", (char (*)(char))tolower) :\n", s);
        smap = ft_strmap(s, (char (*)(char))tolower);
        printf("%s\n", smap);
        if (smap)
            free(smap);
    }
    else
#endif
#ifdef	STRMAPI
    if (strcmp(str, "strmapi") == 0)
    {
        char	s[256];
        char	*smap;

        printf("char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));\n");
        printf("*f = strmapi_tolower\n");
        printf("s = ");
        gets(s);
        printf("\nft_strmapi(\"%s\", strmapi_tolower) :\n", s);
        strmapi_tolower(1, (int)s[1]);
        smap = ft_strmapi(s, (char (*)(unsigned int, char))strmapi_tolower);
        printf("%s\n", smap);
        if (smap)
            free(smap);
    }
    else
#endif
#ifdef	STREQU
    if (strcmp(str, "strequ") == 0)
    {
        char	s1[256];
        char	s2[256];

        printf("int	ft_strequ(char const *s1, char const *s2);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        printf("\nft_strequ(\"%s\", \"%s\") :\n", s1, s2);
        printf("%d\n", ft_strequ(s1, s2));
    }
    else
#endif
#ifdef	STRNEQU
    if (strcmp(str, "strnequ") == 0)
    {
        char	s1[256];
        char	s2[256];
        int		n;

        printf("int	ft_strnequ(char const *s1, char const *s2, size_t n);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        printf("n = ");
        n = atoi(gets((char *)&n));
        printf("\nft_strnequ(\"%s\", \"%s\", %d) :\n", s1, s2, n);
        printf("%d\n", ft_strnequ(s1, s2, n));
    }
    else
#endif
#ifdef	STRSUB
    if (strcmp(str, "strsub") == 0)
    {
        char			s[256];
        unsigned int	start;
        unsigned int	len;
        char			*ssub;

        printf("char	*ft_strsub(char const *s, unsigned int start, size_t len);\n");
        printf("s = ");
        gets(s);
        printf("start = ");
        start = atoi(gets((char *)&start));
        printf("len = ");
        len = atoi(gets((char *)&len));
        printf("\nft_strsub(\"%s\", %d, %d) :\n", s, start, len);
        ssub = ft_strsub(s, start, len);
        printf("%s\n", ssub);
        if (ssub)
            free(ssub);
    }
    else
#endif
#ifdef	STRJOIN
    if (strcmp(str, "strjoin") == 0)
    {
        char	s1[256];
        char	s2[256];
        char	*sjoin;

        printf("char	*ft_strjoin(char const *s1, char const *s2);\n");
        printf("s1 = ");
        gets(s1);
        printf("s2 = ");
        gets(s2);
        printf("\nft_strjoin(\"%s\", \"%s\") :\n", s1, s2);
        sjoin = ft_strjoin(s1, s2);
        printf("%s\n", sjoin);
        if (sjoin)
            free(sjoin);
    }
    else
#endif
#ifdef	STRTRIM
    if (strcmp(str, "strtrim") == 0)
    {
        char	s[256];
        char	*strim;

        printf("char	*ft_strtrim(char const *s);\n");
        printf("s = ");
        gets(s);
        printf("\nft_strtrim(\"%s\") :\n", s);
        strim = ft_strtrim(s);
        printf("%s", strim);
        if (strim)
            free(strim);
    }
    else
#endif
#ifdef	STRSPLIT
    if (strcmp(str, "strsplit") == 0)
    {
        char	s[256];
        char	**tab;
        char	c;
        int	i;

        printf("char	**ft_strsplit(char const *s, char c);\n");
        printf("s = ");
        gets(s);
        printf("c = ");
        gets(&c);
        printf("\nft_strsplit(\"%s\", '%c') :\n", s, c);
        tab = ft_strsplit(s, c);
        i = 0;
        while (tab[i])
        {
        printf("tab[%d] = %s\n", i, tab[i]);
        i++;
        }
        i = 0;
        while (tab[i])
        free(tab[i++]);
        if (tab)
        free(tab);
    }
    else
#endif
#ifdef	ITOA
    if (strcmp(str, "itoa") == 0)
    {
        int	n;
        char	*s;

        printf("char	*ft_itoa(int n);\n");
        printf("n = ");
        n = atoi(gets((char *)&n));
        printf("\nft_itoa(%d) :\n", n);
        s = ft_itoa(n);
        printf("%s\n", s);
    }
    else
#endif
#ifdef	PUTCHAR
    if (strcmp(str, "putchar") == 0)
    {
        char	c;

        printf("void	ft_putchar(char c);\n");
        printf("c = ");
        gets(&c);
        printf("\nft_putchar('%c') :\n", c);
        ft_putchar(c);
        printf("\n");
    }
    else
#endif
#ifdef	PUTSTR
    if (strcmp(str, "putstr") == 0)
    {
        char	s[256];

        printf("void	ft_putstr(char const *s);\n");
        printf("s = ");
        gets(s);
        printf("\nft_putstr(\"%s\") :\n", s);
        ft_putstr(s);
        printf("\n");
    }
    else
#endif
#ifdef	PUTENDL
    if (strcmp(str, "putendl") == 0)
    {
        char	s[256];

        printf("void	ft_putendl(char const *s);\n");
        printf("s = ");
        gets(s);
        printf("\nft_putendl(\"%s\") :\n", s);
        ft_putendl(s);
        printf("\n");
    }
    else
#endif
#ifdef	PUTNBR
    if (strcmp(str, "putnbr") == 0)
    {
        int		n;

        printf("void	ft_putnbr(int n);\n");
        printf("n = ");
        n = atoi(gets((char *)&n));
        printf("\nft_putnbr(%d) :\n", n);
        ft_putnbr(n);
        printf("\n");
    }
    else
#endif
#ifdef	PUTCHAR_FD
    if (strcmp(str, "putchar_fd") == 0)
    {
        char	c;

        printf("void	ft_putchar_fd(char c, int fd);\n");
        printf("c = ");
        gets(&c);
        printf("fd = 1\n");
        printf("\nft_putchar_fd('%c', 1) :\n", c);
        ft_putchar_fd(c, 1);
        printf("\n");
    }
    else
#endif
#ifdef	PUTSTR_FD
    if (strcmp(str, "putstr_fd") == 0)
    {
        char	s[256];

        printf("void	ft_putstr_fd(char const *s, int fd);\n");
        printf("s = ");
        gets(s);
        printf("fd = 1\n");
        printf("\nft_putstr_fd(\"%s\", 1) :\n", s);
        ft_putstr_fd(s, 1);
        printf("\n");
    }
    else
#endif
#ifdef	PUTENDL_FD
    if (strcmp(str, "putendl_fd") == 0)
    {
        char	s[256];

        printf("void	ft_putendl_fd(char const *s, int fd);\n");
        printf("s = ");
        gets(s);
        printf("fd = 1\n");
        printf("\nft_putendl_fd(\"%s\", 1) :\n", s);
        ft_putendl_fd(s, 1);
        printf("\n");
    }
    else
#endif
#ifdef	PUTNBR_FD
    if (strcmp(str, "putnbr_fd") == 0)
    {
        int		n;

        printf("void	ft_putnbr_fd(int n, int fd);\n");
        printf("n = ");
        n = atoi(gets((char *)&n));
        printf("fd = 1\n");
        printf("\nft_putnbr_fd(%d, 1) :\n", n);
        ft_putnbr_fd(n, 1);
        printf("\n");
    }
    else
#endif
        printf("This function does not exist.\n");
    main();
    return (0);
}
