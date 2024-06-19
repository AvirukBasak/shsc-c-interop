#include "../include/shsc.h"
#include <stdio.h>

rt_Data_t shsc_add(rt_Data_t context, rt_DataList_t *numbers) {
    // validate input
    for (int i = 0; i < rt_DataList_length(numbers); ++i) {
        char str[1024] = {0};
        sprintf(str, "number[%d]", i);
        rt_Data_assert_type(
            *rt_DataList_getref(numbers, i),
            rt_DATA_TYPE_I64,
            str
        );
    }

    int64_t sum = 0;
    for (int i = 0; i < rt_DataList_length(numbers); ++i) {
        sum += rt_DataList_getref(numbers, i)->data.i64;
    }

    return rt_Data_i64(sum);
}
