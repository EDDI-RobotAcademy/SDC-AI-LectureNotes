#ifndef __GRAMMAR_PROB_SECOND_H__
#define __GRAMMAR_PROB_SECOND_H__

#define MIN             1
#define MAX             12

void print_random_number(void);
void print_random_number_and_alloc_to_global(void);
int get_allocated_global_random_number(void);
void print_random_number_from_main_parameter_transfer(const int min, const int max);

extern int generated_random_number;

#endif