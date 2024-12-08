#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

/**
* @brief - принимает из stdin, а затем возвращает значение переменной value
* @var value - переменная для хранения значения того что ввели в stdin
* @var s - переменная для хранения количества символов введенных в stdin
*/
int input();

/**
* @brief - принимает из stdin, а затем возвращает значение переменной value, проверяет является ли число положительным
* @var value - переменная для хранения значения того что ввели в stdin
* @var s - переменная для хранения количества символов введенных в stdin
*/
size_t input_p();

/**
* @brief - проверяет размер массива
* @param size - размер массива
*/
size_t check_size(const size_t size);

/**
* @brief - заполняет массив случайно сгенерироваными числами
* @param array - содержимое массива
* @param size - размер массива
*/
int r_input(int* array, const size_t size);

/**
* @brief - заполняет массив из стандартного потока ввода
* @param array - содержимое массива
* @param size - размер массива
*/
int k_input(int* array, const size_t size);

/**
* @brief - Расчитывает сумму элементов, имеющих нечетные индексы.
* @param array - содержимое массива
* @param size - размер массива
*/
int sum(const size_t size, int* array);

/**
* @brief - Расчитывает количество элементов массива, значения которых больше заданного числа А и кратных 5.
* @param array - содержимое массива
* @param size - размер массива
*/
int count(const size_t size, int* array);

/**
* @brief - Делит все элементы массива с четными номерами на первый элемент (первый элемент отличен от 0).
* @param array - содержимое массива
* @param size - размер массива
* @param array_float - содержимое массива чисел с плавающей точкой
*/
void division(const size_t size, int* array, float* array_float);

/**
* @brief - выводит содержимое массива
* @param array - содержимое массива
* @param size - размер массива
*/
void print_array(int* array, const size_t size);

/**
* @brief - выводит содержимое массива чисел с плавающей точкой
* @param array - содержимое массива
* @param size - размер массива
*/
void print_array_float(float* array_float, const size_t size);

/**
* @brief - проверяет правильность интервала
* @param min - минимально возможное значение элемента
* @param max - максимально возможное значение элемента
*/
int check_mm(const int min, const int max)

enum method {
	RANDOM,
	KEYBOARD
};

int main() {
	puts("Введите размер массива:");
	size_t size = check_size(input_p());
	int* array = (int*)malloc(size * sizeof(int));
	puts("Выберите способ заполнения массива:\n0 - случайными числами\n1 - вручную");
	enum method choice  = input_p();
	switch (choice) {
	case RANDOM:
		r_input(array, size);
		puts("Массив: ");
		print_array(array, size);
		break;
	case KEYBOARD:
		k_input(array, size);
		break;
	default:
		free(array);
		errno = EIO;
		perror("Введены неверные значения\n");
		exit(EXIT_FAILURE);
	}
	sum(size, array);
	count(size, array);
	float* array_float = (float*)malloc(size * sizeof(float));
	division(size, array, array_float);
	free(array);
	puts("Массив после деления всех элементов с четными номерами на первый элемент: ");
	print_array_float(array_float, size);
	free(array_float);
}


int input() {
	int value = 0.0;
	int s = scanf_s("%d", &value);
	if (s != 1) {
		errno = EIO;
		perror("Ошибка, не числовое значение\n");
		exit(EXIT_FAILURE);
	}
	return value;
}

size_t input_p() {
	int value = 0.0;
	int s = scanf_s("%d", &value);
	if (s != 1 || s < 0) {
		errno = EIO;
		perror("Ошибка, не числовое значение или число отрицательное\n");
		exit(EXIT_FAILURE);
	}
	return value;
}

size_t check_size(const size_t size) {
	if (size > 50) {
		errno = EIO;
		perror("Указано слишком большое число элементов массива\n");
		exit(EXIT_FAILURE);
	}
	return size;
}

int r_input(int* array, const size_t size) {
	srand(time(NULL));
	puts("Введите минимальное значение элемента массива:");
	int min = input();
	puts("Введите максимальное значение элемента массива:");
	int max = input();
	check_mm;
	for (int i = 0; i < size; i++) {
		array[i] = rand() % (max - min + 1) + min;
	}
	return 0;
}

int k_input(int* array, const size_t size) {
	for (int i = 0; i < size; i++) {
		array[i] = input();
	}
}

int sum(const size_t size, int* array) {
	int temp = 0;
	for (int i = 1; i < size; i += 2) {
		temp += array[i];
	}
	printf("Сумма всех элементов с нечетными индексами: %d\n", temp);
	return temp;
}

int count(const size_t size, int* array) {
	printf("Введите число A (с которым будут сравниваться элементы массива): ");
	int A = input();
	int c = 0;
	for (int i = 0; i < size; i++) {
		if ((array[i] > A) && (array[i] % 5 == 0)) {
			c++;
		}
	}
	printf("Количество элементов массива значения которых больше %d и кратны 5: %d\n", A, c);
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
	return array_float;
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

int check_mm(const int min, const int max) {
	if (min > max) {
		errno = EIO;
		perror("Не верно указан интервал\n");
		exit(EXIT_FAILURE);
	}
}
