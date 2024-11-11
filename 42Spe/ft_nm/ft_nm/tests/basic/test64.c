#include <stdio.h>

#define DEFINE_test 13

int  GLOBAL_VAR_test = 14;

extern int EXTERN_test;

void funct_test(){
	printf("Hello from 64-bit ELF!\n");
}

int main() {
	int int_test = 15;
	funct_test();
	return 16;
}


// TO COMPILE: gcc test64.c -o test64
