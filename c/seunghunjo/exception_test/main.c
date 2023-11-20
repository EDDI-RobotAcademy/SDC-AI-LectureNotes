#include <stdio.h>

#include "utility/random.h"
#include "sample/exception.h"

int main (void)
{
    int i, j, k;
    int count = 0;
    int assume_error_random_number;
	printf("누가 goto 쓰지말라고 했어 ?\n");

    config_random_seed();
    assume_error_random_number = generate_random(10, 25);
    printf("에러값 = %d\n", assume_error_random_number);

    // There are no error.
    //assume_error_random_number = 77;

    // Nodap code.
    // for (i = 0; i < 3; i++)
    // {
    //     for (j = 0; j < 3; j++)
    //     {
    //         for (k = 0; k < 3; k++)
    //         {
    //             printf("count = %d\n", count++);
    //             if (count == assume_error_random_number)
    //             {
    //                 printf("에러가 발생했습니다!\n");
    //                 break;
    //             }
    //         }

    //         if (count == assume_error_random_number)
    //         {
    //             break;
    //         }
    //     }

    //     if (count == assume_error_random_number)
    //     {
    //         break;
    //     }
    // }

//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             for (k = 0; k < 3; k++)
//             {
//                 printf("count = %d\n", count++);
//                 if (count == assume_error_random_number)
//                 {
//                     printf("에러가 발생했습니다!\n");
//                     goto error_handler;
//                 }
//             }
//         }
//     }

// error_handler:
//     printf("지금부터 에러를 핸들링합니다!\n");

    exception_setup_table();
    divide_by_zero(7, generate_random(0, 1));
    array_index_exceed(10);

    return 0;
}