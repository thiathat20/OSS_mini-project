CC = gcc
OBJECT = main.c product.o manager.o
TARGET = project
CFLAGES = -W -Wall 
DTARGET = project_D

all: $(TARGET) $(DTARGET)
$(TARGET): $(OBJECT)
	$(CC) $(CFLAGES) -o $@ $^
$(DTARGET): $(OBJECT)
	$(CC) $(CFLAGES) -DDEBUG -o $@ $^
clean:
	rm *.o
	rm $(TARGET) $(DTARGET)
