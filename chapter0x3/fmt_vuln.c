/*
build:
	gcc -g fmt_vuln.c -fno-stack-protector -o fmt_vuln
run:
	./fmt_vuln "$(python -c 'import sys; sys.stdout.write("\x10\x50\x75\x55" + "%08x."*8)')"
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc,char* argv[]){
    char text[1024];
    static int test_val = -72;

    if(argc < 2){
        printf("Usage: %s <text to print>\n", argv[0]);
        exit(0);
    }

    strcpy(text, argv[1]);

    printf("The right way to print user provided string\n");
    printf("%s\n", text);

    printf("The wrong way to print user provided string\n");
    printf(text);

    printf("\n");

    printf("[*] test_val @ 0x%08x = %d 0x%08x\n", &test_val, test_val, test_val);
    return 0;
}
