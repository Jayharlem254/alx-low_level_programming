section .data
    hello_msg db "Hello, Holberton", 0
    fmt db "%s", 0
    newline db 10, 0

section .text
    global main
    extern printf

main:
    push rbp
    mov rdi, fmt
    mov rsi, hello_msg
    call printf

    mov rdi, fmt
    mov rsi, newline
    call printf

    pop rbp
    ret

