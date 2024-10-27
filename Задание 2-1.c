#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

typedef enum {
    TRAPEZOID = 1,
    CIRCLE
} ShapeType;

/**
 * @brief - вычисляет площадь трапеции
 * @param a - длина первого основания
 * @param b - длина второго основания
 * @param h - высота трапеции
 */
double trapezoidcalculation(double a, double b, double h);

/**
 * @brief - вычисляет площадь круга
 * @param r - радиус круга
 */
double circlecalculation(double r);

/**
 * @brief - получает ввод для выбранной фигуры
 * @param shape - тип фигуры
 */
double input(ShapeType shape);

/**
* @brief - точка входа в функцию
* @var choice - целочисленная переменная для получения данных о выборе фигуры от пользователя
* @var shape - перечисляемая переменная принимает значение приведенной к перечисляемому типу переменной choice
* @var area - переменная принимает значение результат выполнения фкнкции input
*/
int main() {
    int choice;
    printf("Выберите фигуру для расчета площади:\n1 - Трапеция\n2 - Круг\nВаш выбор: ");
    if (scanf_s("%d", &choice) != 1) {
        printf("Ошибка ввода! Пожалуйста, введите числовое значение.\n");
        return 1;
    }
    ShapeType shape = (ShapeType)choice;
    double area = input(shape);

    if (area != 1) {
        printf("Площадь выбранной фигуры: %lf\n", area);
    }
    return 0;
}

double trapezoidcalculation(double a, double b, double h) {
    return 0.5 * (a + b) * h;
}

double circlecalculation(double r) {
    return M_PI * r * r;
}

double input(ShapeType shape) {
    switch (shape) {
    case TRAPEZOID: {
        double a, b, h;
        printf("Введите длины оснований a,b и высоту h через пробел: ");
        if (scanf_s("%lf %lf %lf", &a, &b, &h) != 3) {
            printf("Ошибка ввода! Пожалуйста, введите три числовых значения.\n");
            return 1;
        }
        return trapezoidcalculation(a, b, h);
    }
    case CIRCLE: {
        double r;
        printf("Введите радиус круга (r): ");
        if (scanf_s("%lf", &r) != 1) {
            printf("Ошибка ввода! Пожалуйста, введите числовое значение.\n");
            return 1;
        }
        return circlecalculation(r);
    }
    default:
        printf("Неверный выбор! Пожалуйста, выберите 1 или 2.\n");
        return 1;
    }
}
