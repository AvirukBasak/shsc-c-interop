#include <stdio.h>
#include "shsc.h"

rt_Data_t shsc_add(rt_Data_t this, rt_DataList_t *args) {
    // validate input
    for (int i = 0; i < shsc_rt_DataList_length(args); ++i) {
        char str[1024] = {0};
        sprintf(str, "number[%d]", i);

        // complex, adds a stack frame for better error messages
        shsc_rt_fn_call_handler(
            shsc_rt_Data_null(),
            "assert", "type",
            shsc_rt_DataList_from(
                *shsc_rt_DataList_getref(args, i),
                shsc_rt_Data_i64(rt_DATA_TYPE_I64),
                shsc_rt_Data_str(shsc_rt_DataStr_init(str))
            )
        );

        // alternative, simpler
        // rt_Data_assert_type(
        //     *rt_DataList_getref(numbers, i),
        //     rt_DATA_TYPE_I64,
        //     str
        // );
    }

    // print this
    shsc_rt_fn_call_handler(
        shsc_rt_Data_null(),
        "io", "print",
        shsc_rt_DataList_from(
            shsc_rt_Data_str(shsc_rt_DataStr_init("this")),
            this,
            shsc_rt_Data_chr('\n')
        )
    );

    int64_t sum = 0;
    for (int i = 0; i < shsc_rt_DataList_length(args); ++i) {
        sum += shsc_rt_DataList_getref(args, i)->data.i64;
    }

    return shsc_rt_Data_i64(sum);
}
