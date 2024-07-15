#ifndef __SHSC_H__
#define __SHSC_H__

#include <stdbool.h>
#include <stdint.h>

#include "shsctypes.h"

/**
 * Prototype of a function defined in shared library
 * and called from the runtime.
 */
typedef rt_Data_t(*rt_fn_NativeFunction_t)(const rt_Data_t context, rt_DataList_t *args);

/* based on the mapping of datatype IDs provided
   by the Shsc IR Spec
   https://github.com/AvirukBasak/shsc-runtime/docs/ShscIrSpec.md */
enum rt_DataType_t {
    rt_DATA_TYPE_BUL = 0,        /* boolean        : 1 B */
    rt_DATA_TYPE_CHR = 1,        /* char           : 1 B */
    rt_DATA_TYPE_I64 = 2,        /* int64_t        : 8 B */
    rt_DATA_TYPE_F64 = 3,        /* double         : 8 B */
    rt_DATA_TYPE_STR = 4,        /* char*          : variable  */
    rt_DATA_TYPE_INTERP_STR = 5, /* parsable char* : variable  */
    rt_DATA_TYPE_LST = 6,        /* list           : variable  */
    rt_DATA_TYPE_ANY = 7,        /* void*          : undefined */
    rt_DATA_TYPE_MAP = 8,        /* hash map       : variable  */
    rt_DATA_TYPE_PROC = 9,       /* procedure      : ??  */
    rt_DATA_TYPE_LAMBDA = 10,    /* lambda         : ??  */
    rt_DATA_TYPE_LIBHANDLE = 11, /* lib handle     : ??  */
};

struct rt_DataProc_t {
    const ast_Identifier_t *module_name;
    const ast_Identifier_t *proc_name;
    const rt_Data_t *context;
};

enum rt_DataLambdaType_t {
    rt_DATA_LAMBDA_TYPE_NONNATIVE = 0,
    rt_DATA_LAMBDA_TYPE_NATIVE = 1,
};

struct rt_DataNativeFn_t {
    rt_DataLibHandle_t *handle;
    rt_DataStr_t *fn_name;
    rt_fn_NativeFunction_t fn;
};

struct rt_DataLambda_t {
    const rt_Data_t *context;
    union {
        const ast_LambdaLiteral_t *nonnative;
        rt_DataNativeFn_t native;
    } fnptr;
    enum rt_DataLambdaType_t type;
};

/**
 * Shsc rt_Data_t should not be used unless the purpose is to
 * interact with Shsc data. Shsc data is reference counted
 * and involves a large amount of overhead.
 * Intead, make use of native data structures.
 */
struct rt_Data_t {
    union {
        bool bul;
        char chr;
        int64_t i64;
        double f64;
        rt_DataStr_t *str;
        rt_DataList_t *lst;
        rt_DataMap_t *mp;
        rt_DataProc_t proc;
        rt_DataLambda_t lambda;
        rt_DataLibHandle_t *libhandle;
        void *any;
    } data;
    bool is_const;
    bool is_weak;
    bool lvalue;
    enum rt_DataType_t type;
};

#include "shscproto.h"

#endif
