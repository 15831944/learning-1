CC = gcc
EXECUTABLES = badptr testmacs chkexit errs mask_log
OTHER_FILES = foo_bar

all: $(EXECUTABLES)

badptr: badptr.c
	$(CC) -o badptr badptr.c

testmacs: filefcn.c filefcn.h testmacs.c
	$(CC) -o testmacs filefcn.c testmacs.c
	
chkexit:chkexit.c
	$(CC) -o chkexit chkexit.c

errs:errs.c
	$(CC) -o errs errs.c -lm
	
mask_log:mask_log.c
	$(CC) -o mask_log mask_log.c
	
clean:
	for object in $(EXECUTABLES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done
	for object in $(OTHER_FILES);\
	do \
		if [ -f $$object ]; then rm $$object; fi; \
	done