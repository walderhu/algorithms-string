#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  const char str1[] = "abcdef";
  const char str2[] = "cef";
  char *result_s21 = s21_strpbrk(str1, str2);
  const char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test2) {
  const char str1[] = "abcdef";
  const char str2[] = "12f";
  char *result_s21 = s21_strpbrk(str1, str2);
  const char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test3) {
  const char str1[] = "abcdef";
  const char str2[] = "ah";
  char *result_s21 = s21_strpbrk(str1, str2);
  const char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test4) {
  const char str1[] = "abcdef";
  const char str2[] = "123";
  char *result_s21 = s21_strpbrk(str1, str2);
  const char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test5) {
  const char str1[] = "abcdef";
  const char str2[] = "gh";
  char *result_s21 = s21_strpbrk(str1, str2);
  const char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test6) {
  const char str1[] = "abcdef";
  const char str2[] = "";
  char *result_s21 = s21_strpbrk(str1, str2);
  const char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test7) {
  const char str1[] = "";
  const char str2[] = "xyz";
  char *result_s21 = s21_strpbrk(str1, str2);
  const char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test8) {
  const char str1[] = "";
  const char str2[] = "";
  char *result_s21 = s21_strpbrk(str1, str2);
  const char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}
START_TEST(test9) {
  const char str1[] = "\0";
  const char str2[] = "\0";
  char *result_s21 = s21_strpbrk(str1, str2);
  const char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test10) {
  const char str1[] = "\0";
  const char str2[] = "abc";
  char *result_s21 = s21_strpbrk(str1, str2);
  const char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test11) {
  const char str1[] = "abcdef";
  const char str2[] = "\0";
  char *result_s21 = s21_strpbrk(str1, str2);
  const char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test12) {
  const char str1[] = "abc\1\2\3def";
  const char str2[] = "\2";
  char *result_s21 = s21_strpbrk(str1, str2);
  const char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test13) {
  const char str1[] = "\x01\x02\x03";
  const char str2[] = "\x02";
  char *result_s21 = s21_strpbrk(str1, str2);
  const char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}

Suite *s21_strpbrk_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_strpbrk test=-\033[0m");
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
  tcase_add_test(t, test10);
  tcase_add_test(t, test11);
  tcase_add_test(t, test12);
  tcase_add_test(t, test13);
  suite_add_tcase(s, t);
  return s;
}