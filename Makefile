export t="Main"


build:
	@gcc Source/$(t).c -o Bin/main

run: build
	@./Bin/main
