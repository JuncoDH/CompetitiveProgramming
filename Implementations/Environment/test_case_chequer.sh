# Testing locally a lot of tests automatically.
for i in *.in
do
	problem=${ i%.in };
	./a.out < $problem.in > answer.out;
	echo Case $problem:;
	# -w for ignoring spaces.
	diff --color answer.out $problem.out;
done

