/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:53:21 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/16 08:57:10 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ext(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len > 4 && (s[len - 1] == 'r' && s[len - 2] == 'e' && s[len - 3] == 'b' 
			&& s[len - 4] == '.'))
		return (EXIT_SUCCESS);
	return (write(2, "ERROR\nWrong extension\n", 23), EXIT_FAILURE);
}

void	start_game(t_vars *mp)
{
	int	x;
	int	y;

	x = ft_strlen(mp->strmap[0]) * 32;
	y = ft_height(mp->strmap) * 32;
	mp->moves_display = 0;
	mp->minlx = mlx_init();
	mp->minlx_window = mlx_new_window(mp->minlx, x, y, "so_long");
	convert_xpm(mp);
	convert_img_to_window(mp);
	mlx_hook(mp->minlx_window, 2, 0, check_keys, mp);
	mlx_hook(mp->minlx_window, 17, 0, exit_game, mp);
	mlx_loop(mp->minlx);
}

void	free_two_maps(char **map, t_vars *mp)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	i = 0;
	while (mp->active_strmap[i])
	{
		free(mp->active_strmap[i]);
		i++;
	}
	free(mp->active_strmap);
	free(mp);
}

int	main(int ac, char **av)
{
	t_vars	*mp;
	t_data	dt;
	int		f;

	if (ac != 2)
		return (write(2, "ERROR\nCheck your argument!\n", 28), EXIT_FAILURE);
	mp = malloc(sizeof(t_vars));
	if (mp == NULL)
		return (EXIT_SUCCESS);
	mp->dt = &dt;
	if (check_ext(av[1]) == EXIT_FAILURE)
		return (exit(1), EXIT_SUCCESS);
	f = open(av[1], O_RDONLY);
	if (f == -1)
	{
		exit(write(2, "ERROR\nproblem in file descriptor!\n", 35));
		return (EXIT_SUCCESS);
	}
	mp->strmap = get_map(f, mp);
	if (full_check(mp) == 0
		&& check_if_perfect(mp->strmap) == 0 
		&& solvable_map(mp->active_strmap) == 1)
		start_game(mp);
	free_two_maps(mp->strmap, mp);
	close(f);
}
