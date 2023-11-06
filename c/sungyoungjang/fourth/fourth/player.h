#define MAX_PLAYER_NAME_LENGTH	32
#define MAX_PLAYER_NUMBER	2
extern char player[MAX_PLAYER_NAME_LENGTH][MAX_PLAYER_NAME_LENGTH];


//  최상위 아젠다를 결정하고 만들다 보니\
	실제로 초기 계획과는 다른 형태로 코드가 구상하게됨\
	그래서 세부사항을 먼저 구현하면 망함\
	(생각은 현실과 다르다)
void set_player_info(char []);
void print_player_info(int);