#include <wl/types.h>
#include <wl/bit.h>
#include <wl/math.h>
#include <stdio.h>



typedef struct Instruction {
	U8f inst:4;
	U8f reg1:6;
	U8f reg2:6;
} __attribute__((packed)) Instruction;


U8l reg[64];
Instruction inst[64];


void printCode() {
							for (U8f i = 0; i < 64; i++) {
								switch (inst[i].inst) {
									case 0:
										if (inst[i].reg1 > 0) {
											if (inst[i].reg2 > 0) printf("LOAD %llx\n", inst[i].reg2 << 6 | inst[i].reg1);
											else printf("NEG reg%llu\n", inst[i].reg1);
										}
										else if(inst[i].reg2 > 0) printf("NOT reg%llu\n", inst[i].reg2);
										/* else printf("NOP\n"); */
									break;
									case 1: printf("MOV reg%llu, reg%llu\n", inst[i].reg1, inst[i].reg2); break;
									case 2: printf("AND reg%llu, reg%llu\n", inst[i].reg1, inst[i].reg2); break;
									case 3: printf("OR reg%llu, reg%llu\n", inst[i].reg1, inst[i].reg2); break;
									case 4: printf("XOR reg%llu, reg%llu\n", inst[i].reg1, inst[i].reg2); break;
									case 5: printf("NAND reg%llu, reg%llu\n", inst[i].reg1, inst[i].reg2); break;
									case 6: printf("NOR reg%llu, reg%llu\n", inst[i].reg1, inst[i].reg2); break;
									case 7: printf("NXOR reg%llu, reg%llu\n", inst[i].reg1, inst[i].reg2); break;
									case 8: printf("ADD reg%llu, reg%llu\n", inst[i].reg1, inst[i].reg2); break;
									case 9: printf("SUB reg%llu, reg%llu\n", inst[i].reg1, inst[i].reg2); break;
									case 10: printf("MUL reg%llu, reg%llu\n", inst[i].reg1, inst[i].reg2); break;
									case 11: printf("DIV reg%llu, reg%llu\n", inst[i].reg1, inst[i].reg2); break;
									case 12: printf("MOD reg%llu, reg%llu\n", inst[i].reg1, inst[i].reg2); break;
									case 13: printf("SHL reg%llu, reg%llu\n", inst[i].reg1, inst[i].reg2); break;
									case 14: printf("SHR reg%llu, reg%llu\n", inst[i].reg1, inst[i].reg2); break;
									case 15:
									default:
										switch (inst[i].reg1) {
											case 0: printf("B1 reg%llu\n", inst[i].reg2); break;
											case 1: printf("B0 reg%llu\n", inst[i].reg2); break;
											case 2: printf("BCT0 reg%llu\n", inst[i].reg2); break;	
											case 3: printf("BLS1 reg%llu\n", inst[i].reg2); break;
											case 4: printf("BT1 reg%llu\n", inst[i].reg2); break;
											case 5: printf("BL1 reg%llu\n", inst[i].reg2); break;
											case 6: printf("CTZ reg%llu\n", inst[i].reg2); break;
											case 7: printf("CLZ reg%llu\n", inst[i].reg2); break;
											case 8: printf("POP reg%llu\n", inst[i].reg2); break;
											case 9: printf("ABS reg%llu\n", inst[i].reg2); break;
											case 10: printf("TRUE reg%llu\n", inst[i].reg2); break;
											case 11: printf("FALSE reg%llu\n", inst[i].reg2); break;
											default: printf("NOP\n");break;
										}
									break;
								}
							}
}

void exec() {

			for (U8f i = 0; i < 64 && *(U16l*)&(inst[i]) != 0; i++) {
				switch (inst[i].inst) {
					case 0:
						if (inst[i].reg1 > 0) {
							if (inst[i].reg2 > 0) reg[0] = inst[i].reg2 << 6 | inst[i].reg1;
							else reg[inst[i].reg1] = -reg[inst[i].reg1];
						}
						else reg[inst[i].reg2] = ~reg[inst[i].reg2];
					break;

					case 1: reg[inst[i].reg1] = reg[inst[i].reg2]; break;
					case 2: reg[inst[i].reg1] = reg[inst[i].reg1] & reg[inst[i].reg2]; break;
					case 3: reg[inst[i].reg1] = reg[inst[i].reg1] | reg[inst[i].reg2]; break;
					case 4: reg[inst[i].reg1] = reg[inst[i].reg1] ^ reg[inst[i].reg2]; break;
					case 5: reg[inst[i].reg1] = ~(inst[i].reg1 & reg[inst[i].reg2]); break;
					case 6: reg[inst[i].reg1] = ~(inst[i].reg1 | reg[inst[i].reg2]); break;
					case 7: reg[inst[i].reg1] = ~(inst[i].reg1 ^ reg[inst[i].reg2]); break;
					case 8: reg[inst[i].reg1] = reg[inst[i].reg1] + reg[inst[i].reg2]; break;
					case 9: reg[inst[i].reg1] = reg[inst[i].reg1] - reg[inst[i].reg2]; break;
					case 10: reg[inst[i].reg1] = reg[inst[i].reg1] * reg[inst[i].reg2]; break;

					case 11: 
						if (reg[inst[i].reg2] != 0)
							reg[inst[i].reg1] = reg[inst[i].reg1] / reg[inst[i].reg2];
						else reg[inst[i].reg1] = 0xFF;
					break;

					case 12: 
						if (reg[inst[i].reg2] != 0)
							reg[inst[i].reg1] = reg[inst[i].reg1] % reg[inst[i].reg2];
						else reg[inst[i].reg1] = 0xFF;
					break;

					case 13: reg[inst[i].reg1] = reg[inst[i].reg1] << inst[i].reg2; break;
					case 14: reg[inst[i].reg1] = reg[inst[i].reg1] >> inst[i].reg2; break;
					case 15:
					default:
						switch (inst[i].reg1) {
							case 0: reg[inst[i].reg2] = b1(reg[inst[i].reg2]); break;
							case 1: reg[inst[i].reg2] = b0(reg[inst[i].reg2]); break;
							case 2: reg[inst[i].reg2] = bct0(reg[inst[i].reg2]); break;	
							case 3: reg[inst[i].reg2] = bls1(reg[inst[i].reg2]); break;
							case 4: reg[inst[i].reg2] = bt1(reg[inst[i].reg2]); break;
							case 5: reg[inst[i].reg2] = bl1(reg[inst[i].reg2]); break;
							case 6: reg[inst[i].reg2] = ctz(reg[inst[i].reg2]); break;
							case 7: reg[inst[i].reg2] = clz(reg[inst[i].reg2]); break;
							case 8: reg[inst[i].reg2] = pop(reg[inst[i].reg2]); break;
							case 9: reg[inst[i].reg2] = abi(reg[inst[i].reg2]); break;
							case 10: reg[inst[i].reg2] = !!reg[inst[i].reg2]; break;
							case 11: reg[inst[i].reg2] = !reg[inst[i].reg2]; break;
							default: break;
						}
					break;
				}
			}
}

void computer(U8l (*func)(U8l)) {
	U8f goodreg = 64;

	for (U8f i = 0; i < 64; i++) {
		reg[i] = 0;
		inst[i] = (Instruction){0,0,0};
	}

	while (unlikely(*(U16l*)&(inst[63]) < 0xFFFF)) {
		if_unlikely(*(U16l*)&(inst[0]) == 0xFFFF) {
			for (U8f i = 0; unlikely(*(U16l*)&(inst[i]) == 0xFFFF);) {
				(*(U16l*)&(inst[i])) = 0;

				(*(U16l*)&(inst[i++]))++;
			}
		}
		else (*(U16l*)&(inst[0]))++;

/* 		for (U8f i = 0; i < 32; i++) {
			printf("%04hx ", (*(U16l*)&(inst[i])));
		}
		printf("\n"); */

		for (U8f i = 1; i < 64;) {
			for (U8l x = 1; x < 255; x++) {
				for (U8f j = 0; j < 64; j++) {
					reg[j] = 0;
				}
				reg[1] = x;
				exec();
				if (reg[i] != func(x)) {
					goto cont;
				}
			}
			printf("RETURN REGISTER %llu\n", i);
			printCode();
			return;
cont:
		i++;
		}
	}
}


U8l not(U8l x) { return 6; }


int main () {
/* 	reg[1] = 5;
	for (U8f i = 0; i < 64; i++) {
		printf("%02hx ", reg[i]);
	}
	printf("\n");
	*(U16l*)&(inst[0]) = 0x0400;
	printCode();
	exec();
	for (U8f i = 0; i < 64; i++) {
		printf("%02hx ", reg[i]);
	} */
	computer(&not);
	return 0;
}
