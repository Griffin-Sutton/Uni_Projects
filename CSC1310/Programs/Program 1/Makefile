# ***************************** MovieTheater Makefile

all:				MovieTheaterProg

# The rule below will compile the program if .cpp files exist.
MovieTheaterProg:	Driver.cpp Movie.cpp Theater.cpp Showing.cpp
					g++ -Wall -o MovieTheaterProg Driver.cpp Movie.cpp Theater.cpp Showing.cpp

# Execute the rule below with "make run" (without the double quotes), which will run the program if the turtleprog executable exists.
run:				MovieTheaterProg
					./MovieTheaterProg

# Execute the rule below with "make clean" (without the double quotes), which will delete the executable file turtleprog if it exists.	
clean:				MovieTheaterProg
					rm -f MovieTheaterProg
	