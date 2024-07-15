#include <stdio.h>
#include "shsc.h"
#include "shscproto.h"

rt_Data_t shsc_add(rt_Data_t this, rt_DataList_t *args) {
    // validate input
    for (int i = 0; i < shsc_DataList_length(args); ++i) {
        char str[1024] = {0};
        sprintf(str, "number[%d]", i);

        // complex, adds a stack frame for better error messages
        shsc_call_fn(
            shsc_Data_null(),
            "assert", "type",
            shsc_DataList_from(
                *shsc_DataList_getref(args, i),
                shsc_Data_i64(rt_DATA_TYPE_I64),
                shsc_Data_str(shsc_DataStr_init(str))
            )
        );

        // alternative, simpler
        // shsc_Data_assert_type(
        //     *shsc_DataList_getref(numbers, i),
        //     rt_DATA_TYPE_I64,
        //     str
        // );
    }

    rt_Data_t file = shsc_call_fn(
        shsc_Data_null(),
        "dbg", "filename",
        shsc_DataList_from()
    );

    shsc_Data_incref(&file);

    // print this
    shsc_call_fn(
        shsc_Data_null(),
        "io", "print",
        shsc_DataList_from(
            file,
            shsc_Data_str(shsc_DataStr_init(": this")),
            this,
            shsc_Data_chr('\n')
        )
    );

    // print this
    shsc_call_fn(
        shsc_Data_null(),
        "io", "print",
        shsc_DataList_from(
            file,
            shsc_Data_str(shsc_DataStr_init(": reprinted filename to test incref")),
            shsc_Data_chr('\n')
        )
    );

    shsc_Data_destroy(&file);

    int64_t sum = 0;
    for (int i = 0; i < shsc_DataList_length(args); ++i) {
        sum += shsc_DataList_getref(args, i)->data.i64;
    }

    return shsc_Data_i64(sum);
}
