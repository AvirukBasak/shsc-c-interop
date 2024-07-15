#ifndef __SHSCINIT_H__
#define __SHSCINIT_H__

#include "shscfnptr.h"
#include "shscproto.h"
#include "shscinit.h"

MARK_USED
void shsc_init_apifn_data(
    shsc_ptr_Data_bul_t _rt_Data_bul,
    shsc_ptr_Data_chr_t _rt_Data_chr,
    shsc_ptr_Data_i64_t _rt_Data_i64,
    shsc_ptr_Data_f64_t _rt_Data_f64,
    shsc_ptr_Data_str_t _rt_Data_str,
    shsc_ptr_Data_list_t _rt_Data_list,
    shsc_ptr_Data_map_t _rt_Data_map,
    shsc_ptr_Data_any_t _rt_Data_any,
    shsc_ptr_Data_null_t _rt_Data_null,
    shsc_ptr_Data_clone_t _rt_Data_clone,
    shsc_ptr_Data_incref_t _rt_Data_incref,
    shsc_ptr_Data_decref_t _rt_Data_decref,
    shsc_ptr_Data_destroy_t _rt_Data_destroy,
    shsc_ptr_Data_isnull_t _rt_Data_isnull,
    shsc_ptr_Data_isnumeric_t _rt_Data_isnumeric,
    shsc_ptr_Data_isequal_t _rt_Data_isequal,
    shsc_ptr_Data_compare_t _rt_Data_compare,
    shsc_ptr_Data_tobool_t _rt_Data_tobool,
    shsc_ptr_Data_tostr_t _rt_Data_tostr,
    shsc_ptr_Data_cast_t _rt_Data_cast,
    shsc_ptr_Data_typename_t _rt_Data_typename,
    shsc_ptr_Data_assert_type_t _rt_Data_assert_type,
    shsc_ptr_Data_greater_type_t _rt_Data_greater_type,
    shsc_ptr_Data_print_t _rt_Data_print
) {
    _shsc_ptr_Data_bul = _rt_Data_bul;
    _shsc_ptr_Data_chr = _rt_Data_chr;
    _shsc_ptr_Data_i64 = _rt_Data_i64;
    _shsc_ptr_Data_f64 = _rt_Data_f64;
    _shsc_ptr_Data_str = _rt_Data_str;
    _shsc_ptr_Data_list = _rt_Data_list;
    _shsc_ptr_Data_map = _rt_Data_map;
    _shsc_ptr_Data_any = _rt_Data_any;
    _shsc_ptr_Data_null = _rt_Data_null;
    _shsc_ptr_Data_clone = _rt_Data_clone;
    _shsc_ptr_Data_incref = _rt_Data_incref;
    _shsc_ptr_Data_decref = _rt_Data_decref;
    _shsc_ptr_Data_destroy = _rt_Data_destroy;
    _shsc_ptr_Data_isnull = _rt_Data_isnull;
    _shsc_ptr_Data_isnumeric = _rt_Data_isnumeric;
    _shsc_ptr_Data_isequal = _rt_Data_isequal;
    _shsc_ptr_Data_compare = _rt_Data_compare;
    _shsc_ptr_Data_tobool = _rt_Data_tobool;
    _shsc_ptr_Data_tostr = _rt_Data_tostr;
    _shsc_ptr_Data_cast = _rt_Data_cast;
    _shsc_ptr_Data_typename = _rt_Data_typename;
    _shsc_ptr_Data_assert_type = _rt_Data_assert_type;
    _shsc_ptr_Data_greater_type = _rt_Data_greater_type;
    _shsc_ptr_Data_print = _rt_Data_print;
}

MARK_USED
void shsc_init_apifn_vartable(
    shsc_ptr_VarTable_modf_t _rt_VarTable_modf
) {
    _shsc_ptr_VarTable_modf = _rt_VarTable_modf;
}

MARK_USED
void shsc_init_apifn_list(
    shsc_ptr_DataList_init_t _rt_DataList_init,
    shsc_ptr_DataList_clone_t _rt_DataList_clone,
    shsc_ptr_DataList_length_t _rt_DataList_length,
    shsc_ptr_DataList_destroy_t _rt_DataList_destroy,
    shsc_ptr_DataList_isequal_t _rt_DataList_isequal,
    shsc_ptr_DataList_compare_t _rt_DataList_compare,
    shsc_ptr_DataList_append_t _rt_DataList_append,
    shsc_ptr_DataList_concat_t _rt_DataList_concat,
    shsc_ptr_DataList_insert_t _rt_DataList_insert,
    shsc_ptr_DataList_erase_t _rt_DataList_erase,
    shsc_ptr_DataList_reverse_t _rt_DataList_reverse,
    shsc_ptr_DataList_find_t _rt_DataList_find,
    shsc_ptr_DataList_sublist_t _rt_DataList_sublist,
    shsc_ptr_DataList_join_t _rt_DataList_join,
    shsc_ptr_DataList_sort_t _rt_DataList_sort,
    shsc_ptr_DataList_getref_errnull_t _rt_DataList_getref_errnull,
    shsc_ptr_DataList_getref_t _rt_DataList_getref,
    shsc_ptr_DataList_del_index_t _rt_DataList_del_index,
    shsc_ptr_DataList_del_val_t _rt_DataList_del_val,
    shsc_ptr_DataList_tostr_t _rt_DataList_tostr
) {
    _shsc_ptr_DataList_init = _rt_DataList_init;
    _shsc_ptr_DataList_clone = _rt_DataList_clone;
    _shsc_ptr_DataList_length = _rt_DataList_length;
    _shsc_ptr_DataList_destroy = _rt_DataList_destroy;
    _shsc_ptr_DataList_isequal = _rt_DataList_isequal;
    _shsc_ptr_DataList_compare = _rt_DataList_compare;
    _shsc_ptr_DataList_append = _rt_DataList_append;
    _shsc_ptr_DataList_concat = _rt_DataList_concat;
    _shsc_ptr_DataList_insert = _rt_DataList_insert;
    _shsc_ptr_DataList_erase = _rt_DataList_erase;
    _shsc_ptr_DataList_reverse = _rt_DataList_reverse;
    _shsc_ptr_DataList_find = _rt_DataList_find;
    _shsc_ptr_DataList_sublist = _rt_DataList_sublist;
    _shsc_ptr_DataList_join = _rt_DataList_join;
    _shsc_ptr_DataList_sort = _rt_DataList_sort;
    _shsc_ptr_DataList_getref_errnull = _rt_DataList_getref_errnull;
    _shsc_ptr_DataList_getref = _rt_DataList_getref;
    _shsc_ptr_DataList_del_index = _rt_DataList_del_index;
    _shsc_ptr_DataList_del_val = _rt_DataList_del_val;
    _shsc_ptr_DataList_tostr = _rt_DataList_tostr;
}

MARK_USED
void shsc_init_apifn_map(
    shsc_ptr_DataMap_init_t _rt_DataMap_init,
    shsc_ptr_DataMap_clone_t _rt_DataMap_clone,
    shsc_ptr_DataMap_length_t _rt_DataMap_length,
    shsc_ptr_DataMap_destroy_t _rt_DataMap_destroy,
    shsc_ptr_DataMap_insert_t _rt_DataMap_insert,
    shsc_ptr_DataMap_del_t _rt_DataMap_del,
    shsc_ptr_DataMap_concat_t _rt_DataMap_concat,
    shsc_ptr_DataMap_getkey_copy_t _rt_DataMap_getkey_copy,
    shsc_ptr_DataMap_getref_errnull_t _rt_DataMap_getref_errnull,
    shsc_ptr_DataMap_getref_t _rt_DataMap_getref,
    shsc_ptr_DataMap_tostr_t _rt_DataMap_tostr
) {
    _shsc_ptr_DataMap_init = _rt_DataMap_init;
    _shsc_ptr_DataMap_clone = _rt_DataMap_clone;
    _shsc_ptr_DataMap_length = _rt_DataMap_length;
    _shsc_ptr_DataMap_destroy = _rt_DataMap_destroy;
    _shsc_ptr_DataMap_insert = _rt_DataMap_insert;
    _shsc_ptr_DataMap_del = _rt_DataMap_del;
    _shsc_ptr_DataMap_concat = _rt_DataMap_concat;
    _shsc_ptr_DataMap_getkey_copy = _rt_DataMap_getkey_copy;
    _shsc_ptr_DataMap_getref_errnull = _rt_DataMap_getref_errnull;
    _shsc_ptr_DataMap_getref = _rt_DataMap_getref;
    _shsc_ptr_DataMap_tostr = _rt_DataMap_tostr;
}

MARK_USED
void shsc_init_apifn_str(
    shsc_ptr_DataStr_init_t _rt_DataStr_init,
    shsc_ptr_DataStr_clone_t _rt_DataStr_clone,
    shsc_ptr_DataStr_length_t _rt_DataStr_length,
    shsc_ptr_DataStr_destroy_t _rt_DataStr_destroy,
    shsc_ptr_DataStr_toupper_t _rt_DataStr_toupper,
    shsc_ptr_DataStr_tolower_t _rt_DataStr_tolower,
    shsc_ptr_DataStr_append_t _rt_DataStr_append,
    shsc_ptr_DataStr_concat_t _rt_DataStr_concat,
    shsc_ptr_DataStr_insert_t _rt_DataStr_insert,
    shsc_ptr_DataStr_insert_str_t _rt_DataStr_insert_str,
    shsc_ptr_DataStr_erase_t _rt_DataStr_erase,
    shsc_ptr_DataStr_reverse_t _rt_DataStr_reverse,
    shsc_ptr_DataStr_isequal_t _rt_DataStr_isequal,
    shsc_ptr_DataStr_compare_t _rt_DataStr_compare,
    shsc_ptr_DataStr_find_t _rt_DataStr_find,
    shsc_ptr_DataStr_find_str_t _rt_DataStr_find_str,
    shsc_ptr_DataStr_substr_t _rt_DataStr_substr,
    shsc_ptr_DataStr_split_t _rt_DataStr_split,
    shsc_ptr_DataStr_split_str_t _rt_DataStr_split_str,
    shsc_ptr_DataStr_sort_t _rt_DataStr_sort,
    shsc_ptr_DataStr_toi64_t _rt_DataStr_toi64,
    shsc_ptr_DataStr_tof64_t _rt_DataStr_tof64,
    shsc_ptr_DataStr_getref_errnull_t _rt_DataStr_getref_errnull,
    shsc_ptr_DataStr_getref_t _rt_DataStr_getref,
    shsc_ptr_DataStr_del_index_t _rt_DataStr_del_index,
    shsc_ptr_DataStr_del_char_t _rt_DataStr_del_char,
    shsc_ptr_DataStr_tostr_t _rt_DataStr_tostr
) {
    _shsc_ptr_DataStr_init = _rt_DataStr_init;
    _shsc_ptr_DataStr_clone = _rt_DataStr_clone;
    _shsc_ptr_DataStr_length = _rt_DataStr_length;
    _shsc_ptr_DataStr_destroy = _rt_DataStr_destroy;
    _shsc_ptr_DataStr_toupper = _rt_DataStr_toupper;
    _shsc_ptr_DataStr_tolower = _rt_DataStr_tolower;
    _shsc_ptr_DataStr_append = _rt_DataStr_append;
    _shsc_ptr_DataStr_concat = _rt_DataStr_concat;
    _shsc_ptr_DataStr_insert = _rt_DataStr_insert;
    _shsc_ptr_DataStr_insert_str = _rt_DataStr_insert_str;
    _shsc_ptr_DataStr_erase = _rt_DataStr_erase;
    _shsc_ptr_DataStr_reverse = _rt_DataStr_reverse;
    _shsc_ptr_DataStr_isequal = _rt_DataStr_isequal;
    _shsc_ptr_DataStr_compare = _rt_DataStr_compare;
    _shsc_ptr_DataStr_find = _rt_DataStr_find;
    _shsc_ptr_DataStr_find_str = _rt_DataStr_find_str;
    _shsc_ptr_DataStr_substr = _rt_DataStr_substr;
    _shsc_ptr_DataStr_split = _rt_DataStr_split;
    _shsc_ptr_DataStr_split_str = _rt_DataStr_split_str;
    _shsc_ptr_DataStr_sort = _rt_DataStr_sort;
    _shsc_ptr_DataStr_toi64 = _rt_DataStr_toi64;
    _shsc_ptr_DataStr_tof64 = _rt_DataStr_tof64;
    _shsc_ptr_DataStr_getref_errnull = _rt_DataStr_getref_errnull;
    _shsc_ptr_DataStr_getref = _rt_DataStr_getref;
    _shsc_ptr_DataStr_del_index = _rt_DataStr_del_index;
    _shsc_ptr_DataStr_del_char = _rt_DataStr_del_char;
    _shsc_ptr_DataStr_tostr = _rt_DataStr_tostr;
}

MARK_USED
void shsc_init_apifn_others(
    shsc_ptr_throw_t _rt_throw,

    shsc_ptr_fn_get_valid_args_t _rt_fn_get_valid_args,
    shsc_ptr_fn_call_handler_t _rt_fn_call_handler,
    shsc_ptr_fn_lambda_call_handler_t _rt_fn_lambda_call_handler
) {
    shsc_throw = _rt_throw;

    _shsc_ptr_fn_get_valid_args = _rt_fn_get_valid_args;
    _shsc_ptr_fn_call_handler = _rt_fn_call_handler;
    _shsc_ptr_fn_lambda_call_handler = _rt_fn_lambda_call_handler;
}

MARK_USED
void shsc_init_apifn_ops(
    shsc_ptr_op_ampersand_t _rt_op_ampersand,
    shsc_ptr_op_arith_rshift_t _rt_op_arith_rshift,
    shsc_ptr_op_assign_t _rt_op_assign,
    shsc_ptr_op_asterix_t _rt_op_asterix,
    shsc_ptr_op_bang_t _rt_op_bang,
    shsc_ptr_op_bitwise_lshift_t _rt_op_bitwise_lshift,
    shsc_ptr_op_bitwise_rshift_t _rt_op_bitwise_rshift,
    shsc_ptr_op_caret_t _rt_op_caret,
    shsc_ptr_op_decrement_t _rt_op_decrement,
    shsc_ptr_op_dot_t _rt_op_dot,
    shsc_ptr_op_exponent_t _rt_op_exponent,
    shsc_ptr_op_floor_divide_t _rt_op_floor_divide,
    shsc_ptr_op_fslash_t _rt_op_fslash,
    shsc_ptr_op_increment_t _rt_op_increment,
    shsc_ptr_op_lbrace_angular_t _rt_op_lbrace_angular,
    shsc_ptr_op_logical_and_t _rt_op_logical_and,
    shsc_ptr_op_logical_equal_t _rt_op_logical_equal,
    shsc_ptr_op_logical_greater_equal_t _rt_op_logical_greater_equal,
    shsc_ptr_op_logical_lesser_equal_t _rt_op_logical_lesser_equal,
    shsc_ptr_op_logical_or_t _rt_op_logical_or,
    shsc_ptr_op_logical_unequal_t _rt_op_logical_unequal,
    shsc_ptr_op_minus_t _rt_op_minus,
    shsc_ptr_op_percent_t _rt_op_percent,
    shsc_ptr_op_pipe_t _rt_op_pipe,
    shsc_ptr_op_plus_t _rt_op_plus,
    shsc_ptr_op_rbrace_angular_t _rt_op_rbrace_angular,
    shsc_ptr_op_tilde_t _rt_op_tilde,
    shsc_ptr_op_fnargs_indexing_t _rt_op_fnargs_indexing,
    shsc_ptr_op_fncall_t _rt_op_fncall,
    shsc_ptr_op_indexing_t _rt_op_indexing,
    shsc_ptr_op_nop_t _rt_op_nop,
    shsc_ptr_op_ternary_cond_t _rt_op_ternary_cond
) {
    _shsc_ptr_op_ampersand = _rt_op_ampersand;
    _shsc_ptr_op_arith_rshift = _rt_op_arith_rshift;
    _shsc_ptr_op_assign = _rt_op_assign;
    _shsc_ptr_op_asterix = _rt_op_asterix;
    _shsc_ptr_op_bang = _rt_op_bang;
    _shsc_ptr_op_bitwise_lshift = _rt_op_bitwise_lshift;
    _shsc_ptr_op_bitwise_rshift = _rt_op_bitwise_rshift;
    _shsc_ptr_op_caret = _rt_op_caret;
    _shsc_ptr_op_decrement = _rt_op_decrement;
    _shsc_ptr_op_dot = _rt_op_dot;
    _shsc_ptr_op_exponent = _rt_op_exponent;
    _shsc_ptr_op_floor_divide = _rt_op_floor_divide;
    _shsc_ptr_op_fslash = _rt_op_fslash;
    _shsc_ptr_op_increment = _rt_op_increment;
    _shsc_ptr_op_lbrace_angular = _rt_op_lbrace_angular;
    _shsc_ptr_op_logical_and = _rt_op_logical_and;
    _shsc_ptr_op_logical_equal = _rt_op_logical_equal;
    _shsc_ptr_op_logical_greater_equal = _rt_op_logical_greater_equal;
    _shsc_ptr_op_logical_lesser_equal = _rt_op_logical_lesser_equal;
    _shsc_ptr_op_logical_or = _rt_op_logical_or;
    _shsc_ptr_op_logical_unequal = _rt_op_logical_unequal;
    _shsc_ptr_op_minus = _rt_op_minus;
    _shsc_ptr_op_percent = _rt_op_percent;
    _shsc_ptr_op_pipe = _rt_op_pipe;
    _shsc_ptr_op_plus = _rt_op_plus;
    _shsc_ptr_op_rbrace_angular = _rt_op_rbrace_angular;
    _shsc_ptr_op_tilde = _rt_op_tilde;
    _shsc_ptr_op_fnargs_indexing = _rt_op_fnargs_indexing;
    _shsc_ptr_op_fncall = _rt_op_fncall;
    _shsc_ptr_op_indexing = _rt_op_indexing;
    _shsc_ptr_op_nop = _rt_op_nop;
    _shsc_ptr_op_ternary_cond = _rt_op_ternary_cond;
}

#else
    #warning re-inclusion of module 'src/shscinit.c.h'
#endif
