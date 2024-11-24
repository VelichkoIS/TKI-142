#include <stdio.h>
#include <math.h>

/**
* @ breif - принимает значения
* @ param x - указатель на переменную хранящую введеное число
*/
double input(double*);

/**
* @ breif - проверяет значение функции
* @ param x - параметр принимающий значение переменной x введеное число
* @ param result - параметр принимающий значение функции для его проверки
*/
double check(double, double);

/**
* @ breif - точка входа в функцию
* @ var x - переменная дублируящая актуальное значение в цикле
* @ var result - переменная результата одного шага цикла
*/
int main(void) {
	double x, result;

	input(&x);
	result = x + pow(x, 1 / 2) + pow(x, 1 / 3) - 2.5;
	check(result, x);
	return 0;
}

double input(double* x) {
	printf("Введите число: ");
	double c = scanf_s("%lf", x);
	if (c != 1 || (*x) < 0.4 || (*x) > 1) {
		printf("Введенное значение не соответсвуют указаному в задание интервалу, или не число");
		exit(1);
	}
}

double check(double result, double x) {
	if ((isnan(result) == 1) || (isinf(result) == 1))
		printf("Для данного значения x = %lf решения не существует:", x);
	else printf("%lf", result);
}
