#include "../s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  va_list arg;
  int count = 0;
  char str_replica[s21_strlen(str) + 1];
  char format_replica[s21_strlen(format) + 1];
  s21_strcpy(str_replica, str);
  s21_strcpy(format_replica, format);
  va_start(arg, format);
  for (s21_size_t i = 0; i < s21_strlen(format); i++) {
    if (parsing(str_replica, format_replica) == INCORRECT) break;
    if (treatment(str, str_replica, format, format_replica, arg) == INCORRECT)
      break;
    count++;
  }
  va_end(arg);
  return count;
}

int treatment(const char *str, char *str_replica, const char *format,
              char *format_replica, va_list arg) {
  int status = CORRECT;
  char specifier = format_replica[0];
  if (specifier == 'n') {
    int *buffer = va_arg(arg, int *);
    specifier_n(str, str_replica, format, buffer);
  } else if (specifier == 'c' || specifier == 's') {
    treatment_symbols(str_replica, specifier, arg, STOCK);
  } else if (specifier == 'i' || specifier == 'd' || specifier == 'o' ||
             specifier == 'u' || specifier == 'x' || specifier == 'X') {
    treatment_simple_digit(str_replica, specifier, arg, STOCK);
  } else if (specifier == 'f' || specifier == 'g' || specifier == 'G' ||
             specifier == 'e' || specifier == 'E') {
    treatment_floating_digit(str_replica, specifier, arg, STOCK);
  } else if (specifier == 'h') {
    treatment_short_digit(str_replica, format_replica[1], arg, STOCK);
  } else if (specifier == 'l') {
    treatment_long_simple_digit(str_replica, format_replica[1], arg, STOCK);
  } else if (specifier == 'L') {
    treatment_long_float_digit(str_replica, format_replica[1], arg, STOCK);
  } else if (specifier == 'p' || specifier == '%' || specifier == '*' ||
             (specifier >= '0' && specifier <= '9')) {
    treatment_other_specifiers(str_replica, format, format_replica, arg, STOCK);
  } else if (specifier != ' ' && specifier != '\0') {
    // fprintf(stderr, "'%c' - non-existent specifier. Abort.\n", specifier);
    status = INCORRECT;
  }
  remove_beginning(format_replica, 1);
  return status;
}

void treatment_symbols(char *str, char specifier, va_list arg, int width) {
  char *buffer = va_arg(arg, char *);
  if (specifier == 'c') specifier_c(str, buffer);
  if (specifier == 's') specifier_s(str, buffer, width);
}

void treatment_simple_digit(char *str, char specifier, va_list arg, int width) {
  if (specifier == 'd') {
    int *buffer = va_arg(arg, int *);
    specifier_d(str, (long *)buffer, width);
  } else if (specifier == 'i') {
    long *buffer = va_arg(arg, long *);
    specifier_i(str, (long *)buffer, width);
  } else {
    unsigned long *buffer = va_arg(arg, unsigned long *);
    if (specifier == 'o') specifier_o(str, (unsigned long *)buffer, width);
    if (specifier == 'u') specifier_u(str, (unsigned long *)buffer, width);
    if (specifier == 'x') specifier_x(str, (unsigned long *)buffer, width);
    if (specifier == 'X') specifier_X(str, (unsigned long *)buffer, width);
  }
}

void treatment_floating_digit(char *str, char specifier, va_list arg,
                              int width) {
  long double temporarily;
  float *buffer = va_arg(arg, float *);
  if (specifier == 'f') {
    if (specifier_f(str, &temporarily, width)) *buffer = (float)temporarily;
  } else if (specifier == 'e') {
    if (specifier_e(str, &temporarily, width)) *buffer = (float)temporarily;
  } else if (specifier == 'E') {
    if (specifier_E(str, &temporarily, width)) *buffer = (float)temporarily;
  } else if (specifier == 'g') {
    if (specifier_g(str, &temporarily, width)) *buffer = (float)temporarily;
  } else if (specifier == 'G') {
    if (specifier_G(str, &temporarily, width)) *buffer = (float)temporarily;
  }
}

void treatment_short_digit(char *str, char specifier, va_list arg, int width) {
  if ((specifier == 'd') || (specifier == 'i')) {
    short *buffer = va_arg(arg, short *);
    if (specifier == 'd') specifier_d(str, (long *)buffer, width);
    if (specifier == 'i') specifier_i(str, (long *)buffer, width);
  } else {
    unsigned short *buffer = va_arg(arg, unsigned short *);
    if (specifier == 'u') specifier_u(str, (unsigned long *)buffer, width);
    if (specifier == 'o') specifier_o(str, (unsigned long *)buffer, width);
    if (specifier == 'x') specifier_x(str, (unsigned long *)buffer, width);
    if (specifier == 'X') specifier_X(str, (unsigned long *)buffer, width);
  }
}

void treatment_long_simple_digit(char *str, char specifier, va_list arg,
                                 int width) {
  if ((specifier == 'd') || (specifier == 'i')) {
    long *buffer = va_arg(arg, long *);
    if (specifier == 'd') specifier_d(str, (long *)buffer, width);
    if (specifier == 'i') specifier_i(str, (long *)buffer, width);
  } else {
    unsigned long *buffer = va_arg(arg, unsigned long *);
    if (specifier == 'u') specifier_u(str, (unsigned long *)buffer, width);
    if (specifier == 'o') specifier_o(str, (unsigned long *)buffer, width);
    if (specifier == 'x') specifier_x(str, (unsigned long *)buffer, width);
    if (specifier == 'X') specifier_X(str, (unsigned long *)buffer, width);
  }
}

void treatment_long_float_digit(char *str, char specifier, va_list arg,
                                int width) {
  long double *buffer = va_arg(arg, long double *);
  if (specifier == 'f') specifier_f(str, (long double *)buffer, width);
  if (specifier == 'e') specifier_e(str, (long double *)buffer, width);
  if (specifier == 'E') specifier_E(str, (long double *)buffer, width);
  if (specifier == 'g') specifier_g(str, (long double *)buffer, width);
  if (specifier == 'G') specifier_G(str, (long double *)buffer, width);
}

void treatment_other_specifiers(char *str, const char *format,
                                char *format_replica, va_list arg, int width) {
  char specifier = format_replica[0];
  if (specifier == 'p') {
    void *buffer = va_arg(arg, void *);
    specifier_p(str, (void *)buffer, width);
  } else if (specifier == '*') {
    specifier_skeep(str, format_replica);
  } else if (specifier >= '0' && specifier <= '9') {
    specifier_width(str, format, format_replica, arg);
  } else if (specifier == '%') {
    specifier_percent(str, format, format_replica, arg);
  }
}

s21_size_t specifier_d(char *str, long *buffer, int width) {
  long temporarily, result = 0;
  s21_size_t total_length = 0, space_length = 0, number_length = 0;
  int sign = 1;
  while (s21_isspace(str[space_length])) space_length++;
  if (str[space_length] == '-') {
    sign = -1;
    space_length++;
  }
  total_length = space_length;
  while (str[total_length] >= '0' && str[total_length] <= '9') total_length++;

  number_length =
      determine_length(total_length, space_length, number_length, width);

  for (s21_size_t i = space_length, j = number_length - 1;
       i < space_length + number_length; i++, j--) {
    if (str[i] >= '0' && str[i] <= '9') {
      temporarily = (long)(str[i] - '0');
      result += temporarily * pow(10, j);
    }
  }
  if (number_length > 0) *buffer = result * sign;
  remove_beginning(str, total_length);
  return number_length;
}

void specifier_i(char *str, long *buffer, int width) {
  if (*str == '-') {
    remove_beginning(str, 1);
    specifier_u(str, (unsigned long int *)buffer, width);
    *buffer *= -1;
  } else if (str[0] == '0') {
    if (str[1] == 'x') {
      int spec_x = 0, spec_X = 0;
      for (s21_size_t i = 0; i < s21_strlen(str) && !spec_x && !spec_X; i++) {
        if (str[i] >= 'a' && str[i] <= 'f') spec_x = 1;
        if (str[i] >= 'A' && str[i] <= 'F') spec_X = 1;
      }
      if (spec_x) specifier_x(str, (unsigned long int *)buffer, width);
      if (spec_X) specifier_X(str, (unsigned long int *)buffer, width);
    } else {
      specifier_o(str, (unsigned long int *)buffer, width);
    }
  } else {
    specifier_u(str, (unsigned long int *)buffer, width);
  }
}

void specifier_o(char *str, unsigned long *buffer, int width) {
  unsigned long result = 0, temporarily = 0;
  s21_size_t total_length = 0, space_length = 0, number_length = 0;
  while (s21_isspace(str[space_length])) space_length++;
  total_length = space_length;
  while (str[total_length] >= '0' && str[total_length] <= '7') total_length++;

  number_length =
      determine_length(total_length, space_length, number_length, width);

  for (s21_size_t i = space_length, j = number_length - 1;
       i < space_length + number_length; i++, j--) {
    if (str[i] >= '0' && str[i] <= '7') temporarily = (int)str[i] - '0';
    result += temporarily * pow(8, j);
  }
  if (width != 0) *buffer = result;
  remove_beginning(str, total_length);
}

void specifier_u(char *str, unsigned long *buffer, int width) {
  s21_size_t total_length = 0, space_length = 0, number_length = 0;
  unsigned long result = 0, temporarily = 0;
  int sign = 1;
  while (s21_isspace(str[space_length])) space_length++;
  if (str[space_length] == '-') {
    sign *= -1;
    space_length++;
  }
  total_length = space_length;
  while (((str[total_length] >= '0' && str[total_length] <= '9')))
    total_length++;

  number_length =
      determine_length(total_length, space_length, number_length, width);

  for (s21_size_t i = space_length, j = number_length - 1;
       i < space_length + number_length; i++, j--) {
    if (str[i] >= '0' && str[i] <= '9') temporarily = (int)str[i] - '0';
    result += temporarily * pow(10, j);
  }
  if (number_length > 0) *buffer = result * sign;
  remove_beginning(str, total_length);
}

void specifier_x(char *str, unsigned long *buffer, int width) {
  s21_size_t total_length = 0, space_length = 0, number_length = 0;
  unsigned long result = 0, temporarily = 0;
  while (s21_isspace(str[space_length])) space_length++;
  total_length = space_length;
  if (s21_strstr(str, "0x") || s21_strstr(str, "0X")) total_length += 2;
  while (((str[total_length] >= '0' && str[total_length] <= '9') ||
          (str[total_length] >= 'A' && str[total_length] <= 'F') ||
          (str[total_length] >= 'a' && str[total_length] <= 'f')) &&
         str[total_length] != '\0') {
    total_length++;
  }
  number_length =
      determine_length(total_length, space_length, number_length, width);
  for (s21_size_t i = space_length, j = number_length - 1;
       i < space_length + number_length; i++, j--) {
    if (str[i] >= '0' && str[i] <= '9') temporarily = (int)str[i] - '0';
    if (str[i] >= 'A' && str[i] <= 'F') temporarily = (int)str[i] - 'A' + 10;
    if (str[i] >= 'a' && str[i] <= 'f') temporarily = (int)str[i] - 'a' + 10;
    result += temporarily * pow(16, j);
  }
  if (width != 0) *buffer = result;
  remove_beginning(str, total_length);
}

void specifier_X(char *str, unsigned long *buffer, int width) {
  s21_size_t total_length = 0, space_length = 0, number_length = 0;
  unsigned long result = 0, temporarily = 0;
  while (s21_isspace(str[space_length])) space_length++;
  total_length = space_length;
  if (s21_strstr(str, "0x") || s21_strstr(str, "0X")) total_length += 2;
  while (((str[total_length] >= '0' && str[total_length] <= '9') ||
          (str[total_length] >= 'A' && str[total_length] <= 'F') ||
          (str[total_length] >= 'a' && str[total_length] <= 'f')) &&
         str[total_length] != '\0') {
    total_length++;
  }
  number_length =
      determine_length(total_length, space_length, number_length, width);
  for (s21_size_t i = space_length, j = number_length - 1;
       i < space_length + number_length; i++, j--) {
    if (str[i] >= '0' && str[i] <= '9') temporarily = (int)str[i] - '0';
    if (str[i] >= 'A' && str[i] <= 'F') temporarily = (int)str[i] - 'A' + 10;
    if (str[i] >= 'a' && str[i] <= 'f') temporarily = (int)str[i] - 'a' + 10;
    result += temporarily * pow(16, j);
  }
  if (width != 0) *buffer = result;
  remove_beginning(str, total_length);
}

s21_size_t specifier_f(char *str, long double *buffer, int width) {
  long double temporarily = 0, result = 0;
  s21_size_t total_length = 0, space_length = 0, number_length = 0,
             integer_leght = 0;
  int sign = 1;
  float degree;
  while (s21_isspace(str[space_length])) space_length++;
  if (s21_strstr(str, "0x") || s21_strstr(str, "0X")) space_length += 2;
  if (str[space_length] == '-') sign = -1;
  total_length = space_length;
  while ((str[total_length] >= '0' && str[total_length] <= '9') ||
         str[total_length] == '.' || str[total_length] == '-')
    total_length++;
  while ((str[integer_leght + space_length] >= '0' &&
          str[integer_leght + space_length] <= '9') ||
         str[integer_leght + space_length] == '-')
    integer_leght++;

  number_length =
      determine_length(total_length, space_length, number_length, width);

  if (width != STOCK && (s21_size_t)width < integer_leght)
    integer_leght = width;
  degree = pow(10, integer_leght - 1);
  for (s21_size_t i = space_length; i < space_length + number_length; i++) {
    if (str[i] == '.') continue;
    if (str[i] >= '0' && str[i] <= '9') temporarily = (int)str[i] - '0';
    result += temporarily * degree;
    degree /= 10;
  }
  if (number_length > 0) *buffer = sign * result;
  remove_beginning(str, total_length);
  return number_length;
}

s21_size_t specifier_e(char *str, long double *buffer, int width) {
  s21_size_t length_degree = 0, length_number = 0;
  long double temporarily = 0, result = 0;
  int sign = 1, degree = 0;
  length_number = specifier_f(str, &result, width);
  while ((str[length_degree] >= '0' && str[length_degree] <= '9') ||
         str[length_degree] == '+' || str[length_degree] == '-' ||
         str[length_degree] == 'e' || str[length_degree] == 'E') {
    length_degree++;
  }

  if (str[1] == '-') sign = -1;  // знак степени
  for (s21_size_t i = 1, j = length_degree - 2; i < length_degree; i++, j--) {
    if (str[i] >= '0' && str[i] <= '9') temporarily = (int)str[i] - '0';
    degree += temporarily * pow(10, j);
  }
  if (length_number + length_degree <= (s21_size_t)width)
    result *= pow(10, sign * degree);
  if (length_number && width != 0) *buffer = result;
  remove_beginning(str, length_degree);
  return length_number + length_degree;
}

s21_size_t specifier_g(char *str, long double *buffer, int width) {
  s21_size_t spec_e = 0, spec_E = 0, number_exists;
  long double result;
  for (int i = 0;
       ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' ||
        (str[i] == '+' || str[i] == '-') || (str[i] == 'e' || str[i] == 'E'));
       i++) {
    if (str[i] == 'e') spec_e = 1;
    if (str[i] == 'E') spec_E = 1;
  }
  if (spec_e)
    number_exists = specifier_e(str, &result, width);
  else if (spec_E)
    number_exists = specifier_E(str, &result, width);
  else
    number_exists = specifier_f(str, &result, width);
  if (number_exists && width != 0) *buffer = result;
  return number_exists;
}

s21_size_t specifier_E(char *str, long double *buffer, int width) {
  return specifier_e(str, buffer, width);
}
s21_size_t specifier_G(char *str, long double *buffer, int width) {
  return specifier_g(str, buffer, width);
}

void remove_beginning(char *str, s21_size_t quantity) {
  if (str == s21_NULL || quantity == 0) return;
  if (quantity >= s21_strlen(str)) {
    str[0] = '\0';
    return;
  }
  s21_size_t len = s21_strlen(str);
  char *copy = malloc(len - quantity + 1);
  if (copy == s21_NULL) return;
  s21_strncpy(copy, str + quantity, len - quantity);
  copy[len - quantity] = '\0';
  s21_strcpy(str, copy);
  free(copy);
}

s21_size_t parsing(char *str, char *format) {
  if (str == s21_NULL || format == s21_NULL) return INCORRECT;
  s21_size_t length = s21_strlen(str) < s21_strlen(format) ? s21_strlen(str)
                                                           : s21_strlen(format);
  s21_size_t i = 0, find = 0;
  while (str[i] == format[i] && format[i] != '%' && i < length) i++;
  while (s21_isspace(format[i])) i++;
  if (format[i] == '%') find++;
  remove_beginning(str, i);
  remove_beginning(format, i + find);
  return (find) ? CORRECT : INCORRECT;
}

void specifier_c(char *str, char *buffer) {
  s21_strncpy(buffer, str, 1);
  remove_beginning(str, 1);
}

void specifier_s(char *str, char *buffer, int width) {
  s21_size_t total_length = 0, word_length = 0;
  char temporarily[s21_strlen(str)];

  while (s21_isspace(str[total_length]) && str[total_length] != '\0') {
    total_length++;
  }

  while (s21_isspace(str[total_length]) == 0 && str[total_length] != '\0') {
    temporarily[word_length] = str[total_length];
    word_length++;
    total_length++;
  }
  temporarily[word_length] = '\0';

  (width == STOCK) ? s21_strcpy(buffer, temporarily)
                   : s21_strncpy(buffer, temporarily, width);

  remove_beginning(str, total_length);
}

void specifier_n(const char *str, char *str_replica, const char *format,
                 int *buffer) {
  int space_in_str = 0, result = s21_strlen(str) - s21_strlen(str_replica);
  while (str_replica[space_in_str] == ' ') space_in_str++;
  if (s21_strstr(format, " %n")) result += space_in_str;
  *buffer = result;
}

void specifier_p(char *str, void *buffer, int width) {
  s21_size_t total_length = 0, space_length = 0, number_length = 0;
  unsigned long result = 0, temporarily = 0;
  while (s21_isspace(str[space_length])) space_length++;
  if (str[space_length] == '0' &&
      (str[space_length + 1] == 'x' || str[space_length + 1] == 'X'))
    space_length += 2;

  total_length = space_length;
  while (((str[total_length] >= '0' && str[total_length] <= '9') ||
          (str[total_length] >= 'A' && str[total_length] <= 'F') ||
          (str[total_length] >= 'a' && str[total_length] <= 'f')) &&
         str[total_length] != '\0') {
    total_length++;
  }

  number_length =
      determine_length(total_length, space_length, number_length, width);

  for (s21_size_t i = space_length, j = number_length - 1;
       i < space_length + number_length; i++, j--) {
    if (str[i] >= '0' && str[i] <= '9') temporarily = (int)str[i] - '0';
    if (str[i] >= 'A' && str[i] <= 'F') temporarily = (int)str[i] - 'A' + 10;
    if (str[i] >= 'a' && str[i] <= 'f') temporarily = (int)str[i] - 'a' + 10;
    result += temporarily * pow(16, j);
  }
  if (number_length > 0) *(unsigned long *)buffer = result;
  remove_beginning(str, total_length);
}

int s21_isspace(char symbol) {
  return (symbol == '\t' || symbol == '\r' || symbol == '\v' ||
          symbol == '\f' || symbol == '\n' || symbol == ' ')
             ? 1
             : 0;
}

void specifier_skeep(char *str, char *format_replica) {
  char specifier = format_replica[1];
  int width = 0;
  remove_beginning(format_replica, 1);
  if (specifier == 'c' || specifier == 's') {
    char temporarily[s21_strlen(str)];
    if (specifier == 'c') specifier_c(str, (char *)temporarily);
    if (specifier == 's') specifier_s(str, (char *)temporarily, width);
  } else if (specifier == 'i' || specifier == 'd') {
    long temporarily[s21_strlen(str)];
    if (specifier == 'd') specifier_d(str, (long *)temporarily, width);
    if (specifier == 'i') specifier_i(str, (long *)temporarily, width);
  } else if (specifier == 'o' || specifier == 'u' || specifier == 'x' ||
             specifier == 'X') {
    unsigned long temporarily[s21_strlen(str)];
    if (specifier == 'o') specifier_o(str, (unsigned long *)temporarily, width);
    if (specifier == 'u') specifier_u(str, (unsigned long *)temporarily, width);
    if (specifier == 'x') specifier_x(str, (unsigned long *)temporarily, width);
    if (specifier == 'X') specifier_X(str, (unsigned long *)temporarily, width);
  } else if (specifier == 'f' || specifier == 'g' || specifier == 'G' ||
             specifier == 'e' || specifier == 'E') {
    long double temporarily[s21_strlen(str)];
    if (specifier == 'f') specifier_f(str, (long double *)temporarily, width);
    if (specifier == 'e') specifier_e(str, (long double *)temporarily, width);
    if (specifier == 'E') specifier_E(str, (long double *)temporarily, width);
    if (specifier == 'g') specifier_g(str, (long double *)temporarily, width);
    if (specifier == 'G') specifier_G(str, (long double *)temporarily, width);
  } else if (specifier == 'p') {
    void *temporarily;
    specifier_p(str, &temporarily, width);
  }
}
void specifier_width(char *str, const char *format, char *format_replica,
                     va_list arg) {
  int width = -1;
  long temporarily;
  char specifier;
  specifier_d(format_replica, &temporarily, STOCK);
  width = (int)temporarily;
  if (width == 0) width = STOCK;
  specifier_c(format_replica, &specifier);

  if (specifier == 'c' || specifier == 's') {
    treatment_symbols(str, specifier, arg, width);
  } else if (specifier == 'i' || specifier == 'd' || specifier == 'o' ||
             specifier == 'u' || specifier == 'x' || specifier == 'X') {
    treatment_simple_digit(str, specifier, arg, width);
  } else if (specifier == 'f' || specifier == 'g' || specifier == 'G' ||
             specifier == 'e' || specifier == 'E') {
    treatment_floating_digit(str, specifier, arg, width);
  } else if (specifier == 'n' || specifier == 'p')
    treatment_other_specifiers(str, format, format_replica, arg, width);
}

s21_size_t determine_length(s21_size_t total_length, s21_size_t space_length,
                            s21_size_t number_length, int width) {
  if (width == STOCK || ((s21_size_t)width > total_length - space_length))
    number_length = total_length - space_length;
  else if (width)
    number_length = width * (total_length - space_length > 0) + space_length;
  return number_length;
}

void specifier_percent(char *str, const char *format, char *format_replica,
                       va_list arg) {
  remove_beginning(format_replica, 1);
  remove_beginning(str, 1);
  if (parsing(str, format_replica) == INCORRECT) return;
  char specifier = format_replica[0];
  if (specifier == 'c' || specifier == 's') {
    treatment_symbols(str, specifier, arg, STOCK);
  } else if (specifier == 'i' || specifier == 'd' || specifier == 'o' ||
             specifier == 'u' || specifier == 'x' || specifier == 'X') {
    treatment_simple_digit(str, specifier, arg, STOCK);
  } else if (specifier == 'f' || specifier == 'g' || specifier == 'G' ||
             specifier == 'e' || specifier == 'E') {
    treatment_floating_digit(str, specifier, arg, STOCK);
  } else if (specifier == 'n' || specifier == 'p')
    treatment_other_specifiers(str, format, format_replica, arg, STOCK);
}