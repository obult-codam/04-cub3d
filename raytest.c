/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raytest.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:25:47 by obult         #+#    #+#                 */
/*   Updated: 2022/09/29 21:21:32 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#define PI 3.1415926535

/*
 *  this will shoot a ray and return the len in horizontal or vertical
 */

// double	shoot(double angle, double x, double y)
// {
// 	double	progress;
// 	double	y_distance;

// 	y_distance = modf(y, NULL);
// 	if (y_distance == 0)
// 		y_distance = 1;
// 	progress = tan(angle) * y_distance;
// }

int	main(void)
{
	// char ** testdata = {"1111", "1001", "1001", "1111"};

	// printf("tan 0: %f\n", tan(0) * 1);
	// printf("tan 1/3p: %f\n", tan(PI / 3) * 1);
	// printf("tan 2/3p: %f\n", tan(PI / 3 * 2) * 1);
	// printf("tan p: %f\n", tan(PI) * 1);
	// printf("tan 2p: %f\n", tan(PI * 2) * 1);
	// printf("tan .5p: %f\n", tan(PI * 0.5) * 1);
	// printf("tan 1/3p: %f\n", tan(PI / 3) * 1);

	// printf("\n");

	printf("sin(x) 1/3p: %f\n", sin(PI / 3) * 1);
	printf("cos(y) 1/3p: %f\n", cos(PI / 3) * 1);
	printf("sin(x) 0.5p: %f\n", sin(PI / 2) * 1);
	printf("cos(y) 0.5p: %f\n", cos(PI / 2) * 1);
	printf("sin(x) 1p: %f\n", sin(PI) * 1);
	printf("cos(y) 1p: %f\n", cos(PI) * 1);
	printf("sin(x) 1.5p: %f\n", sin(PI * 1.5) * 1);
	printf("cos(y) 1.5p: %f\n", cos(PI * 1.5) * 1);

	return (0);
}
