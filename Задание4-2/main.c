#include "myheader.h"

int main() {
	puts("Введите размер массива:");
	size_t size = input_positive();
	create_array(size);
	printf("Выберите способ заполнения массива:\n%d - случайными числами\n%d - вводом с клавиатуры\n", (int)random, (int)keyboard);
	enum method choice = (enum method)input_positive();
	switch (choice) {
	case random:
		random_input(array, size);
		puts("Массив: ");
		print_array(array, size);
		break;
	case keyboard:
		keyboard_input(array, size);
		break;
	default:
		free(array);
		errno = EIO;
		perror("Введены неверные значения\n");
		exit(1);
	}
	change(array, size);
	delete_elements(array, size);
	create_array(size);
	array_filling(array, new_array, size);
	puts("\nПолученный массив A: \n");
	print_array(new_array, size);
	free(array);
	free(new_array);

	return 0;
}
