#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

/**
* @brief принимает из stdin, а затем возвращает значение переменной value
* @return числовое значение полученное из stdin
*/
int input(void);

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
* @brief расчитывает сумму элементов, имеющих нечетные индексы.
* @param array указатель на массив
* @param size размер массива
* @return сумму элементов, имеющих нечетные индексы
*/
int sum(const size_t size, int* const array);

/**
* @brief расчитывает количество элементов массива, значения которых больше заданного числа А и кратных 5.
* @param array указатель на массив
* @param size размер массива
* @return количество элементов массива, значения которых больше заданного числа А и кратных 5.
*/
int count(const int A, const size_t size, int* array);

/**
* @brief делит все элементы массива с четными номерами на первый элемент (первый элемент отличен от 0).
* @param array указатель на массив
* @param size размер массива
* @param array_float указатель на массив чисел с плававющей точкой
*/
void division(const size_t size, int* array, float* array_float);

/**
* @brief выводит содержимое массива
* @param array указатель на массив
* @param size размер массива
*/
void print_array(int* array, const size_t size);

/**
* @brief выводит содержимое массива чисел с плавающей точкой
* @param array указатель на массив
* @param size размер массива
*/
void print_array_float(float* array_float, const size_t size);

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

enum method {
	RANDOM,
	KEYBOARD
};

int main() {
	puts("Введите размер массива:");
	size_t size = input_positive();
	int* array = (int*)malloc(size * sizeof(int));
	check_array(array);
	puts("Выберите способ заполнения массива:\n0 - случайными числами\n1 - вручную");
	enum method choice = (enum method)input_positive();
	switch (choice) {
	case RANDOM:
		random_input(array, size);
		puts("Массив: ");
		print_array(array, size);
		break;
	case KEYBOARD:
		keyboard_input(array, size);
		break;
	default:
		free(array);
		errno = EIO;
		perror("Введены неверные значения\n");
		exit(1);
	}
	printf("Сумма всех элементов с нечетными индексами: %d\n", sum(size, array));
	printf("Введите число A (с которым будут сравниваться элементы массива): ");
	int A = input();
	printf("Количество элементов массива значения которых больше %d и кратны 5: %d\n", A, count(A, size, array));
	float* array_float = (float*)malloc(size * sizeof(float));
	check_array(array_float);
	division(size, array, array_float);
	free(array);
	puts("Массив после деления всех элементов с четными номерами на первый элемент: ");
	print_array_float(array_float, size);
	free(array_float);
	return 0;
}


int input() {
	int value = 0.0;
	int s = scanf_s("%d", &value);
	if (s != 1) {
		errno = EIO;
		perror("Ошибка, не числовое значение\n");
		exit(1);
	}
	return value;
}

size_t input_positive() {
	size_t value = 0.0;
	int s = input();
	if (s < 0) {
		errno = EIO;
		perror("Ошибка, не числовое значение или число отрицательное\n");
		exit(1);
	}
	return value;
}

void random_input(int* const array, const size_t size) {
	srand(time(NULL));
	puts("Введите минимальное значение элемента массива:");
	int min = input();
	puts("Введите максимальное значение элемента массива:");
	int max = input();
	check_range(min, max);
	for (size_t i = 0; i < size; i++) {
		array[i] = rand() % (max - min + 1) + min;
	}
}

void keyboard_input(int* array, const size_t size) {
	for (int i = 0; i < size; i++) {
		array[i] = input();
	}
}

int sum(const size_t size, int* const array) {
	int temp = 0;
	for (int i = 1; i < size; i += 2) {
		temp += array[i];
	}
	return temp;
}

int count(const int A, const size_t size, int* array) {
	printf("Введите число A (с которым будут сравниваться элементы массива): ");;
	int c = 0;
	for (int i = 0; i < size; i++) {
		if ((array[i] > A) && (array[i] % 5 == 0)) {
			c++;
		}
	}
	return c;
}

void division(const size_t size, int* array, float* array_float) {
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			array_float[i] = (float)array[i] / (float)array[0];
		}
		else
			array_float[i] = array[i];
	}
}

void print_array(int* array, const size_t size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
}

void print_array_float(float* array_float, const size_t size) {
	for (int i = 0; i < size; i++) {
		printf("%0.2f ", array_float[i]);
	}
}

void check_range(const int min, const int max) {
	if (min > max) {
		errno = EIO;
		perror("Не верно указан интервал\n");
		exit(1);
	}
}

void check_array(int* const array) {
	if (!array) {
		perror("Ошибка: массив не выделен");
		exit(EXIT_FAILURE);
	}
}
