#include <stdio.h>
#include <math.h>

/**
 * @brief - вычисляет значение функции y
 * @param x - значение параметра x
 * @param a - константа
 */
double calculateY(double x, double a);

/**
 * @brief - получает ввод от пользователя и проверяет тип вводимых данных
 */
double input();

int main() {
    const double a = 2.8;
    double x = input();
    if (x != 1) { 
        printf("y: %lf\n", calculateY(x, a));
    }
    return 0;
}

double input() {
    double x;
    printf("Введите значение x: ");
    if (scanf_s("%lf", &x) != 1) {
        printf("Ошибка ввода! Пожалуйста, введите числовое значение.\n");
        return 1; 
    }
    return x;
}

double calculateY(double x, double a) {
    if (x < 1.2) {
        return a * x * x + 4;
    }
    else {
        return (a + 4 * x) * sqrt(x * x * a);
    }
}
