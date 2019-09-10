BITS 32

jmp short one

two:
    ; ssize_t write(fd, buffer, count)
    pop ecx
    mov eax, 4
    mov ebx, 1
    mov edx, 15
    int 0x80

    ; exit(0) syscall
    mov eax, 1
    mov ebx, 0
    int 0x80

one:
    call two; Call back to avoid null bytes
    db "Hello, world!", 0x0a, 0x0d; String with newline and carriage return bytes