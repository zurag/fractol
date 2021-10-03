#include "fractol.h"


int	ft_rand()
{
	static unsigned long int rand;

	rand = rand * 1103515245;
  	return ((unsigned int)(rand / 65536) * 2768);
}

int ft_create_color(int i)
{	
	// (void)i;
	return (create_trgb(0, (3 * sin(i) + 100), (60 * sin(i) + 150), (10 * sin(i) + 200)));
	// return (create_trgb(0, ( i * ft_rand()) % 255, (i * ft_rand()) % 255, (i * ft_rand()) % 255 ));
	// return (create_trgb(0, (ft_rand()) % 255 , (ft_rand()) % 255, (ft_rand()) % 255));
}
