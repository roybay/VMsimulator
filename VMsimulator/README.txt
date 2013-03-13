VMsimulator(4)

NAME
     VMsimulator

SYNOPSIS
     VMsimulator <plist> <ptrace> <sizeofpages> <repalgorith> <flag>

DESCRIPTION
     A program  is to simulate a virtual memory management system. You will 
     experiment with different page replacement algorithms. Your program must
     accept the following parameters at the command prompt in the order 
     specified:	
	
     <plist>             The number of process list.
                         Type is external File name.
	
     <ptrace>            The number of running process list.
                         Type is external File name.	

     <sizeofpages>       Size of pages number of memory location on each page.
                         Type is positive integer.				

     <repalgorith>       FIFO, LRU or CLOCK for type of page replacement 
                         algorithms
                         Type is algorithms.
                         FIFO. for First-Come-First-Serve
                         LRU. for Least Recently Used
                         CLOCK. for Clock Page Replacement	

     <flag>              Turn on/off for pre-paging
                         +. for turn it on
                         -. for turn it off	
     
     <help>              Display manual page.

     <?>                 Display manual page.

EXAMPLES
     ./VMsimulator plist ptrace 2 FIFO +
          Receive 2 file names
          one is proccecer list and the other one is running procceser list.
          It runs the simulator algorithm for page size of equal to 2.
          FIFO replacement algorithm with pre-paging.
          
     ./pc ?
          Shows manual page.
     ./pc help
          Shows manual page.

AUTHOR
     Written by Roy Bahian.

REPORTING BUGS
     Please report sempipetest bugs to roy@bahian.us

RETURN
     Each item will be printed out.
     
NOTES
     Fist two parameters will be tested if it is maximum lenght of 20 character. 
     Third parameter will be tested if it is positive integer power of two. It 
     is allowed up to 32. Constant can be change in header file. 
     Forth parameter will be tested if it is FIFO, LRU or CLOCK
     Fifth parameter will be tested wheather is + or -.

WARNINS
     <W1001>             init_program          line 16

ERRORS
     <E1001>             std_param_check       line 11
     <E1002>             std_param_check       line 21
     <E1003>             std_param_check       line 37
     <E1004>             std_param_check       line 48
     <E1005>             std_param_check       line 58
     <E1006>             get_instance_count    line  9
     <E1007>             init_programs         line 14
     <E1008>             fifo_replacement      line 13
     <E1009>             lru_replacement       line 13
     <E1010>             clock_replacement     line 13

