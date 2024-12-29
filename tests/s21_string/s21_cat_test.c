#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char dest1[8000] = {0};
  char dest2[8000] = {0};
  char src[] = "Hello world";
  s21_strcat(dest1, src);
  strcat(dest2, src);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(test2) {
  char dest1[8000] = "Hello";
  char dest2[8000] = "Hello";
  char src[] = " world";
  s21_strcat(dest1, src);
  strcat(dest2, src);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(test3) {
  char dest1[8000] = "Hello";
  char dest2[8000] = "Hello";
  char src[] = "";
  s21_strcat(dest1, src);
  strcat(dest2, src);
  ck_assert_str_eq(dest1, dest2);
}

Suite *s21_strcat_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_strcat test=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  suite_add_tcase(s, t);
  return s;
}