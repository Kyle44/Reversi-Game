all:
	g++ -Wall Proj1.cpp Proj1.h UnoClass.cpp -o Proj1.out
run:
	./Proj1.out 4
clean:
	rm -rf *.o *~ *#
