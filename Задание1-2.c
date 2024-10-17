#include <stdio.h>
#include <math.h>

/**
* @brief расчитывает значение обьема шара
*/
double Volume(double R, const double p);

/**
* @brief расчитывает площадь поверхности шара
*/
double Square(double R, const double p);

/**
* @brief точка входа функции
*/
int main() {
    double R;
    const double p = 3.14;
    printf("%s", "Пожалуйста введите радиус шара:");
    scanf_s("%lf", &R);
    printf("S: %f\nV: %f", Square(R, p), Volume(R, p));
    return 0;
}

double Volume(double R, const double p) {
    return (4.0 / 3.0) * p * pow(R, 3);
}

double Square(double R, const double p) {
    return 4 * p * pow(R, 2);
}
