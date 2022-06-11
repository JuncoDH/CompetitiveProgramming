FLAGS=-g -Wall -Wextra -Wshadow -Wno-unused-result -D_GLIBCXX_DEBUG -fsanitize=address -fsanitize=undefined -fno-sanitize-recover

run_a run_A: clean
	@g++ A.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out < z.in

run_b run_B: clean
	@g++ B.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out < z.in

run_c run_C: clean
	@g++ C.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out < z.in

run_d run_D: clean
	@g++ D.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out < z.in

run_e run_E: clean
	@g++ E.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out < z.in

run_f run_F: clean
	@g++ F.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out < z.in

run_g run_G: clean
	@g++ G.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out < z.in

run_h run_H: clean
	@g++ H.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out < z.in

run_i run_I: clean
	@g++ I.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out < z.in

run_j run_J: clean
	@g++ J.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out < z.in

run_k run_K: clean
	@g++ K.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out < z.in

run_l run_L: clean
	@g++ L.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out < z.in



run_py: clean
	@/usr/bin/python3 /home/junco/zzCP/python.py < z.in

run_java: clean
	@cp z.in src/src/z.in
	@javac src/src/Main.java && cd src/src; java Main < z.in



# b 116 y run < z.in.
run_gdb_a: clean
	g++ -g -DJUNCO_DEBUG A.cpp && gdb a.out -q

run_gdb_b: clean
	g++ -g -DJUNCO_DEBUG B.cpp && gdb a.out -q

run_gdb_c: clean
	g++ -g -DJUNCO_DEBUG C.cpp && gdb a.out -q

run_gdb_d: clean
	g++ -g -DJUNCO_DEBUG D.cpp && gdb a.out -q

run_gdb_e: clean
	g++ -g -DJUNCO_DEBUG E.cpp && gdb a.out -q

run_gdb_f: clean
	g++ -g -DJUNCO_DEBUG F.cpp && gdb a.out -q

# Without input file. For interactive problems.
run_file_a run_file_A: clean
	@g++ A.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out

run_file_b run_file_B: clean
	@g++ B.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out

run_file_c run_file_C: clean
	@g++ C.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out

run_file_d run_file_D: clean
	@g++ D.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out

run_file_e run_file_E: clean
	@g++ E.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out

run_file_f run_file_F: clean
	@g++ F.cpp $(FLAGS) -DJUNCO_DEBUG && ./a.out

# Without flags, runs faster.
run_flag_a: clean
	@g++ A.cpp -Wall -Wextra -Wshadow -Wno-unused-result && ./a.out

run_flag_b: clean
	@g++ B.cpp -Wall -Wextra -Wshadow -Wno-unused-result && ./a.out

run_flag_c: clean
	@g++ C.cpp -Wall -Wextra -Wshadow -Wno-unused-result && ./a.out

run_flag_d: clean
	@g++ D.cpp -Wall -Wextra -Wshadow -Wno-unused-result && ./a.out

run_flag_e: clean
	@g++ E.cpp -Wall -Wextra -Wshadow -Wno-unused-result && ./a.out

run_flag_f: clean
	@g++ F.cpp -Wall -Wextra -Wshadow -Wno-unused-result && ./a.out

# Execute A.cpp and B.cpp and diff them.
bruteforce: clean
	@# make run_c > z2.in
	@g++ C.cpp -DJUNCO_DEBUG && ./a.out < z.in > z2.in
	@# make run_file_a < z2.in > za.out
	@g++ A.cpp -DJUNCO_DEBUG && ./a.out < z2.in > za.out
	@# make run_file_a < z2.in > zb.out
	@g++ B.cpp -DJUNCO_DEBUG && ./a.out < z2.in > zb.out
	diff za.out zb.out


clean:
	@rm -rf a.out

