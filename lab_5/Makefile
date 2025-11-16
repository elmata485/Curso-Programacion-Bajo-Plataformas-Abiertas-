CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude -g
LIBS = -lm


# Archivos fuente en src/
SRCS = $(wildcard src/*.c)


# Objetos generados automáticamente
OBJS = $(SRCS:.c=.o)


# Archivos de dependencias (.d)
DEPS = $(SRCS:.c=.d)




# Ejecutable final
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)



# Regla para generar .o y .d de cada .c
src/%.o: src/%.c
	$(CC) $(CFLAGS) -MMD -c -o $@ $<


# Incluye dependencias generadas automáticamente
-include $(DEPS)




clean:
	rm -f src/*.o src/*.d $(TARGET)





.PHONY: all clean

