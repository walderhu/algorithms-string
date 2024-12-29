#include "../s21_string.h"

char *s21_strpbrk(const char *string1, const char *string2) {
  char *result = s21_NULL;
  s21_size_t i = 0;
  int found = 0;

  while (string1[i] != '\0' && !found) {
    for (int j = 0; string2[j] != '\0' && !found; j++) {
      if (string1[i] == string2[j]) {
        result = (char *)&string1[i];
        found = 1;  // Установка флага, указывающего на нахождение совпадения
      }
    }
    i++;
  }

  return result;
}