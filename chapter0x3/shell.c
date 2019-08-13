#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/*
	build: gcc -g shell.c -fno-stack-protector -m32 -z execstack -o shell

	run: SHELLCODE=$(python shell.py) ./shell $(python padding.py)
*/
void func(char *password) {
	char buffer[64];
	strcpy(buffer, password);
	return;
}

int main(int argc, char **argv)
{
	if(argv[1] != 0) {
		func(argv[1]);
	}
}
