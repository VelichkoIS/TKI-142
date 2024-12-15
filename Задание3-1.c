#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

/**
* @brief принимает числовое значение из stdin
* @return числовое значение полученное из stdin
*/
double input();

/**
* @brief проверяет что шаг является положительным числом
* @param step параметр принимающий значение шага
* @return числовое значение параметра step
*/
double check_step(const double step);

/**
* @brief табулирует функцию в пределах ОДЗ
* @param intervalB параметр принимающий значение начала интервала
* @param intervalE параметр принимающий значение конца интервала
* @param step параметр принимающий значение шага
*/
void calc(double intervalB, const double intervalE, const double step);

/**
* @brief - точка входа в программу
* @return 0 при успешном выполнении программы
*/
int main() {
	puts("Пожалуйста введите значения начала и конца интервала:");
	const double intervalB = input();
	const double intervalE = input();
	puts("Пожалуйста введите значение шага табулирования:");
	const double step = check_step(input());
	calc(intervalB, intervalE, step);
	return 0;
}

double input() {
	double value = 0.0;
	int s = scanf_s("%lf", &value);
	if (s != 1) {
		errno = EIO;
		perror("Ошибка, не числовое значение\n");
		exit(EXIT_FAILURE);
	}
	return value;
}

double check_step(const double step) {
	if (step < DBL_EPSILON) {
		errno = EIO;
		perror("Ошибка, слишком маленький шаг\n");
		exit(EXIT_FAILURE);
	}
	return step;
}

void calc(double intervalB, const double intervalE, const double step) {
	double result;
	for (; intervalB <= intervalE + DBL_EPSILON; intervalB += step) {
		if (intervalB < 0) // ОДЗ
			puts("Значение не может быть посчитанно");
		result = intervalB + sqrt(intervalB) + cbrt(intervalB) - 2.5;
		printf("Для x = %0.2f y = %0.2f\n", intervalB, result);
	}
}
