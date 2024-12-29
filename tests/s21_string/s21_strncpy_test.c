#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char dest1[10] = {0};
  char dest2[10] = {0};

  char src[] = "abcdef";
  s21_strncpy(dest1, src, 5);
  strncpy(dest2, src, 5);

  ck_assert_str_eq(dest1, dest2);
}

START_TEST(test2) {
  char dest1[8] = {0};
  char dest2[8] = {0};

  char src[] = "1234567";
  s21_strncpy(dest1, src, 3);
  strncpy(dest2, src, 3);

  ck_assert_str_eq(dest1, dest2);
}

START_TEST(test3) {
  char dest1[5] = {0};
  char dest2[5] = {0};

  char src[] = "abcd";
  s21_strncpy(dest1, src, 5);
  strncpy(dest2, src, 5);

  ck_assert_str_eq(dest1, dest2);
}

START_TEST(test4) {
  char dest1[8] = {0};
  char dest2[8] = {0};

  char src[] = "abcdefg";
  strncpy(dest1, src, 4);
  s21_strncpy(dest2, src, 4);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(test5) {
  char dest1[10] = {0};
  char dest2[10] = {0};
  char src[] = "";
  s21_strncpy(dest1, src, 10);
  strncpy(dest2, src, 10);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(test6) {
  char dest1[10] = "initial";
  char dest2[10] = "initial";
  char src[] = "abcdef";
  s21_strncpy(dest1, src, 1);
  strncpy(dest2, src, 1);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(test7) {
  char dest1[10] = {0};
  char dest2[10] = {0};
  char src[] = "abc";
  s21_strncpy(dest1, src, 10);
  strncpy(dest2, src, 10);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(test8) {
  char dest1[10] = {0};
  char dest2[10] = {0};
  char src[] = "abc";
  s21_strncpy(dest1, src, 3);
  strncpy(dest2, src, 3);
  ck_assert_mem_eq(dest1, dest2, 3);
}

Suite *s21_strncpy_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_strncpy test=-\033[0m");
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