#include "../s21_string.h"

char *s21_strcpy(char *restrict dst, const char *restrict src) {
  if (dst == s21_NULL) {
    return s21_NULL;
  }

  int i = 0;
  while (src[i] != '\0') {
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
  return dst;
}