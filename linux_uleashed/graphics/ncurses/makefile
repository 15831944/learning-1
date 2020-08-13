CC = gcc
AR = ar
EXECUTABLES = initcurs newterm curschar cursstr cursbox cursinch cursgstr color cursutil
OBJECTS =  
OTHER_FILES = dump.win

all: $(EXECUTABLES)

initcurs: initcurs.c
	$(CC) -o initcurs initcurs.c -lcurses

newterm: newterm.c
	$(CC) -o newterm newterm.c -lcurses

curschar:curschar.c
	$(CC) -o curschar curschar.c -lcurses

cursstr:cursstr.c
	$(CC) -o cursstr cursstr.c -lcurses
	
cursbox:cursbox.c
	$(CC) -o cursbox cursbox.c -lcurses

cursinch:cursinch.c
	$(CC) -o cursinch cursinch.c -lcurses

cursgstr:cursgstr.c
	$(CC) -o cursgstr cursgstr.c -lcurses

color: color.c
	$(CC) -o color color.c -lcurses

cursutil: cursutil.c
	$(CC) -o cursutil cursutil.c -lcurses
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
	