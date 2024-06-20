#ifndef __SHSC_TYPES_H__
#define __SHSC_TYPES_H__

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

#endif
