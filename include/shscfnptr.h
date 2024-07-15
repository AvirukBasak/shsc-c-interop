#ifndef __SHSC_FN_PTR_H__
#define __SHSC_FN_PTR_H__

/**

The purpose of this file is to provide the SHSC runtime a way to set pointers to
functions that are defined in the SHSC runtime. This is useful for calling SHSC
functions from C code defined in an external library.

These function pointers may be called from C code directly, or may be called via
the cleaner names defined in shscproto.h.

*/

#include <stdbool.h>
#include <stdint.h>

#if _WIN32
    #define DL_EXPORT __declspec(dllexport)
#else
    #define DL_EXPORT __attribute__((visibility("default")))
#endif

#define MARK_USED __attribute__((used))
#define FN_MODIFIERS extern

#include "shsctypes.h"

typedef rt_Data_t          (* shsc_ptr_Data_bul_t)         (bool            val);
typedef rt_Data_t          (* shsc_ptr_Data_chr_t)         (char            val);
typedef rt_Data_t          (* shsc_ptr_Data_i64_t)         (int64_t         val);
typedef rt_Data_t          (* shsc_ptr_Data_f64_t)         (double          val);
typedef rt_Data_t          (* shsc_ptr_Data_str_t)         (rt_DataStr_t   *str);
typedef rt_Data_t          (* shsc_ptr_Data_list_t)        (rt_DataList_t  *lst);
typedef rt_Data_t          (* shsc_ptr_Data_map_t)         (rt_DataMap_t   *mp);
typedef rt_Data_t          (* shsc_ptr_Data_any_t)         (void           *ptr);
typedef rt_Data_t          (* shsc_ptr_Data_null_t)        (void);
typedef rt_Data_t          (* shsc_ptr_Data_clone_t)       (const rt_Data_t var);
typedef void               (* shsc_ptr_Data_incref_t)      (rt_Data_t      *var);
typedef void               (* shsc_ptr_Data_decref_t)      (rt_Data_t      *var);
typedef void               (* shsc_ptr_Data_destroy_t)     (rt_Data_t      *var);
typedef bool               (* shsc_ptr_Data_isnull_t)      (const rt_Data_t var);
typedef bool               (* shsc_ptr_Data_isnumeric_t)   (const rt_Data_t var);
typedef bool               (* shsc_ptr_Data_isequal_t)     (const rt_Data_t var1, const rt_Data_t    var2);
typedef int64_t            (* shsc_ptr_Data_compare_t)     (const rt_Data_t var1, const rt_Data_t    var2);
typedef bool               (* shsc_ptr_Data_tobool_t)      (const rt_Data_t var);
typedef char              *(* shsc_ptr_Data_tostr_t)       (const rt_Data_t var);
typedef rt_Data_t          (* shsc_ptr_Data_cast_t)        (const rt_Data_t var,  rt_DataType_t type);
typedef const char        *(* shsc_ptr_Data_typename_t)    (const rt_Data_t var);
typedef bool               (* shsc_ptr_Data_assert_type_t) (const rt_Data_t var,  rt_DataType_t expected_type, const char *for_varname);
typedef enum rt_DataType_t (* shsc_ptr_Data_greater_type_t)(const rt_Data_t var1, const rt_Data_t    var2);
typedef int                (* shsc_ptr_Data_print_t)       (const rt_Data_t var);

/*------------------------
 |       VAR TABLE        |
 ------------------------*/

/**
 * This function is used to modify the value of a variable that exists
 * in the variable table. It takes care of reference counts.
 */
typedef rt_Data_t         *(* shsc_ptr_VarTable_modf_t)    (rt_Data_t *dest, rt_Data_t src, bool is_const, bool is_weak);

/*------------------------
 |       LIST DATA       |
 ------------------------*/

/**
 * List types should not be used unless the purpose is to
 * interact with Shsc lists. Shsc lists are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C arrays or other native data structures.
 */
typedef rt_DataList_t     *(* shsc_ptr_DataList_init_t)();

/**
 * List types should not be used unless the purpose is to
 * interact with Shsc lists. Shsc lists are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C arrays or other native data structures.
 */
typedef rt_DataList_t     *(* shsc_ptr_DataList_clone_t)         (const rt_DataList_t *lst);

typedef int64_t            (* shsc_ptr_DataList_length_t)        (const rt_DataList_t *lst);
typedef void               (* shsc_ptr_DataList_destroy_t)       (rt_DataList_t      **ptr);
typedef bool               (* shsc_ptr_DataList_isequal_t)       (const rt_DataList_t *p_lst1, const rt_DataList_t *p_lst2);
typedef int64_t            (* shsc_ptr_DataList_compare_t)       (const rt_DataList_t *p_lst1, const rt_DataList_t *p_lst2);
typedef void               (* shsc_ptr_DataList_append_t)        (rt_DataList_t       *lst,  rt_Data_t            var);
typedef void               (* shsc_ptr_DataList_concat_t)        (rt_DataList_t       *lst,  const rt_DataList_t *p_lst2);
typedef void               (* shsc_ptr_DataList_insert_t)        (rt_DataList_t       *lst,  int64_t              idx,   rt_Data_t var);
typedef void               (* shsc_ptr_DataList_erase_t)         (rt_DataList_t       *lst,  int64_t              idx,   int64_t   len);
typedef void               (* shsc_ptr_DataList_reverse_t)       (rt_DataList_t       *lst);
typedef int64_t            (* shsc_ptr_DataList_find_t)          (const rt_DataList_t *lst,  rt_Data_t            var);
typedef rt_DataList_t     *(* shsc_ptr_DataList_sublist_t)       (const rt_DataList_t *lst,  int64_t              idx,   int64_t   len);
typedef rt_DataStr_t      *(* shsc_ptr_DataList_join_t)          (const rt_DataList_t *lst,  const rt_DataStr_t  *sep);
typedef rt_DataList_t     *(* shsc_ptr_DataList_sort_t)          (rt_DataList_t       *lst);
typedef rt_Data_t         *(* shsc_ptr_DataList_getref_errnull_t)(const rt_DataList_t *lst,  int64_t              idx);

/** data should be updated only by calling
    `void rt_VarTable_modf(rt_Data_t *dest, rt_Data_t src)`
    on the returned data pointer, that'll take care of reference counts */
typedef rt_Data_t         *(* shsc_ptr_DataList_getref_t)        (const rt_DataList_t *lst, int64_t   idx);

typedef void               (* shsc_ptr_DataList_del_index_t)     (rt_DataList_t       *lst, int64_t   idx);
typedef void               (* shsc_ptr_DataList_del_val_t)       (rt_DataList_t       *lst, rt_Data_t var);
typedef char              *(* shsc_ptr_DataList_tostr_t)         (const rt_DataList_t *lst);

/*------------------------
 |       MAP DATA        |
 ------------------------*/

/**
 * Map types should not be used unless the purpose is to
 * interact with Shsc maps. Shsc maps are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C hash maps or other native data structures.
 */
typedef rt_DataMap_t      *(* shsc_ptr_DataMap_init_t)();

/**
 * Map types should not be used unless the purpose is to
 * interact with Shsc maps. Shsc maps are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C hash maps or other native data structures.
 */
typedef rt_DataMap_t      *(* shsc_ptr_DataMap_clone_t)          (const rt_DataMap_t  *mp);

typedef int64_t            (* shsc_ptr_DataMap_length_t)         (const rt_DataMap_t  *mp);
typedef void               (* shsc_ptr_DataMap_destroy_t)        (rt_DataMap_t       **ptr);
typedef void               (* shsc_ptr_DataMap_insert_t)         (rt_DataMap_t        *mp,   const char         *key,  rt_Data_t value);
typedef void               (* shsc_ptr_DataMap_del_t)            (rt_DataMap_t        *mp,   const char         *key);
typedef void               (* shsc_ptr_DataMap_concat_t)         (rt_DataMap_t        *mp1,  const rt_DataMap_t *mp2);
typedef const char        *(* shsc_ptr_DataMap_getkey_copy_t)    (const rt_DataMap_t  *mp,   const char         *key);

/** unlike rt_DataMap_getref, returns NULL if key not found */
typedef rt_Data_t         *(* shsc_ptr_DataMap_getref_errnull_t) (const rt_DataMap_t *mp,    const char         *key);

/** unlike rt_DataMap_getref_errnull, CRASHES using rt_throw if key not found.
    data should be updated only by calling
    `void rt_VarTable_modf(rt_Data_t *dest, rt_Data_t src)`
    on the returned data pointer, that'll take care of reference counts */
typedef rt_Data_t         *(* shsc_ptr_DataMap_getref_t)         (const rt_DataMap_t *mp,     const char        *key);

typedef char              *(* shsc_ptr_DataMap_tostr_t)          (const rt_DataMap_t *mp);

/*------------------------
 |       STR DATA        |
 ------------------------*/

/**
 * String types should not be used unless the purpose is to
 * interact with Shsc strings. Shsc strings are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C strings or other native data structures.
 */
typedef rt_DataStr_t      *(* shsc_ptr_DataStr_init_t)(const char *s);

/**
 * String types should not be used unless the purpose is to
 * interact with Shsc strings. Shsc strings are reference counted
 * and involve a large amount of overhead.
 * Intead, make use of C strings or other native data structures.
 */
typedef rt_DataStr_t      *(* shsc_ptr_DataStr_clone_t)          (const rt_DataStr_t *str);

typedef int64_t            (* shsc_ptr_DataStr_length_t)         (const rt_DataStr_t *str);
typedef void               (* shsc_ptr_DataStr_destroy_t)        (rt_DataStr_t       **ptr);
typedef void               (* shsc_ptr_DataStr_toupper_t)        (rt_DataStr_t        *str);
typedef void               (* shsc_ptr_DataStr_tolower_t)        (rt_DataStr_t        *str);
typedef void               (* shsc_ptr_DataStr_append_t)         (rt_DataStr_t        *str, char                 ch);
typedef void               (* shsc_ptr_DataStr_concat_t)         (rt_DataStr_t        *str, const rt_DataStr_t  *str2);
typedef void               (* shsc_ptr_DataStr_insert_t)         (rt_DataStr_t        *str, int64_t              idx, char                ch);
typedef void               (* shsc_ptr_DataStr_insert_str_t)     (rt_DataStr_t        *str, int64_t              idx, const rt_DataStr_t *str2);
typedef void               (* shsc_ptr_DataStr_erase_t)          (rt_DataStr_t        *str, int64_t              idx, int64_t             len);
typedef void               (* shsc_ptr_DataStr_reverse_t)        (rt_DataStr_t        *str);
typedef bool               (* shsc_ptr_DataStr_isequal_t)        (const rt_DataStr_t  *str, const rt_DataStr_t  *str2);
typedef int64_t            (* shsc_ptr_DataStr_compare_t)        (const rt_DataStr_t  *str, const rt_DataStr_t  *str2);
typedef int64_t            (* shsc_ptr_DataStr_find_t)           (const rt_DataStr_t  *str, char                 ch);
typedef int64_t            (* shsc_ptr_DataStr_find_str_t)       (const rt_DataStr_t  *str, const rt_DataStr_t  *str2);
typedef rt_DataStr_t      *(* shsc_ptr_DataStr_substr_t)         (const rt_DataStr_t  *str, int64_t idx, int64_t len);
typedef rt_DataList_t     *(* shsc_ptr_DataStr_split_t)          (const rt_DataStr_t  *str, char                 ch);
typedef rt_DataList_t     *(* shsc_ptr_DataStr_split_str_t)      (const rt_DataStr_t  *str, const rt_DataStr_t  *str2);
typedef rt_DataStr_t      *(* shsc_ptr_DataStr_sort_t)           (rt_DataStr_t        *str);
typedef rt_Data_t          (* shsc_ptr_DataStr_toi64_t)          (const rt_DataStr_t  *str);
typedef rt_Data_t          (* shsc_ptr_DataStr_tof64_t)          (const rt_DataStr_t  *str);
typedef char              *(* shsc_ptr_DataStr_getref_errnull_t) (const rt_DataStr_t  *str, int64_t idx);

/** data can be updated by assigning a char to the returned pointer */
typedef rt_Data_t         *(* shsc_ptr_DataStr_getref_t)(const rt_DataStr_t *str, int64_t idx);

typedef void               (* shsc_ptr_DataStr_del_index_t)      (rt_DataStr_t *str, int64_t idx);
typedef void               (* shsc_ptr_DataStr_del_char_t)       (rt_DataStr_t *str, char ch);
typedef char              *(* shsc_ptr_DataStr_tostr_t)          (const rt_DataStr_t *str);

/*------------------------
 | FUNCTION CALL HANDLER |
 ------------------------*/

/**
 * Calls rt_throw if the number of arguments is less than min_expected_argc.
 * Results in a runtime error.
 */
typedef const rt_DataList_t *(* shsc_ptr_fn_get_valid_args_t)(int64_t min_expected_argc);

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
typedef rt_Data_t (* shsc_ptr_fn_call_handler_t)(
    const rt_Data_t context,
    const char *module_name,
    const char *proc_name,
    rt_DataList_t *args
);

/**
 * This function is provided for calling lambda functions.
 * Such lambda functions may be passed by from Shsc code as callbacks.
 */
typedef rt_Data_t (* shsc_ptr_fn_lambda_call_handler_t)(
    const rt_Data_t context,
    const rt_DataLambda_t lambda,
    rt_DataList_t *args
);

/*------------------------
 |       OPERATORS       |
 ------------------------*/

typedef void (* shsc_ptr_op_ampersand_t)              (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_arith_rshift_t)           (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_assign_t)                 (rt_Data_t       *lhs, const rt_Data_t *rhs, bool is_const, bool is_weak);
typedef void (* shsc_ptr_op_asterix_t)                (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_bang_t)                   (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_bitwise_lshift_t)         (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_bitwise_rshift_t)         (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_caret_t)                  (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_decrement_t)              (rt_Data_t       *lhs, rt_Data_t       *rhs);
typedef void (* shsc_ptr_op_dot_t)                    (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_exponent_t)               (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_floor_divide_t)           (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_fslash_t)                 (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_increment_t)              (rt_Data_t       *lhs, rt_Data_t       *rhs);
typedef void (* shsc_ptr_op_lbrace_angular_t)         (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_logical_and_t)            (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_logical_equal_t)          (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_logical_greater_equal_t)  (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_logical_lesser_equal_t)   (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_logical_or_t)             (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_logical_unequal_t)        (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_minus_t)                  (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_percent_t)                (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_pipe_t)                   (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_plus_t)                   (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_rbrace_angular_t)         (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_tilde_t)                  (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_fnargs_indexing_t)        (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_fncall_t)                 (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_indexing_t)               (const rt_Data_t *lhs, const rt_Data_t *rhs);
typedef void (* shsc_ptr_op_nop_t)                    (const rt_Data_t *lhs);
typedef void (* shsc_ptr_op_ternary_cond_t)           (const rt_Data_t *lhs, const rt_Data_t *rhs, const rt_Data_t *condition);

/*---------------------------------
 |  FN POINTERS WITH CLEANED API  |
 ---------------------------------*/

FN_MODIFIERS shsc_ptr_Data_bul_t _shsc_ptr_Data_bul;
FN_MODIFIERS shsc_ptr_Data_chr_t _shsc_ptr_Data_chr;
FN_MODIFIERS shsc_ptr_Data_i64_t _shsc_ptr_Data_i64;
FN_MODIFIERS shsc_ptr_Data_f64_t _shsc_ptr_Data_f64;
FN_MODIFIERS shsc_ptr_Data_str_t _shsc_ptr_Data_str;
FN_MODIFIERS shsc_ptr_Data_list_t _shsc_ptr_Data_list;
FN_MODIFIERS shsc_ptr_Data_map_t _shsc_ptr_Data_map;
FN_MODIFIERS shsc_ptr_Data_any_t _shsc_ptr_Data_any;
FN_MODIFIERS shsc_ptr_Data_null_t _shsc_ptr_Data_null;
FN_MODIFIERS shsc_ptr_Data_clone_t _shsc_ptr_Data_clone;
FN_MODIFIERS shsc_ptr_Data_incref_t _shsc_ptr_Data_incref;
FN_MODIFIERS shsc_ptr_Data_decref_t _shsc_ptr_Data_decref;
FN_MODIFIERS shsc_ptr_Data_destroy_t _shsc_ptr_Data_destroy;
FN_MODIFIERS shsc_ptr_Data_isnull_t _shsc_ptr_Data_isnull;
FN_MODIFIERS shsc_ptr_Data_isnumeric_t _shsc_ptr_Data_isnumeric;
FN_MODIFIERS shsc_ptr_Data_isequal_t _shsc_ptr_Data_isequal;
FN_MODIFIERS shsc_ptr_Data_compare_t _shsc_ptr_Data_compare;
FN_MODIFIERS shsc_ptr_Data_tobool_t _shsc_ptr_Data_tobool;
FN_MODIFIERS shsc_ptr_Data_tostr_t _shsc_ptr_Data_tostr;
FN_MODIFIERS shsc_ptr_Data_cast_t _shsc_ptr_Data_cast;
FN_MODIFIERS shsc_ptr_Data_typename_t _shsc_ptr_Data_typename;
FN_MODIFIERS shsc_ptr_Data_assert_type_t _shsc_ptr_Data_assert_type;
FN_MODIFIERS shsc_ptr_Data_greater_type_t _shsc_ptr_Data_greater_type;
FN_MODIFIERS shsc_ptr_Data_print_t _shsc_ptr_Data_print;
FN_MODIFIERS shsc_ptr_VarTable_modf_t _shsc_ptr_VarTable_modf;
FN_MODIFIERS shsc_ptr_DataList_init_t _shsc_ptr_DataList_init;
FN_MODIFIERS shsc_ptr_DataList_clone_t _shsc_ptr_DataList_clone;
FN_MODIFIERS shsc_ptr_DataList_length_t _shsc_ptr_DataList_length;
FN_MODIFIERS shsc_ptr_DataList_destroy_t _shsc_ptr_DataList_destroy;
FN_MODIFIERS shsc_ptr_DataList_isequal_t _shsc_ptr_DataList_isequal;
FN_MODIFIERS shsc_ptr_DataList_compare_t _shsc_ptr_DataList_compare;
FN_MODIFIERS shsc_ptr_DataList_append_t _shsc_ptr_DataList_append;
FN_MODIFIERS shsc_ptr_DataList_concat_t _shsc_ptr_DataList_concat;
FN_MODIFIERS shsc_ptr_DataList_insert_t _shsc_ptr_DataList_insert;
FN_MODIFIERS shsc_ptr_DataList_erase_t _shsc_ptr_DataList_erase;
FN_MODIFIERS shsc_ptr_DataList_reverse_t _shsc_ptr_DataList_reverse;
FN_MODIFIERS shsc_ptr_DataList_find_t _shsc_ptr_DataList_find;
FN_MODIFIERS shsc_ptr_DataList_sublist_t _shsc_ptr_DataList_sublist;
FN_MODIFIERS shsc_ptr_DataList_join_t _shsc_ptr_DataList_join;
FN_MODIFIERS shsc_ptr_DataList_sort_t _shsc_ptr_DataList_sort;
FN_MODIFIERS shsc_ptr_DataList_getref_errnull_t _shsc_ptr_DataList_getref_errnull;
FN_MODIFIERS shsc_ptr_DataList_getref_t _shsc_ptr_DataList_getref;
FN_MODIFIERS shsc_ptr_DataList_del_index_t _shsc_ptr_DataList_del_index;
FN_MODIFIERS shsc_ptr_DataList_del_val_t _shsc_ptr_DataList_del_val;
FN_MODIFIERS shsc_ptr_DataList_tostr_t _shsc_ptr_DataList_tostr;
FN_MODIFIERS shsc_ptr_DataMap_init_t _shsc_ptr_DataMap_init;
FN_MODIFIERS shsc_ptr_DataMap_clone_t _shsc_ptr_DataMap_clone;
FN_MODIFIERS shsc_ptr_DataMap_length_t _shsc_ptr_DataMap_length;
FN_MODIFIERS shsc_ptr_DataMap_destroy_t _shsc_ptr_DataMap_destroy;
FN_MODIFIERS shsc_ptr_DataMap_insert_t _shsc_ptr_DataMap_insert;
FN_MODIFIERS shsc_ptr_DataMap_del_t _shsc_ptr_DataMap_del;
FN_MODIFIERS shsc_ptr_DataMap_concat_t _shsc_ptr_DataMap_concat;
FN_MODIFIERS shsc_ptr_DataMap_getkey_copy_t _shsc_ptr_DataMap_getkey_copy;
FN_MODIFIERS shsc_ptr_DataMap_getref_errnull_t _shsc_ptr_DataMap_getref_errnull;
FN_MODIFIERS shsc_ptr_DataMap_getref_t _shsc_ptr_DataMap_getref;
FN_MODIFIERS shsc_ptr_DataMap_tostr_t _shsc_ptr_DataMap_tostr;
FN_MODIFIERS shsc_ptr_DataStr_init_t _shsc_ptr_DataStr_init;
FN_MODIFIERS shsc_ptr_DataStr_clone_t _shsc_ptr_DataStr_clone;
FN_MODIFIERS shsc_ptr_DataStr_length_t _shsc_ptr_DataStr_length;
FN_MODIFIERS shsc_ptr_DataStr_destroy_t _shsc_ptr_DataStr_destroy;
FN_MODIFIERS shsc_ptr_DataStr_toupper_t _shsc_ptr_DataStr_toupper;
FN_MODIFIERS shsc_ptr_DataStr_tolower_t _shsc_ptr_DataStr_tolower;
FN_MODIFIERS shsc_ptr_DataStr_append_t _shsc_ptr_DataStr_append;
FN_MODIFIERS shsc_ptr_DataStr_concat_t _shsc_ptr_DataStr_concat;
FN_MODIFIERS shsc_ptr_DataStr_insert_t _shsc_ptr_DataStr_insert;
FN_MODIFIERS shsc_ptr_DataStr_insert_str_t _shsc_ptr_DataStr_insert_str;
FN_MODIFIERS shsc_ptr_DataStr_erase_t _shsc_ptr_DataStr_erase;
FN_MODIFIERS shsc_ptr_DataStr_reverse_t _shsc_ptr_DataStr_reverse;
FN_MODIFIERS shsc_ptr_DataStr_isequal_t _shsc_ptr_DataStr_isequal;
FN_MODIFIERS shsc_ptr_DataStr_compare_t _shsc_ptr_DataStr_compare;
FN_MODIFIERS shsc_ptr_DataStr_find_t _shsc_ptr_DataStr_find;
FN_MODIFIERS shsc_ptr_DataStr_find_str_t _shsc_ptr_DataStr_find_str;
FN_MODIFIERS shsc_ptr_DataStr_substr_t _shsc_ptr_DataStr_substr;
FN_MODIFIERS shsc_ptr_DataStr_split_t _shsc_ptr_DataStr_split;
FN_MODIFIERS shsc_ptr_DataStr_split_str_t _shsc_ptr_DataStr_split_str;
FN_MODIFIERS shsc_ptr_DataStr_sort_t _shsc_ptr_DataStr_sort;
FN_MODIFIERS shsc_ptr_DataStr_toi64_t _shsc_ptr_DataStr_toi64;
FN_MODIFIERS shsc_ptr_DataStr_tof64_t _shsc_ptr_DataStr_tof64;
FN_MODIFIERS shsc_ptr_DataStr_getref_errnull_t _shsc_ptr_DataStr_getref_errnull;
FN_MODIFIERS shsc_ptr_DataStr_getref_t _shsc_ptr_DataStr_getref;
FN_MODIFIERS shsc_ptr_DataStr_del_index_t _shsc_ptr_DataStr_del_index;
FN_MODIFIERS shsc_ptr_DataStr_del_char_t _shsc_ptr_DataStr_del_char;
FN_MODIFIERS shsc_ptr_DataStr_tostr_t _shsc_ptr_DataStr_tostr;
FN_MODIFIERS shsc_ptr_fn_get_valid_args_t _shsc_ptr_fn_get_valid_args;
FN_MODIFIERS shsc_ptr_fn_call_handler_t _shsc_ptr_fn_call_handler;
FN_MODIFIERS shsc_ptr_fn_lambda_call_handler_t _shsc_ptr_fn_lambda_call_handler;
FN_MODIFIERS shsc_ptr_op_ampersand_t _shsc_ptr_op_ampersand;
FN_MODIFIERS shsc_ptr_op_arith_rshift_t _shsc_ptr_op_arith_rshift;
FN_MODIFIERS shsc_ptr_op_assign_t _shsc_ptr_op_assign;
FN_MODIFIERS shsc_ptr_op_asterix_t _shsc_ptr_op_asterix;
FN_MODIFIERS shsc_ptr_op_bang_t _shsc_ptr_op_bang;
FN_MODIFIERS shsc_ptr_op_bitwise_lshift_t _shsc_ptr_op_bitwise_lshift;
FN_MODIFIERS shsc_ptr_op_bitwise_rshift_t _shsc_ptr_op_bitwise_rshift;
FN_MODIFIERS shsc_ptr_op_caret_t _shsc_ptr_op_caret;
FN_MODIFIERS shsc_ptr_op_decrement_t _shsc_ptr_op_decrement;
FN_MODIFIERS shsc_ptr_op_dot_t _shsc_ptr_op_dot;
FN_MODIFIERS shsc_ptr_op_exponent_t _shsc_ptr_op_exponent;
FN_MODIFIERS shsc_ptr_op_floor_divide_t _shsc_ptr_op_floor_divide;
FN_MODIFIERS shsc_ptr_op_fslash_t _shsc_ptr_op_fslash;
FN_MODIFIERS shsc_ptr_op_increment_t _shsc_ptr_op_increment;
FN_MODIFIERS shsc_ptr_op_lbrace_angular_t _shsc_ptr_op_lbrace_angular;
FN_MODIFIERS shsc_ptr_op_logical_and_t _shsc_ptr_op_logical_and;
FN_MODIFIERS shsc_ptr_op_logical_equal_t _shsc_ptr_op_logical_equal;
FN_MODIFIERS shsc_ptr_op_logical_greater_equal_t _shsc_ptr_op_logical_greater_equal;
FN_MODIFIERS shsc_ptr_op_logical_lesser_equal_t _shsc_ptr_op_logical_lesser_equal;
FN_MODIFIERS shsc_ptr_op_logical_or_t _shsc_ptr_op_logical_or;
FN_MODIFIERS shsc_ptr_op_logical_unequal_t _shsc_ptr_op_logical_unequal;
FN_MODIFIERS shsc_ptr_op_minus_t _shsc_ptr_op_minus;
FN_MODIFIERS shsc_ptr_op_percent_t _shsc_ptr_op_percent;
FN_MODIFIERS shsc_ptr_op_pipe_t _shsc_ptr_op_pipe;
FN_MODIFIERS shsc_ptr_op_plus_t _shsc_ptr_op_plus;
FN_MODIFIERS shsc_ptr_op_rbrace_angular_t _shsc_ptr_op_rbrace_angular;
FN_MODIFIERS shsc_ptr_op_tilde_t _shsc_ptr_op_tilde;
FN_MODIFIERS shsc_ptr_op_fnargs_indexing_t _shsc_ptr_op_fnargs_indexing;
FN_MODIFIERS shsc_ptr_op_fncall_t _shsc_ptr_op_fncall;
FN_MODIFIERS shsc_ptr_op_indexing_t _shsc_ptr_op_indexing;
FN_MODIFIERS shsc_ptr_op_nop_t _shsc_ptr_op_nop;
FN_MODIFIERS shsc_ptr_op_ternary_cond_t _shsc_ptr_op_ternary_cond;

#endif
