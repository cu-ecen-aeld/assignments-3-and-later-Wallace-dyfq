SRC := writer.c
TARGET = writer
OBJS := $(SRC:.c=.o)
all: $(TARGET)
CC=gcc

$(TARGET) : $(OBJS)
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LDFLAGS)

clean:
	-rm -f *.o $(TARGET) *.elf *.map
