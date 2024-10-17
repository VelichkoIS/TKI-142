#include <stdio.h>
#include <math.h>

double R;
const double p = 3.14;

/**
* @brief расчитывает значение обьема шара
*/
double Volume();

/**
* @brief расчитывает площадь поверхности шара
*/
double Square();

/**
* @brief точка входа функции
*/
int main() {
	printf("%s", "Пожалуйста введите радиус шара:");
	scanf_s("%lf", &R);
	printf("S:%f\nV:%f", Square(), Volume());
	return 0;
}

double Volume() {
	return 4 / 3 * p * pow(R, 3);
}

double Square() {
	return 4 * p * pow(R, 2);
}
