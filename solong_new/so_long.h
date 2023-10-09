/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:56:00 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/16 09:13:32 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFFER_SIZE 10

# define ESC_KEY 53

# define UP_KEY 13
# define UP_KEY2 126
# define DOWN_KEY 1
# define DOWN_KEY2 125
# define RIGHT_KEY 2
# define RIGHT_KEY2 124
# define LEFT_KEY 0
# define LEFT_KEY2 123

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}t_data;

typedef struct s_vars
{
	t_data			*dt;
	int				*minlx;
	int				*minlx_window;
	char			**strmap;
	char			**active_strmap;
	int				chr;
	int				moves_display;
	int				x;
	int				y;
	int				plyr_x;
	int				plyr_y;
	void			*cl;
	void			*ext;
	void			*plr;
	void			*wall;
	void			*bckg;
	int				c;
	int				pl;
	int				ex;
}t_vars;

char	*free_str_mem(char **to_free_str);
char	*ft_strjoin(char const *st1, char const *st2);
char	*ft_strchr(const char *str, int find_chr);
void	*ft_calloc(size_t block_size, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_concat_free(char *buf1, char *buf2);
char	*extract_previous_line(char *buffer);
char	*read_one_line_first(char *buffer);
char	*read_file(int fd, char *buff_res);
char	*get_next_line(int fd);

void	*ft_calloc(size_t n_blocks, size_t size_block);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *str, unsigned int index, size_t sub_max);

int		check_player(t_vars *mp);
int		check_collectible(t_vars *mp);
int		check_exit(t_vars *mp);
char	**get_map(int f, t_vars *mp);
int		full_check(t_vars *mp);
int		exit_game(t_vars *mp);
void	locate_player(t_vars *mp);
void	game_display_msg(void);
void	up_move(t_vars *mp);
void	right_move(t_vars *mp);
void	down_move(t_vars *mp);
void	left_move(t_vars *mp);
void	messg1(void);
void	messg2(void);
int		check_if_perfect(char **mp);
void	convert_xpm(t_vars *mp);
void	convert_img_to_window(t_vars *mp);
int		ft_height(char **mp);
int		ft_width(char **mp);
int		check_keys(int key_num, t_vars *mp);
void	free_two_maps(char **map, t_vars *mp);
int		solvable_map(char **map);
int		check_background(char **map);
void	place_p_instead(char **map);
int		is_there_exit(char **map);
int		check_all_cltb(char **map);
int		check_if_big(char **mp);
int		check_walls(char **mp);
int		exit_game(t_vars *mp);
void	game_display_msg(void);
void	print_err(char *s, char **dim_str, t_vars *mp);
int		check_enter_in_map(char *s, char **map);
void	start_game(t_vars *mp);
int		check_ext(char *s);

#endif