#ifndef __SHSCPROTOPTR_H__
#define __SHSCPROTOPTR_H__

/**

This header file is used to define function pointer types for the SHSC API that
cannot be replaced with a cleaner function API. There can be multiple reasons
for this.

These functions are to be called directly via the function pointers defined
in this file.

*/

/*----------------------------------
 | FN POINTERS WITHOUT CLEANED API |
 ----------------------------------*/

#define MARK_USED __attribute__((used))
#define FN_MODIFIERS extern

/*------------------------
 |  RUNTIME FUNCTIONS    |
 ------------------------*/

/**
 * Throws a runtime error with the given message.
 * The message can be formatted using printf-style format specifiers.
 */
typedef void (* shsc_ptr_throw_t)(const char *fmt, ...) __attribute__((format(printf, 1, 2)));

#endif
