#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


int _printf(const char *format, ...);
int _putchar(char c);
int str_print(char *str);
int num_print(int num);
int to_reverse(char *str);
int to_Rot13(char *str);

#endif
