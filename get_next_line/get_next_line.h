/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:34:55 by sbart             #+#    #+#             */
/*   Updated: 2021/12/21 13:35:32 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_rewrite_line(char *line);
char	*ft_enter_line(char *line);
char	*ft_strdup_line(char *line);
int		ft_strlen(const char *str);
int		ft_check_line_feed(char *line);
char	*ft_strjoin(char *s1, char *s2);

#endif