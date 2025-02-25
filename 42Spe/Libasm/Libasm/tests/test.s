global _start ; so the assembler know where the code starts

section .text

_start:
    ; write syscall
    mov rax, 1        ; write
    mov rdi, 1        ; file descriptor (stdout)
    mov rsi, msg ;     address of message
    mov rdx, msglen        ; length of the message
    syscall           ; invoke the syscall


    ;lea rdi, [list] ; load data from stack into register (load the first data (ex. 4) into r0)

    ; exit syscall
    mov rax, 60       ; syscall number for exit (60 for x86_64)
    mov rdi, 0        ; exit code
    syscall           ; invoke the syscall

section .data
  msg: db "Hello, world!", 10 ; 10 for new line character db=1 byte
  msglen equ $-msg

  ;list:
  ;  dd 4, 6, -9, 1, 0, 2, -3



; In the CPU there are some register (= some fast (64bits) variables (ex. rdi, rsi, r8,...))
; mov rdi, 8 (move the number 8 in the register rdi)
; mov rdi, rsi (move the number in rsi in rdi)

; mov rdi, qword ptr [rsi] (Load : moves the 64-bit value located at the memory address pointed to by the rsi register into the rdi register.)
; (qword ptr=8bytes(64bits), dword ptr=4bytes, word ptr=2bytes, byte ptr=1byte)
; !! IN nasm qword ptr=dq, dword ptr=dd, word ptr=dw byte ptr=db
; mov qword ptr [rsi], rdi (Store : takes value from register and put them into memory)

; je = jump if equal 0

;  %rax by convension stores function's return value
