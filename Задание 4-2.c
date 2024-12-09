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
* @brief - выводит содержимое массива
* @param array - содержимое массива
* @param size - размер массива
*/
void print_array(int* array, const size_t size);

/**
* @brief - проверяет правильность интервала
* @param min - минимально возможное значение элемента
* @param max - максимально возможное значение элемента
*/
int check_mm(const int min, const int max);

void swap(const size_t size, int* array);

enum method {
	RANDOM,
	KEYBOARD
};

int main() {
	puts("Введите размер массива:");
	size_t size = check_size(input_p());
	int* array = (int*)malloc(size * sizeof(int));
	puts("Выберите способ заполнения массива:\n0 - случайными числами\n1 - вручную");
	enum method choice = input_p();
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
		exit(1);
	}
	swap(size, array);
	print_array(array, size);
	free(array);
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

size_t input_p() {
	int value = 0.0;
	int s = scanf_s("%d", &value);
	if (s != 1 || s < 0) {
		errno = EIO;
		perror("Ошибка, не числовое значение или число отрицательное\n");
		exit(1);
	}
	return value;
}

size_t check_size(const size_t size) {
	if (size > 50) {
		errno = EIO;
		perror("Указано слишком большое число элементов массива\n");
		exit(1);
	}
	return size;
}

int r_input(int* array, const size_t size) {
	srand(time(NULL));
	puts("Введите минимальное значение элемента массива:");
	int min = input();
	puts("Введите максимальное значение элемента массива:");
	int max = input();
	check_mm(min, max);
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

void print_array(int* array, const size_t size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
}

void swap(const size_t size, int* array) {
	int temp = -1;
	int i = 0;
	for (i; i < size; i++) {
		if (array[i] < 0)
			temp = i;
	}
	if (temp < 0)
		puts("В массиве не существует отрицательных чисел");
	else
		array[temp] = array[i - 1];
}

int check_mm(const int min, const int max) {
	if (min > max) {
		errno = EIO;
		perror("Не верно указан интервал\n");
		exit(1);
	}
	return 0;
}

int get_first_digit(int number) {
	while (fabs(number) >= 10)
		number /= 10;
	return number;
}



/// <summary>
/// delete() ? 
///  1. почитать кол-во нечетных  podschet
///  2. создать массив    
///  3. занести элементы    replace
/// </summary>

	int replace(const size_t size, int* array, int* new_array, int count) {
		for (int i = 0; i < size; i++) {
			if (get_first_digit(array[i]) % 2 == 0) {
				new_array[count] = array[i];
				count++;
			}
		}
		return new_array;
	}

	int podschet(const size_t size, int* array) {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (get_first_digit(array[i]) % 2 == 0) {
				array[i] = 0;
				count++;
			}
		}
		return count;
	}

	if (new_count() > 0)
		int* new_array = (int*)malloc(new_size(size, array) * sizeof(int));
	else
		puts("В массиве нету чисел первая цифра которых четная");


	int delete(const size_t size, int* array, int* new_array) {
		int count = 0;
		podschet(size, array);
		replace(size, array, new_array, count);
	}
