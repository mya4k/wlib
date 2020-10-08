#ifndef ASSERT_H
#define ASSERT_H

/* ISO/IEC 9899:2018 7.2:1 */
#ifndef NDEBUG
#define	assert(ignore) ((void)0)
#endif

/* ISO/IEC 9899:2018 7.2:3 */
#define static_assert _Static_assert

/* ISO/IEC 9899:2018 7.2.1.1:2 */
/* The assert macro puts diagnostic tests into programs; it expands to a
 * void expression. When it is executed, if expression (which shall have
 * a scalar type) is false (that is, compares equal to 0), the assert
 * macro writes information about the particular call that failed
 * (including the text of the argument, the name of the source file, the
 * source line number, and the name of the enclosing function — the latter
 * are respectively the values of the preprocessing macros __FILE__ and
 * __LINE__ and of the identifier __func__) on the standard error stream
 * in an implementation-defined format.) It then calls the abort function.
 */

#endif