/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:27:44 by ali               #+#    #+#             */
/*   Updated: 2020/09/27 14:21:39 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_dico
{
	char	*number;
	char	*string;
}				t_dico;

int				ft_stock_file(int fd, int size, char **raw);
t_dico			*ft_make_dico(char *raw, int lines);
int				ft_filelen(int fd);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
int				ft_count_lines(char *raw);
int				ft_numlen(char *raw);
char			*ft_pass_middle(char *raw);
int				ft_stringlen(char *raw);
t_dico			*ft_format_dico(int ac, char **av);
int				ft_open_dico(int ac, char **av);
void			ft_putstr(char *str);
int				ft_error(int ac, char **av);
int				ft_search_unity(char c, t_dico *dico);
int				ft_search_illion(int size, t_dico *dico);
int				ft_search_ten(char c0, char c1, t_dico *dico);
int				ft_search_hundred(t_dico *dico);
void			ft_fill_tab(char *nb, int size, char **tab, t_dico *dico);
char			*ft_fill_unity(char c, t_dico *dico);
char			*ft_fill_illion(int size, t_dico *dico);
char			*ft_fill_ten(char c0, char c1, t_dico *dico);
char			*ft_fill_hundred(t_dico *dico);
void			ft_display(char **tab);
char			*set_number(char *src);
char			*skip_to_number(char *str);
char			*ft_strdup(char *str);
int				ft_strlen(char *str);
int				ft_strcmp(char *str1, char *str2);
void			ft_units(char *nb, int *count, int index);
void			ft_dozens(char *nb, int *count, int index);
void			ft_hundreds(char *nb, int *count, int index);
int				ft_get_sizeof_malloc(char *nb, int size);
int				ft_strlen(char *str);
int				ft_check_empty_strings_tab(int size, char **tab);
void			ft_freeall(char **tab, t_dico *dico, char *nb);
int				ft_check_double(t_dico *dico);

#endif
