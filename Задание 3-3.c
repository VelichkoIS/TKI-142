#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

/**
* @brief - принимает из stdin, а затем возвращает значение переменной value
* @return числовое значение полученное из stdin
*/
double input(void);

/**
* @brief табулирует функцию в пределах ОДЗ, а так же расчитывает сумму ряда
* @param intervalB передает значение начала интервала
* @param intervalE передает значение конца интервала
* @param step передает значение шага
* @param epsilon передает значение точности
*/
void calc(const double intervalB, const double intervalE, const double step, const double epsilon);

/**
* @brief расчитывает значение функции
* @param x передает значение аргумента функции
* @return возвращает значение функции (y)
*/
double calc_y(const double x);

/**
* @brief расчитывает сумму ряда
* @param x передает значение аргумента функции
* @param epsilon передает значение точности
* @return возвращает сумму ряда
*/
double sum(const double x, const double epsilon);

/**
* @brief возвращает следующий член последовательности по рекуреннтной формуле
* @param x передает значение аргумента функции
* @param k актуальное порядковое значение элемента последовательности
* @return возвращает следующий член последовательности по рекуреннтной формуле
*/
double reccurent(const double x, const double k);

/**
* @brief - точка входа в программу
* @return 0 при успешном выполнении программы
*/
int main(void) {
	double epsilon = pow(15, -4);
	puts("Пожалуйста введите значения начала и конца интервала:\n");
	double intervalB = input();
	double intervalE = input();
	check(intervalB, intervalE);
	puts("Пожалуйста введите значение шага табулирования:\n");
	double step = get_step();
	calc(intervalB, intervalE, step, epsilon);

	return 0;
}

double input(void) {
	double value = 0;
	int s = scanf_s("%lf", &value);
	if (s != 1) {
		errno = EIO;
		perror("Ошибка, не числовое значение\n");
		exit(EXIT_FAILURE);
	}
	return value;
}

double get_step() {
	double value = 0;
	int s = scanf_s("%lf", &value);
	if (s != 1 || value < DBL_EPSILON) {
		errno = EIO;
		perror("Ошибка ввода\n");
		exit(EXIT_FAILURE);
	}
	return value;
}

// область определения от -бесконенчости до бесконенчости
void calc(const double intervalB, const double intervalE, const double step, const double epsilon) {
	for (double x = intervalB; x <= intervalE + FLT_EPSILON; x += step) {
		printf("x = %.2f     f(x) = %.6f      S(x) = %.6f\n", x, calc_y(x), sum(x, epsilon));
	}
}

double calc_y(const double x) {
	return exp(x);
}

double sum(const double x, const double epsilon) {
	double current = recurent(x, 0);
	double result = 0.0;
	int k = 1;

	while (fabs(current) >= epsilon - DBL_EPSILON) {
		result += current;
		current *= recurent(x, k);
		k++;
	}

	return result;
}

double reccurent(const double x, const double k) {
	return x / k;
}
