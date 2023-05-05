#ifndef MAIN_H
#define MAIN_H

int get_bit(unsigned long int f, unsigned int dx);
int set_bit(unsigned long int *f, unsigned int dx);
unsigned int flip_bits(unsigned long int f, unsigned long int y);
int get_endianness(void);
int clear_bit(unsigned long int *f, unsigned int dx);
int _putchar(char x);
unsigned int binary_to_uint(const char *d);
void print_binary(unsigned long int f);

#endif
