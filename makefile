# credit
# http://nuclear.mutantstargoat.com/articles/make/#practical-makefile

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = -lGL -lglut -lpng -lz -lm

myprog: $(obj)
	g++ -o $@ $^

.PHONY: clean
clean:
	rm -f $(obj) myprog
