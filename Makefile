CC=gcc
FLAGS= -Wall -Werror -Wextra -W

all: build

build: clean create_dir src/code/main.c 
	$(CC) $(FLAGS) src/code/main.c -o ./build/main.c

create_dir: 
	mkdir -p build

clean: 
	rm -rf build
