#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief принимает числовое значение из stdin
* @return числовое значение полученное из stdin
*/
double input(void);

/**
 * @brief вычисляет площадь трапеции
 * @return площадь трапеции
 */
double trapezoid_calc(void);

/**
 * @brief вычисляет площадь круга
 * @return площадь круга
 */
double circle_calc(void);

enum ShapeType {
    trapezoid,
    circle
};

/**
* @brief точка входа в функцию
* @return 0 при успешном выполнении программы
*/
int main(void) {
    printf("Введите:\n%d - для расчета полощади трапеции\n%d - для расчета площади круга\n", (int)trapezoid, (int)circle);
    enum ShapeType choice = input();
    switch (choice) {
    case trapezoid: {
        printf("Площадь трапеции: %0.2lf", trapezoid_calc());
        break;
    }
    case circle: {
        printf("Площадь круга: %0.2lf", circle_calc());
        break;
    }
    default:
        puts("Неверный выбор! Пожалуйста, выберите 0 или 1.\n");
        return 1;
    }
    return 0;
}

double trapezoid_calc(void) {
    puts("Введите длины оснований a,b и высоту h через пробел: ");
    double a = input();
    double b = input();
    double h = input();
    return 0.5 * (a + b) * h;
}

double circle_calc(void) {
    puts("Введите радиус круга (r): ");
    double r = input();
    return M_PI * r * r;
}

double input(void) {
    double value = 0.0;
    int s = scanf_s("%lf", &value);
    if (s != 1) {
        errno = EIO;
        perror("Ошибка, не числовое значение\n");
        exit(1);
    }
    return value;
}
