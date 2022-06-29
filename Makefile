SERVER		= server
CLIENT		= client
CLIENT_FILE	= client_file/client.c client_file/diplay.c
CLIENT_BONUS = client_file/client_bonus.c client_file/diplay.c
SERVER_FILE	= server_file/server_util.c server_file/server.c
SERVER_BONUS = server_file/server_util.c server_file/server_bonus.c
UTIL_FILE	= util/util.c
INCLUDE =	client_file/client.h server_file/server.h util/util.h
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rfv

OBJ		=	$(CLIENT_FILE:.c=.o) $(SERVER_FILE:.c=.o)
OBJ_B	=	$(CLIENT_BONUS:.c=.o) $(SERVER_BONUS:.c=.o)

all:		$(SERVER) $(CLIENT)

bonus:		$(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_B)
		$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_BONUS) $(UTIL_FILE)

$(CLIENT_BONUS): $(OBJ_B)
		$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_BONUS) $(UTIL_FILE)

$(SERVER):	$(OBJ)
		$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_FILE) $(UTIL_FILE)

$(CLIENT):	$(OBJ)
		$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_FILE) $(UTIL_FILE)

clean:
			@$(RM) $(OBJ)
			@$(RM) $(OBJ_B)

fclean:		clean
			@$(RM) $(SERVER) $(CLIENT)

re:		fclean all

.PHONY:	all clean fclean re bonus
