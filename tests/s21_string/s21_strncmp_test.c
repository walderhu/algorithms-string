#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test2) {
  char str1[] = "Hell";
  char str2[] = "Hello";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test3) {
  char str1[] = "Hello";
  char str2[] = "Hell";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test4) {
  char str1[] = "Hello";
  char str2[] = "Hello, World!";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test5) {
  char str1[] = "Hello";
  char str2[] = "Hell";
  int n = 0;

  for (int i = 0; i <= n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test6) {
  char str1[] = "\0";
  char str2[] = "Hell";
  int n = sizeof(str2);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test7) {
  char str1[] = "\0";
  char str2[] = "\0";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test8) {
  char str1[] = "Hello!";
  char str2[] = "\0";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

Suite *s21_strncmp_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_strncmp test=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  tcase_add_test(t, test4);
  tcase_add_test(t, test5);
  tcase_add_test(t, test6);
  tcase_add_test(t, test7);
  tcase_add_test(t, test8);
  suite_add_tcase(s, t);
  return s;
}
