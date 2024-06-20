#ifndef __SHSCINIT_H__
#define __SHSCINIT_H__

#include "shsc.h"

SHSC_EXPORT
void shsc_init_apifn_data(
    shsc_rt_Data_t          (* _shsc_rt_Data_bul)         (bool            val),
    shsc_rt_Data_t          (* _shsc_rt_Data_chr)         (char            val),
    shsc_rt_Data_t          (* _shsc_rt_Data_i64)         (int64_t         val),
    shsc_rt_Data_t          (* _shsc_rt_Data_f64)         (double          val),
    shsc_rt_Data_t          (* _shsc_rt_Data_str)         (shsc_rt_DataStr_t   *str),
    shsc_rt_Data_t          (* _shsc_rt_Data_list)        (shsc_rt_DataList_t  *lst),
    shsc_rt_Data_t          (* _shsc_rt_Data_map)         (shsc_rt_DataMap_t   *mp),
    shsc_rt_Data_t          (* _shsc_rt_Data_any)         (void           *ptr),
    shsc_rt_Data_t          (* _shsc_rt_Data_null)        (void),
    shsc_rt_Data_t          (* _shsc_rt_Data_clone)       (const shsc_rt_Data_t var),
    void               (* _shsc_rt_Data_destroy)     (shsc_rt_Data_t      *var),
    bool               (* _shsc_rt_Data_isnull)      (const shsc_rt_Data_t var),
    bool               (* _shsc_rt_Data_isnumeric)   (const shsc_rt_Data_t var),
    bool               (* _shsc_rt_Data_isequal)     (const shsc_rt_Data_t var1, const shsc_rt_Data_t    var2),
    int64_t            (* _shsc_rt_Data_compare)     (const shsc_rt_Data_t var1, const shsc_rt_Data_t    var2),
    bool               (* _shsc_rt_Data_tobool)      (const shsc_rt_Data_t var),
    char              *(* _shsc_rt_Data_tostr)       (const shsc_rt_Data_t var),
    shsc_rt_Data_t          (* _shsc_rt_Data_cast)        (const shsc_rt_Data_t var,  enum shsc_rt_DataType_t type),
    const char        *(* _shsc_rt_Data_typename)    (const shsc_rt_Data_t var),
    bool               (* _shsc_rt_Data_asseshsc_rt_type) (const shsc_rt_Data_t var,  enum shsc_rt_DataType_t expected_type, const char *for_varname),
    enum shsc_rt_DataType_t (* _shsc_rt_Data_greater_type)(const shsc_rt_Data_t var1, const shsc_rt_Data_t    var2),
    int                (* _shsc_rt_Data_print)       (const shsc_rt_Data_t var)
);

SHSC_EXPORT
void shsc_init_apifn_vartable(
    /**
     * This function is used to modify the value of a variable that exists
     * in the variable table. It takes care of reference counts.
     */
    void               (* _shsc_rt_VarTable_modf)    (shsc_rt_Data_t *dest, shsc_rt_Data_t src)
);

SHSC_EXPORT
void shsc_init_apifn_list(
    /**
     * List types should not be used unless the purpose is to
     * interact with Shsc lists. Shsc lists are reference counted
     * and involve a large amount of overhead.
     * Intead, make use of C arrays or other native data structures.
     */
    shsc_rt_DataList_t     *(* _shsc_rt_DataList_init)(),

    /**
     * List types should not be used unless the purpose is to
     * interact with Shsc lists. Shsc lists are reference counted
     * and involve a large amount of overhead.
     * Intead, make use of C arrays or other native data structures.
     */
    shsc_rt_DataList_t *    (* _shsc_rt_DataList_clone)         (const shsc_rt_DataList_t *lst),

    int64_t            (* _shsc_rt_DataList_length)        (const shsc_rt_DataList_t *lst),
    void               (* _shsc_rt_DataList_destroy)       (shsc_rt_DataList_t      **ptr),
    bool               (* _shsc_rt_DataList_isequal)       (const shsc_rt_DataList_t *lst1, const shsc_rt_DataList_t *lst2),
    int64_t            (* _shsc_rt_DataList_compare)       (const shsc_rt_DataList_t *lst1, const shsc_rt_DataList_t *lst2),
    void               (* _shsc_rt_DataList_append)        (shsc_rt_DataList_t       *lst,  shsc_rt_Data_t            var),
    void               (* _shsc_rt_DataList_concat)        (shsc_rt_DataList_t       *lst,  const shsc_rt_DataList_t *lst2),
    void               (* _shsc_rt_DataList_insert)        (shsc_rt_DataList_t       *lst,  int64_t              idx,   shsc_rt_Data_t var),
    void               (* _shsc_rt_DataList_erase)         (shsc_rt_DataList_t       *lst,  int64_t              idx,   int64_t   len),
    void               (* _shsc_rt_DataList_reverse)       (shsc_rt_DataList_t       *lst),
    int64_t            (* _shsc_rt_DataList_find)          (const shsc_rt_DataList_t *lst,  shsc_rt_Data_t            var),
    shsc_rt_DataList_t     *(* _shsc_rt_DataList_sublist)       (const shsc_rt_DataList_t *lst,  int64_t              idx,   int64_t   len),
    shsc_rt_DataStr_t      *(* _shsc_rt_DataList_join)          (const shsc_rt_DataList_t *lst,  const shsc_rt_DataStr_t  *sep),
    shsc_rt_DataList_t     *(* _shsc_rt_DataList_sort)          (shsc_rt_DataList_t       *lst),
    shsc_rt_Data_t         *(* _shsc_rt_DataList_getref_errnull)(const shsc_rt_DataList_t *lst,  int64_t              idx),

    /** data should be updated only by calling
        `void shsc_rt_VarTable_modf(shsc_rt_Data_t *dest, shsc_rt_Data_t src)`
        on the returned data pointer, that'll take care of reference counts */
    shsc_rt_Data_t         *(* _shsc_rt_DataList_getref)        (const shsc_rt_DataList_t *lst, int64_t   idx),

    void               (* _shsc_rt_DataList_del_index)     (shsc_rt_DataList_t       *lst, int64_t   idx),
    void               (* _shsc_rt_DataList_del_val)       (shsc_rt_DataList_t       *lst, shsc_rt_Data_t var),
    char              *(* _shsc_rt_DataList_tostr)         (const shsc_rt_DataList_t *lst)
);

SHSC_EXPORT
void shsc_init_apifn_map(
    /**
     * Map types should not be used unless the purpose is to
     * interact with Shsc maps. Shsc maps are reference counted
     * and involve a large amount of overhead.
     * Intead, make use of C hash maps or other native data structures.
     */
    shsc_rt_DataMap_t      *(* _shsc_rt_DataMap_init)(),

    /**
     * Map types should not be used unless the purpose is to
     * interact with Shsc maps. Shsc maps are reference counted
     * and involve a large amount of overhead.
     * Intead, make use of C hash maps or other native data structures.
     */
    shsc_rt_DataMap_t      *(* _shsc_rt_DataMap_clone)          (const shsc_rt_DataMap_t  *mp),

    int64_t            (* _shsc_rt_DataMap_length)         (const shsc_rt_DataMap_t  *mp),
    void               (* _shsc_rt_DataMap_destroy)        (shsc_rt_DataMap_t       **ptr),
    void               (* _shsc_rt_DataMap_insert)         (shsc_rt_DataMap_t        *mp,   const char         *key,  shsc_rt_Data_t value),
    void               (* _shsc_rt_DataMap_del)            (shsc_rt_DataMap_t        *mp,   const char         *key),
    void               (* _shsc_rt_DataMap_concat)         (const shsc_rt_DataMap_t  *mp1,  const shsc_rt_DataMap_t *mp2),
    const char        *(* _shsc_rt_DataMap_getkey_copy)    (const shsc_rt_DataMap_t  *mp,   const char         *key),

    /** unlike shsc_rt_DataMap_getref, returns NULL if key not found */
    shsc_rt_Data_t         *(* _shsc_rt_DataMap_getref_errnull) (const shsc_rt_DataMap_t *mp,    const char         *key),

    /** unlike shsc_rt_DataMap_getref_errnull, CRASHES using shsc_rt_throw if key not found.
        data should be updated only by calling
        `void shsc_rt_VarTable_modf(shsc_rt_Data_t *dest, shsc_rt_Data_t src)`
        on the returned data pointer, that'll take care of reference counts */
    shsc_rt_Data_t         *(* _shsc_rt_DataMap_getref)         (const shsc_rt_DataMap_t *mp,     const char        *key),

    char              *(* _shsc_rt_DataMap_tostr)          (const shsc_rt_DataMap_t *mp)
);

SHSC_EXPORT
void shsc_init_apifn_str(
    /**
     * String types should not be used unless the purpose is to
     * interact with Shsc strings. Shsc strings are reference counted
     * and involve a large amount of overhead.
     * Intead, make use of C strings or other native data structures.
     */
    shsc_rt_DataStr_t      *(* _shsc_rt_DataStr_init)(const char *s),

    /**
     * String types should not be used unless the purpose is to
     * interact with Shsc strings. Shsc strings are reference counted
     * and involve a large amount of overhead.
     * Intead, make use of C strings or other native data structures.
     */
    shsc_rt_DataStr_t      *(* _shsc_rt_DataStr_clone)          (const shsc_rt_DataStr_t *str),

    int64_t            (* _shsc_rt_DataStr_length)         (const shsc_rt_DataStr_t *str),
    void               (* _shsc_rt_DataStr_destroy)        (shsc_rt_DataStr_t       **ptr),
    void               (* _shsc_rt_DataStr_toupper)        (shsc_rt_DataStr_t        *str),
    void               (* _shsc_rt_DataStr_tolower)        (shsc_rt_DataStr_t        *str),
    void               (* _shsc_rt_DataStr_append)         (shsc_rt_DataStr_t        *str, char                 ch),
    void               (* _shsc_rt_DataStr_concat)         (shsc_rt_DataStr_t        *str, const shsc_rt_DataStr_t  *str2),
    void               (* _shsc_rt_DataStr_insert)         (shsc_rt_DataStr_t        *str, int64_t              idx, char                ch),
    void               (* _shsc_rt_DataStr_inseshsc_rt_str)     (shsc_rt_DataStr_t        *str, int64_t              idx, const shsc_rt_DataStr_t *str2),
    void               (* _shsc_rt_DataStr_erase)          (shsc_rt_DataStr_t        *str, int64_t              idx, int64_t             len),
    void               (* _shsc_rt_DataStr_reverse)        (shsc_rt_DataStr_t        *str),
    bool               (* _shsc_rt_DataStr_isequal)        (const shsc_rt_DataStr_t  *str, const shsc_rt_DataStr_t  *str2),
    int64_t            (* _shsc_rt_DataStr_compare)        (const shsc_rt_DataStr_t  *str, const shsc_rt_DataStr_t  *str2),
    int64_t            (* _shsc_rt_DataStr_find)           (const shsc_rt_DataStr_t  *str, char                 ch),
    int64_t            (* _shsc_rt_DataStr_find_str)       (const shsc_rt_DataStr_t  *str, const shsc_rt_DataStr_t  *str2),
    shsc_rt_DataStr_t      *(* _shsc_rt_DataStr_substr)         (const shsc_rt_DataStr_t  *str, int64_t idx, int64_t len),
    shsc_rt_DataList_t     *(* _shsc_rt_DataStr_split)          (const shsc_rt_DataStr_t  *str, char                 ch),
    shsc_rt_DataList_t     *(* _shsc_rt_DataStr_split_str)      (const shsc_rt_DataStr_t  *str, const shsc_rt_DataStr_t  *str2),
    shsc_rt_DataStr_t      *(* _shsc_rt_DataStr_sort)           (shsc_rt_DataStr_t        *str),
    shsc_rt_Data_t          (* _shsc_rt_DataStr_toi64)          (const shsc_rt_DataStr_t  *str),
    shsc_rt_Data_t          (* _shsc_rt_DataStr_tof64)          (const shsc_rt_DataStr_t  *str),
    char              *(* _shsc_rt_DataStr_getref_errnull) (const shsc_rt_DataStr_t  *str, int64_t idx),

    /** data can be updated by assigning a char to the returned pointer */
    shsc_rt_Data_t         *(* _shsc_rt_DataStr_getref)(const shsc_rt_DataStr_t *str, int64_t idx),

    void               (* _shsc_rt_DataStr_del_index)      (shsc_rt_DataStr_t *str, int64_t idx),
    void               (* _shsc_rt_DataStr_del_char)       (shsc_rt_DataStr_t *str, char ch),
    char              *(* _shsc_rt_DataStr_tostr)          (const shsc_rt_DataStr_t *str)
);

SHSC_EXPORT
void shsc_init_apifn_others(
    /*------------------------
     |  RUNTIME FUNCTIONS    |
     ------------------------*/

    /**
     * Throws a runtime error with the given message.
     * The message can be formatted using printf-style format specifiers.
     */
    void (* _shsc_rt_throw)(const char *fmt, ...) __attribute__((format(printf, 1, 2))),

    /*------------------------
     | FUNCTION CALL HANDLER |
     ------------------------*/

    /**
     * Calls shsc_rt_throw if the number of arguments is less than min_expected_argc.
     * Results in a runtime error.
     */
    const shsc_rt_DataList_t *(* _shsc_rt_fn_get_valid_args)(int64_t min_expected_argc),

    /**
     * Call a function given the module name, procedure name and arguments.
     * Useful for calling predefined shsc functions.
     *
     * Example:
     *
     * ```c
     * // take in input from user
     * const shsc_rt_DataStr_t *prompt_str = shsc_rt_DataStr_init("Enter two numbers: "),
     * const shsc_rt_Data_t prompt_var = shsc_rt_Data_str(prompt_str),
     *
     * shsc_rt_Data_t input = shsc_rt_fn_call_handler(shsc_rt_Data_null(), "io", "input", shsc_rt_DataList_from(
     *     prompt_var,
     *     shsc_rt_Data_i64(shsc_rt_DATA_TYPE_I64)
     * )),
     *
     * shsc_rt_DataStr_destroy(&prompt_str),
     * ```
     */
    shsc_rt_Data_t (* _shsc_rt_fn_call_handler)(
        const shsc_rt_Data_t context,
        const char *module_name,
        const char *proc_name,
        shsc_rt_DataList_t *args
    ),

    /**
     * This function is provided for calling lambda functions.
     * Such lambda functions may be passed by from Shsc code as callbacks.
     */
    shsc_rt_Data_t (* _shsc_rt_fn_lambda_call_handler)(
        const shsc_rt_Data_t context,
        const shsc_rt_DataLambda_t lambda,
        shsc_rt_DataList_t *args
    )
);

SHSC_EXPORT
void shsc_init_apifn_ops(
    void (* _shsc_rt_op_ampersand)              (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_arith_rshift)           (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_assign)                 (shsc_rt_Data_t       *lhs, const shsc_rt_Data_t *rhs, bool is_const, bool is_weak),
    void (* _shsc_rt_op_asterix)                (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_bang)                   (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_bitwise_lshift)         (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_bitwise_rshift)         (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_caret)                  (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_decrement)              (shsc_rt_Data_t       *lhs, shsc_rt_Data_t       *rhs),
    void (* _shsc_rt_op_dot)                    (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_exponent)               (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_floor_divide)           (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_fslash)                 (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_increment)              (shsc_rt_Data_t       *lhs, shsc_rt_Data_t       *rhs),
    void (* _shsc_rt_op_lbrace_angular)         (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_logical_and)            (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_logical_equal)          (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_logical_greater_equal)  (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_logical_lesser_equal)   (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_logical_or)             (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_logical_unequal)        (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_minus)                  (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_percent)                (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_pipe)                   (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_plus)                   (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_rbrace_angular)         (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_tilde)                  (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_fnargs_indexing)        (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_fncall)                 (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_indexing)               (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs),
    void (* _shsc_rt_op_nop)                    (const shsc_rt_Data_t *lhs),
    void (* _shsc_rt_op_ternary_cond)           (const shsc_rt_Data_t *lhs, const shsc_rt_Data_t *rhs, const shsc_rt_Data_t *condition)
);

#endif
