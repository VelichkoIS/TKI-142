#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <errno.h>

/**
* @brief - принимает из stdin, а затем возвращает значение переменной value
* @var value - переменная для хранения значения того что ввели в stdin
* @var s - переменная для хранения количества символов введенных в stdin
*/
float input();

/**
 * @brief - вычисляет площадь трапеции
 * @var a - длина первого основания
 * @var b - длина второго основания
 * @var h - высота трапеции
 */
double trapezoidcalculation();

/**
 * @brief - вычисляет площадь круга
 * @var r - радиус круга
 */
double circlecalculation();

enum ShapeType {
    TRAPEZOID,
    CIRCLE
};

/**
* @brief - точка входа в функцию
* @var choice - целочисленная переменная для получения данных о выборе фигуры от пользователя
*/
int main() {
    puts("Выберите фигуру для расчета площади:\n0 - Трапеция\n1 - Круг\n");
    const int choice = input();
    switch (choice) {
    case TRAPEZOID: {
        printf("Площадь трапеции: %0.2lf", trapezoidcalculation());
        break;
    }
    case CIRCLE: {
        printf("Площадь круга: %0.2lf", circlecalculation());
        break;
    }
    default:
        puts("Неверный выбор! Пожалуйста, выберите 0 или 1.\n");
        return 1;
    }
    return 0;
}

double trapezoidcalculation() {
    puts("Введите длины оснований a,b и высоту h через пробел: ");
    const double a = input();
    const double b = input();
    const double h = input();
    return 0.5 * (a + b) * h;
}

double circlecalculation() {
    puts("Введите радиус круга (r): ");
    const double r = input();
    return M_PI * r * r;
}

float input() {
    float value = 0.0;
    int s = scanf_s("%f", &value);
    if (s != 1) {
        errno = EIO;
        perror("Ошибка, не числовое значение\n");
        exit(1);
    }
    return value;
}
