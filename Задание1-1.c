#include <stdio.h>
#include <math.h>

int main()
{
	double x, y, a, b;
	x = 0.335;
	y = 0.025;
	a = 1 + x + (pow(x, 2) / 2) + (pow (x, 3)/ 3) + (pow(x, 4)/ 4);
	b = x * (sin(pow(x, 3)) + pow(cos(y), 2));
	printf("a = %f\nb = %f", a, b);

	return 0;
}