#include "s21_string.h"

void *s21_memchr(const void *arr, int c, s21_size_t n) {
  const char *res = arr;
  int isGotSymb = 0;
  for (s21_size_t i = 0; i < n && arr; i++) {
    if (res[i] == c) {
      isGotSymb = 1;
      res = (char *)arr + i;
      break;
    }
  }
  return isGotSymb ? ((void *)res) : s21_NULL;
}