#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char dest1[8000] = "Hello world";
  char dest2[8000] = "Hello world";
  char src[8000] = " Hello world";
  s21_strcpy(dest1, src);
  strcpy(dest2, src);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(test2) {
  char dest1[8000] = {0};
  char dest2[8000] = {0};
  char src[8000] = " Hello \0 world";
  s21_strcpy(dest1, src);
  strcpy(dest2, src);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(test3) {
  char dest1[8000] = {0};
  char dest2[8000] = {0};
  char src[8000] =
      "Hello world Hello world Hello world Hello world Hello world Hello world "
      "Hello world Hello world";
  s21_strcpy(dest1, src);
  strcpy(dest2, src);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(test4) {
  char dest1[8000] = {0};
  char dest2[8000] = {0};
  char src[8000] = "";
  s21_strcpy(dest1, src);
  strcpy(dest2, src);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(test5) {
  char dest1[8000] = {"123456778990012345678990"};
  char dest2[8000] = {"123456778990012345678990"};
  char src[8000] = "1234567789900";
  s21_strcpy(dest1, src);
  strcpy(dest2, src);
  ck_assert_str_eq(dest1, dest2);
}

Suite *s21_strcpy_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_strcpy test=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  tcase_add_test(t, test4);
  tcase_add_test(t, test5);
  suite_add_tcase(s, t);
  return s;
}