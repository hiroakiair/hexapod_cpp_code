# server makefile
# version 1.0
# written by ceoifung. Copyright(c) 2022
all:
	g++ -Wall -o ../build/xrtsbase.out *.cpp -lpthread -lsioclient -lHexapodR1

clean:
	rm -rf *.out *o *so
