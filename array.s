	.file	"array.c"
	.text
	.p2align 4
	.globl	wl_afa
	.type	wl_afa, @function
wl_afa:
.LFB19:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	movq	%rdi, %r9
	movl	%r8d, %r13d
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movq	%rdx, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	movq	%rsi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movl	%ecx, %ebx
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	testq	%rdi, %rdi
	je	.L84
.L2:
	movl	%r13d, %esi
	xorl	%edx, %edx
	leaq	.L5(%rip), %rcx
	movl	%ebx, %edi
	andl	$65528, %esi
	je	.L22
	.p2align 4,,10
	.p2align 3
.L19:
	cmpl	$15, %ebx
	ja	.L3
	movslq	(%rcx,%rdi,4), %rax
	addq	%rcx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L5:
	.long	.L3-.L5
	.long	.L18-.L5
	.long	.L17-.L5
	.long	.L16-.L5
	.long	.L15-.L5
	.long	.L14-.L5
	.long	.L13-.L5
	.long	.L12-.L5
	.long	.L11-.L5
	.long	.L10-.L5
	.long	.L9-.L5
	.long	.L8-.L5
	.long	.L3-.L5
	.long	.L7-.L5
	.long	.L6-.L5
	.long	.L4-.L5
	.text
	.p2align 4,,10
	.p2align 3
.L4:
	movq	0(%rbp), %rax
	xorq	(%r12), %rax
	notq	%rax
	movq	%rax, (%r9)
	.p2align 4,,10
	.p2align 3
.L3:
	addl	$8, %edx
	movzwl	%dx, %eax
	cmpl	%esi, %eax
	jl	.L19
.L22:
	movl	%r13d, %eax
	andl	$2, %eax
	testb	$4, %r13b
	jne	.L85
.L21:
	testw	%ax, %ax
	jne	.L86
.L53:
	andl	$1, %r13d
	jne	.L87
.L56:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movq	%r9, %rax
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L13:
	.cfi_restore_state
	movq	(%r9), %rax
	orq	0(%rbp), %rax
	notq	%rax
	movq	%rax, (%r9)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L17:
	movq	0(%rbp), %rax
	orq	%rax, (%r9)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L18:
	movq	0(%rbp), %rax
	andq	%rax, (%r9)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L15:
	notq	(%r9)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L16:
	movq	0(%rbp), %rax
	xorq	%rax, (%r9)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L14:
	movq	(%r9), %rax
	andq	0(%rbp), %rax
	notq	%rax
	movq	%rax, (%r9)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L9:
	movq	0(%rbp), %rax
	orq	(%r12), %rax
	movq	%rax, (%r9)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L10:
	movq	0(%rbp), %rax
	andq	(%r12), %rax
	movq	%rax, (%r9)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L11:
	movq	0(%rbp), %rax
	movq	%rax, (%r9)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L12:
	movq	(%r9), %rax
	xorq	0(%rbp), %rax
	notq	%rax
	movq	%rax, (%r9)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L7:
	movq	0(%rbp), %rax
	andq	(%r12), %rax
	notq	%rax
	movq	%rax, (%r9)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L6:
	movq	0(%rbp), %rax
	orq	(%r12), %rax
	notq	%rax
	movq	%rax, (%r9)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L8:
	movq	0(%rbp), %rax
	xorq	(%r12), %rax
	movq	%rax, (%r9)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L87:
	cmpl	$15, %ebx
	ja	.L56
	leaq	.L71(%rip), %rdx
	movslq	(%rdx,%rbx,4), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L71:
	.long	.L56-.L71
	.long	.L57-.L71
	.long	.L59-.L71
	.long	.L60-.L71
	.long	.L55-.L71
	.long	.L61-.L71
	.long	.L62-.L71
	.long	.L63-.L71
	.long	.L64-.L71
	.long	.L65-.L71
	.long	.L66-.L71
	.long	.L67-.L71
	.long	.L56-.L71
	.long	.L68-.L71
	.long	.L69-.L71
	.long	.L70-.L71
	.text
	.p2align 4,,10
	.p2align 3
.L86:
	cmpl	$15, %ebx
	ja	.L53
	leaq	.L54(%rip), %rdx
	movl	%ebx, %eax
	movslq	(%rdx,%rax,4), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L54:
	.long	.L53-.L54
	.long	.L40-.L54
	.long	.L41-.L54
	.long	.L42-.L54
	.long	.L38-.L54
	.long	.L43-.L54
	.long	.L44-.L54
	.long	.L45-.L54
	.long	.L46-.L54
	.long	.L47-.L54
	.long	.L48-.L54
	.long	.L49-.L54
	.long	.L53-.L54
	.long	.L50-.L54
	.long	.L51-.L54
	.long	.L52-.L54
	.text
	.p2align 4,,10
	.p2align 3
.L85:
	cmpl	$15, %ebx
	ja	.L21
	leaq	.L24(%rip), %rcx
	movl	%ebx, %edx
	movslq	(%rcx,%rdx,4), %rdx
	addq	%rcx, %rdx
	jmp	*%rdx
	.section	.rodata
	.align 4
	.align 4
.L24:
	.long	.L21-.L24
	.long	.L37-.L24
	.long	.L36-.L24
	.long	.L35-.L24
	.long	.L34-.L24
	.long	.L33-.L24
	.long	.L32-.L24
	.long	.L31-.L24
	.long	.L30-.L24
	.long	.L29-.L24
	.long	.L28-.L24
	.long	.L27-.L24
	.long	.L21-.L24
	.long	.L26-.L24
	.long	.L25-.L24
	.long	.L23-.L24
	.text
	.p2align 4,,10
	.p2align 3
.L84:
	movzwl	%r8w, %edi
	call	malloc@PLT
	movq	%rax, %r9
	jmp	.L2
.L23:
	movl	0(%rbp), %edx
	xorl	(%r12), %edx
	notl	%edx
	movl	%edx, (%r9)
	testw	%ax, %ax
	je	.L53
.L52:
	movzwl	0(%rbp), %eax
	xorw	(%r12), %ax
	andl	$1, %r13d
	notl	%eax
	movw	%ax, (%r9)
	je	.L56
.L70:
	movzbl	0(%rbp), %eax
	xorb	(%r12), %al
	notl	%eax
	movb	%al, (%r9)
	jmp	.L56
.L37:
	movl	0(%rbp), %edx
	andl	%edx, (%r9)
	testw	%ax, %ax
	je	.L53
.L40:
	movzwl	0(%rbp), %eax
	andw	%ax, (%r9)
	andl	$1, %r13d
	je	.L56
.L57:
	movzbl	0(%rbp), %eax
	andb	%al, (%r9)
	jmp	.L56
.L36:
	movl	0(%rbp), %edx
	orl	%edx, (%r9)
	testw	%ax, %ax
	je	.L53
.L41:
	movzwl	0(%rbp), %eax
	orw	%ax, (%r9)
	andl	$1, %r13d
	je	.L56
.L59:
	movzbl	0(%rbp), %eax
	orb	%al, (%r9)
	jmp	.L56
.L34:
	notl	(%r9)
	testw	%ax, %ax
	je	.L53
.L38:
	andl	$1, %r13d
	notw	(%r9)
	je	.L56
.L55:
	notb	(%r9)
	jmp	.L56
.L32:
	movl	(%r9), %edx
	orl	0(%rbp), %edx
	notl	%edx
	movl	%edx, (%r9)
	testw	%ax, %ax
	je	.L53
.L44:
	movzwl	(%r9), %eax
	orw	0(%rbp), %ax
	andl	$1, %r13d
	notl	%eax
	movw	%ax, (%r9)
	je	.L56
.L62:
	movzbl	(%r9), %eax
	orb	0(%rbp), %al
	notl	%eax
	movb	%al, (%r9)
	jmp	.L56
.L30:
	movl	0(%rbp), %edx
	movl	%edx, (%r9)
	testw	%ax, %ax
	je	.L53
.L46:
	movzwl	0(%rbp), %eax
	andl	$1, %r13d
	movw	%ax, (%r9)
	je	.L56
.L64:
	movzbl	0(%rbp), %eax
	movb	%al, (%r9)
	jmp	.L56
.L33:
	movl	(%r9), %edx
	andl	0(%rbp), %edx
	notl	%edx
	movl	%edx, (%r9)
	testw	%ax, %ax
	je	.L53
.L43:
	movzwl	(%r9), %eax
	andw	0(%rbp), %ax
	andl	$1, %r13d
	notl	%eax
	movw	%ax, (%r9)
	je	.L56
.L61:
	movzbl	(%r9), %eax
	andb	0(%rbp), %al
	notl	%eax
	movb	%al, (%r9)
	jmp	.L56
.L35:
	movl	0(%rbp), %edx
	xorl	%edx, (%r9)
	testw	%ax, %ax
	je	.L53
.L42:
	movzwl	0(%rbp), %eax
	xorw	%ax, (%r9)
	andl	$1, %r13d
	je	.L56
.L60:
	movzbl	0(%rbp), %eax
	xorb	%al, (%r9)
	jmp	.L56
.L31:
	movl	(%r9), %edx
	xorl	0(%rbp), %edx
	notl	%edx
	movl	%edx, (%r9)
	testw	%ax, %ax
	je	.L53
.L45:
	movzwl	(%r9), %eax
	xorw	0(%rbp), %ax
	andl	$1, %r13d
	notl	%eax
	movw	%ax, (%r9)
	je	.L56
.L63:
	movzbl	(%r9), %eax
	xorb	0(%rbp), %al
	notl	%eax
	movb	%al, (%r9)
	jmp	.L56
.L28:
	movl	0(%rbp), %edx
	orl	(%r12), %edx
	movl	%edx, (%r9)
	testw	%ax, %ax
	je	.L53
.L48:
	movzwl	0(%rbp), %eax
	orw	(%r12), %ax
	andl	$1, %r13d
	movw	%ax, (%r9)
	je	.L56
.L66:
	movzbl	0(%rbp), %eax
	orb	(%r12), %al
	movb	%al, (%r9)
	jmp	.L56
.L29:
	movl	0(%rbp), %edx
	andl	(%r12), %edx
	movl	%edx, (%r9)
	testw	%ax, %ax
	je	.L53
.L47:
	movzwl	0(%rbp), %eax
	andw	(%r12), %ax
	andl	$1, %r13d
	movw	%ax, (%r9)
	je	.L56
.L65:
	movzbl	0(%rbp), %eax
	andb	(%r12), %al
	movb	%al, (%r9)
	jmp	.L56
.L26:
	movl	0(%rbp), %edx
	andl	(%r12), %edx
	notl	%edx
	movl	%edx, (%r9)
	testw	%ax, %ax
	je	.L53
.L50:
	movzwl	0(%rbp), %eax
	andw	(%r12), %ax
	andl	$1, %r13d
	notl	%eax
	movw	%ax, (%r9)
	je	.L56
.L68:
	movzbl	0(%rbp), %eax
	andb	(%r12), %al
	notl	%eax
	movb	%al, (%r9)
	jmp	.L56
.L27:
	movl	0(%rbp), %edx
	xorl	(%r12), %edx
	movl	%edx, (%r9)
	testw	%ax, %ax
	je	.L53
.L49:
	movzwl	0(%rbp), %eax
	xorw	(%r12), %ax
	andl	$1, %r13d
	movw	%ax, (%r9)
	je	.L56
.L67:
	movzbl	0(%rbp), %eax
	xorb	(%r12), %al
	movb	%al, (%r9)
	jmp	.L56
.L25:
	movl	0(%rbp), %edx
	orl	(%r12), %edx
	notl	%edx
	movl	%edx, (%r9)
	testw	%ax, %ax
	je	.L53
.L51:
	movzwl	0(%rbp), %eax
	orw	(%r12), %ax
	andl	$1, %r13d
	notl	%eax
	movw	%ax, (%r9)
	je	.L56
.L69:
	movzbl	0(%rbp), %eax
	orb	(%r12), %al
	notl	%eax
	movb	%al, (%r9)
	jmp	.L56
	.cfi_endproc
.LFE19:
	.size	wl_afa, .-wl_afa
	.p2align 4
	.globl	afab
	.type	afab, @function
afab:
.LFB20:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	%ecx, %ebx
	movq	%rsi, %r9
	movl	%edx, %r10d
	movl	%ecx, %r11d
	andl	$65528, %ebx
	je	.L89
	leal	-16(%r10), %r8d
	xorl	%edx, %edx
	leaq	.L92(%rip), %rcx
	movq	%r8, %rsi
	.p2align 4,,10
	.p2align 3
.L108:
	cmpl	$7, %esi
	ja	.L90
	movslq	(%rcx,%r8,4), %rax
	addq	%rcx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L92:
	.long	.L99-.L92
	.long	.L98-.L92
	.long	.L97-.L92
	.long	.L96-.L92
	.long	.L95-.L92
	.long	.L94-.L92
	.long	.L93-.L92
	.long	.L91-.L92
	.text
	.p2align 4,,10
	.p2align 3
.L93:
	cmpq	$0, (%rdi)
	jne	.L90
	cmpq	$0, (%r9)
	jne	.L90
.L193:
	xorl	%eax, %eax
.L88:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L94:
	.cfi_restore_state
	cmpq	$0, (%rdi)
	je	.L193
	cmpq	$0, (%r9)
	sete	%al
	jmp	.L105
	.p2align 4,,10
	.p2align 3
.L95:
	cmpq	$0, (%rdi)
	sete	%al
.L105:
	testb	%al, %al
	jne	.L193
.L90:
	addl	$8, %edx
	movzwl	%dx, %eax
	cmpl	%ebx, %eax
	jl	.L108
.L89:
	testb	$4, %r11b
	je	.L109
	leal	-16(%r10), %eax
	cmpl	$7, %eax
	ja	.L109
	leaq	.L111(%rip), %rdx
	movslq	(%rdx,%rax,4), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L111:
	.long	.L118-.L111
	.long	.L117-.L111
	.long	.L116-.L111
	.long	.L115-.L111
	.long	.L114-.L111
	.long	.L113-.L111
	.long	.L112-.L111
	.long	.L110-.L111
	.text
	.p2align 4,,10
	.p2align 3
.L99:
	cmpq	$0, (%rdi)
	setne	%al
	jmp	.L105
	.p2align 4,,10
	.p2align 3
.L91:
	cmpq	$0, (%rdi)
	movq	(%r9), %rax
	je	.L106
.L208:
	testq	%rax, %rax
	setne	%al
	jmp	.L105
	.p2align 4,,10
	.p2align 3
.L97:
	cmpq	$0, (%rdi)
	jne	.L193
	cmpq	$0, (%r9)
	setne	%al
	jmp	.L105
	.p2align 4,,10
	.p2align 3
.L98:
	cmpq	$0, (%rdi)
	je	.L90
	cmpq	$0, (%r9)
	je	.L90
	xorl	%eax, %eax
	jmp	.L88
	.p2align 4,,10
	.p2align 3
.L96:
	cmpq	$0, (%rdi)
	movq	(%r9), %rax
	je	.L208
.L106:
	testq	%rax, %rax
	sete	%al
	jmp	.L105
.L110:
	movl	(%rdi), %edx
	movl	(%r9), %eax
	testl	%edx, %edx
	je	.L126
.L209:
	testl	%eax, %eax
	setne	%dl
.L124:
	xorl	%eax, %eax
	testb	%dl, %dl
	jne	.L88
	.p2align 4,,10
	.p2align 3
.L109:
	testb	$2, %r11b
	je	.L128
	leal	-16(%r10), %eax
	cmpl	$7, %eax
	ja	.L128
	leaq	.L130(%rip), %rdx
	movslq	(%rdx,%rax,4), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L130:
	.long	.L137-.L130
	.long	.L136-.L130
	.long	.L135-.L130
	.long	.L134-.L130
	.long	.L133-.L130
	.long	.L132-.L130
	.long	.L131-.L130
	.long	.L129-.L130
	.text
.L118:
	movl	(%rdi), %ecx
	xorl	%eax, %eax
	testl	%ecx, %ecx
	jne	.L88
	testb	$2, %r11b
	je	.L128
.L137:
	cmpw	$0, (%rdi)
	setne	%dl
.L143:
	xorl	%eax, %eax
	testb	%dl, %dl
	jne	.L88
.L128:
	andl	$1, %r11d
	movl	$1, %eax
	je	.L88
	subl	$16, %r10d
	cmpl	$7, %r10d
	ja	.L88
	leaq	.L148(%rip), %rdx
	movslq	(%rdx,%r10,4), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L148:
	.long	.L155-.L148
	.long	.L154-.L148
	.long	.L153-.L148
	.long	.L152-.L148
	.long	.L151-.L148
	.long	.L150-.L148
	.long	.L149-.L148
	.long	.L147-.L148
	.text
.L112:
	movl	(%rdi), %esi
	testl	%esi, %esi
	jne	.L125
	movl	(%r9), %ecx
	xorl	%eax, %eax
	testl	%ecx, %ecx
	je	.L88
.L125:
	testb	$2, %r11b
	je	.L128
.L131:
	cmpw	$0, (%rdi)
	jne	.L144
	xorl	%eax, %eax
	cmpw	$0, (%r9)
	je	.L88
.L144:
	andl	$1, %r11d
	je	.L213
.L149:
	cmpb	$0, (%rdi)
	movl	$1, %eax
	jne	.L88
.L212:
	cmpb	$0, (%r9)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	setne	%al
	ret
.L116:
	.cfi_restore_state
	movl	(%rdi), %esi
	xorl	%eax, %eax
	testl	%esi, %esi
	jne	.L88
	movl	(%r9), %ecx
	testl	%ecx, %ecx
	je	.L109
	jmp	.L88
.L115:
	movl	(%rdi), %edx
	movl	(%r9), %eax
	testl	%edx, %edx
	je	.L209
.L126:
	testl	%eax, %eax
	sete	%dl
	jmp	.L124
.L114:
	movl	(%rdi), %edx
	xorl	%eax, %eax
	testl	%edx, %edx
	je	.L88
	testb	$2, %r11b
	je	.L128
.L133:
	cmpw	$0, (%rdi)
	sete	%dl
	jmp	.L143
.L113:
	movl	(%rdi), %ebx
	xorl	%eax, %eax
	testl	%ebx, %ebx
	je	.L88
	movl	(%r9), %r8d
	testl	%r8d, %r8d
	jne	.L109
	jmp	.L88
.L117:
	movl	(%rdi), %ebx
	testl	%ebx, %ebx
	je	.L121
	movl	(%r9), %r8d
	xorl	%eax, %eax
	testl	%r8d, %r8d
	jne	.L88
.L121:
	testb	$2, %r11b
	je	.L128
.L136:
	cmpw	$0, (%rdi)
	je	.L139
	xorl	%eax, %eax
	cmpw	$0, (%r9)
	jne	.L88
.L139:
	andl	$1, %r11d
	jne	.L154
.L213:
	movl	$1, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L129:
	.cfi_restore_state
	cmpw	$0, (%rdi)
	movzwl	(%r9), %eax
	je	.L145
.L210:
	testw	%ax, %ax
	setne	%dl
	jmp	.L143
.L132:
	xorl	%eax, %eax
	cmpw	$0, (%rdi)
	je	.L88
	cmpw	$0, (%r9)
	sete	%dl
	jmp	.L143
.L134:
	cmpw	$0, (%rdi)
	movzwl	(%r9), %eax
	je	.L210
.L145:
	testw	%ax, %ax
	sete	%dl
	jmp	.L143
.L135:
	xorl	%eax, %eax
	cmpw	$0, (%rdi)
	jne	.L88
	cmpw	$0, (%r9)
	setne	%dl
	jmp	.L143
.L150:
	xorl	%eax, %eax
	cmpb	$0, (%rdi)
	jne	.L212
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L147:
	.cfi_restore_state
	cmpb	$0, (%rdi)
	movzbl	(%r9), %eax
	je	.L163
.L214:
	testb	%al, %al
	setne	%al
.L164:
	xorl	$1, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L151:
	.cfi_restore_state
	cmpb	$0, (%rdi)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	setne	%al
	ret
.L152:
	.cfi_restore_state
	cmpb	$0, (%rdi)
	movzbl	(%r9), %eax
	je	.L214
.L163:
	testb	%al, %al
	sete	%al
	jmp	.L164
.L153:
	xorl	%eax, %eax
	cmpb	$0, (%rdi)
	jne	.L88
.L211:
	cmpb	$0, (%r9)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	sete	%al
	ret
.L155:
	.cfi_restore_state
	cmpb	$0, (%rdi)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	sete	%al
	ret
.L154:
	.cfi_restore_state
	cmpb	$0, (%rdi)
	movl	$1, %eax
	jne	.L211
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE20:
	.size	afab, .-afab
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
