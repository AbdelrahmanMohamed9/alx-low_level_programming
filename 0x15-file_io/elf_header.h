#ifndef ELF_HEADER_H
#define ELF_HEADER_H

void check_elf(unsigned char *e_id);
void print_magic(unsigned char *e_id);
void print_class(unsigned char *e_id);
void print_data(unsigned char *e_id);
void print_version(unsigned char *e_id);
void print_abi(unsigned char *e_id);
void print_osabi(unsigned char *e_id);
void print_type(unsigned int e_tp, unsigned char *e_id);
void print_entry(unsigned long int e_ent, unsigned char *e_id);
void close_elf(int ce);

#endif
