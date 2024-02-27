#ifndef     UTILS_H
# define    UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gnl/get_next_line.h"

char  *get_next_word(char **str, char separator);
char	**ft_split(char *s, char c);
void	free_2d_array(char **array);
void	print_2d_array(char **array);
char	*ft_substr(char *s, int start, int len);

#endif