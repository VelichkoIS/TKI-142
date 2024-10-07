#include <stdio.h>
#include <math.h>

/**
* @brief рассчитывает значения a по формуле
* @return рассчитанное значение */

double getA(const double x);

/*
* @brief рассчитывает значения b по формуле
* @return рассчитанное значение */

double getB(const double x, const double y);

/*
* @brief - точка входа функции
* @return - возвращает 0 в случае успешного выполнения программы */

int main()
{
	double const x = 0.335, y = 0.025;
	printf("a = %f\nb = %f", getA(x), getB(x, y));

	return 0;
}

double getA(const double x)
{
	return 1 + x + (pow(x, 2) / 2) + (pow(x, 3) / 3) + (pow(x, 4) / 4);
}

double getB(const double x, const double y)
{
	return x * (sin(pow(x, 3)) + pow(cos(y), 2));
}
