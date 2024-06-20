#ifndef __SHSCINIT_H__
#define __SHSCINIT_H__

#include "shscfnptr.h"

SHSC_EXPORT
void shsc_init_apifn_data(
    rt_Data_t          (* _rt_Data_bul)         (bool            val),
    rt_Data_t          (* _rt_Data_chr)         (char            val),
    rt_Data_t          (* _rt_Data_i64)         (int64_t         val),
    rt_Data_t          (* _rt_Data_f64)         (double          val),
    rt_Data_t          (* _rt_Data_str)         (rt_DataStr_t   *str),
    rt_Data_t          (* _rt_Data_list)        (rt_DataList_t  *lst),
    rt_Data_t          (* _rt_Data_map)         (rt_DataMap_t   *mp),
    rt_Data_t          (* _rt_Data_any)         (void           *ptr),
    rt_Data_t          (* _rt_Data_null)        (void),
    rt_Data_t          (* _rt_Data_clone)       (const rt_Data_t var),
    void               (* _rt_Data_destroy)     (rt_Data_t      *var),
    bool               (* _rt_Data_isnull)      (const rt_Data_t var),
    bool               (* _rt_Data_isnumeric)   (const rt_Data_t var),
    bool               (* _rt_Data_isequal)     (const rt_Data_t var1, const rt_Data_t    var2),
    int64_t            (* _rt_Data_compare)     (const rt_Data_t var1, const rt_Data_t    var2),
    bool               (* _rt_Data_tobool)      (const rt_Data_t var),
    char              *(* _rt_Data_tostr)       (const rt_Data_t var),
    rt_Data_t          (* _rt_Data_cast)        (const rt_Data_t var,  enum rt_DataType_t type),
    const char        *(* _rt_Data_typename)    (const rt_Data_t var),
    bool               (* _rt_Data_assert_type) (const rt_Data_t var,  enum rt_DataType_t expected_type, const char *for_varname),
    enum rt_DataType_t (* _rt_Data_greater_type)(const rt_Data_t var1, const rt_Data_t    var2),
    int                (* _rt_Data_print)       (const rt_Data_t var)
) {
    shsc_rt_Data_bul = _rt_Data_bul;
    shsc_rt_Data_chr = _rt_Data_chr;
    shsc_rt_Data_i64 = _rt_Data_i64;
    shsc_rt_Data_f64 = _rt_Data_f64;
    shsc_rt_Data_str = _rt_Data_str;
    shsc_rt_Data_list = _rt_Data_list;
    shsc_rt_Data_map = _rt_Data_map;
    shsc_rt_Data_any = _rt_Data_any;
    shsc_rt_Data_null = _rt_Data_null;
    shsc_rt_Data_clone = _rt_Data_clone;
    shsc_rt_Data_destroy = _rt_Data_destroy;
    shsc_rt_Data_isnull = _rt_Data_isnull;
    shsc_rt_Data_isnumeric = _rt_Data_isnumeric;
    shsc_rt_Data_isequal = _rt_Data_isequal;
    shsc_rt_Data_compare = _rt_Data_compare;
    shsc_rt_Data_tobool = _rt_Data_tobool;
    shsc_rt_Data_tostr = _rt_Data_tostr;
    shsc_rt_Data_cast = _rt_Data_cast;
    shsc_rt_Data_typename = _rt_Data_typename;
    shsc_rt_Data_assert_type = _rt_Data_assert_type;
    shsc_rt_Data_greater_type = _rt_Data_greater_type;
    shsc_rt_Data_print = _rt_Data_print;
}

SHSC_EXPORT
void shsc_init_apifn_vartable(
    /**
     * This function is used to modify the value of a variable that exists
     * in the variable table. It takes care of reference counts.
     */
    rt_Data_t         *(* _rt_VarTable_modf)    (rt_Data_t *dest, rt_Data_t src, bool is_const, bool is_weak)
) {
    shsc_rt_VarTable_modf = _rt_VarTable_modf;
}

SHSC_EXPORT
void shsc_init_apifn_list(
    /**
     * List types should not be used unless the purpose is to
     * interact with Shsc lists. Shsc lists are reference counted
     * and involve a large amount of overhead.
     * Intead, make use of C arrays or other native data structures.
     */
    rt_DataList_t     *(* _rt_DataList_init)(),

    /**
     * List types should not be used unless the purpose is to
     * interact with Shsc lists. Shsc lists are reference counted
     * and involve a large amount of overhead.
     * Intead, make use of C arrays or other native data structures.
     */
    rt_DataList_t *    (* _rt_DataList_clone)         (const rt_DataList_t *lst),

    int64_t            (* _rt_DataList_length)        (const rt_DataList_t *lst),
    void               (* _rt_DataList_destroy)       (rt_DataList_t      **ptr),
    bool               (* _rt_DataList_isequal)       (const rt_DataList_t *lst1, const rt_DataList_t *lst2),
    int64_t            (* _rt_DataList_compare)       (const rt_DataList_t *lst1, const rt_DataList_t *lst2),
    void               (* _rt_DataList_append)        (rt_DataList_t       *lst,  rt_Data_t            var),
    void               (* _rt_DataList_concat)        (rt_DataList_t       *lst,  const rt_DataList_t *lst2),
    void               (* _rt_DataList_insert)        (rt_DataList_t       *lst,  int64_t              idx,   rt_Data_t var),
    void               (* _rt_DataList_erase)         (rt_DataList_t       *lst,  int64_t              idx,   int64_t   len),
    void               (* _rt_DataList_reverse)       (rt_DataList_t       *lst),
    int64_t            (* _rt_DataList_find)          (const rt_DataList_t *lst,  rt_Data_t            var),
    rt_DataList_t     *(* _rt_DataList_sublist)       (const rt_DataList_t *lst,  int64_t              idx,   int64_t   len),
    rt_DataStr_t      *(* _rt_DataList_join)          (const rt_DataList_t *lst,  const rt_DataStr_t  *sep),
    rt_DataList_t     *(* _rt_DataList_sort)          (rt_DataList_t       *lst),
    rt_Data_t         *(* _rt_DataList_getref_errnull)(const rt_DataList_t *lst,  int64_t              idx),

    /** data should be updated only by calling
        `void rt_VarTable_modf(rt_Data_t *dest, rt_Data_t src)`
        on the returned data pointer, that'll take care of reference counts */
    rt_Data_t         *(* _rt_DataList_getref)        (const rt_DataList_t *lst, int64_t   idx),

    void               (* _rt_DataList_del_index)     (rt_DataList_t       *lst, int64_t   idx),
    void               (* _rt_DataList_del_val)       (rt_DataList_t       *lst, rt_Data_t var),
    char              *(* _rt_DataList_tostr)         (const rt_DataList_t *lst)
) {
    shsc_rt_DataList_init = _rt_DataList_init;
    shsc_rt_DataList_clone = _rt_DataList_clone;
    shsc_rt_DataList_length = _rt_DataList_length;
    shsc_rt_DataList_destroy = _rt_DataList_destroy;
    shsc_rt_DataList_isequal = _rt_DataList_isequal;
    shsc_rt_DataList_compare = _rt_DataList_compare;
    shsc_rt_DataList_append = _rt_DataList_append;
    shsc_rt_DataList_concat = _rt_DataList_concat;
    shsc_rt_DataList_insert = _rt_DataList_insert;
    shsc_rt_DataList_erase = _rt_DataList_erase;
    shsc_rt_DataList_reverse = _rt_DataList_reverse;
    shsc_rt_DataList_find = _rt_DataList_find;
    shsc_rt_DataList_sublist = _rt_DataList_sublist;
    shsc_rt_DataList_join = _rt_DataList_join;
    shsc_rt_DataList_sort = _rt_DataList_sort;
    shsc_rt_DataList_getref_errnull = _rt_DataList_getref_errnull;
    shsc_rt_DataList_getref = _rt_DataList_getref;
    shsc_rt_DataList_del_index = _rt_DataList_del_index;
    shsc_rt_DataList_del_val = _rt_DataList_del_val;
    shsc_rt_DataList_tostr = _rt_DataList_tostr;
}

SHSC_EXPORT
void shsc_init_apifn_map(
    /**
     * Map types should not be used unless the purpose is to
     * interact with Shsc maps. Shsc maps are reference counted
     * and involve a large amount of overhead.
     * Intead, make use of C hash maps or other native data structures.
     */
    rt_DataMap_t      *(* _rt_DataMap_init)(),

    /**
     * Map types should not be used unless the purpose is to
     * interact with Shsc maps. Shsc maps are reference counted
     * and involve a large amount of overhead.
     * Intead, make use of C hash maps or other native data structures.
     */
    rt_DataMap_t      *(* _rt_DataMap_clone)          (const rt_DataMap_t  *mp),

    int64_t            (* _rt_DataMap_length)         (const rt_DataMap_t  *mp),
    void               (* _rt_DataMap_destroy)        (rt_DataMap_t       **ptr),
    void               (* _rt_DataMap_insert)         (rt_DataMap_t        *mp,   const char         *key,  rt_Data_t value),
    void               (* _rt_DataMap_del)            (rt_DataMap_t        *mp,   const char         *key),
    void               (* _rt_DataMap_concat)         (const rt_DataMap_t  *mp1,  const rt_DataMap_t *mp2),
    const char        *(* _rt_DataMap_getkey_copy)    (const rt_DataMap_t  *mp,   const char         *key),

    /** unlike rt_DataMap_getref, returns NULL if key not found */
    rt_Data_t         *(* _rt_DataMap_getref_errnull) (const rt_DataMap_t *mp,    const char         *key),

    /** unlike rt_DataMap_getref_errnull, CRASHES using rt_throw if key not found.
        data should be updated only by calling
        `void rt_VarTable_modf(rt_Data_t *dest, rt_Data_t src)`
        on the returned data pointer, that'll take care of reference counts */
    rt_Data_t         *(* _rt_DataMap_getref)         (const rt_DataMap_t *mp,     const char        *key),

    char              *(* _rt_DataMap_tostr)          (const rt_DataMap_t *mp)
) {
    shsc_rt_DataMap_init = _rt_DataMap_init;
    shsc_rt_DataMap_clone = _rt_DataMap_clone;
    shsc_rt_DataMap_length = _rt_DataMap_length;
    shsc_rt_DataMap_destroy = _rt_DataMap_destroy;
    shsc_rt_DataMap_insert = _rt_DataMap_insert;
    shsc_rt_DataMap_del = _rt_DataMap_del;
    shsc_rt_DataMap_concat = _rt_DataMap_concat;
    shsc_rt_DataMap_getkey_copy = _rt_DataMap_getkey_copy;
    shsc_rt_DataMap_getref_errnull = _rt_DataMap_getref_errnull;
    shsc_rt_DataMap_getref = _rt_DataMap_getref;
    shsc_rt_DataMap_tostr = _rt_DataMap_tostr;
}

SHSC_EXPORT
void shsc_init_apifn_str(
    /**
     * String types should not be used unless the purpose is to
     * interact with Shsc strings. Shsc strings are reference counted
     * and involve a large amount of overhead.
     * Intead, make use of C strings or other native data structures.
     */
    rt_DataStr_t      *(* _rt_DataStr_init)(const char *s),

    /**
     * String types should not be used unless the purpose is to
     * interact with Shsc strings. Shsc strings are reference counted
     * and involve a large amount of overhead.
     * Intead, make use of C strings or other native data structures.
     */
    rt_DataStr_t      *(* _rt_DataStr_clone)          (const rt_DataStr_t *str),

    int64_t            (* _rt_DataStr_length)         (const rt_DataStr_t *str),
    void               (* _rt_DataStr_destroy)        (rt_DataStr_t       **ptr),
    void               (* _rt_DataStr_toupper)        (rt_DataStr_t        *str),
    void               (* _rt_DataStr_tolower)        (rt_DataStr_t        *str),
    void               (* _rt_DataStr_append)         (rt_DataStr_t        *str, char                 ch),
    void               (* _rt_DataStr_concat)         (rt_DataStr_t        *str, const rt_DataStr_t  *str2),
    void               (* _rt_DataStr_insert)         (rt_DataStr_t        *str, int64_t              idx, char                ch),
    void               (* _rt_DataStr_insert_str)     (rt_DataStr_t        *str, int64_t              idx, const rt_DataStr_t *str2),
    void               (* _rt_DataStr_erase)          (rt_DataStr_t        *str, int64_t              idx, int64_t             len),
    void               (* _rt_DataStr_reverse)        (rt_DataStr_t        *str),
    bool               (* _rt_DataStr_isequal)        (const rt_DataStr_t  *str, const rt_DataStr_t  *str2),
    int64_t            (* _rt_DataStr_compare)        (const rt_DataStr_t  *str, const rt_DataStr_t  *str2),
    int64_t            (* _rt_DataStr_find)           (const rt_DataStr_t  *str, char                 ch),
    int64_t            (* _rt_DataStr_find_str)       (const rt_DataStr_t  *str, const rt_DataStr_t  *str2),
    rt_DataStr_t      *(* _rt_DataStr_substr)         (const rt_DataStr_t  *str, int64_t idx, int64_t len),
    rt_DataList_t     *(* _rt_DataStr_split)          (const rt_DataStr_t  *str, char                 ch),
    rt_DataList_t     *(* _rt_DataStr_split_str)      (const rt_DataStr_t  *str, const rt_DataStr_t  *str2),
    rt_DataStr_t      *(* _rt_DataStr_sort)           (rt_DataStr_t        *str),
    rt_Data_t          (* _rt_DataStr_toi64)          (const rt_DataStr_t  *str),
    rt_Data_t          (* _rt_DataStr_tof64)          (const rt_DataStr_t  *str),
    char              *(* _rt_DataStr_getref_errnull) (const rt_DataStr_t  *str, int64_t idx),

    /** data can be updated by assigning a char to the returned pointer */
    rt_Data_t         *(* _rt_DataStr_getref)(const rt_DataStr_t *str, int64_t idx),

    void               (* _rt_DataStr_del_index)      (rt_DataStr_t *str, int64_t idx),
    void               (* _rt_DataStr_del_char)       (rt_DataStr_t *str, char ch),
    char              *(* _rt_DataStr_tostr)          (const rt_DataStr_t *str)
) {
    shsc_rt_DataStr_init = _rt_DataStr_init;
    shsc_rt_DataStr_clone = _rt_DataStr_clone;
    shsc_rt_DataStr_length = _rt_DataStr_length;
    shsc_rt_DataStr_destroy = _rt_DataStr_destroy;
    shsc_rt_DataStr_toupper = _rt_DataStr_toupper;
    shsc_rt_DataStr_tolower = _rt_DataStr_tolower;
    shsc_rt_DataStr_append = _rt_DataStr_append;
    shsc_rt_DataStr_concat = _rt_DataStr_concat;
    shsc_rt_DataStr_insert = _rt_DataStr_insert;
    shsc_rt_DataStr_insert_str = _rt_DataStr_insert_str;
    shsc_rt_DataStr_erase = _rt_DataStr_erase;
    shsc_rt_DataStr_reverse = _rt_DataStr_reverse;
    shsc_rt_DataStr_isequal = _rt_DataStr_isequal;
    shsc_rt_DataStr_compare = _rt_DataStr_compare;
    shsc_rt_DataStr_find = _rt_DataStr_find;
    shsc_rt_DataStr_find_str = _rt_DataStr_find_str;
    shsc_rt_DataStr_substr = _rt_DataStr_substr;
    shsc_rt_DataStr_split = _rt_DataStr_split;
    shsc_rt_DataStr_split_str = _rt_DataStr_split_str;
    shsc_rt_DataStr_sort = _rt_DataStr_sort;
    shsc_rt_DataStr_toi64 = _rt_DataStr_toi64;
    shsc_rt_DataStr_tof64 = _rt_DataStr_tof64;
    shsc_rt_DataStr_getref_errnull = _rt_DataStr_getref_errnull;
    shsc_rt_DataStr_getref = _rt_DataStr_getref;
    shsc_rt_DataStr_del_index = _rt_DataStr_del_index;
    shsc_rt_DataStr_del_char = _rt_DataStr_del_char;
    shsc_rt_DataStr_tostr = _rt_DataStr_tostr;
}

SHSC_EXPORT
void shsc_init_apifn_others(
    /*------------------------
     |  RUNTIME FUNCTIONS    |
     ------------------------*/

    /**
     * Throws a runtime error with the given message.
     * The message can be formatted using printf-style format specifiers.
     */
    void (* _rt_throw)(const char *fmt, ...) __attribute__((format(printf, 1, 2))),

    /*------------------------
     | FUNCTION CALL HANDLER |
     ------------------------*/

    /**
     * Calls rt_throw if the number of arguments is less than min_expected_argc.
     * Results in a runtime error.
     */
    const rt_DataList_t *(* _rt_fn_get_valid_args)(int64_t min_expected_argc),

    /**
     * Call a function given the module name, procedure name and arguments.
     * Useful for calling predefined shsc functions.
     *
     * Example:
     *
     * ```c
     * // take in input from user
     * const rt_DataStr_t *prompt_str = rt_DataStr_init("Enter two numbers: "),
     * const rt_Data_t prompt_var = rt_Data_str(prompt_str),
     *
     * rt_Data_t input = rt_fn_call_handler(rt_Data_null(), "io", "input", rt_DataList_from(
     *     prompt_var,
     *     rt_Data_i64(rt_DATA_TYPE_I64)
     * )),
     *
     * rt_DataStr_destroy(&prompt_str),
     * ```
     */
    rt_Data_t (* _rt_fn_call_handler)(
        const rt_Data_t context,
        const char *module_name,
        const char *proc_name,
        rt_DataList_t *args
    ),

    /**
     * This function is provided for calling lambda functions.
     * Such lambda functions may be passed by from Shsc code as callbacks.
     */
    rt_Data_t (* _rt_fn_lambda_call_handler)(
        const rt_Data_t context,
        const rt_DataLambda_t lambda,
        rt_DataList_t *args
    )
) {
     shsc_rt_throw = _rt_throw;
    shsc_rt_fn_get_valid_args = _rt_fn_get_valid_args;
    shsc_rt_fn_call_handler = _rt_fn_call_handler;
    shsc_rt_fn_lambda_call_handler = _rt_fn_lambda_call_handler;
}

SHSC_EXPORT
void shsc_init_apifn_ops(
    void (* _rt_op_ampersand)              (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_arith_rshift)           (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_assign)                 (rt_Data_t       *lhs, const rt_Data_t *rhs, bool is_const, bool is_weak),
    void (* _rt_op_asterix)                (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_bang)                   (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_bitwise_lshift)         (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_bitwise_rshift)         (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_caret)                  (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_decrement)              (rt_Data_t       *lhs, rt_Data_t       *rhs),
    void (* _rt_op_dot)                    (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_exponent)               (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_floor_divide)           (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_fslash)                 (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_increment)              (rt_Data_t       *lhs, rt_Data_t       *rhs),
    void (* _rt_op_lbrace_angular)         (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_logical_and)            (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_logical_equal)          (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_logical_greater_equal)  (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_logical_lesser_equal)   (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_logical_or)             (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_logical_unequal)        (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_minus)                  (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_percent)                (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_pipe)                   (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_plus)                   (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_rbrace_angular)         (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_tilde)                  (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_fnargs_indexing)        (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_fncall)                 (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_indexing)               (const rt_Data_t *lhs, const rt_Data_t *rhs),
    void (* _rt_op_nop)                    (const rt_Data_t *lhs),
    void (* _rt_op_ternary_cond)           (const rt_Data_t *lhs, const rt_Data_t *rhs, const rt_Data_t *condition)
) {
    shsc_rt_op_ampersand = _rt_op_ampersand;
    shsc_rt_op_arith_rshift = _rt_op_arith_rshift;
    shsc_rt_op_assign = _rt_op_assign;
    shsc_rt_op_asterix = _rt_op_asterix;
    shsc_rt_op_bang = _rt_op_bang;
    shsc_rt_op_bitwise_lshift = _rt_op_bitwise_lshift;
    shsc_rt_op_bitwise_rshift = _rt_op_bitwise_rshift;
    shsc_rt_op_caret = _rt_op_caret;
    shsc_rt_op_decrement = _rt_op_decrement;
    shsc_rt_op_dot = _rt_op_dot;
    shsc_rt_op_exponent = _rt_op_exponent;
    shsc_rt_op_floor_divide = _rt_op_floor_divide;
    shsc_rt_op_fslash = _rt_op_fslash;
    shsc_rt_op_increment = _rt_op_increment;
    shsc_rt_op_lbrace_angular = _rt_op_lbrace_angular;
    shsc_rt_op_logical_and = _rt_op_logical_and;
    shsc_rt_op_logical_equal = _rt_op_logical_equal;
    shsc_rt_op_logical_greater_equal = _rt_op_logical_greater_equal;
    shsc_rt_op_logical_lesser_equal = _rt_op_logical_lesser_equal;
    shsc_rt_op_logical_or = _rt_op_logical_or;
    shsc_rt_op_logical_unequal = _rt_op_logical_unequal;
    shsc_rt_op_minus = _rt_op_minus;
    shsc_rt_op_percent = _rt_op_percent;
    shsc_rt_op_pipe = _rt_op_pipe;
    shsc_rt_op_plus = _rt_op_plus;
    shsc_rt_op_rbrace_angular = _rt_op_rbrace_angular;
    shsc_rt_op_tilde = _rt_op_tilde;
    shsc_rt_op_fnargs_indexing = _rt_op_fnargs_indexing;
    shsc_rt_op_fncall = _rt_op_fncall;
    shsc_rt_op_indexing = _rt_op_indexing;
    shsc_rt_op_nop = _rt_op_nop;
    shsc_rt_op_ternary_cond = _rt_op_ternary_cond;
}

#endif
