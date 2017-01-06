/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wide_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 17:30:25 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/24 17:30:26 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static unsigned int		wchar_converter(wchar_t wchar,
						unsigned char **result, unsigned int length)
{
	if (!(*result = (unsigned char*)malloc(sizeof(char) * 5)))
		return (0);
	if (wchar < (1 << 7) && (length += 1))
		**result = (unsigned char)(wchar);
	else if (wchar < (1 << 11) && (length += 2))
	{
		**result = (unsigned char)((wchar >> 6) | 0xC0);
		*(*result + 1) = (unsigned char)((wchar & 0x3F) | 0x80);
	}
	else if (wchar < (1 << 16) && (length += 3))
	{
		**result = (unsigned char)(((wchar >> 12)) | 0xE0);
		*(*result + 1) = (unsigned char)(((wchar >> 6) & 0x3F) | 0x80);
		*(*result + 2) = (unsigned char)((wchar & 0x3F) | 0x80);
	}
	else if (wchar < (1 << 21) && (length += 4))
	{
		**result = (unsigned char)(((wchar >> 18)) | 0xF0);
		*(*result + 1) = (unsigned char)(((wchar >> 12) & 0x3F) | 0x80);
		*(*result + 2) = (unsigned char)(((wchar >> 6) & 0x3F) | 0x80);
		*(*result + 3) = (unsigned char)((wchar & 0x3F) | 0x80);
	}
	if (length > 0)
		*(*result + length) = '\0';
	return (length);
}

static unsigned char	*ft_wchar_strjoin_and_free(
						unsigned char *str1, unsigned char *str2,
						unsigned int length, unsigned int len)
{
	unsigned char		*new_result;
	unsigned char		*copy_result;
	unsigned char		*copy_str1;
	unsigned char		*copy_str2;

	copy_str1 = str1;
	copy_str2 = str2;
	new_result = (unsigned char*)malloc(sizeof(char) * (length + len) + 1);
	copy_result = new_result;
	if (!new_result)
		return (NULL);
	while (length > 0)
	{
		*copy_result++ = *copy_str1++;
		length--;
	}
	while (len > 0)
	{
		*copy_result++ = *copy_str2++;
		len--;
	}
	*copy_result = '\0';
	free(str1);
	free(str2);
	return (new_result);
}

unsigned char			*wchar_str(wchar_t *str, unsigned int *count)
{
	unsigned char		*result;
	unsigned char		*temp;
	unsigned int		word_len;

	word_len = 0;
	*count = 0;
	result = NULL;
	while (*str)
	{
		word_len = wchar_converter(*str, &temp, 0);
		if (word_len > 0)
			result = ft_wchar_strjoin_and_free(result, temp, *count, word_len);
		*count += word_len;
		str++;
	}
	return (result);
}

unsigned char			*wchar_chr(wchar_t chr, unsigned int *length)
{
	unsigned char		*result;

	result = NULL;
	*length = wchar_converter(chr, &result, 0);
	return (result);
}

void					ft_putwstr(unsigned char *str)
{
	if (str)
	{
		while (*str != '\0')
		{
			write(1, str, 1);
			str++;
		}
	}
}
