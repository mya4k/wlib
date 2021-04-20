	.file	"uS.c"
	.text
	.globl	uS
	.type	uS, @function
uS:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movl	%edi, -52(%rbp)
	movl	%esi, %eax
	movb	%al, -56(%rbp)
	movzbl	-56(%rbp), %eax
	andl	$3, %eax
	cmpl	$3, %eax
	je	.L2
	cmpl	$3, %eax
	jg	.L3
	cmpl	$1, %eax
	je	.L4
	cmpl	$2, %eax
	je	.L5
	jmp	.L3
.L4:
	movl	$2, %r12d
	jmp	.L6
.L5:
	movl	$8, %r12d
	jmp	.L6
.L2:
	movl	$16, %r12d
	jmp	.L6
.L3:
	movl	$10, %r12d
	nop
.L6:
	movzbl	%r12b, %edx
	movl	-52(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	dcu@PLT
	leal	-1(%rax), %ebx
	movzbl	-56(%rbp), %eax
	andl	$12, %eax
	testl	%eax, %eax
	je	.L8
	movzbl	%bl, %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	0(,%rax,8), %edx
	addl	%edx, %eax
.L8:
	movzbl	%bl, %eax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, %r15
	movl	$0, %r13d
	jmp	.L9
.L10:
	movl	-52(%rbp), %eax
	leal	48(%rax), %edx
	movsbq	%r13b, %rax
	addq	%r15, %rax
	movb	%dl, (%rax)
	movl	%r13d, %eax
	addl	$1, %eax
	movl	%eax, %r13d
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, %ebx
.L9:
	movsbl	%r13b, %r14d
	movzbl	%r12b, %edx
	movl	-52(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	dcu@PLT
	movzbl	%al, %eax
	cmpl	%eax, %r14d
	jl	.L10
	testb	%bl, %bl
	jle	.L10
	movq	%r15, %rax
	addq	$24, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	uS, .-uS
	.ident	"GCC: (GNU) 10.2.0"
	.section	.note.GNU-stack,"",@progbits
