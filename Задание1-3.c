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
* @brief расчитывает сопротивление
* @param R1, R2, R3 - пременные
* @return численное значение сопротивления
*/
double get_r(const double R1, const double R2, const double R3);

/**
* @brief точка входа функции
* @return 0 в случае успешного выполнения программы
*/
int main(void) {
	puts("Введите сопротивление первого резистора:");
    double R1 = input();
	puts("Введите сопротивление второго резистора:");
    double R2 = input();
	puts("Введите сопротивление третьего резистора:");
    double R3 = input();
    printf("R: %lf\n", get_r(R1, R2, R3));
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

double get_r(const double R1, const double R2, const double R3) {
    return (R1 * R2 * R3) / (R1 * R2 + R1 * R3 + R2 * R3);
}
