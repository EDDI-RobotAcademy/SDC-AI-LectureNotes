#define MAX_PLAYER_NUMBER		2

extern char* player_nickname[MAX_PLAYER_NUMBER];
extern int player_count;
void init_player_nickname(char* nickname);
void print_player_list(void);