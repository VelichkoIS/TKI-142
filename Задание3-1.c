#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

/**
* @brief - принимает из stdin, а затем возвращает значение переменной value
* @var value - переменная для хранения значения того что ввели в stdin
* @var s - переменная для хранения количества символов введенных в stdin
*/
float input();


/**
* @brief - проверяет что интервал существует
* @param intervalB - параметр принимающий значение начала интервала
* @param intervalE - параметр принимающий значение конца интервала
*/
int check(const float, const float);

/**
* @brief - проверяет что шаг является положительным числом 
* @param step - параметр принимающий значение шага
*/
float check_step(const float);

/**
* @brief - табулирует функцию в пределах ОДЗ
* @param intervalB - параметр принимающий значение начала интервала
* @param intervalE - параметр принимающий значение конца интервала
* @param step - параметр принимающий значение шага
* @var result - переменная для хранения значения функции
*/
int calc(float, const float, const float);

int main() {
	puts("Пожалуйста введите значения начала и конца интервала:");
	const float intervalB = input();
	const float intervalE = input();
	check(intervalB, intervalE);
	puts("Пожалуйста введите значение шага табулирования:");
	const float step = check_step(input());
	calc(intervalB, intervalE, step);
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

int calc(float intervalB, const float intervalE, const float step) {
	float result;
	for (; intervalB <= intervalE + FLT_EPSILON; intervalB += step) {
		if (intervalB < 0) // ОДЗ
			puts("Значение не может быть посчитанно");
		result = intervalB + pow(intervalB, 1.0 / 2.0) + pow(intervalB, 1.0 / 3.0) - 2.5;
		printf("Для x = %0.2f y = %0.2f\n", intervalB, result);
	}
}
