#include "s21_string.h"

char *s21_strstr(const char *str1, const char *str2) {
  const char *res = s21_NULL;
  int isGotStr = 0;
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    if (str1[i] == str2[0]) {
      for (s21_size_t z = 0; z < s21_strlen(str2); z++) {
        if (str1[i + z] == str2[z])
          isGotStr = 1;
        else
          isGotStr = 0;
      }
      if (isGotStr == 1) {
        res = str1 + i;
        break;
      }
    }
  }
  if (str1[0] == '\0' || str2[0] == '\0') res = str1;
  return (char *)res;
}