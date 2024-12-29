#include "../s21_string.h"

/* Возвращает новую строку, в которой указанная строка (str) вставлена
в указанную позицию (start_index) в данной строке (src).
 В случае какой-либо ошибки следует вернуть значение NULL */
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  void *result = s21_NULL;
  if (src != s21_NULL && str != s21_NULL) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);

    if (start_index <= src_len) {
      char *new_str = malloc((src_len + str_len + 1) * sizeof(char));
      if (new_str != s21_NULL) {
        s21_strncpy(new_str, src, start_index);
        s21_strncpy(new_str + start_index, str, str_len);
        s21_strcpy(new_str + start_index + str_len, src + start_index);
        result = new_str;
      }
    }
  }
  return result;
}