/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:25:47 by obult         #+#    #+#                 */
/*   Updated: 2022/10/03 17:37:04 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>
#include <stdio.h>

/*
 *  This function calls the distance towards the cell border over an axis.
 *	The angle is needed to return a negative number for back- and downwards.
 */
float	calc_distance(float z, float angle)
{
	float	tmp;
	float	trash;

	tmp = modff(z, &trash);
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
float	max_x_dist(t_data data, float angle, float x, float y)
{
	float	x_dist;
	float	y_dist;
	float	result;

	y_dist = calc_distance(y, angle);
	x_dist = tanf(angle) * y_dist;
	// if 
	if ((int)roundf(x_dist + x) > data.x_max || (int)roundf(x_dist + x) < 0)
		return (ERROR);
	if ((int)y_dist + y > data.y_max)
		return (0);
	if (angle < 0.5 * PI || angle > 1.5 * PI)
		if (data.map[(int)roundf(y + y_dist)][(int)roundf(x + x_dist)] != '0')
			return (x_dist);
	if ((int)roundf(x_dist + x) < 1)
		return (ERROR);
	if (data.map[(int)roundf(y + y_dist) - 1][(int)roundf(x + x_dist)] != '0')
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
float	max_y_dist(t_data data, float angle, float x, float y)
{
	float	y_dist;
	float	x_dist;
	float	result;
	float	anglePI;

	anglePI = angle + (PI * 0.5);
	x_dist = calc_distance(x, anglePI);
	y_dist = tanf(anglePI) * x_dist;
	if ((int)roundf(y_dist + y) > data.y_max || (int)roundf(y_dist + y) < 0)
		return (ERROR);
	if ((int)x_dist + x > data.x_max)
		return (0);
	if (anglePI < 0.5 * PI || anglePI > 1.5 * PI)  // here is the issue!!
		if (data.map[(int)roundf(y + y_dist)][(int)roundf(x + x_dist)] != '0')
			return (y_dist);
	if ((int)roundf(y_dist + y) < 1)
		return (ERROR);
	if (data.map[(int)roundf(y + y_dist)][(int)roundf(x + x_dist) - 1] != '0') //the coordinates minus Z nr Z is the problem here
		return (y_dist);
	result = max_y_dist(data, anglePI, y + y_dist, x + x_dist);
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
		// return (x_total);
	}
	data->sign = 'y';
	return (y_total / sinf(angle + (PI * 0.5)));
	// return (y_total);
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
	data.y_max = 3;
	data.sign = 'o';

	data.player.x = 2.9;
	data.player.y = 2.9;

		printf("max dist (2, 2) PI/120 : %f", max_dist(&data, PI / 120));
		printf(", s=%c\n", data.sign);

	// it needs to work between and including 18 and 27 with coords of (3 . 3)
	for (int i = 0; i < 72; i++)
	{
		printf("max dist (px, py) %i : %f", i, max_dist(&data, PI / 36 * i));
		printf(", s=%c\n", data.sign);
	}
	printf("sin(0.5PI) : %f\n", sinf(PI));
	printf("%f\n", -0.0f / -0.0f);


	// printf("next should be 1.1547005\n");
	// printf("calc : %f\n", max_x_dist(data, PI / 6, 1, 1));

	// printf("next should be 0.577350\n");
	// printf("calc : %f\n", max_x_dist(data, PI / 6, 2, 2));

	// printf("next should be -0.577350\n");
	// printf("calc : %f\n", max_x_dist(data, PI / 6 * 7, 2, 2));
	// printf("this is incorrect because it now runs twice as far, not anymore since I fixed it\n");

	// printf("next should be ERROR / INT_MAX\n");
	// printf("calc : %f\n", max_x_dist(data, PI / 2, 2, 2));

	// printf("\nnext up is y\n");

	// printf("next should be same as third one from x\n");
	// printf("calc : %f\n", max_y_dist(data, PI / 6 * 8, 2, 2));
}

int	main(void)
{
	test_max_dist_calc();
	return (0);
}
