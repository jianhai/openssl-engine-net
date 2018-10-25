.PHONY: all clean

TARGET := net_engine.so

LIB_SOURCES :=	net_engine.c \
				net_rsa.c \
				net_ec.c

LIB_OBJECTS := $(LIB_SOURCES:%.c=%.o)

CFLAGS := -Wall

%.o: %.c 
	gcc -c -fPIC ${CFLAGS} -o $@ $<

all: ${LIB_OBJECTS}
	gcc -shared -lcrypto -o ${TARGET} -lcrypto ${LIB_OBJECTS}

clean:
	rm -rf ${LIB_OBJECTS}
	rm -rf ${TARGET}

test:
	openssl engine -t -tt -vvvv -c `pwd`/${TARGET}
