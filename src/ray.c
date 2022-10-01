/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:25:47 by obult         #+#    #+#                 */
/*   Updated: 2022/10/01 23:04:13 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>
#include <stdio.h>

/*
 *  this will shoot a ray and return the len in horizontal or vertical
 */

// double	shoot_ray_h(t_data data, double angle, double x, double y)
// {
// 	double	x_progress;
// 	double	y_distance;

// 	y_distance = modf(y, NULL);
// 	if (y_distance == 0)
// 		y_distance = 1;
// 	x_progress = sin(angle) * y_distance;
// 	if (data.map[(int)round(y + y_distance)][(int)round(x + x_progress)] != '0')
// 		return (x_progress / cos(angle));
// 	return (x_progress / cos(angle) + shoot_ray_h(data, angle, x + x_progress, y + y_distance));
// }

double	calc_distance(double z, double angle)
{
	double	tmp;
	double	trash;

	tmp = modf(z, &trash);
	if (angle < 0.5 * PI || angle > 1.5 * PI)
	{
		if (!tmp)
			return (1);
		return (1 - tmp);
	}
	if (!tmp)
		return (-1);
	return (-1 * tmp);
}

// double	shoot_ray_h2(t_data data, double angle, double x, double y)
// {
// 	double	distance;
// 	double	y_diff;

// 	y_diff = calc_distance(y);

// 	distance = y_diff / cos(angle);
// 	// return (0);
// }

double	max_x_dist(t_data data, double angle, double x, double y)
{
	double	x_dist;
	double	y_dist;
	double	result;

	y_dist = calc_distance(y, angle);
	x_dist = tan(angle) * y_dist;
	if ((int)round(x_dist + x) > data.x_max || (int)round(x_dist + x) < 1)
		return (ERROR);
	if (angle < 0.5 * PI || angle > 1.5 * PI)
		if (data.map[(int)round(y + y_dist)][(int)round(x + x_dist)] != '0')
			return (x_dist);
	if (data.map[(int)round(y + y_dist) - 1][(int)round(x + x_dist) - 1] != '0')
		return (x_dist);
	result = max_x_dist(data, angle, x + x_dist, y + y_dist);
	if (result == ERROR)
		return (ERROR);
	return (result + x_dist);
}

int	main(void)
{
	char *map[4];
	t_data data;
	char	a[] = "1111";
	char	b[] = "1001";
	data.map = map;
	map[0] = a;
	map[1] = b;
	map[2] = b;
	map[3] = a;
	data.x_max = 3;


	printf("next should be 1.1547005\n");
	printf("calc : %f\n", max_x_dist(data, PI / 6, 1, 1));

	printf("next should be 0.577350\n");
	printf("calc : %f\n", max_x_dist(data, PI / 6, 2, 2));

	printf("next should be -0.577350\n");
	printf("calc : %f\n", max_x_dist(data, PI / 6 * 7, 2, 2));
	printf("this is incorrect because it now runs twice as far, not anymore since I fixed it\n");

	printf("next should be ERROR / INT_MAX\n");
	printf("calc : %f\n", max_x_dist(data, PI / 2, 2, 2));
	return (0);
}