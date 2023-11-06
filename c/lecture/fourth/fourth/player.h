#define MAX_PLAYER_NAME_LENGTH			32
#define MAX_PLAYER_NUMBER				2

extern char player[MAX_PLAYER_NUMBER][MAX_PLAYER_NAME_LENGTH];

// 최상위 아젠다를 결정하고 만들다 보니까
// 실제로 초기 계획과는 다른 형태로 코드가 구상되게 됨
// 그래서 세부 사항을 먼저 구현하면 망함
// (생각과 현실은 다르다)
void set_player_info(char []);
void print_player_info(int);
