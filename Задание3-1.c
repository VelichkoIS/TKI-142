#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>

/**
 * @brief Проверяет равенство двух чисел с плавающей точкой с учетом допустимой погрешности
 * @param num1 Первое число для сравнения
 * @param num2 Второе число для сравнения
 */
bool equality_check(const double num1, const double num2);

/**
 * @brief Рассчитывает значение функции y(x) в заданной точке x
 * @param x Значение x
 */
double get_function(const double x);

/**
 * @brief Проверяет, больше ли значение финиша, нежели значение старта
 * @param start Значение начала интервала
 * @param finish Значение конца интервала
 */
void start_finish_check(const double start, const double finish);

/**
 * @brief Проверяет шаг на положительность
 * @param step Шаг табуляции
 */
void check_step(double step);

/**
 * @brief Проверяет введённое значение на корректность для шага
 * @param value Введённое значение
 */
double input_check(double value);

/**
 * @brief Считывает вещественное число от пользователя
 */
double input(void);

/**
 * @brief Печатает заголовок таблицы
 */
void print_table_header(void);

/**
 * @brief Печатает строку таблицы с конкретным значением x и соответствующим значением y
 * @param x Текущее значение x
 * @param y Значение функции в точке x
 */
void print_table_row(const double x, const double y);

/**
 * @brief Печатает нижнюю часть таблицы
 */
void print_table_footer(void);

/**
 * @brief Табулирует функцию на заданном интервале с заданным шагом
 * @param start Начало интервала
 * @param finish Конец интервала
 * @param step Шаг табуляции
 */
void tabulate_function(const double start, const double finish, const double step);

/**
 * @brief Точка входа в программу
 */
int main(void) {
    printf("Введите начало интервала: ");
    double start = input();
    printf("Введите конец интервала: ");
    double finish = input();
    start_finish_check(start, finish);

    printf("Введите шаг табуляции: ");
    double step = input_check(input());
    check_step(step);

    tabulate_function(start, finish, step);

    return 0;
}

bool equality_check(const double num1, const double num2) {
    return fabs(num1 - num2) < DBL_EPSILON;
}

void start_finish_check(const double start, const double finish) {
    if (start >= finish) {
        errno = EPERM;
        perror("Ошибка: Начало интервала должно быть меньше конца");
        exit(EXIT_FAILURE);
    }
}

void check_step(double step) {
    if (step <= DBL_EPSILON) {
        errno = EINVAL;
        perror("Ошибка: Шаг табуляции слишком мал или равен нулю");
        exit(EXIT_FAILURE);
    }
}

double input_check(double value) {
    if (value < DBL_EPSILON) {
        errno = EINVAL;
        perror("Ошибка: Шаг не может быть отрицательным");
        exit(EXIT_FAILURE);
    }
    else if (equality_check(0.0, value)) {
        errno = EINVAL;
        perror("Ошибка: Шаг не может быть равен нулю");
        exit(EXIT_FAILURE);
    }
    return value;
}

double input(void) {
    double value;
    if (scanf("%lf", &value) != 1) {
        errno = EINVAL;
        perror("Ошибка: Введено нечисловое значение");
        exit(EXIT_FAILURE);
    }
    return value;
}

double get_function(const double x) {
    if (x < 0) {
        return NAN;  
    }
    return x + cbrt(x) + (pow(x, 2.5) / 2) - 2.5;
}

void print_table_header(void) {
    printf("|     x    |     y    |\n");
}

void print_table_row(const double x, const double y) {
    if (isnan(y)) {
        printf("| %8.2lf |   Нет решения   |\n", x);
    }
    else {
        printf("| %8.2lf | %8.2lf |\n", x, y);
    }
}

void print_table_footer(void) {
    printf("+==========+==========+\n");
}

void tabulate_function(const double start, const double finish, const double step) {
    print_table_header();
    for (double x = start; x <= finish; x += step) {
        double y = get_function(x);
        print_table_row(x, y);
    }
    print_table_footer();
}
