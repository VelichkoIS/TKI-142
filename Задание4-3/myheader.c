#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <errno.h>
#include <time.h>
#include <math.h>

enum array_filling {
	RANDOM,
	STDIO_INPUT
};

/**
* @brief принимает целочисленное число из stdin
* @return целочисленное число из stdin
*/
int input(void);

/**
* @brief принимает целочисленное неотрицательное число из stdin
* @return целочисленное неотрицательное число из stdin
*/
size_t positive_input(void);

/**
* @brief проверяет выделилась ли память под массив
* @param array указатель на массив
*/
void check_array(const long long* array);

/**
* @brief создает массив
* @param size размер массива
* @return массив
*/
long long* create_array(const size_t size);

/**
* @brief создает двумерный массив
* @param rows количество массивов(строк) в двумерном массиве
* @param columns количество элементов каждого массива(столбцов) в двумерном массиве
* @return двумерный массив
*/
long long** create_2d_array(const size_t rows, const size_t columns);

/**
* @brief проверяет что наибольшее значение интервала больше наимешьшего
* @param min наимешьшее значение интервала
* @param max наибольшее щначение интервала
*/
void check_range(const long long min, const long long max);

/**
* @brief заполняет массив случайными числами
* @param array указатель на массив
* @param min наимешьшее значение интервала возможных значений элемента массива
* @param max наибольшее щначение интервала возможных значений элемента массива
* @param columns количество элементов массива
*/
void random_array_filling(long long* array, const long long min, const long long max, const size_t columns);

/**
* @brief заполняет двумерный массив случайными числами
* @param array двойной указатель на массив
* @param rows количество массивов(строк) в двумерном массиве
* @param columns количество элементов каждого массива(столбцов) в двумерном массиве
*/
void random_2d_array_filling(long long** array, const size_t rows, const size_t columns);

/**
* @brief заполняет массив значениями из stdin
* @param array указатель на массив
* @param columns количество элементов каждого массива(столбцов) в двумерном массиве
*/
void input_array_filling(long long* array, const size_t columns);

/**
* @brief заполняет двумерный массив значениями из stdin
* @param array двойной указатель на массив
* @param rows количество массивов(строк) в двумерном массиве
* @param columns количество элементов каждого массива(столбцов) в двумерном массиве
*/
void input_2d_array_filling(long long** array, const size_t rows, const size_t columns);

/**
* @brief выводит содержимое массива 
* @param array указатель на массив
* @param columns количество элементов каждого массива(столбцов) в двумерном массиве
*/
void print_array(const long long* array, const size_t columns);

/**
* @brief выводит содержимое двумерного массива
* @param array двойной указатель на массив
* @param rows количество массивов(строк) в двумерном массиве
* @param columns количество элементов каждого массива(столбцов) в двумерном массиве
*/
void print_2d_array(const long long** array, const size_t rows, const size_t columns);

/**
* @brief возводит в степень первые 3 элемента массива
* @param array указатель на массив
* @param columns количество элементов каждого массива(столбцов) в двумерном массиве
*/
void first_3_elements_to_root(long long* array, const size_t columns);

/**
* @brief возводит в степень первые 3 элемента в каждом из массивов двумерного массива
* @param array двойной указатель на массив
* @param rows количество массивов(строк) в двумерном массиве
* @param columns количество элементов каждого массива(столбцов) в двумерном массиве
*/
void first_3_columns_to_root(long long** array, const size_t rows, const size_t columns);

/**
* @brief считает количество нечетных элементов(массивов) в двумерном массиве
* @param array двойной указатель на массив
* @param rows количество массивов(строк) в двумерном массиве
* @return количество нечетных элементов(массивов)
*/
size_t odd_rows_count(long long** array, const size_t rows);

/**
* @brief копирует содержимое элемента двумерного массива
* @param new_array элемент нового двумерного массива
* @param array элемент двумерного массива
* @param columns количество элементов каждого массива(столбцов) в двумерном массиве
*/
void copy_row(long long* new_array, const long long* array, const size_t columns);

/**
* @brief создвет новый массив где после каждого нечетного элемента(строка матрици) вставлется первый элемент(строка матрици) старого массива
* @param array двойной указатель на массив
* @param rows количество массивов(строк) в двумерном массиве
* @param количество элементов каждого массива(столбцов) в двумерном массиве
* @return новый массив
*/
long long** create_an_extended_2d_array(long long** array, const size_t rows, const size_t new_rows, const size_t columns);

/**
* @brief освобождает выделенную память для элементов двумерого массива(массивов)
* @param array двойной указатель на массив
* @param rows количество массивов(строк) в двумерном массиве
*/
void free_2d_array(long long** array, const size_t rows);
