# Variables
NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFTPRINTF_DIR = ./printf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a
CLIENT = client
SERVER = server

# Source files
CLIENT_SRCS = client.c
SERVER_SRCS = server.c

# Object files
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

# Rule to compile libft
$(LIBFT):
	cd $(LIBFT_DIR) && make

# Rule to compile libftprintf
$(LIBFTPRINTF): $(LIBFT)
	cd $(LIBFTPRINTF_DIR) && make

# Rule to compile the client
$(CLIENT): $(CLIENT_OBJS) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(LIBFT) $(LIBFTPRINTF)
	@echo "Client compiled."

# Rule to compile the server
$(SERVER): $(SERVER_OBJS) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) $(LIBFT) $(LIBFTPRINTF)
	@echo "Server compiled."

# Default rule to compile both client and server
all: $(CLIENT) $(SERVER)

# Clean object files and libraries
clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)
	@echo "Object files removed."
	@cd $(LIBFT_DIR) && make clean
	@cd $(LIBFTPRINTF_DIR) && make clean
	@echo "Cleaned libft and libftprintf."

# Clean everything (object files and libraries)
fclean: clean
	rm -f $(CLIENT) $(SERVER)
	@echo "Executables removed."
	@cd $(LIBFT_DIR) && make fclean
	@cd $(LIBFTPRINTF_DIR) && make fclean
	@echo "Cleaned libft and libftprintf completely."

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
