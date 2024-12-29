#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  const char *src = "Hello, World!";
  const char *str = "beautiful ";
  s21_size_t start_index = 7;

  const char *expected = "Hello, beautiful World!";

  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test2) {
  const char *src = "World!";
  const char *str = "Hello, ";
  s21_size_t start_index = 0;

  const char *expected = "Hello, World!";

  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test3) {
  const char *src = "Hello, ";
  const char *str = "World!";
  s21_size_t start_index = 7;

  const char *expected = "Hello, World!";

  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test4) {
  const char *src = "";
  const char *str = "Hello";
  s21_size_t start_index = 0;

  const char *expected = "Hello";

  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test5) {
  const char *src = "Hello";
  const char *str = "";
  s21_size_t start_index = 3;

  const char *expected = "Hello";

  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(test6) {
  const char *src = "Hello";
  const char *str = "";
  s21_size_t start_index = 10;

  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_null(result);
  free(result);
}

START_TEST(test7) {
  const char *src = "Hello";
  const char *str = "World";
  s21_size_t start_index = -1;

  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_null(result);
  free(result);
}

Suite *s21_insert_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_insert test=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  tcase_add_test(t, test4);
  tcase_add_test(t, test5);
  tcase_add_test(t, test6);
  tcase_add_test(t, test7);
  suite_add_tcase(s, t);
  return s;
}
