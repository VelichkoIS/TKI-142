#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>


enum method {
	random,
	keyboard
};

/**
* @brief заменяет последний отрицательный элемент массива предпоследним элементом массива.
* @param array указатель на массив
* @param size размер массива
*/
void change(int* array, size_t size);

/**
* @brief удаляет из массива все элементы, первая цифра которых четная.
* @param array указатель на массив
* @param size размер массива
*/
void delete_elements(int* array, size_t size);

/**
* @brief принимает из stdin, а затем возвращает значение переменной value
* @return числовое значение полученное из stdin
*/
double input(void);

/**
* @brief принимает из stdin, а затем возвращает значение переменной value, проверяет является ли число положительным
* @return положительное числовое значение
*/
size_t input_positive(void);

/**
* @brief заполняет массив случайно сгенерироваными числами
* @param array указатель на массив
* @param size размер массива
*/
void random_input(int* const array, const size_t size);

/**
* @brief заполняет массив из стандартного потока ввода
* @param array указатель на массив
* @param size размер массива
*/
void keyboard_input(int* array, const size_t size);


/**
* @brief выводит содержимое массива
* @param array указатель на массив
* @param size размер массива
*/
void print_array(int const* array, const size_t size);


/**
* @brief проверяет правильность интервала
* @param min минимально возможное значение элемента
* @param max максимально возможное значение элемента
*/
void check_range(const int min, const int max);

/**
* @brief проверяет выделение памяти
* @param array указатель на массив
*/
void check_array(int* const array);

/**
* @brief возвращает индекс последнего отрицательного элемента
* @param array указатель на массив
* @param size размер массива
* @return индекс последнего отрицательного
*/
int index_last_negative(int* const array, const size_t size);

/**
* @brief меняет два элемента местами в массиве
* @param array указатель на массив
* @param index_first номер первого элемента
* @param index_second номер второго элемента
*/
void swap(int* array, const int index_first, const int index_second);


/**
* @brief возвращает первую цифру числа
* @param value число
* @return возвращает первую цифру числа
*/
int first_digit(const int value);


/**
* @brief определяет количество четных элементов(которые нужно удалить)
* @param array указатель на массив
* @param size размер массива
* @return количество четных элементов(которые нужно удалить)
*/
int count_remove_elements(int* array, const size_t size);


/**
* @brief копирует элементы массива array в массив new_array
* @param array указатель на массив
* @param new_array указатель на массив
* @param size размер массива
*/
void copy_array(int* new_array, int const* array, const size_t size);

/**
* @brief определяет какие элементы должны остаться в новом массивк новый массиве и создает его
* @param array указатель на массив
* @param size размер массива
* @return новый массив состоящий из всех элементов с первой четной цифрой
*/
int* remove_elements(int* array, const size_t size);

/**
* @brief заполняет массив new_array значениями из array
* @param array указатель на массив
* @param new_array указатель на массив
* @param size размер массива
*/
void array_filling(int const* array, int* new_array, const size_t size);

/**
* @brief создает массив
* @param size размер создаваемого массива
* @return указатель на созданный массив
*/
int* create_array(const size_t size);
