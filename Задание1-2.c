#include <stdio.h>
#include <math.h>

double R;
const double p = 3.14;

int main(){
	printf("%s", "Пожалуйста введите радиус шара:");
	scanf_s("%lf", &R);
	double V = 4 / 3 * p * pow(R, 3);
	double S = 4 * p * pow(R, 2);
	printf("S:%f\nV:%f", S, V);
	return 0;
}
