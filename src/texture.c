/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:54:54 by mich              #+#    #+#             */
/*   Updated: 2023/05/18 15:45:10 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void	malloc_img(t_game *game)
{
	game->count.i = -1;
	game->mlx.text = (int **)malloc(sizeof(int *) * 3);
	if (!game->mlx.text)
		exit_game(game, 1, "error during allocation\n");
	while (++game->count.i < 3)
	{
		printf("culo\n");
		game->mlx.text[game->count.i] = (int *)malloc(sizeof(int)
				* (TEXT_SIZE * TEXT_SIZE));
		if (!game->mlx.text[game->count.i])
			exit_game(game, 1, "error during allocation\n");
	}
	game->count.i = -1;
	while (++game->count.i < 3)
	{
		game->count.j = -1;
		while (++game->count.j < TEXT_SIZE * TEXT_SIZE)
			game->mlx.text[game->count.i][game->count.j] = 0;
	}
}

void	open_img(t_game *game, int *n_text, char *path)
{
	game->img.image = mlx_xpm_file_to_image(game->mlx.mlx, path,
			&game->img.img_w, &game->img.img_h);
	if (!game->img.image)
		exit_game(game, 1, "Texture not found\n");
	game->img.data = (int *)mlx_get_data_addr(game->img.image, &game->img.pos,
			&game->img.line_size, &game->img.end);
	game->count.i = -1;
	while (++game->count.i < game->img.img_h)
	{
		game->count.j = -1;
		while (++game->count.j < game->img.img_w)
		{
			n_text[game->img.img_w * game->count.i + game->count.j]
				= game->img.data[game->img.img_w
				* game->count.i + game->count.j];
		}
	}
	mlx_destroy_image(game->mlx.mlx, game->img.image);
}

void	make_img(t_game *game)
{
	open_img(game, game->mlx.text[0], "sprites/xpm/door.xpm");
	open_img(game, game->mlx.text[1], "sprites/xpm/slime_2.xpm");
	open_img(game, game->mlx.text[2], "sprites/xpm/slime.xpm");
}

void	put_txt(t_game *game)
{
	malloc_img(game);
	make_img(game);
}
