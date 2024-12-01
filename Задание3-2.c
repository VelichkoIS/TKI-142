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

int check(const int);

float sum(float, float, const int);

float_sum_e(const int);

int main() {
	puts("Введите чило n:");
	int n = check(input());
	printf("Сумма первых %d элементов последовательности: %f\n", n, sum(1.0, 1.0, n));
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

float sum(float a, float result, const int n) {
	for (int k = 0; k < n; k++) {
		a *= -1.0 / (k + 1.0);
		result += a;
	}
	return result;
}

float sum_e(const int n, const int e) {
	for (int k = 0; k < n; k++) {
		if (k >= e - FLT_EPSILON) {
			k -= 1;
			float a = pow(-1, k) / factorial(k);
			float result = a;
			return sum(a, result, n-k);
		}
	}
}

int factorial(int k) {
	int result = 1;
	for (int i = 1; i < k+1; i++) {
		result *= i;
	}
	return result;
}
