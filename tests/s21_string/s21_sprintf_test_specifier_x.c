#include "../../src/s21_string.h"
#include "../s21_string_test.h"

/*specifiers x*/
START_TEST(test1) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%x| years old", 16384);
  sprintf(buffer2, "I'm |%x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test2) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%x| years old", 123456789);
  sprintf(buffer2, "I'm |%x| years old", 123456789);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test3) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%lx| years old", 5124095576030430L);
  sprintf(buffer2, "I'm |%lx| years old", 5124095576030430L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test4) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%lX| years old", 5124095576030430L);
  sprintf(buffer2, "I'm |%lX| years old", 5124095576030430L);
  ck_assert_str_eq(buffer1, buffer2);
}

Suite *s21_sprintf_test_suite_specifier_x() {
  Suite *s = suite_create("\033[42m-=s21_sprintf test specifier x=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  tcase_add_test(t, test4);
  suite_add_tcase(s, t);
  return s;
}