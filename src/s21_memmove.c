#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *temp = (char *)malloc(sizeof(char) * n);
  if (temp) {
    s21_memcpy(temp, ((char *)src), n);
    s21_memcpy(((char *)dest), temp, n);
    free(temp);
  }
  return dest;
}