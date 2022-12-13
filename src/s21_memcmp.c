#include "s21_string.h"

int s21_memcmp(const void *arr1, const void *arr2, s21_size_t n) {
  int res = 0;
  for (s21_size_t i = 0;
       i < n && ((char *)arr1)[i] != '\0' && ((char *)arr2)[i] != '\0'; i++) {
    if (((char *)arr1)[i] != ((char *)arr2)[i]) {
      res = ((char *)arr1)[i] - ((char *)arr2)[i];
      break;
    }
  }
  return res;
}