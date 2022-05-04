#include <check.h>

#include "s21_string.h"
// 1
START_TEST(test_s21_memchr) {
  char str1[] = "Hello world!", str2[] = "";
  ck_assert_msg(s21_memchr(str1, 'w', 13) == memchr(str1, 'w', 13),
                "s21_memchr 1");
  ck_assert_msg(s21_memchr(str1, 'a', 13) == memchr(str1, 'a', 13),
                "s21_memchr 2");
  ck_assert_msg(s21_memchr(str1, ' ', 13) == memchr(str1, ' ', 13),
                "s21_memchr 3");
  ck_assert_msg(s21_memchr(str1, '\n', 13) == memchr(str1, '\n', 13),
                "s21_memchr 4");
  ck_assert_msg(s21_memchr(str1, 98, 13) == memchr(str1, 98, 13),
                "s21_memchr 5");
  ck_assert_msg(s21_memchr(str1, 111, 13) == memchr(str1, 111, 13),
                "s21_memchr 6");
  ck_assert_msg(s21_memchr(str2, 'a', 1) == memchr(str2, 'a', 1),
                "s21_memchr 7");
  ck_assert_msg(s21_memchr(str2, ' ', 1) == memchr(str2, ' ', 1),
                "s21_memchr 8");
  ck_assert_msg(s21_memchr(str2, '\n', 1) == memchr(str2, '\n', 1),
                "s21_memchr 9");
}
END_TEST
// 2
START_TEST(test_s21_memcmp) {
  char str1[] = "abcdefghj", str2[] = "abcdefghj", str3[] = "abcdefghjz",
       str4[] = "", str5[] = "\n";
  ck_assert_msg(s21_memcmp(str1, str2, 10) == memcmp(str1, str2, 10),
                "s21_memcmp 1");
  ck_assert_msg(s21_memcmp(str1, str3, 10) == memcmp(str1, str3, 10),
                "s21_memcmp 2");
  ck_assert_msg(s21_memcmp(str4, str1, 1) == memcmp(str4, str1, 1),
                "s21_memcmp 3");
  ck_assert_msg(s21_memcmp(str1, str4, 1) == memcmp(str1, str4, 1),
                "s21_memcmp 4");
  ck_assert_msg(s21_memcmp(str5, str1, 2) == memcmp(str5, str1, 2),
                "s21_memcmp 5");
  ck_assert_msg(s21_memcmp(str4, str5, 1) == memcmp(str4, str5, 1),
                "s21_memcmp 6");
}
END_TEST
// 3
START_TEST(test_s21_memcpy) {
  char str1[] = "abcd", str2[] = "efgh", str3[] = "efghi", str4[] = "";
  ck_assert_msg(s21_memcpy(str1, str2, 5) == memcpy(str1, str2, 5),
                "s21_memcpy 1");
  ck_assert_msg(s21_memcpy(str1, str3, 5) == memcpy(str1, str3, 5),
                "s21_memcpy 2");
  ck_assert_msg(s21_memcpy(str3, str1, 5) == memcpy(str3, str1, 5),
                "s21_memcpy 3");
  ck_assert_msg(s21_memcpy(str4, str1, 1) == memcpy(str4, str1, 1),
                "s21_memcpy 4");
  ck_assert_msg(s21_memcpy(str1, str4, 1) == memcpy(str1, str4, 1),
                "s21_memcpy 5");
}
END_TEST
// 4
START_TEST(test_s21_memmove) {
  char str1[] = "abcd", str2[] = "efgh", str3[] = "efghi", str4[] = "";
  ck_assert_msg(s21_memmove(str1, str2, 5) == memmove(str1, str2, 5),
                "s21_memmove 1");
  ck_assert_msg(s21_memmove(str2, str1, 5) == memmove(str2, str1, 5),
                "s21_memmove 2");
  ck_assert_msg(s21_memmove(str1, str3, 5) == memmove(str1, str3, 5),
                "s21_memmove 3");
  ck_assert_msg(s21_memmove(str3, str1, 5) == memmove(str3, str1, 5),
                "s21_memmove 4");
  ck_assert_msg(s21_memmove(str1, str4, 1) == memmove(str1, str4, 1),
                "s21_memmove 5");
  ck_assert_msg(s21_memmove(str4, str1, 1) == memmove(str4, str1, 1),
                "s21_memmove 6");
  ck_assert_msg(
      s21_memmove(&str1[0], &str1[1], 4) == memmove(&str1[0], &str1[1], 4),
      "s21_memmove 7");
}
END_TEST
// 5
START_TEST(test_s21_memset) {
  char str1[] = "abcdefgh", str2[] = "";
  ck_assert_msg(s21_memset(str1, 'i', 9) == memset(str1, 'i', 9),
                "s21_memset 1");
  ck_assert_msg(s21_memset(str1, 'i', 5) == memset(str1, 'i', 5),
                "s21_memset 2");
  ck_assert_msg(s21_memset(str1, ' ', 9) == memset(str1, ' ', 9),
                "s21_memset 3");
  ck_assert_msg(s21_memset(str1, ' ', 5) == memset(str1, ' ', 5),
                "s21_memset 4");
  ck_assert_msg(s21_memset(str2, ' ', 1) == memset(str2, ' ', 1),
                "s21_memset 5");
  ck_assert_msg(s21_memset(str2, 'i', 1) == memset(str2, 'i', 1),
                "s21_memset 6");
}
END_TEST
// 6
START_TEST(test_s21_strcat) {
  char str1[64] = "Hello world\0", str2[] = " \n\0", str3[] = "\0",
       str4[] = "abcde\0";
  ck_assert_msg(s21_strcat(str1, str2) == strcat(str1, str2), "s21_strcat 1");
  ck_assert_msg(s21_strcat(str1, str3) == strcat(str1, str3), "s21_strcat 2");
  ck_assert_msg(s21_strcat(str1, str4) == strcat(str1, str4), "s21_strcat 3");
  ck_assert_msg(s21_strcat(str2, str3) == strcat(str2, str3), "s21_strcat 4");
  ck_assert_msg(s21_strcat(str4, str3) == strcat(str4, str3), "s21_strcat 5");
}
END_TEST
// 7
START_TEST(test_s21_strncat) {
  char str1[32] = "Hello world", str2[] = "qwe", str3[] = " \n\0",
       str4[] = "\0", str5[] = "abcde\0", str6[32] = "";
  ck_assert_msg(s21_strncat(str1, str2, 3) == strncat(str1, str2, 3),
                "s21_strncat 1");
  ck_assert_msg(s21_strncat(str1, str3, 4) == strncat(str1, str3, 4),
                "s21_strncat 2");
  ck_assert_msg(s21_strncat(str2, str4, 3) == strncat(str2, str4, 3),
                "s21_strncat 3");
  ck_assert_msg(s21_strncat(str5, str4, 2) == strncat(str5, str4, 2),
                "s21_strncat 4");
  ck_assert_msg(s21_strncat(str3, str4, 1) == strncat(str3, str4, 1),
                "s21_strncat 5");
  ck_assert_msg(s21_strncat(str6, str2, 4) == strncat(str6, str2, 4),
                "s21_strncat 6");
}
END_TEST
// 8
START_TEST(test_s21_strchr) {
  char str1[] = "Hello world!", str2[] = "";
  ck_assert_msg(s21_strchr(str1, 'w') == strchr(str1, 'w'), "s21_strchr 1");
  ck_assert_msg(s21_strchr(str1, 'a') == strchr(str1, 'a'), "s21_strchr 2");
  ck_assert_msg(s21_strchr(str1, 108) == strchr(str1, 108), "s21_strchr 3");
  ck_assert_msg(s21_strchr(str1, ' ') == strchr(str1, ' '), "s21_strchr 4");
  ck_assert_msg(s21_strchr(str2, ' ') == strchr(str2, ' '), "s21_strchr 5");
  ck_assert_msg(s21_strchr(str2, 'w') == strchr(str2, 'w'), "s21_strchr 6");
  ck_assert_msg(s21_strchr(str2, 120) == strchr(str2, 120), "s21_strchr 7");
}
END_TEST
// 9
START_TEST(test_s21_strcmp) {
  char str1[] = "abcd", str2[] = "abcd", str3[] = "efgh", str4[] = "efghi",
       str5[] = "";
  ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "s21_strcmp 1");
  ck_assert_msg(s21_strcmp(str1, str3) == strcmp(str1, str3), "s21_strcmp 2");
  ck_assert_msg(s21_strcmp(str1, str3) == strcmp(str1, str3), "s21_strcmp 3");
  ck_assert_msg(s21_strcmp(str1, str4) == strcmp(str1, str4), "s21_strcmp 4");
  ck_assert_msg(s21_strcmp(str4, str1) == strcmp(str4, str1), "s21_strcmp 5");
  ck_assert_msg(s21_strcmp(str5, str1) == strcmp(str5, str1), "s21_strcmp 6");
  ck_assert_msg(s21_strcmp(str1, str5) == strcmp(str1, str5), "s21_strcmp 7");
}
END_TEST
// 10
START_TEST(test_s21_strncmp) {
  char str1[] = "abcd", str2[] = "abcd", str3[] = "efgh", str4[] = "efghi",
       str5[] = "";
  ck_assert_msg(s21_strncmp(str1, str2, 5) == strncmp(str1, str2, 5),
                "s21_strncmp 1");
  ck_assert_msg(s21_strncmp(str1, str3, 5) == strncmp(str1, str3, 5),
                "s21_strncmp 2");
  ck_assert_msg(s21_strncmp(str1, str3, 4) == strncmp(str1, str3, 4),
                "s21_strncmp 3");
  ck_assert_msg(s21_strncmp(str1, str4, 5) == strncmp(str1, str4, 5),
                "s21_strncmp 4");
  ck_assert_msg(s21_strncmp(str4, str1, 4) == strncmp(str4, str1, 4),
                "s21_strncmp 5");
  ck_assert_msg(s21_strncmp(str5, str1, 1) == strncmp(str5, str1, 1),
                "s21_strncmp 6");
  ck_assert_msg(s21_strncmp(str1, str5, 1) == strncmp(str1, str5, 1),
                "s21_strncmp 7");
}
END_TEST
// 11
START_TEST(test_s21_strcpy) {
  char str1[] = "Hello", str2[] = "World", str3[] = "", str4[32] = "";
  ck_assert_msg(s21_strcpy(str1, str2) == strcpy(str1, str2), "s21_strcpy 1");
  ck_assert_msg(s21_strcpy(str2, str1) == strcpy(str2, str1), "s21_strcpy 2");
  ck_assert_msg(s21_strcpy(str1, str3) == strcpy(str1, str3), "s21_strcpy 3");
  ck_assert_msg(s21_strcpy(str4, str1) == strcpy(str4, str1), "s21_strcpy 4");
  ck_assert_msg(s21_strcpy(str4, str3) == strcpy(str4, str3), "s21_strcpy 5");
}
END_TEST
// 12
START_TEST(test_s21_strncpy) {
  char str1[] = "kjzxnvkjbsdfjhkbbds", str2[] = "jsdjsdfkjdsfjh", str3[] = "";
  ck_assert_msg(s21_strncpy(str1, str2, 5) == strncpy(str1, str2, 5),
                "s21_strncpy 1");
  ck_assert_msg(s21_strncpy(str1, str2, 0) == strncpy(str1, str2, 0),
                "s21_strncpy 2");
  ck_assert_msg(s21_strncpy(str1, str2, 20) == strncpy(str1, str2, 20),
                "s21_strncpy 3");
  ck_assert_msg(s21_strncpy(str1, str2, 15) == strncpy(str1, str2, 15),
                "s21_strncpy 4");
  ck_assert_msg(s21_strncpy(str2, str1, 8) == strncpy(str2, str1, 8),
                "s21_strncpy 5");
  ck_assert_msg(s21_strncpy(str2, str1, 0) == strncpy(str2, str1, 0),
                "s21_strncpy 6");
  ck_assert_msg(s21_strncpy(str2, str1, 15) == strncpy(str2, str1, 15),
                "s21_strncpy 7");
  ck_assert_msg(s21_strncpy(str1, str3, 8) == strncpy(str1, str3, 8),
                "s21_strncpy 8");
}
END_TEST
// 13
START_TEST(test_s21_strcspn) {
  char str1[] = "jkflkfgdkhslkhgsdk", str2[] = "gd", str3[] = "";
  ck_assert_msg(s21_strcspn(str1, str2) == strcspn(str1, str2),
                "s21_strcspn 1");
  ck_assert_msg(s21_strcspn(str2, str1) == strcspn(str2, str1),
                "s21_strcspn 2");
  ck_assert_msg(s21_strcspn(str1, str3) == strcspn(str1, str3),
                "s21_strcspn 3");
  ck_assert_msg(s21_strcspn(str2, str3) == strcspn(str2, str3),
                "s21_strcspn 4");
  ck_assert_msg(s21_strcspn(str3, str1) == strcspn(str3, str1),
                "s21_strcspn 5");
  ck_assert_msg(s21_strcspn(str3, str2) == strcspn(str3, str2),
                "s21_strcspn 6");
}
END_TEST
// 14
START_TEST(test_s21_strerror) {
  for (int j = 0, err = -1; j < 3; j++) {
    char *errtest1 = s21_strerror(err);
    char *errtest2 = strerror(err);
    s21_size_t i = 0, len1 = s21_strlen(errtest1), len2 = s21_strlen(errtest2);
    while (i < len1 || i < len2) {
      ck_assert_msg(*(errtest1 + i) == *(errtest2 + i), "strerror 1");
      i++;
    }
    err += 1;
  }
}
END_TEST
// 15
START_TEST(test_s21_strlen) {
  char str1[] = "Hello world!", str2[] = "", str3[] = "!@IU@!*&$@1KWljD",
       str4[] = "Hello world!\n", str5[] = "123456";
  ck_assert_msg(s21_strlen(str1) == strlen(str1), "s21_strlen 1");
  ck_assert_msg(s21_strlen(str2) == strlen(str2), "s21_strlen 2");
  ck_assert_msg(s21_strlen(str3) == strlen(str3), "s21_strlen 3");
  ck_assert_msg(s21_strlen(str4) == strlen(str4), "s21_strlen 4");
  ck_assert_msg(s21_strlen(str5) == strlen(str5), "s21_strlen 5");
}
END_TEST
// 16
START_TEST(test_s21_strpbrk) {
  char str1[] = "abcdefghijklmnop", str2[] = "pkh", str3[] = "";
  ck_assert_msg(s21_strpbrk(str1, str2) == strpbrk(str1, str2),
                "s21_strpbrk 1");
  ck_assert_msg(s21_strpbrk(str2, str1) == strpbrk(str2, str1),
                "s21_strpbrk 2");
  ck_assert_msg(s21_strpbrk(str1, str3) == strpbrk(str1, str3),
                "s21_strpbrk 3");
  ck_assert_msg(s21_strpbrk(str2, str3) == strpbrk(str2, str3),
                "s21_strpbrk 4");
  ck_assert_msg(s21_strpbrk(str3, str1) == strpbrk(str3, str1),
                "s21_strpbrk 5");
  ck_assert_msg(s21_strpbrk(str3, str2) == strpbrk(str3, str2),
                "s21_strpbrk 6");
}
END_TEST
// 17
START_TEST(test_s21_strrchr) {
  char str1[] = ";odsagjnpasdun 1242149215", str2[] = "";
  ck_assert_msg(s21_strrchr(str1, 'a') == strrchr(str1, 'a'), "s21_strrchr 1");
  ck_assert_msg(s21_strrchr(str1, 100) == strrchr(str1, 100), "s21_strrchr 2");
  ck_assert_msg(s21_strrchr(str1, '/') == strrchr(str1, '/'), "s21_strrchr 3");
  ck_assert_msg(s21_strrchr(str1, 98) == strrchr(str1, 98), "s21_strrchr 4");
  ck_assert_msg(s21_strrchr(str2, 'a') == strrchr(str2, 'a'), "s21_strrchr 5");
  ck_assert_msg(s21_strrchr(str2, ' ') == strrchr(str2, ' '), "s21_strrchr 6");
  ck_assert_msg(s21_strrchr(str2, 56) == strrchr(str2, 56), "s21_strrchr 7");
}
END_TEST
// 18
START_TEST(test_s21_strspn) {
  char str1[] = "a;iuhgilsdugiaudhgiu2", str2[] = "gsdsgk", str3[] = "i2u",
       str4[] = "";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "s21_strspn 1");
  ck_assert_msg(s21_strspn(str1, str3) == strspn(str1, str3), "s21_strspn 2");
  ck_assert_msg(s21_strspn(str2, str1) == strspn(str2, str1), "s21_strspn 3");
  ck_assert_msg(s21_strspn(str3, str1) == strspn(str3, str1), "s21_strspn 4");
  ck_assert_msg(s21_strspn(str2, str3) == strspn(str2, str3), "s21_strspn 5");
  ck_assert_msg(s21_strspn(str2, str4) == strspn(str2, str4), "s21_strspn 6");
  ck_assert_msg(s21_strspn(str4, str1) == strspn(str4, str1), "s21_strspn 7");
}
END_TEST
// 19
START_TEST(test_s21_strstr) {
  char str1[] = "abcdefghijklm", str2[] = "hij", str3[] = "", str4[] = "edc";
  ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "s21_strstr 1");
  ck_assert_msg(s21_strstr(str1, str4) == strstr(str1, str4), "s21_strstr 2");
  ck_assert_msg(s21_strstr(str2, str1) == strstr(str2, str1), "s21_strstr 3");
  ck_assert_msg(s21_strstr(str2, str4) == strstr(str2, str4), "s21_strstr 4");
  ck_assert_msg(s21_strstr(str3, str1) == strstr(str3, str1), "s21_strstr 5");
  ck_assert_msg(s21_strstr(str3, str2) == strstr(str3, str2), "s21_strstr 6");
  ck_assert_msg(s21_strstr(str3, str4) == strstr(str3, str4), "s21_strstr 7");
}
END_TEST
// 20
START_TEST(test_s21_strtok) {
  char arr1[100] = "My name is Root. Hello world!", *parr1 = arr1,
       arr2[100] = "My name is Root. Hello world!", *parr2 = arr2;
  s21_strtok(parr1, " .");
  strtok(parr2, " .");
  ck_assert_str_eq(parr1, parr2);
  parr1 = s21_strtok(NULL, " .");
  parr2 = strtok(NULL, " .");
  ck_assert_str_eq(parr1, parr2);
  parr1 = s21_strtok(NULL, " .");
  parr2 = strtok(NULL, " .");
  ck_assert_str_eq(parr1, parr2);
}
END_TEST
// s21_sprintf
START_TEST(test_s21_sprintf) {
  char c[255] = {}, d[255] = {}, x1 = 't';
  int n = 2100, n1 = 0, n2 = -21;
  short sh = 123, sh1 = -123;
  float f = 21.21, f1 = -21.21;
  long int lg = 12345678912345, lg1 = -12345678912345;
  s21_sprintf(c, "%% %p", &n);
  sprintf(d, "%% %p", &n);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg, lg1,
              lg1);
  sprintf(d, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg, lg1,
          lg1);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%10d %+3d %+010d %+-10d %+-10d % -10d %-10d %-10d", n, 212121,
              2121, n2, n, 21, 55, -55);
  sprintf(d, "%10d %+3d %+010d %+-10d %+-10d % -10d %-10d %-10d", n, 212121,
          2121, n2, n, 21, 55, -55);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%-10d %010d %010d %*d %2d", 21, n2, n, 10, n, n2);
  sprintf(d, "%-10d %010d %010d %*d %2d", 21, n2, n, 10, n, n2);
  ck_assert_str_eq(c, d);
  s21_sprintf(c,
              "%.*d %3.10d %.d %-+.5d %-+10.5d %.10d %.10d %2.2d %.d % d %.0d",
              10, n, n2, 42, 21, 10, n, n2, -21, x1, 21, -42);
  sprintf(d, "%.*d %3.10d %.d %-+.5d %-+10.5d %.10d %.10d %2.2d %.d % d %.0d",
          10, n, n2, 42, 21, 10, n, n2, -21, x1, 21, -42);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%d %d %d %d %d %ld %ld", INT_MIN, INT_MAX, SHRT_MAX, SHRT_MIN,
              USHRT_MAX, LONG_MAX, LONG_MIN);
  sprintf(d, "%d %d %d %d %d %ld %ld", INT_MIN, INT_MAX, SHRT_MAX, SHRT_MIN,
          USHRT_MAX, LONG_MAX, LONG_MIN);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%c %10c %-10c", '!', 'a', 'b');
  sprintf(d, "%c %10c %-10c", '!', 'a', 'b');
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
  sprintf(d, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello", "hello",
              "hello", "hello", "hello", "hello");
  sprintf(d, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello", "hello",
          "hello", "hello", "hello", "hello");
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello", L"hello",
              L"hello", L"hello", L"hello", L"hello", L"hello");
  sprintf(d, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello", L"hello",
          L"hello", L"hello", L"hello", L"hello", L"hello");
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%u %lu", UINT_MAX, ULONG_MAX);
  sprintf(d, "%u %lu", UINT_MAX, ULONG_MAX);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "hello %n", &n);
  sprintf(d, "hello %n", &n1);
  ck_assert_msg(c, d, "error");
  s21_sprintf(c, "%-10o %lo %lo %o %o %o %10o %#10o %0#10o", 21, lg, lg1, n, 0,
              n2, 0, 21, 42);
  sprintf(d, "%-10o %lo %lo %o %o %o %10o %#10o %0#10o", 21, lg, lg1, n, 0, n2,
          0, 21, 42);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%#o %#o %#10o %0#10o %.10o %.0o %#5.10o", n, n2, 0, 0, n, 0,
              123);
  sprintf(d, "%#o %#o %#10o %0#10o %.10o %.0o %#5.10o", n, n2, 0, 0, n, 0, 123);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%x %x %x %10x %-10x %.10x %.0x %#5.10x", n, n1, n2, 0, 21, n,
              0, 123);
  sprintf(d, "%x %x %x %10x %-10x %.10x %.0x %#5.10x", n, n1, n2, 0, 21, n, 0,
          123);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx", n,
              n2, 21, 0, 42, 21, 0, -65, lg, lg1);
  sprintf(d, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx", n, n2,
          21, 0, 42, 21, 0, -65, lg, lg1);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%X %X %X %10X %-10X %lX", n, n1, n2, 0, 21, lg1);
  sprintf(d, "%X %X %X %10X %-10X %lX", n, n1, n2, 0, 21, lg1);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%#X %#X %-#10X %#10X %#10X %0#10X %0#10X", n, n2, 21, 42, 0,
              4221, n1);
  sprintf(d, "%#X %#X %-#10X %#10X %#10X %0#10X %0#10X", n, n2, 21, 42, 0, 4221,
          n1);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%+.1f %.2f %.3f %.4f %10.5f %10.5f %-10.3f %-10.2f", f, f1,
              21.21, -21.21, 42.42, -42.42, f, f1);
  sprintf(d, "%+.1f %.2f %.3f %.4f %10.5f %10.5f %-10.3f %-10.2f", f, f1, 21.21,
          -21.21, 42.42, -42.42, f, f1);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f, f1, 21.,
              21.21, 0.0, 21.21, 21., 0.0, 21.21);
  sprintf(d, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f, f1, 21., 21.21,
          0.0, 21.21, 21., 0.0, 21.21);
  ck_assert_str_eq(c, d);
}
END_TEST
// s21_sscanf
START_TEST(test_s21_sscanf) {
  wchar_t wc1, wc2;
  int a1 = 1, b1 = 0, i1 = 0, n1 = 0, i2 = 0, n2 = 0;
  unsigned int a2 = 1, a3 = 1, b2 = 0, b3 = 0;
  long e1 = 1, r1 = 1;
  unsigned long e2 = 0, r2 = 0;
  long double e3 = 0, e4 = 0, g3 = 0, g4 = 0, ld1 = 0, ld2 = 1;
  float f1 = 0, f2 = 1;
  char q1 = '0', w1 = '1', arr1[100] = "", arr2[100] = "";
  void *adres1 = S21_NULL, *adres2 = S21_NULL;

  ck_assert_msg(
      s21_sscanf(" -12345678asd", " %2d%2o%2x%1c%2s", &a1, &a2, &a3, &q1,
                 arr1) ==
          sscanf(" -12345678asd", " %2d%2o%2x%1c%2s", &b1, &b2, &b3, &w1, arr2),
      "sscanf 1.0");
  ck_assert_msg(a1 == b1, "sscanf 1.1");
  ck_assert_msg(a2 == b2, "sscanf 1.2");
  ck_assert_msg(a3 == b3, "sscanf 1.3");
  ck_assert_msg(q1 == w1, "sscanf 1.4");
  ck_assert_str_eq(arr1, arr2);
  ck_assert_msg(s21_sscanf("z1.25e5 1.23e+10", "%lc%G%Le", &wc1, &f1, &ld1) ==
                    sscanf("z1.25e5 1.23e+10", "%lc%G%Le", &wc2, &f2, &ld2),
                "sscanf 2.0");
  ck_assert_msg(f1 == f2, "sscanf 2.1");
  ck_assert_msg(ld1 == ld2, "sscanf 2.2");
  ck_assert_msg(s21_sscanf(" -123abcdeasd", "%2li%2lo", &e1, &e2) ==
                    sscanf(" -123abcdeasd", "%2li%2lo", &r1, &r2),
                "sscanf 3.0");
  ck_assert_msg(e1 == r1, "sscanf 3.1");
  ck_assert_msg(e2 == r2, "sscanf 3.2");
  ck_assert_msg(s21_sscanf("5 0x213def", "%1i%p%n", &i1, &adres1, &n1) ==
                    sscanf("5 0x213def", "%1i%p%n", &i2, &adres2, &n2),
                "sscanf 4.0");
  ck_assert_msg(i1 == i2, "sscanf 4.1");
  ck_assert_msg(n1 == n2, "sscanf 4.2");
  ck_assert_ptr_eq(adres1, adres2);
  ck_assert_msg(s21_sscanf("1.23451e+15 34567837433.456", "%Le%Lg", &e3, &g3) ==
                    sscanf("1.23451e+15 34567837433.456", "%Le%Lg", &e4, &g4),
                "sscanf 4.4");
  ck_assert_msg(e3 == e4, "sscanf 4.4");
  ck_assert_msg(g3 == g4, "sscanf 4.4");
}
END_TEST
// s21_to_upper
START_TEST(test_s21_to_upper) {
  char *res = s21_to_upper("test");
  ck_assert_str_eq(res, "TEST");
  free(res);

  res = s21_to_upper(" t e s t");
  ck_assert_str_eq(res, " T E S T");
  free(res);

  res = s21_to_upper("test001");
  ck_assert_str_eq(res, "TEST001");
  free(res);

  res = s21_to_upper("!test!");
  ck_assert_str_eq(res, "!TEST!");
  free(res);

  res = s21_to_upper(" ");
  ck_assert_str_eq(res, " ");
  free(res);

  res = s21_to_upper("!*_*!");
  ck_assert_str_eq(res, "!*_*!");
  free(res);
}
END_TEST
// s21_to_lower
START_TEST(test_s21_to_lower) {
  char *res = s21_to_lower("TEST");
  ck_assert_str_eq(res, "test");
  free(res);

  res = s21_to_lower(" T E S T");
  ck_assert_str_eq(res, " t e s t");
  free(res);

  res = s21_to_lower("TEST001");
  ck_assert_str_eq(res, "test001");
  free(res);

  res = s21_to_lower("!TEST!");
  ck_assert_str_eq(res, "!test!");
  free(res);

  res = s21_to_lower(" ");
  ck_assert_str_eq(res, " ");
  free(res);

  res = s21_to_lower("!*_*!");
  ck_assert_str_eq(res, "!*_*!");
  free(res);
}
END_TEST
// s21_insert
START_TEST(test_s21_insert) {
  char *str1 = "Test";
  char *str2 = "quest";
  char *result = NULL;
  result = s21_insert(str1, str2, 2);
  ck_assert_str_eq(result, "Tequestst");
  free(result);

  str1 = "The test";
  str2 = " perfect";
  result = s21_insert(str1, str2, 3);
  ck_assert_str_eq(result, "The perfect test");
  free(result);

  str1 = "Insert in";
  str2 = " end";
  result = s21_insert(str1, str2, 9);
  ck_assert_str_eq(result, "Insert in end");
  free(result);

  str1 = " with insert";
  str2 = "Start";
  result = s21_insert(str1, str2, 0);
  ck_assert_str_eq(result, "Start with insert");
  free(result);

  str1 = "Newspace";
  str2 = " ";
  result = s21_insert(str1, str2, 3);
  ck_assert_str_eq(result, "New space");
  free(result);

  str1 = "";
  str2 = " ";
  result = s21_insert(str1, str2, 0);
  ck_assert_str_eq(result, " ");
  free(result);
}
END_TEST
// s21_trim
START_TEST(test_s21_trim) {
  char *res = s21_trim("testc", "c");
  ck_assert_str_eq(res, "test");
  free(res);

  res = s21_trim(" test ", " ");
  ck_assert_str_eq(res, "test");
  free(res);

  res = s21_trim(" ", " ");
  ck_assert_str_eq(res, "");
  free(res);

  res = s21_trim("*te*st*", "*");
  ck_assert_str_eq(res, "te*st");
  free(res);

  res = s21_trim(" te st001", " ");
  ck_assert_str_eq(res, "te st001");
  free(res);

  res = s21_trim(" /*()", ")(/ *");
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

int main() {
  Suite *suite = suite_create("S21_Debuger");
  SRunner *srunner = srunner_create(suite);
  // 1
  TCase *s21_memchrCase = tcase_create("s21_memchrCase");
  suite_add_tcase(suite, s21_memchrCase);
  tcase_add_test(s21_memchrCase, test_s21_memchr);
  // 2
  TCase *s21_memcmpCase = tcase_create("s21_memcmpCase");
  suite_add_tcase(suite, s21_memcmpCase);
  tcase_add_test(s21_memcmpCase, test_s21_memcmp);
  // 3
  TCase *s21_memcpyCase = tcase_create("s21_memcpyCase");
  suite_add_tcase(suite, s21_memcpyCase);
  tcase_add_test(s21_memcpyCase, test_s21_memcpy);
  // 4
  TCase *s21_memmoveCase = tcase_create("s21_memmoveCase");
  suite_add_tcase(suite, s21_memmoveCase);
  tcase_add_test(s21_memmoveCase, test_s21_memmove);
  // 5
  TCase *s21_memsetCase = tcase_create("s21_memsetCase");
  suite_add_tcase(suite, s21_memsetCase);
  tcase_add_test(s21_memsetCase, test_s21_memset);
  // 6
  TCase *s21_strcatCase = tcase_create("s21_strcatCase");
  suite_add_tcase(suite, s21_strcatCase);
  tcase_add_test(s21_strcatCase, test_s21_strcat);
  // 7
  TCase *s21_strncatCase = tcase_create("s21_strncatCase");
  suite_add_tcase(suite, s21_strncatCase);
  tcase_add_test(s21_strncatCase, test_s21_strncat);
  // 8
  TCase *s21_strchrCase = tcase_create("s21_strchrCase");
  suite_add_tcase(suite, s21_strchrCase);
  tcase_add_test(s21_strchrCase, test_s21_strchr);
  // 9
  TCase *s21_strcmpCase = tcase_create("s21_strcmpCase");
  suite_add_tcase(suite, s21_strcmpCase);
  tcase_add_test(s21_strcmpCase, test_s21_strcmp);
  // 10
  TCase *s21_strncmpCase = tcase_create("s21_strncmpCase");
  suite_add_tcase(suite, s21_strncmpCase);
  tcase_add_test(s21_strncmpCase, test_s21_strncmp);
  // 11
  TCase *s21_strcpyCase = tcase_create("s21_strcpyCase");
  suite_add_tcase(suite, s21_strcpyCase);
  tcase_add_test(s21_strcpyCase, test_s21_strcpy);
  // 12
  TCase *s21_strncpyCase = tcase_create("s21_strncpyCase");
  suite_add_tcase(suite, s21_strncpyCase);
  tcase_add_test(s21_strncpyCase, test_s21_strncpy);
  // 13
  TCase *s21_strcspnCase = tcase_create("s21_strcspnCase");
  suite_add_tcase(suite, s21_strcspnCase);
  tcase_add_test(s21_strcspnCase, test_s21_strcspn);
  // 14
  TCase *s21_strerrorCase = tcase_create("s21_strerrorCase");
  suite_add_tcase(suite, s21_strerrorCase);
  tcase_add_test(s21_strerrorCase, test_s21_strerror);
  // 15
  TCase *s21_strlenCase = tcase_create("s21_strlenCase");
  suite_add_tcase(suite, s21_strlenCase);
  tcase_add_test(s21_strlenCase, test_s21_strlen);
  // 16
  TCase *s21_strpbrkCase = tcase_create("s21_strpbrkCase");
  suite_add_tcase(suite, s21_strpbrkCase);
  tcase_add_test(s21_strpbrkCase, test_s21_strpbrk);
  // 17
  TCase *s21_strrchrCase = tcase_create("s21_strrchrCase");
  suite_add_tcase(suite, s21_strrchrCase);
  tcase_add_test(s21_strrchrCase, test_s21_strrchr);
  // 18
  TCase *s21_strspnCase = tcase_create("s21_strspnCase");
  suite_add_tcase(suite, s21_strspnCase);
  tcase_add_test(s21_strspnCase, test_s21_strspn);
  // 19
  TCase *s21_strstrCase = tcase_create("s21_strstrCase");
  suite_add_tcase(suite, s21_strstrCase);
  tcase_add_test(s21_strstrCase, test_s21_strstr);
  // 20
  TCase *s21_strtokCase = tcase_create("s21_strtokCase");
  suite_add_tcase(suite, s21_strtokCase);
  tcase_add_test(s21_strtokCase, test_s21_strtok);
  // s21_sprintf
  TCase *s21_sprintfCase = tcase_create("s21_sprintfCase");
  suite_add_tcase(suite, s21_sprintfCase);
  tcase_add_test(s21_sprintfCase, test_s21_sprintf);
  // s21_sscanf
  TCase *s21_sscanfCase = tcase_create("s21_sscanfCase");
  suite_add_tcase(suite, s21_sscanfCase);
  tcase_add_test(s21_sscanfCase, test_s21_sscanf);
  // s21_to_upper
  TCase *s21_to_upperCase = tcase_create("s21_to_upperCase");
  suite_add_tcase(suite, s21_to_upperCase);
  tcase_add_test(s21_to_upperCase, test_s21_to_upper);
  // s21_to_lower
  TCase *s21_to_lowerCase = tcase_create("s21_to_lowerCase");
  suite_add_tcase(suite, s21_to_lowerCase);
  tcase_add_test(s21_to_lowerCase, test_s21_to_lower);
  // s21_insert
  TCase *s21_insertCase = tcase_create("s21_insertCase");
  suite_add_tcase(suite, s21_insertCase);
  tcase_add_test(s21_insertCase, test_s21_insert);
  // s21_trim
  TCase *s21_trimCase = tcase_create("s21_trimCase");
  suite_add_tcase(suite, s21_trimCase);
  tcase_add_test(s21_trimCase, test_s21_trim);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
