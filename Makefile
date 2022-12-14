all:
	gcc -Wall --pedantic src/*.c -o gauss

test: all
	gauss dane/A dane/b

test: all
	gauss dane/1_1 dane/1_2

test: all
	gauss dane/2_2 dane/2_2

