#ifndef __VECTOR_IN_MEMORY_COMMAND_H__
#define __VECTOR_IN_MEMORY_COMMAND_H__

enum vector_in_memory_command
{
    VECTOR_IN_MEMORY_STORE,
    VECTOR_IN_MEMORY_END
};

#define VECTOR_IN_MEMORY_BUFFER_COUNT           (VECTOR_IN_MEMORY_END)
#define VECTOR_IN_MEMORY_BUFFER                 ((VECTOR_IN_MEMORY_END) - 1)

#endif
