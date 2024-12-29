#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char str1[] = "Hello world";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}

START_TEST(test2) {
  char str1[] = "";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}

START_TEST(test3) {
  char str1[] = "a";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}

START_TEST(test4) {
  char str1[] = "   ";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}

START_TEST(test5) {
  char str1[] = "Hello\0world";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}

START_TEST(test6) {
  char str1[1000];
  memset(str1, 'a', 999);
  str1[999] = '\0';
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}

START_TEST(test7) {
  char str1[] = "\t\n\v\f\r";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}

Suite *s21_strlen_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_strlen test=-\033[0m");
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