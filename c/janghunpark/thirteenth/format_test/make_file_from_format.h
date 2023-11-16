#ifndef __MAKE_FILE_FROM_FORMAT_H__
#define __MAKE_FILE_FROM_FORMAT_H__

#include <stdbool.h>

#include "format_test.h"

void adjust_write_contents_from_format(char *contents, test_form *format);
bool write_format_to_file(test_form *);

#endif