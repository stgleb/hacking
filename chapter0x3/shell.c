#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char buffer[64];

	if(argv[1] != 0) {
		strcpy(buffer, argv[1]);
	}
}
