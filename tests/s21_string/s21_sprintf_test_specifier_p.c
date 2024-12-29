#include "../../src/s21_string.h"
#include "../s21_string_test.h"

/*specifiers p*/
START_TEST(test1) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  int a = 10;
  s21_sprintf(buffer1, "I'm |%p| years old", &a);
  sprintf(buffer2, "I'm |%p| years old", &a);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test2) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  int a = 10;
  s21_sprintf(buffer1, "I'm |%30p| years old", &a);
  sprintf(buffer2, "I'm |%30p| years old", &a);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test3) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  int a = 10;
  s21_sprintf(buffer1, "I'm |%-30p| years old", &a);
  sprintf(buffer2, "I'm |%-30p| years old", &a);
  ck_assert_str_eq(buffer1, buffer2);
}

// START_TEST(test4) {
//     char buffer1[8000] = {0};
//     char buffer2[8000] = {0};
//     int a = 10;
//     s21_sprintf(buffer1, "I'm |%030p| years old", &a);
//         sprintf(buffer2, "I'm |%030p| years old", &a);
//     ck_assert_str_eq(buffer1, buffer2);
// }

// START_TEST(test6) {
//     char buffer1[8000] = {0};
//     char buffer2[8000] = {0};
//     int a = 10;
//     s21_sprintf(buffer1, "I'm |% 30p| years old", &a);
//         sprintf(buffer2, "I'm |% 30p| years old", &a);
//     ck_assert_str_eq(buffer1, buffer2);
// }

// START_TEST(test7) {
//     char buffer1[8000] = {0};
//     char buffer2[8000] = {0};
//     int a = 10;
//     s21_sprintf(buffer1, "I'm |%30.15p| years old", &a);
//         sprintf(buffer2, "I'm |%30.15p| years old", &a);
//     ck_assert_str_eq(buffer1, buffer2);
// }

Suite *s21_sprintf_test_suite_specifier_p() {
  Suite *s = suite_create("\033[42m-=s21_sprintf test specifier p=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  //   tcase_add_test(t, test4);
  //   tcase_add_test(t, test5);
  //   tcase_add_test(t, test6);
  //   tcase_add_test(t, test7);
  //   tcase_add_test(t, test8);
  //   tcase_add_test(t, test9);
  //   tcase_add_test(t, test10);
  //   tcase_add_test(t, test11);
  //   tcase_add_test(t, test12);
  //   tcase_add_test(t, test13);
  //   tcase_add_test(t, test14);
  //   tcase_add_test(t, test15);
  //   tcase_add_test(t, test16);
  //   tcase_add_test(t, test17);
  //   tcase_add_test(t, test18);
  //   tcase_add_test(t, test19);
  //   tcase_add_test(t, test20);
  //   tcase_add_test(t, test21);
  //   tcase_add_test(t, test22);
  //   tcase_add_test(t, test23);
  //   tcase_add_test(t, test24);
  //   tcase_add_test(t, test25);
  //   tcase_add_test(t, test26);
  //   tcase_add_test(t, test27);
  //   tcase_add_test(t, test28);
  //   tcase_add_test(t, test29);
  //   tcase_add_test(t, test30);
  //   tcase_add_test(t, test31);
  //   tcase_add_test(t, test32);
  //   tcase_add_test(t, test33);
  //   tcase_add_test(t, test34);
  //   tcase_add_test(t, test35);
  //   tcase_add_test(t, test36);
  //   tcase_add_test(t, test37);
  //   tcase_add_test(t, test38);
  //   tcase_add_test(t, test39);
  //   tcase_add_test(t, test40);
  //   tcase_add_test(t, test41);
  //   tcase_add_test(t, test42);
  //   tcase_add_test(t, test43);
  //   tcase_add_test(t, test44);
  //   tcase_add_test(t, test45);
  //   tcase_add_test(t, test46);
  //   tcase_add_test(t, test47);
  //   tcase_add_test(t, test48);
  //   tcase_add_test(t, test49);
  //   tcase_add_test(t, test50);
  //   tcase_add_test(t, test51);
  //   tcase_add_test(t, test52);
  //   tcase_add_test(t, test53);
  //   tcase_add_test(t, test54);
  //   tcase_add_test(t, test55);
  //   tcase_add_test(t, test56);
  //   tcase_add_test(t, test57);
  //   tcase_add_test(t, test58);
  //   tcase_add_test(t, test59);
  //   tcase_add_test(t, test60);
  //   tcase_add_test(t, test61);
  //   tcase_add_test(t, test62);
  //   tcase_add_test(t, test63);
  //   tcase_add_test(t, test64);
  //   tcase_add_test(t, test65);
  //   tcase_add_test(t, test66);
  //   tcase_add_test(t, test67);
  //   tcase_add_test(t, test68);
  //   tcase_add_test(t, test69);
  //   tcase_add_test(t, test70);
  //   tcase_add_test(t, test71);
  //   tcase_add_test(t, test72);
  //   tcase_add_test(t, test73);
  //   tcase_add_test(t, test74);
  //   tcase_add_test(t, test75);
  //   tcase_add_test(t, test76);
  //   tcase_add_test(t, test77);
  //   tcase_add_test(t, test78);
  suite_add_tcase(s, t);
  return s;
}