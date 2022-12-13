CC = gcc -Wall -Wextra -Werror -std=c11
SRC = s21_memset.c s21_strcat.c s21_strncat.c \
		s21_strchr.c s21_memcmp.c s21_memcpy.c s21_strlen.c \
 		s21_memmove.c s21_strcspn.c s21_strpbrk.c s21_strcmp.c s21_strncmp.c \
		s21_strcpy.c s21_strncpy.c  s21_strrchr.c s21_strspn.c \
 		s21_strtok.c s21_trim.c s21_to_lower.c s21_to_upper.c \
		s21_memchr.c s21_insert.c s21_strstr.c s21_sprintf.c s21_strerror.c
OBJ = $(SRC:%.c=%.o)
OS = $(shell uname -s)

all: s21_string.a test gcov_report

s21_string.a: $(OBJ)
	ar rcs s21_string.a $^ 

%.o: %.c s21_string.h
	$(CC) -c $<

test:
ifeq ($(OS), Darwin)
	$(CC) -coverage string_test.c $(SRC) -lcheck -lm -lpthread -o test
else
	$(CC) -coverage string_test.c $(SRC) -lcheck -lsubunit -lrt -lpthread -lm -o test
endif
	./test

gcov_report: test
	lcov -t "test" -o test.info -c -d .
	genhtml -o test_output test.info
	@cd ./test_output ; open index.html
	

clean:
	rm -rf $(OBJ)
	rm -rf test
	rm -rf *.gcda *.gcno *.info
	rm -rf ./test_output/ 
	rm -rf s21_string.a
	rm -rf test_leaks
	rm -rf CPPLINT.cfg
	rm -rf RESULT_VALGRIND.txt
	rm -rf test_leaks.dSYM

re: clean all

