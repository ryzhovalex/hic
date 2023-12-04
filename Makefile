export t="Main"
export runargs=""


build:
	@gcc Source/$(t).c Source/Utils.c -o Bin/main

run: build
	@./Bin/main $(runargs)
