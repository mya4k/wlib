	.file	"string.c"
	.text
	.p2align 4
	.globl	wl_sl
	.type	wl_sl, @function
wl_sl:
.LFB0:
	.cfi_startproc
	movq	%rdi, %rax
	testb	$3, %dil
	je	.L2
	.p2align 4,,10
	.p2align 3
.L3:
	addq	$1, %rax
	testb	$3, %al
	jne	.L3
.L2:
	movabsq	$-72340172838076673, %r8
	movq	(%rax), %rdx
	movabsq	$-9187201950435737472, %rsi
	movq	%rdx, %rcx
	addq	%r8, %rdx
	notq	%rcx
	andq	%rcx, %rdx
	testq	%rsi, %rdx
	jne	.L4
	.p2align 4,,10
	.p2align 3
.L5:
	movq	4(%rax), %rdx
	addq	$4, %rax
	leaq	(%rdx,%r8), %rcx
	notq	%rdx
	andq	%rcx, %rdx
	testq	%rsi, %rdx
	je	.L5
.L4:
	movq	%rax, %rdx
	subq	%rdi, %rdx
	cmpb	$0, (%rax)
	movl	%edx, %r8d
	je	.L1
	cmpb	$0, 1(%rax)
	leal	1(%rdx), %r8d
	je	.L1
	cmpb	$0, 2(%rax)
	leal	2(%rdx), %r8d
	je	.L1
	cmpb	$0, 3(%rax)
	leal	3(%rdx), %r8d
	je	.L1
	cmpb	$0, 4(%rax)
	leal	4(%rdx), %r8d
	je	.L1
	cmpb	$0, 5(%rax)
	leal	5(%rdx), %r8d
	je	.L1
	cmpb	$0, 6(%rax)
	leal	7(%rdx), %r8d
	je	.L18
.L1:
	movl	%r8d, %eax
	ret
.L18:
	leal	6(%rdx), %r8d
	jmp	.L1
	.cfi_endproc
.LFE0:
	.size	wl_sl, .-wl_sl
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
