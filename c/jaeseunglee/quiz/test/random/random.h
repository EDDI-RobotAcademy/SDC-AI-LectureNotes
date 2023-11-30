
#define RANDOM_MIN -10
#define RANDOM_MAX  10
#define SIGNIFICANT 3
#define BASE_TEN            10


void random_config();
float generate_random_float(const int min, const int max);
int generate_random_int(const int min, const int max);

float random_float();
int random_int();

int process_for_expression_float(const int int_number, const int significant);

float generate_float_random_advanced(
    const int min, const int max, const int significant);
    