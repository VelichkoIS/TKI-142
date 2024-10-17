#include <stdio.h>
#include <math.h>

/**
* @brief получает значения от пользователя
* @param R1, R2, R3 - указатели на переменные(напрямую на ячейки памяти для инициализации переменных)  
*/
void input(double* R1, double* R2, double* R3);

/**
* @brief расчитывает сопротивление
* @param R1, R2, R3 - пременные
*/
double resistance(double R1, double R2, double R3);

/**
* @brief точка входа функции
*/
int main() {
    double R1, R2, R3;
    input(&R1, &R2, &R3); 
    printf("R: %lf\n", resistance(R1, R2, R3)); 
    return 0;
}

void input(double* R1, double* R2, double* R3) {
    printf("Пожалуйста введите значения сопротивлений R1, R2, R3:\n");
    scanf_s("%lf", R1); 
    scanf_s("%lf", R2);
    scanf_s("%lf", R3);
}

double resistance(double R1, double R2, double R3) {
    return (R1 * R2 * R3) / (R1 * R2 + R2 * R3 + R3 * R1);
}
