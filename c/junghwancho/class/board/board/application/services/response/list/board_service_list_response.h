#ifndef __BOARD_SERVICE_LIST_RESPONSE_H__
#define __BOARD_SERVICE_LIST_RESPONSE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _board_service_list_response board_service_list_response;

struct _board_service_list_response
{
    unsigned int id;
    char *title;
    char *writer;
};

board_service_list_response *init_board_service_list_response(
    unsigned int, char *title, char *writer);

char *get_board_service_list_response_id(board_service_list_response *);
char *get_board_service_list_response_title(board_service_list_response *);
char *get_board_service_list_response_writer(board_service_list_response *);

void clear_board_service_list_response(board_service_list_response *);

void print_board_service_list_response(board_service_list_response **);

#ifdef __cplusplus
}
#endif

#endif