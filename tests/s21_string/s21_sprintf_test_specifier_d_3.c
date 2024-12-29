#include "../../src/s21_string.h"
#include "../s21_string_test.h"

/*Specifier d Table 3*/
/*Legth h*/
START_TEST(test1) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = 12800;
  s21_sprintf(buffer1, "I'm %hd years old", x);
  sprintf(buffer2, "I'm %hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test2) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = -12800;
  s21_sprintf(buffer1, "I'm %hd years old", x);
  sprintf(buffer2, "I'm %hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test3) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = 26000;
  s21_sprintf(buffer1, "I'm %hd years old", x);
  sprintf(buffer2, "I'm %hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test4) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = -26000;
  s21_sprintf(buffer1, "I'm %hd years old", x);
  sprintf(buffer2, "I'm %hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test5) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = 12800;
  s21_sprintf(buffer1, "I'm %+hd years old", x);
  sprintf(buffer2, "I'm %+hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test6) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = -12800;
  s21_sprintf(buffer1, "I'm %+hd years old", x);
  sprintf(buffer2, "I'm %+hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test7) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = 12800;
  s21_sprintf(buffer1, "I'm % hd years old", x);
  sprintf(buffer2, "I'm % hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test8) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = -12800;
  s21_sprintf(buffer1, "I'm % hd years old", x);
  sprintf(buffer2, "I'm % hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test9) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = 12800;
  s21_sprintf(buffer1, "I'm %0hd years old", x);
  sprintf(buffer2, "I'm %0hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test10) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = -12800;
  s21_sprintf(buffer1, "I'm %0hd years old", x);
  sprintf(buffer2, "I'm %0hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test11) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = 12800;
  s21_sprintf(buffer1, "I'm %+0hd years old", x);
  sprintf(buffer2, "I'm %+0hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test12) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = -12800;
  s21_sprintf(buffer1, "I'm %+0hd years old", x);
  sprintf(buffer2, "I'm %+0hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test13) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = 12800;
  s21_sprintf(buffer1, "I'm %12hd years old", x);
  sprintf(buffer2, "I'm %12hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test14) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = -12800;
  s21_sprintf(buffer1, "I'm %12hd years old", x);
  sprintf(buffer2, "I'm %12hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test15) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = 26000;
  s21_sprintf(buffer1, "I'm %12hd years old", x);
  sprintf(buffer2, "I'm %12hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test16) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = -26000;
  s21_sprintf(buffer1, "I'm %12hd years old", x);
  sprintf(buffer2, "I'm %12hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test17) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = 12800;
  s21_sprintf(buffer1, "I'm %+12hd years old", x);
  sprintf(buffer2, "I'm %+12hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test18) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = -12800;
  s21_sprintf(buffer1, "I'm %+12hd years old", x);
  sprintf(buffer2, "I'm %+12hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test19) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = 12800;
  s21_sprintf(buffer1, "I'm % 12hd years old", x);
  sprintf(buffer2, "I'm % 12hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test20) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = -12800;
  s21_sprintf(buffer1, "I'm % 12hd years old", x);
  sprintf(buffer2, "I'm % 12hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test21) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = 12800;
  s21_sprintf(buffer1, "I'm %012hd years old", x);
  sprintf(buffer2, "I'm %012hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test22) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = -12800;
  s21_sprintf(buffer1, "I'm %012hd years old", x);
  sprintf(buffer2, "I'm %012hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test23) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = 12800;
  s21_sprintf(buffer1, "I'm %+012hd years old", x);
  sprintf(buffer2, "I'm %+012hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test24) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = -12800;
  s21_sprintf(buffer1, "I'm %+012hd years old", x);
  sprintf(buffer2, "I'm %+012hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test25) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = 12800;
  s21_sprintf(buffer1, "I'm %+-12hd years old", x);
  sprintf(buffer2, "I'm %+-12hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test26) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  short x = -12800;
  s21_sprintf(buffer1, "I'm %+-12hd years old", x);
  sprintf(buffer2, "I'm %+-12hd years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

/*Legth l*/

START_TEST(test27) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %ld years old", 12800L);
  sprintf(buffer2, "I'm %ld years old", 12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test28) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %ld years old", -12800L);
  sprintf(buffer2, "I'm %ld years old", -12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test29) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %ld years old", 8223372036854775807L);
  sprintf(buffer2, "I'm %ld years old", 8223372036854775807L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test30) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %ld years old", -8223372036854775807L);
  sprintf(buffer2, "I'm %ld years old", -8223372036854775807L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test31) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %+ld years old", 12800L);
  sprintf(buffer2, "I'm %+ld years old", 12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test32) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %+ld years old", -12800L);
  sprintf(buffer2, "I'm %+ld years old", -12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test33) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm % ld years old", 12800L);
  sprintf(buffer2, "I'm % ld years old", 12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test34) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm % ld years old", -12800L);
  sprintf(buffer2, "I'm % ld years old", -12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test35) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %0ld years old", 12800L);
  sprintf(buffer2, "I'm %0ld years old", 12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test36) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %0ld years old", -12800L);
  sprintf(buffer2, "I'm %0ld years old", -12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test37) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %+0ld years old", 12800L);
  sprintf(buffer2, "I'm %+0ld years old", 12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test38) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %+0ld years old", -12800L);
  sprintf(buffer2, "I'm %+0ld years old", -12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test39) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %12ld years old", 12800L);
  sprintf(buffer2, "I'm %12ld years old", 12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test40) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %12ld years old", -12800L);
  sprintf(buffer2, "I'm %12ld years old", -12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test41) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %12ld years old", 8223372036854775807L);
  sprintf(buffer2, "I'm %12ld years old", 8223372036854775807L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test42) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %12ld years old", -8223372036854775807L);
  sprintf(buffer2, "I'm %12ld years old", -8223372036854775807L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test43) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %+12ld years old", 12800L);
  sprintf(buffer2, "I'm %+12ld years old", 12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test44) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %+12ld years old", -12800L);
  sprintf(buffer2, "I'm %+12ld years old", -12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test45) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm % 12ld years old", 12800L);
  sprintf(buffer2, "I'm % 12ld years old", 12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test46) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm % 12ld years old", -12800L);
  sprintf(buffer2, "I'm % 12ld years old", -12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test47) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %012ld years old", 12800L);
  sprintf(buffer2, "I'm %012ld years old", 12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test48) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %012ld years old", -12800L);
  sprintf(buffer2, "I'm %012ld years old", -12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test49) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %+012ld years old", 12800L);
  sprintf(buffer2, "I'm %+012ld years old", 12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test50) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %+012ld years old", -12800L);
  sprintf(buffer2, "I'm %+012ld years old", -12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test51) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %+-12ld years old", 12800L);
  sprintf(buffer2, "I'm %+-12ld years old", 12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test52) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};

  s21_sprintf(buffer1, "I'm %+-12ld years old", -12800L);
  sprintf(buffer2, "I'm %+-12ld years old", -12800L);
  ck_assert_str_eq(buffer1, buffer2);
}

Suite *s21_sprintf_test_suite_specifier_d_3() {
  Suite *s = suite_create("\033[42m-=s21_sprintf test specifier d 3=-\033[0m");
  TCase *t = tcase_create("main tcase");
  // Legth h
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
  tcase_add_test(t, test23);
  tcase_add_test(t, test24);
  tcase_add_test(t, test25);
  tcase_add_test(t, test26);
  // Length l
  tcase_add_test(t, test27);
  tcase_add_test(t, test28);
  tcase_add_test(t, test29);
  tcase_add_test(t, test30);
  tcase_add_test(t, test31);
  tcase_add_test(t, test32);
  tcase_add_test(t, test33);
  tcase_add_test(t, test34);
  tcase_add_test(t, test35);
  tcase_add_test(t, test36);
  tcase_add_test(t, test37);
  tcase_add_test(t, test38);
  tcase_add_test(t, test39);
  tcase_add_test(t, test40);
  tcase_add_test(t, test41);
  tcase_add_test(t, test42);
  tcase_add_test(t, test43);
  tcase_add_test(t, test44);
  tcase_add_test(t, test45);
  tcase_add_test(t, test46);
  tcase_add_test(t, test47);
  tcase_add_test(t, test48);
  tcase_add_test(t, test49);
  tcase_add_test(t, test50);
  tcase_add_test(t, test51);
  tcase_add_test(t, test52);
  suite_add_tcase(s, t);
  return s;
}