#ifndef WC_IO_H
#define WC_IO_H

#define RD_FLAG	0		/* Read only flag */
#define WR_FLAG	1		/* Write only flag */
#define RW_FLAG	2		/* Read-Write flag */
#define WR_FLAG	RW_FLAG	/* Read-Write flag */
#define cl close		/* Closes file */
#define op open			/* Opens file */
#define rd read			/* Reads from file */
#define wr write		/* Write into file */

typedef long int ssize_t;

/* System calls */
extern int		close	(int fd);
extern int		open	(const char *pathname, int flags);
extern ssize_t	read	(int fd, void *buf, size_t count);
extern ssize_t	write	(int fd, const void *buf, size_t count);

#endif