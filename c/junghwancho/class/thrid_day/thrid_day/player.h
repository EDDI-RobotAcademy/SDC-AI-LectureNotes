#define PLAYER_NAME_MAX		32

extern char player_name[PLAYER_NAME_MAX];
extern char player1[PLAYER_NAME_MAX];
extern char player2[PLAYER_NAME_MAX];


void set_player_name(char name[]);
void set_player1(char name[]);
void set_player2(char name[]);

void print_player_name(void);