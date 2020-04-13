FLAGS=-Wall -Wextra -Wshadow -Wno-unused-result -D_GLIBCXX_DEBUG -fsanitize=address -fsanitize=undefined -fno-sanitize-recover

run_a run_A: clean
	@g++ A.cpp $(FLAGS) -D_LOCAL_ && ./a.out < z.in

run_b run_B: clean
	 @g++ B.cpp $(FLAGS) -D_LOCAL_ && ./a.out < z.in

run_c run_C: clean
	@g++ C.cpp $(FLAGS) -D_LOCAL_ && ./a.out < z.in

run_d run_D: clean
	@g++ D.cpp $(FLAGS) -D_LOCAL_ && ./a.out < z.in

run_e run_E: clean
	@g++ E.cpp $(FLAGS) -D_LOCAL_ && ./a.out < z.in

run_f run_F: clean
	@g++ F.cpp $(FLAGS) -D_LOCAL_ && ./a.out < z.in

run_g run_G: clean
	@g++ G.cpp $(FLAGS) -D_LOCAL_ && ./a.out < z.in

run_h run_H: clean
	@g++ H.cpp $(FLAGS) -D_LOCAL_ && ./a.out < z.in



run_py: clean
	@/usr/bin/python3 /home/gremio/aaCP/python.py < z.in

run_java: clean
	@javac Main.java && java Main < z.in



run_flag_a: clean
	@g++ A.cpp -D_LOCAL_ && ./a.out < z.in

run_gdb_a: clean
	g++ -g -D_LOCAL_ A.cpp && gdb a.out -q

run_memory_a: clean
	@g++ A.cpp -Wall -Wextra -Wshadow -Wno-unused-result -D_GLIBCXX_DEBUG -fsanitize=undefined -fno-sanitize-recover -D_LOCAL_ && ./a.out < z.in

run_memory_b: clean
	@g++ B.cpp -Wall -Wextra -Wshadow -Wno-unused-result -D_GLIBCXX_DEBUG -fsanitize=undefined -fno-sanitize-recover -D_LOCAL_ && ./a.out < z.in

run_memory_c: clean
	@g++ C.cpp -Wall -Wextra -Wshadow -Wno-unused-result -D_GLIBCXX_DEBUG -fsanitize=undefined -fno-sanitize-recover -D_LOCAL_ && ./a.out < z.in

run_memory_d: clean
	@g++ D.cpp -Wall -Wextra -Wshadow -Wno-unused-result -D_GLIBCXX_DEBUG -fsanitize=undefined -fno-sanitize-recover -D_LOCAL_ && ./a.out < z.in



clean:
	@rm -rf a.out *.class
