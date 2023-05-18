/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:54:24 by mich              #+#    #+#             */
/*   Updated: 2023/05/18 11:25:32 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast_sprite.h"

void	camera_count(t_game *game,
			t_maths *m_sprite, int *sprite_order)
{
	m_sprite->sprite_x = game->sprt[sprite_order[m_sprite->i]]->x
		- game->plyr.pos_x;
	m_sprite->sprite_y = game->sprt[sprite_order[m_sprite->i]]->y
		- game->plyr.pos_y;
	m_sprite->inv_det = 1.0 / (game->plyr.plane_x * game->plyr.dir_y
			- game->plyr.dir_x * game->plyr.plane_y);
	m_sprite->transform_x = m_sprite->inv_det * (game->plyr.dir_y
			* m_sprite->sprite_x - game->plyr.dir_x * m_sprite->sprite_y);
	m_sprite->transform_y = m_sprite->inv_det * (-game->plyr.plane_y
			* m_sprite->sprite_x + game->plyr.plane_x * m_sprite->sprite_y);
	m_sprite->sprite_screen_x = (int)((WIDTH / 2)
			* (1 + m_sprite->transform_x / m_sprite->transform_y));
	m_sprite->v_move_screen = (int)(MOVE / m_sprite->transform_y);
}

void	draw_sprite(t_maths *m_sprite)
{
	m_sprite->sprite_h = (int)fabs((HEIGHT / m_sprite->transform_y) / DIV_1);
	m_sprite->draw_start_y = -m_sprite->sprite_h / 2
		+ HEIGHT / 2 + m_sprite->v_move_screen;
	if (m_sprite->draw_start_y < 0)
		m_sprite->draw_start_y = 0;
	m_sprite->draw_end_y = m_sprite->sprite_h / 2
		+ HEIGHT / 2 + m_sprite->v_move_screen;
	if (m_sprite->draw_end_y >= HEIGHT)
		m_sprite->draw_end_y = HEIGHT - 1;
	m_sprite->sprite_width = (int)fabs((HEIGHT / m_sprite->transform_y)
			/ DIV_2);
	m_sprite->draw_start_x = -m_sprite->sprite_width / 2
		+ m_sprite->sprite_screen_x;
	if (m_sprite->draw_start_x < 0)
		m_sprite->draw_start_x = 0;
	m_sprite->draw_end_x = m_sprite->sprite_width / 2
		+ m_sprite->sprite_screen_x;
	if (m_sprite->draw_end_x >= WIDTH)
		m_sprite->draw_end_x = WIDTH - 1;
}

void	print(t_game *game, t_maths *m_sprite,
				int *sprite_order)
{
	m_sprite->d = (m_sprite->y - m_sprite->v_move_screen) * 256 - HEIGHT
		* 128 + m_sprite->sprite_h * 128;
	m_sprite->tex_y = ((m_sprite->d * TEXT_SIZE)
			/ m_sprite->sprite_h) / 256;
	m_sprite->color = game->mlx.text[game->sprt[sprite_order
	[m_sprite->i]]->txt_n]
	[TEXT_SIZE * m_sprite->tex_y + m_sprite->tex_x];
	if ((m_sprite->color & 0x00FFFFFF) != 0)
	game->mlx.buff[m_sprite->y][m_sprite->stripe] = m_sprite->color;
}

void	loop(t_game *game, t_maths *m_sprite,
			int	*sprite_order)
{
	camera_count(game, m_sprite, sprite_order);
	draw_sprite(m_sprite);
	m_sprite->stripe = m_sprite->draw_start_x;
	while (m_sprite->stripe < m_sprite->draw_end_x)
	{
		m_sprite->tex_x = (int)((256 * (m_sprite->stripe
						- (-m_sprite->sprite_width
							/ 2 + m_sprite->sprite_screen_x))
					* TEXT_SIZE / m_sprite->sprite_width) / 256);
		if (m_sprite->transform_y > 0 && m_sprite->stripe > 0
			&& m_sprite->stripe < WIDTH
			&& m_sprite->transform_y < game->mlx.z_buff[m_sprite->stripe])
		{
			m_sprite->y = m_sprite->draw_start_y;
			while (m_sprite->y < m_sprite->draw_end_y)
			{
				print(game, m_sprite, sprite_order);
				m_sprite->y++;
			}
		}
		m_sprite->stripe++;
	}
}

void	sprites_cast(t_game *game)
{
	int		*sprite_order;
	double	*sprite_dist;
	t_maths	m_sprite;

	ft_bzero(&m_sprite, sizeof(t_maths));
	sprite_order = (int *)malloc(sizeof(int) * game->b_sprite.sprites_n);
	sprite_dist = (double *)malloc(sizeof(double) * game->b_sprite.sprites_n);
	sort_close(game, sprite_order, sprite_dist);
	sort_sprites(sprite_order, sprite_dist, game->b_sprite.sprites_n);
	m_sprite.i = 0;
	while (m_sprite.i < game->b_sprite.sprites_n)
	{
		loop(game, &m_sprite, sprite_order);
		m_sprite.i++;
	}
	free(sprite_order);
	free(sprite_dist);
}
