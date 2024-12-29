#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  int result_founded = 0;
  int n = s21_strlen(needle);
  char *result = s21_NULL;

  while (*haystack != '\0') {
    if ((s21_memcmp(haystack, needle, n) == 0) && (result_founded == 0)) {
      result = (char *)(haystack);
      result_founded = 1;
    }
    haystack++;
  }
  return result;
}