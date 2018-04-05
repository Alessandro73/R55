#include <stdio.h>

int main(int argc, char *argv[]) {
	
	FILE *fd;

	char cnt_n_args = 0;

	int *ptr_n_args;

	char **ptr_argv;

	ptr_n_args = &argc;

	ptr_argv = argv;

	puts("R55-Versione-001");

	printf("Numero parametri ricevuti: %d\n", *ptr_n_args);

	while (*argv!='\0') {
		printf("Parametro [%d]: %s\n", cnt_n_args, *argv++);
		cnt_n_args++;
	}

	cnt_n_args = 0;

	while (*ptr_argv!='\0') {
		printf("Parametro [%d]: %s\n", cnt_n_args, *ptr_argv++);
		cnt_n_args++;
	}

	return 0;
}



