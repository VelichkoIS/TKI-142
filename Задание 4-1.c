#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* @brief - принимает значение для определения ветки в switch
* @param value - указатель на переменную значения
*/
int choice(int*);

/*
* @brief - выводит каждый элемент массива в целочисленном типе данных
* @param array - указатель на целочисленный массив
* @param n - передает количество введеных пользователем чисел
**/
void outputI(int*, int);

/**
* @brief - выводит каждый элемент массива в вещественном типе данных
* @param arrayF - указатель на вещественный массив
* @param n - передает количество введеных пользователем чисел
*/
void outputF(float*, int);

/**
* @brief - Случайно генерирует числа(запрашивает их количество у пользователя) и записывает в целочисленный массив
* @param array - указатель на целочисленный массив
* @param n - передает количество введеных пользователем чисел
* @param min - минимальное значение генерируемых чисел
* @param max - максимальное значение генерируемых чисел
*/
int case0Input(int*, int**, int, int);

/**
* @brief - запрашивает числа у пользователя(и их число)
* @param array - указатель на целочисленный массив
* @param n - передает количество введеных пользователем чисел
*/
int case1Input(int*, int**);

/**
* @brief - расчитывает сумму элементов имеющих нечетные индексы
* @param array - указатель на целочисленный массив
* @param n - передает количество введеных пользователем чисел
*/
int sum(int, int*);

/**
* @brief - Подсчитывает количество элементов массива, значения которых больше заданного числа А и кратных 5.
* @param A - указатель на переменную содержащую число с которым должны сравниваться элементы 
* @param array - указатель на целочисленный массив
* @param c - указатель на переменную содержащую значение количества элементов попадающих под свойство
* @param n - передает количество введеных пользователем чисел
*/
int count(int, int*, int*, int*);

/**
* @brief - Делит все элементы массива с четными номерами на первый элемент если первый элемент отличен от 0.
* @param arrayF - указатель на вещественный массив
* @param array - указатель на целочисленный массив
* @param n - передает количество введеных пользователем чисел
*/
void division(int, int*, float**);

int main() {
    int A, value, stop = 0, c, n, min = -10, max = 20;
    int* array = (int*)calloc(1, sizeof(int));
    float* arrayF = (float*)calloc(1, sizeof(int));

    choice(&value);

    switch (value) {
    case 0:
        case0Input(&n, &array, min, max);
        printf("Ваши числа: ");
        outputI(array, n);
        sum(n, array);
        count(n, &c, &A, array);
        if (array[0] != 0) {
            division(n, array, &arrayF);
            printf("Ваши числа после деления на первый элемент (с плавающей точкой):\n");
            outputF(arrayF, n);
        }
        free(array);
        free(arrayF);
        break;
    case 1:
        case1Input(&n, &array);
        printf("Ваши числа: ");
        outputI(array, n);
        sum(n, array);
        count(n, &c, &A, array);
        if (array[0] != 0) {
            division(n, array, &arrayF);
            printf("Ваши числа после деления на первый элемент (с плавающей точкой):\n");
            outputF(arrayF, n);
        }
        free(array);
        free(arrayF);
        break;
    }
    return 0;
}

void outputI(int* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}

void outputF(float* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
}

int choice(int* value) {
    printf("0 - случайная генерация чисел\n1 - ручной ввод\nВаш выбор: ");
    scanf_s("%d", value);
    return 0;
}

int case0Input(int* n, int** array, int min, int max) {
    srand(time(NULL));
    printf("Введите число генерируемых чисел (не больше 15): ");
    scanf_s("%d", n);
    if ((*n) > 15 || (*n) <= 0) {
        printf("Ошибка, превышение максимально возможного значения\n");
        return 1;
    }
    *array = (int*)realloc(*array, (*n) * sizeof(int));
    for (int i = 0; i < *n; i++) {
        (*array)[i] = rand() % (max - min + 1) + min;
    }
    return 0;
}

int case1Input(int* n, int** array) {
    printf("Введите количество чисел которые вы хотите ввести: ");
    scanf_s("%d", n);
    if ((*n) > 15 || (*n) <= 0) {
        printf("Ошибка, превышение максимально возможного значения\n");
        return 1;
    }
    *array = (int*)realloc(*array, (*n) * sizeof(int));
    for (int i = 0; i < *n; i++) {
        scanf_s("%d", &((*array)[i]));
    }
    return 0;
}

int sum(int n, int* array) {
    int temp = 0;
    for (int i = 1; i < n; i += 2) {
        temp += array[i];
    }
    printf("Сумма всех элементов с нечетными индексами: %d\n", temp);
    return temp;
}

int count(int n, int* c, int* A, int* array) {
    printf("Введите число (с которым будут сравниваться элементы массива): ");
    scanf_s("%d", A);
    *c = 0;
    for (int i = 0; i < n; i++) {
        if ((array[i] > *A) && (array[i] % 5 == 0)) {
            (*c)++;
        }
    }
    printf("Количество элементов массива значения которых больше %d и кратны 5: %d\n", *A, *c);
    return *c;
}

void division(int n, int* array, float** arrayF) {
    *arrayF = (float*)calloc(n, sizeof(float));
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            (*arrayF)[i] = (float)array[i] / (float)array[0];
        }
        else {
            (*arrayF)[i] = (float)array[i];
        }
    }
}
