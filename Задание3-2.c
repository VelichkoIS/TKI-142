#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

/**
* @brief - принимает из stdin, а затем возвращает значение переменной value
* @var value - переменная для хранения значения того что ввели в stdin
* @var s - переменная для хранения количества символов введенных в stdin
*/
int input();

/**
* @brief - проверяет является ли число n роложительным
* @param n - значение числа членов последовательности сумму которых необходимо найти(n)
*/
int check(const int n);

/**
* @brief - считает сумму первых n элементов последовательности
* @param n - значение числа членов последовательности сумму которых необходимо найти(n)
* @var a - текущий элемент последовательности
* @var result - текущая сумма членов последовательности
* @var k - используется для цикла (актуальное порядковое значение элемента последовательности)
*/
float sum(const int n);

/**
* @brief - вычисляет сумму всех членов последовательности, по модулю не меньших заданного числа e
* @param e - заданное из stdin число
* @var a - текущий элемент последовательности
* @var result - текущая сумма членов последовательности
* @var k - используется для цикла (актуальное порядковое значение элемента последовательности)
*/
float sum_e(const int e);

/**
* @brief - возвращает следующий член последовательности по рекуреннтной формуле
* @param k - актуальное порядковое значение элемента последовательности 
*/
float recurent(const int k);

int main() {
	puts("Введите чило n:");
	int n = check(input());
	printf("Сумма первых %d элементов последовательности: %f\n", n, sum(n));
	puts("Введите чило e:");
	int e = check(input());
	printf("Сумма всех элементов по модулю больше e: %f", sum_e(e));
	return 0;
}

int input() {
	int value = 0;
	const int s = scanf_s("%d", &value);
	if (s != 1) {
		errno = EIO;
		perror("Ошибка, не числовое значение\n");
		exit(EXIT_FAILURE);
	}
	return value;
}

int check(const int n) {
	if (n <= 0) {
		errno = EIO;
		perror("Ошибка, не положительное значение n\n");
		exit(EXIT_FAILURE);
	}
	return n;
}

float sum(const int n) {
	float a = 1.0;
	float result = 1.0;
	for (int k = 0; k < n; k++) {
		a *= recurent(k);
		result += a;
	}
	return result;
}

float sum_e(const int e) {
	float a = 1.0;
	float result = 1.0;
	int k = 1;
	while (fabs(a) >= e +FLT_EPSILON) {
		result += a;
		a *= recurent(k);
		k++;
	}
}

float recurent(const int k) {
	return -1.0 / (k + 1.0);
}
