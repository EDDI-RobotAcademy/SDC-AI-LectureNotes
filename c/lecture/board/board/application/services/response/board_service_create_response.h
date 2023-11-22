#ifndef __BOARD_SERVICE_CREATE_RESPONSE_H__
#define __BOARD_SERVICE_CREATE_RESPONSE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _board_service_create_response board_service_create_response;

struct _board_service_create_response
{
    unsigned int id;
    char *title;
    char *writer;
    char *content;
};

board_service_create_response *init_board_service_create_response(
    unsigned int, char *title, char *writer, char *content);

char *get_board_service_create_response_title(board_service_create_response *);
char *get_board_service_create_response_writer(board_service_create_response *);
char *get_board_service_create_response_content(board_service_create_response *);

void clear_board_service_create_response(board_service_create_response *);

#ifdef __cplusplus
}
#endif

#endif