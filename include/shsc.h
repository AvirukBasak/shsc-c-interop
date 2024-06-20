#ifndef __SHSC_H__
#define __SHSC_H__

#include <stdbool.h>
#include <stdint.h>

#if _WIN32
    #define SHSC_EXPORT __declspec(dllexport)
#else
    #define SHSC_EXPORT __attribute__((visibility("default")))
#endif

#define FN_MODIFIERS extern

/*------------------------
 |      AST STRUCTS      |
 ------------------------*/

typedef char ast_Identifier_t;
typedef struct ast_LambdaLiteral_t ast_LambdaLiteral_t;
typedef struct ast_Statement_t ast_Statement_t;

/*------------------------
 |      DATA TYPES       |
 ------------------------*/

typedef struct shsc_rt_Data_t shsc_rt_Data_t;
typedef struct shsc_rt_DataStr_t shsc_rt_DataStr_t;
typedef struct shsc_rt_DataList_t shsc_rt_DataList_t;
typedef struct shsc_rt_DataMap_t shsc_rt_DataMap_t;
typedef struct shsc_rt_DataProc_t shsc_rt_DataProc_t;
typedef struct shsc_rt_DataNativeFn_t shsc_rt_DataNativeFn_t;
typedef struct shsc_rt_DataLambda_t shsc_rt_DataLambda_t;
typedef struct shsc_rt_DataLibHandle_t shsc_rt_DataLibHandle_t;

/**
 * Prototype of a function defined in shared library
 * and called from the runtime.
 */
typedef shsc_rt_Data_t(*shsc_rt_fn_NativeFunction_t)(const shsc_rt_Data_t context, shsc_rt_DataList_t *args);

/* based on the mapping of datatype IDs provided
   by the Shsc IR Spec
   https://github.com/AvirukBasak/shsc-runtime/docs/ShscIrSpec.md */
enum shsc_rt_DataType_t {
    shsc_rt_DATA_TYPE_BUL = 0,        /* boolean        : 1 B */
    shsc_rt_DATA_TYPE_CHR = 1,        /* char           : 1 B */
    shsc_rt_DATA_TYPE_I64 = 2,        /* int64_t        : 8 B */
    shsc_rt_DATA_TYPE_F64 = 3,        /* double         : 8 B */
    shsc_rt_DATA_TYPE_STR = 4,        /* char*          : variable  */
    shsc_rt_DATA_TYPE_INTERP_STR = 5, /* parsable char* : variable  */
    shsc_rt_DATA_TYPE_LST = 6,        /* list           : variable  */
    shsc_rt_DATA_TYPE_ANY = 7,        /* void*          : undefined */
    shsc_rt_DATA_TYPE_MAP = 8,        /* hash map       : variable  */
    shsc_rt_DATA_TYPE_PROC = 9,       /* procedure      : ??  */
    shsc_rt_DATA_TYPE_LAMBDA = 10,    /* lambda         : ??  */
    shsc_rt_DATA_TYPE_LIBHANDLE = 11, /* lib handle     : ??  */
};

struct shsc_rt_DataProc_t {
    const ast_Identifier_t *module_name;
    const ast_Identifier_t *proc_name;
    const shsc_rt_Data_t *context;
};

enum shsc_rt_DataLambdaType_t {
    shsc_rt_DATA_LAMBDA_TYPE_NONNATIVE = 0,
    shsc_rt_DATA_LAMBDA_TYPE_NATIVE = 1,
};

struct shsc_rt_DataNativeFn_t {
    shsc_rt_DataLibHandle_t *handle;
    shsc_rt_DataStr_t *fn_name;
    shsc_rt_fn_NativeFunction_t fn;
};

struct shsc_rt_DataLambda_t {
    const shsc_rt_Data_t *context;
    union {
        const ast_LambdaLiteral_t *nonnative;
        shsc_rt_DataNativeFn_t native;
    } fnptr;
    enum shsc_rt_DataLambdaType_t type;
};

/**
 * Shsc shsc_rt_Data_t should not be used unless the purpose is to
 * interact with Shsc data. Shsc data is reference counted
 * and involves a large amount of overhead.
 * Intead, make use of native data structures.
 */
struct shsc_rt_Data_t {
    union {
        bool bul;
        char chr;
        int64_t i64;
        double f64;
        shsc_rt_DataStr_t *str;
        shsc_rt_DataList_t *lst;
        shsc_rt_DataMap_t *mp;
        shsc_rt_DataProc_t proc;
        shsc_rt_DataLambda_t lambda;
        shsc_rt_DataLibHandle_t *libhandle;
        void *any;
    } data;
    bool is_const;
    bool is_weak;
    bool lvalue;
    enum shsc_rt_DataType_t type;
};

FN_MODIFIERS shsc_rt_Data_t          (* shsc_rt_Data_bul)         (bool            val);
FN_MODIFIERS shsc_rt_Data_t          (* shsc_rt_Data_chr)         (char            val);
FN_MODIFIERS shsc_rt_Data_t          (* shsc_rt_Data_i64)         (int64_t         val);
FN_MODIFIERS shsc_rt_Data_t          (* shsc_rt_Data_f64)         (double          val);
FN_MODIFIERS shsc_rt_Data_t          (* shsc_rt_Data_str)         (shsc_rt_DataStr_t   *str);
FN_MODIFIERS shsc_rt_Data_t          (* shsc_rt_Data_list)        (shsc_rt_DataList_t  *lst);
FN_MODIFIERS shsc_rt_Data_t          (* shsc_rt_Data_map)         (shsc_rt_DataMap_t   *mp);
FN_MODIFIERS shsc_rt_Data_t          (* shsc_rt_Data_any)         (void           *ptr);
FN_MODIFIERS shsc_rt_Data_t          (* shsc_rt_Data_null)        (void);
FN_MODIFIERS shsc_rt_Data_t          (* shsc_rt_Data_clone)       (const shsc_rt_Data_t var);
FN_MODIFIERS void               (* shsc_rt_Data_destroy)     (shsc_rt_Data_t      *var);
FN_MODIFIERS bool               (* shsc_rt_Data_isnull)      (const shsc_rt_Data_t var);
FN_MODIFIERS bool               (* shsc_rt_Data_isnumeric)   (const shsc_rt_Data_t var);
FN_MODIFIERS bool               (* shsc_rt_Data_isequal)     (const shsc_rt_Data_t var1, const shsc_rt_Data_t    var2);
FN_MODIFIERS int64_t            (* shsc_rt_Data_compare)     (const shsc_rt_Data_t var1, const shsc_rt_Data_t    var2);
FN_MODIFIERS bool               (* shsc_rt_Data_tobool)      (const shsc_rt_Data_t var);
FN_MODIFIERS char              *(* shsc_rt_Data_tostr)       (const shsc_rt_Data_t var);
FN_MODIFIERS shsc_rt_Data_t          (* shsc_rt_Data_cast)        (const shsc_rt_Data_t var,  enum shsc_rt_DataType_t type);
FN_MODIFIERS const char        *(* shsc_rt_Data_typename)    (const shsc_rt_Data_t var);
FN_MODIFIERS bool               (* shsc_rt_Data_asseshsc_rt_type) (const shsc_rt_Data_t var,  enum shsc_rt_DataType_t expected_type, const char *for_varname);
FN_MODIFIERS enum shsc_rt_DataType_t (* shsc_rt_Data_greater_type)(const shsc_rt_Data_t var1, const shsc_rt_Data_t    var2);
FN_MODIFIERS int                (* shsc_rt_Data_print)       (const shsc_rt_Data_t var);

/*------------------------
 |       VAR TABLE        |
 ------------------------*/

/**
 * This function is used to modify the value of a variable that exists
 * in the variable table. It takes care of reference counts.
 */
FN_MODIFIERS void               (* shsc_rt_VarTable_modf)    (shsc_rt_Data_t *dest, shsc_rt_Data_t src);

/*------------------------
 |       LIST DATA       |
 ------------------------*/

/* macro that takes a variable number of shsc_rt_Data_t type arguments
   and calls shsc_rt_DataList_append for each item */
#define shsc_rt_DataList_from(...)                                \
    ({                                                       \
        shsc_rt_Data_t _args[] = { __VA_ARGS__ };                 \
        size_t args_len = sizeof(_args) / sizeof(shsc_rt_Data_t); \
        shsc_rt_DataList_t *lst = shsc_rt_DataList_init();             \
        for (size_t i = 0; i < args_len; i++) {              \
            shsc_rt_DataList_append(lst, _args[i]);               \
        }                                                    \
        lst;                                                 \
    })

/**
 * List types should not be used unless the purpose is to
 * interact with Shsc lists. Shsc lists are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C arrays or other native data structures.
 */
FN_MODIFIERS shsc_rt_DataList_t     *(* shsc_rt_DataList_init)();

/**
 * List types should not be used unless the purpose is to
 * interact with Shsc lists. Shsc lists are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C arrays or other native data structures.
 */
FN_MODIFIERS shsc_rt_DataList_t *    (* shsc_rt_DataList_clone)         (const shsc_rt_DataList_t *lst);

FN_MODIFIERS int64_t            (* shsc_rt_DataList_length)        (const shsc_rt_DataList_t *lst);
FN_MODIFIERS void               (* shsc_rt_DataList_destroy)       (shsc_rt_DataList_t      **ptr);
FN_MODIFIERS bool               (* shsc_rt_DataList_isequal)       (const shsc_rt_DataList_t *lst1, const shsc_rt_DataList_t *lst2);
FN_MODIFIERS int64_t            (* shsc_rt_DataList_compare)       (const shsc_rt_DataList_t *lst1, const shsc_rt_DataList_t *lst2);
FN_MODIFIERS void               (* shsc_rt_DataList_append)        (shsc_rt_DataList_t       *lst,  shsc_rt_Data_t            var);
FN_MODIFIERS void               (* shsc_rt_DataList_concat)        (shsc_rt_DataList_t       *lst,  const shsc_rt_DataList_t *lst2);
FN_MODIFIERS void               (* shsc_rt_DataList_insert)        (shsc_rt_DataList_t       *lst,  int64_t              idx,   shsc_rt_Data_t var);
FN_MODIFIERS void               (* shsc_rt_DataList_erase)         (shsc_rt_DataList_t       *lst,  int64_t              idx,   int64_t   len);
FN_MODIFIERS void               (* shsc_rt_DataList_reverse)       (shsc_rt_DataList_t       *lst);
FN_MODIFIERS int64_t            (* shsc_rt_DataList_find)          (const shsc_rt_DataList_t *lst,  shsc_rt_Data_t            var);
FN_MODIFIERS shsc_rt_DataList_t     *(* shsc_rt_DataList_sublist)       (const shsc_rt_DataList_t *lst,  int64_t              idx,   int64_t   len);
FN_MODIFIERS shsc_rt_DataStr_t      *(* shsc_rt_DataList_join)          (const shsc_rt_DataList_t *lst,  const shsc_rt_DataStr_t  *sep);
FN_MODIFIERS shsc_rt_DataList_t     *(* shsc_rt_DataList_sort)          (shsc_rt_DataList_t       *lst);
FN_MODIFIERS shsc_rt_Data_t         *(* shsc_rt_DataList_getref_errnull)(const shsc_rt_DataList_t *lst,  int64_t              idx);

/** data should be updated only by calling
    `void shsc_rt_VarTable_modf(shsc_rt_Data_t *dest, shsc_rt_Data_t src)`
    on the returned data pointer, that'll take care of reference counts */
FN_MODIFIERS shsc_rt_Data_t         *(* shsc_rt_DataList_getref)        (const shsc_rt_DataList_t *lst, int64_t   idx);

FN_MODIFIERS void               (* shsc_rt_DataList_del_index)     (shsc_rt_DataList_t       *lst, int64_t   idx);
FN_MODIFIERS void               (* shsc_rt_DataList_del_val)       (shsc_rt_DataList_t       *lst, shsc_rt_Data_t var);
FN_MODIFIERS char              *(* shsc_rt_DataList_tostr)         (const shsc_rt_DataList_t *lst);

/*------------------------
 |       MAP DATA        |
 ------------------------*/

/**
 * Map types should not be used unless the purpose is to
 * interact with Shsc maps. Shsc maps are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C hash maps or other native data structures.
 */
FN_MODIFIERS shsc_rt_DataMap_t      *(* shsc_rt_DataMap_init)();

/**
 * Map types should not be used unless the purpose is to
 * interact with Shsc maps. Shsc maps are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C hash maps or other native data structures.
 */
FN_MODIFIERS shsc_rt_DataMap_t      *(* shsc_rt_DataMap_clone)          (const shsc_rt_DataMap_t  *mp);

FN_MODIFIERS int64_t            (* shsc_rt_DataMap_length)         (const shsc_rt_DataMap_t  *mp);
FN_MODIFIERS void               (* shsc_rt_DataMap_destroy)        (shsc_rt_DataMap_t       **ptr);
FN_MODIFIERS void               (* shsc_rt_DataMap_insert)         (shsc_rt_DataMap_t        *mp,   const char         *key,  shsc_rt_Data_t value);
FN_MODIFIERS void               (* shsc_rt_DataMap_del)            (shsc_rt_DataMap_t        *mp,   const char         *key);
FN_MODIFIERS void               (* shsc_rt_DataMap_concat)         (const shsc_rt_DataMap_t  *mp1,  const shsc_rt_DataMap_t *mp2);
FN_MODIFIERS const char        *(* shsc_rt_DataMap_getkey_copy)    (const shsc_rt_DataMap_t  *mp,   const char         *key);

/** unlike shsc_rt_DataMap_getref, returns NULL if key not found */
FN_MODIFIERS shsc_rt_Data_t         *(* shsc_rt_DataMap_getref_errnull) (const shsc_rt_DataMap_t *mp,    const char         *key);

/** unlike shsc_rt_DataMap_getref_errnull, CRASHES using shsc_rt_throw if key not found.
    data should be updated only by calling
    `void shsc_rt_VarTable_modf(shsc_rt_Data_t *dest, shsc_rt_Data_t src)`
    on the returned data pointer, that'll take care of reference counts */
FN_MODIFIERS shsc_rt_Data_t         *(* shsc_rt_DataMap_getref)         (const shsc_rt_DataMap_t *mp,     const char        *key);

FN_MODIFIERS char              *(* shsc_rt_DataMap_tostr)          (const shsc_rt_DataMap_t *mp);

/*------------------------
 |       STR DATA        |
 ------------------------*/

/**
 * String types should not be used unless the purpose is to
 * interact with Shsc strings. Shsc strings are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C strings or other native data structures.
 */
FN_MODIFIERS shsc_rt_DataStr_t      *(* shsc_rt_DataStr_init)(const char *s);

/**
 * String types should not be used unless the purpose is to
 * interact with Shsc strings. Shsc strings are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C strings or other native data structures.
 */
FN_MODIFIERS shsc_rt_DataStr_t      *(* shsc_rt_DataStr_clone)          (const shsc_rt_DataStr_t *str);

FN_MODIFIERS int64_t            (* shsc_rt_DataStr_length)         (const shsc_rt_DataStr_t *str);
FN_MODIFIERS void               (* shsc_rt_DataStr_destroy)        (shsc_rt_DataStr_t       **ptr);
FN_MODIFIERS void               (* shsc_rt_DataStr_toupper)        (shsc_rt_DataStr_t        *str);
FN_MODIFIERS void               (* shsc_rt_DataStr_tolower)        (shsc_rt_DataStr_t        *str);
FN_MODIFIERS void               (* shsc_rt_DataStr_append)         (shsc_rt_DataStr_t        *str, char                 ch);
FN_MODIFIERS void               (* shsc_rt_DataStr_concat)         (shsc_rt_DataStr_t        *str, const shsc_rt_DataStr_t  *str2);
FN_MODIFIERS void               (* shsc_rt_DataStr_insert)         (shsc_rt_DataStr_t        *str, int64_t              idx, char                ch);
FN_MODIFIERS void               (* shsc_rt_DataStr_inseshsc_rt_str)     (shsc_rt_DataStr_t        *str, int64_t              idx, const shsc_rt_DataStr_t *str2);
FN_MODIFIERS void               (* shsc_rt_DataStr_erase)          (shsc_rt_DataStr_t        *str, int64_t              idx, int64_t             len);
FN_MODIFIERS void               (* shsc_rt_DataStr_reverse)        (shsc_rt_DataStr_t        *str);
FN_MODIFIERS bool               (* shsc_rt_DataStr_isequal)        (const shsc_rt_DataStr_t  *str, const shsc_rt_DataStr_t  *str2);
FN_MODIFIERS int64_t            (* shsc_rt_DataStr_compare)        (const shsc_rt_DataStr_t  *str, const shsc_rt_DataStr_t  *str2);
FN_MODIFIERS int64_t            (* shsc_rt_DataStr_find)           (const shsc_rt_DataStr_t  *str, char                 ch);
FN_MODIFIERS int64_t            (* shsc_rt_DataStr_find_str)       (const shsc_rt_DataStr_t  *str, const shsc_rt_DataStr_t  *str2);
FN_MODIFIERS shsc_rt_DataStr_t      *(* shsc_rt_DataStr_substr)         (const shsc_rt_DataStr_t  *str, int64_t idx, int64_t len);
FN_MODIFIERS shsc_rt_DataList_t     *(* shsc_rt_DataStr_split)          (const shsc_rt_DataStr_t  *str, char                 ch);
FN_MODIFIERS shsc_rt_DataList_t     *(* shsc_rt_DataStr_split_str)      (const shsc_rt_DataStr_t  *str, const shsc_rt_DataStr_t  *str2);
FN_MODIFIERS shsc_rt_DataStr_t      *(* shsc_rt_DataStr_sort)           (shsc_rt_DataStr_t        *str);
FN_MODIFIERS shsc_rt_Data_t          (* shsc_rt_DataStr_toi64)          (const shsc_rt_DataStr_t  *str);
FN_MODIFIERS shsc_rt_Data_t          (* shsc_rt_DataStr_tof64)          (const shsc_rt_DataStr_t  *str);
FN_MODIFIERS char              *(* shsc_rt_DataStr_getref_errnull) (const shsc_rt_DataStr_t  *str, int64_t idx);

/** data can be updated by assigning a char to the returned pointer */
FN_MODIFIERS shsc_rt_Data_t         *(* shsc_rt_DataStr_getref)(const shsc_rt_DataStr_t *str, int64_t idx);

FN_MODIFIERS void               (* shsc_rt_DataStr_del_index)      (shsc_rt_DataStr_t *str, int64_t idx);
FN_MODIFIERS void               (* shsc_rt_DataStr_del_char)       (shsc_rt_DataStr_t *str, char ch);
FN_MODIFIERS char              *(* shsc_rt_DataStr_tostr)          (const shsc_rt_DataStr_t *str);

/*------------------------
 |  RUNTIME FUNCTIONS    |
 ------------------------*/

/**
 * Throws a runtime error with the given message.
 * The message can be formatted using printf-style format specifiers.
 */
FN_MODIFIERS void (* shsc_rt_throw)(const char *fmt, ...) __attribute__((format(printf, 1, 2)));

/*------------------------
 | FUNCTION CALL HANDLER |
 ------------------------*/

/**
 * Calls shsc_rt_throw if the number of arguments is less than min_expected_argc.
 * Results in a runtime error.
 */
FN_MODIFIERS const shsc_rt_DataList_t *(* shsc_rt_fn_get_valid_args)(int64_t min_expected_argc);

/**
 * Call a function given the module name, procedure name and arguments.
 * Useful for calling predefined shsc functions.
 *
 * Example:
 *
 * ```c
 * // take in input from user
 * const shsc_rt_DataStr_t *prompt_str = shsc_rt_DataStr_init("Enter two numbers: ");
 * const shsc_rt_Data_t prompt_var = shsc_rt_Data_str(prompt_str);
 *
 * shsc_rt_Data_t input = shsc_rt_fn_call_handler(shsc_rt_Data_null(), "io", "input", shsc_rt_DataList_from(
 *     prompt_var,
 *     shsc_rt_Data_i64(shsc_rt_DATA_TYPE_I64)
 * ));
 *
 * shsc_rt_DataStr_destroy(&prompt_str);
 * ```
 */
FN_MODIFIERS shsc_rt_Data_t (* shsc_rt_fn_call_handler)(
    const shsc_rt_Data_t context,
    const char *module_name,
    const char *proc_name,
    shsc_rt_DataList_t *args
);

/**
 * This function is provided for calling lambda functions.
 * Such lambda functions may be passed by from Shsc code as callbacks.
 */
FN_MODIFIERS shsc_rt_Data_t (* shsc_rt_fn_lambda_call_handler)(
    const shsc_rt_Data_t context,
    const shsc_rt_DataLambda_t lambda,
    shsc_rt_DataList_t *args
);

/*------------------------
 |       OPERATORS       |
 ------------------------*/

FN_MODIFIERS void (* shsc_rt_op_ampersand)              (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_arith_rshift)           (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_assign)                 (shsc_rt_Data_t       *lhs, const shsc_rt_Data_t *rhs, bool is_const, bool is_weak);
FN_MODIFIERS void (* shsc_rt_op_asterix)                (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_bang)                   (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_bitwise_lshift)         (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_bitwise_rshift)         (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_caret)                  (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_decrement)              (shsc_rt_Data_t       *lhs, shsc_rt_Data_t       *rhs);
FN_MODIFIERS void (* shsc_rt_op_dot)                    (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_exponent)               (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_floor_divide)           (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_fslash)                 (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_increment)              (shsc_rt_Data_t       *lhs, shsc_rt_Data_t       *rhs);
FN_MODIFIERS void (* shsc_rt_op_lbrace_angular)         (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_logical_and)            (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_logical_equal)          (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_logical_greater_equal)  (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_logical_lesser_equal)   (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_logical_or)             (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_logical_unequal)        (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_minus)                  (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_percent)                (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_pipe)                   (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_plus)                   (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_rbrace_angular)         (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_tilde)                  (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_fnargs_indexing)        (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_fncall)                 (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_indexing)               (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs);
FN_MODIFIERS void (* shsc_rt_op_nop)                    (const shsc_rt_Data_t *lhs);
FN_MODIFIERS void (* shsc_rt_op_ternary_cond)           (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs, const shsc_rt_Data_t *condition);

#endif
