#include <check.h>

#include "s21_string.h"

START_TEST(strlen_test) {
  char *s1 = "0123456789";
  char *s2 = "";
  char *s3 = "a";
  ck_assert_int_eq(s21_strlen(s1), strlen(s1));
  ck_assert_int_eq(s21_strlen(s2), strlen(s2));
  ck_assert_int_eq(s21_strlen(s3), strlen(s3));
}
END_TEST

START_TEST(memchr_test) {
  char *s1 = "012a3456789";
  char *s2 = "";
  int i = 3;
  int c = '5';
  s21_size_t n[5] = {0, 3, 6, 10, 15};
  while (i >= 0) {
    ck_assert_ptr_eq(memchr(s1, c, n[i]), s21_memchr(s1, c, n[i]));
    ck_assert_ptr_eq(memchr(s2, c, n[i]), s21_memchr(s2, c, n[i]));
    i--;
  }
}
END_TEST

START_TEST(memcmp_test) {
  int i = 2;
  char *str1 = "Hello World !!!";
  char *str2 = "Hello Wirld !!!";
  char *str3 = "a";
  char *str4 = " ";
  s21_size_t n[3] = {1, 6, 10};
  while (i >= 0) {
    ck_assert_int_eq(memcmp(str1, str2, n[i]), s21_memcmp(str1, str2, n[i]));
    ck_assert_int_eq(memcmp(str3, str4, n[i]), s21_memcmp(str3, str4, n[i]));
    i--;
  }
}
END_TEST

START_TEST(memcpy_test) {
  int i = 2;
  char str1[100] = " ";
  char str2[100] = "Hello World !!!";
  char str3[100] = "123456";
  s21_size_t n[3] = {1, 6, 10};
  while (i >= 0) {
    ck_assert_ptr_eq(memcpy(str1, str2, n[i]), s21_memcpy(str1, str2, n[i]));
    ck_assert_ptr_eq(memcpy(str2, str3, n[i]), s21_memcpy(str2, str3, n[i]));
    i--;
  }
}
END_TEST

START_TEST(memmove_test) {
  int i = 2;
  char str1[100] = " ";
  char str2[100] = "Hello World !!!";
  char str3[100] = "123456";
  s21_size_t n[3] = {1, 6, 10};
  while (i >= 0) {
    ck_assert_ptr_eq(memmove(str1, str2, n[i]), s21_memmove(str1, str2, n[i]));
    ck_assert_ptr_eq(memmove(str2, str3, n[i]), s21_memmove(str2, str3, n[i]));
    i--;
  }
}
END_TEST

START_TEST(memset_test) {
  int i = 2;
  char str1[100] = " ";
  char str2[100] = "Hello World !!!";
  s21_size_t n[3] = {1, 6, 10};
  int c = '5';
  while (i >= 0) {
    ck_assert_ptr_eq(memset(str1, c, n[i]), s21_memset(str1, c, n[i]));
    ck_assert_ptr_eq(memset(str2, c, n[i]), s21_memset(str2, c, n[i]));
    i--;
  }
}
END_TEST

START_TEST(strcat_test) {
  char str1[100] = " ";
  char str2[100] = "Hello World !!!";
  char str3[100] = "123456";
  ck_assert_str_eq(strcat(str1, str2), s21_strcat(str1, str2));
  ck_assert_str_eq(strcat(str2, str3), s21_strcat(str2, str3));
}
END_TEST

START_TEST(strncat_test) {
  int i = 1;
  char str1[100] = " ";
  char str2[100] = "Hello World !!!";
  char str3[100] = "123456";
  s21_size_t n[3] = {1, 6};
  while (i >= 0) {
    ck_assert_str_eq(strncat(str1, str2, n[i]), s21_strncat(str1, str2, n[i]));
    ck_assert_str_eq(strncat(str2, str3, n[i]), s21_strncat(str2, str3, n[i]));
    i--;
  }
}
END_TEST

START_TEST(strchr_test) {
  char str1[100] = "Hello World !!!";
  char str2[100] = "123456";
  int c = '5';
  ck_assert_ptr_eq(strchr(str1, c), s21_strchr(str1, c));
  ck_assert_str_eq(strchr(str2, c), s21_strchr(str2, c));
}
END_TEST

START_TEST(strcmp_test) {
  char str1[100] = "123456";
  char str2[100] = "Hello World !!!";
  char str3[100] = "123456";
  char str4[100] = "12Hello World !!!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
  ck_assert_int_eq(strcmp(str1, str3), s21_strcmp(str1, str3));
  ck_assert_int_eq(strcmp(str1, str4), s21_strcmp(str1, str4));
}
END_TEST

START_TEST(strncmp_test) {
  int i = 2;
  s21_size_t n[3] = {1, 6, 10};
  char str1[100] = "123456";
  char str2[100] = "Hello World !!!";
  char str3[100] = "123456";
  char str4[100] = "12Hello World !!!";
  while (i >= 0) {
    ck_assert_int_eq(strncmp(str1, str2, n[i]), s21_strncmp(str1, str2, n[i]));
    ck_assert_int_eq(strncmp(str1, str3, n[i]), s21_strncmp(str1, str3, n[i]));
    ck_assert_int_eq(strncmp(str1, str4, n[i]), s21_strncmp(str1, str4, n[i]));
    i--;
  }
}
END_TEST

START_TEST(strcpy_test) {
  char str1[100] = "123456";
  char str2[100] = "Hello World !!!";
  char str3[100] = "789";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
  ck_assert_str_eq(strcpy(str2, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(strncpy_test) {
  int i = 2;
  char str1[100] = "123456";
  char str2[100] = "Hello World !!!";
  char str3[100] = "789";
  s21_size_t n[3] = {1, 6, 10};
  while (i >= 0) {
    ck_assert_str_eq(strncpy(str1, str2, n[i]), s21_strncpy(str1, str2, n[i]));
    ck_assert_str_eq(strncpy(str2, str3, n[i]), s21_strncpy(str2, str3, n[i]));
    i--;
  }
}
END_TEST

START_TEST(strcspn_test) {
  char str1[100] = "123456";
  char str2[100] = "Hello3 World !!!";
  char str3[100] = "468";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
  ck_assert_int_eq(strcspn(str1, str3), s21_strcspn(str1, str3));
}
END_TEST

START_TEST(strpbrk_test) {
  char str1[100] = "123456";
  char str2[100] = "Hello3 World !!!";
  char str3[100] = "468";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
  ck_assert_str_eq(strpbrk(str1, str3), s21_strpbrk(str1, str3));
}
END_TEST

START_TEST(strrchr_test) {
  char str1[100] = "1234536346";
  char str2[100] = "Hello World !!!";
  int c = '3';
  ck_assert_str_eq(strrchr(str1, c), s21_strrchr(str1, c));
  ck_assert_ptr_eq(strrchr(str2, c), s21_strrchr(str2, c));
}
END_TEST

START_TEST(strerror_test) {
  ck_assert_str_eq(strerror(500), s21_strerror(500));
  ck_assert_str_eq(strerror(1), s21_strerror(1));
  ck_assert_str_eq(strerror(-56), s21_strerror(-56));
  ck_assert_str_eq(strerror(-2147483648), s21_strerror(-2147483648));
}
END_TEST

START_TEST(strstr_test) {
  char str1[100] = "12345363462345";
  char str2[100] = "1234";
  char str3[100] = "23";
  char str4[100] = "\0";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
  ck_assert_str_eq(strstr(str1, str3), s21_strstr(str1, str3));
  ck_assert_str_eq(strstr(str2, str4), s21_strstr(str2, str4));
  ck_assert_ptr_eq(strstr(str2, str1), s21_strstr(str2, str1));
}
END_TEST

START_TEST(strspn_test) {
  char str1[100] = "6651234536346";
  char str2[100] = "134";
  char str3[100] = "66512345363461234";
  char str4[100] = "1234";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
  ck_assert_int_eq(strspn(str3, str4), s21_strspn(str3, str4));
}
END_TEST

START_TEST(strtok_test) {
  char str1[100] = "123453636235";
  char str2[100] = "4";
  char str4[100] = "8888123456788888";
  char str[100] = "8";
  char a1[100] = "test1/test2/test3";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
  ck_assert_str_eq(strtok(str4, str), s21_strtok(str4, str));
  ck_assert_str_eq(strtok(a1, "/"), s21_strtok(a1, "/"));
}
END_TEST

START_TEST(trim_test) {
  char str1[100] = "  **  //QWERTYUI//  //  **";
  char str2[100] = " */";
  char *except = "QWERTYUI";
  ck_assert_str_eq(s21_trim(str1, str2), except);
}
END_TEST

START_TEST(insert_test) {
  char *s1 = "1234789";
  char *s2 = "56";
  s21_size_t s = 4;
  s21_size_t x = 0;
  char *ex = "123456789";
  char *ex1 = "561234789";
  ck_assert_str_eq((char *)s21_insert(s1, s2, s), ex);
  ck_assert_str_eq((char *)s21_insert(s1, s2, x), ex1);
}
END_TEST

START_TEST(to_lower_test) {
  char *str = "qWertYuiOp";
  char *except = "qwertyuiop";
  ck_assert_str_eq(s21_to_lower(str), except);
}
END_TEST

START_TEST(to_upper_test) {
  char *str = "qWertYuiOp";
  char *except = "QWERTYUIOP";
  ck_assert_str_eq(s21_to_upper(str), except);
}
END_TEST

START_TEST(sprintf_test) {
  char str[2048];
  char str1[2048];

  ck_assert_int_eq(sprintf(str, "%% %d %f", 14, -9.9),
                   s21_sprintf(str1, "%% %d %f", 14, -9.9));
  ck_assert_int_eq(sprintf(str, "%% %-.0ld % .0f", -2147483648, 0.5),
                   s21_sprintf(str1, "%% %-.0ld % .0f", -2147483648, 0.5));
  ck_assert_int_eq(sprintf(str, "%% % 5d %10.3f", 23, 0.58989),
                   s21_sprintf(str1, "%% % 5d %10.3f", 23, 0.58989));
  ck_assert_int_eq(sprintf(str, "%10s", "Hello"),
                   s21_sprintf(str1, "%10s", "Hello"));
  ck_assert_int_eq(sprintf(str, "%1s", "Hello"),
                   s21_sprintf(str1, "%1s", "Hello"));
  ck_assert_int_eq(sprintf(str, "%hu", -15), s21_sprintf(str1, "%hu", -15));
  ck_assert_int_eq(sprintf(str, "%s", "Hello"),
                   s21_sprintf(str1, "%s", "Hello"));
  ck_assert_int_eq(sprintf(str, "%+-f", 123.23),
                   s21_sprintf(str1, "%+-f", 123.23));
  ck_assert_int_eq(sprintf(str, "%+f", -123.23),
                   s21_sprintf(str1, "%+f", -123.23));
  ck_assert_int_eq(sprintf(str, "% f", -123.23),
                   s21_sprintf(str1, "% +f", -123.23));
  ck_assert_int_eq(sprintf(str, "%+.6f", 0.), s21_sprintf(str1, "%+.6f", 0.));
  ck_assert_int_eq(sprintf(str, "%hu", 655363),
                   s21_sprintf(str1, "%hu", 655363));
  ck_assert_int_eq(sprintf(str, "%d", -123), s21_sprintf(str1, "%d", -123));
  ck_assert_int_eq(sprintf(str, "%+d", -123), s21_sprintf(str1, "%+d", -123));
  ck_assert_int_eq(sprintf(str, "% d", -123), s21_sprintf(str1, "% d", -123));
  ck_assert_int_eq(sprintf(str, "%-+d", 123), s21_sprintf(str1, "%-+d", 123));
  ck_assert_int_eq(sprintf(str, "%-10d", 123), s21_sprintf(str1, "%-10d", 123));
  ck_assert_int_eq(sprintf(str, "%-.5d", 123), s21_sprintf(str1, "%-.5d", 123));
  ck_assert_int_eq(sprintf(str, "%3.0s", "Hello"),
                   s21_sprintf(str1, "%3.0s", "Hello"));
  ck_assert_int_eq(sprintf(str, "%-10s", "Hello"),
                   s21_sprintf(str1, "%-10s", "Hello"));
  ck_assert_int_eq(sprintf(str, "%-c", 'f'), s21_sprintf(str1, "%-c", 'f'));
  ck_assert_int_eq(sprintf(str, "%5c", 'f'), s21_sprintf(str1, "%5c", 'f'));
  ck_assert_int_eq(sprintf(str, "%hd", -1), s21_sprintf(str1, "%hd", -1));
  ck_assert_int_eq(sprintf(str, "% hd", -1), s21_sprintf(str1, "% hd", -1));
  ck_assert_int_eq(sprintf(str, "%+10hd", -1), s21_sprintf(str1, "%+10hd", -1));
  ck_assert_int_eq(sprintf(str, "%+10hi", -1), s21_sprintf(str1, "%+10hi", -1));
  ck_assert_int_eq(sprintf(str, "%+10hd", 23472),
                   s21_sprintf(str1, "%+10hd", 23472));
  ck_assert_int_eq(sprintf(str, "%+10i", 0x7ffe),
                   s21_sprintf(str1, "%+10i", 0x7ffe));
  ck_assert_int_eq(sprintf(str, "%+10.8lf", -159.352),
                   s21_sprintf(str1, "%+10.8lf", -159.352));  //
  ck_assert_int_eq(sprintf(str, "%10u", 5522), s21_sprintf(str1, "%10u", 5522));
  ck_assert_int_eq(sprintf(str, "%-ld", -54875466588),
                   s21_sprintf(str1, "%-ld", -54875466588));
  ck_assert_int_eq(sprintf(str, "%ld", 2147483649),
                   s21_sprintf(str1, "%ld", 2147483649));
  ck_assert_int_eq(sprintf(str, "%+-20ld", 2147483649),
                   s21_sprintf(str1, "%-+20ld", 2147483649));
  ck_assert_int_eq(sprintf(str, "% 20ld", 2147483649),
                   s21_sprintf(str1, "% 20ld", 2147483649));
  ck_assert_int_eq(sprintf(str, "%+ld", -2147483649),
                   s21_sprintf(str1, "%+ld", -2147483649));
  ck_assert_int_eq(sprintf(str, "%-.20lu", 2147483649),
                   s21_sprintf(str1, "%-.20lu", 2147483649));
  ck_assert_int_eq(sprintf(str, "%-.20lu", 2147483649),
                   s21_sprintf(str1, "%-.20lu", 2147483649));
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, strlen_test);
  tcase_add_test(tc1_1, memchr_test);
  tcase_add_test(tc1_1, memcmp_test);
  tcase_add_test(tc1_1, memcpy_test);
  tcase_add_test(tc1_1, memmove_test);
  tcase_add_test(tc1_1, memset_test);
  tcase_add_test(tc1_1, strcat_test);
  tcase_add_test(tc1_1, strncat_test);
  tcase_add_test(tc1_1, strchr_test);
  tcase_add_test(tc1_1, strcmp_test);
  tcase_add_test(tc1_1, strncmp_test);
  tcase_add_test(tc1_1, strcpy_test);
  tcase_add_test(tc1_1, strncpy_test);
  tcase_add_test(tc1_1, strcspn_test);
  tcase_add_test(tc1_1, strpbrk_test);
  tcase_add_test(tc1_1, strrchr_test);
  tcase_add_test(tc1_1, strerror_test);
  tcase_add_test(tc1_1, strstr_test);
  tcase_add_test(tc1_1, strspn_test);
  tcase_add_test(tc1_1, strtok_test);
  tcase_add_test(tc1_1, trim_test);
  tcase_add_test(tc1_1, insert_test);
  tcase_add_test(tc1_1, to_lower_test);
  tcase_add_test(tc1_1, to_upper_test);
  tcase_add_test(tc1_1, sprintf_test);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
