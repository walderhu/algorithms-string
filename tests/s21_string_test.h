#ifndef S21_STRING_TEST_H
#define S21_STRING_TEST_H

#include <check.h>
#include <stdio.h>
#include <string.h>
#include "../src/s21_string.h"

int run_testcase(Suite *testcase);
void run_tests(void);

Suite *s21_memchr_test_suite(); //1
Suite *s21_memset_test_suite(); //2
Suite *s21_strchr_test_suite(); //3
Suite *s21_strrchr_test_suite();
Suite *s21_strlen_test_suite(); //4
Suite *s21_strncpy_test_suite(); //5
Suite *s21_strpbrk_test_suite(); //6
Suite *s21_strstr_test_suite(); //7
Suite *s21_trim_test_suite(); //8

Suite *s21_memcpy_test_suite();
Suite *s21_strcspn_test_suite();
Suite *s21_strncat_test_suite();
Suite *s21_to_lower_test_suite();
Suite *s21_to_upper_test_suite();

Suite *s21_memcmp_test_suite();
Suite *s21_strncmp_test_suite();
Suite *s21_strerror_test_suite();
Suite *s21_strtok_test_suite();
Suite *s21_insert_test_suite();

Suite *s21_strcpy_test_suite();
Suite *s21_strcat_test_suite();

Suite *s21_sprintf_test_suite();
Suite *s21_sprintf_test_suite_specifier_s();
Suite *s21_sprintf_test_suite_specifier_u();
Suite *s21_sprintf_test_suite_specifier_g();
Suite *s21_sprintf_test_suite_specifier_g_2();
Suite *s21_sprintf_test_suite_specifier_g_3();
Suite *s21_sprintf_test_suite_specifier_g_4();
Suite *s21_sprintf_test_suite_specifier_g_5();
Suite *s21_sprintf_test_suite_specifier_g_6();
Suite *s21_sprintf_test_suite_specifier_g_7();
Suite *s21_sprintf_test_suite_specifier_d_1();
Suite *s21_sprintf_test_suite_specifier_d_2();
Suite *s21_sprintf_test_suite_specifier_d_3();
Suite *s21_sprintf_test_suite_specifier_f_1();
Suite *s21_sprintf_test_suite_specifier_f_2();
Suite *s21_sprintf_test_suite_specifier_f_3();
Suite *s21_sprintf_test_suite_specifier_f_4();
Suite *s21_sprintf_test_suite_specifier_f_5();
Suite *s21_sprintf_test_suite_specifier_e_1();
Suite *s21_sprintf_test_suite_specifier_e_2();
Suite *s21_sprintf_test_suite_specifier_e_3();
Suite *s21_sprintf_test_suite_specifier_e_4();
Suite *s21_sprintf_test_suite_specifier_e_5();
Suite *s21_sprintf_test_suite_specifier_e_6();
Suite *s21_sprintf_test_suite_specifier_e_7();
Suite *s21_sprintf_test_suite_specifier_e_8();
Suite *s21_sprintf_test_suite_specifier_e_9();
Suite *s21_sprintf_test_suite_specifier_x();
Suite *s21_sprintf_test_suite_specifier_x_2();
Suite *s21_sprintf_test_suite_specifier_o();
Suite *s21_sprintf_test_suite_specifier_o_2();
Suite *s21_sprintf_test_suite_specifier_p();

Suite *s21_scanf_test_suite();

#endif
