global ft_strlen

section .text

ft_strlen:
    mov rax, 0      ; Initialize length counter (rax) to 0
    jmp .loop

.loop:
    cmp byte [rdi + rax], 0 ; Check if current byte is null terminator
    je .end              ; If null, jump to end
    inc rax              ; Increment length counter
    jmp .loop

.end:
    ret                  ; Return length (in rax)
