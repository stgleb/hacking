#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to display an error message and then exit
void fatal(char *message) {
   char error_message[100];

   strcpy(error_message, "[!!] Fatal Error ");
   strncat(error_message, message, 83);
   perror(error_message);
   exit(-1);
}

// Dumps raw memory in hex bytes and printable split format
void dump(const unsigned char* data_buffer, const unsigned int length) {
    unsigned char byte;
    unsigned int i;
    unsigned int j;

    for(i=0;i < length; i++) {
        byte = data_buffer[i];
        // Display byte in hex
        printf("%02x ", data_buffer[i]);
        if((i% 16 == 15) || (i == length - 1)) {
            for(j = 0;j < 15 - (i % 16); j++)
                printf("  ");
            printf("| ");
            for(j=(i - (i % 16));j <= i; j++) {
                byte=data_buffer[j];
                if(byte > 31 && (byte < 127)) {
                    printf("%c", byte);
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
    }
}
