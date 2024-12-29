#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char *sstr = "hello";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "HELLO");
  free(result);
}

START_TEST(test2) {
  char *sstr = "hello world";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "HELLO WORLD");
  free(result);
}

START_TEST(test3) {
  char *sstr = "hello world!!";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "HELLO WORLD!!");
  free(result);
}

START_TEST(test4) {
  char *sstr = "hello)(%world!!!";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "HELLO)(%WORLD!!!");
  free(result);
}

START_TEST(test5) {
  char *sstr = "hellooo";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "HELLOOO");
  free(result);
}

START_TEST(test6) {
  char *sstr = "upperTO";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "UPPERTO");
  free(result);
}

START_TEST(test7) {
  char *sstr = "123upperTO";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "123UPPERTO");
  free(result);
}

START_TEST(test8) {
  char *sstr = "123";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "123");
  free(result);
}

START_TEST(test9) {
  char *sstr = "upper123";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "UPPER123");
  free(result);
}

START_TEST(test10) {
  char *sstr = "098765";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "098765");
  free(result);
}

START_TEST(test11) {
  char *sstr = "1234567890qwertyuiop[]\';lkjhgfdsazxcvbnm,./";
  char *result = s21_to_upper(sstr);
  ck_assert_str_eq(result, "1234567890QWERTYUIOP[]\';LKJHGFDSAZXCVBNM,./");
  free(result);
}

Suite *s21_to_upper_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_to_upper test=-\033[0m");
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
