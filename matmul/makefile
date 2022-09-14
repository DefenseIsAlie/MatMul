CFLAGS = -g -Wall -Werror -std=c++17 -pedantic -Wvla

entry: bin/matmul1 bin/matmul2 bin/matmul3

bin/matmul1: src/matmul1.cpp build/input.o build/ijkmul.o
	bash bash/createbin.sh
	g++ $(CFLAGS) -I./inc src/matmul1.cpp build/input.o build/ijkmul.o -o bin/matmul1

bin/matmul2: src/matmul2.cpp build/input.o build/kijmul.o
	bash bash/createbin.sh
	g++ $(CFLAGS) -I./inc src/matmul2.cpp build/input.o build/kijmul.o -o bin/matmul2

bin/matmul3: src/matmul3.cpp build/input.o build/row_blocked_mul.o
	bash bash/createbin.sh
	g++ $(CFLAGS) -I./inc src/matmul3.cpp build/input.o build/row_blocked_mul.o -o bin/matmul3

build/input.o: src/input.cpp inc/input.hpp
	bash bash/createbuild.sh
	g++ $(CFLAGS) -I./inc src/input.cpp -c -o build/input.o

build/ijkmul.o: src/ijkmul.cpp inc/ijkmul.hpp
	bash bash/createbuild.sh
	g++ $(CFLAGS) -I./inc src/ijkmul.cpp -c -o build/ijkmul.o

build/kijmul.o: src/kijmul.cpp inc/kijmul.hpp
	bash bash/createbuild.sh
	g++ $(CFLAGS) -I./inc src/kijmul.cpp -c -o build/kijmul.o

build/row_blocked_mul.o: src/row_blocked_mul.cpp inc/row_blocked_mul.hpp
	bash bash/createbuild.sh
	g++ $(CFLAGS) -I./inc src/row_blocked_mul.cpp -c -o build/row_blocked_mul.o

clean:
	rm -rf bin
	rm -rf build

all: bin/matmul1 bin/matmul2 bin/matmul3

matmul1: bin/matmul1

matmul2: bin/matmul2

matmul3: bin/matmul3

.PHONY: all matmul1 matmul2 matmul3 clean
