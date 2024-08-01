#####################################################
CC = gcc				# Gcc Compiler
CCARM = arm-none-eabi-gcc 		# ARM Compiler

CFLAGS = -W -Wall -g -Iincludes/# warnings
LDFLAGS = -mfloat-abi=soft #enbale floating points
CCARM_FLAGS = -mcpu=cortex-m0 -mthumb -Wall -Wextra -std=gnu11 -O1 
LDSCRIPT = lib/stm32f030f4.ld -nostdlib -Wl,-Map=build/final.map

EXTRA_CFLAGS=-fprofile-arcs -ftest-coverage
EXTRA_LDFLAGS=--coverage 

#### Sources variables
OBJ=build/main.o build/functions.o build/startup.o
EXEC=build/main.elf

#### Unitary tests variables
TEST_SRC=tests/tests.c
TEST_OBJ=build/tests.o build/test_functions.o
TEST_EXEC=build/tri_tests
TEST_LDFLAGS=-lcheck -lpthread -lm
TEST_OS_DEP_LFLAGS= 

UNAME=$(shell uname)

ifeq ($(UNAME), Linux)
	TEST_OS_DEP_LFLAGS=-lsubunit -lrt
endif
#####################################################

all: main tests

################# Compile main code #################
main: $(EXEC)

build/main.o: src/main.c src/functions.h
	mkdir -p build
	$(CCARM) $(CFLAGS) $(LDFLAGS) -c $< -o $@

build/functions.o: src/functions.c src/functions.h
	$(CCARM) $(CFLAGS) $(LDFLAGS) -c $< -o $@
	
build/startup.o: src/stm32_startup.c
	$(CCARM) $(CCARM_FLAGS) $(LDFLAGS) -T $(LDSCRIPT) -c $< -o $@

$(EXEC): $(OBJ)
	$(CCARM) $(CCARM_FLAGS) $(LDFLAGS) -T $(LDSCRIPT) $^ -o $(EXEC) 
	
#####################################################



################# Compile test code #################
tests: $(TEST_EXEC)

build/test_functions.o: src/functions.c
	mkdir -p build
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS) -c $< -o $@
	
build/tests.o: tests/tests.c
	mkdir -p build
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS) -c $< -o $@
	
$(TEST_EXEC): $(TEST_OBJ)
	$(CC) $(TEST_OBJ) $(TEST_LDFLAGS) $(EXTRA_LDFLAGS) $(TEST_OS_DEP_LFLAGS) -o $(TEST_EXEC)
#####################################################



################### Code loading ####################
load:
	#openocd -f board/st_nucleo_f4.cfg	#Debug
	openocd -f board/st_nucleo_f0.cfg
#####################################################



##################### Cleaning ######################
clean:
	@rm -rf build/* build/*.gc* src/*.dump build/final.map functions.c.gcov tests.c.gcov tests/index* tests/tests.c.* src/index* src/functions.c.*
	find . -mindepth 1 -maxdepth 1 ! -name 'build' ! -name 'src' ! -name 'tests' ! -name 'lib' ! -name 'README.md' ! -name 'Makefile' -exec rm -rf {} +

mrproper: clean
	@rm -rf $(TEST_EXEC)
#####################################################



##################### Coverage ######################
coverage:
	./build/tri_tests
	gcov -o build -f -b build/test*
	lcov --directory build --base-directory . -c -o cov.info
	genhtml cov.info
#####################################################
