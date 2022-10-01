/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:25:47 by obult         #+#    #+#                 */
/*   Updated: 2022/10/01 23:34:48 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>
#include <stdio.h>

/*
 *  This function calls the distance towards the cell border over an axis.
 *	The angle is needed to return a negative number for back- and downwards.
 */
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

/*
 *	This Function calculates the distance untill a ray with an angle against the north
 *	has reached an obstacle perpendicular with the x axis.
 */
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

/*
 *	This Function calculates the distance untill a ray with an angle against the north
 *	has reached an obstacle perpendicular with the y axis.
 */
double	max_y_dist(t_data data, double angle, double x, double y)
{
	double	y_dist;
	double	x_dist;
	double	result;
	double	anglePI;

	anglePI = angle + (PI * 0.5);
	x_dist = calc_distance(x, anglePI);
	y_dist = tan(anglePI) * x_dist;
	if ((int)round(y_dist + y) > data.x_max || (int)round(y_dist + y) < 1)
		return (ERROR);
	if (anglePI < 0.5 * PI || anglePI > 1.5 * PI)
		if (data.map[(int)round(y + y_dist)][(int)round(x + x_dist)] != '0')
			return (y_dist);
	if (data.map[(int)round(y + y_dist) - 1][(int)round(x + x_dist) - 1] != '0')
		return (y_dist);
	result = max_x_dist(data, anglePI, y + y_dist, x + x_dist);
	if (result == ERROR)
		return (ERROR);
	return (result + y_dist);
}

/*
 *	This thing is here to test the functions.
 */
void	test_max_dist_calc(void)
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

	printf("\nnext up is y\n");

	printf("next should be same as third one from x\n");
	printf("calc : %f\n", max_y_dist(data, PI / 6 * 8, 2, 2));
}

int	main(void)
{
	test_max_dist_calc();
	return (0);
}
