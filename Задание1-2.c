#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/**
* @brief - рассчитывает значение объема шара
* @param R - параметр принимающий значение радиуса
*/
double Volume(double R);

/**
* @brief - рассчитывает площадь поверхности шара
* @param R - параметр принимающий значение радиуса
*/
double Square(double R);

/**
* @brief - спрашивает, а затем получает значение вводимое пользователем
* @var RE - принимает значение радиуса
*/
double Enter();

/**
* @brief - точка входа функции
* @var R - переменная принимает значение функции Enter
*/
int main() {
    double R = Enter(); 
    printf("S: %f\nV: %f\n", Square(R), Volume(R));
    return 0;
}

double Enter() {
    double RE;
    printf("Пожалуйста, введите радиус шара: ");
    scanf_s("%lf", &RE);
    return RE;
}

double Volume(double R) {
    return (4.0 / 3.0) * M_PI * pow(R, 3);
}

double Square(double R) {
    return 4 * M_PI * pow(R, 2);
}
