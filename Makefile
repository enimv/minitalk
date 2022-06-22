
ft_server = ft_server
ft_client = ft_client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
client = ./client/ft_client.c
server = ./server/ft_server.c

all : server client
server : $(ft_server)
$(ft_server) : $(server)
	@$(CC) $(CFLAGS) $(server) -o $(ft_server)
	@echo SERVER IS READY !!!
client : $(ft_client)
$(ft_client) : $(client)
	@$(CC) $(CFLAGS) $(client) -o $(ft_client)
	@echo CLIENT IS READY !!!
clean :
	@rm -rf $(ft_client) $(ft_server)
	@echo CLEAN !!!
fclean :
	@rm -rf $(ft_client) $(ft_server)
	@echo RESET...
re : fclean all