#include <stdio.h>

int main(int argc, char *argv[]) {
	
	FILE *fd;

	char cnt_n_args = 0;

	int *ptr_n_args;

	char **ptr_argv;

	ptr_n_args = &argc;

	ptr_argv = argv;

	puts("R55-Versione-001");

	puts("Template HTML");

	puts("Sintassi: ./start <filename> <title> <body>");

	printf("Numero parametri ricevuti: %d\n", *ptr_n_args);

	while (*argv!='\0') {
		printf("Parametro [%d]: %s\n", cnt_n_args, *argv++);
		cnt_n_args++;
	}

	*ptr_argv++;

	fd = fopen(*ptr_argv, "w");

	*ptr_argv++;

	fprintf(fd, "<!DOCTYPE html>\n<html>\n\t<head>\n\t\t<meta charset=\"UTF-8\">\n\t\t<title>%s</title>\n\t</head>\n\n\t<body>\n\t\t", *ptr_argv);

	*ptr_argv++;

	fprintf(fd, "%s\n\t</body>\n\n</html>\n\n", *ptr_argv);

	fclose(fd);

  return 0;
}



