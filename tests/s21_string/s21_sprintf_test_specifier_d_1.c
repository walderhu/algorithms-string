#include "../../src/s21_string.h"
#include "../s21_string_test.h"

/*Specifier d Table 1*/
START_TEST(test1) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I'm %d years old", 37);
  sprintf(buffer2, "I'm %d years old", 37);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test2) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I'm %8d years old", 37);
  sprintf(buffer2, "I'm %8d years old", 37);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test3) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %-8d years old", 37);
  sprintf(buffer2, "I'm %-8d years old", 37);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test4) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %+d years old", 37);
  sprintf(buffer2, "I'm %+d years old", 37);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test5) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %+8d years old", 37);
  sprintf(buffer2, "I'm %+8d years old", 37);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test6) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %-+8d years old", 37);
  sprintf(buffer2, "I'm %-+8d years old", 37);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test7) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm % d years old", 8192);
  sprintf(buffer2, "I'm % d years old", 8192);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test8) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm % 8d years old", 8192);
  sprintf(buffer2, "I'm % 8d years old", 8192);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test9) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %- 8d years old", 8192);
  sprintf(buffer2, "I'm %- 8d years old", 8192);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test10) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %0d years old", 8192);
  sprintf(buffer2, "I'm %0d years old", 8192);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test11) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %08d years old", 8192);
  sprintf(buffer2, "I'm %08d years old", 8192);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test12) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %+0d years old", 16384);
  sprintf(buffer2, "I'm %+0d years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test13) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%+0d| years old", 16384);
  sprintf(buffer2, "I'm |%+0d| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test14) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%+08d| years old", 16384);
  sprintf(buffer2, "I'm |%+08d| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test15) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%+016d| years old", 16384);
  sprintf(buffer2, "I'm |%+016d| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test16) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |% 0d| years old", 16384);
  sprintf(buffer2, "I'm |% 0d| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test17) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |% 08d| years old", 16384);
  sprintf(buffer2, "I'm |% 08d| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test18) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |% 016d| years old", 16384);
  sprintf(buffer2, "I'm |% 016d| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test19) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |% 010d| years old", -16384);
  sprintf(buffer2, "I'm |% 010d| years old", -16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test20) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-16d| years old", -16384);
  sprintf(buffer2, "I'm |%-16d| years old", -16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test21) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |% d| years old", -16384);
  sprintf(buffer2, "I'm |% d| years old", -16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test22) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |% 10d| years old", -16384);
  sprintf(buffer2, "I'm |% 10d| years old", -16384);
  ck_assert_str_eq(buffer1, buffer2);
}

Suite *s21_sprintf_test_suite_specifier_d_1() {
  Suite *s = suite_create("\033[42m-=s21_sprintf test specifier d 1=-\033[0m");
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
  tcase_add_test(t, test14);
  tcase_add_test(t, test15);
  tcase_add_test(t, test16);
  tcase_add_test(t, test17);
  tcase_add_test(t, test18);
  tcase_add_test(t, test19);
  tcase_add_test(t, test20);
  tcase_add_test(t, test21);
  tcase_add_test(t, test22);

  suite_add_tcase(s, t);
  return s;
}