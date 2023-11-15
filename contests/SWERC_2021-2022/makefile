run: a.out
	./a.out < in.in

a.out: $(EXE).cpp
	g++ -Wall -Wextra -Wshadow -Wno-unused-result -g -fsanitize=address -o a.out $(EXE).cpp