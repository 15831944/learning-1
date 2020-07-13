CC = gcc

EXECUTABLES = rcat

all: $(EXECUTABLES)

rcat: rcat.c
	$(CC) -fPIC -o rcat rcat.c
		
clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done 