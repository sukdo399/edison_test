#Makefile

cc = gcc
#cc = ${CC}

TARGET = gpio13_mraa
OBJECT = $(TARGET).o

CCFLAGS =
LDFLAGS =  -lmraa

$(TARGET): $(OBJECT)
	$(cc) $(LDFLAGS) -o $@ $(OBJECT)
%.o:%.c
	$(cc) $(CCFLAGS) -c -o $@ $<
clean:
	rm -f *.o $(TARGET)


