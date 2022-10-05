/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:25:47 by obult         #+#    #+#                 */
/*   Updated: 2022/10/05 16:11:22 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "quartz.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

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
	printf("xdist: %f\n", x_dist);
	if ((int)roundf(x_dist + x) > data.x_max || (int)roundf(x_dist + x) < 0)
		return (ERROR);
	if ((int)y_dist + y > data.y_max || (int)y_dist + y < 0)
		return (ERROR);
	if (angle < 0.5 * PI || angle > 1.5 * PI)	//check?
		if (data.map[(int)roundf(y + y_dist)][(int)roundf(x + x_dist)] != '0')
			return (x_dist);
	if ((int)roundf(y_dist + y) < 1)
		return (ERROR);
	if (data.map[(int)roundf(y + y_dist) - 1][(int)roundf(x + x_dist)] != '0')
		return (x_dist);
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
	// printf("ydist: %f\n", y_dist);
	if ((int)roundf(y_dist + y) > data.y_max || (int)roundf(y_dist + y) < 0)
		return (ERROR);
	if ((int)roundf(x_dist + x) > data.x_max || (int)roundf(x_dist + x) < 0)
		return (ERROR);
	if (angle > 0 && angle < PI)
		if (data.map[(int)roundf(y + y_dist)][(int)roundf(x + x_dist)] != '0')
			return (y_dist);
	if ((int)roundf(x_dist + x) < 1)
		return (ERROR);
	if (data.map[(int)roundf(y + y_dist)][(int)roundf(x + x_dist) - 1] != '0')
		return (y_dist);
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

// float	template_dist_y(t_data *data, float angle, t_template tem)
// {
// 	float	y_dist;
// 	float	x_dist;
// 	float	result;
// 	float	anglePI;

// 	anglePI = angle - 0.5 * PI;
// 	x_dist = calc_distance_x(data->player.x, angle);
// 	y_dist = tanf(anglePI) * x_dist * tem.sign;
// 	if (data->player.x + x_dist + tem.x_offset < 0 || data->player.x + x_dist + tem.x_offset > data->x_max)
// 		return (ERROR);
// 	if (data->player.y + y_dist + tem.y_offset < 0 || data->player.y + y_dist + tem.y_offset > data->y_max)
// 		return (ERROR);
// 	if (data->map[(int)roundf(data->player.y + y_dist) + tem.y_offset][(int)roundf(data->player.x + x_dist) + tem.x_offset] != '0')
// 		return (y_dist);
// 	result = template_dist_y(data, angle, tem);
// 	if (result == ERROR)
// 		return (ERROR);
// 	return (result + y_dist);
// }

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

		printf("max dist (2, 2) PI/120 : %f", max_dist(&data, PI / 120));
		printf(", s=%c\n", data.sign);

	// it needs to work between and including 18 and 27 with coords of (3 . 3)
	for (int i = 0; i < 18; i++)
	{
		usleep(200);
		if (i % 18 == 0)
			printf("========\n");
		printf("max dist (px, py) %i : %f", i, first_q(&data, PI / 36 * i));
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
	test_max_dist_calc((char *[]){"1111", "1001" "1001", "1111"});
	return (0);
}
