/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:25:47 by obult         #+#    #+#                 */
/*   Updated: 2022/10/09 17:42:58 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "quartz.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

int	round_down(float z)
{
	float	trash;

	return ((int)modff(z, &trash));
}

/*
 *  This function calls the distance towards the cell border over an axis.
 *	The angle is needed to return a negative number for back- and downwards.
 */
float	calc_distance_y(float z, float angle)
{
	float	tmp;
	float	trash;

	tmp = modff(z, &trash);
	if (angle > 0.5 * PI && angle < 1.5 * PI)
	{
		if (!tmp)
			return (-1);
		return (-1 * tmp);
	}
	return (1 - tmp);
}

/*
 *	This Function calculates the distance untill a ray with an angle against the north
 *	has reached an obstacle perpendicular with the x axis.
 */
float	max_x_dist(t_data data, float angle, float x, float y)
{
	float	x_dist;
	float	y_dist;
	float	result;

	usleep(200);
	y_dist = calc_distance_y(y, angle);
	x_dist = tanf(angle) * y_dist;
	if (round_down(x_dist + x) > data.x_max || round_down(x_dist + x) < 0)
		return (ERROR);
	if (round_down(y_dist + y) > data.y_max || round_down(y_dist + y) < 0)
		return (ERROR);
	// if (angle < 0.5 * PI || angle > 1.5 * PI)
		if (data.map[round_down(y + y_dist)][round_down(x + x_dist)] != '0')
			return (x_dist);
	// if (round_down(y_dist + y) < 1)
	// 	return (ERROR);
	// if (data.map[round_down(y + y_dist) - 1][round_down(x + x_dist)] != '0')
	// 	return (x_dist);
	result = max_x_dist(data, angle, x + x_dist, y + y_dist);
	if (result == ERROR)
		return (ERROR);
	return (result + x_dist);
}


float	calc_distance_x(float z, float angle)
{
	float	tmp;
	float	trash;

	tmp = modff(z, &trash);
	if (angle > 0 && angle < PI)
		return (1 - tmp);
	if (!tmp)
		return (-1);
	return (tmp * -1);
}

/*
 *	This Function calculates the distance untill a ray with an angle against the north
 *	has reached an obstacle perpendicular with the y axis.
 */
float	max_y_dist(t_data data, float angle, float x, float y)
{
	float	y_dist;
	float	x_dist;
	float	result;
	float	anglePI;

	usleep(200);
	anglePI = angle - (PI * 0.5);
	x_dist = calc_distance_x(x, angle);
	y_dist = tanf(anglePI) * x_dist;
	if (round_down(y_dist + y) > data.y_max || round_down(y_dist + y) < 0)
		return (ERROR);
	if (round_down(x_dist + x) > data.x_max || round_down(x_dist + x) < 0)
		return (ERROR);
	// if (angle > 0 && angle < PI)
		if (data.map[round_down(y + y_dist)][round_down(x + x_dist)] != '0')
			return (y_dist);
	// if (round_down(x_dist + x) < 1)
	// 	return (ERROR);
	// if (data.map[round_down(y + y_dist)][round_down(x + x_dist) - 1] != '0')
	// 	return (y_dist);
	result = max_y_dist(data, angle, x + x_dist, y + y_dist);
	if (result == ERROR)
		return (ERROR);
	return (result + y_dist);
}

float	positivef(float f)
{
	if (f < 0)
		return (f * -1);
	return (f);
}

float	max_dist(t_data *data, float angle)
{
	float	x_total;
	float	y_total;

	x_total = max_x_dist(*data, angle, data->player.x, data->player.y);
	y_total = max_y_dist(*data, angle, data->player.x, data->player.y);
	if (x_total == ERROR && y_total == ERROR)
		return (ERROR);
	if (positivef(x_total) < positivef(y_total))
	{
		data->sign = 'x';
		return (x_total / sinf(angle));
	}
	data->sign = 'y';
	return (y_total / sinf(angle - (PI * 0.5)));
}

/*
 *	This thing is here to test the functions.
 */
void	test_max_dist_calc(char ** map)
{
	t_data data;
	data.map = map;
	data.x_max = 3;
	data.y_max = 3;
	data.sign = 'o';

	data.player.x = 2;
	data.player.y = 2;
	for (int i = 0; i < 18 * 4; i++)
	{
		if (i % 18 == 0)
			printf("========\n");
		printf("max dist (px, py) %i : %f", i, max_dist(&data, PI / 36 * i));
		printf(", s=%c\n", data.sign);
	}
}

void	test_max_dist_calc_float(char ** map)
{
	t_data data;
	data.map = map;
	data.x_max = 3;
	data.y_max = 3;
	data.sign = 'o';

	data.player.x = 2.5;
	data.player.y = 2.5;
	for (int i = 0; i < 18 * 4; i++)
	{
		if (i % 18 == 0)
			printf("========\n");
		printf("max dist (px, py) %i : %f", i, max_dist(&data, PI / 36 * i));
		printf(", s=%c\n", data.sign);
	}
}

int	main(void)
{
	test_max_dist_calc((char *[]){"1111", "1001", "1001", "1111"});
	test_max_dist_calc_float((char *[]){"1111", "1001", "1001", "1111"});
	return (0);
}
