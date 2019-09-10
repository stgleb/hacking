; build nasm  helloworld2.asm
; link ld -m i386linux  helloworld2.o -o helloworld2
; run ./helloworld2

BITS 32

    call mark_below ; call function
    db "Hello, world!", 0x0a, 0x0d; string terminated  by EOL


    mark_below:
        ; pop string addr from the stack
        pop ecx
        mov eax, 4
        mov ebx, 1
        mov edx, 15
        ; execute write(1, db, 15)
        int 0x80

        ; call exit(1)
        mov eax, 1
        mov ebx, 0
        int 0x80