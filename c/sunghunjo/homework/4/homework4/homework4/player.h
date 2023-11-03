#define MAX_PERSON_NUMBER				2
#define MAX_PLAYER_NAME_LENGTH			32

extern char player_name[MAX_PERSON_NUMBER][MAX_PLAYER_NAME_LENGTH];

void set_player_info(char[]);
void print_player_info(int);

extern char* player_dynamic_array;

void set_name_to_char_dynamic_array(char* name);
void print_char_dynamic_array(void);