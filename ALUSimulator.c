//*****************************************************************************
//--ALUSimulator.c
//
//		Author: 		Gary J. Minden
//		Organization:	KU/EECS/EECS 645
//		Date:			2017-04-22 (B70422)
//		Version:		1.0
//		Description:	This is the test standin for a simple ALU simulator
//		Notes:
//
//*****************************************************************************
//

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

#include <stdio.h>

#include "RegisterFile_01.h"
#include "ALUSimulator.h"

extern void ALUSimulator( RegisterFile theRegisterFile,
				uint32_t OpCode,
				uint32_t Rs, uint32_t Rt, uint32_t Rd,
				uint32_t ShiftAmt,
				uint32_t FunctionCode,
				uint32_t ImmediateValue,
				uint32_t* Status ) {

	printf( ">>ALU: Opcode: %02X; Rs: %02X; Rt: %02X; Rd: %02X;\n",
				OpCode,
				Rs,
				Rt,
				Rd );

	printf( ">>>>ALU: ShiftAmt: %02X; FunctionCode: %02X; ImmediateValue: %04X;\n",
				ShiftAmt,
				FunctionCode,
				ImmediateValue );

	uint32_t WrtAddr;
	int32_t Value_S, Value_T, Value_D, WrtValue;

	bool WrtEnb = false; //set to true to enable writing

	RegisterFile_Read(theRegisterFile, Rs, &Value_S, Rt, &Value_T);

	switch(OpCode) {
		case OP_ADDI: // ADD IMMEDIATE (with overflow)
			printf("\n\nOP_ADDI\n");
			WrtValue = Value_S + ImmediateValue;
			WrtAddr = Rt;
			WrtEnb = true;
		break;
		case OP_ADDIU: // ADD IMMEDIATE UNSIGNED
			printf("\n\nOP_ADDIU\n");
		break;
		case OP_SLTI: // SET ON LESS THAN IMMEDIATE
			printf("\n\nOP_SLTI\n");
		break;
		case OP_SLTIU: //SET ON LESS THAN IMMEDIATE UNSIGNED
			printf("\n\nOP_SLTIU\n");
		break;
		case 0:
			switch(FunctionCode) {
				case F_SLL:
					printf("\n\nF_SLL\n");
					WrtAddr = Rd;
					WrtValue = ((uint32_t) Value_T) << ShiftAmt;
					WrtEnb = true;
				break;
				case F_SRL:
					printf("\n\nF_SRL\n");
					WrtAddr = Rd;
					WrtValue = ((uint32_t) Value_T) >> ShiftAmt;
					WrtEnb = true;
				break;
				case F_SRA:
					printf("\n\nF_SRA\n");
					WrtAddr = Rd;
					WrtValue = ((int32_t) Value_T) >> ShiftAmt;
					WrtEnb = true;
				break;
				case F_SLLV:
					printf("\n\nF_SLLV\n");
				break;
				case F_SRLV:
					printf("\n\nF_SRLV\n");
				break;
				case F_MFHI:
					printf("\n\nF_MFHI\n");
				break;
				case F_MFLO:
					printf("\n\nF_MFLO\n");
				break;
				case F_MULT:
					printf("\n\nF_MULT\n");
				break;
				case F_MULTU:
					printf("\n\nF_MULTU\n");
				break;
				case F_DIV:
					printf("\n\nF_DIV\n");
				break;
				case F_DIVU:
					printf("\n\nF_DIVU\n");
				break;
				case F_ADD:
					printf("\n\nF_ADD\n");
				break;
				case F_ADDU:
					printf("\n\nF_ADDU\n");
				break;
				case F_SUB:
					printf("\n\nF_SUB\n");
				break;
				case F_SUBU:
					printf("\n\nF_SUBU\n");
				break;
				case F_AND:
					printf("\n\nF_AND\n");
				break;
				case F_OR:
					printf("\n\nF_OR\n");
				break;
				case F_XOR:
					printf("\n\nF_XOR\n");
				break;
				case F_SLT:
					printf("\n\nF_SLT\n");
				break;
				case F_SLTU:
					printf("\n\nF_SLTU\n");
				break;
			}
		break;
		default:
			printf("ERR: UNRECOGNIZED OPCODE\n");
		break;
	}

	//write changes
	RegisterFile_Write(theRegisterFile, WrtEnb, WrtAddr, WrtValue);

}
