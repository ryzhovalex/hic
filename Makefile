export t="Main"


compile:
	@gcc Source/$(t).c -o Bin/a.out

run: compile
	@./Bin/a.out
