#ifndef S21_STRING_H
#define S21_STRING_H

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#define s21_NULL ((void *)0)

/*walderhu*/
#define CORRECT 0
#define INCORRECT 1
#define STOCK -1
/*end of walderhu*/
typedef long unsigned s21_size_t;

typedef struct pattern {
  int flag_minus;
  int flag_plus;
  int flag_space;
  int flag_grid;
  int flag_zero;

  int is_width_asterisk;
  int width;

  int is_precision_asterisk;
  int precision;

  char length;

  char specifier;
} pattern;

int s21_sprintf(char *final_buffer, const char *format, ...);
char *s21_strcpy(char *restrict dst, const char *restrict src);
char *s21_strcat(char *dest, const char *src);

// Функции Натальи
char *s21_strchr(const char *str, int c);  // 6-я функция
s21_size_t s21_strlen(const char *str);    // 11-я функция
int s21_memcmp(const void *str1, const void *str2,
               s21_size_t n);  // 2-я функиця
int s21_strncmp(const char *str1, const char *str2,
                s21_size_t n);                   // 7-я функция
char *s21_strerror(int errnum);                  // 10-я функция
char *s21_strtok(char *str, const char *delim);  // 15-я функция
void *s21_insert(const char *src, const char *str, s21_size_t start_index);

// Функции Ангелины
s21_size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);

// Функции Илдара
void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);
char *s21_strpbrk(const char *string1, const char *string2);
char *s21_strstr(const char *haystack, const char *needle);
void *s21_trim(const char *src, const char *trim_chars);

/*
Вспомогательные функции из s21_sprintf_helpers
*/
void s21_copy_to_buff(char *final_buffer, const char *format, va_list arg_list);

/*функции для парсерв*/
int parse_pattern(char *final_buffer, const char *format, va_list arg_list,
                  int *i);
void generate_string_from_pattern(pattern current_pattern, va_list arg_list,
                                  char arg_str[8000]);
void fill_pattern(pattern *current_pattern, char ch, int *stage,
                  va_list arg_list);
void increase_width_or_precision(pattern *current_pattern, int digit,
                                 int stage);

/*генераторы итоговых строк*/
void generate_s_flag(pattern current_pattern, va_list arg_list,
                     char arg_str[8000]);
void generate_d_flag(pattern current_pattern, va_list arg_list,
                     char arg_str[8000]);
void generate_c_flag(pattern current_pattern, va_list arg_list, char chr[8000]);
void generate_u_flag(pattern current_pattern, va_list arg_list, char str[8000]);
void generate_e_flag(pattern current_pattern, va_list arg_list, char str[8000],
                     char e[2]);
void generate_g_flag(pattern current_pattern, va_list arg_list, char str[8000],
                     char g_value);
void generate_x_flag(pattern current_pattern, va_list arg_list, char str[8000],
                     char x_value);
void generate_f_flag(pattern current_pattern, va_list arg_list,
                     char str_number[8000]);
long double generate_simple_e_number(long double src_number, char sign[2],
                                     int *distance);
void generate_o_flag(pattern current_pattern, va_list arg_list, char str[8000]);
void generate_p_flag(pattern current_pattern, va_list arg_list, char str[8000]);
// void print_pattern(pattern currnet_pattern);

/*Проверки различные*/
int str_number_has_dot(char str[8000]);
int is_specifier(char ch);

/*обработки строк*/
void alignment_str(char str[8000], int width, int minus_enabled, char chr);
void cat_end_zeros(char str[8000]);
void fit_str_number_to_the_final_string(
    pattern current_pattern, char str[8000], int is_negative,
    long double number,
    char sign_specifier);  // берёт число уже в char и применяет к нему всякие
                           // плюсы, точности минусы и т.д. и возврщает
                           // отформатированную строку
void add_symbol_before_string(char str[8000], char symbol);

/*обработки чисел*/
unsigned long int cut_unsigned_number_to_length(pattern current_pattern,
                                                unsigned long int number);
long int cut_number_to_length(pattern current_pattern, long int number);
void from_float_to_string(long double number, pattern current_pattern,
                          char str_number[8000]);
void from_long_int_to_hex(unsigned long int number, char str[8000],
                          char x_value);
void from_long_int_to_oct(unsigned long int number, char str[8000]);
char *s21_from_long_int_to_str(unsigned long int digit);
int get_left_numbers_counter(long double src_number);

void from_unsigned_long_long_int_to_hex(unsigned long long int number,
                                        char str[8000], char x_value);
void from_ptr_to_hex(unsigned long long int *number, char str[8000]);

long double get_significant_number(long double number, pattern current_pattern);
void create_full_e_string(long double number, pattern current_pattern,
                          char str[8000], char e[2], int g_enabled,
                          int source_number_is_negative);

/*void'ы от душных пиров*/
void g_inner_function(long double *number, char str[8000],
                      int *source_number_is_negative, char floatstr[8000],
                      pattern current_pattern, char e[2]);
void d_inner_function(pattern current_pattern, long int number, int origin_len,
                      char str[8000], char sign_of_number);
void from_float_to_string_inner_function(char str_number[8000],
                                         pattern current_pattern,
                                         char *strright, int is_negative);

/*код walderhu*/
int s21_sscanf(const char *str, const char *format, ...);
s21_size_t parsing(char *str, char *format);
void remove_beginning(char *str, s21_size_t quantity);
int s21_isspace(char symbol);

int treatment(const char *str, char *str_replica, const char *format,
              char *format_replica, va_list arg);
void treatment_symbols(char *str, char specifier, va_list arg, int width);
void treatment_simple_digit(char *str, char specifier, va_list arg, int width);
void treatment_floating_digit(char *str, char specifier, va_list arg,
                              int width);
void treatment_short_digit(char *str, char specifier, va_list arg, int width);
void treatment_long_simple_digit(char *str, char specifier, va_list arg,
                                 int width);
void treatment_long_float_digit(char *str, char specifier, va_list arg,
                                int width);
void treatment_other_specifiers(char *str, const char *format,
                                char *format_replica, va_list arg, int width);

void specifier_c(char *str, char *buffer);
void specifier_s(char *str, char *buffer, int width);

s21_size_t specifier_d(char *str, long *buffer, int width);
void specifier_i(char *str, long *buffer, int width);
void specifier_o(char *str, unsigned long *buffer, int width);
void specifier_u(char *str, unsigned long *buffer, int width);
void specifier_x(char *str, unsigned long *buffer, int width);
void specifier_X(char *str, unsigned long *buffer, int width);

s21_size_t specifier_f(char *str, long double *buffer, int width);
s21_size_t specifier_e(char *str, long double *buffer, int width);
s21_size_t specifier_E(char *str, long double *buffer, int width);
s21_size_t specifier_g(char *str, long double *buffer, int width);
s21_size_t specifier_G(char *str, long double *buffer, int width);

void specifier_h(char *str, char format, short *buffer, int width);
void specifier_l(char *str, char format, long *buffer, int width);
void specifier_L(char *str, char format, long double *buffer, int width);

void specifier_n(const char *str, char *str_replica, const char *format,
                 int *buffer);
void specifier_skeep(char *str, char *format_replica);
void specifier_width(char *str, const char *format, char *format_replica,
                     va_list arg);
void specifier_p(char *str, void *buffer, int width);
void specifier_percent(char *str, const char *format, char *format_replica,
                       va_list arg);

s21_size_t determine_length(s21_size_t total_length, s21_size_t space_length,
                            s21_size_t number_length, int width);
#endif
