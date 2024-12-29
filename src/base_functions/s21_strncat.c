#include "../s21_string.h"

//Добавляет строку, на которую указывает src, в конец строки, на которую
//указывает dest, длиной до n символов
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *sdest = dest;
  const char *ssrc = src;
  s21_size_t dest_len = s21_strlen(dest);
  s21_size_t i = 0;
  while (i < n && ssrc[i] != '\0') {  //пока не встретиться конец строки и пока
                                      //не будет доб n символов
    sdest[dest_len + i] = ssrc[i];
    i++;
  }
  sdest[dest_len + i] = '\0';

  return sdest;
}
