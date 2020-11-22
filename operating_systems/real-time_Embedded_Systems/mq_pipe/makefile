CC = gcc
AR = ar
EXECUTABLES = master mqreader mqwriter pipe_ex
OBJECTS = 
OTHER_FILES =  

all: $(OBJECTS) $(EXECUTABLES)

master:master.c mqheader.h
	$(CC) -fPIC -o master master.c -lrt
	
mqreader:mqreader.c mqheader.h
	$(CC) -fPIC -o mqreader mqreader.c -lrt

mqwriter:mqwriter.c mqheader.h
	$(CC) -fPIC -o mqwriter mqwriter.c -lrt

pipe_ex:pipe_ex.c
	$(CC) -fPIC -o pipe_ex pipe_ex.c
		
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
	