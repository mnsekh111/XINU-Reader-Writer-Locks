/*
 * lock.h
 *
 *  Created on: Nov 30, 2015
 *      Author: mns
 */

#ifndef _LOCK_H_
#define _LOCK_H_

#ifndef	NLOCK
#define	NLOCK		50	/* number of locks, if not defined	*/
#endif

/* lock types used in int lock (int ldes1, int type, int priority) */

#define NOTUSING -1
#define READ 1
#define WRITE 0

#define	LFREE	'\01'		/* this lock is free		*/
#define	LUSED	'\02'		/* this lock is used		*/

struct lentry {
	char lstate; /* the state SFREE or SUSED		*/
	int lqhead; /* q index of head of list		*/
	int lqtail; /* q index of tail of list		*/
};

extern	struct	lentry	locks[];
extern  int locktab[][NLOCK];

extern	int	nextlock;

#define	isbadlock(l)	(l<0 || l>=NLOCK)

#endif
