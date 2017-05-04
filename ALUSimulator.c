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

//set this to print feedback about what operations are detected
#define DEBUG_LOG_OPERATIONS 0

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

	//TODO: verify

	RegisterFile_Read(theRegisterFile, Rs, &Value_S, Rt, &Value_T);

	switch(OpCode) {
		case OP_ADDI: // ADD IMMEDIATE (with overflow)
			#if DEBUG_LOG_OPERATIONS
			printf("\n\nOP_ADDI\n");
			#endif
			WrtValue = ((int32_t) Value_S) + (int32_t)(int16_t) ImmediateValue; //cast ImmediateValue to 32bit signed integer
			WrtAddr = Rt;
			WrtEnb = true;
		break;
		case OP_ADDIU: // ADD IMMEDIATE UNSIGNED, DON'T HAVE TO HANDLE OVERFLOW (PER MINDEN'S SPECIFICATION)
			#if DEBUG_LOG_OPERATIONS
			printf("\n\nOP_ADDIU\n");
			#endif
			WrtValue = ((uint32_t) Value_S) + (uint32_t)(uint16_t) ImmediateValue; //cast ImmediateValue to 32bit unsigned integer
			WrtAddr = Rt;
			WrtEnb = true;
		break;
		case OP_SLTI: // SET ON LESS THAN IMMEDIATE
			#if DEBUG_LOG_OPERATIONS
			printf("\n\nOP_SLTI\n");
			#endif
			WrtAddr = Rt;
			WrtValue = ((int32_t) Value_S) < (int32_t)(int16_t) ImmediateValue ? 1 : 0; //cast ImmediateValue to 32bit signed integer
			WrtEnb = true;
		break;
		case OP_SLTIU: //SET ON LESS THAN IMMEDIATE UNSIGNED
			#if DEBUG_LOG_OPERATIONS
			printf("\n\nOP_SLTIU\n");
			#endif
			WrtAddr = Rt;
			WrtValue = ((uint32_t) Value_S) < (uint32_t)(uint16_t) ImmediateValue ? 1 : 0; //cast ImmediateValue to 32bit unsigned integer
			WrtEnb = true;
		break;
		case 0:
			switch(FunctionCode) {
				case F_SLL:
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_SLL\n");
					#endif
					WrtAddr = Rd;
					WrtValue = ((uint32_t) Value_T) << ShiftAmt;
					WrtEnb = true;
				break;
				case F_SLLV:
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_SLLV\n");
					#endif
					WrtAddr = Rd;
					WrtValue = ((uint32_t) Value_T) << Value_S;
					WrtEnb = true;
				break;
				case F_SRL:
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_SRL\n");
					#endif
					WrtAddr = Rd;
					WrtValue = ((uint32_t) Value_T) >> ShiftAmt;
					WrtEnb = true;
				break;
				case F_SRA:
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_SRA\n");
					#endif
					WrtAddr = Rd;
					WrtValue = ((int32_t) Value_T) >> ShiftAmt;
					WrtEnb = true;
				break;
				case F_SRLV:
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_SRLV\n");
					#endif
					WrtAddr = Rd;
					WrtValue = ((uint32_t) Value_T) >> Value_S;
					WrtEnb = true;
				break;
				case F_MFHI: //DON'T NEED TO IMPLMENT
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_MFHI\tNOT REQUIRED\n");
					#endif
				break;
				case F_MFLO: //DON'T NEED TO IMPLMENT
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_MFLO\tNOT REQUIRED\n");
					#endif
				break;
				case F_MULT: //DON'T NEED TO IMPLMENT
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_MULT\tNOT REQUIRED\n");
					#endif
				break;
				case F_MULTU: //DON'T NEED TO IMPLMENT
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_MULTU\tNOT REQUIRED\n");
					#endif
				break;
				case F_DIV: //DON'T NEED TO IMPLMENT
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_DIV\tNOT REQUIRED\n");
					#endif
				break;
				case F_DIVU: //DON'T NEED TO IMPLMENT
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_DIVU\tNOT REQUIRED\n");
					#endif
				break;
				case F_ADD:
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_ADD\n");
					#endif
					WrtAddr = Rd;
					WrtValue = ((int32_t) Value_S) + (int32_t) Value_T;
					WrtEnb = true;
				break;
				case F_ADDU: // DON'T HAVE TO HANDLE OVERFLOW (PER MINDEN'S SPECIFICATION)
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_ADDU\n");
					#endif
					WrtAddr = Rd;
					WrtValue = ((uint32_t) Value_S) + (uint32_t) Value_T;
					WrtEnb = true;
				break;
				case F_SUB:
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_SUB\n");
					#endif
					WrtAddr = Rd;
					WrtValue = ((int32_t) Value_S) - (int32_t) Value_T;
					WrtEnb = true;
				break;
				case F_SUBU: // DON'T HAVE TO HANDLE OVERFLOW (PER MINDEN'S SPECIFICATION)
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_SUBU\n");
					#endif
					WrtAddr = Rd;
					WrtValue = ((uint32_t) Value_S) - (uint32_t) Value_T;
					WrtEnb = true;
				break;
				case F_AND:
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_AND\n");
					#endif
					WrtAddr = Rd;
					WrtValue = Value_S & Value_T;
					WrtEnb = true;
				break;
				case F_OR:
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_OR\n");
					#endif
					WrtAddr = Rd;
					WrtValue = Value_S | Value_T;
					WrtEnb = true;
				break;
				case F_XOR:
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_XOR\n");
					#endif
					WrtAddr = Rd;
					WrtValue = Value_S ^ Value_T;
					WrtEnb = true;
				break;
				case F_SLT:
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_SLT\n");
					#endif
					WrtAddr = Rd;
					WrtValue = ((int32_t) Value_S) < (int32_t) Value_T ? 1 : 0;
					WrtEnb = true;
				break;
				case F_SLTU:
					#if DEBUG_LOG_OPERATIONS
					printf("\n\nF_SLTU\n");
					#endif
					WrtAddr = Rd;
					WrtValue = ((uint32_t) Value_S) < (uint32_t) Value_T ? 1 : 0;
					WrtEnb = true;
				break;
			}
		break;
		default:
			#if DEBUG_LOG_OPERATIONS
			printf("ERR: UNRECOGNIZED OPCODE\n");
			#endif
		break;
	}

	//write changes
	RegisterFile_Write(theRegisterFile, WrtEnb, WrtAddr, WrtValue);

}
