#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char str[] = "greybaca";
  ck_assert_str_eq(s21_strchr(str, 'y'), strchr(str, 'y'));
}

START_TEST(test2) {
  char str[] = "This is a sample string";
  char *s21_p, *p;
  s21_p = s21_strchr(str, 's');
  p = strchr(str, 's');

  while (s21_p != NULL) {
    ck_assert_int_eq(s21_p - str + 1, p - str + 1);
    s21_p = strchr(s21_p + 1, 's');
    p = strchr(p + 1, 's');
  }
}

START_TEST(test3) {
  char str[] = "";
  ck_assert_pstr_eq(s21_strchr(str, ' '), strchr(str, ' '));
}

START_TEST(test4) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_strchr(str, 'z'), strchr(str, 'z'));
}

START_TEST(test5) {
  char str[] = "Hello world";
  ck_assert_ptr_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
}

START_TEST(test6) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_strchr(str, 'a'), strchr(str, 'a'));
}

START_TEST(test7) {
  char str[] = "abc\0def";
  ck_assert_ptr_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
}

START_TEST(test8) {
  char str[] = "";
  ck_assert_ptr_eq(s21_strchr(str, 'a'), strchr(str, 'a'));
}

Suite *s21_strchr_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_strchr test=-\033[0m");
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
