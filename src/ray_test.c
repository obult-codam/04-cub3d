#include "ray.h"

/*
 *	This thing is here to test the functions
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

	data.player.x = 1.8;
	data.player.y = 1.8;
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
	printf("\n");
	test_max_dist_calc_float((char *[]){"1111", "1001", "1001", "1111"});
	return (0);
}
