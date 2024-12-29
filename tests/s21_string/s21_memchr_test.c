#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char str[] = "greybaca";
  ck_assert_str_eq(s21_memchr(str, 'y', 9), memchr(str, 'y', 9));
}

START_TEST(test2) {
  char str[] = "Hello, world!";
  ck_assert_ptr_eq(s21_memchr(str, 'o', 13), memchr(str, 'o', 13));
}

START_TEST(test3) {
  char str[] = "This is a test string";
  ck_assert_ptr_eq(s21_memchr(str, 't', 20), memchr(str, 't', 20));
}

START_TEST(test4) {
  char str[] = "1234567890";
  ck_assert_ptr_eq(s21_memchr(str, '5', 10), memchr(str, '5', 10));
}

START_TEST(test5) {
  char str[] = "abcdefg";
  ck_assert_ptr_eq(s21_memchr(str, 'z', 7), memchr(str, 'z', 7));
}

START_TEST(test6) {
  char str[] = "aaabbbccc";
  ck_assert_ptr_eq(s21_memchr(str, 'b', 9), memchr(str, 'b', 9));
}

START_TEST(test7) {
  char str[] = "abcdefgh";
  ck_assert_ptr_eq(s21_memchr(str, 'z', 8), memchr(str, 'z', 8));
}

START_TEST(test8) {
  char str[] = "abcdef";
  s21_size_t i = 0;
  while (i < 6) {
    ck_assert_ptr_eq(s21_memchr(str, 'd', i), memchr(str, 'd', i));
    i++;
  }
}

START_TEST(test9) {
  char str[] = "abc\0def";
  ck_assert_ptr_eq(s21_memchr(str, '\0', 7), memchr(str, '\0', 7));
}

START_TEST(test10) {
  char str[] = "Hello, world!";
  ck_assert_ptr_eq(s21_memchr(str, 'o', 0), memchr(str, 'o', 0));
}

START_TEST(test11) {
  char str[] = "абвгдеж";
  const char target[] = "в";  // "в" как массив байтов
  ck_assert_ptr_eq(s21_memchr(str, (int)(unsigned char)target[0], 14),
                   memchr(str, (int)(unsigned char)target[0], 14));
}

START_TEST(test12) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_memchr(str, 'z', 6), memchr(str, 'z', 6));
}

START_TEST(test13) {
  char str[] = "";
  ck_assert_ptr_eq(s21_memchr(str, 'a', 1), memchr(str, 'a', 1));
}
Suite *s21_memchr_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_memchr test=-\033[0m");
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