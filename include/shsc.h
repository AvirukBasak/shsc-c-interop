#ifndef __SHSC_H__
#define __SHSC_H__

#include <stdbool.h>
#include <stdint.h>

/*------------------------
 |      AST STRUCTS      |
 ------------------------*/

typedef char ast_Identifier_t;
typedef struct ast_LambdaLiteral_t ast_LambdaLiteral_t;
typedef struct ast_Statement_t ast_Statement_t;

/*------------------------
 |      DATA TYPES       |
 ------------------------*/

typedef struct rt_Data_t rt_Data_t;
typedef struct rt_DataStr_t rt_DataStr_t;
typedef struct rt_DataList_t rt_DataList_t;
typedef struct rt_DataMap_t rt_DataMap_t;
typedef struct rt_DataProc_t rt_DataProc_t;
typedef struct rt_DataNativeFn_t rt_DataNativeFn_t;
typedef struct rt_DataLambda_t rt_DataLambda_t;
typedef struct rt_DataLibHandle_t rt_DataLibHandle_t;

/**
 * Prototype of a function defined in shared library
 * and called from the runtime.
 */
typedef rt_Data_t (*rt_fn_NativeFunction_t)(const rt_Data_t context, rt_DataList_t *args);

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

rt_Data_t rt_Data_bul(bool val);
rt_Data_t rt_Data_chr(char val);
rt_Data_t rt_Data_i64(int64_t val);
rt_Data_t rt_Data_f64(double val);
rt_Data_t rt_Data_str(rt_DataStr_t *str);
rt_Data_t rt_Data_list(rt_DataList_t *lst);
rt_Data_t rt_Data_map(rt_DataMap_t *mp);
rt_Data_t rt_Data_any(void *ptr);
rt_Data_t rt_Data_null(void);

rt_Data_t rt_Data_clone(const rt_Data_t var);
void rt_Data_destroy(rt_Data_t *var);
bool rt_Data_isnull(const rt_Data_t var);
bool rt_Data_isnumeric(const rt_Data_t var);
bool rt_Data_isequal(const rt_Data_t var1, const rt_Data_t var2);
int64_t rt_Data_compare(const rt_Data_t var1, const rt_Data_t var2);
bool rt_Data_tobool(const rt_Data_t var);
char *rt_Data_tostr(const rt_Data_t var);
rt_Data_t rt_Data_cast(const rt_Data_t var, enum rt_DataType_t type);
const char *rt_Data_typename(const rt_Data_t var);
bool rt_Data_assert_type(
    const rt_Data_t var,
    enum rt_DataType_t expected_type,
    const char *for_varname
);
enum rt_DataType_t rt_Data_greater_type(const rt_Data_t var1, const rt_Data_t var2);
int rt_Data_print(const rt_Data_t var);

/*------------------------
 |       VAR TABLE        |
 ------------------------*/

/**
 * This function is used to modify the value of a variable that exists
 * in the variable table. It takes care of reference counts.
 */
void rt_VarTable_modf(rt_Data_t *dest, rt_Data_t src);

/*------------------------
 |       LIST DATA       |
 ------------------------*/

/* macro that takes a variable number of rt_Data_t type arguments
   and calls rt_DataList_append for each item */
#define rt_DataList_from(...)                                \
    ({                                                       \
        rt_Data_t _args[] = { __VA_ARGS__ };                 \
        size_t args_len = sizeof(_args) / sizeof(rt_Data_t); \
        rt_DataList_t *lst = rt_DataList_init();             \
        for (size_t i = 0; i < args_len; i++) {              \
            rt_DataList_append(lst, _args[i]);               \
        }                                                    \
        lst;                                                 \
    })

/**
 * List types should not be used unless the purpose is to
 * interact with Shsc lists. Shsc lists are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C arrays or other native data structures.
 */
rt_DataList_t *rt_DataList_init();

/**
 * List types should not be used unless the purpose is to
 * interact with Shsc lists. Shsc lists are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C arrays or other native data structures.
 */
rt_DataList_t *rt_DataList_clone(const rt_DataList_t *lst);

int64_t rt_DataList_length(const rt_DataList_t *lst);
void rt_DataList_destroy(rt_DataList_t **ptr);
bool rt_DataList_isequal(const rt_DataList_t *lst1, const rt_DataList_t *lst2);
int64_t rt_DataList_compare(const rt_DataList_t *lst1, const rt_DataList_t *lst2);
void rt_DataList_append(rt_DataList_t *lst, rt_Data_t var);
void rt_DataList_concat(rt_DataList_t *lst, const rt_DataList_t *lst2);
void rt_DataList_insert(rt_DataList_t *lst, int64_t idx, rt_Data_t var);
void rt_DataList_erase(rt_DataList_t *lst, int64_t idx, int64_t len);
void rt_DataList_reverse(rt_DataList_t *lst);
int64_t rt_DataList_find(const rt_DataList_t *lst, rt_Data_t var);
rt_DataList_t *rt_DataList_sublist(const rt_DataList_t *lst, int64_t idx, int64_t len);
rt_DataStr_t *rt_DataList_join(const rt_DataList_t *lst, const rt_DataStr_t *sep);
rt_DataList_t *rt_DataList_sort(rt_DataList_t *lst);
rt_Data_t *rt_DataList_getref_errnull(const rt_DataList_t *lst, int64_t idx);

/** data should be updated only by calling
    `void rt_VarTable_modf(rt_Data_t *dest, rt_Data_t src)`
    on the returned data pointer, that'll take care of reference counts */
rt_Data_t *rt_DataList_getref(const rt_DataList_t *lst, int64_t idx);

void rt_DataList_del_index(rt_DataList_t *lst, int64_t idx);
void rt_DataList_del_val(rt_DataList_t *lst, rt_Data_t var);
char *rt_DataList_tostr(const rt_DataList_t *lst);

/*------------------------
 |       MAP DATA        |
 ------------------------*/

/**
 * Map types should not be used unless the purpose is to
 * interact with Shsc maps. Shsc maps are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C hash maps or other native data structures.
 */
rt_DataMap_t *rt_DataMap_init();

/**
 * Map types should not be used unless the purpose is to
 * interact with Shsc maps. Shsc maps are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C hash maps or other native data structures.
 */
rt_DataMap_t *rt_DataMap_clone(const rt_DataMap_t *mp);

int64_t rt_DataMap_length(const rt_DataMap_t *mp);
void rt_DataMap_destroy(rt_DataMap_t **ptr);
void rt_DataMap_insert(rt_DataMap_t *mp, const char *key, rt_Data_t value);
void rt_DataMap_del(rt_DataMap_t *mp, const char *key);
void rt_DataMap_concat(const rt_DataMap_t *mp1, const rt_DataMap_t *mp2);
const char *rt_DataMap_getkey_copy(const rt_DataMap_t *mp, const char *key);

/** unlike rt_DataMap_getref, returns NULL if key not found */
rt_Data_t *rt_DataMap_getref_errnull(const rt_DataMap_t *mp, const char *key);

/** unlike rt_DataMap_getref_errnull, CRASHES using rt_throw if key not found.
    data should be updated only by calling
    `void rt_VarTable_modf(rt_Data_t *dest, rt_Data_t src)`
    on the returned data pointer, that'll take care of reference counts */
rt_Data_t *rt_DataMap_getref(const rt_DataMap_t *mp, const char *key);
char *rt_DataMap_tostr(const rt_DataMap_t *mp);

/*------------------------
 |       STR DATA        |
 ------------------------*/

/**
 * String types should not be used unless the purpose is to
 * interact with Shsc strings. Shsc strings are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C strings or other native data structures.
 */
rt_DataStr_t *rt_DataStr_init(const char *s);

/**
 * String types should not be used unless the purpose is to
 * interact with Shsc strings. Shsc strings are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C strings or other native data structures.
 */
rt_DataStr_t *rt_DataStr_clone(const rt_DataStr_t *str);

int64_t rt_DataStr_length(const rt_DataStr_t *str);
void rt_DataStr_destroy(rt_DataStr_t **ptr);

void rt_DataStr_toupper              (rt_DataStr_t *str);
void rt_DataStr_tolower              (rt_DataStr_t *str);
void rt_DataStr_append               (rt_DataStr_t *str, char ch);
void rt_DataStr_concat               (rt_DataStr_t *str, const rt_DataStr_t *str2);
void rt_DataStr_insert               (rt_DataStr_t *str, int64_t idx, char ch);
void rt_DataStr_insert_str           (rt_DataStr_t *str, int64_t idx, const rt_DataStr_t *str2);
void rt_DataStr_erase                (rt_DataStr_t *str, int64_t idx, int64_t len);
void rt_DataStr_reverse              (rt_DataStr_t *str);
bool rt_DataStr_isequal              (const rt_DataStr_t *str, const rt_DataStr_t *str2);
int64_t rt_DataStr_compare           (const rt_DataStr_t *str, const rt_DataStr_t *str2);
int64_t rt_DataStr_find              (const rt_DataStr_t *str, char ch);
int64_t rt_DataStr_find_str          (const rt_DataStr_t *str, const rt_DataStr_t *str2);
rt_DataStr_t *rt_DataStr_substr      (const rt_DataStr_t *str, int64_t idx, int64_t len);
rt_DataList_t *rt_DataStr_split      (const rt_DataStr_t *str, char ch);
rt_DataList_t *rt_DataStr_split_str  (const rt_DataStr_t *str, const rt_DataStr_t *str2);
rt_DataStr_t *rt_DataStr_sort        (rt_DataStr_t *str);

rt_Data_t rt_DataStr_toi64           (const rt_DataStr_t *str);
rt_Data_t rt_DataStr_tof64           (const rt_DataStr_t *str);

char *rt_DataStr_getref_errnull(const rt_DataStr_t *str, int64_t idx);

/** data can be updated by assigning a char to the returned pointer */
rt_Data_t *rt_DataStr_getref(const rt_DataStr_t *str, int64_t idx);

void rt_DataStr_del_index(rt_DataStr_t *str, int64_t idx);
void rt_DataStr_del_char(rt_DataStr_t *str, char ch);
char *rt_DataStr_tostr(const rt_DataStr_t *str);

/*------------------------
 |  RUNTIME FUNCTIONS    |
 ------------------------*/

/**
 * Throws a runtime error with the given message.
 * The message can be formatted using printf-style format specifiers.
 */
void rt_throw(const char *fmt, ...) __attribute__((format(printf, 1, 2)));

/*------------------------
 | FUNCTION CALL HANDLER |
 ------------------------*/

/**
 * Calls rt_throw if the number of arguments is less than min_expected_argc.
 * Results in a runtime error.
 */
const rt_DataList_t *rt_fn_get_valid_args(int64_t min_expected_argc);

/**
 * Call a function given the module name, procedure name and arguments.
 * Useful for calling predefined shsc functions.
 *
 * Example:
 *
 * ```c
 * // take in input from user
 * const rt_DataStr_t *prompt_str = rt_DataStr_init("Enter two numbers: ");
 * const rt_Data_t prompt_var = rt_Data_str(prompt_str);
 *
 * rt_Data_t input = rt_fn_call_handler(rt_Data_null(), "io", "input", rt_DataList_from(
 *     prompt_var,
 *     rt_Data_i64(rt_DATA_TYPE_I64)
 * ));
 *
 * rt_DataStr_destroy(&prompt_str);
 * ```
 */
rt_Data_t rt_fn_call_handler(
    const rt_Data_t context,
    const char *module_name,
    const char *proc_name,
    rt_DataList_t *args
);

/**
 * This function is provided for calling lambda functions.
 * Such lambda functions may be passed by from Shsc code as callbacks.
 */
rt_Data_t rt_fn_lambda_call_handler(
    const rt_Data_t context,
    const rt_DataLambda_t lambda,
    rt_DataList_t *args
);

/*------------------------
 |       OPERATORS       |
 ------------------------*/

void rt_op_ampersand              (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_arith_rshift           (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_assign                 (rt_Data_t *lhs, const rt_Data_t *rhs, bool is_const, bool is_weak);
void rt_op_asterix                (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_bang                   (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_bitwise_lshift         (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_bitwise_rshift         (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_caret                  (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_decrement              (rt_Data_t *lhs, rt_Data_t *rhs);
void rt_op_dot                    (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_exponent               (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_floor_divide           (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_fslash                 (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_increment              (rt_Data_t *lhs, rt_Data_t *rhs);
void rt_op_lbrace_angular         (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_logical_and            (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_logical_equal          (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_logical_greater_equal  (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_logical_lesser_equal   (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_logical_or             (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_logical_unequal        (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_minus                  (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_percent                (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_pipe                   (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_plus                   (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_rbrace_angular         (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_tilde                  (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_fnargs_indexing        (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_fncall                 (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_indexing               (const rt_Data_t *lhs, const rt_Data_t *rhs);
void rt_op_nop                    (const rt_Data_t *lhs);
void rt_op_ternary_cond           (const rt_Data_t *lhs, const rt_Data_t *rhs, const rt_Data_t *condition);

#endif
