#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "tests.h"
#include "../clist.h"

struct myitem {
	struct clist_item_head list;
	int n;
};


void
init(void)
{
}

void
pretest(int idx)
{
}

void
posttest(int idx)
{
}

void
deinit(void)
{
}

int
test0_0(void)
{
	struct clist_item_head lh;

	lh.prev = NULL;
	lh.next = NULL;
	clist_item_head_init(&lh);
	if (lh.prev != &lh)
		TERR("lh.prev is not &lh: %p", lh.prev);
	if (lh.next != &lh)
		TERR("lh.next is not &lh: %p", lh.next);

	return 1;
}

int
test0_1(void)
{
	struct myitem myi1;

	myi1.n = 113;
	myi1.list.prev = (void*)0x17;
	myi1.list.next = (void*)0x18;
	clist_item_head_init(&myi1.list);
	if (myi1.list.prev != &myi1.list)
		TERR("myi1.list.prev is not &myi1.list: %p", myi1.list.prev);
	if (myi1.list.next != &myi1.list)
		TERR("myi1.list.next is not &myi1.list: %p", myi1.list.next);
	if (myi1.n != 113)
		TERR("myi1.n is not 113: %p", myi1.n);

	return 1;
}

int
test1_0(void)
{
	struct clist_item_head lh1, lh2;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	_clist_add(&lh2, &lh1, &lh1);
	if (lh1.prev != &lh2)
		TERR("lh1.prev is not &lh2: %p", lh1.prev);
	if (lh1.next != &lh2)
		TERR("lh1.next is not &lh2: %p", lh1.next);
	if (lh2.prev != &lh1)
		TERR("lh2.prev is not &lh1: %p", lh2.prev);
	if (lh2.next != &lh1)
		TERR("lh2.next is not &lh1: %p", lh2.next);

	return 1;
}

int
test1_1(void)
{
	struct clist_item_head lh1, lh2, lh3;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	_clist_add(&lh3, &lh1, &lh1);
	_clist_add(&lh2, &lh1, &lh3);
	if (lh1.prev != &lh3)
		TERR("lh1.prev is not &lh3: %p", lh1.prev);
	if (lh1.next != &lh2)
		TERR("lh1.next is not &lh2: %p", lh1.next);
	if (lh2.prev != &lh1)
		TERR("lh2.prev is not &lh1: %p", lh2.prev);
	if (lh2.next != &lh3)
		TERR("lh2.next is not &lh3: %p", lh2.next);
	if (lh3.prev != &lh2)
		TERR("lh3.prev is not &lh2: %p", lh3.prev);
	if (lh3.next != &lh1)
		TERR("lh3.next is not &lh1: %p", lh3.next);

	return 1;
}

int
test1_2(void)
{
	struct clist_item_head lh1, lh2, lh3;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	_clist_add(&lh2, &lh1, &lh1);
	_clist_add(&lh3, &lh2, &lh1);
	if (lh1.prev != &lh3)
		TERR("lh1.prev is not &lh3: %p", lh1.prev);
	if (lh1.next != &lh2)
		TERR("lh1.next is not &lh2: %p", lh1.next);
	if (lh2.prev != &lh1)
		TERR("lh2.prev is not &lh1: %p", lh2.prev);
	if (lh2.next != &lh3)
		TERR("lh2.next is not &lh3: %p", lh2.next);
	if (lh3.prev != &lh2)
		TERR("lh3.prev is not &lh2: %p", lh3.prev);
	if (lh3.next != &lh1)
		TERR("lh3.next is not &lh1: %p", lh3.next);

	return 1;
}

int
test2_0(void)
{
	struct clist_item_head lh1, lh2, lh3;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	if (lh1.prev != &lh2)
		TERR("lh1.prev is not &lh2: %p", lh1.prev);
	if (lh1.next != &lh2)
		TERR("lh1.next is not &lh2: %p", lh1.next);
	if (lh2.prev != &lh1)
		TERR("lh2.prev is not &lh1: %p", lh2.prev);
	if (lh2.next != &lh1)
		TERR("lh2.next is not &lh1: %p", lh2.next);
	clist_add(&lh3, &lh2);
	if (lh1.prev != &lh3)
		TERR("lh1.prev is not &lh3: %p", lh1.prev);
	if (lh1.next != &lh2)
		TERR("lh1.next is not &lh2: %p", lh1.next);
	if (lh2.prev != &lh1)
		TERR("lh2.prev is not &lh1: %p", lh2.prev);
	if (lh2.next != &lh3)
		TERR("lh2.next is not &lh3: %p", lh2.next);
	if (lh3.prev != &lh2)
		TERR("lh3.prev is not &lh2: %p", lh3.prev);
	if (lh3.next != &lh1)
		TERR("lh3.next is not &lh1: %p", lh3.next);

	return 1;
}

int
test2_1(void)
{
	struct clist_item_head lh1, lh2, lh3;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	if (lh1.prev != &lh2)
		TERR("lh1.prev is not &lh2: %p", lh1.prev);
	if (lh1.next != &lh2)
		TERR("lh1.next is not &lh2: %p", lh1.next);
	if (lh2.prev != &lh1)
		TERR("lh2.prev is not &lh1: %p", lh2.prev);
	if (lh2.next != &lh1)
		TERR("lh2.next is not &lh1: %p", lh2.next);
	clist_add(&lh3, &lh1);
	if (lh1.prev != &lh2)
		TERR("lh1.prev is not &lh2: %p", lh1.prev);
	if (lh1.next != &lh3)
		TERR("lh1.next is not &lh3: %p", lh1.next);
	if (lh2.prev != &lh3)
		TERR("lh2.prev is not &lh3: %p", lh2.prev);
	if (lh2.next != &lh1)
		TERR("lh2.next is not &lh1: %p", lh2.next);
	if (lh3.prev != &lh1)
		TERR("lh3.prev is not &lh1: %p", lh3.prev);
	if (lh3.next != &lh2)
		TERR("lh3.next is not &lh2: %p", lh3.next);

	return 1;
}

int
test3_0(void)
{
	struct clist_item_head lh1, lh2, lh3;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add_before(&lh2, &lh1);
	if (lh1.prev != &lh2)
		TERR("lh1.prev is not &lh2: %p", lh1.prev);
	if (lh1.next != &lh2)
		TERR("lh1.next is not &lh2: %p", lh1.next);
	if (lh2.prev != &lh1)
		TERR("lh2.prev is not &lh1: %p", lh2.prev);
	if (lh2.next != &lh1)
		TERR("lh2.next is not &lh1: %p", lh2.next);
	clist_add_before(&lh3, &lh2);
	if (lh1.prev != &lh2)
		TERR("lh1.prev is not &lh2: %p", lh1.prev);
	if (lh1.next != &lh3)
		TERR("lh1.next is not &lh3: %p", lh1.next);
	if (lh2.prev != &lh3)
		TERR("lh2.prev is not &lh3: %p", lh2.prev);
	if (lh2.next != &lh1)
		TERR("lh2.next is not &lh1: %p", lh2.next);
	if (lh3.prev != &lh1)
		TERR("lh3.prev is not &lh1: %p", lh3.prev);
	if (lh3.next != &lh2)
		TERR("lh3.next is not &lh2: %p", lh3.next);

	return 1;
}

int
test3_1(void)
{
	struct clist_item_head lh1, lh2, lh3;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add_before(&lh2, &lh1);
	if (lh1.prev != &lh2)
		TERR("lh1.prev is not &lh2: %p", lh1.prev);
	if (lh1.next != &lh2)
		TERR("lh1.next is not &lh2: %p", lh1.next);
	if (lh2.prev != &lh1)
		TERR("lh2.prev is not &lh1: %p", lh2.prev);
	if (lh2.next != &lh1)
		TERR("lh2.next is not &lh1: %p", lh2.next);
	clist_add_before(&lh3, &lh1);
	if (lh1.prev != &lh3)
		TERR("lh1.prev is not &lh3: %p", lh1.prev);
	if (lh1.next != &lh2)
		TERR("lh1.next is not &lh2: %p", lh1.next);
	if (lh2.prev != &lh1)
		TERR("lh2.prev is not &lh1: %p", lh2.prev);
	if (lh2.next != &lh3)
		TERR("lh2.next is not &lh3: %p", lh2.next);
	if (lh3.prev != &lh2)
		TERR("lh3.prev is not &lh2: %p", lh3.prev);
	if (lh3.next != &lh1)
		TERR("lh3.next is not &lh1: %p", lh3.next);

	return 1;
}

int
test8_0(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head lh;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_replace(&lh1, &lh);
	if (lh.prev != &lh3)
		TERR("lh.prev is not &lh: %p", lh1.prev);
	if (lh.next != &lh2)
		TERR("lh.next is not &lh2: %p", lh1.next);
	if (lh2.prev != &lh)
		TERR("lh2.prev is not &lh: %p", lh2.prev);
	if (lh2.next != &lh3)
		TERR("lh2.next is not &lh3: %p", lh2.next);
	if (lh3.prev != &lh2)
		TERR("lh3.prev is not &lh2: %p", lh3.prev);
	if (lh3.next != &lh)
		TERR("lh3.next is not NULL: %p", lh3.next);

	return 1;
}

int
test8_1(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head lh;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_replace(&lh2, &lh);
	if (lh1.prev != &lh3)
		TERR("lh1.prev is not &lh: %p", lh1.prev);
	if (lh1.next != &lh)
		TERR("lh1.next is not &lh: %p", lh1.next);
	if (lh.prev != &lh1)
		TERR("lh.prev is not &lh1: %p", lh.prev);
	if (lh.next != &lh3)
		TERR("lh.next is not &lh3: %p", lh.next);
	if (lh3.prev != &lh)
		TERR("lh3.prev is not &lh: %p", lh3.prev);
	if (lh3.next != &lh1)
		TERR("lh3.next is not NULL: %p", lh3.next);

	return 1;
}

int
test8_2(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head lh;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_replace(&lh3, &lh);
	if (lh1.prev != &lh)
		TERR("lh1.prev is not &lh: %p", lh1.prev);
	if (lh1.next != &lh2)
		TERR("lh1.next is not &lh2: %p", lh1.next);
	if (lh2.prev != &lh1)
		TERR("lh2.prev is not &lh1: %p", lh.prev);
	if (lh2.next != &lh)
		TERR("lh2.next is not &lh3: %p", lh.next);
	if (lh.prev != &lh2)
		TERR("lh3.prev is not &lh2: %p", lh3.prev);
	if (lh.next != &lh1)
		TERR("lh3.next is not NULL: %p", lh3.next);

	return 1;
}

int
test9_0(void)
{
	struct clist_item_head lh1, lh2, lh3;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_rm(&lh1);
	if (lh2.prev != &lh3)
		TERR("lh2.prev is not NULL: %p", lh2.prev);
	if (lh2.next != &lh3)
		TERR("lh2.next is not &lh3: %p", lh2.next);
	if (lh3.prev != &lh2)
		TERR("lh3.prev is not &lh2: %p", lh3.prev);
	if (lh3.next != &lh2)
		TERR("lh3.next is not NULL: %p", lh3.next);

	return 1;
}

int
test9_1(void)
{
	struct clist_item_head lh1, lh2, lh3;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_rm(&lh2);
	if (lh1.prev != &lh3)
		TERR("lh1.prev is not NULL: %p", lh1.prev);
	if (lh1.next != &lh3)
		TERR("lh1.next is not &lh3: %p", lh1.next);
	if (lh3.prev != &lh1)
		TERR("lh3.prev is not &lh1: %p", lh3.prev);
	if (lh3.next != &lh1)
		TERR("lh3.next is not NULL: %p", lh3.next);

	return 1;
}

int
test9_2(void)
{
	struct clist_item_head lh1, lh2, lh3;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_rm(&lh3);
	if (lh1.prev != &lh2)
		TERR("lh1.prev is not NULL: %p", lh1.prev);
	if (lh1.next != &lh2)
		TERR("lh1.next is not &lh2: %p", lh1.next);
	if (lh2.prev != &lh1)
		TERR("lh2.prev is not &lh1: %p", lh2.prev);
	if (lh2.next != &lh1)
		TERR("lh2.next is not NULL: %p", lh2.next);

	return 1;
}

int
test10_0(void)
{
	struct clist_item_head lh1, lh2, lh3;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_swap(&lh1, &lh2);
	if (lh1.prev != &lh2)
		TERR("lh1.prev is not &lh2: %p", lh1.prev);
	if (lh1.next != &lh3)
		TERR("lh1.next is not &lh3: %p", lh1.next);
	if (lh2.prev != &lh3)
		TERR("lh2.prev is not NULL: %p", lh2.prev);
	if (lh2.next != &lh1)
		TERR("lh2.next is not &lh1: %p", lh2.next);
	if (lh3.prev != &lh1)
		TERR("lh3.prev is not &lh1: %p", lh3.prev);
	if (lh3.next != &lh2)
		TERR("lh3.next is not NULL: %p", lh3.next);

	return 1;
}

int
test10_1(void)
{
	struct clist_item_head lh1, lh2, lh3;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_swap(&lh1, &lh3);
	if (lh1.prev != &lh2)
		TERR("lh1.prev is not &lh2: %p", lh1.prev);
	if (lh1.next != &lh3)
		TERR("lh1.next is not NULL: %p", lh1.next);
	if (lh2.prev != &lh3)
		TERR("lh2.prev is not &lh3: %p", lh2.prev);
	if (lh2.next != &lh1)
		TERR("lh2.next is not &lh1: %p", lh2.next);
	if (lh3.prev != &lh1)
		TERR("lh3.prev is not NULL: %p", lh3.prev);
	if (lh3.next != &lh2)
		TERR("lh3.next is not &lh2: %p", lh3.next);

	return 1;
}

int
test10_2(void)
{
	struct clist_item_head lh1, lh2, lh3;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_swap(&lh2, &lh1);
	if (lh1.prev != &lh2)
		TERR("lh1.prev is not &lh2: %p", lh1.prev);
	if (lh1.next != &lh3)
		TERR("lh1.next is not &lh3: %p", lh1.next);
	if (lh2.prev != &lh3)
		TERR("lh2.prev is not NULL: %p", lh2.prev);
	if (lh2.next != &lh1)
		TERR("lh2.next is not &lh1: %p", lh2.next);
	if (lh3.prev != &lh1)
		TERR("lh3.prev is not &lh1: %p", lh3.prev);
	if (lh3.next != &lh2)
		TERR("lh3.next is not NULL: %p", lh3.next);

	return 1;
}

int
test10_3(void)
{
	struct clist_item_head lh1, lh2, lh3;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_swap(&lh2, &lh2);
	if (lh1.prev != &lh3)
		TERR("lh1.prev is not NULL: %p", lh1.prev);
	if (lh1.next != &lh2)
		TERR("lh1.next is not &lh2: %p", lh1.next);
	if (lh2.prev != &lh1)
		TERR("lh2.prev is not &lh1: %p", lh2.prev);
	if (lh2.next != &lh3)
		TERR("lh2.next is not &lh3: %p", lh2.next);
	if (lh3.prev != &lh2)
		TERR("lh3.prev is not &lh2: %p", lh3.prev);
	if (lh3.next != &lh1)
		TERR("lh3.next is not NULL: %p", lh3.next);

	return 1;
}

int
test10_4(void)
{
	struct clist_item_head lh1, lh2, lh3;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_swap(&lh2, &lh3);
	if (lh1.prev != &lh2)
		TERR("lh1.prev is not NULL: %p", lh1.prev);
	if (lh1.next != &lh3)
		TERR("lh1.next is not &lh3: %p", lh1.next);
	if (lh2.prev != &lh3)
		TERR("lh2.prev is not &lh3: %p", lh2.prev);
	if (lh2.next != &lh1)
		TERR("lh2.next is not NULL: %p", lh2.next);
	if (lh3.prev != &lh1)
		TERR("lh3.prev is not &lh1: %p", lh3.prev);
	if (lh3.next != &lh2)
		TERR("lh3.next is not &lh2: %p", lh3.next);

	return 1;
}

int
test11_0(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head *lh;
	int i = 0;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_for_each(lh, &lh1) {
		switch (i) {
		case 0:
			if (lh != &lh1)
				TERR("lh is not &lh1: %p", lh);
			if (lh->prev != &lh3)
				TERR("lh->prev is not NULL: %p", lh);
			if (lh->next != &lh2)
				TERR("lh->next is not &lh2: %p", lh);
			break;
		case 1:
			if (lh != &lh2)
				TERR("lh is not &lh2: %p", lh);
			if (lh->prev != &lh1)
				TERR("lh->prev is not &lh1: %p", lh);
			if (lh->next != &lh3)
				TERR("lh->next is not &lh3: %p", lh);
			break;
		case 2:
			if (lh != &lh3)
				TERR("lh is not &lh3: %p", lh);
			if (lh->prev != &lh2)
				TERR("lh->prev is not &lh2: %p", lh);
			if (lh->next != &lh1)
				TERR("lh->next is not NULL: %p", lh);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		i++;
	}

	return 1;
}

int
test11_1(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head *lh;
	int i = 0;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_for_each(lh, &lh2) {
		switch (i) {
		case 0:
			if (lh != &lh2)
				TERR("lh is not &lh2: %p", lh);
			if (lh->prev != &lh1)
				TERR("lh->prev is not &lh1: %p", lh);
			if (lh->next != &lh3)
				TERR("lh->next is not &lh3: %p", lh);
			break;
		case 1:
			if (lh != &lh3)
				TERR("lh is not &lh3: %p", lh);
			if (lh->prev != &lh2)
				TERR("lh->prev is not &lh2: %p", lh);
			if (lh->next != &lh1)
				TERR("lh->next is not NULL: %p", lh);
			break;
		case 2:
			if (lh != &lh1)
				TERR("lh is not &lh1: %p", lh);
			if (lh->prev != &lh3)
				TERR("lh->prev is not NULL: %p", lh);
			if (lh->next != &lh2)
				TERR("lh->next is not &lh2: %p", lh);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		i++;
	}

	return 1;
}

int
test11_2(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head *lh;
	int i = 0;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_for_each(lh, &lh3) {
		switch (i) {
		case 0:
			if (lh != &lh3)
				TERR("lh is not &lh3: %p", lh);
			if (lh->prev != &lh2)
				TERR("lh->prev is not &lh2: %p", lh);
			if (lh->next != &lh1)
				TERR("lh->next is not NULL: %p", lh);
			break;
		case 1:
			if (lh != &lh1)
				TERR("lh is not &lh1: %p", lh);
			if (lh->prev != &lh3)
				TERR("lh->prev is not NULL: %p", lh);
			if (lh->next != &lh2)
				TERR("lh->next is not &lh2: %p", lh);
			break;
		case 2:
			if (lh != &lh2)
				TERR("lh is not &lh2: %p", lh);
			if (lh->prev != &lh1)
				TERR("lh->prev is not &lh1: %p", lh);
			if (lh->next != &lh3)
				TERR("lh->next is not &lh3: %p", lh);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		i++;
	}

	return 1;
}

int
test12_0(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head *lh;
	int i = 0;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_for_each_reverse(lh, &lh3) {
		switch (i) {
		case 0:
			if (lh != &lh3)
				TERR("lh is not &lh3: %p", lh);
			if (lh->prev != &lh2)
				TERR("lh->prev is not &lh2: %p", lh);
			if (lh->next != &lh1)
				TERR("lh->next is not NULL: %p", lh);
			break;
		case 1:
			if (lh != &lh2)
				TERR("lh is not &lh2: %p", lh);
			if (lh->prev != &lh1)
				TERR("lh->prev is not &lh1: %p", lh);
			if (lh->next != &lh3)
				TERR("lh->next is not &lh3: %p", lh);
			break;
		case 2:
			if (lh != &lh1)
				TERR("lh is not &lh1: %p", lh);
			if (lh->prev != &lh3)
				TERR("lh->prev is not NULL: %p", lh);
			if (lh->next != &lh2)
				TERR("lh->next is not &lh2: %p", lh);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		i++;
	}

	return 1;
}

int
test12_1(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head *lh;
	int i = 0;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_for_each_reverse(lh, &lh2) {
		switch (i) {
		case 0:
			if (lh != &lh2)
				TERR("lh is not &lh2: %p", lh);
			if (lh->prev != &lh1)
				TERR("lh->prev is not &lh1: %p", lh);
			if (lh->next != &lh3)
				TERR("lh->next is not &lh3: %p", lh);
			break;
		case 1:
			if (lh != &lh1)
				TERR("lh is not &lh1: %p", lh);
			if (lh->prev != &lh3)
				TERR("lh->prev is not NULL: %p", lh);
			if (lh->next != &lh2)
				TERR("lh->next is not &lh2: %p", lh);
			break;
		case 2:
			if (lh != &lh3)
				TERR("lh is not &lh3: %p", lh);
			if (lh->prev != &lh2)
				TERR("lh->prev is not &lh2: %p", lh);
			if (lh->next != &lh1)
				TERR("lh->next is not NULL: %p", lh);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		i++;
	}

	return 1;
}

int
test12_2(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head *lh;
	int i = 0;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_for_each_reverse(lh, &lh1) {
		switch (i) {
		case 0:
			if (lh != &lh1)
				TERR("lh is not &lh1: %p", lh);
			if (lh->prev != &lh3)
				TERR("lh->prev is not NULL: %p", lh);
			if (lh->next != &lh2)
				TERR("lh->next is not &lh2: %p", lh);
			break;
		case 1:
			if (lh != &lh3)
				TERR("lh is not &lh3: %p", lh);
			if (lh->prev != &lh2)
				TERR("lh->prev is not &lh2: %p", lh);
			if (lh->next != &lh1)
				TERR("lh->next is not NULL: %p", lh);
			break;
		case 2:
			if (lh != &lh2)
				TERR("lh is not &lh2: %p", lh);
			if (lh->prev != &lh1)
				TERR("lh->prev is not &lh1: %p", lh);
			if (lh->next != &lh3)
				TERR("lh->next is not &lh3: %p", lh);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		i++;
	}

	return 1;
}

int
test13_0(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head *lh, *lh_tmp;
	int i = 0;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_for_each_safe(lh_tmp, lh, &lh1) {
		switch (i) {
		case 0:
			if (lh != &lh1)
				TERR("lh is not &lh1: %p", lh);
			if (lh->prev != &lh3)
				TERR("lh->prev is not NULL: %p", lh);
			if (lh->next != &lh2)
				TERR("lh->next is not &lh2: %p", lh);
			break;
		case 1:
			if (lh != &lh2)
				TERR("lh is not &lh2: %p", lh);
			if (lh->prev != &lh1)
				TERR("lh->prev is not &lh1: %p", lh);
			if (lh->next != &lh3)
				TERR("lh->next is not &lh3: %p", lh);
			break;
		case 2:
			if (lh != &lh3)
				TERR("lh is not &lh3: %p", lh);
			if (lh->prev != &lh2)
				TERR("lh->prev is not &lh2: %p", lh);
			if (lh->next != &lh1)
				TERR("lh->next is not NULL: %p", lh);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		lh->next = lh;
		lh->prev = lh;
		i++;
	}

	return 1;
}

int
test13_1(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head *lh, *lh_tmp;
	int i = 0;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_for_each_safe(lh_tmp, lh, &lh2) {
		switch (i) {
		case 0:
			if (lh != &lh2)
				TERR("lh is not &lh2: %p", lh);
			if (lh->prev != &lh1)
				TERR("lh->prev is not &lh1: %p", lh);
			if (lh->next != &lh3)
				TERR("lh->next is not &lh3: %p", lh);
			break;
		case 1:
			if (lh != &lh3)
				TERR("lh is not &lh3: %p", lh);
			if (lh->prev != &lh2)
				TERR("lh->prev is not &lh2: %p", lh);
			if (lh->next != &lh1)
				TERR("lh->next is not NULL: %p", lh);
			break;
		case 2:
			if (lh != &lh1)
				TERR("lh is not &lh1: %p", lh);
			if (lh->prev != &lh3)
				TERR("lh->prev is not NULL: %p", lh);
			if (lh->next != &lh2)
				TERR("lh->next is not &lh2: %p", lh);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		lh->next = lh;
		lh->prev = lh;
		i++;
	}

	return 1;
}

int
test13_2(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head *lh, *lh_tmp;
	int i = 0;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_for_each_safe(lh_tmp, lh, &lh3) {
		switch (i) {
		case 0:
			if (lh != &lh3)
				TERR("lh is not &lh3: %p", lh);
			if (lh->prev != &lh2)
				TERR("lh->prev is not &lh2: %p", lh);
			if (lh->next != &lh1)
				TERR("lh->next is not NULL: %p", lh);
			break;
		case 1:
			if (lh != &lh1)
				TERR("lh is not &lh1: %p", lh);
			if (lh->prev != &lh3)
				TERR("lh->prev is not NULL: %p", lh);
			if (lh->next != &lh2)
				TERR("lh->next is not &lh2: %p", lh);
			break;
		case 2:
			if (lh != &lh2)
				TERR("lh is not &lh2: %p", lh);
			if (lh->prev != &lh1)
				TERR("lh->prev is not &lh1: %p", lh);
			if (lh->next != &lh3)
				TERR("lh->next is not &lh3: %p", lh);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		lh->next = lh;
		lh->prev = lh;
		i++;
	}

	return 1;
}

int
test14_0(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head *lh, *lh_tmp;
	int i = 0;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_for_each_reverse_safe(lh_tmp, lh, &lh3) {
		switch (i) {
		case 0:
			if (lh != &lh3)
				TERR("lh is not &lh3: %p", lh);
			if (lh->prev != &lh2)
				TERR("lh->prev is not &lh2: %p", lh);
			if (lh->next != &lh1)
				TERR("lh->next is not NULL: %p", lh);
			break;
		case 1:
			if (lh != &lh2)
				TERR("lh is not &lh2: %p", lh);
			if (lh->prev != &lh1)
				TERR("lh->prev is not &lh1: %p", lh);
			if (lh->next != &lh3)
				TERR("lh->next is not &lh3: %p", lh);
			break;
		case 2:
			if (lh != &lh1)
				TERR("lh is not &lh1: %p", lh);
			if (lh->prev != &lh3)
				TERR("lh->prev is not NULL: %p", lh);
			if (lh->next != &lh2)
				TERR("lh->next is not &lh2: %p", lh);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		lh->next = lh;
		lh->prev = lh;
		i++;
	}

	return 1;
}

int
test14_1(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head *lh, *lh_tmp;
	int i = 0;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_for_each_reverse_safe(lh_tmp, lh, &lh2) {
		switch (i) {
		case 0:
			if (lh != &lh2)
				TERR("lh is not &lh2: %p", lh);
			if (lh->prev != &lh1)
				TERR("lh->prev is not &lh1: %p", lh);
			if (lh->next != &lh3)
				TERR("lh->next is not &lh3: %p", lh);
			break;
		case 1:
			if (lh != &lh1)
				TERR("lh is not &lh1: %p", lh);
			if (lh->prev != &lh3)
				TERR("lh->prev is not NULL: %p", lh);
			if (lh->next != &lh2)
				TERR("lh->next is not &lh2: %p", lh);
			break;
		case 2:
			if (lh != &lh3)
				TERR("lh is not &lh3: %p", lh);
			if (lh->prev != &lh2)
				TERR("lh->prev is not &lh2: %p", lh);
			if (lh->next != &lh1)
				TERR("lh->next is not NULL: %p", lh);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		lh->next = lh;
		lh->prev = lh;
		i++;
	}

	return 1;
}

int
test14_2(void)
{
	struct clist_item_head lh1, lh2, lh3;
	struct clist_item_head *lh, *lh_tmp;
	int i = 0;

	clist_item_head_init(&lh1);
	clist_item_head_init(&lh2);
	clist_item_head_init(&lh3);
	clist_add(&lh2, &lh1);
	clist_add(&lh3, &lh2);
	clist_for_each_reverse_safe(lh_tmp, lh, &lh1) {
		switch (i) {
		case 0:
			if (lh != &lh1)
				TERR("lh is not &lh1: %p", lh);
			if (lh->prev != &lh3)
				TERR("lh->prev is not NULL: %p", lh);
			if (lh->next != &lh2)
				TERR("lh->next is not &lh2: %p", lh);
			break;
		case 1:
			if (lh != &lh3)
				TERR("lh is not &lh3: %p", lh);
			if (lh->prev != &lh2)
				TERR("lh->prev is not &lh2: %p", lh);
			if (lh->next != &lh1)
				TERR("lh->next is not NULL: %p", lh);
			break;
		case 2:
			if (lh != &lh2)
				TERR("lh is not &lh2: %p", lh);
			if (lh->prev != &lh1)
				TERR("lh->prev is not &lh1: %p", lh);
			if (lh->next != &lh3)
				TERR("lh->next is not &lh3: %p", lh);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		lh->next = lh;
		lh->prev = lh;
		i++;
	}

	return 1;
}

int
test15_0(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi;

	myi1.n = 17;
	clist_item_head_init(&myi1.list);
	myi2.n = 18;
	clist_item_head_init(&myi2.list);
	myi3.n = 19;
	clist_item_head_init(&myi3.list);

	myi = clist_item(&myi1.list, struct myitem, list);
	if (myi != &myi1)
		TERR("myi is not myi1: %p", myi);
	if (myi->n != 17)
		TERR("myi-> is not 17: %d", myi->n);
	if (myi->list.prev != &myi1.list)
		TERR("myi->list.prev is not NULL: %p", myi->list.prev);
	if (myi->list.next != &myi1.list)
		TERR("myi->list.next is not NULL: %p", myi->list.next);

	myi = clist_item(&myi2.list, struct myitem, list);
	if (myi != &myi2)
		TERR("myi is not myi2: %p", myi);
	if (myi->n != 18)
		TERR("myi-> is not 18: %d", myi->n);
	if (myi->list.prev != &myi2.list)
		TERR("myi->list.prev is not NULL: %p", myi->list.prev);
	if (myi->list.next != &myi2.list)
		TERR("myi->list.next is not NULL: %p", myi->list.next);

	myi = clist_item(&myi3.list, struct myitem, list);
	if (myi != &myi3)
		TERR("myi is not myi3: %p", myi);
	if (myi->n != 19)
		TERR("myi-> is not 19: %d", myi->n);
	if (myi->list.prev != &myi3.list)
		TERR("myi->list.prev is not NULL: %p", myi->list.prev);
	if (myi->list.next != &myi3.list)
		TERR("myi->list.next is not NULL: %p", myi->list.next);

	return 1;
}

int
test15_1(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi;

	myi1.n = 17;
	clist_item_head_init(&myi1.list);
	myi2.n = 18;
	clist_item_head_init(&myi2.list);
	myi3.n = 19;
	clist_item_head_init(&myi3.list);

	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);

	myi = clist_item(&myi1.list, typeof(myi1), list);
	if (myi != &myi1)
		TERR("myi is not myi1: %p", myi);
	if (myi->n != 17)
		TERR("myi-> is not 17: %d", myi->n);
	if (myi->list.prev != &myi3.list)
		TERR("myi->list.prev is not NULL: %p", myi->list.prev);
	if (myi->list.next != &myi2.list)
		TERR("myi->list.next is not &myi2.list: %p", myi->list.next);

	myi = clist_item(&myi2.list, typeof(myi1), list);
	if (myi != &myi2)
		TERR("myi is not myi2: %p", myi);
	if (myi->n != 18)
		TERR("myi-> is not 18: %d", myi->n);
	if (myi->list.prev != &myi1.list)
		TERR("myi->list.prev is not &myi1.list: %p", myi->list.prev);
	if (myi->list.next != &myi3.list)
		TERR("myi->list.next is not &myi3.list: %p", myi->list.next);

	myi = clist_item(&myi3.list, typeof(myi1), list);
	if (myi != &myi3)
		TERR("myi is not myi3: %p", myi);
	if (myi->n != 19)
		TERR("myi-> is not 19: %d", myi->n);
	if (myi->list.prev != &myi2.list)
		TERR("myi->list.prev is not &myi2.list: %p", myi->list.prev);
	if (myi->list.next != &myi1.list)
		TERR("myi->list.next is not NULL: %p", myi->list.next);

	return 1;
}

int
test16_0(void)
{
	struct myitem myi1;

	myi1.n = 113;
	myi1.list.prev = (void*)0x17;
	myi1.list.next = (void*)0x18;
	clist_item_init(&myi1, list);
	if (myi1.list.prev != &myi1.list)
		TERR("myi1.list.prev is not NULL: %p", myi1.list.prev);
	if (myi1.list.next != &myi1.list)
		TERR("myi1.list.next is not NULL: %p", myi1.list.next);
	if (myi1.n != 113)
		TERR("myi1.n is not 113: %p", myi1.n);

	return 1;
}

int
test19_0(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi;

	myi1.n = 17;
	clist_item_init(&myi1, list);
	myi2.n = 18;
	clist_item_init(&myi2, list);
	myi3.n = 19;
	clist_item_init(&myi3, list);

	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);
	myi = clist_get_next_item(&myi1, list);
	if (myi != &myi2)
		TERR("next is not myi2(%p): %p", &myi2, myi);
	myi = clist_get_next_item(&myi2, list);
	if (myi != &myi3)
		TERR("next is not myi3(%p): %p", &myi3, myi);
	myi = clist_get_next_item(&myi3, list);
	if (myi != &myi1)
		TERR("next is not NULL: %p", myi);

	return 1;
}

int
test20_0(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi;

	myi1.n = 17;
	clist_item_init(&myi1, list);
	myi2.n = 18;
	clist_item_init(&myi2, list);
	myi3.n = 19;
	clist_item_init(&myi3, list);

	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);
	myi = clist_get_prev_item(&myi1, list);
	if (myi != &myi3)
		TERR("prev is not NULL: %p", myi);
	myi = clist_get_prev_item(&myi2, list);
	if (myi != &myi1)
		TERR("next is not myi1(%p): %p", &myi1, myi);
	myi = clist_get_prev_item(&myi3, list);
	if (myi != &myi2)
		TERR("next is not myi2(%p): %p", &myi2, myi);

	return 1;
}

int
test21_0(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi;
	int i = 0;

	myi1.n = 17;
	clist_item_init(&myi1, list);
	myi2.n = 18;
	clist_item_init(&myi2, list);
	myi3.n = 19;
	clist_item_init(&myi3, list);
	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);
	clist_for_each_item(myi, &myi1, list) {
		switch (i) {
		case 0:
			if (myi != &myi1)
				TERR("myi is not &myi1: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi3)
				TERR("myi prev is not &myi3: %p", myi);
			if (clist_get_next_item(myi, list) != &myi2)
				TERR("myi next is not &myi2: %p", myi);
			break;
		case 1:
			if (myi != &myi2)
				TERR("myi is not &myi2: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi1)
				TERR("myi prev is not &myi1: %p", myi);
			if (clist_get_next_item(myi, list) != &myi3)
				TERR("myi next is not &myi3: %p", myi);
			break;
		case 2:
			if (myi != &myi3)
				TERR("myi is not &myi3: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi2)
				TERR("myi prev is not &myi2: %p", myi);
			if (clist_get_next_item(myi, list) != &myi1)
				TERR("myi next is not &myi1: %p", myi);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		i++;
	}
	if (i != 3)
		TERR("i isn't 3: %d", i);

	return 1;
}

int
test21_1(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi;
	int i = 0;

	myi1.n = 17;
	clist_item_init(&myi1, list);
	myi2.n = 18;
	clist_item_init(&myi2, list);
	myi3.n = 19;
	clist_item_init(&myi3, list);
	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);
	clist_for_each_item(myi, &myi2, list) {
		switch (i) {
		case 0:
			if (myi != &myi2)
				TERR("myi is not &myi2: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi1)
				TERR("myi prev is not &myi1: %p", myi);
			if (clist_get_next_item(myi, list) != &myi3)
				TERR("myi next is not &myi3: %p", myi);
			break;
		case 1:
			if (myi != &myi3)
				TERR("myi is not &myi3: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi2)
				TERR("myi prev is not &myi2: %p", myi);
			if (clist_get_next_item(myi, list) != &myi1)
				TERR("myi next is not NULL: %p", myi);
			break;
		case 2:
			if (myi != &myi1)
				TERR("myi is not &myi1: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi3)
				TERR("myi prev is not NULL: %p", myi);
			if (clist_get_next_item(myi, list) != &myi2)
				TERR("myi next is not &myi2: %p", myi);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		i++;
	}
	if (i != 3)
		TERR("i isn't 3: %d", i);

	return 1;
}

int
test21_2(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi;
	int i = 0;

	myi1.n = 17;
	clist_item_init(&myi1, list);
	myi2.n = 18;
	clist_item_init(&myi2, list);
	myi3.n = 19;
	clist_item_init(&myi3, list);
	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);
	clist_for_each_item(myi, &myi3, list) {
		switch (i) {
		case 0:
			if (myi != &myi3)
				TERR("myi is not &myi3: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi2)
				TERR("myi prev is not &myi2: %p", myi);
			if (clist_get_next_item(myi, list) != &myi1)
				TERR("myi next is not NULL: %p", myi);
			break;
		case 1:
			if (myi != &myi1)
				TERR("myi is not &myi1: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi3)
				TERR("myi prev is not NULL: %p", myi);
			if (clist_get_next_item(myi, list) != &myi2)
				TERR("myi next is not &myi2: %p", myi);
			break;
		case 2:
			if (myi != &myi2)
				TERR("myi is not &myi2: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi1)
				TERR("myi prev is not &myi1: %p", myi);
			if (clist_get_next_item(myi, list) != &myi3)
				TERR("myi next is not &myi3: %p", myi);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		i++;
	}
	if (i != 3)
		TERR("i isn't 3: %d", i);

	return 1;
}

int
test22_0(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi;
	int i = 0;

	myi1.n = 17;
	clist_item_init(&myi1, list);
	myi2.n = 18;
	clist_item_init(&myi2, list);
	myi3.n = 19;
	clist_item_init(&myi3, list);
	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);
	clist_for_each_item_reverse(myi, &myi3, list) {
		switch (i) {
		case 0:
			if (myi != &myi3)
				TERR("myi is not &myi3: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi2)
				TERR("myi prev is not &myi2: %p", myi);
			if (clist_get_next_item(myi, list) != &myi1)
				TERR("myi next is not NULL: %p", myi);
			break;
		case 1:
			if (myi != &myi2)
				TERR("myi is not &myi2: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi1)
				TERR("myi prev is not &myi1: %p", myi);
			if (clist_get_next_item(myi, list) != &myi3)
				TERR("myi next is not &myi3: %p", myi);
			break;
		case 2:
			if (myi != &myi1)
				TERR("myi is not &myi1: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi3)
				TERR("myi prev is not NULL: %p", myi);
			if (clist_get_next_item(myi, list) != &myi2)
				TERR("myi next is not &myi2: %p", myi);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		i++;
	}
	if (i != 3)
		TERR("i isn't 3: %d", i);

	return 1;
}

int
test22_1(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi;
	int i = 0;

	myi1.n = 17;
	clist_item_init(&myi1, list);
	myi2.n = 18;
	clist_item_init(&myi2, list);
	myi3.n = 19;
	clist_item_init(&myi3, list);
	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);
	clist_for_each_item_reverse(myi, &myi2, list) {
		switch (i) {
		case 0:
			if (myi != &myi2)
				TERR("myi is not &myi2: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi1)
				TERR("myi prev is not &myi1: %p", myi);
			if (clist_get_next_item(myi, list) != &myi3)
				TERR("myi next is not &myi3: %p", myi);
			break;
		case 1:
			if (myi != &myi1)
				TERR("myi is not &myi1: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi3)
				TERR("myi prev is not NULL: %p", myi);
			if (clist_get_next_item(myi, list) != &myi2)
				TERR("myi next is not &myi2: %p", myi);
			break;
		case 2:
			if (myi != &myi3)
				TERR("myi is not &myi3: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi2)
				TERR("myi prev is not &myi2: %p", myi);
			if (clist_get_next_item(myi, list) != &myi1)
				TERR("myi next is not NULL: %p", myi);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		i++;
	}
	if (i != 3)
		TERR("i isn't 3: %d", i);

	return 1;
}

int
test22_2(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi;
	int i = 0;

	myi1.n = 17;
	clist_item_init(&myi1, list);
	myi2.n = 18;
	clist_item_init(&myi2, list);
	myi3.n = 19;
	clist_item_init(&myi3, list);
	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);
	clist_for_each_item_reverse(myi, &myi1, list) {
		switch (i) {
		case 0:
			if (myi != &myi1)
				TERR("myi is not &myi1: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi3)
				TERR("myi prev is not NULL: %p", myi);
			if (clist_get_next_item(myi, list) != &myi2)
				TERR("myi next is not &myi2: %p", myi);
			break;
		case 1:
			if (myi != &myi3)
				TERR("myi is not &myi3: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi2)
				TERR("myi prev is not &myi2: %p", myi);
			if (clist_get_next_item(myi, list) != &myi1)
				TERR("myi next is not NULL: %p", myi);
			break;
		case 2:
			if (myi != &myi2)
				TERR("myi is not &myi2: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi1)
				TERR("myi prev is not &myi1: %p", myi);
			if (clist_get_next_item(myi, list) != &myi3)
				TERR("myi next is not &myi3: %p", myi);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		i++;
	}
	if (i != 3)
		TERR("i isn't 3: %d", i);

	return 1;
}

int
test23_0(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi, *myi_tmp;
	int i = 0;

	myi1.n = 17;
	clist_item_init(&myi1, list);
	myi2.n = 18;
	clist_item_init(&myi2, list);
	myi3.n = 19;
	clist_item_init(&myi3, list);
	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);
	clist_for_each_item_safe(myi_tmp, myi, &myi1, list) {
		switch (i) {
		case 0:
			if (myi != &myi1)
				TERR("myi is not &myi1: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi3)
				TERR("myi prev is not NULL: %p", myi);
			if (clist_get_next_item(myi, list) != &myi2)
				TERR("myi next is not &myi2: %p", myi);
			break;
		case 1:
			if (myi != &myi2)
				TERR("myi is not &myi2: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi1)
				TERR("myi prev is not &myi1: %p", myi);
			if (clist_get_next_item(myi, list) != &myi3)
				TERR("myi next is not &myi3: %p", myi);
			break;
		case 2:
			if (myi != &myi3)
				TERR("myi is not &myi3: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi2)
				TERR("myi prev is not &myi2: %p", myi);
			if (clist_get_next_item(myi, list) != &myi1)
				TERR("myi next is not NULL: %p", myi);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		myi->list.prev = &myi->list;
		myi->list.next = &myi->list;
		i++;
	}
	if (i != 3)
		TERR("i isn't 3: %d", i);

	return 1;
}

int
test23_1(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi, *myi_tmp;
	int i = 0;

	myi1.n = 17;
	clist_item_init(&myi1, list);
	myi2.n = 18;
	clist_item_init(&myi2, list);
	myi3.n = 19;
	clist_item_init(&myi3, list);
	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);
	clist_for_each_item_safe(myi_tmp, myi, &myi2, list) {
		switch (i) {
		case 0:
			if (myi != &myi2)
				TERR("myi is not &myi2: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi1)
				TERR("myi prev is not &myi1: %p", myi);
			if (clist_get_next_item(myi, list) != &myi3)
				TERR("myi next is not &myi3: %p", myi);
			break;
		case 1:
			if (myi != &myi3)
				TERR("myi is not &myi3: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi2)
				TERR("myi prev is not &myi2: %p", myi);
			if (clist_get_next_item(myi, list) != &myi1)
				TERR("myi next is not NULL: %p", myi);
			break;
		case 2:
			if (myi != &myi1)
				TERR("myi is not &myi1: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi3)
				TERR("myi prev is not NULL: %p", myi);
			if (clist_get_next_item(myi, list) != &myi2)
				TERR("myi next is not &myi2: %p", myi);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		myi->list.prev = &myi->list;
		myi->list.next = &myi->list;
		i++;
	}
	if (i != 3)
		TERR("i isn't 3: %d", i);

	return 1;
}

int
test23_2(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi, *myi_tmp;
	int i = 0;

	myi1.n = 17;
	clist_item_init(&myi1, list);
	myi2.n = 18;
	clist_item_init(&myi2, list);
	myi3.n = 19;
	clist_item_init(&myi3, list);
	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);
	clist_for_each_item_safe(myi_tmp, myi, &myi3, list) {
		switch (i) {
		case 0:
			if (myi != &myi3)
				TERR("myi is not &myi3: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi2)
				TERR("myi prev is not &myi2: %p", myi);
			if (clist_get_next_item(myi, list) != &myi1)
				TERR("myi next is not NULL: %p", myi);
			break;
		case 1:
			if (myi != &myi1)
				TERR("myi is not &myi1: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi3)
				TERR("myi prev is not NULL: %p", myi);
			if (clist_get_next_item(myi, list) != &myi2)
				TERR("myi next is not &myi2: %p", myi);
			break;
		case 2:
			if (myi != &myi2)
				TERR("myi is not &myi2: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi1)
				TERR("myi prev is not &myi1: %p", myi);
			if (clist_get_next_item(myi, list) != &myi3)
				TERR("myi next is not &myi3: %p", myi);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		myi->list.prev = &myi->list;
		myi->list.next = &myi->list;
		i++;
	}
	if (i != 3)
		TERR("i isn't 3: %d", i);

	return 1;
}

int
test24_0(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi, *myi_tmp;
	int i = 0;

	myi1.n = 17;
	clist_item_init(&myi1, list);
	myi2.n = 18;
	clist_item_init(&myi2, list);
	myi3.n = 19;
	clist_item_init(&myi3, list);
	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);
	clist_for_each_item_reverse_safe(myi_tmp, myi, &myi3, list) {
		switch (i) {
		case 0:
			if (myi != &myi3)
				TERR("myi is not &myi3: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi2)
				TERR("myi prev is not &myi2: %p", myi);
			if (clist_get_next_item(myi, list) != &myi1)
				TERR("myi next is not NULL: %p", myi);
			break;
		case 1:
			if (myi != &myi2)
				TERR("myi is not &myi2: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi1)
				TERR("myi prev is not &myi1: %p", myi);
			if (clist_get_next_item(myi, list) != &myi3)
				TERR("myi next is not &myi3: %p", myi);
			break;
		case 2:
			if (myi != &myi1)
				TERR("myi is not &myi1: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi3)
				TERR("myi prev is not NULL: %p", myi);
			if (clist_get_next_item(myi, list) != &myi2)
				TERR("myi next is not &myi2: %p", myi);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		myi->list.prev = &myi->list;
		myi->list.next = &myi->list;
		i++;
	}
	if (i != 3)
		TERR("i isn't 3: %d", i);

	return 1;
}

int
test24_1(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi, *myi_tmp;
	int i = 0;

	myi1.n = 17;
	clist_item_init(&myi1, list);
	myi2.n = 18;
	clist_item_init(&myi2, list);
	myi3.n = 19;
	clist_item_init(&myi3, list);
	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);
	clist_for_each_item_reverse_safe(myi_tmp, myi, &myi2, list) {
		switch (i) {
		case 0:
			if (myi != &myi2)
				TERR("myi is not &myi2: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi1)
				TERR("myi prev is not &myi1: %p", myi);
			if (clist_get_next_item(myi, list) != &myi3)
				TERR("myi next is not &myi3: %p", myi);
			break;
		case 1:
			if (myi != &myi1)
				TERR("myi is not &myi1: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi3)
				TERR("myi prev is not NULL: %p", myi);
			if (clist_get_next_item(myi, list) != &myi2)
				TERR("myi next is not &myi2: %p", myi);
			break;
		case 2:
			if (myi != &myi3)
				TERR("myi is not &myi3: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi2)
				TERR("myi prev is not &myi2: %p", myi);
			if (clist_get_next_item(myi, list) != &myi1)
				TERR("myi next is not NULL: %p", myi);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		myi->list.prev = &myi->list;
		myi->list.next = &myi->list;
		i++;
	}
	if (i != 3)
		TERR("i isn't 3: %d", i);

	return 1;
}

int
test24_2(void)
{
	struct myitem myi1, myi2, myi3;
	struct myitem *myi, *myi_tmp;
	int i = 0;

	myi1.n = 17;
	clist_item_init(&myi1, list);
	myi2.n = 18;
	clist_item_init(&myi2, list);
	myi3.n = 19;
	clist_item_init(&myi3, list);
	clist_add(&myi2.list, &myi1.list);
	clist_add(&myi3.list, &myi2.list);
	clist_for_each_item_reverse_safe(myi_tmp, myi, &myi1, list) {
		switch (i) {
		case 0:
			if (myi != &myi1)
				TERR("myi is not &myi1: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi3)
				TERR("myi prev is not NULL: %p", myi);
			if (clist_get_next_item(myi, list) != &myi2)
				TERR("myi next is not &myi2: %p", myi);
			break;
		case 1:
			if (myi != &myi3)
				TERR("myi is not &myi3: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi2)
				TERR("myi prev is not &myi2: %p", myi);
			if (clist_get_next_item(myi, list) != &myi1)
				TERR("myi next is not NULL: %p", myi);
			break;
		case 2:
			if (myi != &myi2)
				TERR("myi is not &myi2: %p", myi);
			if (clist_get_prev_item(myi, list) != &myi1)
				TERR("myi prev is not &myi1: %p", myi);
			if (clist_get_next_item(myi, list) != &myi3)
				TERR("myi next is not &myi3: %p", myi);
			break;
		default:
			TERR("i is bigger than 2");
			break;
		}
		myi->list.prev = &myi->list;
		myi->list.next = &myi->list;
		i++;
	}
	if (i != 3)
		TERR("i isn't 3: %d", i);

	return 1;
}

struct test tests[] = {
	{test0_0, "clist_item_head_init()"},
	{test0_1, "clist_item_head_init(): for my struct"},
	{test1_0, "_clist_add(,,): 1-2"},
	{test1_1, "_clist_add(,,): 1-3, 1-2-3"},
	{test1_2, "_clist_add(,,): 1-2, 1-2-3"},
	{test2_0, "clist_add(): 1-2, 1-2-3"},
	{test2_1, "clist_add(): 1-2, 1-3-2"},
	{test3_0, "clist_add_before(): 2-1, 3-2-1"},
	{test3_1, "clist_add_before(): 2-1, 2-3-1"},
	{test8_0, "clist_replace(,1)"},
	{test8_1, "clist_replace(,2)"},
	{test8_2, "clist_replace(,3)"},
	{test9_0, "clist_rm(1)"},
	{test9_1, "clist_rm(2)"},
	{test9_2, "clist_rm(3)"},
	{test10_0, "clist_swap(1, 2)"},
	{test10_1, "clist_swap(1, 3)"},
	{test10_2, "clist_swap(2, 1)"},
	{test10_3, "clist_swap(2, 2)"},
	{test10_4, "clist_swap(2, 3)"},
	{test11_0, "clist_for_each(, 1)"},
	{test11_1, "clist_for_each(, 2)"},
	{test11_2, "clist_for_each(, 3)"},
	{test12_0, "clist_for_each_reverse(, 3)"},
	{test12_1, "clist_for_each_reverse(, 2)"},
	{test12_2, "clist_for_each_reverse(, 1)"},
	{test13_0, "clist_for_each_safe(, 1)"},
	{test13_1, "clist_for_each_safe(, 2)"},
	{test13_2, "clist_for_each_safe(, 3)"},
	{test14_0, "clist_for_each_reverse_safe(, 3)"},
	{test14_1, "clist_for_each_reverse_safe(, 2)"},
	{test14_2, "clist_for_each_reverse_safe(, 1)"},
	{test15_0, "clist_item()"},
	{test15_1, "clist_item(): for linked items"},
	{test16_0, "clist_item_init()"},
	{test19_0, "clist_get_next_item()"},
	{test20_0, "clist_get_prev_item()"},
	{test21_0, "clist_for_each_item(, 1, )"},
	{test21_1, "clist_for_each_item(, 2, )"},
	{test21_2, "clist_for_each_item(, 3, )"},
	{test22_0, "clist_for_each_item_reverse(, 3, )"},
	{test22_1, "clist_for_each_item_reverse(, 2, )"},
	{test22_2, "clist_for_each_item_reverse(, 1, )"},
	{test23_0, "clist_for_each_item_safe(, 1, )"},
	{test23_1, "clist_for_each_item_safe(, 2, )"},
	{test23_2, "clist_for_each_item_safe(, 3, )"},
	{test24_0, "clist_for_each_item_reverse_safe(, 3, )"},
	{test24_1, "clist_for_each_item_reverse_safe(, 2, )"},
	{test24_2, "clist_for_each_item_reverse_safe(, 1, )"},
	TEST_NULL
};

int
main(int argc, char **argv)
{
	int i, cnt = 0, ret, total = 0;

	init();

	for(i = 0; tests[i].test; i++)
		total++;

	for(i = 0; tests[i].test; i++) {
		pretest(i);
		fprintf(stderr, "\x1b[34;01m%s\x1b[00m:%s... ", argv[0], tests[i].title);
		ret = tests[i].test();
		fprintf(stderr, "%s\n", ret ? "ok" : "fail");
		posttest(i);
		if (ret)
			cnt++;
	}

	deinit();

	printf("\x1b[34;01m%s\x1b[00m:TOTAL %d/%d\n", argv[0], cnt, total);
	return cnt != total;
}
