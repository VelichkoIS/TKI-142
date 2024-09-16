#include <stdio.h>
#include <math.h>
/**
* @brief рассчитывает а по формуле 
* @param x - значение константы х
* @param y - значение константы y
* @param z - значение константы z
* @return рассчитанное значение
*/
double getA(const double x, const double y, const double z); 

int main()
{
	double const x = 0.335, y = 0.025;
	b = x * (sin(pow(x, 3)) + pow(cos(y), 2));
	printf("a = %f\nb = %f", getA(x, y, z), b);

	return 0;
}

double getA(const double x, const double y, const double z)
{
	return 1 + x + (pow(x, 2) / 2) + (pow (x, 3)/ 3) + (pow(x, 4)/ 4);
}
