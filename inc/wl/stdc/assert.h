#ifndef ASSERT_H
#define ASSERT_H

/* ISO/IEC 9899:2018 7.2:1 */
#ifndef NDEBUG
#define	assert(ignore) ((void)0)
#endif

/* ISO/IEC 9899:2018 7.2:3 */
#define static_assert _Static_assert

#endif