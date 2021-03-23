OBJECTS=command.o game.o game_reader.o graphic_engine.o screen.o space.o object.o player.o set.o die.o
SPACETEST=space.o set.o 
CFLAGS=-Wall -pedantic -g

.PHONY: clear clean

###################################################
# Main game
###################################################
all: oca clear
	valgrind -s --leak-check=full --track-origins=yes ./oca data.dat -l fchlog

oca: game_loop.o $(OBJECTS)
	gcc game_loop.o $(OBJECTS) -o oca

game_loop.o: game_loop.c graphic_engine.h game.h command.h space.h \
 types.h set.h player.h object.h die.h game_reader.h
	gcc $(CFLAGS) -c game_loop.c

command.o: command.c command.h
	gcc $(CFLAGS) -c command.c

game.o: game.c game.h command.h space.h types.h set.h player.h object.h \
 die.h
	gcc $(CFLAGS) -c game.c
	
game_reader.o: game_reader.c game_reader.h game.h command.h space.h \
 types.h set.h player.h object.h die.h
	gcc $(CFLAGS) -c game_reader.c
	
graphic_engine.o: graphic_engine.c screen.h graphic_engine.h game.h \
 command.h space.h types.h set.h player.h object.h die.h
	gcc $(CFLAGS) -c graphic_engine.c	
	
screen.o: screen.c screen.h
	gcc $(CFLAGS) -c screen.c
	
space.o: space.c types.h space.h set.h
	gcc $(CFLAGS) -c space.c

object.o: object.c object.h types.h
	gcc $(CFLAGS) -c object.c
	
player.o: player.c player.h types.h
	gcc $(CFLAGS) -c player.c

set.o: set.c set.h types.h
	gcc $(CFLAGS) -c set.c

die.o: die.c die.h types.h
	gcc $(CFLAGS) -c die.c
	
###################################################
# Clean up
###################################################
clear:
	rm -rf *.o 

clean:
	rm -rf *.o *_test oca 


###################################################
# Space test 
###################################################
run_space_test: space_test clear
	valgrind -s --leak-check=full ./space_test

space_test: space_test.o $(SPACETEST)
	gcc $^ -o space_test

space_test.o: space_test.c space.h types.h set.h space_test.h test.h
	gcc $(CFLAGS) -c space_test.c


###################################################
# Die test 
###################################################
run_die_test: die_test clear
	valgrind -s --leak-check=full ./die_test

die_test: die_test.o die.o
	gcc $^ -o die_test

die_test.o: die_test.c die.h types.h die_test.h test.h
	gcc $(CFLAGS) -c die_test.c


###################################################
# Set test 
###################################################
run_set_test: set_test clear
	valgrind -s --leak-check=full ./set_test

set_test: set_test.o set.o
	gcc $^ -o set_test

set_test.o: set_test.c set.h types.h set_test.h test.h
	gcc $(CFLAGS) -c set_test.c