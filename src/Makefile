.PHONY: all clean test s21_string.a check rebuild gcov open gcov_report
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
LINUX=-lsubunit -lrt -lpthread -lm
LIBS = -lcheck
CFLAGS=-fprofile-arcs -ftest-coverage
OS=$(shell uname -s)

all: clean s21_string.a test

s21_string.a: s21_string.o
	ar rcs s21_string.a s21_string.o
	cp s21_string.a libs21_string.a
	cp s21_string.a ls21_string.a
	ranlib libs21_string.a
	ranlib ls21_string.a

s21_string.o: s21_string.c
	$(CC) -c s21_string.c -o s21_string.o

test: s21_string.a
ifeq ($(OS), Darwin)
	$(CC) test.c s21_string.a -o test $(LIBS)
	./test
else
	$(CC) test.c s21_string.a -o test $(LIBS) $(LINUX)
	./test
endif

gcov_report: s21_string.a
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) test.c s21_string.c s21_string.a -o test $(LIBS)
else
	$(CC) $(CFLAGS) test.c s21_string.c s21_string.a -o test $(LIBS) $(LINUX)
endif
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info

open:
	open report/index.html

rebuild: clean all

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	make test
	CK_FORK=no leaks --atExit -- ./test
	make clean

clean:
	rm -rf *.gc* *.o *.a *.out *.info test
	rm -rf report