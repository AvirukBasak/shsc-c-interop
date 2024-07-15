#ifndef __SHSCPROTO_H__
#define __SHSCPROTO_H__

/**

The purpose of this file is to provide a cleaner API to call the
function pointers defined in shscfnptr.h.

*/

#include <stdbool.h>
#include <stdint.h>
#include "shsctypes.h"
#include "shscprotoptr.h"

rt_Data_t          shsc_Data_bul         (bool            val);
rt_Data_t          shsc_Data_chr         (char            val);
rt_Data_t          shsc_Data_i64         (int64_t         val);
rt_Data_t          shsc_Data_f64         (double          val);
rt_Data_t          shsc_Data_str         (rt_DataStr_t   *str);
rt_Data_t          shsc_Data_list        (rt_DataList_t  *lst);
rt_Data_t          shsc_Data_map         (rt_DataMap_t   *mp);
rt_Data_t          shsc_Data_any         (void           *ptr);
rt_Data_t          shsc_Data_null        (void);
rt_Data_t          shsc_Data_clone       (const rt_Data_t var);
void               shsc_Data_incref      (rt_Data_t *var);
void               shsc_Data_decref      (rt_Data_t *var);
void               shsc_Data_destroy     (rt_Data_t      *var);
bool               shsc_Data_isnull      (const rt_Data_t var);
bool               shsc_Data_isnumeric   (const rt_Data_t var);
bool               shsc_Data_isequal     (const rt_Data_t var1, const rt_Data_t    var2);
int64_t            shsc_Data_compare     (const rt_Data_t var1, const rt_Data_t    var2);
bool               shsc_Data_tobool      (const rt_Data_t var);
char              *shsc_Data_tostr       (const rt_Data_t var);
rt_Data_t          shsc_Data_cast        (const rt_Data_t var,  rt_DataType_t type);
const char        *shsc_Data_typename    (const rt_Data_t var);
bool               shsc_Data_assert_type (const rt_Data_t var,  rt_DataType_t expected_type, const char *for_varname);
enum rt_DataType_t shsc_Data_greater_type(const rt_Data_t var1, const rt_Data_t    var2);
int                shsc_Data_print       (const rt_Data_t var);

/*------------------------
 |       VAR TABLE        |
 ------------------------*/

/**
 * This function is used to modify the value of a variable that exists
 * in the variable table. It takes care of reference counts.
 */
rt_Data_t         *shsc_VarTable_modf    (rt_Data_t *dest, rt_Data_t src, bool is_const, bool is_weak);

/*------------------------
 |       LIST DATA       |
 ------------------------*/

/* macro that takes a variable number of rt_Data_t type arguments
   and calls rt_DataList_append for each item */
#define shsc_DataList_from(...)                                   \
    ({                                                            \
        rt_Data_t _args[] = { __VA_ARGS__ };                      \
        size_t args_len = sizeof(_args) / sizeof(rt_Data_t);      \
        rt_DataList_t *lst = shsc_DataList_init();                \
        for (size_t i = 0; i < args_len; i++) {                   \
            shsc_DataList_append(lst, _args[i]);                  \
        }                                                         \
        lst;                                                      \
    })

/**
 * List types should not be used unless the purpose is to
 * interact with Shsc lists. Shsc lists are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C arrays or other native data structures.
 */
rt_DataList_t     *shsc_DataList_init();

/**
 * List types should not be used unless the purpose is to
 * interact with Shsc lists. Shsc lists are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C arrays or other native data structures.
 */
rt_DataList_t     *shsc_DataList_clone         (const rt_DataList_t *lst);

int64_t            shsc_DataList_length        (const rt_DataList_t *lst);
void               shsc_DataList_destroy       (rt_DataList_t      **ptr);
bool               shsc_DataList_isequal       (const rt_DataList_t *p_lst1, const rt_DataList_t *p_lst2);
int64_t            shsc_DataList_compare       (const rt_DataList_t *p_lst1, const rt_DataList_t *p_lst2);
void               shsc_DataList_append        (rt_DataList_t       *lst,  rt_Data_t            var);
void               shsc_DataList_concat        (rt_DataList_t       *lst,  const rt_DataList_t *p_lst2);
void               shsc_DataList_insert        (rt_DataList_t       *lst,  int64_t              idx,   rt_Data_t var);
void               shsc_DataList_erase         (rt_DataList_t       *lst,  int64_t              idx,   int64_t   len);
void               shsc_DataList_reverse       (rt_DataList_t       *lst);
int64_t            shsc_DataList_find          (const rt_DataList_t *lst,  rt_Data_t            var);
rt_DataList_t     *shsc_DataList_sublist       (const rt_DataList_t *lst,  int64_t              idx,   int64_t   len);
rt_DataStr_t      *shsc_DataList_join          (const rt_DataList_t *lst,  const rt_DataStr_t  *sep);
rt_DataList_t     *shsc_DataList_sort          (rt_DataList_t       *lst);
rt_Data_t         *shsc_DataList_getref_errnull(const rt_DataList_t *lst,  int64_t              idx);

/** data should be updated only by calling
    `void rt_VarTable_modf(rt_Data_t *dest, rt_Data_t src)`
    on the returned data pointer, that'll take care of reference counts */
rt_Data_t         *shsc_DataList_getref        (const rt_DataList_t *lst, int64_t   idx);

void               shsc_DataList_del_index     (rt_DataList_t       *lst, int64_t   idx);
void               shsc_DataList_del_val       (rt_DataList_t       *lst, rt_Data_t var);
char              *shsc_DataList_tostr         (const rt_DataList_t *lst);

/*------------------------
 |       MAP DATA        |
 ------------------------*/

/**
 * Map types should not be used unless the purpose is to
 * interact with Shsc maps. Shsc maps are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C hash maps or other native data structures.
 */
rt_DataMap_t      *shsc_DataMap_init();

/**
 * Map types should not be used unless the purpose is to
 * interact with Shsc maps. Shsc maps are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C hash maps or other native data structures.
 */
rt_DataMap_t      *shsc_DataMap_clone          (const rt_DataMap_t  *mp);

int64_t            shsc_DataMap_length         (const rt_DataMap_t  *mp);
void               shsc_DataMap_destroy        (rt_DataMap_t       **ptr);
void               shsc_DataMap_insert         (rt_DataMap_t        *mp,   const char         *key,  rt_Data_t value);
void               shsc_DataMap_del            (rt_DataMap_t        *mp,   const char         *key);
void               shsc_DataMap_concat         (rt_DataMap_t        *mp1,  const rt_DataMap_t *mp2);
const char        *shsc_DataMap_getkey_copy    (const rt_DataMap_t  *mp,   const char         *key);

/** unlike rt_DataMap_getref, returns NULL if key not found */
rt_Data_t         *shsc_DataMap_getref_errnull (const rt_DataMap_t *mp,    const char         *key);

/** unlike rt_DataMap_getref_errnull, CRASHES using rt_throw if key not found.
    data should be updated only by calling
    `void rt_VarTable_modf(rt_Data_t *dest, rt_Data_t src)`
    on the returned data pointer, that'll take care of reference counts */
rt_Data_t         *shsc_DataMap_getref         (const rt_DataMap_t *mp,     const char        *key);

char              *shsc_DataMap_tostr          (const rt_DataMap_t *mp);

/*------------------------
 |       STR DATA        |
 ------------------------*/

/**
 * String types should not be used unless the purpose is to
 * interact with Shsc strings. Shsc strings are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C strings or other native data structures.
 */
rt_DataStr_t      *shsc_DataStr_init(const char *s);

/**
 * String types should not be used unless the purpose is to
 * interact with Shsc strings. Shsc strings are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C strings or other native data structures.
 */
rt_DataStr_t      *shsc_DataStr_clone          (const rt_DataStr_t *str);

int64_t            shsc_DataStr_length         (const rt_DataStr_t *str);
void               shsc_DataStr_destroy        (rt_DataStr_t       **ptr);
void               shsc_DataStr_toupper        (rt_DataStr_t        *str);
void               shsc_DataStr_tolower        (rt_DataStr_t        *str);
void               shsc_DataStr_append         (rt_DataStr_t        *str, char                 ch);
void               shsc_DataStr_concat         (rt_DataStr_t        *str, const rt_DataStr_t  *str2);
void               shsc_DataStr_insert         (rt_DataStr_t        *str, int64_t              idx, char                ch);
void               shsc_DataStr_insert_str     (rt_DataStr_t        *str, int64_t              idx, const rt_DataStr_t *str2);
void               shsc_DataStr_erase          (rt_DataStr_t        *str, int64_t              idx, int64_t             len);
void               shsc_DataStr_reverse        (rt_DataStr_t        *str);
bool               shsc_DataStr_isequal        (const rt_DataStr_t  *str, const rt_DataStr_t  *str2);
int64_t            shsc_DataStr_compare        (const rt_DataStr_t  *str, const rt_DataStr_t  *str2);
int64_t            shsc_DataStr_find           (const rt_DataStr_t  *str, char                 ch);
int64_t            shsc_DataStr_find_str       (const rt_DataStr_t  *str, const rt_DataStr_t  *str2);
rt_DataStr_t      *shsc_DataStr_substr         (const rt_DataStr_t  *str, int64_t idx, int64_t len);
rt_DataList_t     *shsc_DataStr_split          (const rt_DataStr_t  *str, char                 ch);
rt_DataList_t     *shsc_DataStr_split_str      (const rt_DataStr_t  *str, const rt_DataStr_t  *str2);
rt_DataStr_t      *shsc_DataStr_sort           (rt_DataStr_t        *str);
rt_Data_t          shsc_DataStr_toi64          (const rt_DataStr_t  *str);
rt_Data_t          shsc_DataStr_tof64          (const rt_DataStr_t  *str);
char              *shsc_DataStr_getref_errnull (const rt_DataStr_t  *str, int64_t idx);

/** data can be updated by assigning a char to the returned pointer */
rt_Data_t         *shsc_DataStr_getref(const rt_DataStr_t *str, int64_t idx);

void               shsc_DataStr_del_index      (rt_DataStr_t *str, int64_t idx);
void               shsc_DataStr_del_char       (rt_DataStr_t *str, char ch);
char              *shsc_DataStr_tostr          (const rt_DataStr_t *str);

/*------------------------
 |  RUNTIME FUNCTIONS    |
 ------------------------*/

/**
 * Fn shsc_throw accepts a printf-style format string and arguments.
 * This is why it cannot be replaced with a cleaner function API
 * and must be called directly via the function pointer.
 *
 * @param fmt printf-style format string
 * @param ... arguments to be formatted *
 *
 * void shsc_throw(const char *fmt, ...);
 */
FN_MODIFIERS shsc_ptr_throw_t shsc_throw;

/*------------------------
 | FUNCTION CALL HANDLER |
 ------------------------*/

/**
 * Calls rt_throw if the number of arguments is less than min_expected_argc.
 * Results in a runtime error.
 */
const rt_DataList_t *shsc_fn_get_valid_args(int64_t min_expected_argc);

/**
 * Call a function given the module name, procedure name and arguments.
 * Useful for calling predefined shsc functions.
 *
 * Example:
 *
 * ```c
 * // take in input from user
 * const shsc_DataStr_t *prompt_str = shsc_DataStr_init("Enter two numbers: ");
 * const shsc_Data_t prompt_var = shsc_Data_str(prompt_str);
 *
 * rt_Data_t input = shsc_call_fn(shsc_Data_null(), "io", "input", rt_DataList_from(
 *     prompt_var,
 *     shsc_Data_i64(rt_DATA_TYPE_I64)
 * ));
 *
 * shsc_DataStr_destroy(&prompt_str);
 * ```
 */
rt_Data_t shsc_call_fn(
    const rt_Data_t context,
    const char *module_name,
    const char *proc_name,
    rt_DataList_t *args
);

/**
 * This function is provided for calling lambda functions.
 * Such lambda functions may be passed by from Shsc code as callbacks.
 */
rt_Data_t shsc_call_lambda(
    const rt_Data_t context,
    const rt_DataLambda_t lambda,
    rt_DataList_t *args
);

/*------------------------
 |       OPERATORS       |
 ------------------------*/

void shsc_op_ampersand              (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_arith_rshift           (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_assign                 (rt_Data_t       *lhs, const rt_Data_t *rhs, bool is_const, bool is_weak);
void shsc_op_asterix                (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_bang                   (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_bitwise_lshift         (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_bitwise_rshift         (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_caret                  (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_decrement              (rt_Data_t       *lhs, rt_Data_t       *rhs);
void shsc_op_dot                    (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_exponent               (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_floor_divide           (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_fslash                 (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_increment              (rt_Data_t       *lhs, rt_Data_t       *rhs);
void shsc_op_lbrace_angular         (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_logical_and            (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_logical_equal          (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_logical_greater_equal  (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_logical_lesser_equal   (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_logical_or             (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_logical_unequal        (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_minus                  (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_percent                (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_pipe                   (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_plus                   (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_rbrace_angular         (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_tilde                  (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_fnargs_indexing        (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_fncall                 (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_indexing               (const rt_Data_t *lhs, const rt_Data_t *rhs);
void shsc_op_nop                    (const rt_Data_t *lhs);
void shsc_op_ternary_cond           (const rt_Data_t *lhs, const rt_Data_t *rhs, const rt_Data_t *condition);

#endif
