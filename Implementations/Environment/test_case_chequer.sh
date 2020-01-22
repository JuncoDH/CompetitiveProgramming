#For testing locally bunch of tests

for i in *.in
do
	j=${i%.in};
	./a.out < $j.in > answer.out;
	echo Case $j:;
	diff --color answer.out $j.out;
	#-w for ignoring spaces
done
