final: Q1.o
		gcc Q1.o -o Q1

Q1.o: Q1.s
		gcc -c Q1.s -o Q1.o

Q1.s: Q1.i
		gcc -S Q1.i -o Q1.s

Q1.i: Q1.c marks.csv
		gcc -E Q1.c -o Q1.i