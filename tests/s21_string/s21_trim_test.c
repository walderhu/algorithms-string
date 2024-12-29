#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  const char *test_str = "+++Hello World!!!";
  const char *trim_chars = "+!";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "Hello World");
  free(trimmed);
}

START_TEST(test2) {
  const char *test_str = "d29d27";
  const char *trim_chars = "";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "d29d27");
  free(trimmed);
}

START_TEST(test3) {
  const char *test_str = "5v7,.Di3d dyry.:,5,";
  const char *trim_chars = "5,";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "v7,.Di3d dyry.:");
  free(trimmed);
}

START_TEST(test4) {
  const char *test_str = "115.:,32ref3d  ";
  const char *trim_chars = " 1.";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "5.:,32ref3d");
  free(trimmed);
}

START_TEST(test5) {
  const char *trim_chars = "+!";

  char *trimmed = s21_trim(s21_NULL, trim_chars);
  ck_assert_ptr_eq(trimmed, s21_NULL);
}

START_TEST(test6) {
  const char *test_str = "";
  const char *trim_chars = "+!";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "");
  free(trimmed);
}

START_TEST(test7) {
  const char *test_str = "Hello World";
  const char *trim_chars = "";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "Hello World");
  free(trimmed);
}

START_TEST(test8) {
  const char *test_str = "   Hello World   ";
  const char *trim_chars = " ";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "Hello World");
  free(trimmed);
}

START_TEST(test9) {
  const char *test_str = "+++!!!";
  const char *trim_chars = "+!";

  char *trimmed = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(trimmed, "");
  free(trimmed);
}

START_TEST(test10) {
  const char *test_str = "Hello World";

  char *trimmed = s21_trim(test_str, s21_NULL);
  ck_assert_ptr_eq(trimmed, s21_NULL);
}

Suite *s21_trim_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_trim test=-\033[0m");
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
  suite_add_tcase(s, t);
  return s;
}