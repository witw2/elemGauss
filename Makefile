all:
	gcc -Wall --pedantic src/*.c -o gauss
test: all
	gauss dane/A dane/b
	gauss dane/1_1 dane/1_2
	gauss dane/2_2 dane/2_2
