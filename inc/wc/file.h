/****************************
 * File management library	*
 * Wispy (c) 2021			*
 ****************************/

#ifndef WC_FILE
#define WC_FILE

#include <wc/sys/osys.h>

/* If Linux system calls are avaliable and allowed, rely on them */
#if defined(OS_LINUX) && !defined(NO_LINUX)
#	include <fcntl.h>
#	include <sys/types.h>
#	include <sys/stat.h>
#	include <unistd.h>

/*	Create a file
 *	path -- path/name of the file
 */
#	define cr(path)				creat(path, O_CREAT)
#	define fC					cr
/* Delete a file */
#	define dl(path)				unlink(path)
#	define fd					dl
/* Open a file */
#	define op(path, flags)		open(path, flags)
#	define fo					op
/* Close a file */
#	define cl(file)				close(file)
#	define fc					cl
/* Read a file */
#	define rd(file, buf, size)	read(file, buf, size)
#	define fr					rd
/* Write a file */
#	define wr(file, buf, size)	write(file, buf, size)
#	define fw					wr
/* Execute a file */
#	define ex(file, args)		execve(file, args, 0)
#	define fx					ex
#else
#	error Not Implimented Yet
#endif

#endif