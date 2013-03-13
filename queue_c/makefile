#for libqueue_c.h
# (- makefile stops if it cannot delete somthing)
#----------------------------------------------------------

NAME	= libqueue_c.a
HFILE= queue_c.h
RM	= rm -f
SRC	= c_init.c c_push.c c_node_update.c c_pop.c

OBJ	= $(SRC:.c=.o)
TESTNAME= test
TESTSRC	= main.c
TESTOBJ = $(TESTSRC:.c=.o)
LIBS	= -lqueue_c -lmy
LPATH	= ../lib/
#----------------------------------------------------------
all:	$(OBJ)
	cp $(HFILE) $(LPATH) 
	ar -rc	$(NAME)	$(OBJ)
	ranlib $(NAME)
	cp $(NAME) $(LPATH)

clean:	
	-$(RM) *.o
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core

fclean:	clean
	-$(RM) $(LPATH)$(NAME)
	-$(RM) $(TESTNAME)
	-$(RM) $(NAME)

re:	fclean all

test:	$(NAME) $(TESTOBJ)
	cc -L $(LPATH) $(TESTSRC) $(LIBS) -o $(TESTNAME)

$(NAME):all

rt:	fclean test
#----------------------------------------------------------

