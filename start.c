#include <stdio.h>

int main(int argc, char *argv[]) {

	char cnt_n_args = 0;

	int *ptr_n_args;

	ptr_n_args = &argc;

	printf("Numero parametri ricevuti: %d\n", *ptr_n_args);

	while (*argv!='\0') {
		cnt_n_args++;
		printf("Parametro [%d]: %s\n", cnt_n_args, *argv++);
	}

}
