#for libqueue_r.h
# (- makefile stops if it cannot delete somthing)
#----------------------------------------------------------

NAME	= libqueue_r.a
HFILE= queue_r.h
RM	= rm -f
SRC	= q_init.c q_push.c q_pop.c 

OBJ	= $(SRC:.c=.o)
TESTNAME= test
TESTSRC	= main.c
TESTOBJ = $(TESTSRC:.c=.o)
LIBS	= -lqueue_r -lmy
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

retest:	fclean test
#----------------------------------------------------------

