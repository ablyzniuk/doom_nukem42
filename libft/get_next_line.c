/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:10:36 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/13 17:22:51 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strndup(const char *src, size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char*)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int			ft_copy(char **line, t_list *tmp)
{
	char	*str;
	size_t	len;
	size_t	size;
	char	*del;

	size = 0;
	str = (char*)tmp->content;
	len = ft_strlen(str);
	del = *line;
	while (str[size] != '\n' && str[size] != '\0')
		size++;
	if (len > 0)
		*line = ft_strndup(str, size);
	if (str[size] != '\0')
		tmp->content = ft_strjoin("", str + (size + 1));
	else
		tmp->content = ft_strjoin("", str + size);
	if (str != NULL)
		free(str);
	if (len > 0)
		return (1);
	return (0);
	free(del);
}

t_list		*ft_getlst(t_list **list, int fd)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(list, tmp);
	return (tmp);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static t_list	*list;
	char			*tmp_del;
	t_list			*tmp;

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	tmp = ft_getlst(&list, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp_del = tmp->content;
		if (!(tmp->content = ft_strjoin(tmp_del, buf)))
			return (-1);
		if (tmp_del != NULL)
			free(tmp_del);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ft_copy(line, tmp))
		return (1);
	return (0);
}
