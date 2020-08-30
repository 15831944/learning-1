CC = gcc
AR = ar
EXECUTABLES = arguments test_fork fork ex_exit ex_wait double_fork ex_fork ex_fork_sync
OBJECTS = 
OTHER_FILES = 

all: $(EXECUTABLES)

arguments: arguments.c
	$(CC) -fPIC -o arguments arguments.c

fork: fork.c ../common/err.o
	$(CC) -fPIC -o fork fork.c ../common/err.o

test_fork: test_fork.c
	$(CC) -fPIC -o test_fork test_fork.c
	
ex_exit:ex_exit.c ../common/err.o 
	$(CC) -fPIC -o ex_exit ex_exit.c ../common/err.o
	
ex_wait:ex_wait.c ../common/print_exit.o ../common/err.o
	$(CC) -fPIC -o ex_wait ex_wait.c ../common/print_exit.o ../common/err.o

double_fork:double_fork.c ../common/print_exit.o ../common/err.o
	$(CC) -fPIC -o double_fork double_fork.c ../common/print_exit.o ../common/err.o

ex_fork:ex_fork.c ../common/err.o
	$(CC) -fPIC -o ex_fork ex_fork.c ../common/err.o
	
ex_fork_sync:ex_fork_sync.c ../common/err.o
	$(CC) -fPIC -o ex_fork_sync ex_fork_sync.c ../common/err.o			
clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	for object in $(OBJECTS);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	for object in $(OTHER_FILES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	