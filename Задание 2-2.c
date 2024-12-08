#include <stdio.h>
#include <math.h>

/**
 * @brief - вычисляет значение функции y
 * @param x - значение параметра x
 * @param a - константа
 */
double calculateY(const double x, const double a);

/**
* @brief - принимает из stdin, а затем возвращает значение переменной value
* @var value - переменная для хранения значения того что ввели в stdin
* @var s - переменная для хранения количества символов введенных в stdin
*/
double input();

int main() {
    const double a = 2.8;
    const double x = input();
        printf("y: %lf\n", calculateY(x, a));
    return 0;
}

double input() {
    const double x = 0;
    printf("Введите значение x: ");
    if (scanf_s("%lf", &x) != 1) {
        printf("Ошибка ввода! Пожалуйста, введите числовое значение.\n");
        return 1;
    }
    return x;
}

double calculateY(const double x, const double a) {
    if (x < 1.2) {
        return a * x * x + 4;
    }
    else {
        return (a + 4 * x) * sqrt(x * x * a);
    }
}
