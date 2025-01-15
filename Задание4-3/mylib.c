#include "myheader.h"

int input(void) {
	int value = 0;
	if (scanf_s("%d", &value) != 1) {
		errno = EINVAL;
		perror("Ошибка, не числовое значение");
		exit(EXIT_FAILURE);
	}
	return value;
}

size_t positive_input(void) {
	int value = input();
	if (value <= 0) {
		errno = EINVAL;
		perror("Ошибка, число не является положительным");
		exit(EXIT_FAILURE);
	}
	return (size_t)value;
}

void check_array(const long long* array) {
	if (!array) {
		errno = ENOMEM;
		perror("Ошибка выделения памяти.");
		exit(EXIT_FAILURE);
	}
}

long long* create_array(const size_t size) {
	long long* array = (long long*)malloc(size * sizeof(long long));
	check_array(array);
	return array;
}

long long** create_2d_array(const size_t rows, const size_t columns) {
	long long** array = (long long**)malloc(rows * sizeof(long long*));
	check_array(array);
	for (size_t i = 0; i < rows; i++) {
		array[i] = create_array(columns);
		check_array(array[i]);
	}
	return array;
}

void check_range(const long long min, const long long max) {
	if (min > max) {
		errno = EINVAL;
		perror("Ошибка, неправильно задан интервал");
		exit(EXIT_FAILURE);
	}
}

void random_array_filling(long long* array, const long long min, const long long max, const size_t columns) {
	for (size_t i = 0; i < columns; i++) {
		array[i] = rand() % (max - min + 1) + min;
	}
}

void random_2d_array_filling(long long** array, const size_t rows, const size_t columns) {
	 srand(time(NULL));
	 puts("Введите минимальное значение элемента массива:");
	 long long min = input();
	 puts("Введите максимальное значение элемента массива:");
	 long long max = input();
	 check_range(min, max);
	 for (size_t i = 0; i < rows; i++) {
		 random_array_filling(array[i], min, max, columns);
	 }
}

void input_array_filling(long long *array, const size_t columns) {
	for (size_t i = 0; i < columns; i++) {
		array[i] = input();
	}
}

void input_2d_array_filling(long long** array, const size_t rows, const size_t columns) {
	for (size_t i = 0; i < rows; i++) {
		input_array_filling(array[i], columns);
	}
}

void print_array(const long long* array, const size_t columns) {
	for (size_t i = 0; i < columns; i++) {
		printf("%lld ", array[i]);
	}
}

void print_2d_array(const long long** array, const size_t rows, const size_t columns) {
	for (size_t i = 0; i < rows; i++) {
		print_array(array[i], columns);
		puts("\n");
	}
}

void first_3_elements_to_root(long long* array, const size_t columns) {
	for (size_t i = 0; i < 3 && i < columns; i++) {
		array[i] *= array[i];
	}
}

void first_3_columns_to_root(long long** array, const size_t rows, const size_t columns) {
	for (size_t i = 0; i < rows; i++) {
		first_3_elements_to_root(array[i], columns);
	}
}

size_t odd_rows_count(long long** array, const size_t rows) {
		size_t new_rows = rows;
		for (size_t i = 0; i < rows; i++) {
			if (i % 2 == 0)
				new_rows++;
		}
		return new_rows;
}

void copy_row(long long* new_array, const long long* array, const size_t columns) {
	for (size_t i = 0; i < columns; i++) {
		new_array[i] = array[i];
	}
}

long long** create_an_extended_2d_array(long long** array, const size_t rows, const size_t new_rows, const size_t columns) {
	size_t current = 0;
	long long** new_array = create_2d_array(new_rows, columns);
	for (size_t i = 0; i < rows; i++) {
			copy_row(new_array[current], array[i], columns);
			current++;
			if (i % 2 == 0) {
				copy_row(new_array[current], array[0], columns);
				current++;
			}
	}
	return new_array;
}

void free_2d_array(long long** array, const size_t rows) {
	for (size_t i = 0; i < rows; i++) {
		free(array[i]);
	}
	free(array);
}
