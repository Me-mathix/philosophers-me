NAME			:= philo
SRC_DIR			:= src
OBJ_DIR			:= obj
SRCS			:= main.c init_args.c exec_philo.c actions.c utils.c utils2.c
#commande shell pour les src: ls src/. | tr "\n" " " > oui | cat; rm oui
SRCS			:= $(SRCS:%=$(SRC_DIR)/%)
OBJS			:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS			:= $(OBJS:.o=.d)
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -pthread
CPPFLAGS		:= -MMD -MP -I include
#CFLAGS			:= -g3 -Iinclude
RM				:= rm -rf
DIR_DUP			= mkdir -p $(@D)

all		:	$(NAME)

$(NAME) :	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

-include $(DEPS)

clean	:
	$(RM) $(OBJ_DIR)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY: all clean fclean re
