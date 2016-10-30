global _ft_syscall
section .text
_ft_syscall:
%ifdef __APPLE__
	add rdi, 0x2000000
%endif
	mov rax, rdi
	mov rdi, rsi
	mov rsi, rdx
	mov rdx, rcx
	mov r10, r8
	mov r8, r9
	mov r9, [rsp + 8]
	syscall
	ret
