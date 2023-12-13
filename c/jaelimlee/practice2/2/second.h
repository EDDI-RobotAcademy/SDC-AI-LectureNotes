#ifndef __SECOND_H__
#define __SECOND_H__

#define MIN     (-999)
#define MAX      (999)

void config_random_seed(void);
int generate_random();
int generate_random2(const int min, const int max);

#endif