#for VMsimulator.h
# (- makefile stops if it cannot delete somthing)
#----------------------------------------------------------
NAME	= VMsimulator
RM	= rm -f
SRC	= std_input_check.c std_input_error.c std_param_check.c \
	  read_file.c get_instance_count.c init_programs.c \
	  init_pages.c run_programs.c time_stamp.c demand_fifo_replacement.c \
	  demand_lru_replacement.c demand_clock_replacement.c \
	  prepaging_fifo_replacement.c prepaging_lru_replacement.c \
	  prepaging_clock_replacement.c

OBJ	= $(SRC:.c=.o)

TESTNAME= VMsimulator
TESTSRC= main.c
TESTOBJ= $(TESTSRC:.c=.o)

LIBS	= -lmy -lqueue_r -lqueue_p -lqueue_c
LPATH= ../lib/ -lrt
#----------------------------------------------------------
all:	object testobj

object:	
	cc -c $(SRC)

lib:	
	./queue_p/make fclean;
	

testobj:
	cc -c $(TESTSRC)

clean:	
	-$(RM) *.o
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core
	-$(RM) *.gch

fclean:	clean
	-$(RM) $(TESTNAME)
	
re:	fclean all

test:	all
	cc $(SRC) $(TESTSRC) -L $(LPATH) $(LIBS) -o $(TESTNAME)

$(NAME):all

rt:	fclean test
#----------------------------------------------------------

