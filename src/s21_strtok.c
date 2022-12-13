#include "s21_string.h"

char *s21_strtok(char *str, const char *sep) {
  static char *temp = s21_NULL;
  if (str) temp = str;
  if (temp) {
    str = temp + s21_strspn(temp, sep);
    temp = str + s21_strcspn(str, sep);
  }
  return *str != '\0' ? str : s21_NULL;
}