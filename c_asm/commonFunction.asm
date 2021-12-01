;------------------------------------------------------------------------------
; commonFunction.asm - единица компиляции, вбирающая функции вычисления периметра
;------------------------------------------------------------------------------

extern FUNC
extern OOp
extern PROCEDUR

global functionalCommon
functionalCommon:
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес треугольника
    mov eax, [rel rdi+8]
    mov ebx, 10
    div ebx
    cvtsi2sd    xmm0, eax

leave
ret

global oopCommon
oopCommon:
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес треугольника
    mov eax, [rel rdi+4]
    mov ebx, 3
    div ebx
    cvtsi2sd    xmm0, eax

leave
ret

global procedureCommon
procedureCommon:
section .text
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес треугольника
    mov eax, [rel rdi+16]
    mov ebx, 9
    div ebx
    cvtsi2sd    xmm0, eax

leave
ret

global commonL
commonL:
section .text
push rbp
mov rbp, rsp
    ; В rdi адрес фигуры
    mov eax, [rel rdi]
    cmp eax, [rel OOp]
    je .commonO
    cmp eax, [rel PROCEDUR]
    je .commonP
    cmp eax, [rel FUNC]
    je .commonF
    xor eax, eax
    cvtsi2sd    xmm0, eax
    jmp     .return
.commonF:
    ; Вычисление периметра прямоугольника
    add     rdi, 4
    call    functionalCommon
    jmp     .return
.commonP:
    add     rdi, 4
    call    procedureCommon
    jmp     .return
.commonO:
    ; Вычисление периметра треугольника
    add     rdi, 4
    call    oopCommon
.return:
leave
ret

global PerimeterSumContainer
PerimeterSumContainer:
section .data
    .sum    dq  0.0
section .text
push rbp
mov rbp, rsp


    mov rbx, rsi
    xor rcx, rcx
    movsd xmm1, [rel .sum]
.loop:
    cmp rcx, rbx
    jge .return

    mov r10, rdi
    call commonL
    addsd xmm1, xmm0
    inc rcx
    add r10, 16
    mov rdi, r10
    jmp .loop
.return:
    movsd xmm0, xmm1
leave
ret
