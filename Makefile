player.o: player.c player.h utils.h setup.h
	gcc -c player.c

food.o: food.c food.h utils.h setup.h
	gcc -c food.c

utils.o: utils.c utils.h setup.h
	gcc -c utils.c

main.o: main.c utils.h player.h food.h setup.h
	gcc -c main.c 

main: utils.o main.o player.o food.o
	gcc -o main main.o utils.o player.o food.o -lraylib

clean: main
	rm -f *.o
	mkdir -p ./target/
	mv main ./target/

run: clean
	./target/main
