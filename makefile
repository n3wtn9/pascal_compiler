# credit
# http://nuclear.mutantstargoat.com/articles/make/#practical-makefile

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

CC = clang++ -Wno-c++11-extensions
LDFLAGS = -lGL -lglut -lpng -lz -lm

myprog: $(obj)
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm -f $(obj) myprog
