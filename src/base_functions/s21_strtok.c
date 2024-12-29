#include "../s21_string.h"

// Разбивает строку str на ряд токенов, разделенных delim

char *s21_strtok(char *str, const char *delim) {
  static char *olds;
  char *token;

  if (str == s21_NULL) str = olds;

  // Пропускаем ведущие разделители
  while (*str && s21_strchr(delim, *str)) str++;

  // Если *s указывает на null-байт \0, значит достигнут конец строки,
  // возвращаем NULL
  if (*str == '\0') {
    olds = str;
    return s21_NULL;
  }

  // Находим конец лексемы
  token = str;
  while (*str && !s21_strchr(delim, *str)) str++;

  // Если достигнут конец строки, то olds указывает на null-байт,
  // иначе устанавливаем null-терминатор для текущей лексемы и смещаем olds на
  // следующий символ после лексемы
  if (*str == '\0')
    olds = str;
  else {
    *str = '\0';
    olds = str + 1;
  }

  return token;
}