#include <stdio.h>
#include <math.h>

/**
* @ breif - принимает значения
* @ param intervalB - указатель на адрес значения начала интервала
* @ param intervalE - указатель на адрес значения конца интервала
* @ param step - указатель на адрес значения шага
*/
double input(double*, double*, double*);


/**
* @ breif - точка входа в функцию
* @ var intervalB - переменная начала интервала
* @ var intervalE - переменная конец интервала
* @ var step - переменная шага
* @ var x - переменная дублируящая актуальное значение в цикле
* @ var result - переменная результата одного шага цикла
*/
int main(void) {
	double intervalB, intervalE, step, x, result;

	input(&intervalB, &intervalE, &step);
	for (double i = intervalB; i < intervalE; i += step) {
		x = i;
		result = x + pow(x, 1 / 2) + pow(x, 1 / 3) - 2.5;

			if ((isnan(result) == 1) || (isinf(result) == 1))
				 printf("Для данного значения x = %x решения не существует");
			else printf("%lf", result);
	}

}

double input(double* intervalB, double* intervalE, double* step) {
	printf("Введите интервал(два числа через двоеточие):");
	scanf_s("%lf: %lf", intervalB, intervalE);
	printf("Введите шаг для этого интервала:");
	scanf_s("%lf", step);
}
