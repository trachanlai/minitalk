CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = server.c client.c utils.c

all: server client

server.o : server.c utils.o
	$(CC) $(CFLAGS) -c server.c -o server.o

client.o : client.c utils.o
	$(CC) $(CFLAGS) -c client.c -o client.o

utils.o : utils.c
	$(CC) $(CFLAGS) -c utils.c -o utils.o

server : server.o utils.o
	$(CC) $(CFLAGS) server.o utils.o -o server

client : client.o utils.o
	$(CC) $(CFLAGS) client.o utils.o -o client

clean:
	rm -f server.o client.o utils.o

fclean: clean
	rm -f server client

re: fclean all


# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# SRC = server.c client.c utils.c

# OBJ_SERVER = server.o
# OBJ_CLIENT = client.o
# OBJ_UTILS = utils.o

# all: server client

# $(OBJ_SERVER) : server.c $(OBJ_UTILS)
# 	$(CC) $(CFLAGS) -c server.c -o $(OBJ_SERVER)

# $(OBJ_CLIENT) : client.c $(OBJ_UTILS)
# 	$(CC) $(CFLAGS) -c client.c -o $(OBJ_CLIENT)

# $(OBJ_UTILS) : utils.c
# 	$(CC) $(CFLAGS) -c utils.c -o $(OBJ_UTILS)

# server : $(OBJ_SERVER) $(OBJ_UTILS)
# 	$(CC) $(CFLAGS) $(OBJ_SERVER) $(OBJ_UTILS) -o server

# client : $(OBJ_CLIENT) $(OBJ_UTILS)
# 	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(OBJ_UTILS) -o client

# clean:
# 	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_UTILS)

# fclean: clean
# 	rm -f server client

# re: fclean all
