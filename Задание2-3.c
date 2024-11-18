#include <stdio.h>
#include <math.h>

/**
* @brief - определяет какое действие произвести
* @ param n - число над которым необходисо выполнить действие
*/
double calc(int);

/**
* @brief - точка входа в функцию
* @var - n1, n2, n3 вещественные числа вводимые пользователем
*/
int main(void) {
	double n1, n2, n3;
	
	scanf_s("%lf%lf%lf", &n1, &n2, &n3);
	printf("%lf %lf %lf", calc(n1), calc(n2), calc(n3));

}


double calc(int n) {
	if (n < 0)
		return pow(n, 2);
	return pow(n, 4);
}
