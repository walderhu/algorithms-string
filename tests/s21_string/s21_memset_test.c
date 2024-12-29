#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char str[10] = "abcdefghi";
  s21_memset(str, 'X', 5);
  ck_assert_str_eq(str, "XXXXXfghi");
}

START_TEST(test2) {
  char str[8] = "1234567";
  s21_memset(str, '0', 3);
  ck_assert_str_eq(str, "0004567");
}

START_TEST(test3) {
  char str[5] = "abcd";
  s21_memset(str, '\0', 5);
  ck_assert_str_eq(str, "\0\0\0\0\0");
}

START_TEST(test4) {
  char str1[8] = "abcdefg";
  char str2[8] = "abcdefg";

  s21_size_t i = 0;
  while (i < 7) {
    s21_memset(str1, 'X', i);
    memset(str2, 'X', i);
    ck_assert_str_eq(str1, str2);
    i++;
  }
}

START_TEST(test5) {
  char str1[10] = "123456789";
  char str2[10] = "123456789";

  s21_size_t i = 0;
  while (i < 10) {
    memset(str2, '0', i);
    s21_memset(str1, '0', i);
    ck_assert_str_eq(str1, str2);
    i++;
  }
}

START_TEST(test6) {
  char str1[2] = "\0";
  memset(str1, 'X', 1);
  char str2[2] = "\0";
  s21_memset(str2, 'X', 1);

  ck_assert_str_eq(str1, str2);
}

START_TEST(test7) {
  char str[10] = "123456789";
  s21_memset(str, 'X', 0);
  ck_assert_str_eq(str, "123456789");
}

START_TEST(test8) {
  char str[10] = "123456789";
  s21_memset(str, 'X', 9);
  ck_assert_str_eq(str, "XXXXXXXXX");
}

START_TEST(test9) {
  char str1[10] = "123456789";
  s21_memset(str1, '\xFF', 5);
  char str2[10] = "123456789";
  memset(str2, '\xFF', 5);
  ck_assert_mem_eq(str1, str2, 10);
}

Suite* s21_memset_test_suite() {
  Suite* s = suite_create("\033[42m-=s21_memset test=-\033[0m");
  TCase* t = tcase_create("main tcase");
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
