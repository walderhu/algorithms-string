#include "../../src/s21_string.h"
#include "../s21_string_test.h"

/*specifiers x*/
START_TEST(test1) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%x| years old", 16384);
  sprintf(buffer2, "I'm |%x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test2) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  unsigned int x = 4294967294;
  s21_sprintf(buffer1, "I'm |%x| years old", x);
  sprintf(buffer2, "I'm |%x| years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test3) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  unsigned int x = 4294967294;
  s21_sprintf(buffer1, "I'm |%x| years old", x);
  sprintf(buffer2, "I'm |%x| years old", x);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test4) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%x| years old", 0);
  sprintf(buffer2, "I'm |%x| years old", 0);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test5) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%lx| years old", 8294967296);
  sprintf(buffer2, "I'm |%lx| years old", 8294967296);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test6) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%hx| years old", (unsigned short)65538);
  sprintf(buffer2, "I'm |%hx| years old", (unsigned short)65538);
  ck_assert_str_eq(buffer1, buffer2);
}

// START_TEST(test7) {
//     char buffer1[8000] = {0};
//     char buffer2[8000] = {0};
//     s21_sprintf(buffer1, "I'm |%u| years old", 4294967299);
//         sprintf(buffer2, "I'm |%u| years old", 4294967299);
//     ck_assert_str_eq(buffer1, buffer2);
// }

START_TEST(test8) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%lx| years old", 4294967299);
  sprintf(buffer2, "I'm |%lx| years old", 4294967299);
  ck_assert_str_eq(buffer1, buffer2);
}

// table 1
START_TEST(test9) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%x| years old", 16384);
  sprintf(buffer2, "I'm |%x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test10) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%8x| years old", 16384);
  sprintf(buffer2, "I'm |%8x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test11) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%2x| years old", 16384);
  sprintf(buffer2, "I'm |%2x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test12) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%0x| years old", 16384);
  sprintf(buffer2, "I'm |%0x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test13) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%08x| years old", 16384);
  sprintf(buffer2, "I'm |%08x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test14) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%02x| years old", 16384);
  sprintf(buffer2, "I'm |%02x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test15) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-x| years old", 16384);
  sprintf(buffer2, "I'm |%-x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test16) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-8x| years old", 16384);
  sprintf(buffer2, "I'm |%-8x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test17) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-2x| years old", 16384);
  sprintf(buffer2, "I'm |%-2x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

// Table 2

START_TEST(test18) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%.0x| years old", 0);
  sprintf(buffer2, "I'm |%.0x| years old", 0);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test19) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%5.0x| years old", 0);
  sprintf(buffer2, "I'm |%5.0x| years old", 0);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test20) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-.0x| years old", 0);
  sprintf(buffer2, "I'm |%-.0x| years old", 0);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test21) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-5.0x| years old", 0);
  sprintf(buffer2, "I'm |%-5.0x| years old", 0);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test22) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%.8x| years old", 16384);
  sprintf(buffer2, "I'm |%.8x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test23) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-.8x| years old", 16384);
  sprintf(buffer2, "I'm |%-.8x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test24) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%.2x| years old", 16384);
  sprintf(buffer2, "I'm |%.2x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test25) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-.2x| years old", 16384);
  sprintf(buffer2, "I'm |%-.2x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

// table 4
START_TEST(test26) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%8.0x| years old", 16384);
  sprintf(buffer2, "I'm |%8.0x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test27) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%8.x| years old", 16384);
  sprintf(buffer2, "I'm |%8.x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test28) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-8.0x| years old", 16384);
  sprintf(buffer2, "I'm |%-8.0x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test29) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-8.x| years old", 16384);
  sprintf(buffer2, "I'm |%-8.x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test30) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%8.16x| years old", 16384);
  sprintf(buffer2, "I'm |%8.16x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test31) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-8.16x| years old", 16384);
  sprintf(buffer2, "I'm |%-8.16x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test32) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%8.0x| years old", 0);
  sprintf(buffer2, "I'm |%8.0x| years old", 0);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test33) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%8.x| years old", 0);
  sprintf(buffer2, "I'm |%8.x| years old", 0);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test34) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-8.0x| years old", 0);
  sprintf(buffer2, "I'm |%-8.0x| years old", 0);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test35) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-8.x| years old", 0);
  sprintf(buffer2, "I'm |%-8.x| years old", 0);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test36) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%10.7x| years old", 16384);
  sprintf(buffer2, "I'm |%10.7x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test37) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-10.7x| years old", 16384);
  sprintf(buffer2, "I'm |%-10.7x| years old", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

// table 5

START_TEST(test38) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%10.7hx| years old", (unsigned short)128540);
  sprintf(buffer2, "I'm |%10.7hx| years old", (unsigned short)128540);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test39) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-10.7hx| years old", (unsigned short)128540);
  sprintf(buffer2, "I'm |%-10.7hx| years old", (unsigned short)128540);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test40) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%20.15lx| years old", 4294967299L);
  sprintf(buffer2, "I'm |%20.15lx| years old", 4294967299L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test41) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-20.15lx| years old", 4294967299L);
  sprintf(buffer2, "I'm |%-20.15lx| years old", 4294967299L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test42) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%10hx| years old", (unsigned short)128540);
  sprintf(buffer2, "I'm |%10hx| years old", (unsigned short)128540);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test43) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-10hx| years old", (unsigned short)128540);
  sprintf(buffer2, "I'm |%-10hx| years old", (unsigned short)128540);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test44) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%20lx| years old", 4294967299L);
  sprintf(buffer2, "I'm |%20lx| years old", 4294967299L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test45) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-20lx| years old", 4294967299L);
  sprintf(buffer2, "I'm |%-20lx| years old", 4294967299L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test46) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%020lx| years old", 4294967299L);
  sprintf(buffer2, "I'm |%020lx| years old", 4294967299L);
  ck_assert_str_eq(buffer1, buffer2);
}

// an asterisk

START_TEST(test47) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%*x| years old", 8, 16384);
  sprintf(buffer2, "I'm |%*x| years old", 8, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test48) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%*x| years old", 2, 16384);
  sprintf(buffer2, "I'm |%*x| years old", 2, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test49) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%0*x| years old", 8, 16384);
  sprintf(buffer2, "I'm |%0*x| years old", 8, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test50) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%0*x| years old", 2, 16384);
  sprintf(buffer2, "I'm |%0*x| years old", 2, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test51) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-*x| years old", 8, 16384);
  sprintf(buffer2, "I'm |%-*x| years old", 8, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test52) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-*x| years old", 2, 16384);
  sprintf(buffer2, "I'm |%-*x| years old", 2, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test53) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%*.0x| years old", 5, 0);
  sprintf(buffer2, "I'm |%*.0x| years old", 5, 0);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test54) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-.*x| years old", 0, 0);
  sprintf(buffer2, "I'm |%-.*x| years old", 0, 0);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test55) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-5.*x| years old", 0, 0);
  sprintf(buffer2, "I'm |%-5.*x| years old", 0, 0);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test56) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%.*x| years old", 8, 16384);
  sprintf(buffer2, "I'm |%.*x| years old", 8, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test57) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-.*x| years old", 8, 16384);
  sprintf(buffer2, "I'm |%-.*x| years old", 8, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test58) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%.*x| years old", 2, 16384);
  sprintf(buffer2, "I'm |%.*x| years old", 2, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test59) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-.*x| years old", 2, 16384);
  sprintf(buffer2, "I'm |%-.*x| years old", 2, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test60) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%*.*x| years old", 8, 0, 16384);
  sprintf(buffer2, "I'm |%*.*x| years old", 8, 0, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test61) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%*.x| years old", 8, 16384);
  sprintf(buffer2, "I'm |%*.x| years old", 8, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test62) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-8.*x| years old", 0, 16384);
  sprintf(buffer2, "I'm |%-8.*x| years old", 0, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test63) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%*.*x| years old", 8, 16, 16384);
  sprintf(buffer2, "I'm |%*.*x| years old", 8, 16, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test64) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-*.*x| years old", 8, 16, 16384);
  sprintf(buffer2, "I'm |%-*.*x| years old", 8, 16, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test65) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%*.*x| years old", 10, 7, 16384);
  sprintf(buffer2, "I'm |%*.*x| years old", 10, 7, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test66) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-*.*x| years old", 10, 7, 16384);
  sprintf(buffer2, "I'm |%-*.*x| years old", 10, 7, 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test67) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%*.*hx| years old", 10, 7, (unsigned short)128540);
  sprintf(buffer2, "I'm |%*.*hx| years old", 10, 7, (unsigned short)128540);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test68) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-*.*hx| years old", 10, 7,
              (unsigned short)128540);
  sprintf(buffer2, "I'm |%-*.*hx| years old", 10, 7, (unsigned short)128540);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test69) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%*.*lx| years old", 20, 15, 4294967299L);
  sprintf(buffer2, "I'm |%*.*lx| years old", 20, 15, 4294967299L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test70) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-*.*lx| years old", 20, 15, 4294967299L);
  sprintf(buffer2, "I'm |%-*.*lx| years old", 20, 15, 4294967299L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test71) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%*hx| years old", 10, (unsigned short)128540);
  sprintf(buffer2, "I'm |%*hx| years old", 10, (unsigned short)128540);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test72) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-*hx| years old", 10, (unsigned short)128540);
  sprintf(buffer2, "I'm |%-*hx| years old", 10, (unsigned short)128540);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test73) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%*lx| years old", 20, 4294967299L);
  sprintf(buffer2, "I'm |%*lx| years old", 20, 4294967299L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test74) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%-*lx| years old", 20, 4294967299L);
  sprintf(buffer2, "I'm |%-*lx| years old", 20, 4294967299L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test75) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%0*lx| years old", 20, 4294967299L);
  sprintf(buffer2, "I'm |%0*lx| years old", 20, 4294967299L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test76) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %lx years old", 18446744073709551615ul);
  sprintf(buffer2, "I'm %lx years old", 18446744073709551615ul);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test77) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %30lx years old", 18446744073709551615ul);
  sprintf(buffer2, "I'm %30lx years old", 18446744073709551615ul);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test78) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %-30lx years old", 18446744073709551615ul);
  sprintf(buffer2, "I'm %-30lx years old", 18446744073709551615ul);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test79) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %#x years old", 1223629);
  sprintf(buffer2, "I'm %#x years old", 1223629);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test80) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %#X years old", 1223629);
  sprintf(buffer2, "I'm %#X years old", 1223629);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test81) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %#30x years old", 1223629);
  sprintf(buffer2, "I'm %#30x years old", 1223629);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test82) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %-#30X years old", 1223629);
  sprintf(buffer2, "I'm %-#30X years old", 1223629);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test83) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %#030X years old", 1223629);
  sprintf(buffer2, "I'm %#030X years old", 1223629);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test84) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %#30.15x years old", 1223629);
  sprintf(buffer2, "I'm %#30.15x years old", 1223629);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test85) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %#30.5x years old", 1223629);
  sprintf(buffer2, "I'm %#30.5x years old", 1223629);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test86) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %#30.x years old", 1223629);
  sprintf(buffer2, "I'm %#30.x years old", 1223629);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test87) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm %#30.x years old", 0);
  sprintf(buffer2, "I'm %#30.x years old", 0);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test88) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I'm |%030x| years old", 1234567);
  sprintf(buffer2, "I'm |%030x| years old", 1234567);
  ck_assert_str_eq(buffer1, buffer2);
}

// START_TEST(test89) {
//     char buffer1[8000] = {0};
//     char buffer2[8000] = {0};
//     int a = 10;
//     s21_sprintf(buffer1, "I'm |%+30x| years old", 1234567);
//         sprintf(buffer2, "I'm |%+30x| years old", 1234567);
//     ck_assert_str_eq(buffer1, buffer2);
// }

Suite *s21_sprintf_test_suite_specifier_x_2() {
  Suite *s = suite_create("\033[42m-=s21_sprintf test specifier x_2=-\033[0m");
  TCase *t = tcase_create("main tcase");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  tcase_add_test(t, test4);
  tcase_add_test(t, test5);
  tcase_add_test(t, test6);
  //   tcase_add_test(t, test7); //кидает варнинг, но это не баг, а фича, чтоб
  //   выйти за допустимые границы числа
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
  tcase_add_test(t, test53);
  tcase_add_test(t, test54);
  tcase_add_test(t, test55);
  tcase_add_test(t, test56);
  tcase_add_test(t, test57);
  tcase_add_test(t, test58);
  tcase_add_test(t, test59);
  tcase_add_test(t, test60);
  tcase_add_test(t, test61);
  tcase_add_test(t, test62);
  tcase_add_test(t, test63);
  tcase_add_test(t, test64);
  tcase_add_test(t, test65);
  tcase_add_test(t, test66);
  tcase_add_test(t, test67);
  tcase_add_test(t, test68);
  tcase_add_test(t, test69);
  tcase_add_test(t, test70);
  tcase_add_test(t, test71);
  tcase_add_test(t, test72);
  tcase_add_test(t, test73);
  tcase_add_test(t, test74);
  tcase_add_test(t, test75);
  tcase_add_test(t, test76);
  tcase_add_test(t, test77);
  tcase_add_test(t, test78);
  tcase_add_test(t, test79);
  tcase_add_test(t, test80);
  tcase_add_test(t, test81);
  tcase_add_test(t, test82);
  tcase_add_test(t, test83);
  tcase_add_test(t, test84);
  tcase_add_test(t, test85);
  tcase_add_test(t, test86);
  tcase_add_test(t, test87);
  tcase_add_test(t, test88);
  //   tcase_add_test(t, test89);
  suite_add_tcase(s, t);
  return s;
}