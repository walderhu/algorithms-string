#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *current_byte_ptr = str;
  unsigned char unsigned_target_char = c;
  void *result = s21_NULL;

  while (n-- > 0) {
    if (unsigned_target_char == *current_byte_ptr) {
      result = (void *)current_byte_ptr;
      break;  // Выходим из цикла после нахождения символа
    }
    current_byte_ptr++;
  }

  return result;
}