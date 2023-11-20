#ifndef __RANDOM_H__
#define __RANDOM_H__

void config_random_seed(void);
int generate_random(const int min, const int max);
float generate_float_random(const int min, const int max, const int significant);
float generate_float_random_advanced(
    const int min, const int max, const int significant);

#endif