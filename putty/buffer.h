/*	$OpenBSD: buffer.h,v 1.11 2002/03/04 17:27:39 stevesk Exp $	*/

/*
 * Author: Tatu Ylonen <ylo@cs.hut.fi>
 * Copyright (c) 1995 Tatu Ylonen <ylo@cs.hut.fi>, Espoo, Finland
 *                    All rights reserved
 * Code for manipulating FIFO buffers.
 *
 * As far as I am concerned, the code I have written for this software
 * can be used freely for any purpose.  Any derived versions of this
 * software must be clearly marked as such, and if the derived work is
 * incompatible with the protocol description in the RFC file, it must be
 * called by a name other than "ssh" or "Secure Shell".
 */

#ifndef BUFFER_H
#define BUFFER_H

typedef unsigned int  u_int;
typedef unsigned char u_char;

typedef struct {
	u_char	*buf;		/* Buffer for data. */
	u_int	 alloc;		/* Number of bytes allocated for data. */
	u_int	 offset;	/* Offset of first byte containing data. */
	u_int	 end;		/* Offset of last byte containing data. */
}    Buffer;

void	buffer_init(Buffer *);
void	buffer_free(Buffer *);

void	buffer_append(Buffer *, const void *, u_int);
void	*buffer_append_space(Buffer *, u_int);

u_int	buffer_len(Buffer *);
void	*buffer_ptr(Buffer *);

void	buffer_put_int(Buffer *, u_int);

void	buffer_put_char(Buffer *, int);
void	buffer_put_string(Buffer *, const void *, u_int);
void	buffer_put_cstring(Buffer *, const char *);

#endif				/* BUFFER_H */
