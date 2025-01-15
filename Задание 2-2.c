#include <stdio.h>
#include <math.h>
#include <errno.h>

/**
 * @brief вычисляет значение функции y
 * @param x значение параметра x
 * @param a константа
 * @return значение функции (y)
 */
double calculateY(const double x, const double a);

/**
* @brief принимает числовое значение из stdin
* @return числовое значение полученное из stdin
*/
double input(void);

/**
* @brief точка входа в функцию
* @return 0 при успешном выполнении программы
*/
int main(void) {
    const double a = 2.8;
    const double x = input();
        printf("y: %lf\n", calculateY(x, a));
    return 0;
}

double input(void) {
    const double x = 0;
    printf("Введите значение x: ");
    if (scanf_s("%lf", &x) != 1) {
        errno = EIO;
        perror("Ошибка, не числовое значение\n");
        abort(1);
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
