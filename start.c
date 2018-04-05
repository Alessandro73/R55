#include <stdio.h>

int main(int argc, char *argv[]) {

	int *ptr_n_args;

	ptr_n_args = &argc;

	printf("Numero parametri ricevuti: %d\n", *ptr_n_args);

}
