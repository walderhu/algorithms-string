#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  const char str1[] = "Hello";
  const char str2[] = "Hello";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_memcmp(str1, str2, i);
    int expected = memcmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test2) {
  const char str1[] = "abcd";
  const char str2[] = "ABCD";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_memcmp(str1, str2, i);
    int expected = memcmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test3) {
  const char str1[] = "Hello";
  const char str2[] = "Hella";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_memcmp(str1, str2, i);
    int expected = memcmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test4) {
  const int arr1[] = {1, 2, 3};
  const int arr2[] = {1, 2, 3};
  int n = sizeof(arr1);

  for (int i = 0; i < n; i++) {
    int result = s21_memcmp(arr1, arr2, i);
    int expected = memcmp(arr1, arr2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test5) {
  const char str1[] = "";
  const char str2[] = "Hello";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_memcmp(str1, str2, i);
    int expected = memcmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test6) {
  const char str1[] = "\0";
  const char str2[] = "";
  int n = sizeof(str2);

  for (int i = 0; i < n; i++) {
    int result = s21_memcmp(str1, str2, i);
    int expected = memcmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test7) {
  const int arr1[] = {1, 2, 3};
  const int arr2[] = {1, 7, 3};
  int n = sizeof(arr1);

  for (int i = 0; i < n; i++) {
    int result = s21_memcmp(arr1, arr2, i);
    int expected = memcmp(arr1, arr2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test8) {
  const int arr1[] = {1, 2, 3};
  const int arr2[] = {1, 7, 3, 5, 6};
  int n = sizeof(arr1);

  for (int i = 0; i < n; i++) {
    int result = s21_memcmp(arr1, arr2, i);
    int expected = memcmp(arr1, arr2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

START_TEST(test9) {
  const int arr1[] = {1, 7, 3};
  const int arr2[] = {1, 7, 3, 5, 6};
  int n = sizeof(arr2);

  for (int i = 0; i < n; i++) {
    int result = s21_memcmp(arr1, arr2, i);
    int expected = memcmp(arr1, arr2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}

Suite *s21_memcmp_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_memcmp test=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  tcase_add_test(t, test4);
  tcase_add_test(t, test5);
  tcase_add_test(t, test6);
  tcase_add_test(t, test7);
  tcase_add_test(t, test8);
  tcase_add_test(t, test9);
  suite_add_tcase(s, t);
  return s;
}
