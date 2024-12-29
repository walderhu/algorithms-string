#include "../s21_string.h"

// cравнивает не более первых n байтов str1 и str2
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;

  while (n > 0 && *str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
    str1++;
    str2++;
    n--;  // проверяем до тех пор, пока не закончится количество символов n
  }

  if (n == 0) {  // все символы проверены и равны между собой
    result = 0;
  } else {
    result = *(unsigned char *)str1 -
             *(unsigned char *)str2;  // разницу между значениями символов
  }
  return result;
}