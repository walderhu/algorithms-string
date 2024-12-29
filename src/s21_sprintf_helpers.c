#include "s21_string.h"

void s21_copy_to_buff(char *final_buffer, const char *format,
                      va_list arg_list) {
  int i = 0;
  while (*format != '\0') {
    if (*format == '%') {
      format += parse_pattern(final_buffer, format, arg_list, &i);
    } else {
      *(final_buffer + i) = *format;
      i++;
    }
    format++;
  }
}

int parse_pattern(char *final_buffer, const char *format, va_list arg_list,
                  int *i) {  // return format shift
  int format_shift = 0, pattern_char_counter = 1;
  int stage = 0;  // 0 - flags, 1 - width, 2 - precision, specificator
  char next_ch;
  char generated_string[8000] = {0};

  pattern current_pattern = {0};
  current_pattern.precision = -1;

  while (!is_specifier(next_ch =
                           *(format + pattern_char_counter))) {  // == 0 - FALSE
    fill_pattern(&current_pattern, next_ch, &stage, arg_list);
    pattern_char_counter++;
    format_shift++;
  }
  if (is_specifier(next_ch)) {  // == 1 - TRUE
    current_pattern.specifier = next_ch;
  }

  generate_string_from_pattern(current_pattern, arg_list, generated_string);
  s21_strcat(final_buffer, generated_string);
  *i = s21_strlen(final_buffer);
  format_shift++;
  return format_shift;
}

void fill_pattern(pattern *current_pattern, char ch, int *stage,
                  va_list arg_list) {
  if (*stage == 0 && ch == '+') {
    (*current_pattern).flag_plus = 1;
  } else if (*stage == 0 && ch == '-') {
    (*current_pattern).flag_minus = 1;
  } else if (*stage == 0 && ch == ' ') {
    (*current_pattern).flag_space = 1;
  } else if (*stage == 0 && ch == '#') {
    (*current_pattern).flag_grid = 1;
  } else if (*stage == 0 && ch == '0') {
    (*current_pattern).flag_zero = 1;
  } else if ((*stage == 1 || *stage == 2) && ch == 0) {
    increase_width_or_precision(current_pattern, 0, *stage);
  } else if (((ch > 47 && ch < 58) || ch == '*') && *stage < 2) {
    *stage = 1;
    if (ch == '*') {
      (*current_pattern).width = va_arg(arg_list, int);
    } else if (ch > 47 && ch < 58) {
      increase_width_or_precision(current_pattern, ch - 48, *stage);
    }
  } else if (ch == '.') {
    *stage = 2;
    (*current_pattern).precision = 0;
  } else if (ch == 'l' || ch == 'L' || ch == 'h') {
    (*current_pattern).length = ch;
  } else if (((ch > 47 && ch < 58) || ch == '*') && *stage > 1) {
    if (ch == '*') {
      (*current_pattern).precision = va_arg(arg_list, int);
    } else if (ch > 47 && ch < 58) {
      increase_width_or_precision(current_pattern, ch - 48, *stage);
    }
  }
}

void increase_width_or_precision(pattern *current_pattern, int digit,
                                 int stage) {
  if (stage == 1) {
    (*current_pattern).width *= 10;
    (*current_pattern).width += digit;
  } else if (stage == 2) {
    (*current_pattern).precision *= 10;
    (*current_pattern).precision += digit;
  }
}

void generate_string_from_pattern(pattern current_pattern, va_list arg_list,
                                  char arg_str[8000]) {
  char generated_string[8000] = {'\0'};

  if (current_pattern.specifier == 's') {
    generate_s_flag(current_pattern, arg_list, generated_string);
  } else if (current_pattern.specifier == 'd') {
    generate_d_flag(current_pattern, arg_list, generated_string);
  } else if (current_pattern.specifier == 'f') {
    generate_f_flag(current_pattern, arg_list, generated_string);
  } else if (current_pattern.specifier == 'u') {
    generate_u_flag(current_pattern, arg_list, generated_string);
  } else if (current_pattern.specifier == '%') {
    generated_string[0] = '%';
    generated_string[1] = '\0';
  } else if (current_pattern.specifier == 'c') {
    generate_c_flag(current_pattern, arg_list, generated_string);
  } else if (current_pattern.specifier == 'e') {
    generate_e_flag(current_pattern, arg_list, generated_string, "e\0");
  } else if (current_pattern.specifier == 'E') {
    generate_e_flag(current_pattern, arg_list, generated_string, "E\0");
  } else if (current_pattern.specifier == 'g') {
    generate_g_flag(current_pattern, arg_list, generated_string, 'g');
  } else if (current_pattern.specifier == 'G') {
    generate_g_flag(current_pattern, arg_list, generated_string, 'G');
  } else if (current_pattern.specifier == 'x') {
    generate_x_flag(current_pattern, arg_list, generated_string, 'x');
  } else if (current_pattern.specifier == 'X') {
    generate_x_flag(current_pattern, arg_list, generated_string, 'X');
  } else if (current_pattern.specifier == 'o') {
    generate_o_flag(current_pattern, arg_list, generated_string);
  } else if (current_pattern.specifier == 'p') {
    generate_p_flag(current_pattern, arg_list, generated_string);
  }
  s21_strcpy(arg_str, generated_string);
}

void generate_p_flag(pattern current_pattern, va_list arg_list,
                     char str[8000]) {
  unsigned long long int *number = va_arg(arg_list, unsigned long long int *);
  char char_for_fill_empty_places = current_pattern.flag_zero == 1 ? '0' : ' ';
  from_ptr_to_hex(number, str);
  current_pattern.flag_grid = 1;
  if ((s21_size_t)current_pattern.precision < s21_strlen(str))
    current_pattern.precision = -1;
  if (current_pattern.flag_grid == 1 && current_pattern.precision == -1 &&
      current_pattern.flag_zero == 0) {
    add_symbol_before_string(str, 'x');
    add_symbol_before_string(str, '0');
  }

  if (current_pattern.precision > (int)s21_strlen(str)) {
    alignment_str(str, current_pattern.precision, 0, '0');
    if (current_pattern.flag_grid == 1) {
      add_symbol_before_string(str, 'x');
      add_symbol_before_string(str, '0');
    }
  }

  if ((s21_size_t)current_pattern.width > s21_strlen(str)) {
    if (current_pattern.flag_minus != 1 || current_pattern.flag_zero != 1) {
      alignment_str(str, current_pattern.width, current_pattern.flag_minus,
                    char_for_fill_empty_places);
      if (current_pattern.flag_grid == 1 && current_pattern.flag_zero == 1) {
        str[0] = '0';
        str[1] = 'x';
      }
    }
  }

  if (current_pattern.precision == 0 && number == 0) {
    char tmp_str[8000] = {0};
    for (int i = 0; i < current_pattern.width; i++) {
      tmp_str[i] = ' ';
    }
    s21_strcpy(str, tmp_str);
  }

  if (number == 0 && current_pattern.precision == -1) s21_strcpy(str, "0");
}

void generate_o_flag(pattern current_pattern, va_list arg_list,
                     char str[8000]) {
  unsigned long int number = va_arg(arg_list, unsigned long int);
  number = cut_unsigned_number_to_length(current_pattern, number);
  char char_for_fill_empty_places = current_pattern.flag_zero == 1 ? '0' : ' ';
  from_long_int_to_oct(number, str);
  if ((s21_size_t)current_pattern.precision < s21_strlen(str))
    current_pattern.precision = -1;
  if (current_pattern.flag_grid == 1 && current_pattern.precision == -1 &&
      current_pattern.flag_zero == 0) {
    add_symbol_before_string(str, '0');  // x_value
  }

  if (current_pattern.precision > (int)s21_strlen(str)) {
    alignment_str(str, current_pattern.precision, 0, '0');
    if (current_pattern.flag_grid == 1) {
      add_symbol_before_string(str, '0');  // x_value
    }
  }

  if ((s21_size_t)current_pattern.width > s21_strlen(str)) {
    if (current_pattern.flag_minus != 1 || current_pattern.flag_zero != 1) {
      alignment_str(str, current_pattern.width, current_pattern.flag_minus,
                    char_for_fill_empty_places);
      if (current_pattern.flag_grid == 1 && current_pattern.flag_zero == 1) {
        str[0] = '0';  // x_value
      }
    }
  }

  if (current_pattern.precision == 0 && number == 0) {
    char tmp_str[8000] = {0};
    for (int i = 0; i < current_pattern.width; i++) {
      tmp_str[i] = ' ';
    }
    s21_strcpy(str, tmp_str);
  }

  if (number == 0 && current_pattern.precision == -1) s21_strcpy(str, "0");
}

void generate_x_flag(pattern current_pattern, va_list arg_list, char str[8000],
                     char x_value) {
  unsigned long int number = va_arg(arg_list, unsigned long int);
  number = cut_unsigned_number_to_length(current_pattern, number);
  char char_for_fill_empty_places = current_pattern.flag_zero == 1 ? '0' : ' ';
  from_long_int_to_hex(number, str, x_value);
  if ((s21_size_t)current_pattern.precision < s21_strlen(str))
    current_pattern.precision = -1;
  if (current_pattern.flag_grid == 1 && current_pattern.precision == -1 &&
      current_pattern.flag_zero == 0) {
    add_symbol_before_string(str, x_value);
    add_symbol_before_string(str, '0');
  }

  if (current_pattern.precision > (int)s21_strlen(str)) {
    alignment_str(str, current_pattern.precision, 0, '0');
    if (current_pattern.flag_grid == 1) {
      add_symbol_before_string(str, x_value);
      add_symbol_before_string(str, '0');
    }
  }

  if ((s21_size_t)current_pattern.width > s21_strlen(str)) {
    if (current_pattern.flag_minus != 1 || current_pattern.flag_zero != 1) {
      alignment_str(str, current_pattern.width, current_pattern.flag_minus,
                    char_for_fill_empty_places);
      if (current_pattern.flag_grid == 1 && current_pattern.flag_zero == 1) {
        str[0] = '0';
        str[1] = x_value;
      }
    }
  }

  if (current_pattern.precision == 0 && number == 0) {
    char tmp_str[8000] = {0};
    for (int i = 0; i < current_pattern.width; i++) {
      tmp_str[i] = ' ';
    }
    s21_strcpy(str, tmp_str);
  }

  if (number == 0 && current_pattern.precision == -1) s21_strcpy(str, "0");
}

void from_ptr_to_hex(unsigned long long int *number, char str[8000]) {
  unsigned long long dex_ptr = (unsigned long long)number;
  char hex_ptr[8000] = {0};
  from_unsigned_long_long_int_to_hex(dex_ptr, hex_ptr, 'x');
  s21_strcpy(str, hex_ptr);
}

void from_long_int_to_hex(unsigned long int number, char str[8000],
                          char x_value) {
  unsigned long int tmp_number = number;
  while (tmp_number != 0) {
    int digit = tmp_number % 16;
    tmp_number /= 16;
    char text_digit = digit + 48;
    if (x_value == 'x') {
      if (digit == 10) text_digit = 'a';
      if (digit == 11) text_digit = 'b';
      if (digit == 12) text_digit = 'c';
      if (digit == 13) text_digit = 'd';
      if (digit == 14) text_digit = 'e';
      if (digit == 15) text_digit = 'f';
    } else if (x_value == 'X') {
      if (digit == 10) text_digit = 'A';
      if (digit == 11) text_digit = 'B';
      if (digit == 12) text_digit = 'C';
      if (digit == 13) text_digit = 'D';
      if (digit == 14) text_digit = 'E';
      if (digit == 15) text_digit = 'F';
    }
    add_symbol_before_string(str, text_digit);
  }
}

void from_unsigned_long_long_int_to_hex(unsigned long long int number,
                                        char str[8000], char x_value) {
  unsigned long long int tmp_number = number;
  while (tmp_number != 0) {
    int digit = tmp_number % 16;
    tmp_number /= 16;
    char text_digit = digit + 48;
    if (x_value == 'x') {
      if (digit == 10) text_digit = 'a';
      if (digit == 11) text_digit = 'b';
      if (digit == 12) text_digit = 'c';
      if (digit == 13) text_digit = 'd';
      if (digit == 14) text_digit = 'e';
      if (digit == 15) text_digit = 'f';
    }
    add_symbol_before_string(str, text_digit);
  }
}

void from_long_int_to_oct(unsigned long int number, char str[8000]) {
  unsigned long int tmp_number = number;
  while (tmp_number != 0) {
    int digit = tmp_number % 8;
    tmp_number /= 8;
    char text_digit = digit + 48;
    add_symbol_before_string(str, text_digit);
  }
}

void generate_g_flag(pattern current_pattern, va_list arg_list, char str[8000],
                     char g_value) {
  char e[2] = {'\0'};
  e[0] = g_value == 'g' ? 'e' : 'E';
  long double number = 0;
  int is_negative = 0;
  char sign = '+';
  char floatstr[8000] = {0};

  if (current_pattern.length == 'L')
    number = va_arg(arg_list, long double);
  else
    number = va_arg(arg_list, double);
  if (current_pattern.precision == -1) current_pattern.precision = 6;

  int source_number_is_negative = 0;
  if (number < 0) {
    source_number_is_negative = 1;
    number *= -1;
  }
  if (get_left_numbers_counter(number) == current_pattern.precision) {
    long double tmp_number = roundl(number);
    current_pattern.precision = 0;
    if (source_number_is_negative == 1) tmp_number *= -1;
    from_float_to_string(tmp_number, current_pattern, floatstr);
    s21_strcat(str, floatstr);
    str[s21_strlen(str)] = '\0';
    fit_str_number_to_the_final_string(current_pattern, str, is_negative,
                                       tmp_number, sign);
  } else if (get_left_numbers_counter(number) < current_pattern.precision) {
    g_inner_function(&number, str, &source_number_is_negative, floatstr,
                     current_pattern, e);
    fit_str_number_to_the_final_string(current_pattern, str, is_negative,
                                       number, sign);
  } else {
    current_pattern.precision--;
    number = roundl(number);
    create_full_e_string(number, current_pattern, str, e, 1,
                         source_number_is_negative);
    fit_str_number_to_the_final_string(current_pattern, str, is_negative,
                                       number, sign);
  }
}

int get_left_numbers_counter(long double src_number) {
  int i = 0;
  long int tmp_number = (long int)src_number;
  while (tmp_number != 0) {
    tmp_number /= 10;
    i++;
  }
  return i;
}

void g_inner_function(long double *number, char str[8000],
                      int *source_number_is_negative, char floatstr[8000],
                      pattern current_pattern, char e[2]) {
  if (round(*number) > 0) {
    if (*source_number_is_negative == 1) *number *= -1;
    from_float_to_string(*number, current_pattern, floatstr);
    s21_strcat(str, floatstr);
    if (str_number_has_dot(str) == 1) cat_end_zeros(str);
    if (str[s21_strlen(str) - 1] == '.') str[s21_strlen(str) - 1] = '\0';
    if (s21_strlen(str) - 1 > (s21_size_t)current_pattern.precision) {
      int needed_pow =
          current_pattern.precision - get_left_numbers_counter(*number);
      *number *= pow(10, needed_pow);
      long double tmp_number = roundl(*number);
      tmp_number /= pow(10, needed_pow);
      str[0] = '\0';
      current_pattern.precision = needed_pow;
      from_float_to_string(tmp_number, current_pattern, str);
      cat_end_zeros(str);
    }
  } else {
    int iteration_counter = 0;
    long double tmp_number = *number;
    while (round(tmp_number) <= 0) {
      tmp_number *= 10;
      iteration_counter++;
    }
    tmp_number *= pow(10, current_pattern.precision - 1);
    tmp_number = round(tmp_number);
    tmp_number /= pow(10, current_pattern.precision + (iteration_counter - 1));
    if (iteration_counter < 5) {
      int tmp_precision = current_pattern.precision + (iteration_counter - 1);
      current_pattern.precision = tmp_precision + 1;
      if (*source_number_is_negative == 1) tmp_number *= -1;
      from_float_to_string(tmp_number, current_pattern, str);
      cat_end_zeros(str);
    } else {
      create_full_e_string(tmp_number, current_pattern, str, e, 1,
                           *source_number_is_negative);
      cat_end_zeros(str);
    }
  }
}

void cat_end_zeros(char str[8000]) {
  int is_only_zeros = 1;
  for (int i = s21_strlen(str) - 1; i >= 0; i--) {
    if (is_only_zeros == 1) {
      // if (str[i] == '0' && is_only_zeros == 1)
      if (str[i] == '0')
        str[i] = '\0';
      else
        is_only_zeros = 0;
    }
  }
}

int str_number_has_dot(char str[8000]) {
  int has_dot = 0;
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    if (str[i] == '.') has_dot = 1;
  }
  return has_dot;
}

void generate_e_flag(pattern current_pattern, va_list arg_list, char str[8000],
                     char e[2]) {
  long double number = 0;

  if (current_pattern.length == 'L')
    number = va_arg(arg_list, long double);
  else
    number = va_arg(arg_list, double);

  if (current_pattern.precision == -1) current_pattern.precision = 6;

  int source_number_is_negative = 0;
  if (number < 0) {
    source_number_is_negative = 1;
    number *= -1;
  }

  create_full_e_string(number, current_pattern, str, e, 0,
                       source_number_is_negative);

  if (source_number_is_negative == 1) {
    number *= -1;
  }

  int is_negative = 0;
  char sign_specifier = '+';

  fit_str_number_to_the_final_string(current_pattern, str, is_negative, number,
                                     sign_specifier);
}

void create_full_e_string(long double number, pattern current_pattern,
                          char str[8000], char e[2], int g_enabled,
                          int source_number_is_negative) {
  int distance = 0;
  char sign[2] = {'\0'};
  char floatstr[8000] = {0};
  long double notation_number =
      generate_simple_e_number(number, sign, &distance);
  from_float_to_string(notation_number, current_pattern, floatstr);
  s21_strcat(str, floatstr);
  if (g_enabled == 1) cat_end_zeros(str);
  s21_strcat(str, e);
  s21_strcat(str, sign);
  if (distance < 10) s21_strcat(str, "0");
  char *str_discance = s21_from_long_int_to_str(distance);
  s21_strcat(str, str_discance);
  if (source_number_is_negative == 1) {
    add_symbol_before_string(str, '-');
  }
  free(str_discance);
}

void generate_f_flag(pattern current_pattern, va_list arg_list,
                     char str_number[8000]) {
  long double number = 0;
  int is_negative = 0;
  char sign = '+';

  if (current_pattern.length == 'L')
    number = va_arg(arg_list, long double);
  else
    number = va_arg(arg_list, double);

  if (current_pattern.precision == -1) current_pattern.precision = 6;

  char floatstr[8000] = {0};
  from_float_to_string(number, current_pattern, floatstr);
  s21_strcat(str_number, floatstr);

  fit_str_number_to_the_final_string(current_pattern, str_number, is_negative,
                                     number, sign);
}

void fit_str_number_to_the_final_string(pattern current_pattern, char str[8000],
                                        int is_negative, long double number,
                                        char sign_specifier) {
  if ((s21_size_t)current_pattern.width > s21_strlen(str) &&
      current_pattern.flag_zero == 1 &&
      (str[0] == '-' || current_pattern.flag_plus == 1 ||
       current_pattern.flag_space == 1)) {
    is_negative = 1;
    if (current_pattern.flag_plus == 1 && str[0] != '-' &&
        current_pattern.flag_space != 1)
      sign_specifier = '+';
    if (current_pattern.flag_space == 1 && current_pattern.flag_plus != 1 &&
        str[0] != '-')
      sign_specifier = ' ';
    if (str[0] == '-') {
      sign_specifier = '-';
      str[0] = '0';
    }
  }

  char char_for_fill_empty_places = current_pattern.flag_zero == 1 ? '0' : ' ';

  if ((s21_size_t)current_pattern.width > s21_strlen(str)) {
    if (current_pattern.flag_space == 1 && str[0] != '-' && str[0] != '+' &&
        current_pattern.flag_zero != 1)
      add_symbol_before_string(str, ' ');
    if (current_pattern.flag_plus == 1 && str[0] != '-' && str[0] != '+' &&
        current_pattern.flag_zero != 1)
      add_symbol_before_string(str, '+');
    alignment_str(str, current_pattern.width, current_pattern.flag_minus,
                  char_for_fill_empty_places);
  } else {
    double x = copysign(3, number);
    if (current_pattern.flag_plus == 1 && x >= 0)
      add_symbol_before_string(str, '+');
    if (current_pattern.flag_space == 1 && x >= 0)
      add_symbol_before_string(str, ' ');
  }

  if (is_negative == 1) str[0] = sign_specifier;
}

long double generate_simple_e_number(
    long double src_number, char sign[2],
    int *distance) {  //только для положительных чисел
  if (src_number >= 1) {
    sign[0] = '+';
    while (get_left_numbers_counter(src_number) != 1) {
      src_number /= 10;
      (*distance)++;
    }
  } else {
    sign[0] = '-';
    while (get_left_numbers_counter(src_number) != 1) {
      src_number *= 10;
      (*distance)++;
    }
  }
  return src_number;
}

char *s21_from_long_int_to_str(unsigned long int digit) {
  char *a = (char *)malloc(22 * sizeof(char));
  char *b;
  unsigned long int tmp_digit = digit;
  if (digit == 0) {
    a[21] = '\0';
    a[20] = '0';
    b = &a[20];
  } else {
    int i = 21;
    while (tmp_digit != 0) {
      i--;
      a[i] = tmp_digit % 10 + 48;
      tmp_digit /= 10;
    }
    a[21] = '\0';
    b = &a[i];
  }
  char *c = (char *)malloc(22 * sizeof(char));
  s21_strcpy(c, b);
  free(a);
  return c;
}

void generate_d_flag(pattern current_pattern, va_list arg_list,
                     char str[8000]) {
  long int number = va_arg(arg_list, long int);
  char sign_of_number = '+';
  number = cut_number_to_length(current_pattern, number);
  if (number < 0) {
    number *= -1;
    current_pattern.flag_plus = 1;
    sign_of_number = '-';
  }
  char char_for_fill_empty_places = current_pattern.flag_zero == 1 ? '0' : ' ';
  char *strnum = s21_from_long_int_to_str(number);
  s21_strcpy(str, strnum);
  if (current_pattern.precision > (int)s21_strlen(str))
    alignment_str(str, current_pattern.precision, 0, '0');
  int origin_len = s21_strlen(str);
  if (current_pattern.flag_plus == 1 && number >= 0 &&
      ((s21_size_t)current_pattern.width <= s21_strlen(str) ||
       current_pattern.flag_zero == 0))
    add_symbol_before_string(str, sign_of_number);
  if (current_pattern.flag_space == 1 && number >= 0 &&
      current_pattern.flag_plus == 0 &&
      ((s21_size_t)current_pattern.width <= s21_strlen(str) ||
       current_pattern.flag_zero == 0))
    add_symbol_before_string(str, ' ');
  if ((s21_size_t)current_pattern.width > s21_strlen(str)) {
    if (current_pattern.flag_minus != 1 || current_pattern.flag_zero != 1)
      alignment_str(str, current_pattern.width, current_pattern.flag_minus,
                    char_for_fill_empty_places);
  }
  d_inner_function(current_pattern, number, origin_len, str, sign_of_number);
  free(strnum);
}

void d_inner_function(pattern current_pattern, long int number, int origin_len,
                      char str[8000], char sign_of_number) {
  if (current_pattern.flag_plus == 1 && number >= 0 &&
      current_pattern.width > origin_len && current_pattern.flag_zero == 1)
    str[0] = sign_of_number;
  if (current_pattern.flag_plus == 0 && current_pattern.flag_space == 1 &&
      number >= 0 && current_pattern.width > origin_len &&
      current_pattern.flag_zero == 1)
    str[0] = ' ';
  if (current_pattern.precision == 0 && number == 0) {
    char tmp_str[8000] = {0};
    for (int i = 0; i < current_pattern.width; i++) {
      tmp_str[i] = ' ';
    }
    if (current_pattern.flag_plus == 1) {
      if (current_pattern.flag_minus == 1 || current_pattern.width == 0) {
        tmp_str[0] = '+';
      } else {
        tmp_str[current_pattern.width - 1] = '+';
      }
    }
    if (current_pattern.flag_space == 1) {
      if (current_pattern.flag_minus == 1 || current_pattern.width == 0) {
        tmp_str[0] = ' ';
      } else {
        tmp_str[current_pattern.width - 1] = ' ';
      }
    }
    s21_strcpy(str, tmp_str);
  }
}

long int cut_number_to_length(pattern current_pattern, long int number) {
  if (current_pattern.length == 'h') {
    short int tmp_number = number;
    number = tmp_number;
  } else if (current_pattern.length == 'l') {
    long int tmp_number = number;
    number = tmp_number;
  } else {
    int tmp_number = number;
    number = tmp_number;
  }
  return number;
}

unsigned long int cut_unsigned_number_to_length(pattern current_pattern,
                                                unsigned long int number) {
  if (current_pattern.length == 'h') {
    unsigned short int tmp_number = number;
    number = tmp_number;
  } else if (current_pattern.length == 'l') {
    unsigned long int tmp_number = number;
    number = tmp_number;
  } else {
    unsigned int tmp_number = number;
    number = tmp_number;
  }
  return number;
}

void generate_s_flag(pattern current_pattern, va_list arg_list,
                     char arg_str[8000]) {
  int width = current_pattern.width;
  int precision = current_pattern.precision;

  if (precision != -1) {
    s21_strncpy(arg_str, va_arg(arg_list, char *), precision);
  } else {
    s21_strcpy(arg_str, va_arg(arg_list, char *));
  }

  if ((s21_size_t)width > s21_strlen(arg_str))
    alignment_str(arg_str, width, current_pattern.flag_minus, ' ');
}

void generate_c_flag(pattern current_pattern, va_list arg_list,
                     char chr[8000]) {
  chr[0] = va_arg(arg_list, int);
  if (current_pattern.width > 1)
    alignment_str(chr, current_pattern.width, current_pattern.flag_minus, ' ');
}

void generate_u_flag(pattern current_pattern, va_list arg_list,
                     char str[8000]) {
  unsigned long int number = va_arg(arg_list, unsigned long int);
  number = cut_unsigned_number_to_length(current_pattern, number);
  char char_for_fill_empty_places = current_pattern.flag_zero == 1 ? '0' : ' ';
  char *numberstr = s21_from_long_int_to_str(number);
  s21_strcpy(str, numberstr);
  if (current_pattern.precision > (int)s21_strlen(str)) {
    alignment_str(str, current_pattern.precision, 0, '0');
  }

  if ((s21_size_t)current_pattern.width > s21_strlen(str)) {
    if (current_pattern.flag_minus != 1 || current_pattern.flag_zero != 1) {
      alignment_str(str, current_pattern.width, current_pattern.flag_minus,
                    char_for_fill_empty_places);
    }
  }

  if (current_pattern.precision == 0 && number == 0) {
    char tmp_str[8000] = {0};
    for (int i = 0; i < current_pattern.width; i++) {
      tmp_str[i] = ' ';
    }
    s21_strcpy(str, tmp_str);
  }
  free(numberstr);
}

void alignment_str(char str[8000], int width, int minus_enabled, char chr) {
  char tmp_str[8000] = {'\0'};
  if (minus_enabled == 0) {
    for (s21_size_t i = 0; i < width - s21_strlen(str); i++) {
      tmp_str[i] = chr;
    }
    for (s21_size_t i = width - s21_strlen(str); i <= (s21_size_t)width; i++) {
      tmp_str[i] = str[i - width + s21_strlen(str)];
    }
  } else {
    s21_size_t i = 0;
    for (; i < s21_strlen(str); i++) {
      tmp_str[i] = str[i];
    }
    while (i < (s21_size_t)width) {
      tmp_str[i] = chr;
      i++;
    }
  }
  s21_strcpy(str, tmp_str);
}

int is_specifier(char ch) {
  int result = 0;
  if (ch == 'c' || ch == 'd' || ch == 'i' || ch == 'e' || ch == 'E' ||
      ch == 'f' || ch == 'g' || ch == 'G' || ch == 'o' || ch == 's' ||
      ch == 'u' || ch == 'x' || ch == 'X' || ch == 'p' || ch == 'n' ||
      ch == '%')
    result = 1;
  return result;
}

void add_symbol_before_string(char str[8000], char symbol) {
  for (int i = s21_strlen(str); i >= 0; i--) {
    str[i + 1] = str[i];
  }
  str[0] = symbol;
}

void from_float_to_string(long double number, pattern current_pattern,
                          char str_number[8000]) {
  int is_negative = 0;
  int count_of_zeros = 0;
  double x = copysign(3, number);
  if (x < 0) {
    is_negative = 1;
    number *= -1;
  }
  if (roundl(number) == 0) {
    long double tmp_number = number;
    while (roundl(tmp_number) == 0 && count_of_zeros < 20) {
      count_of_zeros++;
      tmp_number *= 10;
    }
    count_of_zeros--;
  }
  long double left = 0;
  long double right = modfl(number, &left);
  right = right * pow(10, current_pattern.precision);
  right = round(right);
  char *strleft = s21_from_long_int_to_str(left);
  s21_strcat(str_number, strleft);
  if (current_pattern.precision != 0) s21_strcat(str_number, ".");
  char *strright = s21_from_long_int_to_str(right);
  while (count_of_zeros != 0) {
    char *tmp = (char *)realloc(
        strright, s21_strlen(strright) * (sizeof(char) * 2) + sizeof(char));
    if (tmp == s21_NULL)
      free(tmp);
    else
      strright = tmp;
    for (int i = s21_strlen(strright); i >= 0; i--) {
      strright[i + 1] = strright[i];
    }
    strright[0] = '0';
    count_of_zeros--;
  }
  from_float_to_string_inner_function(str_number, current_pattern, strright,
                                      is_negative);
  free(strleft);
  free(strright);
}

void from_float_to_string_inner_function(char str_number[8000],
                                         pattern current_pattern,
                                         char *strright, int is_negative) {
  if (current_pattern.precision != 0) s21_strcat(str_number, strright);
  if (s21_strlen(strright) < (s21_size_t)current_pattern.precision) {
    for (s21_size_t i = 0;
         i < (current_pattern.precision - s21_strlen(strright)); i++) {
      s21_strcat(str_number, "0");
    }
  }
  if (current_pattern.flag_grid == 1 && current_pattern.precision == 0)
    s21_strcat(str_number, ".");
  if (is_negative == 1) add_symbol_before_string(str_number, '-');
}