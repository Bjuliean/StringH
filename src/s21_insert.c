#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *newStr = s21_NULL;
  char *temp = s21_NULL;
  if (src && str && start_index <= s21_strlen(src)) {
    newStr = calloc(s21_strlen(src) + s21_strlen(str) + 1, sizeof(char));
    temp = calloc(s21_strlen(str) + 1, sizeof(char));
    for (s21_size_t i = 0; i < s21_strlen(src); i++) {
      newStr[i] = src[i];
    }
    int tempArrCounter = 0;
    for (s21_size_t i = start_index; i < start_index + s21_strlen(newStr);
         i++) {
      temp[tempArrCounter] = newStr[i];
      tempArrCounter++;
    }
    tempArrCounter = 0;
    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
      newStr[start_index + i] = str[tempArrCounter];
      tempArrCounter++;
    }
    tempArrCounter = 0;
    for (s21_size_t i = start_index + s21_strlen(str);
         i < s21_strlen(src) + s21_strlen(str); i++) {
      newStr[i] = temp[tempArrCounter];
      tempArrCounter++;
    }
    free(temp);
  }
  if (!str) {
    newStr = calloc(s21_strlen(src) + 1, sizeof(char));
    for (s21_size_t i = 0; i < s21_strlen(src); i++) newStr[i] = src[i];
  }
  return (void *)newStr;
}