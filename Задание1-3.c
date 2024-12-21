#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief принимает числовое значение из stdin
* @return числовое значение полученное из stdin
*/
void input(void);

/**
* @brief расчитывает сопротивление
* @param R1, R2, R3 - пременные
* @return численное значение сопротивления
*/
double resistance(double R1, double R2, double R3);

/**
* @brief точка входа функции
* @return 0 в случае успешного выполнения программы
*/
int main(void) {
    double R1 = input();
    double R2 = input();
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

double get_r(double R1, double R2, double R3) {
    return (R1 * R2 * R3) / (R1 * R2 + R2 * R3 + R3 * R1);
}
