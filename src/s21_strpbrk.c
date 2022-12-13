#include "s21_string.h"

char *s21_strpbrk(const char *str, const char *sym) {
  const char *res = s21_NULL;
  int isGotSymb = 0;
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    for (s21_size_t z = 0; z < s21_strlen(sym); z++) {
      if (str[i] == sym[z]) {
        res = str + i;
        isGotSymb = 1;
        break;
      }
    }
    if (isGotSymb == 1) break;
  }
  return (char *)res;
}