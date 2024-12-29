#include "../../src/s21_string.h"
#include "../s21_string_test.h"

START_TEST(test_c_1) {
  char *str = "Hello my dear friend, how are you?";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_2) {
  char *str = "walderhu";
  char buff1, buff2, buff1_s21, buff2_s21;
  sscanf(str, "%c%c", &buff1, &buff2);
  s21_sscanf(str, "%c%c", &buff1_s21, &buff2_s21);
  ck_assert_int_eq(buff1, buff1_s21);
  ck_assert_int_eq(buff2, buff2_s21);
}
END_TEST

START_TEST(test_c_3) {
  char *str = "163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_4) {
  char *str = "   163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_5) {
  char *str = "?163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_6) {
  char *str = "___163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_7) {
  char *str = "\t163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_8) {
  char *str = "\r163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_9) {
  char *str = "f163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_10) {
  char *str = "\n163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_d_1) {
  char *str = "163.5";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_d_2) {
  char *str = "walderhu 163";
  int original = 0, replica = 0;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_d_3) {
  char *str = "16 3";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_d_4) {
  char *str = "16.3";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_d_5) {
  char *str = "\t16 3";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_d_6) {
  char *str = "       my16 3";
  int original = 0, replica = 0;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_d_7) {
  char *str = "\r16 3";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_d_8) {
  char *str = "0x16 3";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_d_9) {
  char *str = "432416 3";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_d_10) {
  char *str = "136 3";
  int original, replica;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_x_1) {
  char *str = "1a";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_x_2) {
  char *str = "1as";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_x_3) {
  char *str = "1abc3";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_x_4) {
  char *str = "0";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_x_5) {
  char *str = "01ab";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_x_6) {
  char *str = "0x1a";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_x_7) {
  char *str = "0x1a";
  unsigned int original1 = 0, replica1 = 0;
  unsigned int original2 = 0, replica2 = 0;
  sscanf(str, "%x%x", &original1, &original2);
  s21_sscanf(str, "%x%x", &replica1, &replica2);
  ck_assert_int_eq(original1, replica1);
  ck_assert_int_eq(original2, replica2);
}
END_TEST

START_TEST(test_x_8) {
  char *str = "0x1a";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_x_9) {
  char *str = "   3x1a";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_x_10) {
  char *str = "\t0X1a";
  unsigned int original, replica;
  sscanf(str, "%x", &original);
  s21_sscanf(str, "%x", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_X_1) {
  char *str = "1A";
  unsigned int original, replica;
  sscanf(str, "%X", &original);
  s21_sscanf(str, "%X", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_X_2) {
  char *str = "1AS";
  unsigned int original, replica;
  sscanf(str, "%X", &original);
  s21_sscanf(str, "%X", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_X_3) {
  char *str = "1ABC3";
  unsigned int original, replica;
  sscanf(str, "%X", &original);
  s21_sscanf(str, "%X", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_X_4) {
  char *str = "0";
  unsigned int original, replica;
  sscanf(str, "%X", &original);
  s21_sscanf(str, "%X", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_X_5) {
  char *str = "01AB";
  unsigned int original, replica;
  sscanf(str, "%X", &original);
  s21_sscanf(str, "%X", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_X_6) {
  char *str = "0x1A";
  unsigned int original, replica;
  sscanf(str, "%X", &original);
  s21_sscanf(str, "%X", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_X_7) {
  char *str = "\t0x1a";
  unsigned int original1 = 0, replica1 = 0;
  unsigned int original2 = 0, replica2 = 0;
  sscanf(str, "%X%X", &original1, &original2);
  s21_sscanf(str, "%X%X", &replica1, &replica2);
  ck_assert_int_eq(original1, replica1);
  ck_assert_int_eq(original2, replica2);
}
END_TEST

START_TEST(test_X_8) {
  char *str = "     \t0x1a";
  unsigned int original, replica;
  sscanf(str, "%X", &original);
  s21_sscanf(str, "%X", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_X_9) {
  char *str = "   3X1A";
  unsigned int original, replica;
  sscanf(str, "%X", &original);
  s21_sscanf(str, "%X", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_X_10) {
  char *str = "\t0X1A";
  unsigned int original, replica;
  sscanf(str, "%X", &original);
  s21_sscanf(str, "%X", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_o_1) {
  char *str = "0123";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_o_2) {
  char *str = "123";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_o_3) {
  char *str = "01239";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_o_4) {
  char *str = "\t0";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_o_5) {
  char *str = "01AB";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_o_6) {
  char *str = "0x1A";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_o_7) {
  char *str = "\n0x1A";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_o_8) {
  char *str = "     \t0x1a";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_o_9) {
  char *str = "   3X1A";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_o_10) {
  char *str = "\t0X1A";
  unsigned int original, replica;
  sscanf(str, "%o", &original);
  s21_sscanf(str, "%o", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_u_1) {
  char *str = "0123";
  unsigned int original, replica;
  sscanf(str, "%u", &original);
  s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_u_2) {
  char *str = "-123";
  unsigned int original, replica;
  sscanf(str, "%u", &original);
  s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_u_3) {
  char *str = "01239.3";
  unsigned int original, replica;
  sscanf(str, "%u", &original);
  s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_u_4) {
  char *str = "walderhu 163";
  unsigned int original = 0, replica = 0;
  sscanf(str, "%u", &original);
  s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_u_5) {
  char *str = "16 3";
  unsigned int original, replica;
  sscanf(str, "%u", &original);
  s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_u_6) {
  char *str = "1a";
  unsigned int original, replica;
  sscanf(str, "%u", &original);
  s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_u_7) {
  char *str = "0x1a";
  unsigned int original, replica;
  sscanf(str, "%u", &original);
  s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_u_8) {
  char *str = "0x1ABC";
  unsigned int original, replica;
  sscanf(str, "%u", &original);
  s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_u_9) {
  char *str = "01239.3";
  unsigned int original, replica;
  sscanf(str, "%u", &original);
  s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_u_10) {
  char *str = "-123";
  unsigned int original, replica;
  sscanf(str, "%u", &original);
  s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_i_1) {
  char *str = "0123";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_i_2) {
  char *str = "-123";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_i_3) {
  char *str = "01239.3";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}

START_TEST(test_i_4) {
  char *str = "walderhu 163";
  int original = 0, replica = 0;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_i_5) {
  char *str = "16 3";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_i_6) {
  char *str = "1a";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_i_7) {
  char *str = "0x1a";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_i_8) {
  char *str = "0x1ABC";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_i_9) {
  char *str = "01239.3";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_i_10) {
  char *str = "-123";
  int original, replica;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_s_1) {
  char *str = "hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  sscanf(str, "%10s", original);
  s21_sscanf(str, "%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_s_2) {
  char *str = "   hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  sscanf(str, "%10s", original);
  s21_sscanf(str, "%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_s_3) {
  char *str = "walderhu\tworld";
  char original[strlen(str)];
  char replica[strlen(str)];
  sscanf(str, "%10s", original);
  s21_sscanf(str, "%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_s_4) {
  char *str = "   163";
  char original[strlen(str)];
  char replica[strlen(str)];
  sscanf(str, "%10s", original);
  s21_sscanf(str, "%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_s_5) {
  char *str = "   \t163";
  char original[strlen(str)];
  char replica[strlen(str)];
  sscanf(str, "%10s", original);
  s21_sscanf(str, "%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_s_6) {
  char str[] = "hello walderhu";
  char original1[strlen(str)];
  char replica1[strlen(str)];

  char original2[strlen(str)];
  char replica2[strlen(str)];

  char specifier[] = "%s%s";

  sscanf(str, specifier, original1, original2);
  s21_sscanf(str, specifier, replica1, replica2);

  ck_assert_int_eq(strcmp(original1, replica1), 0);
  ck_assert_int_eq(strcmp(original2, replica2), 0);
  for (s21_size_t i = 0; i < strlen(original1); i++)
    ck_assert_int_eq(original1[i], replica1[i]);
  for (s21_size_t i = 0; i < strlen(original2); i++)
    ck_assert_int_eq(original2[i], replica2[i]);
}
END_TEST

START_TEST(test_s_7) {
  char str[] = "hello    \twalderhu";
  char original1[strlen(str)];
  char replica1[strlen(str)];

  char original2[strlen(str)];
  char replica2[strlen(str)];

  char specifier[] = "%s%s";

  sscanf(str, specifier, original1, original2);
  s21_sscanf(str, specifier, replica1, replica2);

  ck_assert_int_eq(strcmp(original1, replica1), 0);
  ck_assert_int_eq(strcmp(original2, replica2), 0);
  for (s21_size_t i = 0; i < strlen(original1); i++)
    ck_assert_int_eq(original1[i], replica1[i]);
  for (s21_size_t i = 0; i < strlen(original2); i++)
    ck_assert_int_eq(original2[0], replica2[0]);
}
END_TEST

START_TEST(test_s_8) {
  char *str = "   163";
  char original[strlen(str)];
  char replica[strlen(str)];
  sscanf(str, "%10s", original);
  s21_sscanf(str, "%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_s_9) {
  char *str = "   163";
  char original[strlen(str)];
  char replica[strlen(str)];
  sscanf(str, "%10s", original);
  s21_sscanf(str, "%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_s_10) {
  char *str = "   163";
  char original[strlen(str)];
  char replica[strlen(str)];
  sscanf(str, "%10s", original);
  s21_sscanf(str, "%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_f_1) {
  char *str = "3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_f_2) {
  char *str = "-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_f_3) {
  char *str = "     -3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_f_4) {
  char *str = "\t-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_f_5) {
  char *str = "\r-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_f_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_f_7) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_f_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_f_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_f_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_e_1) {
  char *str = "3.141500e-11";
  float original, replica;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_e_2) {
  char *str = "3.141500e+11";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_e_3) {
  char *str = "     -3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_e_4) {
  char *str = "\t-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_e_5) {
  char *str = "\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_e_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_e_7) {
  char *str = "3.141500E+11";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_e_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_e_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_e_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_E_1) {
  char *str = "3.141500E-11";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST
START_TEST(test_E_2) {
  char *str = "3.141500E+11";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_E_3) {
  char *str = "     -3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_E_4) {
  char *str = "\t-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_E_5) {
  char *str = "\r-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_E_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_E_7) {
  char *str = "3.141500e+11";
  float original = 0, replica = 0;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_E_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_E_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_E_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_g_1) {
  char *str = "3.141500E-11";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST
START_TEST(test_g_2) {
  char *str = "3.141500E+11";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_g_3) {
  char *str = "     -3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_g_4) {
  char *str = "\t-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_g_5) {
  char *str = "\r-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_g_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_g_7) {
  char *str = "3.141500e+11";
  float original = 0, replica = 0;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_g_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_g_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_g_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_G_1) {
  char *str = "3.141500E-11";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST
START_TEST(test_G_2) {
  char *str = "3.141500E+11";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_G_3) {
  char *str = "     -3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_G_4) {
  char *str = "\t-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_G_5) {
  char *str = "\r-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_G_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_G_7) {
  char *str = "3.141500e+11";
  float original = 0, replica = 0;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_G_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_G_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_G_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_1) {
  char *str = "163.5";
  short original, replica;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_2) {
  char *str = "walderhu 163";
  short original = 0, replica = 0;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_3) {
  char *str = "16 3";
  short original, replica;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_4) {
  char *str = "16.3";
  short original, replica;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_5) {
  char *str = "\t16 3";
  short original, replica;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_6) {
  char *str = "       my16 3";
  short original = 0, replica = 0;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_7) {
  char *str = "\r16 3";
  short original, replica;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_8) {
  char *str = "0x16 3";
  short original, replica;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_9) {
  char *str = "432416 3";
  short original, replica;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_10) {
  char *str = "136 3";
  short original, replica;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_1) {
  char *str = "1a";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_2) {
  char *str = "1as";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_3) {
  char *str = "1abc3";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_4) {
  char *str = "0";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_5) {
  char *str = "01ab";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_6) {
  char *str = "0x1a";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_7) {
  char *str = "0x1a";
  short unsigned int original1 = 0, replica1 = 0;
  short unsigned int original2 = 0, replica2 = 0;
  sscanf(str, "%hx%hx", &original1, &original2);
  s21_sscanf(str, "%hx%hx", &replica1, &replica2);
  ck_assert_int_eq(original1, replica1);
  ck_assert_int_eq(original2, replica2);
}
END_TEST

START_TEST(test_hx_8) {
  char *str = "0x1a";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_9) {
  char *str = "   3x1a";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_10) {
  char *str = "\t0X1a";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hX_1) {
  char *str = "1A";
  short unsigned int original, replica;
  sscanf(str, "%hX", &original);
  s21_sscanf(str, "%hX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hX_2) {
  char *str = "1AS";
  short unsigned int original, replica;
  sscanf(str, "%hX", &original);
  s21_sscanf(str, "%hX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hX_3) {
  char *str = "1ABC3";
  short unsigned int original, replica;
  sscanf(str, "%hX", &original);
  s21_sscanf(str, "%hX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hX_4) {
  char *str = "0";
  short unsigned int original, replica;
  sscanf(str, "%hX", &original);
  s21_sscanf(str, "%hX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hX_5) {
  char *str = "01AB";
  short unsigned int original, replica;
  sscanf(str, "%hX", &original);
  s21_sscanf(str, "%hX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hX_6) {
  char *str = "0x1A";
  short unsigned int original, replica;
  sscanf(str, "%hX", &original);
  s21_sscanf(str, "%hX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hX_7) {
  char *str = "\t0x1a";
  short unsigned int original1 = 0, replica1 = 0;
  short unsigned int original2 = 0, replica2 = 0;
  sscanf(str, "%hX%hX", &original1, &original2);
  s21_sscanf(str, "%hX%hX", &replica1, &replica2);
  ck_assert_int_eq(original1, replica1);
  ck_assert_int_eq(original2, replica2);
}
END_TEST

START_TEST(test_hX_8) {
  char *str = "     \t0x1a";
  short unsigned int original = 0, replica = 0;
  sscanf(str, "%hX", &original);
  s21_sscanf(str, "%hX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hX_9) {
  char *str = "   3X1A";
  short unsigned int original, replica;
  sscanf(str, "%hX", &original);
  s21_sscanf(str, "%hX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hX_10) {
  char *str = "\t0X1A";
  short unsigned int original, replica;
  sscanf(str, "%hX", &original);
  s21_sscanf(str, "%hX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_1) {
  char *str = "0123";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_2) {
  char *str = "123";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_3) {
  char *str = "01239";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_4) {
  char *str = "\t0";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_5) {
  char *str = "01AB";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_6) {
  char *str = "0x1A";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_7) {
  char *str = "\n0x1A";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_8) {
  char *str = "     \t0x1a";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_9) {
  char *str = "   3X1A";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_10) {
  char *str = "\t0X1A";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_1) {
  char *str = "0123";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_2) {
  char *str = "-123";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_3) {
  char *str = "01239.3";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_4) {
  char *str = "walderhu 163";
  short unsigned int original = 0, replica = 0;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_5) {
  char *str = "16 3";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_6) {
  char *str = "1a";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_7) {
  char *str = "0x1a";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_8) {
  char *str = "0x1ABC";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_9) {
  char *str = "01239.3";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_10) {
  char *str = "-123";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hi_1) {
  char *str = "0123";
  short int original, replica;
  sscanf(str, "%hi", &original);
  s21_sscanf(str, "%hi", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hi_2) {
  char *str = "-123";
  short int original, replica;
  sscanf(str, "%hi", &original);
  s21_sscanf(str, "%hi", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hi_3) {
  char *str = "01239.3";
  short int original, replica;
  sscanf(str, "%hi", &original);
  s21_sscanf(str, "%hi", &replica);
  ck_assert_int_eq(original, replica);
}

START_TEST(test_hi_4) {
  char *str = "walderhu 163";
  short int original = 0, replica = 0;
  sscanf(str, "%hi", &original);
  s21_sscanf(str, "%hi", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hi_5) {
  char *str = "16 3";
  short int original, replica;
  sscanf(str, "%hi", &original);
  s21_sscanf(str, "%hi", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hi_6) {
  char *str = "1a";
  short int original, replica;
  sscanf(str, "%hi", &original);
  s21_sscanf(str, "%hi", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hi_7) {
  char *str = "0x1a";
  short int original, replica;
  sscanf(str, "%hi", &original);
  s21_sscanf(str, "%hi", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hi_8) {
  char *str = "0x1ABC";
  short int original, replica;
  sscanf(str, "%hi", &original);
  s21_sscanf(str, "%hi", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hi_9) {
  char *str = "01239.3";
  short int original, replica;
  sscanf(str, "%hi", &original);
  s21_sscanf(str, "%hi", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hi_10) {
  char *str = "-123";
  short int original, replica;
  sscanf(str, "%hi", &original);
  s21_sscanf(str, "%hi", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ld_1) {
  char *str = "163.5";
  long original, replica;
  sscanf(str, "%ld", &original);
  s21_sscanf(str, "%ld", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ld_2) {
  char *str = "walderlu 163";
  long original = 0, replica = 0;
  sscanf(str, "%ld", &original);
  s21_sscanf(str, "%ld", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ld_3) {
  char *str = "16 3";
  long original, replica;
  sscanf(str, "%ld", &original);
  s21_sscanf(str, "%ld", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ld_4) {
  char *str = "16.3";
  long original, replica;
  sscanf(str, "%ld", &original);
  s21_sscanf(str, "%ld", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ld_5) {
  char *str = "\t16 3";
  long original, replica;
  sscanf(str, "%ld", &original);
  s21_sscanf(str, "%ld", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ld_6) {
  char *str = "       my16 3";
  long original = 0, replica = 0;
  sscanf(str, "%ld", &original);
  s21_sscanf(str, "%ld", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ld_7) {
  char *str = "\r16 3";
  long original, replica;
  sscanf(str, "%ld", &original);
  s21_sscanf(str, "%ld", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ld_8) {
  char *str = "0x16 3";
  long original, replica;
  sscanf(str, "%ld", &original);
  s21_sscanf(str, "%ld", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ld_9) {
  char *str = "432416 3";
  long original, replica;
  sscanf(str, "%ld", &original);
  s21_sscanf(str, "%ld", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ld_10) {
  char *str = "136 3";
  long original, replica;
  sscanf(str, "%ld", &original);
  s21_sscanf(str, "%ld", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lx_1) {
  char *str = "1a";
  long unsigned int original, replica;
  sscanf(str, "%lx", &original);
  s21_sscanf(str, "%lx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lx_2) {
  char *str = "1as";
  long unsigned int original, replica;
  sscanf(str, "%lx", &original);
  s21_sscanf(str, "%lx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lx_3) {
  char *str = "1abc3";
  long unsigned int original, replica;
  sscanf(str, "%lx", &original);
  s21_sscanf(str, "%lx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lx_4) {
  char *str = "0";
  long unsigned int original, replica;
  sscanf(str, "%lx", &original);
  s21_sscanf(str, "%lx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lx_5) {
  char *str = "01ab";
  long unsigned int original, replica;
  sscanf(str, "%lx", &original);
  s21_sscanf(str, "%lx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lx_6) {
  char *str = "0x1a";
  long unsigned int original, replica;
  sscanf(str, "%lx", &original);
  s21_sscanf(str, "%lx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lx_7) {
  char *str = "0x1a";
  long unsigned int original1 = 0, replica1 = 0;
  long unsigned int original2 = 0, replica2 = 0;
  sscanf(str, "%lx%lx", &original1, &original2);
  s21_sscanf(str, "%lx%lx", &replica1, &replica2);
  ck_assert_int_eq(original1, replica1);
  ck_assert_int_eq(original2, replica2);
}
END_TEST

START_TEST(test_lx_8) {
  char *str = "0x1a";
  long unsigned int original, replica;
  sscanf(str, "%lx", &original);
  s21_sscanf(str, "%lx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lx_9) {
  char *str = "   3x1a";
  long unsigned int original, replica;
  sscanf(str, "%lx", &original);
  s21_sscanf(str, "%lx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lx_10) {
  char *str = "\t0X1a";
  long unsigned int original, replica;
  sscanf(str, "%lx", &original);
  s21_sscanf(str, "%lx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lX_1) {
  char *str = "1A";
  long unsigned int original, replica;
  sscanf(str, "%lX", &original);
  s21_sscanf(str, "%lX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lX_2) {
  char *str = "1AS";
  long unsigned int original, replica;
  sscanf(str, "%lX", &original);
  s21_sscanf(str, "%lX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lX_3) {
  char *str = "1ABC3";
  long unsigned int original, replica;
  sscanf(str, "%lX", &original);
  s21_sscanf(str, "%lX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lX_4) {
  char *str = "0";
  long unsigned int original, replica;
  sscanf(str, "%lX", &original);
  s21_sscanf(str, "%lX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lX_5) {
  char *str = "01AB";
  long unsigned int original, replica;
  sscanf(str, "%lX", &original);
  s21_sscanf(str, "%lX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lX_6) {
  char *str = "0x1A";
  long unsigned int original, replica;
  sscanf(str, "%lX", &original);
  s21_sscanf(str, "%lX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lX_7) {
  char *str = "\t0x1a";
  long unsigned int original1 = 0, replica1 = 0;
  long unsigned int original2 = 0, replica2 = 0;
  sscanf(str, "%lX%lX", &original1, &original2);
  s21_sscanf(str, "%lX%lX", &replica1, &replica2);
  ck_assert_int_eq(original1, replica1);
  ck_assert_int_eq(original2, replica2);
}
END_TEST

START_TEST(test_lX_8) {
  char *str = "     \t0x1a";
  long unsigned int original, replica;
  sscanf(str, "%lX", &original);
  s21_sscanf(str, "%lX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lX_9) {
  char *str = "   3X1A";
  long unsigned int original, replica;
  sscanf(str, "%lX", &original);
  s21_sscanf(str, "%lX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lX_10) {
  char *str = "\t0X1A";
  long unsigned int original, replica;
  sscanf(str, "%lX", &original);
  s21_sscanf(str, "%lX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lo_1) {
  char *str = "0123";
  long unsigned int original, replica;
  sscanf(str, "%lo", &original);
  s21_sscanf(str, "%lo", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lo_2) {
  char *str = "123";
  long unsigned int original, replica;
  sscanf(str, "%lo", &original);
  s21_sscanf(str, "%lo", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lo_3) {
  char *str = "01239";
  long unsigned int original, replica;
  sscanf(str, "%lo", &original);
  s21_sscanf(str, "%lo", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lo_4) {
  char *str = "\t0";
  long unsigned int original, replica;
  sscanf(str, "%lo", &original);
  s21_sscanf(str, "%lo", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lo_5) {
  char *str = "01AB";
  long unsigned int original, replica;
  sscanf(str, "%lo", &original);
  s21_sscanf(str, "%lo", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lo_6) {
  char *str = "0x1A";
  long unsigned int original, replica;
  sscanf(str, "%lo", &original);
  s21_sscanf(str, "%lo", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lo_7) {
  char *str = "\n0x1A";
  long unsigned int original, replica;
  sscanf(str, "%lo", &original);
  s21_sscanf(str, "%lo", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lo_8) {
  char *str = "     \t0x1a";
  long unsigned int original, replica;
  sscanf(str, "%lo", &original);
  s21_sscanf(str, "%lo", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lo_9) {
  char *str = "   3X1A";
  long unsigned int original, replica;
  sscanf(str, "%lo", &original);
  s21_sscanf(str, "%lo", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lo_10) {
  char *str = "\t0X1A";
  long unsigned int original, replica;
  sscanf(str, "%lo", &original);
  s21_sscanf(str, "%lo", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lu_1) {
  char *str = "0123";
  long unsigned int original, replica;
  sscanf(str, "%lu", &original);
  s21_sscanf(str, "%lu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lu_2) {
  char *str = "-123";
  long unsigned int original, replica;
  sscanf(str, "%lu", &original);
  s21_sscanf(str, "%lu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lu_3) {
  char *str = "01239.3";
  long unsigned int original, replica;
  sscanf(str, "%lu", &original);
  s21_sscanf(str, "%lu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lu_4) {
  char *str = "walderlu 163";
  long unsigned int original = 0, replica = 0;
  sscanf(str, "%lu", &original);
  s21_sscanf(str, "%lu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lu_5) {
  char *str = "16 3";
  long unsigned int original, replica;
  sscanf(str, "%lu", &original);
  s21_sscanf(str, "%lu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lu_6) {
  char *str = "1a";
  long unsigned int original, replica;
  sscanf(str, "%lu", &original);
  s21_sscanf(str, "%lu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lu_7) {
  char *str = "0x1a";
  long unsigned int original, replica;
  sscanf(str, "%lu", &original);
  s21_sscanf(str, "%lu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lu_8) {
  char *str = "0x1ABC";
  long unsigned int original, replica;
  sscanf(str, "%lu", &original);
  s21_sscanf(str, "%lu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lu_9) {
  char *str = "01239.3";
  long unsigned int original, replica;
  sscanf(str, "%lu", &original);
  s21_sscanf(str, "%lu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lu_10) {
  char *str = "-123";
  long unsigned int original, replica;
  sscanf(str, "%lu", &original);
  s21_sscanf(str, "%lu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_li_1) {
  char *str = "0123";
  long original, replica;
  sscanf(str, "%li", &original);
  s21_sscanf(str, "%li", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_li_2) {
  char *str = "-123";
  long original, replica;
  sscanf(str, "%li", &original);
  s21_sscanf(str, "%li", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_li_3) {
  char *str = "01239.3";
  long original, replica;
  sscanf(str, "%li", &original);
  s21_sscanf(str, "%li", &replica);
  ck_assert_int_eq(original, replica);
}

START_TEST(test_li_4) {
  char *str = "walderlu 163";
  long original = 0, replica = 0;
  sscanf(str, "%li", &original);
  s21_sscanf(str, "%li", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_li_5) {
  char *str = "16 3";
  long original, replica;
  sscanf(str, "%li", &original);
  s21_sscanf(str, "%li", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_li_6) {
  char *str = "1a";
  long original, replica;
  sscanf(str, "%li", &original);
  s21_sscanf(str, "%li", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_li_7) {
  char *str = "0x1a";
  long original, replica;
  sscanf(str, "%li", &original);
  s21_sscanf(str, "%li", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_li_8) {
  char *str = "0x1ABC";
  long original, replica;
  sscanf(str, "%li", &original);
  s21_sscanf(str, "%li", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_li_9) {
  char *str = "01239.3";
  long original, replica;
  sscanf(str, "%li", &original);
  s21_sscanf(str, "%li", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_li_10) {
  char *str = "-123";
  long original, replica;
  sscanf(str, "%li", &original);
  s21_sscanf(str, "%li", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_1) {
  char *str = "3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_2) {
  char *str = "-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_3) {
  char *str = "     -3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_4) {
  char *str = "\t-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_5) {
  char *str = "\r-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_7) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Le_1) {
  char *str = "3.141500e-11";
  float original, replica;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Le_2) {
  char *str = "3.141500e+11";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Le_3) {
  char *str = "     -3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Le_4) {
  char *str = "\t-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Le_5) {
  char *str = "\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Le_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Le_7) {
  char *str = "3.141500E+11";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Le_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Le_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Le_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LE_1) {
  char *str = "3.141500E-11";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST
START_TEST(test_LE_2) {
  char *str = "3.141500E+11";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LE_3) {
  char *str = "     -3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LE_4) {
  char *str = "\t-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LE_5) {
  char *str = "\r-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LE_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LE_7) {
  char *str = "3.141500e+11";
  float original = 0, replica = 0;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LE_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LE_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LE_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lg_1) {
  char *str = "3.141500E-11";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST
START_TEST(test_Lg_2) {
  char *str = "3.141500E+11";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lg_3) {
  char *str = "     -3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lg_4) {
  char *str = "\t-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lg_5) {
  char *str = "\r-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lg_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lg_7) {
  char *str = "3.141500e+11";
  float original = 0, replica = 0;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lg_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lg_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lg_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LG_1) {
  char *str = "3.141500E-11";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST
START_TEST(test_LG_2) {
  char *str = "3.141500E+11";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LG_3) {
  char *str = "     -3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LG_4) {
  char *str = "\t-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LG_5) {
  char *str = "\r-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LG_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LG_7) {
  char *str = "3.141500e+11";
  float original = 0, replica = 0;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LG_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LG_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LG_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_n_1) {
  char *str = "163";
  int digin, n;
  sscanf(str, "%d%n", &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, "%d%n", &digin_r, &n_r);
  ck_assert_int_eq(digin, digin_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_2) {
  char *str = "163 ";
  int digin, n;
  sscanf(str, "%d %n", &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, "%d %n", &digin_r, &n_r);
  ck_assert_int_eq(digin, digin_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_3) {
  char *str = "163 ";
  int digin, n;
  char specifier[] = "%d   %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(digin, digin_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_4) {
  char *str = "163 ";
  int digin, n;
  char specifier[] = "%d   %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(digin, digin_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_5) {
  char *str = "163";
  int digin, n;
  char specifier[] = "%d %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_6) {
  char *str = "163";
  int digin, n;
  char specifier[] = "%d          %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_7) {
  char *str = "163                              ";
  int digin, n;
  char specifier[] = "%d %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_8) {
  char *str = "163\t";
  int digin, n;
  char specifier[] = "%d %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_9) {
  char *str = "163";
  int digin, n;
  char specifier[] = "%d %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_n_10) {
  char *str = "163 ";
  int digin, n;
  char specifier[] = "%d   %n";
  sscanf(str, specifier, &digin, &n);
  int digin_r, n_r;
  s21_sscanf(str, specifier, &digin_r, &n_r);
  ck_assert_int_eq(digin, digin_r);
  ck_assert_int_eq(n, n_r);
}
END_TEST

START_TEST(test_p_1) {
  char addressStr[] = "0x7fff5fbff820";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_p_2) {
  char addressStr[] = "   0x7fff5fbff820";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_p_3) {
  char addressStr[] = "\t0x7fff5fbff820";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_p_4) {
  char addressStr[] = "\r0x7fff5fbff820";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_p_5) {
  char addressStr[] = "des 0x7fff5fbff820";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_p_6) {
  char addressStr[] = "\v0x7fff5fbff820";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_p_8) {
  char addressStr[] = "\n0x7abbbbbbb";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_p_9) {
  char addressStr[] = "0x7fff5fffffbf20";
  void *ptr1;
  void *ptr2;
  sscanf(addressStr, "%p", &ptr1);
  s21_sscanf(addressStr, "%p", &ptr2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(test_star_1) {
  char str[] = "10 apples";
  char original[20];
  char replica[20];
  sscanf(str, "%*d%10s", original);
  s21_sscanf(str, "%*d%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_star_2) {
  char str[] = "10 apples";
  char original[20];
  char replica[20];
  sscanf(str, "%*s%10s", original);
  s21_sscanf(str, "%*s%10s", replica);

  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_star_3) {
  char *str = "\twalderhu\tworld";
  char original[strlen(str)];
  char replica[strlen(str)];
  sscanf(str, "%*s%10s", original);
  s21_sscanf(str, "%*s%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_star_4) {
  char str[] = "hello walderhu";
  char original1[strlen(str)];
  char replica1[strlen(str)];

  char original2[strlen(str)];
  char replica2[strlen(str)];

  memset(original1, '\0', sizeof(original1));
  memset(replica1, '\0', sizeof(replica1));

  memset(original2, '\0', sizeof(original2));
  memset(replica2, '\0', sizeof(replica2));

  char specifier[] = "%*s%s";

  sscanf(str, specifier, original1, original2);
  s21_sscanf(str, specifier, replica1, replica2);

  ck_assert_int_eq(strcmp(original1, replica1), 0);
  ck_assert_int_eq(strcmp(original2, replica2), 0);
  for (s21_size_t i = 0; i < strlen(original1); i++)
    ck_assert_int_eq(original1[i], replica1[i]);
  for (s21_size_t i = 0; i < strlen(original2); i++)
    ck_assert_int_eq(original2[i], replica2[i]);
}
END_TEST

START_TEST(test_star_5) {
  char *str = "\f   \t163";
  char original1[strlen(str)];
  char replica1[strlen(str)];

  char original2[strlen(str)];
  char replica2[strlen(str)];

  memset(original1, '\0', sizeof(original1));
  memset(replica1, '\0', sizeof(replica1));

  memset(original2, '\0', sizeof(original2));
  memset(replica2, '\0', sizeof(replica2));

  char specifier[] = "%*s%s";

  sscanf(str, specifier, original1, original2);
  s21_sscanf(str, specifier, replica1, replica2);

  ck_assert_int_eq(strcmp(original1, replica1), 0);
  ck_assert_int_eq(strcmp(original2, replica2), 0);
  for (s21_size_t i = 0; i < strlen(original1); i++)
    ck_assert_int_eq(original1[i], replica1[i]);
  for (s21_size_t i = 0; i < strlen(original2); i++)
    ck_assert_int_eq(original2[i], replica2[i]);
}
END_TEST

START_TEST(test_star_6) {
  char *str = "\f   \t163";
  char original1[strlen(str)];
  char replica1[strlen(str)];
  char original2[strlen(str)];
  char replica2[strlen(str)];
  memset(original1, '\0', sizeof(original1));
  memset(replica1, '\0', sizeof(replica1));
  memset(original2, '\0', sizeof(original2));
  memset(replica2, '\0', sizeof(replica2));
  char specifier[] = "%*d%s";
  sscanf(str, specifier, original1, original2);
  s21_sscanf(str, specifier, replica1, replica2);
  ck_assert_int_eq(strcmp(original1, replica1), 0);
  ck_assert_int_eq(strcmp(original2, replica2), 0);
  for (s21_size_t i = 0; i < strlen(original1); i++)
    ck_assert_int_eq(original1[i], replica1[i]);
  for (s21_size_t i = 0; i < strlen(original2); i++)
    ck_assert_int_eq(original2[i], replica2[i]);
}
END_TEST

START_TEST(test_star_7) {
  char *str = "213 hello 163";
  char original1[strlen(str)];
  char replica1[strlen(str)];
  memset(original1, '\0', sizeof(original1));
  memset(replica1, '\0', sizeof(replica1));
  char specifier[] = "%*d%s";
  sscanf(str, specifier, original1);
  s21_sscanf(str, specifier, replica1);
  ck_assert_int_eq(strcmp(original1, replica1), 0);
  for (s21_size_t i = 0; i < strlen(original1); i++)
    ck_assert_int_eq(original1[i], replica1[i]);
}
END_TEST

START_TEST(test_star_8) {
  char *str = "   163";
  char original[strlen(str)];
  char replica[strlen(str)];
  sscanf(str, "%10s", original);
  s21_sscanf(str, "%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_star_9) {
  char *str = "   163";
  char original[strlen(str)];
  char replica[strlen(str)];
  sscanf(str, "%10s", original);
  s21_sscanf(str, "%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_star_10) {
  char *str = "   163";
  char original[strlen(str)];
  char replica[strlen(str)];
  sscanf(str, "%10s", original);
  s21_sscanf(str, "%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_width_1) {
  char *str = "16313";
  int buffer1 = 0, buffer2 = 0;
  char specifier[] = "%3d";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_2) {
  char *str = "16313";
  int buffer1 = 0, buffer2 = 0;
  char specifier[] = "%3d";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_3) {
  char *str = "16313";
  int buffer1 = 0, buffer2 = 0;
  char specifier[] = "%123d";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_4) {
  char *str = "hello 163131234";
  int buffer1 = 0, buffer2 = 0;
  char specifier[] = "%123d";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST
START_TEST(test_width_5) {
  char *str = "0123";
  int buffer1 = 0, buffer2 = 0;
  char specifier[] = "%1o";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_6) {
  char *str = "0123";
  int buffer1 = 0, buffer2 = 0;
  char specifier[] = "%2o";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_7) {
  char *str = "0123";
  int buffer1 = 0, buffer2 = 0;
  char specifier[] = "%2o";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST
START_TEST(test_width_8) {
  char *str = "0123";
  int buffer1 = 0, buffer2 = 0;
  char specifier[] = "%3o";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_9) {
  char *str = "0123";
  int buffer1 = 0, buffer2 = 0;
  char specifier[] = "%30o";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_10) {
  char *str = "0123";
  unsigned int buffer1 = 0, buffer2 = 0;
  char specifier[] = "%432u";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_11) {
  char *str = "-123.4567";
  float buffer1 = 0, buffer2 = 0;
  char specifier[] = "%1f";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_double_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_12) {
  char *str = "-123.4567";
  float buffer1 = 0, buffer2 = 0;
  char specifier[] = "%3f";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_double_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_13) {
  char *str = "-123.4567";
  float buffer1 = 0, buffer2 = 0;
  char specifier[] = "%7f";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_double_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_14) {
  char *str = "-123.4567";
  float buffer1 = 0, buffer2 = 0;
  char specifier[] = "%327f";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_double_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_15) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%0e";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_16) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%2e";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_17) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%8e";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_18) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%20e";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_19) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%1g";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_20) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%2g";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_21) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%8g";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_22) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%20g";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_23) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%1E";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_24) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%2E";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_25) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%8E";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_26) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%20E";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_27) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%1G";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_28) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%2G";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_29) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%8G";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_30) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%20G";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_31) {
  char *str = "hello";
  char buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%1c";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_32) {
  char *str = "hello";
  char buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%2c";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_33) {
  char *str = "hello";
  char buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%1c";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_34) {
  char *str = "\tello";
  char buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%1c";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_35) {
  char *str = "\rello";
  char buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%1c";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_36) {
  char *str = "hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  char specifier[] = "%10s";
  sscanf(str, specifier, original);
  s21_sscanf(str, specifier, replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_width_37) {
  char *str = "hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  char specifier[] = "%1s";
  sscanf(str, specifier, original);
  s21_sscanf(str, specifier, replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST
START_TEST(test_width_38) {
  char *str = "hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  char specifier[] = "%2s";
  sscanf(str, specifier, original);
  s21_sscanf(str, specifier, replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST
START_TEST(test_width_39) {
  char *str = "hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  char specifier[] = "%10s";
  sscanf(str, specifier, original);
  s21_sscanf(str, specifier, replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST
START_TEST(test_width_40) {
  char *str = "hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  char specifier[] = "%0s";
  sscanf(str, specifier, original);
  s21_sscanf(str, specifier, replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_percent_1) {
  char str[] = "Привет!%";
  char original[strlen(str)];
  char replica[strlen(str)];
  char specifier[] = "%s%d";
  sscanf(str, specifier, original);
  s21_sscanf(str, specifier, replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_percent_2) {
  char str[] = "Значение: 42%, Символ: %";
  int value1, value2;
  char symbol1, symbol2;

  sscanf(str, "Значение: %d%%, Символ: %c", &value1, &symbol1);
  s21_sscanf(str, "Значение: %d%%, Символ: %c", &value2, &symbol2);
  ck_assert_int_eq(symbol1, symbol2);
  ck_assert_int_eq(value1, value2);
}
END_TEST

Suite *s21_scanf_test_suite() {
  Suite *s = suite_create("\033[42m-=s21_scanf test=-\033[0m");
  TCase *t = tcase_create("main tcase");

  tcase_add_test(t, test_c_1);
  tcase_add_test(t, test_c_2);
  tcase_add_test(t, test_c_3);
  tcase_add_test(t, test_c_4);
  tcase_add_test(t, test_c_5);
  tcase_add_test(t, test_c_6);
  tcase_add_test(t, test_c_7);
  tcase_add_test(t, test_c_8);
  tcase_add_test(t, test_c_9);
  tcase_add_test(t, test_c_10);

  tcase_add_test(t, test_d_1);
  tcase_add_test(t, test_d_2);
  tcase_add_test(t, test_d_3);
  tcase_add_test(t, test_d_4);
  tcase_add_test(t, test_d_5);
  tcase_add_test(t, test_d_6);
  tcase_add_test(t, test_d_7);
  tcase_add_test(t, test_d_8);
  tcase_add_test(t, test_d_9);
  tcase_add_test(t, test_d_10);

  tcase_add_test(t, test_X_1);
  tcase_add_test(t, test_X_2);
  tcase_add_test(t, test_X_3);
  tcase_add_test(t, test_X_4);
  tcase_add_test(t, test_X_5);
  tcase_add_test(t, test_X_6);
  tcase_add_test(t, test_X_7);
  tcase_add_test(t, test_X_8);
  tcase_add_test(t, test_X_9);
  tcase_add_test(t, test_X_10);

  tcase_add_test(t, test_x_1);
  tcase_add_test(t, test_x_2);
  tcase_add_test(t, test_x_3);
  tcase_add_test(t, test_x_4);
  tcase_add_test(t, test_x_5);
  tcase_add_test(t, test_x_6);
  tcase_add_test(t, test_x_7);
  tcase_add_test(t, test_x_8);
  tcase_add_test(t, test_x_9);
  tcase_add_test(t, test_x_10);

  tcase_add_test(t, test_o_1);
  tcase_add_test(t, test_o_2);
  tcase_add_test(t, test_o_3);
  tcase_add_test(t, test_o_4);
  tcase_add_test(t, test_o_5);
  tcase_add_test(t, test_o_6);
  tcase_add_test(t, test_o_7);
  tcase_add_test(t, test_o_8);
  tcase_add_test(t, test_o_9);
  tcase_add_test(t, test_o_10);

  tcase_add_test(t, test_u_1);
  tcase_add_test(t, test_u_2);
  tcase_add_test(t, test_u_3);
  tcase_add_test(t, test_u_4);
  tcase_add_test(t, test_u_5);
  tcase_add_test(t, test_u_6);
  tcase_add_test(t, test_u_7);
  tcase_add_test(t, test_u_8);
  tcase_add_test(t, test_u_9);
  tcase_add_test(t, test_u_10);

  tcase_add_test(t, test_i_1);
  tcase_add_test(t, test_i_2);
  tcase_add_test(t, test_i_3);
  tcase_add_test(t, test_i_4);
  tcase_add_test(t, test_i_5);
  tcase_add_test(t, test_i_6);
  tcase_add_test(t, test_i_7);
  tcase_add_test(t, test_i_8);
  tcase_add_test(t, test_i_9);
  tcase_add_test(t, test_i_10);

  tcase_add_test(t, test_s_1);
  tcase_add_test(t, test_s_2);
  tcase_add_test(t, test_s_3);
  tcase_add_test(t, test_s_4);
  tcase_add_test(t, test_s_5);
  tcase_add_test(t, test_s_6);
  tcase_add_test(t, test_s_7);
  tcase_add_test(t, test_s_8);
  tcase_add_test(t, test_s_9);
  tcase_add_test(t, test_s_10);

  tcase_add_test(t, test_f_1);
  tcase_add_test(t, test_f_2);
  tcase_add_test(t, test_f_3);
  tcase_add_test(t, test_f_4);
  tcase_add_test(t, test_f_5);
  tcase_add_test(t, test_f_6);
  tcase_add_test(t, test_f_7);
  tcase_add_test(t, test_f_8);
  tcase_add_test(t, test_f_9);
  tcase_add_test(t, test_f_10);

  tcase_add_test(t, test_e_1);
  tcase_add_test(t, test_e_2);
  tcase_add_test(t, test_e_3);
  tcase_add_test(t, test_e_4);
  tcase_add_test(t, test_e_5);
  tcase_add_test(t, test_e_6);
  tcase_add_test(t, test_e_7);
  tcase_add_test(t, test_e_8);
  tcase_add_test(t, test_e_9);
  tcase_add_test(t, test_e_10);

  tcase_add_test(t, test_E_1);
  tcase_add_test(t, test_E_2);
  tcase_add_test(t, test_E_3);
  tcase_add_test(t, test_E_4);
  tcase_add_test(t, test_E_5);
  tcase_add_test(t, test_E_6);
  tcase_add_test(t, test_E_7);
  tcase_add_test(t, test_E_8);
  tcase_add_test(t, test_E_9);
  tcase_add_test(t, test_E_10);

  tcase_add_test(t, test_g_1);
  tcase_add_test(t, test_g_2);
  tcase_add_test(t, test_g_3);
  tcase_add_test(t, test_g_4);
  tcase_add_test(t, test_g_5);
  tcase_add_test(t, test_g_6);
  tcase_add_test(t, test_g_7);
  tcase_add_test(t, test_g_8);
  tcase_add_test(t, test_g_9);
  tcase_add_test(t, test_g_10);

  tcase_add_test(t, test_G_1);
  tcase_add_test(t, test_G_2);
  tcase_add_test(t, test_G_3);
  tcase_add_test(t, test_G_4);
  tcase_add_test(t, test_G_5);
  tcase_add_test(t, test_G_6);
  tcase_add_test(t, test_G_7);
  tcase_add_test(t, test_G_8);
  tcase_add_test(t, test_G_9);
  tcase_add_test(t, test_G_10);

  tcase_add_test(t, test_n_1);
  tcase_add_test(t, test_n_2);
  tcase_add_test(t, test_n_3);
  tcase_add_test(t, test_n_4);
  tcase_add_test(t, test_n_5);
  tcase_add_test(t, test_n_6);
  tcase_add_test(t, test_n_7);
  tcase_add_test(t, test_n_8);
  tcase_add_test(t, test_n_9);
  tcase_add_test(t, test_n_10);

  tcase_add_test(t, test_hd_1);
  tcase_add_test(t, test_hd_2);
  tcase_add_test(t, test_hd_3);
  tcase_add_test(t, test_hd_4);
  tcase_add_test(t, test_hd_5);
  tcase_add_test(t, test_hd_6);
  tcase_add_test(t, test_hd_7);
  tcase_add_test(t, test_hd_8);
  tcase_add_test(t, test_hd_9);
  tcase_add_test(t, test_hd_10);

  tcase_add_test(t, test_hX_1);
  tcase_add_test(t, test_hX_2);
  tcase_add_test(t, test_hX_3);
  tcase_add_test(t, test_hX_4);
  tcase_add_test(t, test_hX_5);
  tcase_add_test(t, test_hX_6);
  tcase_add_test(t, test_hX_7);
  tcase_add_test(t, test_hX_8);
  tcase_add_test(t, test_hX_9);
  tcase_add_test(t, test_hX_10);

  tcase_add_test(t, test_hx_1);
  tcase_add_test(t, test_hx_2);
  tcase_add_test(t, test_hx_3);
  tcase_add_test(t, test_hx_4);
  tcase_add_test(t, test_hx_5);
  tcase_add_test(t, test_hx_6);
  tcase_add_test(t, test_hx_7);
  tcase_add_test(t, test_hx_8);
  tcase_add_test(t, test_hx_9);
  tcase_add_test(t, test_hx_10);

  tcase_add_test(t, test_ho_1);
  tcase_add_test(t, test_ho_2);
  tcase_add_test(t, test_ho_3);
  tcase_add_test(t, test_ho_4);
  tcase_add_test(t, test_ho_5);
  tcase_add_test(t, test_ho_6);
  tcase_add_test(t, test_ho_7);
  tcase_add_test(t, test_ho_8);
  tcase_add_test(t, test_ho_9);
  tcase_add_test(t, test_ho_10);

  tcase_add_test(t, test_hu_1);
  tcase_add_test(t, test_hu_2);
  tcase_add_test(t, test_hu_3);
  tcase_add_test(t, test_hu_4);
  tcase_add_test(t, test_hu_5);
  tcase_add_test(t, test_hu_6);
  tcase_add_test(t, test_hu_7);
  tcase_add_test(t, test_hu_8);
  tcase_add_test(t, test_hu_9);
  tcase_add_test(t, test_hu_10);

  tcase_add_test(t, test_hi_1);
  tcase_add_test(t, test_hi_2);
  tcase_add_test(t, test_hi_3);
  tcase_add_test(t, test_hi_4);
  tcase_add_test(t, test_hi_5);
  tcase_add_test(t, test_hi_6);
  tcase_add_test(t, test_hi_7);
  tcase_add_test(t, test_hi_8);
  tcase_add_test(t, test_hi_9);
  tcase_add_test(t, test_hi_10);

  tcase_add_test(t, test_ld_1);
  tcase_add_test(t, test_ld_2);
  tcase_add_test(t, test_ld_3);
  tcase_add_test(t, test_ld_4);
  tcase_add_test(t, test_ld_5);
  tcase_add_test(t, test_ld_6);
  tcase_add_test(t, test_ld_7);
  tcase_add_test(t, test_ld_8);
  tcase_add_test(t, test_ld_9);
  tcase_add_test(t, test_ld_10);

  tcase_add_test(t, test_lX_1);
  tcase_add_test(t, test_lX_2);
  tcase_add_test(t, test_lX_3);
  tcase_add_test(t, test_lX_4);
  tcase_add_test(t, test_lX_5);
  tcase_add_test(t, test_lX_6);
  tcase_add_test(t, test_lX_7);
  tcase_add_test(t, test_lX_8);
  tcase_add_test(t, test_lX_9);
  tcase_add_test(t, test_lX_10);

  tcase_add_test(t, test_lx_1);
  tcase_add_test(t, test_lx_2);
  tcase_add_test(t, test_lx_3);
  tcase_add_test(t, test_lx_4);
  tcase_add_test(t, test_lx_5);
  tcase_add_test(t, test_lx_6);
  tcase_add_test(t, test_lx_7);
  tcase_add_test(t, test_lx_8);
  tcase_add_test(t, test_lx_9);
  tcase_add_test(t, test_lx_10);

  tcase_add_test(t, test_lo_1);
  tcase_add_test(t, test_lo_2);
  tcase_add_test(t, test_lo_3);
  tcase_add_test(t, test_lo_4);
  tcase_add_test(t, test_lo_5);
  tcase_add_test(t, test_lo_6);
  tcase_add_test(t, test_lo_7);
  tcase_add_test(t, test_lo_8);
  tcase_add_test(t, test_lo_9);
  tcase_add_test(t, test_lo_10);

  tcase_add_test(t, test_lu_1);
  tcase_add_test(t, test_lu_2);
  tcase_add_test(t, test_lu_3);
  tcase_add_test(t, test_lu_4);
  tcase_add_test(t, test_lu_5);
  tcase_add_test(t, test_lu_6);
  tcase_add_test(t, test_lu_7);
  tcase_add_test(t, test_lu_8);
  tcase_add_test(t, test_lu_9);
  tcase_add_test(t, test_lu_10);

  tcase_add_test(t, test_li_1);
  tcase_add_test(t, test_li_2);
  tcase_add_test(t, test_li_3);
  tcase_add_test(t, test_li_4);
  tcase_add_test(t, test_li_5);
  tcase_add_test(t, test_li_6);
  tcase_add_test(t, test_li_7);
  tcase_add_test(t, test_li_8);
  tcase_add_test(t, test_li_9);
  tcase_add_test(t, test_li_10);

  tcase_add_test(t, test_Lf_1);
  tcase_add_test(t, test_Lf_2);
  tcase_add_test(t, test_Lf_3);
  tcase_add_test(t, test_Lf_4);
  tcase_add_test(t, test_Lf_5);
  tcase_add_test(t, test_Lf_6);
  tcase_add_test(t, test_Lf_7);
  tcase_add_test(t, test_Lf_8);
  tcase_add_test(t, test_Lf_9);
  tcase_add_test(t, test_Lf_10);

  tcase_add_test(t, test_Le_1);
  tcase_add_test(t, test_Le_2);
  tcase_add_test(t, test_Le_3);
  tcase_add_test(t, test_Le_4);
  tcase_add_test(t, test_Le_5);
  tcase_add_test(t, test_Le_6);
  tcase_add_test(t, test_Le_7);
  tcase_add_test(t, test_Le_8);
  tcase_add_test(t, test_Le_9);
  tcase_add_test(t, test_Le_10);

  tcase_add_test(t, test_LE_1);
  tcase_add_test(t, test_LE_2);
  tcase_add_test(t, test_LE_3);
  tcase_add_test(t, test_LE_4);
  tcase_add_test(t, test_LE_5);
  tcase_add_test(t, test_LE_6);
  tcase_add_test(t, test_LE_7);
  tcase_add_test(t, test_LE_8);
  tcase_add_test(t, test_LE_9);
  tcase_add_test(t, test_LE_10);

  tcase_add_test(t, test_Lg_1);
  tcase_add_test(t, test_Lg_2);
  tcase_add_test(t, test_Lg_3);
  tcase_add_test(t, test_Lg_4);
  tcase_add_test(t, test_Lg_5);
  tcase_add_test(t, test_Lg_6);
  tcase_add_test(t, test_Lg_7);
  tcase_add_test(t, test_Lg_8);
  tcase_add_test(t, test_Lg_9);
  tcase_add_test(t, test_Lg_10);

  tcase_add_test(t, test_LG_1);
  tcase_add_test(t, test_LG_2);
  tcase_add_test(t, test_LG_3);
  tcase_add_test(t, test_LG_4);
  tcase_add_test(t, test_LG_5);
  tcase_add_test(t, test_LG_6);
  tcase_add_test(t, test_LG_7);
  tcase_add_test(t, test_LG_8);
  tcase_add_test(t, test_LG_9);
  tcase_add_test(t, test_LG_10);

  tcase_add_test(t, test_p_1);
  tcase_add_test(t, test_p_2);
  tcase_add_test(t, test_p_3);
  tcase_add_test(t, test_p_4);
  tcase_add_test(t, test_p_5);
  tcase_add_test(t, test_p_6);
  tcase_add_test(t, test_p_8);
  tcase_add_test(t, test_p_9);

  tcase_add_test(t, test_star_1);
  tcase_add_test(t, test_star_2);
  tcase_add_test(t, test_star_3);
  tcase_add_test(t, test_star_4);
  tcase_add_test(t, test_star_5);
  tcase_add_test(t, test_star_6);
  tcase_add_test(t, test_star_7);
  tcase_add_test(t, test_star_8);
  tcase_add_test(t, test_star_9);
  tcase_add_test(t, test_star_10);

  tcase_add_test(t, test_width_1);
  tcase_add_test(t, test_width_2);
  tcase_add_test(t, test_width_3);
  tcase_add_test(t, test_width_4);
  tcase_add_test(t, test_width_5);
  tcase_add_test(t, test_width_6);
  tcase_add_test(t, test_width_7);
  tcase_add_test(t, test_width_8);
  tcase_add_test(t, test_width_9);
  tcase_add_test(t, test_width_10);
  tcase_add_test(t, test_width_11);
  tcase_add_test(t, test_width_12);
  tcase_add_test(t, test_width_13);
  tcase_add_test(t, test_width_14);
  tcase_add_test(t, test_width_15);
  tcase_add_test(t, test_width_16);
  tcase_add_test(t, test_width_17);
  tcase_add_test(t, test_width_18);
  tcase_add_test(t, test_width_19);
  tcase_add_test(t, test_width_20);
  tcase_add_test(t, test_width_21);
  tcase_add_test(t, test_width_22);
  tcase_add_test(t, test_width_23);
  tcase_add_test(t, test_width_24);
  tcase_add_test(t, test_width_25);
  tcase_add_test(t, test_width_26);
  tcase_add_test(t, test_width_27);
  tcase_add_test(t, test_width_28);
  tcase_add_test(t, test_width_29);
  tcase_add_test(t, test_width_30);
  tcase_add_test(t, test_width_31);
  tcase_add_test(t, test_width_32);
  tcase_add_test(t, test_width_33);
  tcase_add_test(t, test_width_34);
  tcase_add_test(t, test_width_35);
  tcase_add_test(t, test_width_36);
  tcase_add_test(t, test_width_37);
  tcase_add_test(t, test_width_38);
  tcase_add_test(t, test_width_39);
  tcase_add_test(t, test_width_40);

  tcase_add_test(t, test_percent_1);
  tcase_add_test(t, test_percent_2);

  suite_add_tcase(s, t);
  return s;
}
