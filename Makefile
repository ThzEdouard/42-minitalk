SERVER = server
CLIENT = client
SERVER_B = server_bonus
CLIENT_B = client_bonus
SERVER_FILE = server_file/server.c server_file/server_util.c util/util.c
SERVER_FILE_BONUS = server_file/server_bonus.c server_file/server_util.c util/util.c
CLIENT_FILE = client_file/client.c client_file/diplay.c util/util.c
CLIENT_FILE_BONUS = client_file/client_bonus.c client_file/diplay.c util/util.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rfv

OBJ_C = $(CLIENT_FILE:.c=.o) 
OBJ_S = $(SERVER_FILE:.c=.o)
OBJ_BC = $(CLIENT_FILE_BONUS:.c=.o) 
OBJ_BS = $(SERVER_FILE_BONUS:.c=.o)

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_B) $(CLIENT_B)

$(SERVER_B):	$(OBJ_BS)
		$(CC) $(CFLAGS) -o $(SERVER_B) $(OBJ_BS) 

$(CLIENT_B):	$(OBJ_BC)
		$(CC) $(CFLAGS) -o $(CLIENT_B) $(OBJ_BC)

$(SERVER):	$(OBJ_S)
		$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_S) 

$(CLIENT):	$(OBJ_C)
		$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_C)

clean:
			@$(RM) $(OBJ_C)
			@$(RM) $(OBJ_S)
			@$(RM) $(OBJ_BC)
			@$(RM) $(OBJ_BS)

fclean:		clean
			@$(RM) $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)

re:		fclean all

.PHONY:	all clean fclean re bonus