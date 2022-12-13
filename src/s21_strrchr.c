#include "s21_string.h"

char *s21_strrchr(const char *str, int ch) {
  const char *res = s21_NULL;
  for (int i = s21_strlen(str); i >= 0; i--) {
    if (str[i] == ch) {
      res = str + i;
      break;
    }
  }
  return (char *)res;
}