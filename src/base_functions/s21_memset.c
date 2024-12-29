#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *dest_ptr = str;
  unsigned char unsigned_fill_char = c;
  s21_size_t index = 0;
  while (index < n) {
    dest_ptr[index] = unsigned_fill_char;
    index++;
  }
  return (void *)dest_ptr;
}