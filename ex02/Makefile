# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 15:13:10 by teppei            #+#    #+#              #
#    Updated: 2023/03/19 13:38:13 by teppei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 				= 	c++
NAME 				= 	PmergeMe
CFLAG 			= 	-Wall -Wextra -Werror -std=c++98
INCLUDES		=	-I.
SRCDIR			=	./
SRCS				=	$(shell ls *.cpp)
OBJDIR			=	./obj/
OBJS				=	$(SRCS:%.cpp=$(OBJDIR)%.o)
DEBUG_MODE	= 0

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir obj

$(NAME): $(OBJS)
	$(CXX) $(CFLAG) -o $@ $^

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CXX) $(CFLAG) -D DEBUG_MODE=$(DEBUG_MODE) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: 
	make re DEBUG_MODE=1

undebug: re

.PHONY: clean fclean all re debug undebug
