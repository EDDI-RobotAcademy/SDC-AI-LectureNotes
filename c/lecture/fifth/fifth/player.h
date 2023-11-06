#define MAX_PLAYER_NUMBER		2

extern char* player_nickname[MAX_PLAYER_NUMBER];
extern int player_count;

#define MAX_ROLL_NUMBER			2

extern int player_each_dice_number[MAX_PLAYER_NUMBER][MAX_ROLL_NUMBER];

void init_player_nickname(char* nickname);
void print_player_list(void);
