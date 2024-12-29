#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test1) {
  int errnum = 0;
  char* result = s21_strerror(errnum);
  char* original_result = strerror(errnum);
  ck_assert_str_eq(result, original_result);
}

START_TEST(test2) {
  int errnum = 5;
  char* result = s21_strerror(errnum);
  char* original_result = strerror(errnum);
  ck_assert_str_eq(result, original_result);
}

START_TEST(test3) {
  int errnum = 8;
  char* result = s21_strerror(errnum);
  char* original_result = strerror(errnum);
  ck_assert_str_eq(result, original_result);
}

START_TEST(test5) {
  int errnum = 108;
  char* result = s21_strerror(errnum);
  char* original_result = strerror(errnum);
  ck_assert_str_eq(result, original_result);
}

START_TEST(test4) {
  int errnum = -1;
  char* result = s21_strerror(errnum);
  // char* original_result = strerror(errnum);
  ck_assert_str_eq(result, "Unknown error -1");
}

START_TEST(test6) {
  int errnum = 200;
  char* result = s21_strerror(errnum);
  // char* original_result = strerror(errnum);
  ck_assert_str_eq(result, "Unknown error 200");
}

START_TEST(test7) {
  int errnum = 300;
  char* result = s21_strerror(errnum);
  // char* original_result = strerror(errnum); //
  ck_assert_str_eq(result, "Unknown error 300");
}

// START_TEST(test8) {
//   for (int i = 0; i < 133; i++) {
//     char* result = s21_strerror(i);
//     char* original_result = strerror(i);
//     ck_assert_str_eq(result, original_result);
//   }
// }

Suite* s21_strerror_test_suite(void) {
  Suite* s = suite_create("\033[42m-=s21_strerror test=-\033[0m");
  TCase* t = tcase_create("main tcase");

  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  tcase_add_test(t, test4);
  tcase_add_test(t, test5);
  tcase_add_test(t, test6);
  tcase_add_test(t, test7);
  // tcase_add_test(t, test8);
  suite_add_tcase(s, t);

  return s;
}
