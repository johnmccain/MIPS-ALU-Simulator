//*****************************************************************************
//--ALUSimulator.h
//
//		Author: 		Gary J. Minden
//		Organization:	KU/EECS/EECS 645
//		Date:			2017-04-22 (B70422)
//		Version:		1.0
//		Description:	This is the prototype for a simple ALU simulator
//		Notes:
//
//*****************************************************************************
//

//OpCodes
#define OP_ADDI 0b001000 // ADD IMMEDIATE
#define OP_ADDIU 0b001001 // ADD IMMEDIATE UNSIGNED
#define OP_SLTI 0b001010 // SET ON LESS THAN IMMEDIATE
#define OP_SLTIU 0b001011 // SET ON LESS THAN IMMEDIATE UNSIGNED

//FunctionCodes
#define F_NOOP 0b000000 // no operation (does nothing)
#define F_SLL 0b000000 // shift left logical
#define F_SRL 0b000010 // shift right logical
#define F_SRA 0b000011 // shift right arithmetic
#define F_SLLV 0b000100 // shift left logical variable
#define F_SRLV 0b000110 // shift right logical variable
#define F_MFHI 0b010000 // move from high (need to implement?)
#define F_MFLO 0b010010 // move from low (need to implement?)
#define F_MULT 0b011000 // multiply
#define F_MULTU 0b011001 // multiply unsigned
#define F_DIV 0b011010 // divide
#define F_DIVU 0b011011 // divide unsigned
#define F_ADD 0b100000 // add
#define F_ADDU 0b100001 // add unsigned
#define F_SUB 0b100010 // subtract
#define F_SUBU 0b100011 // subtract unsigned
#define F_AND 0b100100 // bitwise and
#define F_OR 0b100101 // bitwise or
#define F_XOR 0b100110 // bitwise xor
#define F_SLT 0b101010 // set on less than
#define F_SLTU 0b101011 // set on less than unsigned

extern void ALUSimulator( RegisterFile theRegisterFile,
				uint32_t OpCode,
				uint32_t Rs, uint32_t Rt, uint32_t Rd,
				uint32_t ShiftAmt,
				uint32_t FunctionCode,
				uint32_t ImmediateValue,
				uint32_t* Status );
