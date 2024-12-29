#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char sdest[70] = {0};
  char sdest2[70] = {0};
  const char *ssrc = "0,1,2,3";

  s21_memcpy(sdest, ssrc, 7);
  memcpy(sdest2, ssrc, 7);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test2) {
  char sdest[50];
  char sdest2[50];
  const char *ssrc = "Hello";

  s21_memcpy(sdest, ssrc, 50);
  memcpy(sdest2, ssrc, 50);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test3) {
  char sdest[70];
  char sdest2[70];
  const char *ssrc = " ";

  s21_memcpy(sdest, ssrc, 7);
  memcpy(sdest2, ssrc, 7);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test4) {
  char sdest[5];
  char sdest2[5];
  const char *ssrc = "12";

  s21_memcpy(sdest, ssrc, 5);
  memcpy(sdest2, ssrc, 5);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test5) {
  char sdest[70] = {0};
  char sdest2[70] = {0};
  const char *ssrc = "Memcpy123";

  s21_memcpy(sdest, ssrc, 7);
  memcpy(sdest2, ssrc, 7);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test6) {
  char sdest[50];
  char sdest2[50];
  const char *ssrc = "(=)";

  s21_memcpy(sdest, ssrc, 5);
  memcpy(sdest2, ssrc, 5);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test7) {
  char sdest[100];
  char sdest2[100];
  const char *ssrc = "000 111";

  s21_memcpy(sdest, ssrc, 100);
  memcpy(sdest2, ssrc, 100);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test8) {
  char sdest[70];
  char sdest2[70];
  const char *ssrc = "...";

  s21_memcpy(sdest, ssrc, 7);
  memcpy(sdest2, ssrc, 7);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test9) {
  char sdest[50];
  char sdest2[50];
  const char *ssrc = "(0)";

  s21_memcpy(sdest, ssrc, 5);
  memcpy(sdest2, ssrc, 5);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test10) {
  char sdest[10];
  char sdest2[10];
  const char *ssrc = "1";

  s21_memcpy(sdest, ssrc, 10);
  memcpy(sdest2, ssrc, 10);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test11) {
  const int ssrc[] = {1, 2, 3, 4, 5};
  int n = sizeof(ssrc) / sizeof(ssrc[0]);

  int sdest[n];
  int sdest2[n];

  s21_memcpy(sdest, ssrc, sizeof(ssrc));
  memcpy(sdest2, ssrc, sizeof(ssrc));

  for (int i = 0; i < n; i++) ck_assert_int_eq(sdest[i], sdest2[i]);
}

Suite *s21_memcpy_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_memcpy test=-\033[0m");
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
