
FLAGS=-Wall -Wextra -Wshadow -Wno-unused-result -D_GLIBCXX_DEBUG -fsanitize=address -fsanitize=undefined -fno-sanitize-recover

run_a: clean
	@g++ a.cpp $(FLAGS) -D_LOCAL_ && ./a.out < d.in

run_b: clean
	 @g++ b.cpp $(FLAGS) -D_LOCAL_ && ./a.out < d.in

run_c: clean
	@g++ c.cpp $(FLAGS) -D_LOCAL_ && ./a.out < d.in

run_d: clean
	@g++ d.cpp $(FLAGS) -D_LOCAL_ && ./a.out < d.in

run_e: clean
	@g++ e.cpp $(FLAGS) -D_LOCAL_ && ./a.out < d.in

run_py:
	@/usr/bin/python3 /home/gremio/cp/python.py < d.in

run_java:
	@javac Main.java && java Main < d.in



run_val_a:
	@g++ a.cpp -D_LOCAL_ && valgrind --leak-check=full --track-origins=yes ./a.out < d.in

run_out_b: clean
	@g++ b.cpp $(FLAGS) -D_LOCAL_ && ./a.out < d.in > d.out

run_noflags_b: clean
	@g++ b.cpp -D_LOCAL_ && ./a.out < d.in

clean:
	@rm -rf a.out
