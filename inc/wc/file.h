/****************************
 * File management library	*
 * Wispy (c) 2021			*
 ****************************/

#ifndef WC_FILE
#define WC_FILE

#include <wc/types.h>
#include <sys/osys.h>

/* If Linux system calls are avaliable and allowed, rely on them */
#if defined(OS_LINUX) && !defined(NO_LINUX)
#	include <fcntl.h>
#	include <sys/types.h>
#	include <sys/stat.h>
#	include <unistd.h>

/* Create a file */
#	define cr(path)				creat(path, O_CREAT)
/* Delete a file */
#	define dl(path)				unlink(path)
/* Open a file */
#	define op(path, flags)		open(path, flag)
/* Close a file */
#	define cl(file)				close(file, flags)
/* Read a file */
#	define rd(file, buf, size)	read(file, buf, size)
/* Write a file */
#	define wr(file, buf, size)	write(file, buf, size)
/* Execute a file */
#	define ex(file, args)		execve(file, args)
#else
#	error Not Implimented Yet
#endif

#endif