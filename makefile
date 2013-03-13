#manage all makefiles
#----------------------------------------------------------
all:	
	cd my; make 
	cd queue_r; make
	cd queue_p; make
	cd queue_c; make
	cd VMsimulator; make
	
clean:	
	cd my; make clean 
	cd queue_r; make clean
	cd queue_p; make clean
	cd queue_c; make clean
	cd VMsimulator; make clean
	-$(RM) *~
	
fclean:	
	cd my; make fclean 
	cd queue_r; make fclean
	cd queue_p; make fclean
	cd queue_c; make fclean
	cd VMsimulator; make fclean
	-$(RM) *~

test:	all
	cd VMsimulator; make test
#----------------------------------------------------------

