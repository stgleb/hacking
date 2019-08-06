#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check_authentication(char *password){
    int authenticated;
    char password_buffer[16];

    {
        int auth = 2;

    strcpy(password_buffer, password);

    if(strcmp(password_buffer, "password1") == 0){
        authenticated = 1;
    }
    }
    return authenticated;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <password>\n", argv[0]);
        exit(0);
    }

    if(check_authentication(argv[1])) {
        printf("Authenticated!!!\n");
    } else {
        printf("Access denied\n");
    }

    return 0;
}