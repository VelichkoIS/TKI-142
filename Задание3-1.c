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
 * @return Возвращает true, если числа равны в пределах допустимой погрешности; иначе false
 */
bool equality_check(const double num1, const double num2);

/**
 * @brief Рассчитывает значение функции y(x) в заданной точке x
 * @param x Значение x
 * @return Значение функции y(x) в заданной точке x или NaN, если вычисление невозможно
 */
double get_function(const double x);

/**
 * @brief Проверяет, больше ли значение финиша, нежели значение старта
 * @param start Значение начала интервала
 * @param finish Значение конца интервала
 */
void start_finish_check(const double start, const double finish);

/**
 * @brief Проверяет число с плавающей точкой (шаг)
 * на предмет равенства или слишком большой близости к нулю
 */
void check_step(double step);

/**
 * @brief Проверяет введённое значение на корректность
 * @details Эта функция не разрешает ввод отрицательных чисел и нуля для шага интервала
 */
double input_check(double value);

/**
 * @brief Считывает вещественное число
 * @return Вещественное число
 */
double input(void);

/**
 * @brief Точка входа в программу
 * @return \c 0 в случае выполнения без ошибок 
 */
int main(void) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    puts("Введите начало интервала:");
    double start = input();
    puts("Введите конец интервала: ");
    double finish = input();
    start_finish_check(start, finish);
    puts("Введите шаг табуляции:");
    double step = input_check(input());
    check_step(step);
    double crntstop = start;
    puts("----------------------------");
    printf("Интервал: [%.2lf:%.2lf]\n", start, finish);
    printf("Шаг: %.2lf\n", step);
    puts("Ниже построена таблица значений (произведена табуляция):");
    puts("+==========+==========+");
    puts("|     x    |     y    |");
    puts("+==========+==========+");
    while (crntstop <= finish) {
        double y = get_function(crntstop);
        if (isnan(y)) {
            printf("|%7.2lf   |   Нет решения  |\n", crntstop);
        } else {
            printf("|%7.2lf   |%7.2lf   |\n", crntstop, y);
        }
        crntstop += step;
    }
    puts("+==========+==========+");
    return 0;
}

bool equality_check(const double num1, const double num2) {
    return fabs(num1 - num2) < DBL_EPSILON;
}

void start_finish_check(const double start, const double finish) {
    if (start > finish) {
        errno = EPERM;
        perror("Значение начала интервала больше значения конца интервала");
        exit(EXIT_FAILURE);
    }
}

void check_step(double step) {
    if (step <= DBL_EPSILON) {
        errno = EINVAL;
        perror("Значение шага табуляции слишком мало или равно нулю");
        exit(EXIT_FAILURE);
    }
}

double input_check(double value) {
    if (value < DBL_EPSILON) {
        errno = EINVAL;
        perror("Шаг не может быть отрицателен");
        exit(EXIT_FAILURE);
    } else if (equality_check(0.0, value)) {
        errno = EINVAL;
        perror("Шаг не может быть равен 0");
        exit(EXIT_FAILURE);
    }
    return value;
}

double input(void) {
    double value;
    int result = scanf("%lf", &value);
    if (result != 1) {
        errno = EINVAL;
        perror("Введено не число");
        exit(EXIT_FAILURE);
    }
    return value;
}

double get_function(const double x) {
    if (x < 0) {
        return NAN;  // Возвращаем NaN, если вычисление невозможно
    }
    return x + cbrt(x) + (pow(x, 2.5) / 2) - 2.5;
}
