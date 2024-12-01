#include <stdio.h>
#include <math.h>

/**
* @brief - принимает из stdin, а затем возвращает значение переменной value
* @var value - переменная для хранения значения того что ввели в stdin
* @var s - переменная для хранения количества символов введенных в stdin
*/
float input();

/**
* @brief main - точка входа в функцию
* @var R - принимает значение радиуса вводимое пользователем
* @var p - содержит в себе значение числа пи
* @var V - содержит в себе значение обьема
* @var S - содержит в себе значение площади
* @return - возвращает значение 0 при успешном выполнении программы 
*/
int main(){
	float R = input();
	const float p = 3.14;
	puts("Пожалуйста введите радиус шара");
	double V = 4 / 3 * p * pow(R, 3);
	double S = 4 * p * pow(R, 2);
	printf("S:%f\nV:%f", S, V);
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
