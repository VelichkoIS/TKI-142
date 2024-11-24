#include <stdio.h>
#include <math.h>

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
* @brief - запрашивает данные у пользователя и проверяет их на соответсвие числовым типам данных
* @param - указатель на переменную для вводимого пользователем числа
*/
double input(double*, double*, double*);

int main(void) {
	double n1, n2, n3;
	input(&n1, &n2, &n3);
	printf("%.2lf %.2lf %.2lf", calc(n1), calc(n2), calc(n3));
	return 0;
}

double input(double* n1, double* n2, double* n3) {
	if (scanf_s("%lf %lf %lf", n1, n2, n3) != 3) {
		printf("Ошибка, введен неверный тип данных");
		exit(1);
	}
}

double calc(double n) {
	if (n < 0)
		return pow(n, 2);
	return pow(n, 4);
}
