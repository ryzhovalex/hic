export t="Main"


compile:
	gcc src/$(t).c -o bin/a.out

run: compile
	./bin/a.out
