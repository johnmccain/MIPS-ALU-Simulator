all:
	gcc ALUSimulator.c RegisterFile_01.c ALUSimulator_Main.c -o MIPS_ALU.exe
clean: rm MIPS_ALU.exe
