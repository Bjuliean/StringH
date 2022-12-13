#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *newStr = s21_NULL;
  if (src && trim_chars) {
    newStr = calloc(s21_strlen(src) + 1, sizeof(char));
    int newArrCounter = 0;
    int isCorrectSymb = 1;
    for (s21_size_t i = 0; i < s21_strlen(src); i++) {
      for (s21_size_t z = 0; z < s21_strlen(trim_chars); z++) {
        if (src[i] == trim_chars[z]) {
          isCorrectSymb = 0;
          break;
        }
      }
      if (isCorrectSymb == 1) {
        newStr[newArrCounter] = src[i];
        newArrCounter++;
      }
      isCorrectSymb = 1;
    }
  }
  if (!trim_chars) {
    newStr = calloc(s21_strlen(src) + 1, sizeof(char));
    for (s21_size_t i = 0; i < s21_strlen(src); i++) {
      newStr[i] = src[i];
    }
  }
  return (void *)newStr;
}