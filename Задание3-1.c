#include <stdio.h>
#include <math.h>

/**
* @ breif - принимает значения
* @ param x - указатель на переменную хранящую введеное число
*/
int input(double*);

/**
* @ breif - вычисляет и проверяет на соответсвие интервалу значение функции
* @ param x - параметр принимающий значение переменной x введеное число
*/
void check(double);

/**
* @brief - спрашивает нужно ли остановить выполнение программы или запустить цикл вычислений еще раз
*/
int cycle();

/**
* @brief - проверяет введеное значение на кратность 0.05, то есть шагу табулирования
* @ param x - параметр принимающий значение переменной x введеное число
*/
int step(double);

/**
* @ breif - точка входа в функцию
* @ var x - переменная дублируящая актуальное значение в цикле
* @ var result - переменная результата одного шага цикла
*/
int main(void) {
	int c = 1, s = 0;
	double x, result;

	do {
		input(&x);
		step(x);
		check(x);
		c = cycle();
	} while (c != 0);
	return 0;
}

int input(double* x) {
	printf("Введите число: ");
	double c = scanf_s("%lf", x);
	if (c != 1 || (*x) < 0.4 || (*x) > 1) {
		printf("Введенное значение не соответсвуют указаному в задание интервалу, или не число");
		exit(1);
	}
}

void check(double x) {
	double result = x + pow(x, 1.0 / 2) + pow(x, 1.0 / 3) - 2.5;
	if ((isnan(result) == 1) || (isinf(result) == 1))
		printf("Для данного значения x = %lf решения не существует:\n", x);
	else printf("%lf\n", result);
}

int cycle() {
	int dn = 0;
	printf("Хотите ввести еще одно число (1 - для продолжения ввода)?:");
	scanf_s("%d", &dn);
	if (dn == 1)
		return 0;
	else
		exit(0);
}

int step(double x) {
	if (fabs(fmod(x, 0.05)) > 1e-9) {
		printf("Ошибка, не соблюден шаг между значениями в 0.05");
		exit(1);
	}
}
