BITS 32
; compile nasm -f elf helloworld.asm
; link    ld -m elf_i386 helloworld.o -o helloworld
; run ./helloworld
section .data; data segment
	msg db "Hello, world", 0x0a; the string with newline

section .text; code segment
	global _start; entry point for ELF linking

_start:
; syscall: write(1, msg, 14);
mov eax, 4
mov ebx, 1
mov ecx, msg
mov edx, 14
int 0x80

; sycall: exit(1)
mov eax, 1
mov ebx, 0
int 0x80
