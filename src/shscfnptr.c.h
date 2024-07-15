#ifndef __SHSC_FNPTR_C_H__
#define __SHSC_FNPTR_C_H__

#include <stdio.h>
#include "shscfnptr.h"
#include "shscprotoptr.h"

/*------------------------------------
 |  FN POINTERS WITHOUT CLEANED API  |
 ------------------------------------*/

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
shsc_ptr_throw_t shsc_throw = NULL;

/*---------------------------------
 |  FN POINTERS WITH CLEANED API  |
 ---------------------------------*/

shsc_ptr_Data_bul_t _shsc_ptr_Data_bul = NULL;
shsc_ptr_Data_chr_t _shsc_ptr_Data_chr = NULL;
shsc_ptr_Data_i64_t _shsc_ptr_Data_i64 = NULL;
shsc_ptr_Data_f64_t _shsc_ptr_Data_f64 = NULL;
shsc_ptr_Data_str_t _shsc_ptr_Data_str = NULL;
shsc_ptr_Data_list_t _shsc_ptr_Data_list = NULL;
shsc_ptr_Data_map_t _shsc_ptr_Data_map = NULL;
shsc_ptr_Data_any_t _shsc_ptr_Data_any = NULL;
shsc_ptr_Data_null_t _shsc_ptr_Data_null = NULL;
shsc_ptr_Data_clone_t _shsc_ptr_Data_clone = NULL;
shsc_ptr_Data_incref_t _shsc_ptr_Data_incref = NULL;
shsc_ptr_Data_decref_t _shsc_ptr_Data_decref = NULL;
shsc_ptr_Data_destroy_t _shsc_ptr_Data_destroy = NULL;
shsc_ptr_Data_isnull_t _shsc_ptr_Data_isnull = NULL;
shsc_ptr_Data_isnumeric_t _shsc_ptr_Data_isnumeric = NULL;
shsc_ptr_Data_isequal_t _shsc_ptr_Data_isequal = NULL;
shsc_ptr_Data_compare_t _shsc_ptr_Data_compare = NULL;
shsc_ptr_Data_tobool_t _shsc_ptr_Data_tobool = NULL;
shsc_ptr_Data_tostr_t _shsc_ptr_Data_tostr = NULL;
shsc_ptr_Data_cast_t _shsc_ptr_Data_cast = NULL;
shsc_ptr_Data_typename_t _shsc_ptr_Data_typename = NULL;
shsc_ptr_Data_assert_type_t _shsc_ptr_Data_assert_type = NULL;
shsc_ptr_Data_greater_type_t _shsc_ptr_Data_greater_type = NULL;
shsc_ptr_Data_print_t _shsc_ptr_Data_print = NULL;
shsc_ptr_VarTable_modf_t _shsc_ptr_VarTable_modf = NULL;
shsc_ptr_DataList_init_t _shsc_ptr_DataList_init = NULL;
shsc_ptr_DataList_clone_t _shsc_ptr_DataList_clone = NULL;
shsc_ptr_DataList_length_t _shsc_ptr_DataList_length = NULL;
shsc_ptr_DataList_destroy_t _shsc_ptr_DataList_destroy = NULL;
shsc_ptr_DataList_isequal_t _shsc_ptr_DataList_isequal = NULL;
shsc_ptr_DataList_compare_t _shsc_ptr_DataList_compare = NULL;
shsc_ptr_DataList_append_t _shsc_ptr_DataList_append = NULL;
shsc_ptr_DataList_concat_t _shsc_ptr_DataList_concat = NULL;
shsc_ptr_DataList_insert_t _shsc_ptr_DataList_insert = NULL;
shsc_ptr_DataList_erase_t _shsc_ptr_DataList_erase = NULL;
shsc_ptr_DataList_reverse_t _shsc_ptr_DataList_reverse = NULL;
shsc_ptr_DataList_find_t _shsc_ptr_DataList_find = NULL;
shsc_ptr_DataList_sublist_t _shsc_ptr_DataList_sublist = NULL;
shsc_ptr_DataList_join_t _shsc_ptr_DataList_join = NULL;
shsc_ptr_DataList_sort_t _shsc_ptr_DataList_sort = NULL;
shsc_ptr_DataList_getref_errnull_t _shsc_ptr_DataList_getref_errnull = NULL;
shsc_ptr_DataList_getref_t _shsc_ptr_DataList_getref = NULL;
shsc_ptr_DataList_del_index_t _shsc_ptr_DataList_del_index = NULL;
shsc_ptr_DataList_del_val_t _shsc_ptr_DataList_del_val = NULL;
shsc_ptr_DataList_tostr_t _shsc_ptr_DataList_tostr = NULL;
shsc_ptr_DataMap_init_t _shsc_ptr_DataMap_init = NULL;
shsc_ptr_DataMap_clone_t _shsc_ptr_DataMap_clone = NULL;
shsc_ptr_DataMap_length_t _shsc_ptr_DataMap_length = NULL;
shsc_ptr_DataMap_destroy_t _shsc_ptr_DataMap_destroy = NULL;
shsc_ptr_DataMap_insert_t _shsc_ptr_DataMap_insert = NULL;
shsc_ptr_DataMap_del_t _shsc_ptr_DataMap_del = NULL;
shsc_ptr_DataMap_concat_t _shsc_ptr_DataMap_concat = NULL;
shsc_ptr_DataMap_getkey_copy_t _shsc_ptr_DataMap_getkey_copy = NULL;
shsc_ptr_DataMap_getref_errnull_t _shsc_ptr_DataMap_getref_errnull = NULL;
shsc_ptr_DataMap_getref_t _shsc_ptr_DataMap_getref = NULL;
shsc_ptr_DataMap_tostr_t _shsc_ptr_DataMap_tostr = NULL;
shsc_ptr_DataStr_init_t _shsc_ptr_DataStr_init = NULL;
shsc_ptr_DataStr_clone_t _shsc_ptr_DataStr_clone = NULL;
shsc_ptr_DataStr_length_t _shsc_ptr_DataStr_length = NULL;
shsc_ptr_DataStr_destroy_t _shsc_ptr_DataStr_destroy = NULL;
shsc_ptr_DataStr_toupper_t _shsc_ptr_DataStr_toupper = NULL;
shsc_ptr_DataStr_tolower_t _shsc_ptr_DataStr_tolower = NULL;
shsc_ptr_DataStr_append_t _shsc_ptr_DataStr_append = NULL;
shsc_ptr_DataStr_concat_t _shsc_ptr_DataStr_concat = NULL;
shsc_ptr_DataStr_insert_t _shsc_ptr_DataStr_insert = NULL;
shsc_ptr_DataStr_insert_str_t _shsc_ptr_DataStr_insert_str = NULL;
shsc_ptr_DataStr_erase_t _shsc_ptr_DataStr_erase = NULL;
shsc_ptr_DataStr_reverse_t _shsc_ptr_DataStr_reverse = NULL;
shsc_ptr_DataStr_isequal_t _shsc_ptr_DataStr_isequal = NULL;
shsc_ptr_DataStr_compare_t _shsc_ptr_DataStr_compare = NULL;
shsc_ptr_DataStr_find_t _shsc_ptr_DataStr_find = NULL;
shsc_ptr_DataStr_find_str_t _shsc_ptr_DataStr_find_str = NULL;
shsc_ptr_DataStr_substr_t _shsc_ptr_DataStr_substr = NULL;
shsc_ptr_DataStr_split_t _shsc_ptr_DataStr_split = NULL;
shsc_ptr_DataStr_split_str_t _shsc_ptr_DataStr_split_str = NULL;
shsc_ptr_DataStr_sort_t _shsc_ptr_DataStr_sort = NULL;
shsc_ptr_DataStr_toi64_t _shsc_ptr_DataStr_toi64 = NULL;
shsc_ptr_DataStr_tof64_t _shsc_ptr_DataStr_tof64 = NULL;
shsc_ptr_DataStr_getref_errnull_t _shsc_ptr_DataStr_getref_errnull = NULL;
shsc_ptr_DataStr_getref_t _shsc_ptr_DataStr_getref = NULL;
shsc_ptr_DataStr_del_index_t _shsc_ptr_DataStr_del_index = NULL;
shsc_ptr_DataStr_del_char_t _shsc_ptr_DataStr_del_char = NULL;
shsc_ptr_DataStr_tostr_t _shsc_ptr_DataStr_tostr = NULL;
shsc_ptr_fn_get_valid_args_t _shsc_ptr_fn_get_valid_args = NULL;
shsc_ptr_fn_call_handler_t _shsc_ptr_fn_call_handler = NULL;
shsc_ptr_fn_lambda_call_handler_t _shsc_ptr_fn_lambda_call_handler = NULL;
shsc_ptr_op_ampersand_t _shsc_ptr_op_ampersand = NULL;
shsc_ptr_op_arith_rshift_t _shsc_ptr_op_arith_rshift = NULL;
shsc_ptr_op_assign_t _shsc_ptr_op_assign = NULL;
shsc_ptr_op_asterix_t _shsc_ptr_op_asterix = NULL;
shsc_ptr_op_bang_t _shsc_ptr_op_bang = NULL;
shsc_ptr_op_bitwise_lshift_t _shsc_ptr_op_bitwise_lshift = NULL;
shsc_ptr_op_bitwise_rshift_t _shsc_ptr_op_bitwise_rshift = NULL;
shsc_ptr_op_caret_t _shsc_ptr_op_caret = NULL;
shsc_ptr_op_decrement_t _shsc_ptr_op_decrement = NULL;
shsc_ptr_op_dot_t _shsc_ptr_op_dot = NULL;
shsc_ptr_op_exponent_t _shsc_ptr_op_exponent = NULL;
shsc_ptr_op_floor_divide_t _shsc_ptr_op_floor_divide = NULL;
shsc_ptr_op_fslash_t _shsc_ptr_op_fslash = NULL;
shsc_ptr_op_increment_t _shsc_ptr_op_increment = NULL;
shsc_ptr_op_lbrace_angular_t _shsc_ptr_op_lbrace_angular = NULL;
shsc_ptr_op_logical_and_t _shsc_ptr_op_logical_and = NULL;
shsc_ptr_op_logical_equal_t _shsc_ptr_op_logical_equal = NULL;
shsc_ptr_op_logical_greater_equal_t _shsc_ptr_op_logical_greater_equal = NULL;
shsc_ptr_op_logical_lesser_equal_t _shsc_ptr_op_logical_lesser_equal = NULL;
shsc_ptr_op_logical_or_t _shsc_ptr_op_logical_or = NULL;
shsc_ptr_op_logical_unequal_t _shsc_ptr_op_logical_unequal = NULL;
shsc_ptr_op_minus_t _shsc_ptr_op_minus = NULL;
shsc_ptr_op_percent_t _shsc_ptr_op_percent = NULL;
shsc_ptr_op_pipe_t _shsc_ptr_op_pipe = NULL;
shsc_ptr_op_plus_t _shsc_ptr_op_plus = NULL;
shsc_ptr_op_rbrace_angular_t _shsc_ptr_op_rbrace_angular = NULL;
shsc_ptr_op_tilde_t _shsc_ptr_op_tilde = NULL;
shsc_ptr_op_fnargs_indexing_t _shsc_ptr_op_fnargs_indexing = NULL;
shsc_ptr_op_fncall_t _shsc_ptr_op_fncall = NULL;
shsc_ptr_op_indexing_t _shsc_ptr_op_indexing = NULL;
shsc_ptr_op_nop_t _shsc_ptr_op_nop = NULL;
shsc_ptr_op_ternary_cond_t _shsc_ptr_op_ternary_cond = NULL;

#else
    #warning re-inclusion of module 'src/shscfnptr.c.h'
#endif
