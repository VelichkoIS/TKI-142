#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

/**
* @brief - принимает из stdin, а затем возвращает значение переменной value
* @var value - хранит значение того что ввели в stdin
* @var s - хранит количество символов введенных в stdin
*/
float input();

/**
* @brief - проверяет что интервал существует
* @param intervalB - параметр принимающий значение начала интервала
* @param intervalE - параметр принимающий значение конца интервала
*/
int check(const float intervalB, const float intervalE);

/**
* @brief - проверяет что шаг является положительным числом
* @param step - параметр принимающий значение шага
*/
float check_step(const float step);

/**
* @brief - табулирует функцию в пределах ОДЗ, а так же расчитывает сумму ряда
* @param intervalB - передает значение начала интервала
* @param intervalE - передает значение конца интервала
* @param step - передает значение шага
* @param epsilon - передает значение точности
*/
void calc(const float intervalB, const float intervalE, const float step, const float epsilon);

/**
* @brief - расчитывает значение функции
* @param x - передает значение аргумента функции 
*/
float calc_y(const float x);

/**
* @brief - расчитывает сумму ряда
* @param x - передает значение аргумента функции
* @param epsilon - передает значение точности
*/
float sum(const float x, const float epsilon);

/**
* @brief - возвращает следующий член последовательности по рекуреннтной формуле
* @param x - передает значение аргумента функции
* @param k - актуальное порядковое значение элемента последовательности
*/
float recurent(const float x, const float k);

int main() {
	const float epsilon = pow(15, -4);
	puts("Пожалуйста введите значения начала и конца интервала:\n");
	const float intervalB = input();
	const float intervalE = input();
	check(intervalB, intervalE);
	puts("Пожалуйста введите значение шага табулирования:\n");
	const float step = check_step(input());
	calc(intervalB, intervalE, step, epsilon);

	return 0;
}

float input() {
	float value = 0;
	const int s = scanf_s("%f", &value);
	if (s != 1) {
		errno = EIO;
		perror("Ошибка, не числовое значение\n");
		exit(EXIT_FAILURE);
	}
	return value;
}

int check(const float intervalB, const float intervalE) {
	if (fabs(intervalB - intervalE) < FLT_EPSILON) {
		errno = EIO;
		perror("Ошибка, интервал задан одним числом\n");
		exit(EXIT_FAILURE);
	}
}

float check_step(const float step) {
	if (step < FLT_EPSILON) {
		errno = EIO;
		perror("Ошибка, слишком маленький шаг\n");
		exit(EXIT_FAILURE);
	}
	return step;
}

// область определения от -бесконенчости до бесконенчости
void calc(const float intervalB, const float intervalE, const float step, const float epsilon) {
	for (float x = intervalB; x <= intervalE + FLT_EPSILON; x += step) {
		printf("x = %.2f     f(x) = %.6f      S(x) = %.6f\n", x, calc_y(x), sum(x, epsilon));
	}
}

float calc_y(const float x) {
	  return pow(exp(1), x);
      }

float sum(const float x, const float epsilon) {
	float a = recurent(x, 0); 
	double result = 0.0;
	int k = 1;

	while (fabs(a) >= epsilon) {
		result += a;
		a = recurent(x, k);
		k++;
	}

	return result;
}

float recurent(const float x, const float k) {
	return (4 * k + 1) * pow(x, 4) / (4 * k + 5);
}
