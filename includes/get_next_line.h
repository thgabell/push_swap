/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:47:58 by thgabell          #+#    #+#             */
/*   Updated: 2022/09/13 17:48:00 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_text(int fd, char *statiq);
char	*extract_line(char *statiq);
char	*next_line(char *statiq);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *statiq, char *buf);
char	*ft_strchr(const char *s, int c);

#endif
