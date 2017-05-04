.PHONY: test clean

all:
	gcc ALUSimulator.c RegisterFile_01.c ALUSimulator_Main.c -o MIPS_ALU.exe

test:
	./MIPS_ALU.exe

clean:
	rm MIPS_ALU.exe
