#ifndef __SHSCINIT_H__
#define __SHSCINIT_H__

#include "shscfnptr.h"

typedef void (* shsc_init_apifn_data_t)(
    shsc_rt_Data_bul_t _rt_Data_bul,
    shsc_rt_Data_chr_t _rt_Data_chr,
    shsc_rt_Data_i64_t _rt_Data_i64,
    shsc_rt_Data_f64_t _rt_Data_f64,
    shsc_rt_Data_str_t _rt_Data_str,
    shsc_rt_Data_list_t _rt_Data_list,
    shsc_rt_Data_map_t _rt_Data_map,
    shsc_rt_Data_any_t _rt_Data_any,
    shsc_rt_Data_null_t _rt_Data_null,
    shsc_rt_Data_clone_t _rt_Data_clone,
    shsc_rt_Data_destroy_t _rt_Data_destroy,
    shsc_rt_Data_isnull_t _rt_Data_isnull,
    shsc_rt_Data_isnumeric_t _rt_Data_isnumeric,
    shsc_rt_Data_isequal_t _rt_Data_isequal,
    shsc_rt_Data_compare_t _rt_Data_compare,
    shsc_rt_Data_tobool_t _rt_Data_tobool,
    shsc_rt_Data_tostr_t _rt_Data_tostr,
    shsc_rt_Data_cast_t _rt_Data_cast,
    shsc_rt_Data_typename_t _rt_Data_typename,
    shsc_rt_Data_assert_type_t _rt_Data_assert_type,
    shsc_rt_Data_greater_type_t _rt_Data_greater_type,
    shsc_rt_Data_print_t _rt_Data_print
);

typedef void (* shsc_init_apifn_vartable_t)(
    shsc_rt_VarTable_modf_t _rt_VarTable_modf
);

typedef void (* shsc_init_apifn_list_t)(
    shsc_rt_DataList_init_t _rt_DataList_init,
    shsc_rt_DataList_clone_t _rt_DataList_clone,
    shsc_rt_DataList_length_t _rt_DataList_length,
    shsc_rt_DataList_destroy_t _rt_DataList_destroy,
    shsc_rt_DataList_isequal_t _rt_DataList_isequal,
    shsc_rt_DataList_compare_t _rt_DataList_compare,
    shsc_rt_DataList_append_t _rt_DataList_append,
    shsc_rt_DataList_concat_t _rt_DataList_concat,
    shsc_rt_DataList_insert_t _rt_DataList_insert,
    shsc_rt_DataList_erase_t _rt_DataList_erase,
    shsc_rt_DataList_reverse_t _rt_DataList_reverse,
    shsc_rt_DataList_find_t _rt_DataList_find,
    shsc_rt_DataList_sublist_t _rt_DataList_sublist,
    shsc_rt_DataList_join_t _rt_DataList_join,
    shsc_rt_DataList_sort_t _rt_DataList_sort,
    shsc_rt_DataList_getref_errnull_t _rt_DataList_getref_errnull,
    shsc_rt_DataList_getref_t _rt_DataList_getref,
    shsc_rt_DataList_del_index_t _rt_DataList_del_index,
    shsc_rt_DataList_del_val_t _rt_DataList_del_val,
    shsc_rt_DataList_tostr_t _rt_DataList_tostr
);

typedef void (* shsc_init_apifn_map_t)(
    shsc_rt_DataMap_init_t _rt_DataMap_init,
    shsc_rt_DataMap_clone_t _rt_DataMap_clone,
    shsc_rt_DataMap_length_t _rt_DataMap_length,
    shsc_rt_DataMap_destroy_t _rt_DataMap_destroy,
    shsc_rt_DataMap_insert_t _rt_DataMap_insert,
    shsc_rt_DataMap_del_t _rt_DataMap_del,
    shsc_rt_DataMap_concat_t _rt_DataMap_concat,
    shsc_rt_DataMap_getkey_copy_t _rt_DataMap_getkey_copy,
    shsc_rt_DataMap_getref_errnull_t _rt_DataMap_getref_errnull,
    shsc_rt_DataMap_getref_t _rt_DataMap_getref,
    shsc_rt_DataMap_tostr_t _rt_DataMap_tostr
);

typedef void (* shsc_init_apifn_str_t)(
    shsc_rt_DataStr_init_t _rt_DataStr_init,
    shsc_rt_DataStr_clone_t _rt_DataStr_clone,
    shsc_rt_DataStr_length_t _rt_DataStr_length,
    shsc_rt_DataStr_destroy_t _rt_DataStr_destroy,
    shsc_rt_DataStr_toupper_t _rt_DataStr_toupper,
    shsc_rt_DataStr_tolower_t _rt_DataStr_tolower,
    shsc_rt_DataStr_append_t _rt_DataStr_append,
    shsc_rt_DataStr_concat_t _rt_DataStr_concat,
    shsc_rt_DataStr_insert_t _rt_DataStr_insert,
    shsc_rt_DataStr_insert_str_t _rt_DataStr_insert_str,
    shsc_rt_DataStr_erase_t _rt_DataStr_erase,
    shsc_rt_DataStr_reverse_t _rt_DataStr_reverse,
    shsc_rt_DataStr_isequal_t _rt_DataStr_isequal,
    shsc_rt_DataStr_compare_t _rt_DataStr_compare,
    shsc_rt_DataStr_find_t _rt_DataStr_find,
    shsc_rt_DataStr_find_str_t _rt_DataStr_find_str,
    shsc_rt_DataStr_substr_t _rt_DataStr_substr,
    shsc_rt_DataStr_split_t _rt_DataStr_split,
    shsc_rt_DataStr_split_str_t _rt_DataStr_split_str,
    shsc_rt_DataStr_sort_t _rt_DataStr_sort,
    shsc_rt_DataStr_toi64_t _rt_DataStr_toi64,
    shsc_rt_DataStr_tof64_t _rt_DataStr_tof64,
    shsc_rt_DataStr_getref_errnull_t _rt_DataStr_getref_errnull,
    shsc_rt_DataStr_getref_t _rt_DataStr_getref,
    shsc_rt_DataStr_del_index_t _rt_DataStr_del_index,
    shsc_rt_DataStr_del_char_t _rt_DataStr_del_char,
    shsc_rt_DataStr_tostr_t _rt_DataStr_tostr
);

typedef void (* shsc_init_apifn_others_t)(
    shsc_rt_throw_t _rt_throw,
    shsc_rt_fn_get_valid_args_t _rt_fn_get_valid_args,
    shsc_rt_fn_call_handler_t _rt_fn_call_handler,
    shsc_rt_fn_lambda_call_handler_t _rt_fn_lambda_call_handler
);

typedef void (* shsc_init_apifn_ops_t)(
    shsc_rt_op_ampersand_t _rt_op_ampersand,
    shsc_rt_op_arith_rshift_t _rt_op_arith_rshift,
    shsc_rt_op_assign_t _rt_op_assign,
    shsc_rt_op_asterix_t _rt_op_asterix,
    shsc_rt_op_bang_t _rt_op_bang,
    shsc_rt_op_bitwise_lshift_t _rt_op_bitwise_lshift,
    shsc_rt_op_bitwise_rshift_t _rt_op_bitwise_rshift,
    shsc_rt_op_caret_t _rt_op_caret,
    shsc_rt_op_decrement_t _rt_op_decrement,
    shsc_rt_op_dot_t _rt_op_dot,
    shsc_rt_op_exponent_t _rt_op_exponent,
    shsc_rt_op_floor_divide_t _rt_op_floor_divide,
    shsc_rt_op_fslash_t _rt_op_fslash,
    shsc_rt_op_increment_t _rt_op_increment,
    shsc_rt_op_lbrace_angular_t _rt_op_lbrace_angular,
    shsc_rt_op_logical_and_t _rt_op_logical_and,
    shsc_rt_op_logical_equal_t _rt_op_logical_equal,
    shsc_rt_op_logical_greater_equal_t _rt_op_logical_greater_equal,
    shsc_rt_op_logical_lesser_equal_t _rt_op_logical_lesser_equal,
    shsc_rt_op_logical_or_t _rt_op_logical_or,
    shsc_rt_op_logical_unequal_t _rt_op_logical_unequal,
    shsc_rt_op_minus_t _rt_op_minus,
    shsc_rt_op_percent_t _rt_op_percent,
    shsc_rt_op_pipe_t _rt_op_pipe,
    shsc_rt_op_plus_t _rt_op_plus,
    shsc_rt_op_rbrace_angular_t _rt_op_rbrace_angular,
    shsc_rt_op_tilde_t _rt_op_tilde,
    shsc_rt_op_fnargs_indexing_t _rt_op_fnargs_indexing,
    shsc_rt_op_fncall_t _rt_op_fncall,
    shsc_rt_op_indexing_t _rt_op_indexing,
    shsc_rt_op_nop_t _rt_op_nop,
    shsc_rt_op_ternary_cond_t _rt_op_ternary_cond
);

FN_MODIFIERS shsc_init_apifn_data_t shsc_init_apifn_data;
FN_MODIFIERS shsc_init_apifn_vartable_t shsc_init_apifn_vartable;
FN_MODIFIERS shsc_init_apifn_list_t shsc_init_apifn_list;
FN_MODIFIERS shsc_init_apifn_map_t shsc_init_apifn_map;
FN_MODIFIERS shsc_init_apifn_str_t shsc_init_apifn_str;
FN_MODIFIERS shsc_init_apifn_others_t shsc_init_apifn_others;
FN_MODIFIERS shsc_init_apifn_ops_t shsc_init_apifn_ops;

#endif
