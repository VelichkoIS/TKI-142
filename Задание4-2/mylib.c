#include "myheader.h"

void change(int* array, size_t size) {
	int index = index_last_negative(array, size);
	if (index == -1) {
		puts("Невозможно заменить последний отрицательный элемент массива предпоследним элементом массива. В массиве нет отрицательных элентов\n");
	}
	else {
		swap(array, index, size - 2);
		puts("\nМассив после замены: \n");
		print_array(array, size);
	}
}

void delete_elements(int* array, size_t size) {
	int count = count_remove_elements(array, size);
	if (count == 0) {
		puts("\nНет улементов для удаления: \n");
	}
	else {
		array = remove_elements(array, size);
		size = count;
		puts("\nМассив после удаления элементов,первая цифра которых четная: \n");
		print_array(array, size);
	}
}

double input(void) {
	double value = 0.0;
	int s = scanf_s("%lf", &value);
	if (s != 1) {
		errno = EIO;
		perror("Ошибка, не числовое значение\n");
		exit(1);
	}
	return value;
}


size_t input_positive() {
	int s = input();
	if (s < 0) {
		errno = EIO;
		perror("Ошибка, число отрицательное\n");
		exit(EXIT_FAILURE);

	}
	return (size_t)s;
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
	for (size_t i = 0; i < size; i++) {
		array[i] = input();
	}
}




void print_array(int const* array, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		printf("%d ", array[i]);
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


int index_last_negative(int* const array, const size_t size) {
	int index = -1;
	for (int i = (int)size - 1; i >= 0; i--) {
		if (array[i] < 0) {
			index = i;
			break;
		}
	}
	return index;
}
void swap(int* array, const int index_first, const int index_second) {
	array[index_first] = array[index_second];
}

int first_digit(const int value) {
	int digit = value;
	for (size_t i = abs(value); i > 0; i /= 10) {
		digit = i % 10;
	}
	return digit;
}

int count_remove_elements(int* array, const size_t size) {
	int count = 0;
	for (size_t i = 0; i < size; i++) {
		if (first_digit(array[i]) % 2 != 0) {
			count++;
		}
	}
	return count;
}

void copy_array(int* new_array, int const* array, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		new_array[i] = array[i];
	}
}

int* remove_elements(int* array, const size_t size) {
	int current_index = 0;
	for (size_t i = 0; i < size; i++) {
		if (first_digit(array[i]) % 2 != 0) {

			array[current_index] = array[i];
			current_index++;
		}
	}
	int* new_array = create_array(size);
	copy_array(new_array, array, current_index);
	return new_array;

}

void array_filling(int const* array, int* new_array, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		if (i % 2 == 0) {
			new_array[i] = array[i] * array[i];
		}
		else {
			new_array[i] = 2 * array[i];
		}
	}
}

int* create_array(const size_t size) {
	int* array = (int*)malloc(size * sizeof(int));
	check_array(array);
	return array;
}
