#include "../../src/s21_string.h"
#include "../s21_string_test.h"

/*specifiers s*/
START_TEST(test1) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %s, How are you?", "Alek");
  sprintf(buffer2, "Hello %s, How are you?", "Alek");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test2) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %10s, How are you?", "Alek");
  sprintf(buffer2, "Hello %10s, How are you?", "Alek");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test3) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %-10s, How are you?", "Alek");
  sprintf(buffer2, "Hello %-10s, How are you?", "Alek");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test4) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %.2s, How are you?", "Alek");
  sprintf(buffer2, "Hello %.2s, How are you?", "Alek");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test5) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %10.2s, How are you?", "Alek");
  sprintf(buffer2, "Hello %10.2s, How are you?", "Alek");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test6) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %-10.2s, How are you?", "Alek");
  sprintf(buffer2, "Hello %-10.2s, How are you?", "Alek");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test7) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %*s, How are you?", 10, "Alek");
  sprintf(buffer2, "Hello %*s, How are you?", 10, "Alek");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test8) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %-*s, How are you?", 10, "Alek");
  sprintf(buffer2, "Hello %-*s, How are you?", 10, "Alek");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test9) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %.*s, How are you?", 3, "Alek");
  sprintf(buffer2, "Hello %.*s, How are you?", 3, "Alek");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test10) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %*.*s, How are you?", 10, 2, "Alek");
  sprintf(buffer2, "Hello %*.*s, How are you?", 10, 2, "Alek");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test11) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %-*.*s, How are you?", 10, 2, "Alek");
  sprintf(buffer2, "Hello %-*.*s, How are you?", 10, 2, "Alek");
  ck_assert_str_eq(buffer1, buffer2);
}

Suite *s21_sprintf_test_suite_specifier_s() {
  Suite *s = suite_create("\033[42m-=s21_sprintf test specifier s=-\033[0m");
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
  suite_add_tcase(s, t);
  return s;
}