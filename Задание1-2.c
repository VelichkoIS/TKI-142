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
* @brief точка входа в функцию
* @return 0 при успешном выполнении программы
*/
int main(void) {
	double R = input();
	puts("Пожалуйста введите радиус шара");
	double V = 4.0 / 3.0 * M_PI * pow(R, 3);
	double S = 4.0 * M_PI * pow(R, 2);
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
