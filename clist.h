#ifndef __CLIST_H__
#define __CLIST_H__
/*
 * Circular doubly linked list
 */

/*
 * TODO:
 * - list_move()?
 * - list_is_head()?
 * - list_is_tail()?
 * - list_len()?
 * - list_cut()?
 * - list_push()/list_pop()?
 * - list_unshift()/list_shift()?
 * - list_join()?
 */

#include <stddef.h>
#include <string.h>


struct clist_item_head {
	struct clist_item_head *next;
	struct clist_item_head *prev;
};

static inline void clist_item_head_init(struct clist_item_head *h)
{
	h->next = h->prev = h;
}

static inline void _clist_add(struct clist_item_head *new, struct clist_item_head *prev, struct clist_item_head *next)
{
	new->prev = prev;
	new->next = next;
	next->prev = new;
	prev->next = new;
}

static inline void clist_add(struct clist_item_head *new, struct clist_item_head *h)
{
	_clist_add(new, h, h->next);
}

static inline void clist_add_before(struct clist_item_head *new, struct clist_item_head *h)
{
	_clist_add(new, h->prev, h);
}

static inline void clist_replace(struct clist_item_head *old, struct clist_item_head *new)
{
	new->next = old->next;
	new->next->prev = new;
	new->prev = old->prev;
	new->prev->next = new;
}

static inline void clist_rm(struct clist_item_head *h)
{
	h->prev->next = h->next;
	h->next->prev = h->prev;
	h->prev = (void*)0x1;
	h->next = (void*)0x2;
}

static inline void clist_swap(struct clist_item_head *h1, struct clist_item_head *h2)
{
	struct clist_item_head *h2_prev, *h2_next;

	if (h1 == h2)
		return;
	h2_prev = h2->prev;
	if (h2_prev == h1)
		h2_prev = h2;
	h2_next = h2->next;
	if (h2_next == h1)
		h2_next = h2;
	clist_rm(h2);
	clist_replace(h1, h2);
	_clist_add(h1, h2_prev, h2_next);
}

#define clist_for_each(h, start) \
	for(h = (start); h; h = h->next == start ? NULL : h->next)

#define clist_for_each_reverse(h, start) \
	for(h = (start); h; h = h->prev == start ? NULL : h->prev)

#define clist_for_each_safe(tmp, h, start) \
	for(h = (start), tmp = h ? h->next : NULL; \
	  h; \
	  h = tmp == start ? NULL : tmp, tmp = h ? h->next : NULL)

#define clist_for_each_reverse_safe(tmp, h, start) \
	for(h = (start), tmp = h ? h->prev : NULL; \
	  h; \
	  h = tmp == start ? NULL : tmp, tmp = h ? h->prev : NULL)

/***********************************************************************
 * FOR ITEMS
 ***********************************************************************/
#ifdef __GNUC__
#define clist_item(ptr, type, member) (ptr == NULL ? NULL : ({ \
	const typeof(((type*)0)->member) *__mptr = (ptr); \
	(type*)((char*)(__mptr) - offsetof(type, member));}))
#else
#define clist_item(ptr, type, member) \
	(ptr == NULL ? NULL : (type*)((char*)(ptr) - offsetof(type, member)))
#endif  /* __GNUC__ */

#define clist_item_init(item, member)\
	do { if (item) clist_item_head_init(&(item)->member); } while (0)

#define clist_get_next_item(item, member) \
	((item) ? clist_item((item)->member.next, typeof(*(item)), member) : NULL)

#define clist_get_prev_item(item, member) \
	((item) ? clist_item((item)->member.prev, typeof(*(item)), member) : NULL)

/*
 * i, start - a list item type var
 */
#define clist_for_each_item(i, start, member) \
	for(i = start; \
	    i; \
	    i = clist_get_next_item(i, member), i = i == start ? NULL : i)

/*
 * i, start - a list item type var
 */
#define clist_for_each_item_reverse(i, start, member) \
	for(i = start; \
	    i; \
	    i = clist_get_prev_item(i, member), i = i == start ? NULL : i)

/*
 * tmp, i, start - a list item type var
 */
#define clist_for_each_item_safe(tmp, i, start, member) \
	for(i = (start), \
	    tmp = clist_get_next_item(i, member); \
	    i; \
	    i = tmp == (start) ? NULL : tmp, \
	    tmp = clist_get_next_item(i, member))

/*
 * tmp, i, start - a list item type var
 */
#define clist_for_each_item_reverse_safe(tmp, i, start, member) \
	for(i = start, \
	    tmp = i ? clist_get_prev_item(i, member) : NULL; \
	    i; \
	    i = tmp == (start) ? NULL : tmp, \
	    tmp = clist_get_prev_item(i, member))

#define clist_add_item(new, old, member) \
	clist_add(&(new)->member, &(old)->member)

#define clist_rm_item(item, member) \
	clist_rm(&(item)->member)

#endif /* __CLIST_H__ */
