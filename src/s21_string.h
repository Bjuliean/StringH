#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define s21_NULL (void *)0
typedef unsigned long int s21_size_t;

struct specifics_list {
  int flag_minus;
  int flag_plus;
  int flag_space;
  int width;
  int accur;
  int is_acc_zero;
  int length_h;
  int length_l;
  int is_float;
};

// string.h
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strcspn(const char *str, const char *sym);
s21_size_t s21_strspn(const char *str, const char *sym);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
int s21_strcmp(const char *str1, const char *str2);
int s21_memcmp(const void *arr1, const void *arr2, s21_size_t n);
char *s21_strerror(int errcode);
char *s21_strtok(char *str, const char *sep);
char *s21_strncat(char *dest, const char *app, s21_size_t n);
char *s21_strcat(char *dest, const char *app);
char *s21_strstr(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int ch);
char *s21_strpbrk(const char *str, const char *sym);
char *s21_strchr(const char *str, int ch);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
void *s21_memset(void *dest, int c, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memchr(const void *arr, int c, s21_size_t n);

// special functions
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// sprintf
int s21_sprintf(char *str, const char *format, ...);
int is_len(char leter, struct specifics_list *specifics);
int flagcheck(char format, struct specifics_list *specifics);
int Is_digit(char leter);
int iswidth(const char *format, struct specifics_list *specifics, int form);
void check_type(va_list va, char leter_to_check, char *str,
                struct specifics_list *specifics);
void out_int(char *str, struct specifics_list *specifics, long long int number);
void out_str(va_list va, char *str, struct specifics_list *specifics);
void out_char(va_list, char *str, struct specifics_list *specifics);
void out_float(char *str, struct specifics_list *specifics, long double number);
const char *parser(va_list va, const char *format, char *str);
void add_widt(char *str, struct specifics_list *specifics, int iter, int znak);
void add_zero(char *num_to_str, struct specifics_list *specifics, int *iter,
              int str_rev);
void add_accur(char *str, struct specifics_list *specifics, int iter);
void fil_in_str(char *str, struct specifics_list *specifics, char *num_to_str);
void add_flag(char *num_to_str, int *iter, struct specifics_list *specifics);
void parser_to_int(struct specifics_list *specifics, va_list va, char *str);
void parser_to_unsigned(struct specifics_list *specifics, va_list va,
                        char *str);
void parser_to_float(struct specifics_list *specifics, va_list va, char *str);

#endif  // SRC_S21_STRING_H_
