# Variables
NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
CLIENT = client
SERVER = server

# Source files
CLIENT_SRCS = client.c
SERVER_SRCS = server.c

# Object files
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

# Default rule to compile both client and server
all: $(CLIENT) $(SERVER) $(LIBFT)

# Rule to compile libft
$(LIBFT):
	cd $(LIBFT_DIR) && make

# Rule to compile the client
$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(LIBFT)
	@echo "Client compiled."

# Rule to compile the server
$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) $(LIBFT)
	@echo "Server compiled."

# Clean object files and libraries
clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)
	@echo "Object files removed."
	@cd $(LIBFT_DIR) && make clean
	@echo "Cleaned libft and libftprintf."

# Clean everything (object files and libraries)
fclean: clean
	rm -f $(CLIENT) $(SERVER)
	@echo "Executables removed."
	@cd $(LIBFT_DIR) && make fclean
	@echo "Cleaned libft and libftprintf completely."

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
