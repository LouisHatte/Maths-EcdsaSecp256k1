export CC		=	gcc
export CFLAGS	=	-Iinclude -Ilib -g3
export REMOVE 	=	rm -f

LDFLAGS	=	-Llib/ -lgmp

EXEC_DIR	=	bin/

EXEC_PUBKEY 	=	pubKey
SRC_PUBKEY	=	$(addprefix src/, \
					main.c \
					secp256k1.c \
					modinv.c \
					ECdouble.c)
OBJ_PUBKEY	=	$(SRC_PUBKEY:.c=.o)


all: $(EXEC_PUBKEY) clean

$(EXEC_PUBKEY): $(OBJ_PUBKEY)
	$(CC) -o $(EXEC_DIR)$@ $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(REMOVE) $(OBJ_PUBKEY)

fclean:
	$(REMOVE) $(EXEC_DIR)$(EXEC_PUBKEY)

re: fclean all

.PHONY: all clean fclean re
