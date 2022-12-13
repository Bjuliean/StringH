#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list va;
  va_start(va, format);
  int space_count = 0;
  str[0] = '\0';
  str[1] = '\0';
  while (*format != '\0') {
    if (*format == '%') {
      format++;
      format = parser(va, format, str);
    } else {
      str[s21_strlen(str)] = *format;
      str[s21_strlen(str) + 1] = '\0';
      space_count++;
      str++;
    }
    format++;
  }
  str[s21_strlen(str)] = '\0';
  va_end(va);
  return (s21_strlen(str) + space_count);
}

const char *parser(va_list va, const char *format, char *str) {
  struct specifics_list specifics = {0};
  if (*format == '%') {
    str[s21_strlen(str)] = *format;
    str[s21_strlen(str) + 1] = '\0';
  } else {
    while (flagcheck(*format, &specifics)) {
      format++;
    }
    if (Is_digit(*format)) {
      iswidth(format, &specifics, 1);
      while (Is_digit(*format)) format++;
    }
    if (*format == '.') {
      format++;
      iswidth(format, &specifics, 2);
      while (Is_digit(*format)) format++;
    }
    if (is_len(*format, &specifics)) {
      format++;
    }
    check_type(va, *format, str, &specifics);
  }
  return format;
}

int is_len(char leter, struct specifics_list *specifics) {
  switch (leter) {
    case 'h':
      specifics->length_h++;
      break;
    case 'l':
      specifics->length_l++;
      break;
  }
  return specifics->length_h != 0 || specifics->length_l != 0 ? 1 : 0;
}

int flagcheck(char format, struct specifics_list *specifics) {
  int find_flag = 0;
  switch (format) {
    case '+':
      specifics->flag_plus++;
      find_flag++;
      break;
    case '-':
      specifics->flag_minus++;
      find_flag++;
      break;
    case ' ':
      specifics->flag_space++;
      find_flag++;
      break;
  }
  return find_flag != 0 ? 1 : 0;
}

int iswidth(const char *format, struct specifics_list *specifics, int form) {
  int width = 0;
  while (Is_digit(*format)) {
    if (form == 2 && *format == '0') specifics->is_acc_zero = 1;
    if (width != 0) width *= 10;
    width += ((int)*format - 48);
    format++;
  }
  if (form == 1)
    specifics->width = width;
  else
    specifics->accur = width;
  return (form == 1 && specifics->width != 0) ||
                 (form == 2 && specifics->accur != 0)
             ? 1
             : 0;
}

int Is_digit(char leter) { return leter > 47 && leter < 58 ? 1 : 0; }

void check_type(va_list va, char leter_to_check, char *str,
                struct specifics_list *specifics) {
  switch (leter_to_check) {
    case 'd':
      parser_to_int(specifics, va, str);
      break;
    case 'c':
      out_char(va, str, specifics);
      break;
    case 's':
      out_str(va, str, specifics);
      break;
    case 'f':
      parser_to_float(specifics, va, str);
      break;
    case 'i':
      parser_to_int(specifics, va, str);
      break;
    case 'u':
      specifics->flag_plus = 0;
      specifics->flag_space = 0;
      parser_to_unsigned(specifics, va, str);
      break;
  }
}

void parser_to_float(struct specifics_list *specifics, va_list va, char *str) {
  if (specifics->is_acc_zero == 0 && specifics->accur == 0)
    specifics->accur = 6;
  if (specifics->length_l != 0) {
    long double number = (long double)va_arg(va, double);
    out_float(str, specifics, number);
  } else {
    long double number = (long double)va_arg(va, double);
    out_float(str, specifics, number);
  }
}

void parser_to_unsigned(struct specifics_list *specifics, va_list va,
                        char *str) {
  if (specifics->length_h != 0) {
    unsigned short int number = (unsigned short int)va_arg(va, int);
    out_int(str, specifics, number);
  } else if (specifics->length_l != 0) {
    uint64_t number = va_arg(va, uint64_t);
    out_int(str, specifics, number);
  } else {
    unsigned int number = va_arg(va, unsigned int);
    out_int(str, specifics, number);
  }
}

void parser_to_int(struct specifics_list *specifics, va_list va, char *str) {
  if (specifics->length_h != 0) {
    short int number = (short int)va_arg(va, int);
    out_int(str, specifics, number);
  } else if (specifics->length_l != 0) {
    long int number = va_arg(va, long int);
    out_int(str, specifics, number);
  } else {
    int number = va_arg(va, int);
    out_int(str, specifics, number);
  }
}

void add_flag(char *num_to_str, int *iter, struct specifics_list *specifics) {
  if (specifics->flag_plus != 0) {
    num_to_str[*iter] = '+';
    *iter = *iter + 1;
  } else if (specifics->flag_space != 0) {
    num_to_str[*iter] = ' ';
    *iter = *iter + 1;
  }
}

void out_int(char *str, struct specifics_list *specifics,
             long long int number) {
  char num_to_str[1000] = {'\0'};
  char revers_num[1000] = {'\0'};
  int count = 0;
  int iter = 0;
  if (number < 0) {
    num_to_str[iter] = '-';
    iter++;
    number = -number;
  } else
    add_flag(num_to_str, &iter, specifics);
  while (number != 0) {
    revers_num[count] = "0123456789"[number % 10];
    count++;
    number /= 10;
  }
  add_zero(num_to_str, specifics, &iter, s21_strlen(revers_num));
  while (count > 0) {
    num_to_str[iter] = revers_num[count - 1];
    count--;
    iter++;
  }
  fil_in_str(str, specifics, num_to_str);
}

void add_zero(char *num_to_str, struct specifics_list *specifics, int *iter,
              int str_rev) {
  for (; 0 < specifics->accur - str_rev; specifics->accur--) {
    num_to_str[*iter] = '0';
    *iter = *iter + 1;
  }
}

void out_float(char *str, struct specifics_list *specifics,
               long double number) {
  int count = 0, iter = 0, number_int = (int)number;
  char num_to_str[3000] = {'\0'};
  char num_reverse[3000] = {'\0'};
  if (number - number_int != 0) number = number - number_int;
  if (number < 0) {
    num_to_str[iter] = '-';
    iter++;
    number = -number;
    number_int = -number_int;
  } else
    add_flag(num_to_str, &iter, specifics);
  if (number_int == 0) {
    count++;
    num_reverse[count - 1] = '0';
  }
  while (number_int != 0) {
    count++;
    num_reverse[count - 1] = "0123456789"[number_int % 10];
    number_int /= 10;
  }
  while (count > 0) {
    num_to_str[iter] = num_reverse[count - 1];
    count--;
    iter++;
  }
  if (specifics->accur != 0) {
    num_to_str[iter] = '.';
    iter++;
  }
  for (int i = 1; i <= specifics->accur; i++) {
    number *= 10.0;
    if (i == (specifics->accur)) {
      number += 1 / pow(10, specifics->accur - 1);
      number_int = (int)number;
    } else {
      number += 1 / pow(10, specifics->accur);
      number_int = (int)number;
    }
    num_to_str[iter] = "0123456789"[number_int % 10];
    iter++;
    number = number - (int)number;
  }
  fil_in_str(str, specifics, num_to_str);
}

void out_char(va_list va, char *str, struct specifics_list *specifics) {
  char in_symb = va_arg(va, int);
  for (; specifics->width - 1 > 0; specifics->width--) {
    str[s21_strlen(str)] = ' ';
    str[s21_strlen(str) + 1] = '\0';
    str++;
  }
  str[s21_strlen(str)] = in_symb;
  str[s21_strlen(str) + 1] = '\0';
}

void out_str(va_list va, char *str, struct specifics_list *specifics) {
  char *in_str = va_arg(va, char *);
  int iter = 0;
  char num_to_str2[10000] = {'\0'};
  if (specifics->accur == 0 && specifics->is_acc_zero == 0)
    specifics->accur = s21_strlen(in_str);
  int skoka_bukov = specifics->accur > (int)s21_strlen(in_str)
                        ? (int)s21_strlen(in_str)
                        : specifics->accur;
  for (; skoka_bukov > 0; skoka_bukov--) {
    num_to_str2[iter] = in_str[iter];
    iter++;
  }
  fil_in_str(str, specifics, num_to_str2);
}

void fil_in_str(char *str, struct specifics_list *specifics, char *num_to_str) {
  int iter = 0;
  if (specifics->flag_minus != 0) {
    while (num_to_str[iter] != '\0') {
      str[s21_strlen(str)] = num_to_str[iter];
      str[s21_strlen(str) + 1] = '\0';
      str++;
      iter++;
    }
  }
  for (; (specifics->width - (int)s21_strlen(num_to_str)) > 0;
       specifics->width--) {
    str[s21_strlen(str)] = ' ';
    str[s21_strlen(str) + 1] = '\0';
    str++;
  }
  if (specifics->flag_minus == 0) {
    while (num_to_str[iter] != '\0') {
      str[s21_strlen(str)] = num_to_str[iter];
      str[s21_strlen(str) + 1] = '\0';
      str++;
      iter++;
    }
  }
}
