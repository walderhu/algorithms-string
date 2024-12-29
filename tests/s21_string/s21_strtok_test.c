#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char str[] = "Hello";
  const char *delim = " ";

  char *token = s21_strtok(str, delim);
  char *expected = strtok(str, delim);
  ck_assert_str_eq(token, expected);
}

START_TEST(test2) {
  char str[] = "test string example";
  char str_copy[sizeof(str)];
  strcpy(str_copy, str);

  const char *delim = " ";

  char *token = s21_strtok(str_copy, delim);
  char *expected = strtok(str, delim);
  ck_assert_str_eq(token, expected);

  char *token1 = s21_strtok(NULL, delim);
  char *expected1 = strtok(NULL, delim);
  ck_assert_str_eq(token1, expected1);

  char *token2 = s21_strtok(NULL, delim);
  char *expected2 = strtok(NULL, delim);
  ck_assert_str_eq(token2, expected2);
}

START_TEST(test3) {
  char str[] = "test_string_example";
  char str_copy[sizeof(str)];
  strcpy(str_copy, str);

  const char *delim = "_";

  char *token = s21_strtok(str_copy, delim);
  char *expected = strtok(str, delim);
  ck_assert_str_eq(token, expected);

  char *token1 = s21_strtok(NULL, delim);
  char *expected1 = strtok(NULL, delim);
  ck_assert_str_eq(token1, expected1);

  char *token2 = s21_strtok(NULL, delim);
  char *expected2 = strtok(NULL, delim);
  ck_assert_str_eq(token2, expected2);
}

START_TEST(test4) {
  char str[] = "";
  char str_copy[sizeof(str)];
  strcpy(str_copy, str);

  const char *delim = "";

  char *token = s21_strtok(str_copy, delim);
  char *expected = strtok(str, delim);
  ck_assert_ptr_null(token);
  ck_assert_ptr_null(expected);
}

START_TEST(test5) {
  char str[] = "test string example";
  char str_copy[sizeof(str)];
  strcpy(str_copy, str);

  const char *delim = "";

  char *token = s21_strtok(str_copy, delim);
  char *expected = strtok(str, delim);
  ck_assert_str_eq(token, expected);
}

Suite *s21_strtok_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_strtok test=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  tcase_add_test(t, test4);
  tcase_add_test(t, test5);
  suite_add_tcase(s, t);
  return s;
}
