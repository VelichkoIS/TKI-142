#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

/**
* @brief принимает и проверяет числовое значение из stdin
* @return числовое значение полученное из stdin
*/
int get_positive(void);

/**
* @brief считает сумму первых n элементов последовательности
* @param n значение числа членов последовательности сумму которых необходимо найти(n)
* @return сумму первых n элементов последовательности
*/
double sum(const int n);

/**
* @brief - вычисляет сумму всех членов последовательности, по модулю не меньших заданного числа e
* @param e - заданное из stdin число
* @return сумму всех членов последовательности, по модулю не меньших заданного числа e
*/
double sum_e(const int e);

/**
* @brief возвращает следующий член последовательности по рекуреннтной формуле
* @param k актуальное порядковое значение элемента последовательности 
* @return следующий член последовательности по рекуреннтной формуле
*/
double recurent(const int k);

int main(void) {
	puts("Введите чило n:");
	int n = get_positive();
	printf("Сумма первых %d элементов последовательности: %f\n", n, sum(n));
	puts("Введите чило e:");
	int e = get_positive();
	printf("Сумма всех элементов по модулю больше e: %lf", sum_e(e));
	return 0;
}

int get_positive(void) {
	int value = 0;
	const int s = scanf_s("%d", &value);
	if (s != 1 || value <= 0) {
		errno = EIO;
		perror("Ошибка, не числовое значение\n");
		exit(EXIT_FAILURE);
	}
	return value;
}

double sum(const int n) {
	double a = 1.0;
	double result = 1.0;
	for (int k = 0; k < n; k++) {
		a *= recurent(k);
		result += a;
	}
	return result;
}

double sum_e(const int e) {
	double a = 1.0;
	double result = 1.0;
	int k = 1;
	while (fabs(a) >= e +FLT_EPSILON) {
		result += a;
		a *= recurent(k);
		k++;
	}
	return result;
}

double recurent(const int k) {
	return -1.0 / (k + 1.0);
}
