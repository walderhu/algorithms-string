#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char str[] = "Owl lived in a tall tree in the forest.";
  char sub_str[] = "tree";
  ck_assert_str_eq(s21_strstr(str, sub_str), strstr(str, sub_str));
}

START_TEST(test2) {
  char str[] = "Owl lived in a tall tree in the forest.";
  char sub_str[] = "Owl ";
  ck_assert_str_eq(s21_strstr(str, sub_str), strstr(str, sub_str));
}

START_TEST(test3) {
  char str[] = "";
  char sub_str[] = "tree";
  ck_assert_pstr_eq(s21_strstr(str, sub_str), strstr(str, sub_str));
}

START_TEST(test4) {
  char str[] = "Owl lived in a tall tree in the forest.";
  char sub_str[] = "forest.";
  ck_assert_str_eq(s21_strstr(str, sub_str), strstr(str, sub_str));
}

START_TEST(test5) {
  char str[] = "Owl lived in a tall tree in the forest.";
  char sub_str[] = "forest...";
  ck_assert_pstr_eq(s21_strstr(str, sub_str), strstr(str, sub_str));
  ck_assert_ptr_null(s21_strstr(str, sub_str));
  ck_assert_ptr_null(strstr(str, sub_str));
}

START_TEST(test7) {
  char str[] = "Owl lived in a lall tree in the forest.";
  char sub_str[] = "l";
  ck_assert_pstr_eq(s21_strstr(str, sub_str), strstr(str, sub_str));
}

Suite *s21_strstr_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_strstr test=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  tcase_add_test(t, test4);
  tcase_add_test(t, test5);
  tcase_add_test(t, test7);
  suite_add_tcase(s, t);
  return s;
}