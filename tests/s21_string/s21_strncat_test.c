#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  char sdest[50] = "cat";
  char sdest2[50] = "cat";
  char ssrc[] = "0,1,2,3";

  s21_strncat(sdest, ssrc, 7);
  strncat(sdest2, ssrc, 7);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test2) {
  char sdest[50] = "strncat";
  char sdest2[50] = "strncat";
  char ssrc[] = "3,2,1,0";

  s21_strncat(sdest, ssrc, 20);
  strncat(sdest2, ssrc, 20);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test3) {
  char sdest[100] = "str";
  char sdest2[100] = "str";
  char ssrc[] = "catcat";

  s21_strncat(sdest, ssrc, 10);
  strncat(sdest2, ssrc, 10);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test4) {
  char sdest[50] = "function";
  char sdest2[50] = "function";
  char ssrc[] = "strncat";

  s21_strncat(sdest, ssrc, 49);
  strncat(sdest2, ssrc, 49);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test5) {
  char sdest[50] = "=4";
  char sdest2[50] = "=4";
  char ssrc[] = "2+2";

  s21_strncat(sdest, ssrc, 10);
  strncat(sdest2, ssrc, 10);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test6) {
  char sdest[30] = "---";
  char sdest2[30] = "---";
  char ssrc[] = "здесь тире";

  s21_strncat(sdest, ssrc, 20);
  strncat(sdest2, ssrc, 20);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test7) {
  char sdest[100] = " ";
  char sdest2[100] = " ";
  char ssrc[] = "catcat";

  s21_strncat(sdest, ssrc, 50);
  strncat(sdest2, ssrc, 50);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test8) {
  char sdest[100] = "(function)";
  char sdest2[100] = "(function)";
  char ssrc[] = "=strncat";

  s21_strncat(sdest, ssrc, 90);
  strncat(sdest2, ssrc, 90);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test9) {
  char sdest[100] = "     ";
  char sdest2[100] = "     ";
  char ssrc[] = "табуляция";

  s21_strncat(sdest, ssrc, 50);
  strncat(sdest2, ssrc, 50);
  ck_assert_str_eq(sdest, sdest2);
}

START_TEST(test10) {
  char sdest[100] = ",78№%,),^";
  char sdest2[100] = ",78№%,),^";
  char ssrc[] = "символы";

  s21_strncat(sdest, ssrc, 90);
  strncat(sdest2, ssrc, 90);
  ck_assert_str_eq(sdest, sdest2);
}

Suite *s21_strncat_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_strncat test=-\033[0m");
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
