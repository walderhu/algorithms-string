#include "../../src/s21_string.h"
#include "../s21_string_test.h"

/*
common simple tests
*/

START_TEST(test1) {
  char buffer[8000] = {0};
  s21_sprintf(buffer, "Hello %s, I'm %d years old", "Alek", 37);
  ck_assert_str_eq(buffer, "Hello Alek, I'm 37 years old");
}

/*
increase_width_or_precision tests
*/

START_TEST(test2) {
  pattern test_pattern;
  int stage = 1;
  test_pattern.width = 7;
  increase_width_or_precision(&test_pattern, 8, stage);
  increase_width_or_precision(&test_pattern, 9, stage);
  ck_assert_int_eq(test_pattern.width, 789);
}

START_TEST(test3) {
  pattern test_pattern;
  int stage = 1;
  test_pattern.width = 0;
  increase_width_or_precision(&test_pattern, 8, stage);
  increase_width_or_precision(&test_pattern, 9, stage);
  ck_assert_int_eq(test_pattern.width, 89);
}

START_TEST(test4) {
  pattern test_pattern;
  int stage = 2;
  test_pattern.precision = 5;
  increase_width_or_precision(&test_pattern, 6, stage);
  increase_width_or_precision(&test_pattern, 7, stage);
  ck_assert_int_eq(test_pattern.precision, 567);
}

START_TEST(test5) {
  pattern test_pattern;
  int stage = 2;
  test_pattern.precision = 0;
  increase_width_or_precision(&test_pattern, 0, stage);
  increase_width_or_precision(&test_pattern, 1, stage);
  ck_assert_int_eq(test_pattern.precision, 1);
}

START_TEST(test6) {
  pattern test_pattern;
  int stage = 2;
  test_pattern.precision = 0;
  increase_width_or_precision(&test_pattern, 1, stage);
  increase_width_or_precision(&test_pattern, 0, stage);
  increase_width_or_precision(&test_pattern, 7, stage);
  ck_assert_int_eq(test_pattern.precision, 107);
}

START_TEST(test7) {
  pattern test_pattern;
  int stage = 2;
  test_pattern.precision = 0;
  increase_width_or_precision(&test_pattern, '1' - 48, stage);
  increase_width_or_precision(&test_pattern, '0' - 48, stage);
  increase_width_or_precision(&test_pattern, '7' - 48, stage);
  ck_assert_int_eq(test_pattern.precision, 107);
}

START_TEST(test8) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %s, I'm %d years old", "Alek", 37);
  sprintf(buffer2, "Hello %s, I'm %d years old", "Alek", 37);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test9) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %10s, I'm %d years old", "Alek", 37);
  sprintf(buffer2, "Hello %10s, I'm %d years old", "Alek", 37);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test10) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %-10s, I'm %d years old", "Alek", 37);
  sprintf(buffer2, "Hello %-10s, I'm %d years old", "Alek", 37);
  ck_assert_str_eq(buffer1, buffer2);
}

/*TDD TESTS*/
/*specifiers %*/
START_TEST(test17) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %%, How are you?");
  sprintf(buffer2, "Hello %%, How are you?");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test18) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "%%, How are you?");
  sprintf(buffer2, "%%, How are you?");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test19) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %%");
  sprintf(buffer2, "Hello %%");
  ck_assert_str_eq(buffer1, buffer2);
}

/*specifiers с*/
START_TEST(test20) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %c, How are you?", 'A');
  sprintf(buffer2, "Hello %c, How are you?", 'A');
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test21) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %12c, How are you?", 'A');
  sprintf(buffer2, "Hello %12c, How are you?", 'A');
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test22) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Hello %-12c, How are you?", 'A');
  sprintf(buffer2, "Hello %-12c, How are you?", 'A');
  ck_assert_str_eq(buffer1, buffer2);
}

// get_left_numbers_counter tests

START_TEST(test23) {
  double num1 = 321;
  ck_assert_int_eq(get_left_numbers_counter(num1), 3);
}

START_TEST(test24) {
  double num1 = 0;
  ck_assert_int_eq(get_left_numbers_counter(num1), 0);
}

START_TEST(test25) {
  double num1 = 1;
  ck_assert_int_eq(get_left_numbers_counter(num1), 1);
}

START_TEST(test26) {
  double num1 = -1;
  ck_assert_int_eq(get_left_numbers_counter(num1), 1);
}

START_TEST(test27) {
  double num1 = 1234567890;
  ck_assert_int_eq(get_left_numbers_counter(num1), 10);
}

// generate_simple_e_number test

START_TEST(test28_1) {
  double num1 = 123.321;
  char sign[2] = {'\0'};
  int distance = 0;
  ck_assert_double_le(generate_simple_e_number(num1, sign, &distance) - 1.23321,
                      0.0000000001);
}

START_TEST(test28_2) {
  double num1 = 123.321;
  char sign[2] = {'\0'};
  int distance = 0;
  generate_simple_e_number(num1, sign, &distance);
  ck_assert_str_eq(sign, "+");
}

START_TEST(test28_3) {
  double num1 = 123.321;
  char sign[2] = {'\0'};
  int distance = 0;
  generate_simple_e_number(num1, sign, &distance);
  ck_assert_int_eq(distance, 2);
}

START_TEST(test29) {
  double num1 = 12.1234567;
  char sign[2] = {'\0'};
  int distance = 0;
  ck_assert_double_eq(generate_simple_e_number(num1, sign, &distance),
                      1.21234567);
  ck_assert_str_eq(sign, "+");
  ck_assert_int_eq(distance, 1);
}

START_TEST(test30) {
  double num1 = 1234567.000001;
  char sign[2] = {'\0'};
  int distance = 0;
  ck_assert_double_le(
      generate_simple_e_number(num1, sign, &distance) - 1.234567000001,
      0.000000000000001);
  ck_assert_str_eq(sign, "+");
  ck_assert_int_eq(distance, 6);
}

START_TEST(test31) {
  double num1 = 0.01234;
  char sign[2] = {'\0'};
  int distance = 0;
  ck_assert_double_eq(generate_simple_e_number(num1, sign, &distance), 1.234);
  ck_assert_str_eq(sign, "-");
  ck_assert_int_eq(distance, 2);
}

// Sprintf counter returned test
START_TEST(test32) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  int a = s21_sprintf(buffer1, "Hello %s", " Alek");
  int b = sprintf(buffer2, "Hello %s", " Alek");
  ck_assert_int_eq(a, b);
}

START_TEST(test33) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  int a = s21_sprintf(
      buffer1, "Hello %s your age is %-5d, your wallet have %5.2f dollars",
      " Alek", 37, 1234.56789);
  int b = sprintf(buffer2,
                  "Hello %s your age is %-5d, your wallet have %5.2f dollars",
                  " Alek", 37, 1234.56789);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test34) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  int a = s21_sprintf(buffer1, " ");
  int b = sprintf(buffer2, " ");
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(buffer1, buffer2);
}

Suite *s21_sprintf_test_suite() {
  Suite *s =
      suite_create("\033[42m-=s21_sprintf test specifiers: % c=-\033[0m");
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
  tcase_add_test(t, test17);
  tcase_add_test(t, test18);
  tcase_add_test(t, test19);
  tcase_add_test(t, test20);
  tcase_add_test(t, test21);
  tcase_add_test(t, test22);
  tcase_add_test(t, test23);
  tcase_add_test(t, test24);
  tcase_add_test(t, test25);
  tcase_add_test(t, test26);
  tcase_add_test(t, test27);
  tcase_add_test(t, test28_1);
  tcase_add_test(t, test28_2);
  tcase_add_test(t, test28_3);
  tcase_add_test(t, test29);
  tcase_add_test(t, test30);
  tcase_add_test(t, test31);
  tcase_add_test(t, test32);
  tcase_add_test(t, test33);
  tcase_add_test(t, test34);
  suite_add_tcase(s, t);
  return s;
}
