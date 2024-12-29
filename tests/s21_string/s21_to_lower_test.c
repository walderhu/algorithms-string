#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char *sstr = "HELLO";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "hello");
  free(result);
}

START_TEST(test2) {
  char *sstr = "HELLOWORLD";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "helloworld");
  free(result);
}

START_TEST(test3) {
  char *sstr = "HELLO WORLD!!!";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "hello world!!!");
  free(result);
}

START_TEST(test4) {
  char *sstr = "HELLO)(%WORLD!!!";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "hello)(%world!!!");
  free(result);
}

START_TEST(test5) {
  char *sstr = "hellooo";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "hellooo");
  free(result);
}

START_TEST(test6) {
  char *sstr = "lowerTO";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "lowerto");
  free(result);
}

START_TEST(test7) {
  char *sstr = "123lowerTO";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "123lowerto");
  free(result);
}

START_TEST(test8) {
  char *sstr = "123";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "123");
  free(result);
}

START_TEST(test9) {
  char *sstr = "LOWER123";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "lower123");
  free(result);
}

START_TEST(test10) {
  char *sstr = "098765";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "098765");
  free(result);
}

START_TEST(test11) {
  char *sstr = "1234567890QWERTYUIOP[]\';LKJHGFDSAZXCVBNM,./";
  char *result = s21_to_lower(sstr);
  ck_assert_str_eq(result, "1234567890qwertyuiop[]\';lkjhgfdsazxcvbnm,./");
  free(result);
}

Suite *s21_to_lower_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_to_lower test=-\033[0m");
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
