#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char sstr1[] = "12345";
  char sstr2[] = "34";

  s21_size_t res = s21_strcspn(sstr1, sstr2);
  s21_size_t res2 = strcspn(sstr1, sstr2);

  ck_assert_int_eq(res, res2);
}

START_TEST(test2) {
  char sstr1[] = "12345";
  char sstr2[] = "12";

  s21_size_t res = s21_strcspn(sstr1, sstr2);
  s21_size_t res2 = strcspn(sstr1, sstr2);

  ck_assert_int_eq(res, res2);
}

START_TEST(test3) {
  char sstr1[] = "12345";
  char sstr2[] = "57";

  s21_size_t res = s21_strcspn(sstr1, sstr2);
  s21_size_t res2 = strcspn(sstr1, sstr2);

  ck_assert_int_eq(res, res2);
}

START_TEST(test4) {
  char sstr1[] = "57";
  char sstr2[] = "57";

  s21_size_t res = s21_strcspn(sstr1, sstr2);
  s21_size_t res2 = strcspn(sstr1, sstr2);

  ck_assert_int_eq(res, res2);
}

START_TEST(test5) {
  char sstr1[] = "057";
  char sstr2[] = "570";

  s21_size_t res = s21_strcspn(sstr1, sstr2);
  s21_size_t res2 = strcspn(sstr1, sstr2);

  ck_assert_int_eq(res, res2);
}

START_TEST(test6) {
  char sstr1[] = "hello";
  char sstr2[] = "lo";

  s21_size_t res = s21_strcspn(sstr1, sstr2);
  s21_size_t res2 = strcspn(sstr1, sstr2);

  ck_assert_int_eq(res, res2);
}

START_TEST(test7) {
  char sstr1[] = "hello";
  char sstr2[] = "ello";

  s21_size_t res = s21_strcspn(sstr1, sstr2);
  s21_size_t res2 = strcspn(sstr1, sstr2);

  ck_assert_int_eq(res, res2);
}

START_TEST(test8) {
  char sstr1[] = "12hello";
  char sstr2[] = "ello";

  s21_size_t res = s21_strcspn(sstr1, sstr2);
  s21_size_t res2 = strcspn(sstr1, sstr2);

  ck_assert_int_eq(res, res2);
}

START_TEST(test9) {
  char sstr1[] = "321";
  char sstr2[] = "12";

  s21_size_t res = s21_strcspn(sstr1, sstr2);
  s21_size_t res2 = strcspn(sstr1, sstr2);

  ck_assert_int_eq(res, res2);
}

START_TEST(test10) {
  char sstr1[] = "321";
  char sstr2[] = "172";

  s21_size_t res = s21_strcspn(sstr1, sstr2);
  s21_size_t res2 = strcspn(sstr1, sstr2);

  ck_assert_int_eq(res, res2);
}

Suite *s21_strcspn_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_strcspn test=-\033[0m");
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
