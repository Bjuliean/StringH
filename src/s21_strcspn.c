#include "s21_string.h"

s21_size_t s21_strcspn(const char *str, const char *sym) {
  s21_size_t res = 0;
  int isGotSymb = 0;
  for (s21_size_t i = 0; str[i] != '\0'; i++) {
    for (s21_size_t z = 0; sym[z] != '\0'; z++) {
      if (str[i] != sym[z])
        isGotSymb = 1;
      else {
        isGotSymb = 0;
        break;
      }
    }
    if (isGotSymb == 0)
      break;
    else
      res++;
    isGotSymb = 0;
  }
  return res;
}