#ifndef __BOARD_SERVICE_CREATE_REQUEST_H__
#define __BOARD_SERVICE_CREATE_REQUEST_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _board_service_create_request board_service_create_request;

struct _board_service_create_request
{
    char *title;
    char *writer;
    char *content;
};

board_service_create_request *init_board_service_create_request(
    char *title, char *writer, char *content);

char *get_board_service_create_request_title(board_service_create_request *);
char *get_board_service_create_request_writer(board_service_create_request *);
char *get_board_service_create_request_content(board_service_create_request *);

void clear_board_service_create_request(board_service_create_request *);

#ifdef __cplusplus
}
#endif

#endif