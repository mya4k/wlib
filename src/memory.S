	.file	"memory.c"
	.text
.Ltext0:
	.local	heap
	.comm	heap,8,8
	.local	pagesize
	.comm	pagesize,8,8
	.data
	.align 4
	.type	dev_zero, @object
	.size	dev_zero, 4
dev_zero:
	.long	-1
	.text
	.type	_minit, @function
_minit:
.LFB6:
	.file 1 "src/memory.c"
	.loc 1 95 20
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	.loc 1 98 9
	movl	$0, %edi
	call	sbrk@PLT
	.loc 1 98 7
	movq	%rax, heap(%rip)
	.loc 1 101 13
	movl	$30, %edi
	call	sysconf@PLT
	.loc 1 101 11
	movq	%rax, pagesize(%rip)
	.loc 1 102 1
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	_minit, .-_minit
	.globl	wl_mal
	.type	wl_mal, @function
wl_mal:
.LFB7:
	.loc 1 114 22
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
.L3:
	.loc 1 117 6
	movq	pagesize(%rip), %rax
	.loc 1 117 5
	testq	%rax, %rax
	je	.L4
	.loc 1 119 6
	cmpq	$0, -56(%rbp)
	je	.L5
	.loc 1 123 9
	addq	$8, -56(%rbp)
	.loc 1 126 7
	cmpq	$1048575, -56(%rbp)
	ja	.L6
.LBB2:
	.loc 1 127 19
	movl	$0, %edi
	call	sbrk@PLT
	movq	%rax, -40(%rbp)
	.loc 1 131 10
	movq	$0, -32(%rbp)
	.loc 1 133 10
	movq	$0, -24(%rbp)
.LBB3:
	.loc 1 142 10
	movq	heap(%rip), %rax
	movq	%rax, -16(%rbp)
	.loc 1 138 5
	jmp	.L7
.L16:
	.loc 1 148 18
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	shrq	%rax
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	cmpq	%rax, %rdx
	jnb	.L8
	.loc 1 148 18 is_stmt 0 discriminator 1
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	shrq	%rax
	movq	%rax, %rdx
	movabsq	$-9223372036854775808, %rax
	andq	%rdx, %rax
	jmp	.L9
.L8:
	.loc 1 148 18 discriminator 2
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	shrq	%rax
	movq	%rax, %rdx
	movq	heap(%rip), %rax
	movq	%rax, %rcx
	movabsq	$-9223372036854775808, %rax
	andq	%rcx, %rax
	orq	%rdx, %rax
.L9:
	.loc 1 148 16 is_stmt 1 discriminator 4
	movq	%rax, -8(%rbp)
	.loc 1 150 9 discriminator 4
	movq	-32(%rbp), %rax
	cmpq	-56(%rbp), %rax
	jnb	.L10
	.loc 1 154 11
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	andl	$1, %eax
	.loc 1 154 10
	testb	%al, %al
	je	.L11
	.loc 1 154 40 discriminator 1
	movq	$0, -32(%rbp)
	jmp	.L12
.L11:
	.loc 1 157 27
	movq	-16(%rbp), %rdx
	.loc 1 157 25
	movq	-8(%rbp), %rax
	subq	%rdx, %rax
	.loc 1 157 12
	addq	%rax, -32(%rbp)
	.loc 1 158 14
	movq	-8(%rbp), %rax
	movq	%rax, -24(%rbp)
	jmp	.L12
.L10:
	.loc 1 162 22
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	shrq	%rax
	.loc 1 162 17
	cmpq	%rax, -24(%rbp)
	jbe	.L13
	.loc 1 162 22 discriminator 1
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	shrq	%rax
	movq	%rax, %rdx
	movabsq	$-9223372036854775808, %rax
	andq	%rdx, %rax
	jmp	.L14
.L13:
	.loc 1 162 22 is_stmt 0 discriminator 2
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	shrq	%rax
	movq	%rax, %rdx
	movq	heap(%rip), %rax
	movq	%rax, %rcx
	movabsq	$-9223372036854775808, %rax
	andq	%rcx, %rax
	orq	%rdx, %rax
.L14:
	.loc 1 162 15 is_stmt 1 discriminator 4
	movq	%rax, -40(%rbp)
	.loc 1 163 7 discriminator 4
	jmp	.L15
.L12:
	.loc 1 146 8
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
.L7:
	.loc 1 144 8
	movq	-16(%rbp), %rax
	cmpq	-40(%rbp), %rax
	jb	.L16
.LBE3:
	.loc 1 168 19
	movl	$0, %edi
	call	sbrk@PLT
	.loc 1 168 11
	movq	%rax, -24(%rbp)
	.loc 1 169 20
	movq	pagesize(%rip), %rax
	movq	%rax, %rsi
	movq	-56(%rbp), %rax
	movl	$0, %edx
	divq	%rsi
	movq	%rax, %rsi
	movq	pagesize(%rip), %rax
	movq	%rax, %rcx
	movq	-56(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rdx, %rax
	testq	%rax, %rax
	setne	%al
	movzbl	%al, %eax
	leaq	(%rsi,%rax), %rdx
	movq	pagesize(%rip), %rax
	imulq	%rdx, %rax
	.loc 1 169 15
	movq	%rax, %rdi
	call	sbrk@PLT
	movq	%rax, -40(%rbp)
.L15:
	.loc 1 170 12
	movq	-24(%rbp), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -32(%rbp)
	.loc 1 176 6
	movq	-24(%rbp), %rax
	.loc 1 176 33
	movzbl	(%rax), %edx
	orl	$1, %edx
	movb	%dl, (%rax)
	.loc 1 180 6
	movq	-24(%rbp), %rax
	.loc 1 180 32
	movabsq	$9223372036854775807, %rdx
	andq	-32(%rbp), %rdx
	leaq	(%rdx,%rdx), %rcx
	movq	(%rax), %rdx
	andl	$1, %edx
	orq	%rcx, %rdx
	movq	%rdx, (%rax)
	.loc 1 184 6
	movq	-32(%rbp), %rax
	.loc 1 184 31
	movzbl	(%rax), %edx
	andl	$-2, %edx
	movb	%dl, (%rax)
	.loc 1 185 32
	movq	-40(%rbp), %rdx
	.loc 1 185 6
	movq	-32(%rbp), %rax
	.loc 1 185 32
	movabsq	$9223372036854775807, %rcx
	andq	%rcx, %rdx
	.loc 1 185 30
	leaq	(%rdx,%rdx), %rcx
	movq	(%rax), %rdx
	andl	$1, %edx
	orq	%rcx, %rdx
	movq	%rdx, (%rax)
	.loc 1 186 24
	movq	-24(%rbp), %rax
	subq	$8, %rax
	.loc 1 186 12
	jmp	.L17
.L6:
.LBE2:
	.loc 1 190 12
	movl	dev_zero(%rip), %ecx
	.loc 1 191 9
	movq	pagesize(%rip), %rax
	movq	%rax, %rsi
	movl	$8, %eax
	movl	$0, %edx
	divq	%rsi
	movq	%rax, %rdx
	movq	-56(%rbp), %rax
	leaq	(%rdx,%rax), %rsi
	movq	pagesize(%rip), %rax
	movq	%rax, %rdi
	movl	$8, %eax
	movl	$0, %edx
	divq	%rdi
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	testq	%rax, %rax
	setne	%al
	movzbl	%al, %eax
	leaq	(%rsi,%rax), %rdx
	.loc 1 190 12
	movq	pagesize(%rip), %rax
	imulq	%rdx, %rax
	movl	$0, %r9d
	movl	%ecx, %r8d
	movl	$34, %ecx
	movl	$3, %edx
	movq	%rax, %rsi
	movl	$0, %edi
	call	mmap@PLT
	jmp	.L17
.L5:
	.loc 1 207 15
	movl	$0, %eax
	jmp	.L17
.L4:
	.loc 1 211 3
	movl	$0, %eax
	call	_minit
	.loc 1 212 3
	jmp	.L3
.L17:
	.loc 1 214 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	wl_mal, .-wl_mal
	.globl	wl_mfr
	.type	wl_mfr, @function
wl_mfr:
.LFB8:
	.loc 1 222 18
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	.loc 1 223 5
	cmpq	$0, -8(%rbp)
	je	.L24
	.loc 1 225 9
	movq	heap(%rip), %rax
	.loc 1 225 6
	cmpq	%rax, -8(%rbp)
	jb	.L20
	.loc 1 225 25 discriminator 1
	movl	$0, %edi
	call	sbrk@PLT
	.loc 1 225 17 discriminator 1
	cmpq	%rax, -8(%rbp)
	ja	.L20
	.loc 1 226 15
	movq	-8(%rbp), %rax
	.loc 1 226 22
	subq	$8, %rax
	.loc 1 226 51
	movzbl	(%rax), %edx
	andl	$-2, %edx
	movb	%dl, (%rax)
	jmp	.L19
.L20:
	.loc 1 228 18
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	shrq	%rax
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	cmpq	%rax, %rdx
	jnb	.L21
	.loc 1 228 18 is_stmt 0 discriminator 1
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	shrq	%rax
	movq	%rax, %rdx
	movabsq	$-9223372036854775808, %rax
	andq	%rdx, %rax
	jmp	.L22
.L21:
	.loc 1 228 18 discriminator 2
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	shrq	%rax
	movq	%rax, %rdx
	movq	heap(%rip), %rax
	movq	%rax, %rcx
	movabsq	$-9223372036854775808, %rax
	andq	%rcx, %rax
	orq	%rdx, %rax
.L22:
	.loc 1 228 36 is_stmt 1 discriminator 4
	movq	-8(%rbp), %rcx
	.loc 1 228 8 discriminator 4
	subq	%rcx, %rax
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	munmap@PLT
.L19:
	.loc 1 233 2
	nop
.L24:
	nop
	.loc 1 234 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	wl_mfr, .-wl_mfr
.Letext0:
	.file 2 "/usr/include/bits/types.h"
	.file 3 "/usr/lib/gcc/x86_64-pc-linux-gnu/11.1.0/include/stddef.h"
	.file 4 "inc/wc/types.h"
	.file 5 "inc/wc/memory.h"
	.file 6 "/usr/include/unistd.h"
	.file 7 "/usr/include/sys/mman.h"
	.file 8 "/usr/include/bits/confname.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x7ff
	.value	0x5
	.byte	0x1
	.byte	0x8
	.long	.Ldebug_abbrev0
	.uleb128 0xc
	.long	.LASF253
	.byte	0x1d
	.long	.LASF0
	.long	.LASF1
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF2
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF3
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF4
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF5
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF6
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF7
	.uleb128 0xd
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF8
	.uleb128 0x5
	.long	.LASF10
	.byte	0x2
	.byte	0x98
	.byte	0x19
	.long	0x5f
	.uleb128 0xe
	.byte	0x8
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF9
	.uleb128 0x5
	.long	.LASF11
	.byte	0x2
	.byte	0xcf
	.byte	0x19
	.long	0x5f
	.uleb128 0x5
	.long	.LASF12
	.byte	0x3
	.byte	0xd1
	.byte	0x17
	.long	0x43
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF13
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF14
	.uleb128 0x6
	.long	.LASF15
	.byte	0x4
	.value	0x104
	.byte	0x1a
	.long	0x5f
	.uleb128 0x6
	.long	.LASF16
	.byte	0x4
	.value	0x108
	.byte	0x21
	.long	0x43
	.uleb128 0x6
	.long	.LASF17
	.byte	0x4
	.value	0x109
	.byte	0x13
	.long	0xae
	.uleb128 0xf
	.long	.LASF254
	.byte	0x4
	.value	0x15d
	.byte	0x18
	.uleb128 0x2
	.byte	0x1
	.byte	0x2
	.long	.LASF18
	.uleb128 0x2
	.byte	0x4
	.byte	0x4
	.long	.LASF19
	.uleb128 0x2
	.byte	0x8
	.byte	0x4
	.long	.LASF20
	.uleb128 0x5
	.long	.LASF21
	.byte	0x5
	.byte	0x2a
	.byte	0x1b
	.long	0xbb
	.uleb128 0x6
	.long	.LASF22
	.byte	0x6
	.value	0x10b
	.byte	0x14
	.long	0x7b
	.uleb128 0x10
	.byte	0x7
	.byte	0x4
	.long	0x3c
	.byte	0x8
	.byte	0x48
	.byte	0x3
	.long	0x618
	.uleb128 0x1
	.long	.LASF23
	.byte	0
	.uleb128 0x1
	.long	.LASF24
	.byte	0x1
	.uleb128 0x1
	.long	.LASF25
	.byte	0x2
	.uleb128 0x1
	.long	.LASF26
	.byte	0x3
	.uleb128 0x1
	.long	.LASF27
	.byte	0x4
	.uleb128 0x1
	.long	.LASF28
	.byte	0x5
	.uleb128 0x1
	.long	.LASF29
	.byte	0x6
	.uleb128 0x1
	.long	.LASF30
	.byte	0x7
	.uleb128 0x1
	.long	.LASF31
	.byte	0x8
	.uleb128 0x1
	.long	.LASF32
	.byte	0x9
	.uleb128 0x1
	.long	.LASF33
	.byte	0xa
	.uleb128 0x1
	.long	.LASF34
	.byte	0xb
	.uleb128 0x1
	.long	.LASF35
	.byte	0xc
	.uleb128 0x1
	.long	.LASF36
	.byte	0xd
	.uleb128 0x1
	.long	.LASF37
	.byte	0xe
	.uleb128 0x1
	.long	.LASF38
	.byte	0xf
	.uleb128 0x1
	.long	.LASF39
	.byte	0x10
	.uleb128 0x1
	.long	.LASF40
	.byte	0x11
	.uleb128 0x1
	.long	.LASF41
	.byte	0x12
	.uleb128 0x1
	.long	.LASF42
	.byte	0x13
	.uleb128 0x1
	.long	.LASF43
	.byte	0x14
	.uleb128 0x1
	.long	.LASF44
	.byte	0x15
	.uleb128 0x1
	.long	.LASF45
	.byte	0x16
	.uleb128 0x1
	.long	.LASF46
	.byte	0x17
	.uleb128 0x1
	.long	.LASF47
	.byte	0x18
	.uleb128 0x1
	.long	.LASF48
	.byte	0x19
	.uleb128 0x1
	.long	.LASF49
	.byte	0x1a
	.uleb128 0x1
	.long	.LASF50
	.byte	0x1b
	.uleb128 0x1
	.long	.LASF51
	.byte	0x1c
	.uleb128 0x1
	.long	.LASF52
	.byte	0x1d
	.uleb128 0x1
	.long	.LASF53
	.byte	0x1e
	.uleb128 0x1
	.long	.LASF54
	.byte	0x1f
	.uleb128 0x1
	.long	.LASF55
	.byte	0x20
	.uleb128 0x1
	.long	.LASF56
	.byte	0x21
	.uleb128 0x1
	.long	.LASF57
	.byte	0x22
	.uleb128 0x1
	.long	.LASF58
	.byte	0x23
	.uleb128 0x1
	.long	.LASF59
	.byte	0x24
	.uleb128 0x1
	.long	.LASF60
	.byte	0x25
	.uleb128 0x1
	.long	.LASF61
	.byte	0x26
	.uleb128 0x1
	.long	.LASF62
	.byte	0x27
	.uleb128 0x1
	.long	.LASF63
	.byte	0x28
	.uleb128 0x1
	.long	.LASF64
	.byte	0x29
	.uleb128 0x1
	.long	.LASF65
	.byte	0x2a
	.uleb128 0x1
	.long	.LASF66
	.byte	0x2b
	.uleb128 0x1
	.long	.LASF67
	.byte	0x2c
	.uleb128 0x1
	.long	.LASF68
	.byte	0x2d
	.uleb128 0x1
	.long	.LASF69
	.byte	0x2e
	.uleb128 0x1
	.long	.LASF70
	.byte	0x2f
	.uleb128 0x1
	.long	.LASF71
	.byte	0x30
	.uleb128 0x1
	.long	.LASF72
	.byte	0x31
	.uleb128 0x1
	.long	.LASF73
	.byte	0x32
	.uleb128 0x1
	.long	.LASF74
	.byte	0x33
	.uleb128 0x1
	.long	.LASF75
	.byte	0x34
	.uleb128 0x1
	.long	.LASF76
	.byte	0x35
	.uleb128 0x1
	.long	.LASF77
	.byte	0x36
	.uleb128 0x1
	.long	.LASF78
	.byte	0x37
	.uleb128 0x1
	.long	.LASF79
	.byte	0x38
	.uleb128 0x1
	.long	.LASF80
	.byte	0x39
	.uleb128 0x1
	.long	.LASF81
	.byte	0x3a
	.uleb128 0x1
	.long	.LASF82
	.byte	0x3b
	.uleb128 0x1
	.long	.LASF83
	.byte	0x3c
	.uleb128 0x1
	.long	.LASF84
	.byte	0x3c
	.uleb128 0x1
	.long	.LASF85
	.byte	0x3d
	.uleb128 0x1
	.long	.LASF86
	.byte	0x3e
	.uleb128 0x1
	.long	.LASF87
	.byte	0x3f
	.uleb128 0x1
	.long	.LASF88
	.byte	0x40
	.uleb128 0x1
	.long	.LASF89
	.byte	0x41
	.uleb128 0x1
	.long	.LASF90
	.byte	0x42
	.uleb128 0x1
	.long	.LASF91
	.byte	0x43
	.uleb128 0x1
	.long	.LASF92
	.byte	0x44
	.uleb128 0x1
	.long	.LASF93
	.byte	0x45
	.uleb128 0x1
	.long	.LASF94
	.byte	0x46
	.uleb128 0x1
	.long	.LASF95
	.byte	0x47
	.uleb128 0x1
	.long	.LASF96
	.byte	0x48
	.uleb128 0x1
	.long	.LASF97
	.byte	0x49
	.uleb128 0x1
	.long	.LASF98
	.byte	0x4a
	.uleb128 0x1
	.long	.LASF99
	.byte	0x4b
	.uleb128 0x1
	.long	.LASF100
	.byte	0x4c
	.uleb128 0x1
	.long	.LASF101
	.byte	0x4d
	.uleb128 0x1
	.long	.LASF102
	.byte	0x4e
	.uleb128 0x1
	.long	.LASF103
	.byte	0x4f
	.uleb128 0x1
	.long	.LASF104
	.byte	0x50
	.uleb128 0x1
	.long	.LASF105
	.byte	0x51
	.uleb128 0x1
	.long	.LASF106
	.byte	0x52
	.uleb128 0x1
	.long	.LASF107
	.byte	0x53
	.uleb128 0x1
	.long	.LASF108
	.byte	0x54
	.uleb128 0x1
	.long	.LASF109
	.byte	0x55
	.uleb128 0x1
	.long	.LASF110
	.byte	0x56
	.uleb128 0x1
	.long	.LASF111
	.byte	0x57
	.uleb128 0x1
	.long	.LASF112
	.byte	0x58
	.uleb128 0x1
	.long	.LASF113
	.byte	0x59
	.uleb128 0x1
	.long	.LASF114
	.byte	0x5a
	.uleb128 0x1
	.long	.LASF115
	.byte	0x5b
	.uleb128 0x1
	.long	.LASF116
	.byte	0x5c
	.uleb128 0x1
	.long	.LASF117
	.byte	0x5d
	.uleb128 0x1
	.long	.LASF118
	.byte	0x5e
	.uleb128 0x1
	.long	.LASF119
	.byte	0x5f
	.uleb128 0x1
	.long	.LASF120
	.byte	0x60
	.uleb128 0x1
	.long	.LASF121
	.byte	0x61
	.uleb128 0x1
	.long	.LASF122
	.byte	0x62
	.uleb128 0x1
	.long	.LASF123
	.byte	0x63
	.uleb128 0x1
	.long	.LASF124
	.byte	0x64
	.uleb128 0x1
	.long	.LASF125
	.byte	0x65
	.uleb128 0x1
	.long	.LASF126
	.byte	0x66
	.uleb128 0x1
	.long	.LASF127
	.byte	0x67
	.uleb128 0x1
	.long	.LASF128
	.byte	0x68
	.uleb128 0x1
	.long	.LASF129
	.byte	0x69
	.uleb128 0x1
	.long	.LASF130
	.byte	0x6a
	.uleb128 0x1
	.long	.LASF131
	.byte	0x6b
	.uleb128 0x1
	.long	.LASF132
	.byte	0x6c
	.uleb128 0x1
	.long	.LASF133
	.byte	0x6d
	.uleb128 0x1
	.long	.LASF134
	.byte	0x6e
	.uleb128 0x1
	.long	.LASF135
	.byte	0x6f
	.uleb128 0x1
	.long	.LASF136
	.byte	0x70
	.uleb128 0x1
	.long	.LASF137
	.byte	0x71
	.uleb128 0x1
	.long	.LASF138
	.byte	0x72
	.uleb128 0x1
	.long	.LASF139
	.byte	0x73
	.uleb128 0x1
	.long	.LASF140
	.byte	0x74
	.uleb128 0x1
	.long	.LASF141
	.byte	0x75
	.uleb128 0x1
	.long	.LASF142
	.byte	0x76
	.uleb128 0x1
	.long	.LASF143
	.byte	0x77
	.uleb128 0x1
	.long	.LASF144
	.byte	0x78
	.uleb128 0x1
	.long	.LASF145
	.byte	0x79
	.uleb128 0x1
	.long	.LASF146
	.byte	0x7a
	.uleb128 0x1
	.long	.LASF147
	.byte	0x7b
	.uleb128 0x1
	.long	.LASF148
	.byte	0x7c
	.uleb128 0x1
	.long	.LASF149
	.byte	0x7d
	.uleb128 0x1
	.long	.LASF150
	.byte	0x7e
	.uleb128 0x1
	.long	.LASF151
	.byte	0x7f
	.uleb128 0x1
	.long	.LASF152
	.byte	0x80
	.uleb128 0x1
	.long	.LASF153
	.byte	0x81
	.uleb128 0x1
	.long	.LASF154
	.byte	0x82
	.uleb128 0x1
	.long	.LASF155
	.byte	0x83
	.uleb128 0x1
	.long	.LASF156
	.byte	0x84
	.uleb128 0x1
	.long	.LASF157
	.byte	0x85
	.uleb128 0x1
	.long	.LASF158
	.byte	0x86
	.uleb128 0x1
	.long	.LASF159
	.byte	0x87
	.uleb128 0x1
	.long	.LASF160
	.byte	0x88
	.uleb128 0x1
	.long	.LASF161
	.byte	0x89
	.uleb128 0x1
	.long	.LASF162
	.byte	0x8a
	.uleb128 0x1
	.long	.LASF163
	.byte	0x8b
	.uleb128 0x1
	.long	.LASF164
	.byte	0x8c
	.uleb128 0x1
	.long	.LASF165
	.byte	0x8d
	.uleb128 0x1
	.long	.LASF166
	.byte	0x8e
	.uleb128 0x1
	.long	.LASF167
	.byte	0x8f
	.uleb128 0x1
	.long	.LASF168
	.byte	0x90
	.uleb128 0x1
	.long	.LASF169
	.byte	0x91
	.uleb128 0x1
	.long	.LASF170
	.byte	0x92
	.uleb128 0x1
	.long	.LASF171
	.byte	0x93
	.uleb128 0x1
	.long	.LASF172
	.byte	0x94
	.uleb128 0x1
	.long	.LASF173
	.byte	0x95
	.uleb128 0x1
	.long	.LASF174
	.byte	0x96
	.uleb128 0x1
	.long	.LASF175
	.byte	0x97
	.uleb128 0x1
	.long	.LASF176
	.byte	0x98
	.uleb128 0x1
	.long	.LASF177
	.byte	0x99
	.uleb128 0x1
	.long	.LASF178
	.byte	0x9a
	.uleb128 0x1
	.long	.LASF179
	.byte	0x9b
	.uleb128 0x1
	.long	.LASF180
	.byte	0x9c
	.uleb128 0x1
	.long	.LASF181
	.byte	0x9d
	.uleb128 0x1
	.long	.LASF182
	.byte	0x9e
	.uleb128 0x1
	.long	.LASF183
	.byte	0x9f
	.uleb128 0x1
	.long	.LASF184
	.byte	0xa0
	.uleb128 0x1
	.long	.LASF185
	.byte	0xa1
	.uleb128 0x1
	.long	.LASF186
	.byte	0xa2
	.uleb128 0x1
	.long	.LASF187
	.byte	0xa3
	.uleb128 0x1
	.long	.LASF188
	.byte	0xa4
	.uleb128 0x1
	.long	.LASF189
	.byte	0xa5
	.uleb128 0x1
	.long	.LASF190
	.byte	0xa6
	.uleb128 0x1
	.long	.LASF191
	.byte	0xa7
	.uleb128 0x1
	.long	.LASF192
	.byte	0xa8
	.uleb128 0x1
	.long	.LASF193
	.byte	0xa9
	.uleb128 0x1
	.long	.LASF194
	.byte	0xaa
	.uleb128 0x1
	.long	.LASF195
	.byte	0xab
	.uleb128 0x1
	.long	.LASF196
	.byte	0xac
	.uleb128 0x1
	.long	.LASF197
	.byte	0xad
	.uleb128 0x1
	.long	.LASF198
	.byte	0xae
	.uleb128 0x1
	.long	.LASF199
	.byte	0xaf
	.uleb128 0x1
	.long	.LASF200
	.byte	0xb0
	.uleb128 0x1
	.long	.LASF201
	.byte	0xb1
	.uleb128 0x1
	.long	.LASF202
	.byte	0xb2
	.uleb128 0x1
	.long	.LASF203
	.byte	0xb3
	.uleb128 0x1
	.long	.LASF204
	.byte	0xb4
	.uleb128 0x1
	.long	.LASF205
	.byte	0xb5
	.uleb128 0x1
	.long	.LASF206
	.byte	0xb6
	.uleb128 0x1
	.long	.LASF207
	.byte	0xb7
	.uleb128 0x1
	.long	.LASF208
	.byte	0xb8
	.uleb128 0x1
	.long	.LASF209
	.byte	0xb9
	.uleb128 0x1
	.long	.LASF210
	.byte	0xba
	.uleb128 0x1
	.long	.LASF211
	.byte	0xbb
	.uleb128 0x1
	.long	.LASF212
	.byte	0xbc
	.uleb128 0x1
	.long	.LASF213
	.byte	0xbd
	.uleb128 0x1
	.long	.LASF214
	.byte	0xbe
	.uleb128 0x1
	.long	.LASF215
	.byte	0xbf
	.uleb128 0x1
	.long	.LASF216
	.byte	0xc0
	.uleb128 0x1
	.long	.LASF217
	.byte	0xc1
	.uleb128 0x1
	.long	.LASF218
	.byte	0xc2
	.uleb128 0x1
	.long	.LASF219
	.byte	0xc3
	.uleb128 0x1
	.long	.LASF220
	.byte	0xc4
	.uleb128 0x1
	.long	.LASF221
	.byte	0xc5
	.uleb128 0x1
	.long	.LASF222
	.byte	0xc6
	.uleb128 0x1
	.long	.LASF223
	.byte	0xc7
	.uleb128 0x1
	.long	.LASF224
	.byte	0xeb
	.uleb128 0x1
	.long	.LASF225
	.byte	0xec
	.uleb128 0x1
	.long	.LASF226
	.byte	0xed
	.uleb128 0x1
	.long	.LASF227
	.byte	0xee
	.uleb128 0x1
	.long	.LASF228
	.byte	0xef
	.uleb128 0x1
	.long	.LASF229
	.byte	0xf0
	.uleb128 0x1
	.long	.LASF230
	.byte	0xf1
	.uleb128 0x1
	.long	.LASF231
	.byte	0xf2
	.uleb128 0x1
	.long	.LASF232
	.byte	0xf3
	.uleb128 0x1
	.long	.LASF233
	.byte	0xf4
	.uleb128 0x1
	.long	.LASF234
	.byte	0xf5
	.uleb128 0x1
	.long	.LASF235
	.byte	0xf6
	.uleb128 0x1
	.long	.LASF236
	.byte	0xf7
	.uleb128 0x1
	.long	.LASF237
	.byte	0xf8
	.byte	0
	.uleb128 0x11
	.long	.LASF240
	.byte	0x8
	.byte	0x1
	.byte	0x44
	.byte	0x10
	.long	0x63e
	.uleb128 0x7
	.long	.LASF238
	.byte	0x45
	.long	0xbb
	.byte	0x1
	.byte	0
	.uleb128 0x7
	.long	.LASF239
	.byte	0x4a
	.long	0xbb
	.byte	0x3f
	.byte	0x1
	.byte	0
	.uleb128 0x5
	.long	.LASF240
	.byte	0x1
	.byte	0x4d
	.byte	0x3
	.long	0x618
	.uleb128 0x4
	.long	.LASF241
	.byte	0x53
	.byte	0xc
	.long	0x65f
	.uleb128 0x9
	.byte	0x3
	.quad	heap
	.uleb128 0x12
	.byte	0x8
	.long	0xc8
	.uleb128 0x4
	.long	.LASF242
	.byte	0x54
	.byte	0xd
	.long	0x5f
	.uleb128 0x9
	.byte	0x3
	.quad	pagesize
	.uleb128 0x4
	.long	.LASF243
	.byte	0x55
	.byte	0xc
	.long	0x58
	.uleb128 0x9
	.byte	0x3
	.quad	dev_zero
	.uleb128 0x8
	.long	.LASF244
	.byte	0x4c
	.byte	0xc
	.long	0x58
	.long	0x6a9
	.uleb128 0x3
	.long	0x72
	.uleb128 0x3
	.long	0x87
	.byte	0
	.uleb128 0x8
	.long	.LASF245
	.byte	0x39
	.byte	0xe
	.long	0x72
	.long	0x6d7
	.uleb128 0x3
	.long	0x72
	.uleb128 0x3
	.long	0x87
	.uleb128 0x3
	.long	0x58
	.uleb128 0x3
	.long	0x58
	.uleb128 0x3
	.long	0x58
	.uleb128 0x3
	.long	0x66
	.byte	0
	.uleb128 0x9
	.long	.LASF246
	.value	0x276
	.byte	0x11
	.long	0x5f
	.long	0x6ed
	.uleb128 0x3
	.long	0x58
	.byte	0
	.uleb128 0x9
	.long	.LASF247
	.value	0x41f
	.byte	0xe
	.long	0x72
	.long	0x703
	.uleb128 0x3
	.long	0xf2
	.byte	0
	.uleb128 0x13
	.long	.LASF255
	.byte	0x1
	.byte	0xde
	.byte	0x4
	.quad	.LFB8
	.quad	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.long	0x72f
	.uleb128 0x14
	.string	"p"
	.byte	0x1
	.byte	0xde
	.byte	0xf
	.long	0x65f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x15
	.long	.LASF256
	.byte	0x1
	.byte	0x72
	.byte	0x5
	.long	0x65f
	.quad	.LFB7
	.quad	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.long	0x7e8
	.uleb128 0x16
	.long	.LASF248
	.byte	0x1
	.byte	0x72
	.byte	0x10
	.long	0xe6
	.uleb128 0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0x17
	.long	.LASF249
	.byte	0x1
	.byte	0x73
	.byte	0x1
	.quad	.L3
	.uleb128 0x18
	.string	"end"
	.byte	0x1
	.byte	0xaa
	.byte	0x1
	.quad	.L15
	.uleb128 0xa
	.quad	.LBB2
	.quad	.LBE2-.LBB2
	.uleb128 0x4
	.long	.LASF250
	.byte	0x7f
	.byte	0x9
	.long	0x65f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0xb
	.string	"sum"
	.byte	0x83
	.long	0xbb
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x4
	.long	.LASF251
	.byte	0x85
	.byte	0xa
	.long	0xbb
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x4
	.long	.LASF252
	.byte	0x86
	.byte	0xa
	.long	0xbb
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xa
	.quad	.LBB3
	.quad	.LBE3-.LBB3
	.uleb128 0xb
	.string	"i"
	.byte	0x8e
	.long	0x65f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x19
	.long	.LASF257
	.byte	0x1
	.byte	0x5f
	.byte	0xb
	.quad	.LFB6
	.quad	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 7
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0xd
	.uleb128 0xb
	.uleb128 0x6b
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 7
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 6
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 10
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x1f
	.uleb128 0x1b
	.uleb128 0x1f
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0xa
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0xa
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.file 0 "/home/wispy/prj/wlib" "src/memory.c"
	.section	.debug_str,"MS",@progbits,1
.LASF218:
	.string	"_SC_LEVEL3_CACHE_SIZE"
.LASF251:
	.string	"chunk"
.LASF128:
	.string	"_SC_INT_MAX"
.LASF12:
	.string	"size_t"
.LASF39:
	.string	"_SC_MAPPED_FILES"
.LASF24:
	.string	"_SC_CHILD_MAX"
.LASF249:
	.string	"start"
.LASF247:
	.string	"sbrk"
.LASF25:
	.string	"_SC_CLK_TCK"
.LASF57:
	.string	"_SC_SIGQUEUE_MAX"
.LASF254:
	.string	"wl_Vo"
.LASF236:
	.string	"_SC_THREAD_ROBUST_PRIO_INHERIT"
.LASF164:
	.string	"_SC_DEVICE_IO"
.LASF222:
	.string	"_SC_LEVEL4_CACHE_ASSOC"
.LASF30:
	.string	"_SC_JOB_CONTROL"
.LASF126:
	.string	"_SC_CHAR_MAX"
.LASF207:
	.string	"_SC_TRACE_INHERIT"
.LASF113:
	.string	"_SC_XOPEN_VERSION"
.LASF93:
	.string	"_SC_GETGR_R_SIZE_MAX"
.LASF78:
	.string	"_SC_PII_SOCKET"
.LASF31:
	.string	"_SC_SAVED_IDS"
.LASF135:
	.string	"_SC_SCHAR_MAX"
.LASF23:
	.string	"_SC_ARG_MAX"
.LASF16:
	.string	"wl_U64"
.LASF188:
	.string	"_SC_TIMEOUTS"
.LASF125:
	.string	"_SC_CHAR_BIT"
.LASF46:
	.string	"_SC_AIO_LISTIO_MAX"
.LASF132:
	.string	"_SC_MB_LEN_MAX"
.LASF105:
	.string	"_SC_THREAD_PRIO_PROTECT"
.LASF79:
	.string	"_SC_PII_INTERNET"
.LASF106:
	.string	"_SC_THREAD_PROCESS_SHARED"
.LASF232:
	.string	"_SC_TRACE_NAME_MAX"
.LASF76:
	.string	"_SC_PII"
.LASF48:
	.string	"_SC_AIO_PRIO_DELTA_MAX"
.LASF42:
	.string	"_SC_MEMORY_PROTECTION"
.LASF27:
	.string	"_SC_OPEN_MAX"
.LASF100:
	.string	"_SC_THREAD_THREADS_MAX"
.LASF177:
	.string	"_SC_READER_WRITER_LOCKS"
.LASF198:
	.string	"_SC_STREAMS"
.LASF8:
	.string	"long int"
.LASF50:
	.string	"_SC_MQ_OPEN_MAX"
.LASF168:
	.string	"_SC_FIFO"
.LASF120:
	.string	"_SC_2_C_VERSION"
.LASF237:
	.string	"_SC_THREAD_ROBUST_PRIO_PROTECT"
.LASF240:
	.string	"MChunk"
.LASF60:
	.string	"_SC_BC_DIM_MAX"
.LASF101:
	.string	"_SC_THREAD_ATTR_STACKADDR"
.LASF241:
	.string	"heap"
.LASF226:
	.string	"_SC_V7_ILP32_OFF32"
.LASF140:
	.string	"_SC_UINT_MAX"
.LASF194:
	.string	"_SC_2_PBS_LOCATE"
.LASF6:
	.string	"signed char"
.LASF214:
	.string	"_SC_LEVEL1_DCACHE_LINESIZE"
.LASF252:
	.string	"_ptr2next"
.LASF206:
	.string	"_SC_TRACE_EVENT_FILTER"
.LASF144:
	.string	"_SC_NL_LANGMAX"
.LASF202:
	.string	"_SC_V6_LP64_OFF64"
.LASF145:
	.string	"_SC_NL_MSGMAX"
.LASF2:
	.string	"unsigned char"
.LASF88:
	.string	"_SC_PII_OSI_CLTS"
.LASF210:
	.string	"_SC_LEVEL1_ICACHE_ASSOC"
.LASF166:
	.string	"_SC_DEVICE_SPECIFIC_R"
.LASF133:
	.string	"_SC_NZERO"
.LASF122:
	.string	"_SC_XOPEN_XPG2"
.LASF123:
	.string	"_SC_XOPEN_XPG3"
.LASF124:
	.string	"_SC_XOPEN_XPG4"
.LASF141:
	.string	"_SC_ULONG_MAX"
.LASF18:
	.string	"_Bool"
.LASF117:
	.string	"_SC_XOPEN_ENH_I18N"
.LASF129:
	.string	"_SC_INT_MIN"
.LASF9:
	.string	"char"
.LASF121:
	.string	"_SC_2_UPE"
.LASF53:
	.string	"_SC_PAGESIZE"
.LASF172:
	.string	"_SC_FILE_SYSTEM"
.LASF69:
	.string	"_SC_2_VERSION"
.LASF67:
	.string	"_SC_RE_DUP_MAX"
.LASF239:
	.string	"ptr2next"
.LASF219:
	.string	"_SC_LEVEL3_CACHE_ASSOC"
.LASF72:
	.string	"_SC_2_FORT_DEV"
.LASF127:
	.string	"_SC_CHAR_MIN"
.LASF84:
	.string	"_SC_IOV_MAX"
.LASF163:
	.string	"_SC_THREAD_CPUTIME"
.LASF186:
	.string	"_SC_SYSTEM_DATABASE"
.LASF245:
	.string	"mmap"
.LASF86:
	.string	"_SC_PII_INTERNET_DGRAM"
.LASF171:
	.string	"_SC_FILE_LOCKING"
.LASF242:
	.string	"pagesize"
.LASF136:
	.string	"_SC_SCHAR_MIN"
.LASF83:
	.string	"_SC_UIO_MAXIOV"
.LASF52:
	.string	"_SC_VERSION"
.LASF256:
	.string	"wl_mal"
.LASF178:
	.string	"_SC_SPIN_LOCKS"
.LASF212:
	.string	"_SC_LEVEL1_DCACHE_SIZE"
.LASF225:
	.string	"_SC_RAW_SOCKETS"
.LASF91:
	.string	"_SC_THREADS"
.LASF92:
	.string	"_SC_THREAD_SAFE_FUNCTIONS"
.LASF131:
	.string	"_SC_WORD_BIT"
.LASF179:
	.string	"_SC_REGEXP"
.LASF35:
	.string	"_SC_ASYNCHRONOUS_IO"
.LASF68:
	.string	"_SC_CHARCLASS_NAME_MAX"
.LASF213:
	.string	"_SC_LEVEL1_DCACHE_ASSOC"
.LASF220:
	.string	"_SC_LEVEL3_CACHE_LINESIZE"
.LASF99:
	.string	"_SC_THREAD_STACK_MIN"
.LASF5:
	.string	"long unsigned int"
.LASF115:
	.string	"_SC_XOPEN_UNIX"
.LASF148:
	.string	"_SC_NL_TEXTMAX"
.LASF244:
	.string	"munmap"
.LASF85:
	.string	"_SC_PII_INTERNET_STREAM"
.LASF201:
	.string	"_SC_V6_ILP32_OFFBIG"
.LASF227:
	.string	"_SC_V7_ILP32_OFFBIG"
.LASF44:
	.string	"_SC_SEMAPHORES"
.LASF221:
	.string	"_SC_LEVEL4_CACHE_SIZE"
.LASF238:
	.string	"allocated"
.LASF174:
	.string	"_SC_MULTI_PROCESS"
.LASF108:
	.string	"_SC_NPROCESSORS_ONLN"
.LASF190:
	.string	"_SC_USER_GROUPS"
.LASF75:
	.string	"_SC_2_LOCALEDEF"
.LASF66:
	.string	"_SC_LINE_MAX"
.LASF109:
	.string	"_SC_PHYS_PAGES"
.LASF154:
	.string	"_SC_XOPEN_REALTIME"
.LASF182:
	.string	"_SC_SIGNALS"
.LASF173:
	.string	"_SC_MONOTONIC_CLOCK"
.LASF11:
	.string	"__intptr_t"
.LASF54:
	.string	"_SC_RTSIG_MAX"
.LASF170:
	.string	"_SC_FILE_ATTRIBUTES"
.LASF191:
	.string	"_SC_USER_GROUPS_R"
.LASF114:
	.string	"_SC_XOPEN_XCU_VERSION"
.LASF77:
	.string	"_SC_PII_XTI"
.LASF155:
	.string	"_SC_XOPEN_REALTIME_THREADS"
.LASF14:
	.string	"long long int"
.LASF130:
	.string	"_SC_LONG_BIT"
.LASF150:
	.string	"_SC_XBS5_ILP32_OFFBIG"
.LASF21:
	.string	"wl_Msz"
.LASF20:
	.string	"double"
.LASF139:
	.string	"_SC_UCHAR_MAX"
.LASF169:
	.string	"_SC_PIPE"
.LASF189:
	.string	"_SC_TYPED_MEMORY_OBJECTS"
.LASF95:
	.string	"_SC_LOGIN_NAME_MAX"
.LASF255:
	.string	"wl_mfr"
.LASF98:
	.string	"_SC_THREAD_KEYS_MAX"
.LASF156:
	.string	"_SC_ADVISORY_INFO"
.LASF19:
	.string	"float"
.LASF250:
	.string	"heapEnd"
.LASF4:
	.string	"unsigned int"
.LASF22:
	.string	"intptr_t"
.LASF63:
	.string	"_SC_COLL_WEIGHTS_MAX"
.LASF89:
	.string	"_SC_PII_OSI_M"
.LASF71:
	.string	"_SC_2_C_DEV"
.LASF187:
	.string	"_SC_SYSTEM_DATABASE_R"
.LASF45:
	.string	"_SC_SHARED_MEMORY_OBJECTS"
.LASF231:
	.string	"_SC_TRACE_EVENT_NAME_MAX"
.LASF142:
	.string	"_SC_USHRT_MAX"
.LASF253:
	.string	"GNU C17 11.1.0 -mtune=generic -march=x86-64 -g -std=gnu17"
.LASF224:
	.string	"_SC_IPV6"
.LASF204:
	.string	"_SC_HOST_NAME_MAX"
.LASF62:
	.string	"_SC_BC_STRING_MAX"
.LASF103:
	.string	"_SC_THREAD_PRIORITY_SCHEDULING"
.LASF81:
	.string	"_SC_POLL"
.LASF74:
	.string	"_SC_2_SW_DEV"
.LASF32:
	.string	"_SC_REALTIME_SIGNALS"
.LASF152:
	.string	"_SC_XBS5_LPBIG_OFFBIG"
.LASF193:
	.string	"_SC_2_PBS_ACCOUNTING"
.LASF97:
	.string	"_SC_THREAD_DESTRUCTOR_ITERATIONS"
.LASF208:
	.string	"_SC_TRACE_LOG"
.LASF40:
	.string	"_SC_MEMLOCK"
.LASF80:
	.string	"_SC_PII_OSI"
.LASF49:
	.string	"_SC_DELAYTIMER_MAX"
.LASF73:
	.string	"_SC_2_FORT_RUN"
.LASF228:
	.string	"_SC_V7_LP64_OFF64"
.LASF107:
	.string	"_SC_NPROCESSORS_CONF"
.LASF137:
	.string	"_SC_SHRT_MAX"
.LASF47:
	.string	"_SC_AIO_MAX"
.LASF157:
	.string	"_SC_BARRIERS"
.LASF180:
	.string	"_SC_REGEX_VERSION"
.LASF217:
	.string	"_SC_LEVEL2_CACHE_LINESIZE"
.LASF165:
	.string	"_SC_DEVICE_SPECIFIC"
.LASF15:
	.string	"wl_I64"
.LASF248:
	.string	"size"
.LASF257:
	.string	"_minit"
.LASF151:
	.string	"_SC_XBS5_LP64_OFF64"
.LASF13:
	.string	"long long unsigned int"
.LASF229:
	.string	"_SC_V7_LPBIG_OFFBIG"
.LASF143:
	.string	"_SC_NL_ARGMAX"
.LASF10:
	.string	"__off_t"
.LASF175:
	.string	"_SC_SINGLE_PROCESS"
.LASF110:
	.string	"_SC_AVPHYS_PAGES"
.LASF118:
	.string	"_SC_XOPEN_SHM"
.LASF185:
	.string	"_SC_THREAD_SPORADIC_SERVER"
.LASF17:
	.string	"wl__Ptr"
.LASF230:
	.string	"_SC_SS_REPL_MAX"
.LASF146:
	.string	"_SC_NL_NMAX"
.LASF195:
	.string	"_SC_2_PBS_MESSAGE"
.LASF55:
	.string	"_SC_SEM_NSEMS_MAX"
.LASF90:
	.string	"_SC_T_IOV_MAX"
.LASF36:
	.string	"_SC_PRIORITIZED_IO"
.LASF200:
	.string	"_SC_V6_ILP32_OFF32"
.LASF28:
	.string	"_SC_STREAM_MAX"
.LASF29:
	.string	"_SC_TZNAME_MAX"
.LASF199:
	.string	"_SC_2_PBS_CHECKPOINT"
.LASF183:
	.string	"_SC_SPAWN"
.LASF41:
	.string	"_SC_MEMLOCK_RANGE"
.LASF61:
	.string	"_SC_BC_SCALE_MAX"
.LASF246:
	.string	"sysconf"
.LASF233:
	.string	"_SC_TRACE_SYS_MAX"
.LASF197:
	.string	"_SC_SYMLOOP_MAX"
.LASF119:
	.string	"_SC_2_CHAR_TERM"
.LASF181:
	.string	"_SC_SHELL"
.LASF167:
	.string	"_SC_FD_MGMT"
.LASF116:
	.string	"_SC_XOPEN_CRYPT"
.LASF211:
	.string	"_SC_LEVEL1_ICACHE_LINESIZE"
.LASF160:
	.string	"_SC_C_LANG_SUPPORT_R"
.LASF234:
	.string	"_SC_TRACE_USER_EVENT_MAX"
.LASF58:
	.string	"_SC_TIMER_MAX"
.LASF192:
	.string	"_SC_2_PBS"
.LASF162:
	.string	"_SC_CPUTIME"
.LASF184:
	.string	"_SC_SPORADIC_SERVER"
.LASF7:
	.string	"short int"
.LASF161:
	.string	"_SC_CLOCK_SELECTION"
.LASF149:
	.string	"_SC_XBS5_ILP32_OFF32"
.LASF176:
	.string	"_SC_NETWORKING"
.LASF223:
	.string	"_SC_LEVEL4_CACHE_LINESIZE"
.LASF111:
	.string	"_SC_ATEXIT_MAX"
.LASF243:
	.string	"dev_zero"
.LASF87:
	.string	"_SC_PII_OSI_COTS"
.LASF51:
	.string	"_SC_MQ_PRIO_MAX"
.LASF56:
	.string	"_SC_SEM_VALUE_MAX"
.LASF159:
	.string	"_SC_C_LANG_SUPPORT"
.LASF34:
	.string	"_SC_TIMERS"
.LASF112:
	.string	"_SC_PASS_MAX"
.LASF38:
	.string	"_SC_FSYNC"
.LASF82:
	.string	"_SC_SELECT"
.LASF96:
	.string	"_SC_TTY_NAME_MAX"
.LASF43:
	.string	"_SC_MESSAGE_PASSING"
.LASF216:
	.string	"_SC_LEVEL2_CACHE_ASSOC"
.LASF59:
	.string	"_SC_BC_BASE_MAX"
.LASF215:
	.string	"_SC_LEVEL2_CACHE_SIZE"
.LASF65:
	.string	"_SC_EXPR_NEST_MAX"
.LASF37:
	.string	"_SC_SYNCHRONIZED_IO"
.LASF235:
	.string	"_SC_XOPEN_STREAMS"
.LASF138:
	.string	"_SC_SHRT_MIN"
.LASF196:
	.string	"_SC_2_PBS_TRACK"
.LASF26:
	.string	"_SC_NGROUPS_MAX"
.LASF203:
	.string	"_SC_V6_LPBIG_OFFBIG"
.LASF3:
	.string	"short unsigned int"
.LASF209:
	.string	"_SC_LEVEL1_ICACHE_SIZE"
.LASF64:
	.string	"_SC_EQUIV_CLASS_MAX"
.LASF158:
	.string	"_SC_BASE"
.LASF33:
	.string	"_SC_PRIORITY_SCHEDULING"
.LASF134:
	.string	"_SC_SSIZE_MAX"
.LASF94:
	.string	"_SC_GETPW_R_SIZE_MAX"
.LASF153:
	.string	"_SC_XOPEN_LEGACY"
.LASF104:
	.string	"_SC_THREAD_PRIO_INHERIT"
.LASF205:
	.string	"_SC_TRACE"
.LASF147:
	.string	"_SC_NL_SETMAX"
.LASF70:
	.string	"_SC_2_C_BIND"
.LASF102:
	.string	"_SC_THREAD_ATTR_STACKSIZE"
	.section	.debug_line_str,"MS",@progbits,1
.LASF1:
	.string	"/home/wispy/prj/wlib"
.LASF0:
	.string	"src/memory.c"
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
