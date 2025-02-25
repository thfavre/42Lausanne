global ft_strcpy

section .text

ft_strcpy:
	; rdi : char *dest
	; rsi : char *src

    mov rcx, 0      ; Initialize counter to 0
    jmp .cpy

.cpy:


	mov [rdi+ rcx], rsi


	cmp byte [rsi + rcx], 0 ; Check if current byte is null terminator
    je .end

	inc rcx

	jmp .cpy

.end:
	mov rax, rdi
    ret                  ; Return length (in rax)
