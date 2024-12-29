#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  char *newstr = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
  if (newstr == s21_NULL) return s21_NULL;
  s21_strncpy(newstr, str, sizeof(char));
  s21_size_t i = 0;
  for (i = 0; i < s21_strlen(str); i++) {
    if (str[i] >= 97 && str[i] <= 122) {
      newstr[i] = str[i] - 32;
    } else
      newstr[i] = str[i];
  }
  return (void *)newstr;
}