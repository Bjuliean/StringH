#include "s21_string.h"

void *s21_memset(void *dest, int c, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) ((char *)dest)[i] = c;
  return dest;
}