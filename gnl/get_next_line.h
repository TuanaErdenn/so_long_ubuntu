/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terden <terden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:15:46 by terden            #+#    #+#             */
/*   Updated: 2025/04/08 13:17:42 by terden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include "../libft/libft.h"
# include <stdlib.h>

int		check_nl(char *str);
void	*ft_free(void *ptr);
int		ft_strlen2(char *str);
char	*ft_strjoin2(char *s1, char *s2);

char	*read_file(int fd, char *str);
char	*before_nl(char *str);
char	*after_nl(char *str);
char	*get_next_line(int fd);

#endif