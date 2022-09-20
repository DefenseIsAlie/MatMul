CFLAGS = -g -Wall -Werror -std=c++17 -pedantic -Wvla -O3 -march=native

PAPI_INCLUDE_PATH=/home/s200010021/papi_install/usr/local/include
PAPI_LIB_PATH=/home/s200010021/papi_install/usr/local/lib

ifeq ($(DEBUG),1)
CFLAGS += -I$(PAPI_INCLUDE_PATH) -DPAPI 
LDFLAGS =  -L$(PAPI_LIB_PATH) -lpapi
endif

entry: bin/matmul1 bin/matmul2 bin/matmul3

bin/matmul1: src/matmul1.cpp build/input.o build/ijkmul.o build/test.o build/utils.o
	bash bash/createbin.sh
	g++ $(CFLAGS) -I./inc $^ -o $@ $(LDFLAGS)

bin/matmul2: src/matmul2.cpp build/input.o build/kijmul.o build/test.o build/utils.o
	bash bash/createbin.sh
	g++ $(CFLAGS) -I./inc $^ -o $@ $(LDFLAGS)

bin/matmul3: src/matmul3.cpp build/input.o build/row_blocked_mul.o build/test.o  build/utils.o
	bash bash/createbin.sh
	g++ $(CFLAGS) -I./inc $^ -o $@ $(LDFLAGS)

build/input.o: src/input.cpp inc/input.hpp
	bash bash/createbuild.sh
	g++ $(CFLAGS) -I./inc $< -c -o $@

build/ijkmul.o: src/ijkmul.cpp inc/ijkmul.hpp
	bash bash/createbuild.sh
	g++ $(CFLAGS) -I./inc $< -c -o $@

build/kijmul.o: src/kijmul.cpp inc/kijmul.hpp
	bash bash/createbuild.sh
	g++ $(CFLAGS) -I./inc $< -c -o $@

build/test.o: src/test.cpp inc/test.hpp
	bash bash/createbuild.sh
	g++ $(CFLAGS) -I./inc $< -c -o $@

build/utils.o: src/utils.cpp inc/utils.hpp
	bash bash/createbuild.sh
	g++ $(CFLAGS) -I./inc $< -c -o $@

build/row_blocked_mul.o: src/row_blocked_mul.cpp inc/row_blocked_mul.hpp
	bash bash/createbuild.sh
	g++ $(CFLAGS) -I./inc $< -c -o $@

clean:
	rm -rf bin
	rm -rf build

all: bin/matmul1 bin/matmul2 bin/matmul3

matmul1: bin/matmul1

matmul2: bin/matmul2

matmul3: bin/matmul3

.PHONY: all matmul1 matmul2 matmul3 clean team

team:
	echo 'Josyula V N Taraka Abhishek 200010021@iitdh.ac.in'