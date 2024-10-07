#include <stdio.h>
#include <math.h>

double R1, R2, R3;

double getR(double R1, double R2, double R3) {
	return (R1 * R2 * R3) / (R1 * R2 + R2 * R3 + R3 * R1);
}

int main() {
	printf("Пожалуйста введите значения сопротивлений R1, R2, R3:");
	scanf_s("%lf", &R1);
	scanf_s("%lf", &R2);
	scanf_s("%lf", &R3);
	printf("R:%lf", getR(R1, R2, R3));
	return 0;
}
