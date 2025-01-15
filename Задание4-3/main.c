#include "myheader.h"

int main(void) {
	setlocale(LC_ALL, "");
	puts("Введите количество массивов(строк) в двумерном массиве");
	const size_t rows = positive_input();
	puts("Введите количество элементов каждого массива(столбцов) в двумерном массиве");
	const size_t columns = positive_input();
	long long** array = create_2d_array(rows, columns);
	printf("Выберите способ заполнения массива\n%d - случайными числами\n%d - ручным вводом\n", RANDOM, STDIO_INPUT);
	enum array_filling choice = input();
	switch (choice) {
	case RANDOM:
		random_2d_array_filling(array, rows, columns);
		puts("Массив: ");
		print_2d_array(array, rows, columns);
		break;
	case STDIO_INPUT:
		input_2d_array_filling(array, rows, columns);
		puts("Массив: ");
		print_2d_array(array, rows, columns);
		break;
	default :
		errno = EINVAL;
		perror("Ошибка, введено недопустимое значение");
		exit(EXIT_FAILURE);
	}
	first_3_columns_to_root(array, rows, columns);
	puts("Все элементы первых трех столбцов были возведены в квадрат:");
	print_2d_array(array, rows, columns);
	const size_t new_rows = odd_rows_count(array, rows);
	long long** extended_array = create_an_extended_2d_array(array, rows, new_rows, columns);
	puts("После каждой строки с нечетным индексом была добавлена первая строка:");
	print_2d_array(extended_array, new_rows, columns);
	free_2d_array(array, rows);
	free_2d_array(extended_array, new_rows);
	return EXIT_SUCCESS;
}
