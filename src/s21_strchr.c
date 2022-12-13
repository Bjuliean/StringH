#include "s21_string.h"

char *s21_strchr(const char *str, int ch) {
  const char *res = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    if (str[i] == ch) {
      res = str + i;
      break;
    }
  }
  return (char *)res;
}