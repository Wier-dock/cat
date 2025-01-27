CC=gcc
FLAGS= -Wall -Werror -Wextra -W

all: build

build: clean create_dir src/code/main.c src/headers/cat.h
	$(CC) $(FLAGS) src/code/main.c src/headers/cat.h -o ./build/app

style: src/code/main.c src/headers/cat.h 
	clang-format -i src/code/main.c src/headers/cat.h 

create_dir: 
	mkdir -p build

clean: 
	rm -rf build
