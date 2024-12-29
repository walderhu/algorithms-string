#include "s21_string_test.h"

int main(void) {
  run_tests();
  return 0;
}

int run_testcase(Suite *testcase) {
  int result = 1;
  static int counter_testcase = 1;
  if (counter_testcase > 1) counter_testcase++;
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  result = srunner_ntests_failed(sr);
  srunner_free(sr);
  return result;
}

void run_tests(void) {
  Suite *list_cases[] = {s21_memchr_test_suite(),    // 1
                         s21_memcmp_test_suite(),    // 2
                         s21_memcpy_test_suite(),    // 3
                         s21_memset_test_suite(),    // 4
                         s21_strncat_test_suite(),   // 5
                         s21_strchr_test_suite(),    // 6
                         s21_strncmp_test_suite(),   // 7
                         s21_strncpy_test_suite(),   // 8
                         s21_strcspn_test_suite(),   // 9
                         s21_strerror_test_suite(),  // 10
                         s21_strlen_test_suite(),    // 11
                         s21_strpbrk_test_suite(),   // 12
                         s21_strrchr_test_suite(),   // 13
                         s21_strstr_test_suite(),    // 14
                         s21_strtok_test_suite(),    // 15
                         s21_to_upper_test_suite(),  //с# 1
                         s21_to_lower_test_suite(),  // c# 2
                         s21_insert_test_suite(),    // c# 3
                         s21_trim_test_suite(),      // c# 4
                         s21_strcpy_test_suite(),    // additional 1
                         s21_strcat_test_suite(),    // additional 2
                         s21_sprintf_test_suite(),
                         s21_sprintf_test_suite_specifier_s(),
                         s21_sprintf_test_suite_specifier_u(),
                         s21_sprintf_test_suite_specifier_d_1(),
                         s21_sprintf_test_suite_specifier_d_2(),
                         s21_sprintf_test_suite_specifier_d_3(),
                         s21_sprintf_test_suite_specifier_f_1(),
                         s21_sprintf_test_suite_specifier_f_2(),
                         s21_sprintf_test_suite_specifier_f_3(),
                         s21_sprintf_test_suite_specifier_f_4(),
                         s21_sprintf_test_suite_specifier_f_5(),
                         s21_sprintf_test_suite_specifier_e_1(),
                         s21_sprintf_test_suite_specifier_e_2(),
                         s21_sprintf_test_suite_specifier_e_3(),
                         s21_sprintf_test_suite_specifier_e_4(),
                         s21_sprintf_test_suite_specifier_e_5(),
                         s21_sprintf_test_suite_specifier_e_6(),
                         s21_sprintf_test_suite_specifier_e_7(),
                         s21_sprintf_test_suite_specifier_e_8(),
                         s21_sprintf_test_suite_specifier_e_9(),
                         s21_sprintf_test_suite_specifier_g(),
                         s21_sprintf_test_suite_specifier_g_2(),
                         s21_sprintf_test_suite_specifier_g_3(),
                         s21_sprintf_test_suite_specifier_g_4(),
                         s21_sprintf_test_suite_specifier_g_5(),
                         s21_sprintf_test_suite_specifier_g_6(),
                         s21_sprintf_test_suite_specifier_g_7(),
                         s21_sprintf_test_suite_specifier_x(),
                         s21_sprintf_test_suite_specifier_x_2(),
                         s21_sprintf_test_suite_specifier_o(),
                         s21_sprintf_test_suite_specifier_o_2(),
                         s21_sprintf_test_suite_specifier_p(),
                         s21_scanf_test_suite(),
                         NULL};
  int number_failed = 0;
  int number_success = 0;
  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    if (run_testcase(*current_testcase) != 0)
      number_failed++;
    else
      number_success++;
  }
  printf("\e[32mSuccess: %d\e[0m\n\e[31mFailures: %d\e[0m\n", number_success,
         number_failed);
}