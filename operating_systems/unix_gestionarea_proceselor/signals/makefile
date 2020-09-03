CC = gcc
AR = ar
EXECUTABLES = captureSignal reentrant sigchld exalarm exsetjmp sigaction sigaction1 sigpending sigsetjmp sigsuspend1 sigsuspend2 sleep_ex \
	sig_controll sig_system sig_system2 sig_system4 sig_proc_terminate sig_critical_srv2 sig_critical_srv4 finalApp fil
OBJECTS = print_mask.o sig.o sync.o sig_abort.o sys2.o sys4.o
OTHER_FILES = 

all: $(EXECUTABLES) $(OBJECTS)

captureSignal:captureSignal.c ../common/err.o
	$(CC) -fPIC -o captureSignal captureSignal.c ../common/err.o

reentrant:reentrant.c ../common/err.o
	$(CC) -fPIC -o reentrant reentrant.c ../common/err.o

sigchld:sigchld.c ../common/err.o
	$(CC) -fPIC -o sigchld sigchld.c ../common/err.o

exalarm:exalarm.c ../common/err.o
	$(CC) -fPIC -o exalarm exalarm.c ../common/err.o

exsetjmp:exsetjmp.c ../common/err.o
	$(CC) -fPIC -o exsetjmp exsetjmp.c ../common/err.o
	
print_mask.o:print_mask.c print_mask.h
	$(CC) -c print_mask.c -o print_mask.o
	
sig.o:sig.c sig.h
	$(CC) -c sig.c -o sig.o
	
sigaction:sigaction.c ../common/err.o
	$(CC) -fPIC -o sigaction sigaction.c ../common/err.o
	
sigaction1:sigaction.c ../common/err.o sig.o
	$(CC) -fPIC -o sigaction1 sigaction.c ../common/err.o sig.o

sigpending:sigpending.c ../common/err.o sig.o print_mask.o
	$(CC) -fPIC -o sigpending sigpending.c ../common/err.o sig.o print_mask.o
	
sigsetjmp:sigsetjmp.c ../common/err.o sig.o print_mask.o
	$(CC) -fPIC -o sigsetjmp sigsetjmp.c ../common/err.o sig.o print_mask.o

sigsuspend1:sigsuspend1.c ../common/err.o sig.o print_mask.o
	$(CC) -fPIC -o sigsuspend1 sigsuspend1.c ../common/err.o sig.o print_mask.o

sync.o:sync.c ../common/hdr.h sync.h
	$(CC) -o sync.o -c sync.c
	
sigsuspend2:sigsuspend2.c ../common/err.o sync.o
	$(CC) -fPIC -o sigsuspend2 sigsuspend2.c ../common/err.o sync.o

sig_abort.o:sig_abort.c
	$(CC) -o sig_abort.o -c sig_abort.c

sleep_ex:sleep_ex.c ../common/err.o sig.o
	$(CC) -fPIC -o sleep_ex sleep_ex.c ../common/err.o sig.o

sig_controll:sig_controll.c ../common/err.o
	$(CC) -fPIC -o sig_controll sig_controll.c ../common/err.o

sig_system:sig_system.c ../common/err.o sig.o
	$(CC) -fPIC -o sig_system sig_system.c ../common/err.o sig.o

sys2.o:sys2.c sys2.h
	$(CC) -o sys2.o -c sys2.c

sys4.o:sys4.c sys4.h
	$(CC) -o sys4.o -c sys4.c
	
sig_system2:sig_system.c ../common/err.o sig.o sys2.o
	$(CC) -fPIC -o sig_system2 sig_system.c ../common/err.o sig.o sys2.o
	
sig_system4:sig_system.c ../common/err.o sig.o sys4.o
	$(CC) -fPIC -o sig_system4 sig_system.c ../common/err.o sig.o sys4.o

sig_proc_terminate:sig_proc_terminate.c ../common/err.o sig_abort.o
	$(CC) -fPIC -o sig_proc_terminate sig_proc_terminate.c ../common/err.o sig_abort.o

sig_critical_srv2:sig_critical_srv2.c ../common/err.o
	$(CC) -fPIC -o sig_critical_srv2 sig_critical_srv2.c ../common/err.o

sig_critical_srv4:sig_critical_srv4.c ../common/err.o sig.o print_mask.o
	$(CC) -fPIC -o sig_critical_srv4 sig_critical_srv4.c ../common/err.o print_mask.o

finalApp:finalApp.c ../common/err.o
	$(CC) -fPIC -o finalApp finalApp.c ../common/err.o

fil:fil.c ../common/err.o sig.o
	$(CC) -fPIC -o fil fil.c ../common/err.o sig.o
	
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
	