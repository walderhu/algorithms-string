#include "../s21_string.h"

int is_trim_char(char c, const char *trim_chars) {
  int result = 0;
  while (*trim_chars) {
    if (c == *trim_chars) {
      result = 1;
    }
    trim_chars++;
  }
  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_str = s21_NULL;

  if (src != s21_NULL && trim_chars != s21_NULL) {
    const char *start = src;
    const char *end = src + s21_strlen(src) - 1;

    while (is_trim_char(*start, trim_chars) && start <= end) start++;
    while (is_trim_char(*end, trim_chars) && end >= start) end--;

    int new_len = end - start + 1;
    new_str = calloc(new_len + 1, 1);
    if (new_str != s21_NULL) {
      s21_strncpy(new_str, start, new_len);
      new_str[new_len] = '\0';
    }
  }

  return (void *)new_str;
}
