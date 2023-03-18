# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 15:13:10 by teppei            #+#    #+#              #
#    Updated: 2023/03/18 20:11:03 by teppei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		= 	clang++
NAME 		= 	PmergeMe
CFLAG 		= 	-Wall -Wextra -Werror -std=c++98
INCLUDES	=	-I.
SRCDIR		=	./
SRCS		=	$(shell ls *.cpp)
OBJDIR		=	./obj/
OBJS		=	$(SRCS:%.cpp=$(OBJDIR)%.o)

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir obj

$(NAME): $(OBJS)
	$(CXX) $(CFLAG) -o $@ $^

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CXX) $(CFLAG) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
