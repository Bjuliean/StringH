#include "s21_string.h"

char *s21_strncat(char *dest, const char *app, s21_size_t n) {
  s21_size_t z = s21_strlen(dest);
  for (s21_size_t i = 0; i < s21_strlen(app) && i < n; i++) {
    dest[z + i] = app[i];
  }
  return dest;
}