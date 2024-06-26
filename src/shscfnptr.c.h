#ifndef __SHSC_FNPTR_C_H__
#define __SHSC_FNPTR_C_H__

#include <stdio.h>
#include "shscfnptr.h"

shsc_rt_Data_bul_t shsc_rt_Data_bul = NULL;
shsc_rt_Data_chr_t shsc_rt_Data_chr = NULL;
shsc_rt_Data_i64_t shsc_rt_Data_i64 = NULL;
shsc_rt_Data_f64_t shsc_rt_Data_f64 = NULL;
shsc_rt_Data_str_t shsc_rt_Data_str = NULL;
shsc_rt_Data_list_t shsc_rt_Data_list = NULL;
shsc_rt_Data_map_t shsc_rt_Data_map = NULL;
shsc_rt_Data_any_t shsc_rt_Data_any = NULL;
shsc_rt_Data_null_t shsc_rt_Data_null = NULL;
shsc_rt_Data_clone_t shsc_rt_Data_clone = NULL;
shsc_rt_Data_destroy_t shsc_rt_Data_destroy = NULL;
shsc_rt_Data_isnull_t shsc_rt_Data_isnull = NULL;
shsc_rt_Data_isnumeric_t shsc_rt_Data_isnumeric = NULL;
shsc_rt_Data_isequal_t shsc_rt_Data_isequal = NULL;
shsc_rt_Data_compare_t shsc_rt_Data_compare = NULL;
shsc_rt_Data_tobool_t shsc_rt_Data_tobool = NULL;
shsc_rt_Data_tostr_t shsc_rt_Data_tostr = NULL;
shsc_rt_Data_cast_t shsc_rt_Data_cast = NULL;
shsc_rt_Data_typename_t shsc_rt_Data_typename = NULL;
shsc_rt_Data_assert_type_t shsc_rt_Data_assert_type = NULL;
shsc_rt_Data_greater_type_t shsc_rt_Data_greater_type = NULL;
shsc_rt_Data_print_t shsc_rt_Data_print = NULL;
shsc_rt_VarTable_modf_t shsc_rt_VarTable_modf = NULL;
shsc_rt_DataList_init_t shsc_rt_DataList_init = NULL;
shsc_rt_DataList_clone_t shsc_rt_DataList_clone = NULL;
shsc_rt_DataList_length_t shsc_rt_DataList_length = NULL;
shsc_rt_DataList_destroy_t shsc_rt_DataList_destroy = NULL;
shsc_rt_DataList_isequal_t shsc_rt_DataList_isequal = NULL;
shsc_rt_DataList_compare_t shsc_rt_DataList_compare = NULL;
shsc_rt_DataList_append_t shsc_rt_DataList_append = NULL;
shsc_rt_DataList_concat_t shsc_rt_DataList_concat = NULL;
shsc_rt_DataList_insert_t shsc_rt_DataList_insert = NULL;
shsc_rt_DataList_erase_t shsc_rt_DataList_erase = NULL;
shsc_rt_DataList_reverse_t shsc_rt_DataList_reverse = NULL;
shsc_rt_DataList_find_t shsc_rt_DataList_find = NULL;
shsc_rt_DataList_sublist_t shsc_rt_DataList_sublist = NULL;
shsc_rt_DataList_join_t shsc_rt_DataList_join = NULL;
shsc_rt_DataList_sort_t shsc_rt_DataList_sort = NULL;
shsc_rt_DataList_getref_errnull_t shsc_rt_DataList_getref_errnull = NULL;
shsc_rt_DataList_getref_t shsc_rt_DataList_getref = NULL;
shsc_rt_DataList_del_index_t shsc_rt_DataList_del_index = NULL;
shsc_rt_DataList_del_val_t shsc_rt_DataList_del_val = NULL;
shsc_rt_DataList_tostr_t shsc_rt_DataList_tostr = NULL;
shsc_rt_DataMap_init_t shsc_rt_DataMap_init = NULL;
shsc_rt_DataMap_clone_t shsc_rt_DataMap_clone = NULL;
shsc_rt_DataMap_length_t shsc_rt_DataMap_length = NULL;
shsc_rt_DataMap_destroy_t shsc_rt_DataMap_destroy = NULL;
shsc_rt_DataMap_insert_t shsc_rt_DataMap_insert = NULL;
shsc_rt_DataMap_del_t shsc_rt_DataMap_del = NULL;
shsc_rt_DataMap_concat_t shsc_rt_DataMap_concat = NULL;
shsc_rt_DataMap_getkey_copy_t shsc_rt_DataMap_getkey_copy = NULL;
shsc_rt_DataMap_getref_errnull_t shsc_rt_DataMap_getref_errnull = NULL;
shsc_rt_DataMap_getref_t shsc_rt_DataMap_getref = NULL;
shsc_rt_DataMap_tostr_t shsc_rt_DataMap_tostr = NULL;
shsc_rt_DataStr_init_t shsc_rt_DataStr_init = NULL;
shsc_rt_DataStr_clone_t shsc_rt_DataStr_clone = NULL;
shsc_rt_DataStr_length_t shsc_rt_DataStr_length = NULL;
shsc_rt_DataStr_destroy_t shsc_rt_DataStr_destroy = NULL;
shsc_rt_DataStr_toupper_t shsc_rt_DataStr_toupper = NULL;
shsc_rt_DataStr_tolower_t shsc_rt_DataStr_tolower = NULL;
shsc_rt_DataStr_append_t shsc_rt_DataStr_append = NULL;
shsc_rt_DataStr_concat_t shsc_rt_DataStr_concat = NULL;
shsc_rt_DataStr_insert_t shsc_rt_DataStr_insert = NULL;
shsc_rt_DataStr_insert_str_t shsc_rt_DataStr_insert_str = NULL;
shsc_rt_DataStr_erase_t shsc_rt_DataStr_erase = NULL;
shsc_rt_DataStr_reverse_t shsc_rt_DataStr_reverse = NULL;
shsc_rt_DataStr_isequal_t shsc_rt_DataStr_isequal = NULL;
shsc_rt_DataStr_compare_t shsc_rt_DataStr_compare = NULL;
shsc_rt_DataStr_find_t shsc_rt_DataStr_find = NULL;
shsc_rt_DataStr_find_str_t shsc_rt_DataStr_find_str = NULL;
shsc_rt_DataStr_substr_t shsc_rt_DataStr_substr = NULL;
shsc_rt_DataStr_split_t shsc_rt_DataStr_split = NULL;
shsc_rt_DataStr_split_str_t shsc_rt_DataStr_split_str = NULL;
shsc_rt_DataStr_sort_t shsc_rt_DataStr_sort = NULL;
shsc_rt_DataStr_toi64_t shsc_rt_DataStr_toi64 = NULL;
shsc_rt_DataStr_tof64_t shsc_rt_DataStr_tof64 = NULL;
shsc_rt_DataStr_getref_errnull_t shsc_rt_DataStr_getref_errnull = NULL;
shsc_rt_DataStr_getref_t shsc_rt_DataStr_getref = NULL;
shsc_rt_DataStr_del_index_t shsc_rt_DataStr_del_index = NULL;
shsc_rt_DataStr_del_char_t shsc_rt_DataStr_del_char = NULL;
shsc_rt_DataStr_tostr_t shsc_rt_DataStr_tostr = NULL;
shsc_rt_throw_t shsc_rt_throw = NULL;
shsc_rt_fn_get_valid_args_t shsc_rt_fn_get_valid_args = NULL;
shsc_rt_fn_call_handler_t shsc_rt_fn_call_handler = NULL;
shsc_rt_fn_lambda_call_handler_t shsc_rt_fn_lambda_call_handler = NULL;
shsc_rt_op_ampersand_t shsc_rt_op_ampersand = NULL;
shsc_rt_op_arith_rshift_t shsc_rt_op_arith_rshift = NULL;
shsc_rt_op_assign_t shsc_rt_op_assign = NULL;
shsc_rt_op_asterix_t shsc_rt_op_asterix = NULL;
shsc_rt_op_bang_t shsc_rt_op_bang = NULL;
shsc_rt_op_bitwise_lshift_t shsc_rt_op_bitwise_lshift = NULL;
shsc_rt_op_bitwise_rshift_t shsc_rt_op_bitwise_rshift = NULL;
shsc_rt_op_caret_t shsc_rt_op_caret = NULL;
shsc_rt_op_decrement_t shsc_rt_op_decrement = NULL;
shsc_rt_op_dot_t shsc_rt_op_dot = NULL;
shsc_rt_op_exponent_t shsc_rt_op_exponent = NULL;
shsc_rt_op_floor_divide_t shsc_rt_op_floor_divide = NULL;
shsc_rt_op_fslash_t shsc_rt_op_fslash = NULL;
shsc_rt_op_increment_t shsc_rt_op_increment = NULL;
shsc_rt_op_lbrace_angular_t shsc_rt_op_lbrace_angular = NULL;
shsc_rt_op_logical_and_t shsc_rt_op_logical_and = NULL;
shsc_rt_op_logical_equal_t shsc_rt_op_logical_equal = NULL;
shsc_rt_op_logical_greater_equal_t shsc_rt_op_logical_greater_equal = NULL;
shsc_rt_op_logical_lesser_equal_t shsc_rt_op_logical_lesser_equal = NULL;
shsc_rt_op_logical_or_t shsc_rt_op_logical_or = NULL;
shsc_rt_op_logical_unequal_t shsc_rt_op_logical_unequal = NULL;
shsc_rt_op_minus_t shsc_rt_op_minus = NULL;
shsc_rt_op_percent_t shsc_rt_op_percent = NULL;
shsc_rt_op_pipe_t shsc_rt_op_pipe = NULL;
shsc_rt_op_plus_t shsc_rt_op_plus = NULL;
shsc_rt_op_rbrace_angular_t shsc_rt_op_rbrace_angular = NULL;
shsc_rt_op_tilde_t shsc_rt_op_tilde = NULL;
shsc_rt_op_fnargs_indexing_t shsc_rt_op_fnargs_indexing = NULL;
shsc_rt_op_fncall_t shsc_rt_op_fncall = NULL;
shsc_rt_op_indexing_t shsc_rt_op_indexing = NULL;
shsc_rt_op_nop_t shsc_rt_op_nop = NULL;
shsc_rt_op_ternary_cond_t shsc_rt_op_ternary_cond = NULL;

#else
    #warning re-inclusion of module 'src/shscfnptr.c.h'
#endif
