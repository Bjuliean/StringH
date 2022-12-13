#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  int res = 0;
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    if (str1[i] != str2[i]) {
      res = str1[i] - str2[i];
      break;
    }
  }
  return res;
}