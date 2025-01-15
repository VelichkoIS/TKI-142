#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief принимает числовое значение из stdin
* @return числовое значение полученное из stdin
*/
double input(void);

/**
* @brief расчитывает обьем 
* @return числовое значение обьема
*/
double get_v(const double R);

/**
* @brief расчитывает площадь
* @return числовое значение площади
*/
double get_s(const double R);

/**
* @brief точка входа в функцию
* @return 0 при успешном выполнении программы
*/
int main(void) {
	puts("Пожалуйста введите радиус шара:");
	double R = input();
	double V = get_v(R);
	double S = get_s(R);
	printf("S:%f\nV:%f", S, V);
	return 0;
}

double input(void) {
	double value = 0.0;
	int s = scanf_s("%lf", &value);
	if (s != 1) {
		errno = EIO;
		perror("Ошибка, не числовое значение\n");
		exit(EXIT_FAILURE);
	}
	return value;
}

double get_v(const double R) {
	return 4.0 / 3.0 * M_PI * pow(R, 3.0);
}

double get_s() {
	return 4.0 * M_PI * pow(R, 2.0);
}
