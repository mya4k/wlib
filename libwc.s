In archive /usr/lib/libwc.a:

array.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <wl_aas>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	41 56                	push   %r14
   6:	41 55                	push   %r13
   8:	41 54                	push   %r12
   a:	53                   	push   %rbx
   b:	48 83 ec 10          	sub    $0x10,%rsp
   f:	89 f9                	mov    %edi,%ecx
  11:	48 89 f0             	mov    %rsi,%rax
  14:	49 89 d5             	mov    %rdx,%r13
  17:	89 ca                	mov    %ecx,%edx
  19:	88 55 dc             	mov    %dl,-0x24(%rbp)
  1c:	48 85 c0             	test   %rax,%rax
  1f:	75 27                	jne    48 <wl_aas+0x48>
  21:	0f b6 45 dc          	movzbl -0x24(%rbp),%eax
  25:	41 b9 00 00 00 00    	mov    $0x0,%r9d
  2b:	41 b8 ff ff ff ff    	mov    $0xffffffff,%r8d
  31:	b9 22 00 00 00       	mov    $0x22,%ecx
  36:	ba 03 00 00 00       	mov    $0x3,%edx
  3b:	48 89 c6             	mov    %rax,%rsi
  3e:	bf 00 00 00 00       	mov    $0x0,%edi
  43:	e8 00 00 00 00       	call   48 <wl_aas+0x48>
  48:	0f b6 55 dc          	movzbl -0x24(%rbp),%edx
  4c:	c0 ea 03             	shr    $0x3,%dl
  4f:	41 89 d6             	mov    %edx,%r14d
  52:	0f b6 55 dc          	movzbl -0x24(%rbp),%edx
  56:	83 e2 07             	and    $0x7,%edx
  59:	41 89 d4             	mov    %edx,%r12d
  5c:	bb 00 00 00 00       	mov    $0x0,%ebx
  61:	eb 1f                	jmp    82 <wl_aas+0x82>
  63:	0f b7 d3             	movzwl %bx,%edx
  66:	48 c1 e2 03          	shl    $0x3,%rdx
  6a:	4c 01 ea             	add    %r13,%rdx
  6d:	0f b7 cb             	movzwl %bx,%ecx
  70:	48 c1 e1 03          	shl    $0x3,%rcx
  74:	48 01 c1             	add    %rax,%rcx
  77:	48 8b 12             	mov    (%rdx),%rdx
  7a:	48 89 11             	mov    %rdx,(%rcx)
  7d:	89 da                	mov    %ebx,%edx
  7f:	8d 5a 01             	lea    0x1(%rdx),%ebx
  82:	41 0f b6 d6          	movzbl %r14b,%edx
  86:	66 39 d3             	cmp    %dx,%bx
  89:	72 d8                	jb     63 <wl_aas+0x63>
  8b:	c1 e3 03             	shl    $0x3,%ebx
  8e:	41 0f b6 d4          	movzbl %r12b,%edx
  92:	83 e2 01             	and    $0x1,%edx
  95:	85 d2                	test   %edx,%edx
  97:	74 16                	je     af <wl_aas+0xaf>
  99:	0f b7 d3             	movzwl %bx,%edx
  9c:	4c 01 ea             	add    %r13,%rdx
  9f:	0f b7 cb             	movzwl %bx,%ecx
  a2:	48 01 c1             	add    %rax,%rcx
  a5:	0f b6 12             	movzbl (%rdx),%edx
  a8:	88 11                	mov    %dl,(%rcx)
  aa:	89 da                	mov    %ebx,%edx
  ac:	8d 5a 01             	lea    0x1(%rdx),%ebx
  af:	41 0f b6 d4          	movzbl %r12b,%edx
  b3:	83 e2 02             	and    $0x2,%edx
  b6:	85 d2                	test   %edx,%edx
  b8:	74 1b                	je     d5 <wl_aas+0xd5>
  ba:	0f b7 d3             	movzwl %bx,%edx
  bd:	48 01 d2             	add    %rdx,%rdx
  c0:	4c 01 ea             	add    %r13,%rdx
  c3:	0f b7 cb             	movzwl %bx,%ecx
  c6:	48 01 c9             	add    %rcx,%rcx
  c9:	48 01 c1             	add    %rax,%rcx
  cc:	0f b7 12             	movzwl (%rdx),%edx
  cf:	66 89 11             	mov    %dx,(%rcx)
  d2:	83 c3 02             	add    $0x2,%ebx
  d5:	41 0f b6 d4          	movzbl %r12b,%edx
  d9:	83 e2 04             	and    $0x4,%edx
  dc:	85 d2                	test   %edx,%edx
  de:	74 1b                	je     fb <wl_aas+0xfb>
  e0:	0f b7 d3             	movzwl %bx,%edx
  e3:	48 c1 e2 02          	shl    $0x2,%rdx
  e7:	4c 01 ea             	add    %r13,%rdx
  ea:	0f b7 cb             	movzwl %bx,%ecx
  ed:	48 c1 e1 02          	shl    $0x2,%rcx
  f1:	48 01 c1             	add    %rax,%rcx
  f4:	8b 12                	mov    (%rdx),%edx
  f6:	89 11                	mov    %edx,(%rcx)
  f8:	83 c3 04             	add    $0x4,%ebx
  fb:	48 83 c4 10          	add    $0x10,%rsp
  ff:	5b                   	pop    %rbx
 100:	41 5c                	pop    %r12
 102:	41 5d                	pop    %r13
 104:	41 5e                	pop    %r14
 106:	5d                   	pop    %rbp
 107:	c3                   	ret    

0000000000000108 <wl_ant>:
 108:	55                   	push   %rbp
 109:	48 89 e5             	mov    %rsp,%rbp
 10c:	41 56                	push   %r14
 10e:	41 55                	push   %r13
 110:	41 54                	push   %r12
 112:	53                   	push   %rbx
 113:	48 83 ec 10          	sub    $0x10,%rsp
 117:	89 f9                	mov    %edi,%ecx
 119:	48 89 f0             	mov    %rsi,%rax
 11c:	49 89 d5             	mov    %rdx,%r13
 11f:	89 ca                	mov    %ecx,%edx
 121:	88 55 dc             	mov    %dl,-0x24(%rbp)
 124:	48 85 c0             	test   %rax,%rax
 127:	75 27                	jne    150 <wl_ant+0x48>
 129:	0f b6 45 dc          	movzbl -0x24(%rbp),%eax
 12d:	41 b9 00 00 00 00    	mov    $0x0,%r9d
 133:	41 b8 ff ff ff ff    	mov    $0xffffffff,%r8d
 139:	b9 22 00 00 00       	mov    $0x22,%ecx
 13e:	ba 03 00 00 00       	mov    $0x3,%edx
 143:	48 89 c6             	mov    %rax,%rsi
 146:	bf 00 00 00 00       	mov    $0x0,%edi
 14b:	e8 00 00 00 00       	call   150 <wl_ant+0x48>
 150:	0f b6 55 dc          	movzbl -0x24(%rbp),%edx
 154:	c0 ea 03             	shr    $0x3,%dl
 157:	41 89 d6             	mov    %edx,%r14d
 15a:	0f b6 55 dc          	movzbl -0x24(%rbp),%edx
 15e:	83 e2 07             	and    $0x7,%edx
 161:	41 89 d4             	mov    %edx,%r12d
 164:	bb 00 00 00 00       	mov    $0x0,%ebx
 169:	eb 22                	jmp    18d <wl_ant+0x85>
 16b:	0f b7 d3             	movzwl %bx,%edx
 16e:	48 c1 e2 03          	shl    $0x3,%rdx
 172:	4c 01 ea             	add    %r13,%rdx
 175:	48 8b 0a             	mov    (%rdx),%rcx
 178:	0f b7 d3             	movzwl %bx,%edx
 17b:	48 c1 e2 03          	shl    $0x3,%rdx
 17f:	48 01 c2             	add    %rax,%rdx
 182:	48 f7 d1             	not    %rcx
 185:	48 89 0a             	mov    %rcx,(%rdx)
 188:	89 da                	mov    %ebx,%edx
 18a:	8d 5a 01             	lea    0x1(%rdx),%ebx
 18d:	41 0f b6 d6          	movzbl %r14b,%edx
 191:	66 39 d3             	cmp    %dx,%bx
 194:	72 d5                	jb     16b <wl_ant+0x63>
 196:	c1 e3 03             	shl    $0x3,%ebx
 199:	41 0f b6 d4          	movzbl %r12b,%edx
 19d:	83 e2 01             	and    $0x1,%edx
 1a0:	85 d2                	test   %edx,%edx
 1a2:	74 18                	je     1bc <wl_ant+0xb4>
 1a4:	0f b7 d3             	movzwl %bx,%edx
 1a7:	4c 01 ea             	add    %r13,%rdx
 1aa:	0f b6 0a             	movzbl (%rdx),%ecx
 1ad:	0f b7 d3             	movzwl %bx,%edx
 1b0:	48 01 c2             	add    %rax,%rdx
 1b3:	f7 d1                	not    %ecx
 1b5:	88 0a                	mov    %cl,(%rdx)
 1b7:	89 da                	mov    %ebx,%edx
 1b9:	8d 5a 01             	lea    0x1(%rdx),%ebx
 1bc:	41 0f b6 d4          	movzbl %r12b,%edx
 1c0:	83 e2 02             	and    $0x2,%edx
 1c3:	85 d2                	test   %edx,%edx
 1c5:	74 1d                	je     1e4 <wl_ant+0xdc>
 1c7:	0f b7 d3             	movzwl %bx,%edx
 1ca:	48 01 d2             	add    %rdx,%rdx
 1cd:	4c 01 ea             	add    %r13,%rdx
 1d0:	0f b7 0a             	movzwl (%rdx),%ecx
 1d3:	0f b7 d3             	movzwl %bx,%edx
 1d6:	48 01 d2             	add    %rdx,%rdx
 1d9:	48 01 c2             	add    %rax,%rdx
 1dc:	f7 d1                	not    %ecx
 1de:	66 89 0a             	mov    %cx,(%rdx)
 1e1:	83 c3 02             	add    $0x2,%ebx
 1e4:	41 0f b6 d4          	movzbl %r12b,%edx
 1e8:	83 e2 04             	and    $0x4,%edx
 1eb:	85 d2                	test   %edx,%edx
 1ed:	74 1d                	je     20c <wl_ant+0x104>
 1ef:	0f b7 d3             	movzwl %bx,%edx
 1f2:	48 c1 e2 02          	shl    $0x2,%rdx
 1f6:	4c 01 ea             	add    %r13,%rdx
 1f9:	8b 0a                	mov    (%rdx),%ecx
 1fb:	0f b7 d3             	movzwl %bx,%edx
 1fe:	48 c1 e2 02          	shl    $0x2,%rdx
 202:	48 01 c2             	add    %rax,%rdx
 205:	f7 d1                	not    %ecx
 207:	89 0a                	mov    %ecx,(%rdx)
 209:	83 c3 04             	add    $0x4,%ebx
 20c:	48 83 c4 10          	add    $0x10,%rsp
 210:	5b                   	pop    %rbx
 211:	41 5c                	pop    %r12
 213:	41 5d                	pop    %r13
 215:	41 5e                	pop    %r14
 217:	5d                   	pop    %rbp
 218:	c3                   	ret    

0000000000000219 <wl_aan>:
 219:	55                   	push   %rbp
 21a:	48 89 e5             	mov    %rsp,%rbp
 21d:	41 57                	push   %r15
 21f:	41 56                	push   %r14
 221:	41 55                	push   %r13
 223:	41 54                	push   %r12
 225:	53                   	push   %rbx
 226:	48 83 ec 18          	sub    $0x18,%rsp
 22a:	48 89 f0             	mov    %rsi,%rax
 22d:	49 89 d6             	mov    %rdx,%r14
 230:	49 89 cd             	mov    %rcx,%r13
 233:	89 fa                	mov    %edi,%edx
 235:	88 55 cc             	mov    %dl,-0x34(%rbp)
 238:	48 85 c0             	test   %rax,%rax
 23b:	75 27                	jne    264 <wl_aan+0x4b>
 23d:	0f b6 45 cc          	movzbl -0x34(%rbp),%eax
 241:	41 b9 00 00 00 00    	mov    $0x0,%r9d
 247:	41 b8 ff ff ff ff    	mov    $0xffffffff,%r8d
 24d:	b9 22 00 00 00       	mov    $0x22,%ecx
 252:	ba 03 00 00 00       	mov    $0x3,%edx
 257:	48 89 c6             	mov    %rax,%rsi
 25a:	bf 00 00 00 00       	mov    $0x0,%edi
 25f:	e8 00 00 00 00       	call   264 <wl_aan+0x4b>
 264:	0f b6 55 cc          	movzbl -0x34(%rbp),%edx
 268:	c0 ea 03             	shr    $0x3,%dl
 26b:	41 89 d7             	mov    %edx,%r15d
 26e:	0f b6 55 cc          	movzbl -0x34(%rbp),%edx
 272:	83 e2 07             	and    $0x7,%edx
 275:	41 89 d4             	mov    %edx,%r12d
 278:	bb 00 00 00 00       	mov    $0x0,%ebx
 27d:	eb 2f                	jmp    2ae <wl_aan+0x95>
 27f:	0f b7 d3             	movzwl %bx,%edx
 282:	48 c1 e2 03          	shl    $0x3,%rdx
 286:	4c 01 f2             	add    %r14,%rdx
 289:	48 8b 32             	mov    (%rdx),%rsi
 28c:	0f b7 d3             	movzwl %bx,%edx
 28f:	48 c1 e2 03          	shl    $0x3,%rdx
 293:	4c 01 ea             	add    %r13,%rdx
 296:	48 8b 0a             	mov    (%rdx),%rcx
 299:	0f b7 d3             	movzwl %bx,%edx
 29c:	48 c1 e2 03          	shl    $0x3,%rdx
 2a0:	48 01 c2             	add    %rax,%rdx
 2a3:	48 21 f1             	and    %rsi,%rcx
 2a6:	48 89 0a             	mov    %rcx,(%rdx)
 2a9:	89 da                	mov    %ebx,%edx
 2ab:	8d 5a 01             	lea    0x1(%rdx),%ebx
 2ae:	41 0f b6 d7          	movzbl %r15b,%edx
 2b2:	66 39 d3             	cmp    %dx,%bx
 2b5:	72 c8                	jb     27f <wl_aan+0x66>
 2b7:	c1 e3 03             	shl    $0x3,%ebx
 2ba:	41 0f b6 d4          	movzbl %r12b,%edx
 2be:	83 e2 01             	and    $0x1,%edx
 2c1:	85 d2                	test   %edx,%edx
 2c3:	74 21                	je     2e6 <wl_aan+0xcd>
 2c5:	0f b7 d3             	movzwl %bx,%edx
 2c8:	4c 01 f2             	add    %r14,%rdx
 2cb:	0f b6 32             	movzbl (%rdx),%esi
 2ce:	0f b7 d3             	movzwl %bx,%edx
 2d1:	4c 01 ea             	add    %r13,%rdx
 2d4:	0f b6 0a             	movzbl (%rdx),%ecx
 2d7:	0f b7 d3             	movzwl %bx,%edx
 2da:	48 01 c2             	add    %rax,%rdx
 2dd:	21 f1                	and    %esi,%ecx
 2df:	88 0a                	mov    %cl,(%rdx)
 2e1:	89 da                	mov    %ebx,%edx
 2e3:	8d 5a 01             	lea    0x1(%rdx),%ebx
 2e6:	41 0f b6 d4          	movzbl %r12b,%edx
 2ea:	83 e2 02             	and    $0x2,%edx
 2ed:	85 d2                	test   %edx,%edx
 2ef:	74 29                	je     31a <wl_aan+0x101>
 2f1:	0f b7 d3             	movzwl %bx,%edx
 2f4:	48 01 d2             	add    %rdx,%rdx
 2f7:	4c 01 f2             	add    %r14,%rdx
 2fa:	0f b7 32             	movzwl (%rdx),%esi
 2fd:	0f b7 d3             	movzwl %bx,%edx
 300:	48 01 d2             	add    %rdx,%rdx
 303:	4c 01 ea             	add    %r13,%rdx
 306:	0f b7 0a             	movzwl (%rdx),%ecx
 309:	0f b7 d3             	movzwl %bx,%edx
 30c:	48 01 d2             	add    %rdx,%rdx
 30f:	48 01 c2             	add    %rax,%rdx
 312:	21 f1                	and    %esi,%ecx
 314:	66 89 0a             	mov    %cx,(%rdx)
 317:	83 c3 02             	add    $0x2,%ebx
 31a:	41 0f b6 d4          	movzbl %r12b,%edx
 31e:	83 e2 04             	and    $0x4,%edx
 321:	85 d2                	test   %edx,%edx
 323:	74 29                	je     34e <wl_aan+0x135>
 325:	0f b7 d3             	movzwl %bx,%edx
 328:	48 c1 e2 02          	shl    $0x2,%rdx
 32c:	4c 01 f2             	add    %r14,%rdx
 32f:	8b 32                	mov    (%rdx),%esi
 331:	0f b7 d3             	movzwl %bx,%edx
 334:	48 c1 e2 02          	shl    $0x2,%rdx
 338:	4c 01 ea             	add    %r13,%rdx
 33b:	8b 0a                	mov    (%rdx),%ecx
 33d:	0f b7 d3             	movzwl %bx,%edx
 340:	48 c1 e2 02          	shl    $0x2,%rdx
 344:	48 01 c2             	add    %rax,%rdx
 347:	21 f1                	and    %esi,%ecx
 349:	89 0a                	mov    %ecx,(%rdx)
 34b:	83 c3 04             	add    $0x4,%ebx
 34e:	48 83 c4 18          	add    $0x18,%rsp
 352:	5b                   	pop    %rbx
 353:	41 5c                	pop    %r12
 355:	41 5d                	pop    %r13
 357:	41 5e                	pop    %r14
 359:	41 5f                	pop    %r15
 35b:	5d                   	pop    %rbp
 35c:	c3                   	ret    

000000000000035d <wl_aor>:
 35d:	55                   	push   %rbp
 35e:	48 89 e5             	mov    %rsp,%rbp
 361:	41 57                	push   %r15
 363:	41 56                	push   %r14
 365:	41 55                	push   %r13
 367:	41 54                	push   %r12
 369:	53                   	push   %rbx
 36a:	48 83 ec 18          	sub    $0x18,%rsp
 36e:	48 89 f0             	mov    %rsi,%rax
 371:	49 89 d6             	mov    %rdx,%r14
 374:	49 89 cd             	mov    %rcx,%r13
 377:	89 fa                	mov    %edi,%edx
 379:	88 55 cc             	mov    %dl,-0x34(%rbp)
 37c:	48 85 c0             	test   %rax,%rax
 37f:	75 27                	jne    3a8 <wl_aor+0x4b>
 381:	0f b6 45 cc          	movzbl -0x34(%rbp),%eax
 385:	41 b9 00 00 00 00    	mov    $0x0,%r9d
 38b:	41 b8 ff ff ff ff    	mov    $0xffffffff,%r8d
 391:	b9 22 00 00 00       	mov    $0x22,%ecx
 396:	ba 03 00 00 00       	mov    $0x3,%edx
 39b:	48 89 c6             	mov    %rax,%rsi
 39e:	bf 00 00 00 00       	mov    $0x0,%edi
 3a3:	e8 00 00 00 00       	call   3a8 <wl_aor+0x4b>
 3a8:	0f b6 55 cc          	movzbl -0x34(%rbp),%edx
 3ac:	c0 ea 03             	shr    $0x3,%dl
 3af:	41 89 d7             	mov    %edx,%r15d
 3b2:	0f b6 55 cc          	movzbl -0x34(%rbp),%edx
 3b6:	83 e2 07             	and    $0x7,%edx
 3b9:	41 89 d4             	mov    %edx,%r12d
 3bc:	bb 00 00 00 00       	mov    $0x0,%ebx
 3c1:	eb 2f                	jmp    3f2 <wl_aor+0x95>
 3c3:	0f b7 d3             	movzwl %bx,%edx
 3c6:	48 c1 e2 03          	shl    $0x3,%rdx
 3ca:	4c 01 f2             	add    %r14,%rdx
 3cd:	48 8b 32             	mov    (%rdx),%rsi
 3d0:	0f b7 d3             	movzwl %bx,%edx
 3d3:	48 c1 e2 03          	shl    $0x3,%rdx
 3d7:	4c 01 ea             	add    %r13,%rdx
 3da:	48 8b 0a             	mov    (%rdx),%rcx
 3dd:	0f b7 d3             	movzwl %bx,%edx
 3e0:	48 c1 e2 03          	shl    $0x3,%rdx
 3e4:	48 01 c2             	add    %rax,%rdx
 3e7:	48 09 f1             	or     %rsi,%rcx
 3ea:	48 89 0a             	mov    %rcx,(%rdx)
 3ed:	89 da                	mov    %ebx,%edx
 3ef:	8d 5a 01             	lea    0x1(%rdx),%ebx
 3f2:	41 0f b6 d7          	movzbl %r15b,%edx
 3f6:	66 39 d3             	cmp    %dx,%bx
 3f9:	72 c8                	jb     3c3 <wl_aor+0x66>
 3fb:	c1 e3 03             	shl    $0x3,%ebx
 3fe:	41 0f b6 d4          	movzbl %r12b,%edx
 402:	83 e2 01             	and    $0x1,%edx
 405:	85 d2                	test   %edx,%edx
 407:	74 21                	je     42a <wl_aor+0xcd>
 409:	0f b7 d3             	movzwl %bx,%edx
 40c:	4c 01 f2             	add    %r14,%rdx
 40f:	0f b6 32             	movzbl (%rdx),%esi
 412:	0f b7 d3             	movzwl %bx,%edx
 415:	4c 01 ea             	add    %r13,%rdx
 418:	0f b6 0a             	movzbl (%rdx),%ecx
 41b:	0f b7 d3             	movzwl %bx,%edx
 41e:	48 01 c2             	add    %rax,%rdx
 421:	09 f1                	or     %esi,%ecx
 423:	88 0a                	mov    %cl,(%rdx)
 425:	89 da                	mov    %ebx,%edx
 427:	8d 5a 01             	lea    0x1(%rdx),%ebx
 42a:	41 0f b6 d4          	movzbl %r12b,%edx
 42e:	83 e2 02             	and    $0x2,%edx
 431:	85 d2                	test   %edx,%edx
 433:	74 29                	je     45e <wl_aor+0x101>
 435:	0f b7 d3             	movzwl %bx,%edx
 438:	48 01 d2             	add    %rdx,%rdx
 43b:	4c 01 f2             	add    %r14,%rdx
 43e:	0f b7 32             	movzwl (%rdx),%esi
 441:	0f b7 d3             	movzwl %bx,%edx
 444:	48 01 d2             	add    %rdx,%rdx
 447:	4c 01 ea             	add    %r13,%rdx
 44a:	0f b7 0a             	movzwl (%rdx),%ecx
 44d:	0f b7 d3             	movzwl %bx,%edx
 450:	48 01 d2             	add    %rdx,%rdx
 453:	48 01 c2             	add    %rax,%rdx
 456:	09 f1                	or     %esi,%ecx
 458:	66 89 0a             	mov    %cx,(%rdx)
 45b:	83 c3 02             	add    $0x2,%ebx
 45e:	41 0f b6 d4          	movzbl %r12b,%edx
 462:	83 e2 04             	and    $0x4,%edx
 465:	85 d2                	test   %edx,%edx
 467:	74 29                	je     492 <wl_aor+0x135>
 469:	0f b7 d3             	movzwl %bx,%edx
 46c:	48 c1 e2 02          	shl    $0x2,%rdx
 470:	4c 01 f2             	add    %r14,%rdx
 473:	8b 32                	mov    (%rdx),%esi
 475:	0f b7 d3             	movzwl %bx,%edx
 478:	48 c1 e2 02          	shl    $0x2,%rdx
 47c:	4c 01 ea             	add    %r13,%rdx
 47f:	8b 0a                	mov    (%rdx),%ecx
 481:	0f b7 d3             	movzwl %bx,%edx
 484:	48 c1 e2 02          	shl    $0x2,%rdx
 488:	48 01 c2             	add    %rax,%rdx
 48b:	09 f1                	or     %esi,%ecx
 48d:	89 0a                	mov    %ecx,(%rdx)
 48f:	83 c3 04             	add    $0x4,%ebx
 492:	48 83 c4 18          	add    $0x18,%rsp
 496:	5b                   	pop    %rbx
 497:	41 5c                	pop    %r12
 499:	41 5d                	pop    %r13
 49b:	41 5e                	pop    %r14
 49d:	41 5f                	pop    %r15
 49f:	5d                   	pop    %rbp
 4a0:	c3                   	ret    

00000000000004a1 <wl_axr>:
 4a1:	55                   	push   %rbp
 4a2:	48 89 e5             	mov    %rsp,%rbp
 4a5:	41 57                	push   %r15
 4a7:	41 56                	push   %r14
 4a9:	41 55                	push   %r13
 4ab:	41 54                	push   %r12
 4ad:	53                   	push   %rbx
 4ae:	48 83 ec 18          	sub    $0x18,%rsp
 4b2:	48 89 f0             	mov    %rsi,%rax
 4b5:	49 89 d6             	mov    %rdx,%r14
 4b8:	49 89 cd             	mov    %rcx,%r13
 4bb:	89 fa                	mov    %edi,%edx
 4bd:	88 55 cc             	mov    %dl,-0x34(%rbp)
 4c0:	48 85 c0             	test   %rax,%rax
 4c3:	75 27                	jne    4ec <wl_axr+0x4b>
 4c5:	0f b6 45 cc          	movzbl -0x34(%rbp),%eax
 4c9:	41 b9 00 00 00 00    	mov    $0x0,%r9d
 4cf:	41 b8 ff ff ff ff    	mov    $0xffffffff,%r8d
 4d5:	b9 22 00 00 00       	mov    $0x22,%ecx
 4da:	ba 03 00 00 00       	mov    $0x3,%edx
 4df:	48 89 c6             	mov    %rax,%rsi
 4e2:	bf 00 00 00 00       	mov    $0x0,%edi
 4e7:	e8 00 00 00 00       	call   4ec <wl_axr+0x4b>
 4ec:	0f b6 55 cc          	movzbl -0x34(%rbp),%edx
 4f0:	c0 ea 03             	shr    $0x3,%dl
 4f3:	41 89 d7             	mov    %edx,%r15d
 4f6:	0f b6 55 cc          	movzbl -0x34(%rbp),%edx
 4fa:	83 e2 07             	and    $0x7,%edx
 4fd:	41 89 d4             	mov    %edx,%r12d
 500:	bb 00 00 00 00       	mov    $0x0,%ebx
 505:	eb 2f                	jmp    536 <wl_axr+0x95>
 507:	0f b7 d3             	movzwl %bx,%edx
 50a:	48 c1 e2 03          	shl    $0x3,%rdx
 50e:	4c 01 f2             	add    %r14,%rdx
 511:	48 8b 32             	mov    (%rdx),%rsi
 514:	0f b7 d3             	movzwl %bx,%edx
 517:	48 c1 e2 03          	shl    $0x3,%rdx
 51b:	4c 01 ea             	add    %r13,%rdx
 51e:	48 8b 0a             	mov    (%rdx),%rcx
 521:	0f b7 d3             	movzwl %bx,%edx
 524:	48 c1 e2 03          	shl    $0x3,%rdx
 528:	48 01 c2             	add    %rax,%rdx
 52b:	48 31 f1             	xor    %rsi,%rcx
 52e:	48 89 0a             	mov    %rcx,(%rdx)
 531:	89 da                	mov    %ebx,%edx
 533:	8d 5a 01             	lea    0x1(%rdx),%ebx
 536:	41 0f b6 d7          	movzbl %r15b,%edx
 53a:	66 39 d3             	cmp    %dx,%bx
 53d:	72 c8                	jb     507 <wl_axr+0x66>
 53f:	c1 e3 03             	shl    $0x3,%ebx
 542:	41 0f b6 d4          	movzbl %r12b,%edx
 546:	83 e2 01             	and    $0x1,%edx
 549:	85 d2                	test   %edx,%edx
 54b:	74 21                	je     56e <wl_axr+0xcd>
 54d:	0f b7 d3             	movzwl %bx,%edx
 550:	4c 01 f2             	add    %r14,%rdx
 553:	0f b6 32             	movzbl (%rdx),%esi
 556:	0f b7 d3             	movzwl %bx,%edx
 559:	4c 01 ea             	add    %r13,%rdx
 55c:	0f b6 0a             	movzbl (%rdx),%ecx
 55f:	0f b7 d3             	movzwl %bx,%edx
 562:	48 01 c2             	add    %rax,%rdx
 565:	31 f1                	xor    %esi,%ecx
 567:	88 0a                	mov    %cl,(%rdx)
 569:	89 da                	mov    %ebx,%edx
 56b:	8d 5a 01             	lea    0x1(%rdx),%ebx
 56e:	41 0f b6 d4          	movzbl %r12b,%edx
 572:	83 e2 02             	and    $0x2,%edx
 575:	85 d2                	test   %edx,%edx
 577:	74 29                	je     5a2 <wl_axr+0x101>
 579:	0f b7 d3             	movzwl %bx,%edx
 57c:	48 01 d2             	add    %rdx,%rdx
 57f:	4c 01 f2             	add    %r14,%rdx
 582:	0f b7 32             	movzwl (%rdx),%esi
 585:	0f b7 d3             	movzwl %bx,%edx
 588:	48 01 d2             	add    %rdx,%rdx
 58b:	4c 01 ea             	add    %r13,%rdx
 58e:	0f b7 0a             	movzwl (%rdx),%ecx
 591:	0f b7 d3             	movzwl %bx,%edx
 594:	48 01 d2             	add    %rdx,%rdx
 597:	48 01 c2             	add    %rax,%rdx
 59a:	31 f1                	xor    %esi,%ecx
 59c:	66 89 0a             	mov    %cx,(%rdx)
 59f:	83 c3 02             	add    $0x2,%ebx
 5a2:	41 0f b6 d4          	movzbl %r12b,%edx
 5a6:	83 e2 04             	and    $0x4,%edx
 5a9:	85 d2                	test   %edx,%edx
 5ab:	74 29                	je     5d6 <wl_axr+0x135>
 5ad:	0f b7 d3             	movzwl %bx,%edx
 5b0:	48 c1 e2 02          	shl    $0x2,%rdx
 5b4:	4c 01 f2             	add    %r14,%rdx
 5b7:	8b 32                	mov    (%rdx),%esi
 5b9:	0f b7 d3             	movzwl %bx,%edx
 5bc:	48 c1 e2 02          	shl    $0x2,%rdx
 5c0:	4c 01 ea             	add    %r13,%rdx
 5c3:	8b 0a                	mov    (%rdx),%ecx
 5c5:	0f b7 d3             	movzwl %bx,%edx
 5c8:	48 c1 e2 02          	shl    $0x2,%rdx
 5cc:	48 01 c2             	add    %rax,%rdx
 5cf:	31 f1                	xor    %esi,%ecx
 5d1:	89 0a                	mov    %ecx,(%rdx)
 5d3:	83 c3 04             	add    $0x4,%ebx
 5d6:	48 83 c4 18          	add    $0x18,%rsp
 5da:	5b                   	pop    %rbx
 5db:	41 5c                	pop    %r12
 5dd:	41 5d                	pop    %r13
 5df:	41 5e                	pop    %r14
 5e1:	41 5f                	pop    %r15
 5e3:	5d                   	pop    %rbp
 5e4:	c3                   	ret    

00000000000005e5 <wl_ann>:
 5e5:	55                   	push   %rbp
 5e6:	48 89 e5             	mov    %rsp,%rbp
 5e9:	41 57                	push   %r15
 5eb:	41 56                	push   %r14
 5ed:	41 55                	push   %r13
 5ef:	41 54                	push   %r12
 5f1:	53                   	push   %rbx
 5f2:	48 83 ec 18          	sub    $0x18,%rsp
 5f6:	48 89 f0             	mov    %rsi,%rax
 5f9:	49 89 d6             	mov    %rdx,%r14
 5fc:	49 89 cd             	mov    %rcx,%r13
 5ff:	89 fa                	mov    %edi,%edx
 601:	88 55 cc             	mov    %dl,-0x34(%rbp)
 604:	48 85 c0             	test   %rax,%rax
 607:	75 27                	jne    630 <wl_ann+0x4b>
 609:	0f b6 45 cc          	movzbl -0x34(%rbp),%eax
 60d:	41 b9 00 00 00 00    	mov    $0x0,%r9d
 613:	41 b8 ff ff ff ff    	mov    $0xffffffff,%r8d
 619:	b9 22 00 00 00       	mov    $0x22,%ecx
 61e:	ba 03 00 00 00       	mov    $0x3,%edx
 623:	48 89 c6             	mov    %rax,%rsi
 626:	bf 00 00 00 00       	mov    $0x0,%edi
 62b:	e8 00 00 00 00       	call   630 <wl_ann+0x4b>
 630:	0f b6 55 cc          	movzbl -0x34(%rbp),%edx
 634:	c0 ea 03             	shr    $0x3,%dl
 637:	41 89 d7             	mov    %edx,%r15d
 63a:	0f b6 55 cc          	movzbl -0x34(%rbp),%edx
 63e:	83 e2 07             	and    $0x7,%edx
 641:	41 89 d4             	mov    %edx,%r12d
 644:	bb 00 00 00 00       	mov    $0x0,%ebx
 649:	eb 32                	jmp    67d <wl_ann+0x98>
 64b:	0f b7 d3             	movzwl %bx,%edx
 64e:	48 c1 e2 03          	shl    $0x3,%rdx
 652:	4c 01 f2             	add    %r14,%rdx
 655:	48 8b 0a             	mov    (%rdx),%rcx
 658:	0f b7 d3             	movzwl %bx,%edx
 65b:	48 c1 e2 03          	shl    $0x3,%rdx
 65f:	4c 01 ea             	add    %r13,%rdx
 662:	48 8b 12             	mov    (%rdx),%rdx
 665:	48 21 d1             	and    %rdx,%rcx
 668:	0f b7 d3             	movzwl %bx,%edx
 66b:	48 c1 e2 03          	shl    $0x3,%rdx
 66f:	48 01 c2             	add    %rax,%rdx
 672:	48 f7 d1             	not    %rcx
 675:	48 89 0a             	mov    %rcx,(%rdx)
 678:	89 da                	mov    %ebx,%edx
 67a:	8d 5a 01             	lea    0x1(%rdx),%ebx
 67d:	41 0f b6 d7          	movzbl %r15b,%edx
 681:	66 39 d3             	cmp    %dx,%bx
 684:	72 c5                	jb     64b <wl_ann+0x66>
 686:	c1 e3 03             	shl    $0x3,%ebx
 689:	41 0f b6 d4          	movzbl %r12b,%edx
 68d:	83 e2 01             	and    $0x1,%edx
 690:	85 d2                	test   %edx,%edx
 692:	74 23                	je     6b7 <wl_ann+0xd2>
 694:	0f b7 d3             	movzwl %bx,%edx
 697:	4c 01 f2             	add    %r14,%rdx
 69a:	0f b6 0a             	movzbl (%rdx),%ecx
 69d:	0f b7 d3             	movzwl %bx,%edx
 6a0:	4c 01 ea             	add    %r13,%rdx
 6a3:	0f b6 12             	movzbl (%rdx),%edx
 6a6:	21 d1                	and    %edx,%ecx
 6a8:	0f b7 d3             	movzwl %bx,%edx
 6ab:	48 01 c2             	add    %rax,%rdx
 6ae:	f7 d1                	not    %ecx
 6b0:	88 0a                	mov    %cl,(%rdx)
 6b2:	89 da                	mov    %ebx,%edx
 6b4:	8d 5a 01             	lea    0x1(%rdx),%ebx
 6b7:	41 0f b6 d4          	movzbl %r12b,%edx
 6bb:	83 e2 02             	and    $0x2,%edx
 6be:	85 d2                	test   %edx,%edx
 6c0:	74 2b                	je     6ed <wl_ann+0x108>
 6c2:	0f b7 d3             	movzwl %bx,%edx
 6c5:	48 01 d2             	add    %rdx,%rdx
 6c8:	4c 01 f2             	add    %r14,%rdx
 6cb:	0f b7 0a             	movzwl (%rdx),%ecx
 6ce:	0f b7 d3             	movzwl %bx,%edx
 6d1:	48 01 d2             	add    %rdx,%rdx
 6d4:	4c 01 ea             	add    %r13,%rdx
 6d7:	0f b7 12             	movzwl (%rdx),%edx
 6da:	21 d1                	and    %edx,%ecx
 6dc:	0f b7 d3             	movzwl %bx,%edx
 6df:	48 01 d2             	add    %rdx,%rdx
 6e2:	48 01 c2             	add    %rax,%rdx
 6e5:	f7 d1                	not    %ecx
 6e7:	66 89 0a             	mov    %cx,(%rdx)
 6ea:	83 c3 02             	add    $0x2,%ebx
 6ed:	41 0f b6 d4          	movzbl %r12b,%edx
 6f1:	83 e2 04             	and    $0x4,%edx
 6f4:	85 d2                	test   %edx,%edx
 6f6:	74 2b                	je     723 <wl_ann+0x13e>
 6f8:	0f b7 d3             	movzwl %bx,%edx
 6fb:	48 c1 e2 02          	shl    $0x2,%rdx
 6ff:	4c 01 f2             	add    %r14,%rdx
 702:	8b 0a                	mov    (%rdx),%ecx
 704:	0f b7 d3             	movzwl %bx,%edx
 707:	48 c1 e2 02          	shl    $0x2,%rdx
 70b:	4c 01 ea             	add    %r13,%rdx
 70e:	8b 12                	mov    (%rdx),%edx
 710:	21 d1                	and    %edx,%ecx
 712:	0f b7 d3             	movzwl %bx,%edx
 715:	48 c1 e2 02          	shl    $0x2,%rdx
 719:	48 01 c2             	add    %rax,%rdx
 71c:	f7 d1                	not    %ecx
 71e:	89 0a                	mov    %ecx,(%rdx)
 720:	83 c3 04             	add    $0x4,%ebx
 723:	48 83 c4 18          	add    $0x18,%rsp
 727:	5b                   	pop    %rbx
 728:	41 5c                	pop    %r12
 72a:	41 5d                	pop    %r13
 72c:	41 5e                	pop    %r14
 72e:	41 5f                	pop    %r15
 730:	5d                   	pop    %rbp
 731:	c3                   	ret    

0000000000000732 <wl_anr>:
 732:	55                   	push   %rbp
 733:	48 89 e5             	mov    %rsp,%rbp
 736:	41 57                	push   %r15
 738:	41 56                	push   %r14
 73a:	41 55                	push   %r13
 73c:	41 54                	push   %r12
 73e:	53                   	push   %rbx
 73f:	48 83 ec 18          	sub    $0x18,%rsp
 743:	48 89 f0             	mov    %rsi,%rax
 746:	49 89 d6             	mov    %rdx,%r14
 749:	49 89 cd             	mov    %rcx,%r13
 74c:	89 fa                	mov    %edi,%edx
 74e:	88 55 cc             	mov    %dl,-0x34(%rbp)
 751:	48 85 c0             	test   %rax,%rax
 754:	75 27                	jne    77d <wl_anr+0x4b>
 756:	0f b6 45 cc          	movzbl -0x34(%rbp),%eax
 75a:	41 b9 00 00 00 00    	mov    $0x0,%r9d
 760:	41 b8 ff ff ff ff    	mov    $0xffffffff,%r8d
 766:	b9 22 00 00 00       	mov    $0x22,%ecx
 76b:	ba 03 00 00 00       	mov    $0x3,%edx
 770:	48 89 c6             	mov    %rax,%rsi
 773:	bf 00 00 00 00       	mov    $0x0,%edi
 778:	e8 00 00 00 00       	call   77d <wl_anr+0x4b>
 77d:	0f b6 55 cc          	movzbl -0x34(%rbp),%edx
 781:	c0 ea 03             	shr    $0x3,%dl
 784:	41 89 d7             	mov    %edx,%r15d
 787:	0f b6 55 cc          	movzbl -0x34(%rbp),%edx
 78b:	83 e2 07             	and    $0x7,%edx
 78e:	41 89 d4             	mov    %edx,%r12d
 791:	bb 00 00 00 00       	mov    $0x0,%ebx
 796:	eb 32                	jmp    7ca <wl_anr+0x98>
 798:	0f b7 d3             	movzwl %bx,%edx
 79b:	48 c1 e2 03          	shl    $0x3,%rdx
 79f:	4c 01 f2             	add    %r14,%rdx
 7a2:	48 8b 0a             	mov    (%rdx),%rcx
 7a5:	0f b7 d3             	movzwl %bx,%edx
 7a8:	48 c1 e2 03          	shl    $0x3,%rdx
 7ac:	4c 01 ea             	add    %r13,%rdx
 7af:	48 8b 12             	mov    (%rdx),%rdx
 7b2:	48 09 d1             	or     %rdx,%rcx
 7b5:	0f b7 d3             	movzwl %bx,%edx
 7b8:	48 c1 e2 03          	shl    $0x3,%rdx
 7bc:	48 01 c2             	add    %rax,%rdx
 7bf:	48 f7 d1             	not    %rcx
 7c2:	48 89 0a             	mov    %rcx,(%rdx)
 7c5:	89 da                	mov    %ebx,%edx
 7c7:	8d 5a 01             	lea    0x1(%rdx),%ebx
 7ca:	41 0f b6 d7          	movzbl %r15b,%edx
 7ce:	66 39 d3             	cmp    %dx,%bx
 7d1:	72 c5                	jb     798 <wl_anr+0x66>
 7d3:	c1 e3 03             	shl    $0x3,%ebx
 7d6:	41 0f b6 d4          	movzbl %r12b,%edx
 7da:	83 e2 01             	and    $0x1,%edx
 7dd:	85 d2                	test   %edx,%edx
 7df:	74 23                	je     804 <wl_anr+0xd2>
 7e1:	0f b7 d3             	movzwl %bx,%edx
 7e4:	4c 01 f2             	add    %r14,%rdx
 7e7:	0f b6 0a             	movzbl (%rdx),%ecx
 7ea:	0f b7 d3             	movzwl %bx,%edx
 7ed:	4c 01 ea             	add    %r13,%rdx
 7f0:	0f b6 12             	movzbl (%rdx),%edx
 7f3:	09 d1                	or     %edx,%ecx
 7f5:	0f b7 d3             	movzwl %bx,%edx
 7f8:	48 01 c2             	add    %rax,%rdx
 7fb:	f7 d1                	not    %ecx
 7fd:	88 0a                	mov    %cl,(%rdx)
 7ff:	89 da                	mov    %ebx,%edx
 801:	8d 5a 01             	lea    0x1(%rdx),%ebx
 804:	41 0f b6 d4          	movzbl %r12b,%edx
 808:	83 e2 02             	and    $0x2,%edx
 80b:	85 d2                	test   %edx,%edx
 80d:	74 2b                	je     83a <wl_anr+0x108>
 80f:	0f b7 d3             	movzwl %bx,%edx
 812:	48 01 d2             	add    %rdx,%rdx
 815:	4c 01 f2             	add    %r14,%rdx
 818:	0f b7 0a             	movzwl (%rdx),%ecx
 81b:	0f b7 d3             	movzwl %bx,%edx
 81e:	48 01 d2             	add    %rdx,%rdx
 821:	4c 01 ea             	add    %r13,%rdx
 824:	0f b7 12             	movzwl (%rdx),%edx
 827:	09 d1                	or     %edx,%ecx
 829:	0f b7 d3             	movzwl %bx,%edx
 82c:	48 01 d2             	add    %rdx,%rdx
 82f:	48 01 c2             	add    %rax,%rdx
 832:	f7 d1                	not    %ecx
 834:	66 89 0a             	mov    %cx,(%rdx)
 837:	83 c3 02             	add    $0x2,%ebx
 83a:	41 0f b6 d4          	movzbl %r12b,%edx
 83e:	83 e2 04             	and    $0x4,%edx
 841:	85 d2                	test   %edx,%edx
 843:	74 2b                	je     870 <wl_anr+0x13e>
 845:	0f b7 d3             	movzwl %bx,%edx
 848:	48 c1 e2 02          	shl    $0x2,%rdx
 84c:	4c 01 f2             	add    %r14,%rdx
 84f:	8b 0a                	mov    (%rdx),%ecx
 851:	0f b7 d3             	movzwl %bx,%edx
 854:	48 c1 e2 02          	shl    $0x2,%rdx
 858:	4c 01 ea             	add    %r13,%rdx
 85b:	8b 12                	mov    (%rdx),%edx
 85d:	09 d1                	or     %edx,%ecx
 85f:	0f b7 d3             	movzwl %bx,%edx
 862:	48 c1 e2 02          	shl    $0x2,%rdx
 866:	48 01 c2             	add    %rax,%rdx
 869:	f7 d1                	not    %ecx
 86b:	89 0a                	mov    %ecx,(%rdx)
 86d:	83 c3 04             	add    $0x4,%ebx
 870:	48 83 c4 18          	add    $0x18,%rsp
 874:	5b                   	pop    %rbx
 875:	41 5c                	pop    %r12
 877:	41 5d                	pop    %r13
 879:	41 5e                	pop    %r14
 87b:	41 5f                	pop    %r15
 87d:	5d                   	pop    %rbp
 87e:	c3                   	ret    

000000000000087f <wl_anx>:
 87f:	55                   	push   %rbp
 880:	48 89 e5             	mov    %rsp,%rbp
 883:	41 57                	push   %r15
 885:	41 56                	push   %r14
 887:	41 55                	push   %r13
 889:	41 54                	push   %r12
 88b:	53                   	push   %rbx
 88c:	48 83 ec 18          	sub    $0x18,%rsp
 890:	48 89 f0             	mov    %rsi,%rax
 893:	49 89 d6             	mov    %rdx,%r14
 896:	49 89 cd             	mov    %rcx,%r13
 899:	89 fa                	mov    %edi,%edx
 89b:	88 55 cc             	mov    %dl,-0x34(%rbp)
 89e:	48 85 c0             	test   %rax,%rax
 8a1:	75 27                	jne    8ca <wl_anx+0x4b>
 8a3:	0f b6 45 cc          	movzbl -0x34(%rbp),%eax
 8a7:	41 b9 00 00 00 00    	mov    $0x0,%r9d
 8ad:	41 b8 ff ff ff ff    	mov    $0xffffffff,%r8d
 8b3:	b9 22 00 00 00       	mov    $0x22,%ecx
 8b8:	ba 03 00 00 00       	mov    $0x3,%edx
 8bd:	48 89 c6             	mov    %rax,%rsi
 8c0:	bf 00 00 00 00       	mov    $0x0,%edi
 8c5:	e8 00 00 00 00       	call   8ca <wl_anx+0x4b>
 8ca:	0f b6 55 cc          	movzbl -0x34(%rbp),%edx
 8ce:	c0 ea 03             	shr    $0x3,%dl
 8d1:	41 89 d7             	mov    %edx,%r15d
 8d4:	0f b6 55 cc          	movzbl -0x34(%rbp),%edx
 8d8:	83 e2 07             	and    $0x7,%edx
 8db:	41 89 d4             	mov    %edx,%r12d
 8de:	bb 00 00 00 00       	mov    $0x0,%ebx
 8e3:	eb 32                	jmp    917 <wl_anx+0x98>
 8e5:	0f b7 d3             	movzwl %bx,%edx
 8e8:	48 c1 e2 03          	shl    $0x3,%rdx
 8ec:	4c 01 f2             	add    %r14,%rdx
 8ef:	48 8b 0a             	mov    (%rdx),%rcx
 8f2:	0f b7 d3             	movzwl %bx,%edx
 8f5:	48 c1 e2 03          	shl    $0x3,%rdx
 8f9:	4c 01 ea             	add    %r13,%rdx
 8fc:	48 8b 12             	mov    (%rdx),%rdx
 8ff:	48 31 d1             	xor    %rdx,%rcx
 902:	0f b7 d3             	movzwl %bx,%edx
 905:	48 c1 e2 03          	shl    $0x3,%rdx
 909:	48 01 c2             	add    %rax,%rdx
 90c:	48 f7 d1             	not    %rcx
 90f:	48 89 0a             	mov    %rcx,(%rdx)
 912:	89 da                	mov    %ebx,%edx
 914:	8d 5a 01             	lea    0x1(%rdx),%ebx
 917:	41 0f b6 d7          	movzbl %r15b,%edx
 91b:	66 39 d3             	cmp    %dx,%bx
 91e:	72 c5                	jb     8e5 <wl_anx+0x66>
 920:	c1 e3 03             	shl    $0x3,%ebx
 923:	41 0f b6 d4          	movzbl %r12b,%edx
 927:	83 e2 01             	and    $0x1,%edx
 92a:	85 d2                	test   %edx,%edx
 92c:	74 23                	je     951 <wl_anx+0xd2>
 92e:	0f b7 d3             	movzwl %bx,%edx
 931:	4c 01 f2             	add    %r14,%rdx
 934:	0f b6 0a             	movzbl (%rdx),%ecx
 937:	0f b7 d3             	movzwl %bx,%edx
 93a:	4c 01 ea             	add    %r13,%rdx
 93d:	0f b6 12             	movzbl (%rdx),%edx
 940:	31 d1                	xor    %edx,%ecx
 942:	0f b7 d3             	movzwl %bx,%edx
 945:	48 01 c2             	add    %rax,%rdx
 948:	f7 d1                	not    %ecx
 94a:	88 0a                	mov    %cl,(%rdx)
 94c:	89 da                	mov    %ebx,%edx
 94e:	8d 5a 01             	lea    0x1(%rdx),%ebx
 951:	41 0f b6 d4          	movzbl %r12b,%edx
 955:	83 e2 02             	and    $0x2,%edx
 958:	85 d2                	test   %edx,%edx
 95a:	74 2b                	je     987 <wl_anx+0x108>
 95c:	0f b7 d3             	movzwl %bx,%edx
 95f:	48 01 d2             	add    %rdx,%rdx
 962:	4c 01 f2             	add    %r14,%rdx
 965:	0f b7 0a             	movzwl (%rdx),%ecx
 968:	0f b7 d3             	movzwl %bx,%edx
 96b:	48 01 d2             	add    %rdx,%rdx
 96e:	4c 01 ea             	add    %r13,%rdx
 971:	0f b7 12             	movzwl (%rdx),%edx
 974:	31 d1                	xor    %edx,%ecx
 976:	0f b7 d3             	movzwl %bx,%edx
 979:	48 01 d2             	add    %rdx,%rdx
 97c:	48 01 c2             	add    %rax,%rdx
 97f:	f7 d1                	not    %ecx
 981:	66 89 0a             	mov    %cx,(%rdx)
 984:	83 c3 02             	add    $0x2,%ebx
 987:	41 0f b6 d4          	movzbl %r12b,%edx
 98b:	83 e2 04             	and    $0x4,%edx
 98e:	85 d2                	test   %edx,%edx
 990:	74 2b                	je     9bd <wl_anx+0x13e>
 992:	0f b7 d3             	movzwl %bx,%edx
 995:	48 c1 e2 02          	shl    $0x2,%rdx
 999:	4c 01 f2             	add    %r14,%rdx
 99c:	8b 0a                	mov    (%rdx),%ecx
 99e:	0f b7 d3             	movzwl %bx,%edx
 9a1:	48 c1 e2 02          	shl    $0x2,%rdx
 9a5:	4c 01 ea             	add    %r13,%rdx
 9a8:	8b 12                	mov    (%rdx),%edx
 9aa:	31 d1                	xor    %edx,%ecx
 9ac:	0f b7 d3             	movzwl %bx,%edx
 9af:	48 c1 e2 02          	shl    $0x2,%rdx
 9b3:	48 01 c2             	add    %rax,%rdx
 9b6:	f7 d1                	not    %ecx
 9b8:	89 0a                	mov    %ecx,(%rdx)
 9ba:	83 c3 04             	add    $0x4,%ebx
 9bd:	48 83 c4 18          	add    $0x18,%rsp
 9c1:	5b                   	pop    %rbx
 9c2:	41 5c                	pop    %r12
 9c4:	41 5d                	pop    %r13
 9c6:	41 5e                	pop    %r14
 9c8:	41 5f                	pop    %r15
 9ca:	5d                   	pop    %rbp
 9cb:	c3                   	ret    

00000000000009cc <wl_aeq>:
 9cc:	55                   	push   %rbp
 9cd:	48 89 e5             	mov    %rsp,%rbp
 9d0:	41 56                	push   %r14
 9d2:	41 55                	push   %r13
 9d4:	41 54                	push   %r12
 9d6:	53                   	push   %rbx
 9d7:	89 f9                	mov    %edi,%ecx
 9d9:	48 89 f0             	mov    %rsi,%rax
 9dc:	49 89 d5             	mov    %rdx,%r13
 9df:	89 cb                	mov    %ecx,%ebx
 9e1:	48 85 c0             	test   %rax,%rax
 9e4:	75 26                	jne    a0c <wl_aeq+0x40>
 9e6:	0f b6 c3             	movzbl %bl,%eax
 9e9:	41 b9 00 00 00 00    	mov    $0x0,%r9d
 9ef:	41 b8 ff ff ff ff    	mov    $0xffffffff,%r8d
 9f5:	b9 22 00 00 00       	mov    $0x22,%ecx
 9fa:	ba 03 00 00 00       	mov    $0x3,%edx
 9ff:	48 89 c6             	mov    %rax,%rsi
 a02:	bf 00 00 00 00       	mov    $0x0,%edi
 a07:	e8 00 00 00 00       	call   a0c <wl_aeq+0x40>
 a0c:	41 89 de             	mov    %ebx,%r14d
 a0f:	41 c0 ee 03          	shr    $0x3,%r14b
 a13:	83 e3 07             	and    $0x7,%ebx
 a16:	41 89 dc             	mov    %ebx,%r12d
 a19:	bb 00 00 00 00       	mov    $0x0,%ebx
 a1e:	eb 2e                	jmp    a4e <wl_aeq+0x82>
 a20:	0f b7 d3             	movzwl %bx,%edx
 a23:	48 c1 e2 03          	shl    $0x3,%rdx
 a27:	48 01 c2             	add    %rax,%rdx
 a2a:	48 8b 0a             	mov    (%rdx),%rcx
 a2d:	0f b7 d3             	movzwl %bx,%edx
 a30:	48 c1 e2 03          	shl    $0x3,%rdx
 a34:	4c 01 ea             	add    %r13,%rdx
 a37:	48 8b 12             	mov    (%rdx),%rdx
 a3a:	48 39 d1             	cmp    %rdx,%rcx
 a3d:	74 0a                	je     a49 <wl_aeq+0x7d>
 a3f:	b8 00 00 00 00       	mov    $0x0,%eax
 a44:	e9 a7 00 00 00       	jmp    af0 <wl_aeq+0x124>
 a49:	89 da                	mov    %ebx,%edx
 a4b:	8d 5a 01             	lea    0x1(%rdx),%ebx
 a4e:	41 0f b6 d6          	movzbl %r14b,%edx
 a52:	66 39 d3             	cmp    %dx,%bx
 a55:	72 c9                	jb     a20 <wl_aeq+0x54>
 a57:	c1 e3 03             	shl    $0x3,%ebx
 a5a:	41 0f b6 d4          	movzbl %r12b,%edx
 a5e:	83 e2 01             	and    $0x1,%edx
 a61:	85 d2                	test   %edx,%edx
 a63:	74 22                	je     a87 <wl_aeq+0xbb>
 a65:	0f b7 d3             	movzwl %bx,%edx
 a68:	48 01 c2             	add    %rax,%rdx
 a6b:	0f b6 0a             	movzbl (%rdx),%ecx
 a6e:	0f b7 d3             	movzwl %bx,%edx
 a71:	4c 01 ea             	add    %r13,%rdx
 a74:	0f b6 12             	movzbl (%rdx),%edx
 a77:	38 d1                	cmp    %dl,%cl
 a79:	74 07                	je     a82 <wl_aeq+0xb6>
 a7b:	b8 00 00 00 00       	mov    $0x0,%eax
 a80:	eb 6e                	jmp    af0 <wl_aeq+0x124>
 a82:	89 da                	mov    %ebx,%edx
 a84:	8d 5a 01             	lea    0x1(%rdx),%ebx
 a87:	41 0f b6 d4          	movzbl %r12b,%edx
 a8b:	83 e2 02             	and    $0x2,%edx
 a8e:	85 d2                	test   %edx,%edx
 a90:	74 27                	je     ab9 <wl_aeq+0xed>
 a92:	0f b7 d3             	movzwl %bx,%edx
 a95:	48 01 d2             	add    %rdx,%rdx
 a98:	48 01 c2             	add    %rax,%rdx
 a9b:	0f b7 0a             	movzwl (%rdx),%ecx
 a9e:	0f b7 d3             	movzwl %bx,%edx
 aa1:	48 01 d2             	add    %rdx,%rdx
 aa4:	4c 01 ea             	add    %r13,%rdx
 aa7:	0f b7 12             	movzwl (%rdx),%edx
 aaa:	66 39 d1             	cmp    %dx,%cx
 aad:	74 07                	je     ab6 <wl_aeq+0xea>
 aaf:	b8 00 00 00 00       	mov    $0x0,%eax
 ab4:	eb 3a                	jmp    af0 <wl_aeq+0x124>
 ab6:	83 c3 02             	add    $0x2,%ebx
 ab9:	41 0f b6 d4          	movzbl %r12b,%edx
 abd:	83 e2 04             	and    $0x4,%edx
 ac0:	85 d2                	test   %edx,%edx
 ac2:	74 27                	je     aeb <wl_aeq+0x11f>
 ac4:	0f b7 d3             	movzwl %bx,%edx
 ac7:	48 01 d2             	add    %rdx,%rdx
 aca:	48 01 d0             	add    %rdx,%rax
 acd:	0f b7 10             	movzwl (%rax),%edx
 ad0:	0f b7 c3             	movzwl %bx,%eax
 ad3:	48 01 c0             	add    %rax,%rax
 ad6:	4c 01 e8             	add    %r13,%rax
 ad9:	0f b7 00             	movzwl (%rax),%eax
 adc:	66 39 c2             	cmp    %ax,%dx
 adf:	74 07                	je     ae8 <wl_aeq+0x11c>
 ae1:	b8 00 00 00 00       	mov    $0x0,%eax
 ae6:	eb 08                	jmp    af0 <wl_aeq+0x124>
 ae8:	83 c3 04             	add    $0x4,%ebx
 aeb:	b8 01 00 00 00       	mov    $0x1,%eax
 af0:	5b                   	pop    %rbx
 af1:	41 5c                	pop    %r12
 af3:	41 5d                	pop    %r13
 af5:	41 5e                	pop    %r14
 af7:	5d                   	pop    %rbp
 af8:	c3                   	ret    

0000000000000af9 <wl_afl>:
 af9:	55                   	push   %rbp
 afa:	48 89 e5             	mov    %rsp,%rbp
 afd:	41 56                	push   %r14
 aff:	41 55                	push   %r13
 b01:	41 54                	push   %r12
 b03:	53                   	push   %rbx
 b04:	48 83 ec 20          	sub    $0x20,%rsp
 b08:	49 89 f5             	mov    %rsi,%r13
 b0b:	89 d0                	mov    %edx,%eax
 b0d:	49 89 cc             	mov    %rcx,%r12
 b10:	41 89 fe             	mov    %edi,%r14d
 b13:	89 c3                	mov    %eax,%ebx
 b15:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
 b1c:	00 00 
 b1e:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
 b22:	31 c0                	xor    %eax,%eax
 b24:	4d 85 ed             	test   %r13,%r13
 b27:	75 2a                	jne    b53 <wl_afl+0x5a>
 b29:	41 0f b6 c6          	movzbl %r14b,%eax
 b2d:	41 b9 00 00 00 00    	mov    $0x0,%r9d
 b33:	41 b8 ff ff ff ff    	mov    $0xffffffff,%r8d
 b39:	b9 22 00 00 00       	mov    $0x22,%ecx
 b3e:	ba 03 00 00 00       	mov    $0x3,%edx
 b43:	48 89 c6             	mov    %rax,%rsi
 b46:	bf 00 00 00 00       	mov    $0x0,%edi
 b4b:	e8 00 00 00 00       	call   b50 <wl_afl+0x57>
 b50:	49 89 c5             	mov    %rax,%r13
 b53:	84 db                	test   %bl,%bl
 b55:	75 1d                	jne    b74 <wl_afl+0x7b>
 b57:	4d 85 e4             	test   %r12,%r12
 b5a:	74 07                	je     b63 <wl_afl+0x6a>
 b5c:	b8 00 00 00 00       	mov    $0x0,%eax
 b61:	eb 7d                	jmp    be0 <wl_afl+0xe7>
 b63:	48 c7 45 d0 00 00 00 	movq   $0x0,-0x30(%rbp)
 b6a:	00 
 b6b:	4c 8d 65 d0          	lea    -0x30(%rbp),%r12
 b6f:	bb 08 00 00 00       	mov    $0x8,%ebx
 b74:	41 0f b6 c6          	movzbl %r14b,%eax
 b78:	f6 f3                	div    %bl
 b7a:	0f b6 d0             	movzbl %al,%edx
 b7d:	0f b6 c3             	movzbl %bl,%eax
 b80:	0f af c2             	imul   %edx,%eax
 b83:	66 89 45 ce          	mov    %ax,-0x32(%rbp)
 b87:	66 c7 45 cc 00 00    	movw   $0x0,-0x34(%rbp)
 b8d:	eb 20                	jmp    baf <wl_afl+0xb6>
 b8f:	0f b7 45 cc          	movzwl -0x34(%rbp),%eax
 b93:	49 8d 4c 05 00       	lea    0x0(%r13,%rax,1),%rcx
 b98:	0f b6 c3             	movzbl %bl,%eax
 b9b:	4c 89 e2             	mov    %r12,%rdx
 b9e:	48 89 ce             	mov    %rcx,%rsi
 ba1:	89 c7                	mov    %eax,%edi
 ba3:	e8 00 00 00 00       	call   ba8 <wl_afl+0xaf>
 ba8:	0f b6 c3             	movzbl %bl,%eax
 bab:	66 01 45 cc          	add    %ax,-0x34(%rbp)
 baf:	0f b7 45 cc          	movzwl -0x34(%rbp),%eax
 bb3:	66 3b 45 ce          	cmp    -0x32(%rbp),%ax
 bb7:	72 d6                	jb     b8f <wl_afl+0x96>
 bb9:	0f b7 45 cc          	movzwl -0x34(%rbp),%eax
 bbd:	49 8d 4c 05 00       	lea    0x0(%r13,%rax,1),%rcx
 bc2:	0f b7 45 ce          	movzwl -0x32(%rbp),%eax
 bc6:	89 c2                	mov    %eax,%edx
 bc8:	44 89 f0             	mov    %r14d,%eax
 bcb:	29 d0                	sub    %edx,%eax
 bcd:	0f b6 c0             	movzbl %al,%eax
 bd0:	4c 89 e2             	mov    %r12,%rdx
 bd3:	48 89 ce             	mov    %rcx,%rsi
 bd6:	89 c7                	mov    %eax,%edi
 bd8:	e8 00 00 00 00       	call   bdd <wl_afl+0xe4>
 bdd:	4c 89 e8             	mov    %r13,%rax
 be0:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
 be4:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
 beb:	00 00 
 bed:	74 05                	je     bf4 <wl_afl+0xfb>
 bef:	e8 00 00 00 00       	call   bf4 <wl_afl+0xfb>
 bf4:	48 83 c4 20          	add    $0x20,%rsp
 bf8:	5b                   	pop    %rbx
 bf9:	41 5c                	pop    %r12
 bfb:	41 5d                	pop    %r13
 bfd:	41 5e                	pop    %r14
 bff:	5d                   	pop    %rbp
 c00:	c3                   	ret    

0000000000000c01 <wl_asb>:
 c01:	55                   	push   %rbp
 c02:	48 89 e5             	mov    %rsp,%rbp
 c05:	41 55                	push   %r13
 c07:	41 54                	push   %r12
 c09:	53                   	push   %rbx
 c0a:	48 83 ec 18          	sub    $0x18,%rsp
 c0e:	48 89 f8             	mov    %rdi,%rax
 c11:	89 f7                	mov    %esi,%edi
 c13:	89 d6                	mov    %edx,%esi
 c15:	89 fa                	mov    %edi,%edx
 c17:	41 89 f4             	mov    %esi,%r12d
 c1a:	48 85 c0             	test   %rax,%rax
 c1d:	0f 84 df 00 00 00    	je     d02 <wl_asb+0x101>
 c23:	84 d2                	test   %dl,%dl
 c25:	0f 84 d7 00 00 00    	je     d02 <wl_asb+0x101>
 c2b:	0f b6 f1             	movzbl %cl,%esi
 c2e:	83 e6 02             	and    $0x2,%esi
 c31:	85 f6                	test   %esi,%esi
 c33:	74 3d                	je     c72 <wl_asb+0x71>
 c35:	48 c7 45 d0 00 00 00 	movq   $0x0,-0x30(%rbp)
 c3c:	00 
 c3d:	48 c7 45 d8 00 00 00 	movq   $0x0,-0x28(%rbp)
 c44:	00 
 c45:	eb 16                	jmp    c5d <wl_asb+0x5c>
 c47:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
 c4b:	0f b6 09             	movzbl (%rcx),%ecx
 c4e:	41 38 cc             	cmp    %cl,%r12b
 c51:	75 05                	jne    c58 <wl_asb+0x57>
 c53:	48 83 45 d0 01       	addq   $0x1,-0x30(%rbp)
 c58:	48 83 45 d8 01       	addq   $0x1,-0x28(%rbp)
 c5d:	0f b6 ca             	movzbl %dl,%ecx
 c60:	48 01 c1             	add    %rax,%rcx
 c63:	48 39 4d d8          	cmp    %rcx,-0x28(%rbp)
 c67:	72 de                	jb     c47 <wl_asb+0x46>
 c69:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 c6d:	e9 a1 00 00 00       	jmp    d13 <wl_asb+0x112>
 c72:	0f b6 c9             	movzbl %cl,%ecx
 c75:	83 e1 01             	and    $0x1,%ecx
 c78:	85 c9                	test   %ecx,%ecx
 c7a:	74 46                	je     cc2 <wl_asb+0xc1>
 c7c:	49 89 c5             	mov    %rax,%r13
 c7f:	0f b6 d2             	movzbl %dl,%edx
 c82:	48 8d 1c 10          	lea    (%rax,%rdx,1),%rbx
 c86:	eb 2e                	jmp    cb6 <wl_asb+0xb5>
 c88:	48 89 de             	mov    %rbx,%rsi
 c8b:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # c92 <wl_asb+0x91>
 c92:	48 89 c7             	mov    %rax,%rdi
 c95:	b8 00 00 00 00       	mov    $0x0,%eax
 c9a:	e8 00 00 00 00       	call   c9f <wl_asb+0x9e>
 c9f:	0f b6 03             	movzbl (%rbx),%eax
 ca2:	0f be d0             	movsbl %al,%edx
 ca5:	41 0f b6 c4          	movzbl %r12b,%eax
 ca9:	39 c2                	cmp    %eax,%edx
 cab:	75 05                	jne    cb2 <wl_asb+0xb1>
 cad:	48 89 d8             	mov    %rbx,%rax
 cb0:	eb 61                	jmp    d13 <wl_asb+0x112>
 cb2:	48 83 eb 01          	sub    $0x1,%rbx
 cb6:	4c 39 eb             	cmp    %r13,%rbx
 cb9:	77 cd                	ja     c88 <wl_asb+0x87>
 cbb:	b8 00 00 00 00       	mov    $0x0,%eax
 cc0:	eb 51                	jmp    d13 <wl_asb+0x112>
 cc2:	0f b6 d2             	movzbl %dl,%edx
 cc5:	4c 8d 2c 10          	lea    (%rax,%rdx,1),%r13
 cc9:	48 89 c3             	mov    %rax,%rbx
 ccc:	eb 28                	jmp    cf6 <wl_asb+0xf5>
 cce:	48 89 de             	mov    %rbx,%rsi
 cd1:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # cd8 <wl_asb+0xd7>
 cd8:	48 89 c7             	mov    %rax,%rdi
 cdb:	b8 00 00 00 00       	mov    $0x0,%eax
 ce0:	e8 00 00 00 00       	call   ce5 <wl_asb+0xe4>
 ce5:	0f b6 03             	movzbl (%rbx),%eax
 ce8:	41 38 c4             	cmp    %al,%r12b
 ceb:	75 05                	jne    cf2 <wl_asb+0xf1>
 ced:	48 89 d8             	mov    %rbx,%rax
 cf0:	eb 21                	jmp    d13 <wl_asb+0x112>
 cf2:	48 83 c3 01          	add    $0x1,%rbx
 cf6:	4c 39 eb             	cmp    %r13,%rbx
 cf9:	72 d3                	jb     cce <wl_asb+0xcd>
 cfb:	b8 00 00 00 00       	mov    $0x0,%eax
 d00:	eb 11                	jmp    d13 <wl_asb+0x112>
 d02:	45 84 e4             	test   %r12b,%r12b
 d05:	75 07                	jne    d0e <wl_asb+0x10d>
 d07:	b8 01 00 00 00       	mov    $0x1,%eax
 d0c:	eb 05                	jmp    d13 <wl_asb+0x112>
 d0e:	b8 00 00 00 00       	mov    $0x0,%eax
 d13:	48 83 c4 18          	add    $0x18,%rsp
 d17:	5b                   	pop    %rbx
 d18:	41 5c                	pop    %r12
 d1a:	41 5d                	pop    %r13
 d1c:	5d                   	pop    %rbp
 d1d:	c3                   	ret    

0000000000000d1e <wl_asa>:
 d1e:	55                   	push   %rbp
 d1f:	48 89 e5             	mov    %rsp,%rbp
 d22:	41 57                	push   %r15
 d24:	41 56                	push   %r14
 d26:	41 55                	push   %r13
 d28:	41 54                	push   %r12
 d2a:	53                   	push   %rbx
 d2b:	48 83 ec 28          	sub    $0x28,%rsp
 d2f:	49 89 fd             	mov    %rdi,%r13
 d32:	49 89 d4             	mov    %rdx,%r12
 d35:	89 c8                	mov    %ecx,%eax
 d37:	44 89 c2             	mov    %r8d,%edx
 d3a:	41 89 f6             	mov    %esi,%r14d
 d3d:	89 c3                	mov    %eax,%ebx
 d3f:	89 d0                	mov    %edx,%eax
 d41:	4d 85 e4             	test   %r12,%r12
 d44:	0f 84 8d 01 00 00    	je     ed7 <wl_asa+0x1b9>
 d4a:	84 db                	test   %bl,%bl
 d4c:	0f 84 85 01 00 00    	je     ed7 <wl_asa+0x1b9>
 d52:	4d 85 ed             	test   %r13,%r13
 d55:	0f 84 46 01 00 00    	je     ea1 <wl_asa+0x183>
 d5b:	45 84 f6             	test   %r14b,%r14b
 d5e:	0f 84 3d 01 00 00    	je     ea1 <wl_asa+0x183>
 d64:	89 da                	mov    %ebx,%edx
 d66:	8d 5a ff             	lea    -0x1(%rdx),%ebx
 d69:	0f b6 d0             	movzbl %al,%edx
 d6c:	83 e2 02             	and    $0x2,%edx
 d6f:	85 d2                	test   %edx,%edx
 d71:	74 6b                	je     dde <wl_asa+0xc0>
 d73:	48 c7 45 c0 00 00 00 	movq   $0x0,-0x40(%rbp)
 d7a:	00 
 d7b:	48 c7 45 c8 00 00 00 	movq   $0x0,-0x38(%rbp)
 d82:	00 
 d83:	eb 43                	jmp    dc8 <wl_asa+0xaa>
 d85:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
 d89:	0f b6 10             	movzbl (%rax),%edx
 d8c:	41 0f b6 04 24       	movzbl (%r12),%eax
 d91:	38 c2                	cmp    %al,%dl
 d93:	75 2e                	jne    dc3 <wl_asa+0xa5>
 d95:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
 d99:	48 8d 50 01          	lea    0x1(%rax),%rdx
 d9d:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
 da1:	49 8d 74 24 01       	lea    0x1(%r12),%rsi
 da6:	0f b6 cb             	movzbl %bl,%ecx
 da9:	48 89 c2             	mov    %rax,%rdx
 dac:	89 cf                	mov    %ecx,%edi
 dae:	e8 00 00 00 00       	call   db3 <wl_asa+0x95>
 db3:	84 c0                	test   %al,%al
 db5:	74 0c                	je     dc3 <wl_asa+0xa5>
 db7:	48 83 45 c0 01       	addq   $0x1,-0x40(%rbp)
 dbc:	0f b6 c3             	movzbl %bl,%eax
 dbf:	48 01 45 c8          	add    %rax,-0x38(%rbp)
 dc3:	48 83 45 c8 01       	addq   $0x1,-0x38(%rbp)
 dc8:	41 0f b6 c6          	movzbl %r14b,%eax
 dcc:	4c 01 e8             	add    %r13,%rax
 dcf:	48 39 45 c8          	cmp    %rax,-0x38(%rbp)
 dd3:	72 b0                	jb     d85 <wl_asa+0x67>
 dd5:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
 dd9:	e9 fe 00 00 00       	jmp    edc <wl_asa+0x1be>
 dde:	0f b6 c0             	movzbl %al,%eax
 de1:	83 e0 01             	and    $0x1,%eax
 de4:	85 c0                	test   %eax,%eax
 de6:	74 6e                	je     e56 <wl_asa+0x138>
 de8:	4c 89 6d b8          	mov    %r13,-0x48(%rbp)
 dec:	44 8d 7b ff          	lea    -0x1(%rbx),%r15d
 df0:	41 0f b6 c6          	movzbl %r14b,%eax
 df4:	49 01 c5             	add    %rax,%r13
 df7:	eb 4d                	jmp    e46 <wl_asa+0x128>
 df9:	41 0f b6 45 00       	movzbl 0x0(%r13),%eax
 dfe:	0f b6 d0             	movzbl %al,%edx
 e01:	0f b6 c3             	movzbl %bl,%eax
 e04:	4c 01 e0             	add    %r12,%rax
 e07:	0f b6 00             	movzbl (%rax),%eax
 e0a:	0f be c0             	movsbl %al,%eax
 e0d:	39 c2                	cmp    %eax,%edx
 e0f:	75 31                	jne    e42 <wl_asa+0x124>
 e11:	41 0f b6 c7          	movzbl %r15b,%eax
 e15:	48 f7 d8             	neg    %rax
 e18:	49 01 c5             	add    %rax,%r13
 e1b:	41 0f b6 c7          	movzbl %r15b,%eax
 e1f:	48 f7 d8             	neg    %rax
 e22:	49 8d 0c 04          	lea    (%r12,%rax,1),%rcx
 e26:	0f b6 c3             	movzbl %bl,%eax
 e29:	4c 89 ea             	mov    %r13,%rdx
 e2c:	48 89 ce             	mov    %rcx,%rsi
 e2f:	89 c7                	mov    %eax,%edi
 e31:	e8 00 00 00 00       	call   e36 <wl_asa+0x118>
 e36:	84 c0                	test   %al,%al
 e38:	74 08                	je     e42 <wl_asa+0x124>
 e3a:	4c 89 e8             	mov    %r13,%rax
 e3d:	e9 9a 00 00 00       	jmp    edc <wl_asa+0x1be>
 e42:	49 83 ed 01          	sub    $0x1,%r13
 e46:	4c 3b 6d b8          	cmp    -0x48(%rbp),%r13
 e4a:	77 ad                	ja     df9 <wl_asa+0xdb>
 e4c:	b8 00 00 00 00       	mov    $0x0,%eax
 e51:	e9 86 00 00 00       	jmp    edc <wl_asa+0x1be>
 e56:	41 0f b6 c6          	movzbl %r14b,%eax
 e5a:	4d 8d 74 05 00       	lea    0x0(%r13,%rax,1),%r14
 e5f:	eb 34                	jmp    e95 <wl_asa+0x177>
 e61:	41 0f b6 55 00       	movzbl 0x0(%r13),%edx
 e66:	41 0f b6 04 24       	movzbl (%r12),%eax
 e6b:	38 c2                	cmp    %al,%dl
 e6d:	75 22                	jne    e91 <wl_asa+0x173>
 e6f:	4c 89 ea             	mov    %r13,%rdx
 e72:	4c 8d 6a 01          	lea    0x1(%rdx),%r13
 e76:	49 8d 4c 24 01       	lea    0x1(%r12),%rcx
 e7b:	0f b6 c3             	movzbl %bl,%eax
 e7e:	48 89 ce             	mov    %rcx,%rsi
 e81:	89 c7                	mov    %eax,%edi
 e83:	e8 00 00 00 00       	call   e88 <wl_asa+0x16a>
 e88:	84 c0                	test   %al,%al
 e8a:	74 05                	je     e91 <wl_asa+0x173>
 e8c:	4c 89 e8             	mov    %r13,%rax
 e8f:	eb 4b                	jmp    edc <wl_asa+0x1be>
 e91:	49 83 c5 01          	add    $0x1,%r13
 e95:	4d 39 f5             	cmp    %r14,%r13
 e98:	72 c7                	jb     e61 <wl_asa+0x143>
 e9a:	b8 00 00 00 00       	mov    $0x0,%eax
 e9f:	eb 3b                	jmp    edc <wl_asa+0x1be>
 ea1:	0f b6 c3             	movzbl %bl,%eax
 ea4:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # eab <wl_asa+0x18d>
 eab:	48 89 d1             	mov    %rdx,%rcx
 eae:	ba 01 00 00 00       	mov    $0x1,%edx
 eb3:	be 00 00 00 00       	mov    $0x0,%esi
 eb8:	89 c7                	mov    %eax,%edi
 eba:	e8 00 00 00 00       	call   ebf <wl_asa+0x1a1>
 ebf:	48 89 c1             	mov    %rax,%rcx
 ec2:	0f b6 c3             	movzbl %bl,%eax
 ec5:	4c 89 e2             	mov    %r12,%rdx
 ec8:	48 89 ce             	mov    %rcx,%rsi
 ecb:	89 c7                	mov    %eax,%edi
 ecd:	e8 00 00 00 00       	call   ed2 <wl_asa+0x1b4>
 ed2:	0f b6 c0             	movzbl %al,%eax
 ed5:	eb 05                	jmp    edc <wl_asa+0x1be>
 ed7:	b8 01 00 00 00       	mov    $0x1,%eax
 edc:	48 83 c4 28          	add    $0x28,%rsp
 ee0:	5b                   	pop    %rbx
 ee1:	41 5c                	pop    %r12
 ee3:	41 5d                	pop    %r13
 ee5:	41 5e                	pop    %r14
 ee7:	41 5f                	pop    %r15
 ee9:	5d                   	pop    %rbp
 eea:	c3                   	ret    

char.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <wl_lens>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	53                   	push   %rbx
   5:	48 89 7d f0          	mov    %rdi,-0x10(%rbp)
   9:	bb 00 00 00 00       	mov    $0x0,%ebx
   e:	90                   	nop
   f:	89 d8                	mov    %ebx,%eax
  11:	8d 58 01             	lea    0x1(%rax),%ebx
  14:	0f b6 d0             	movzbl %al,%edx
  17:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  1b:	48 01 d0             	add    %rdx,%rax
  1e:	0f b6 00             	movzbl (%rax),%eax
  21:	84 c0                	test   %al,%al
  23:	75 ea                	jne    f <wl_lens+0xf>
  25:	89 d8                	mov    %ebx,%eax
  27:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  2b:	c9                   	leave  
  2c:	c3                   	ret    

io.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <wl_in>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	53                   	push   %rbx
   5:	48 83 ec 28          	sub    $0x28,%rsp
   9:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
   d:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  11:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  18:	00 00 
  1a:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  1e:	31 c0                	xor    %eax,%eax
  20:	48 83 7d d0 00       	cmpq   $0x0,-0x30(%rbp)
  25:	75 08                	jne    2f <wl_in+0x2f>
  27:	48 c7 45 d0 ff 00 00 	movq   $0xff,-0x30(%rbp)
  2e:	00 
  2f:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
  33:	48 8d 45 e6          	lea    -0x1a(%rbp),%rax
  37:	ba 01 00 00 00       	mov    $0x1,%edx
  3c:	48 89 c6             	mov    %rax,%rsi
  3f:	bf 00 00 00 00       	mov    $0x0,%edi
  44:	e8 00 00 00 00       	call   49 <wl_in+0x49>
  49:	c6 45 e7 00          	movb   $0x0,-0x19(%rbp)
  4d:	eb 2d                	jmp    7c <wl_in+0x7c>
  4f:	48 89 d8             	mov    %rbx,%rax
  52:	48 8d 58 01          	lea    0x1(%rax),%rbx
  56:	0f b6 55 e6          	movzbl -0x1a(%rbp),%edx
  5a:	88 10                	mov    %dl,(%rax)
  5c:	48 8d 45 e6          	lea    -0x1a(%rbp),%rax
  60:	ba 01 00 00 00       	mov    $0x1,%edx
  65:	48 89 c6             	mov    %rax,%rsi
  68:	bf 00 00 00 00       	mov    $0x0,%edi
  6d:	e8 00 00 00 00       	call   72 <wl_in+0x72>
  72:	0f b6 45 e7          	movzbl -0x19(%rbp),%eax
  76:	83 c0 01             	add    $0x1,%eax
  79:	88 45 e7             	mov    %al,-0x19(%rbp)
  7c:	0f b6 45 e6          	movzbl -0x1a(%rbp),%eax
  80:	3c 0a                	cmp    $0xa,%al
  82:	74 0a                	je     8e <wl_in+0x8e>
  84:	0f b6 45 e7          	movzbl -0x19(%rbp),%eax
  88:	48 39 45 d0          	cmp    %rax,-0x30(%rbp)
  8c:	77 c1                	ja     4f <wl_in+0x4f>
  8e:	48 89 d8             	mov    %rbx,%rax
  91:	48 8d 58 01          	lea    0x1(%rax),%rbx
  95:	c6 00 00             	movb   $0x0,(%rax)
  98:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  9c:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  a0:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
  a7:	00 00 
  a9:	74 05                	je     b0 <wl_in+0xb0>
  ab:	e8 00 00 00 00       	call   b0 <wl_in+0xb0>
  b0:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
  b4:	c9                   	leave  
  b5:	c3                   	ret    

vga.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <voc>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	89 f8                	mov    %edi,%eax
   6:	89 f2                	mov    %esi,%edx
   8:	3c 0a                	cmp    $0xa,%al
   a:	75 15                	jne    21 <voc+0x21>
   c:	0f b6 05 00 00 00 00 	movzbl 0x0(%rip),%eax        # 13 <voc+0x13>
  13:	83 c0 01             	add    $0x1,%eax
  16:	88 05 00 00 00 00    	mov    %al,0x0(%rip)        # 1c <voc+0x1c>
  1c:	e9 97 00 00 00       	jmp    b8 <voc+0xb8>
  21:	3c 0d                	cmp    $0xd,%al
  23:	75 0c                	jne    31 <voc+0x31>
  25:	c6 05 00 00 00 00 00 	movb   $0x0,0x0(%rip)        # 2c <voc+0x2c>
  2c:	e9 87 00 00 00       	jmp    b8 <voc+0xb8>
  31:	66 0f be c8          	movsbw %al,%cx
  35:	89 d0                	mov    %edx,%eax
  37:	c1 e0 08             	shl    $0x8,%eax
  3a:	89 c7                	mov    %eax,%edi
  3c:	48 8b 35 00 00 00 00 	mov    0x0(%rip),%rsi        # 43 <voc+0x43>
  43:	0f b6 05 00 00 00 00 	movzbl 0x0(%rip),%eax        # 4a <voc+0x4a>
  4a:	0f b6 d0             	movzbl %al,%edx
  4d:	89 d0                	mov    %edx,%eax
  4f:	c1 e0 02             	shl    $0x2,%eax
  52:	01 d0                	add    %edx,%eax
  54:	c1 e0 04             	shl    $0x4,%eax
  57:	89 c2                	mov    %eax,%edx
  59:	0f b6 05 00 00 00 00 	movzbl 0x0(%rip),%eax        # 60 <voc+0x60>
  60:	0f b6 c0             	movzbl %al,%eax
  63:	01 d0                	add    %edx,%eax
  65:	48 98                	cltq   
  67:	48 01 c0             	add    %rax,%rax
  6a:	48 01 f0             	add    %rsi,%rax
  6d:	09 f9                	or     %edi,%ecx
  6f:	89 ca                	mov    %ecx,%edx
  71:	66 89 10             	mov    %dx,(%rax)
  74:	0f b6 05 00 00 00 00 	movzbl 0x0(%rip),%eax        # 7b <voc+0x7b>
  7b:	83 c0 01             	add    $0x1,%eax
  7e:	88 05 00 00 00 00    	mov    %al,0x0(%rip)        # 84 <voc+0x84>
  84:	0f b6 05 00 00 00 00 	movzbl 0x0(%rip),%eax        # 8b <voc+0x8b>
  8b:	3c 50                	cmp    $0x50,%al
  8d:	75 29                	jne    b8 <voc+0xb8>
  8f:	c6 05 00 00 00 00 00 	movb   $0x0,0x0(%rip)        # 96 <voc+0x96>
  96:	0f b6 05 00 00 00 00 	movzbl 0x0(%rip),%eax        # 9d <voc+0x9d>
  9d:	83 c0 01             	add    $0x1,%eax
  a0:	88 05 00 00 00 00    	mov    %al,0x0(%rip)        # a6 <voc+0xa6>
  a6:	0f b6 05 00 00 00 00 	movzbl 0x0(%rip),%eax        # ad <voc+0xad>
  ad:	3c 19                	cmp    $0x19,%al
  af:	75 07                	jne    b8 <voc+0xb8>
  b1:	c6 05 00 00 00 00 00 	movb   $0x0,0x0(%rip)        # b8 <voc+0xb8>
  b8:	90                   	nop
  b9:	5d                   	pop    %rbp
  ba:	c3                   	ret    

00000000000000bb <vos>:
  bb:	55                   	push   %rbp
  bc:	48 89 e5             	mov    %rsp,%rbp
  bf:	41 54                	push   %r12
  c1:	53                   	push   %rbx
  c2:	48 83 ec 10          	sub    $0x10,%rsp
  c6:	48 89 fb             	mov    %rdi,%rbx
  c9:	41 89 f4             	mov    %esi,%r12d
  cc:	c6 45 ef 00          	movb   $0x0,-0x11(%rbp)
  d0:	eb 21                	jmp    f3 <vos+0x38>
  d2:	0f b6 45 ef          	movzbl -0x11(%rbp),%eax
  d6:	48 01 d8             	add    %rbx,%rax
  d9:	0f b6 00             	movzbl (%rax),%eax
  dc:	0f be c0             	movsbl %al,%eax
  df:	44 89 e6             	mov    %r12d,%esi
  e2:	89 c7                	mov    %eax,%edi
  e4:	e8 00 00 00 00       	call   e9 <vos+0x2e>
  e9:	0f b6 45 ef          	movzbl -0x11(%rbp),%eax
  ed:	83 c0 01             	add    $0x1,%eax
  f0:	88 45 ef             	mov    %al,-0x11(%rbp)
  f3:	48 89 df             	mov    %rbx,%rdi
  f6:	e8 00 00 00 00       	call   fb <vos+0x40>
  fb:	38 45 ef             	cmp    %al,-0x11(%rbp)
  fe:	72 d2                	jb     d2 <vos+0x17>
 100:	90                   	nop
 101:	90                   	nop
 102:	48 83 c4 10          	add    $0x10,%rsp
 106:	5b                   	pop    %rbx
 107:	41 5c                	pop    %r12
 109:	5d                   	pop    %rbp
 10a:	c3                   	ret    
