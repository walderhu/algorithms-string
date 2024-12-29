#include "../s21_string.h"

int s21_sprintf(char *final_buffer, const char *format, ...) {
  char stack_final_buffer[8000] = {0};

  va_list arg_list;
  va_start(arg_list, format);
  s21_copy_to_buff(stack_final_buffer, format, arg_list);
  va_end(arg_list);
  s21_strcpy(final_buffer, stack_final_buffer);
  return s21_strlen(final_buffer);
}
