#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief - определяет какое действие произвести
* @ param n - число над которым необходисо выполнить действие
*/
double calc(double);

/**
* @brief - точка входа в функцию
* @var - n1, n2, n3 вещественные числа вводимые пользователем
*/

/**
* @brief - принимает из stdin, а затем возвращает значение переменной value
* @var value - переменная для хранения значения того что ввели в stdin
* @var s - переменная для хранения количества символов введенных в stdin
*/
float input();

/**
* @brief - точка входа в функцию
* @var n1 - принимает значение n1 из stdin
* @var n1 - принимает значение n2 из stdin
* @var n1 - принимает значение n3 из stdin
* @return - возвращает значение 0 в результате успешного выполнения программы
*/
int main(void) {
	float n1 = input();
	float n2 = input();
	float n3 = input();
	printf("%.2lf %.2lf %.2lf", calc(n1), calc(n2), calc(n3));
	return 0;
}

float input() {
	float value = 0.0;
	int s = scanf_s("%f", &value);
	if (s != 1) {
		errno = EIO;
		perror("Ошибка, не числовое значение\n");
		exit(EXIT_FAILURE);
	}
	return value;
}

double calc(double n) {
	if (n < 0)
		return pow(n, 2);
	return pow(n, 4);
}
