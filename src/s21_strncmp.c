#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  for (s21_size_t i = 0; i < s21_strlen(str1) && i < n; i++) {
    if (str1[i] != str2[i]) {
      res = str1[i] - str2[i];
      break;
    }
  }
  return res;
}