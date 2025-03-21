#ifndef __LIST_H__
#define __LIST_H__
/*
 * Doubly linked list with NULL as terminators
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


struct list_item_head {
	struct list_item_head *next;
	struct list_item_head *prev;
};

static inline void list_item_head_init(struct list_item_head *h)
{
	memset(h, 0, sizeof(*h));
}

static inline void _list_add(struct list_item_head *new, struct list_item_head *prev, struct list_item_head *next)
{
	new->prev = prev;
	new->next = next;
	if (next)
		next->prev = new;
	if (prev)
		prev->next = new;
}

static inline void list_add(struct list_item_head *new, struct list_item_head *h)
{
	_list_add(new, h, h->next);
}

static inline void list_add_before(struct list_item_head *new, struct list_item_head *h)
{
	_list_add(new, h->prev, h);
}

static inline struct list_item_head* list_get_head(struct list_item_head *h)
{
	while (h->prev)
		h = h->prev;
	return h;
}

static inline struct list_item_head* list_get_tail(struct list_item_head *h)
{
	while (h->next)
		h = h->next;
	return h;
}

static inline void list_add_head(struct list_item_head *new, struct list_item_head *h)
{
	_list_add(new, NULL, list_get_head(h));
}

static inline void list_add_tail(struct list_item_head *new, struct list_item_head *h)
{
	_list_add(new, list_get_tail(h), NULL);
}

static inline void list_replace(struct list_item_head *old, struct list_item_head *new)
{
	new->next = old->next;
	new->prev = old->prev;
	if (new->next)
		new->next->prev = new;
	if (new->prev)
		new->prev->next = new;
}

static inline void list_rm(struct list_item_head *h)
{
	if (h->prev)
		h->prev->next = h->next;
	if (h->next)
		h->next->prev = h->prev;
	h->next = NULL;
	h->prev = NULL;
}

static inline void list_swap(struct list_item_head *h1, struct list_item_head *h2)
{
	struct list_item_head *h2_prev, *h2_next;

	if (h1 == h2)
		return;
	h2_prev = h2->prev;
	if (h2_prev == h1)
		h2_prev = h2;
	h2_next = h2->next;
	if (h2_next == h1)
		h2_next = h2;
	list_rm(h2);
	list_replace(h1, h2);
	_list_add(h1, h2_prev, h2_next);
}

#define list_for_each(h, start) \
	for(h = (start); h; h = h->next)

#define list_for_each_reverse(h, start) \
	for(h = (start); h; h = h->prev)

#define list_for_each_safe(tmp, h, start) \
	for(h = (start), tmp = h ? h->next : NULL; \
	  h; \
	  h = tmp, tmp = h ? h->next : NULL)

#define list_for_each_reverse_safe(tmp, h, start) \
	for(h = (start), tmp = h ? h->prev : NULL; \
	  h; \
	  h = tmp, tmp = h ? h->prev : NULL)

/***********************************************************************
 * FOR ITEMS
 ***********************************************************************/
#ifdef __GNUC__
#define list_item(ptr, type, member) (ptr == NULL ? NULL : ({ \
	const typeof(((type*)0)->member) *__mptr = (ptr); \
	(type*)((char*)(__mptr) - offsetof(type, member));}))
#else
#define list_item(ptr, type, member) \
	(ptr == NULL ? NULL : (type*)((char*)(ptr) - offsetof(type, member)))
#endif  /* __GNUC__ */

#define list_item_init(item, member)\
	do { if (item) list_item_head_init(&(item)->member); } while (0)

#define list_get_head_item(item, member) \
	((item) ? list_item(list_get_head(&(item)->member), typeof(*(item)), member) : NULL)

#define list_get_tail_item(item, member) \
	((item) ? list_item(list_get_tail(&(item)->member), typeof(*(item)), member) : NULL)

#define list_get_next_item(item, member) \
	((item) ? list_item((item)->member.next, typeof(*(item)), member) : NULL)

#define list_get_prev_item(item, member) \
	((item) ? list_item((item)->member.prev, typeof(*(item)), member) : NULL)

/*
 * i, start - a list item type var
 */
#define list_for_each_item(i, start, member) \
	for(i = start; \
	    i; \
	    i = list_get_next_item(i, member))

/*
 * i, start - a list item type var
 */
#define list_for_each_item_reverse(i, start, member) \
	for(i = start; \
	    i; \
	    i = list_get_prev_item(i, member))

/*
 * tmp, i, start - a list item type var
 */
#define list_for_each_item_safe(tmp, i, start, member) \
	for(i = start, \
	    tmp = list_get_next_item(i, member); \
	    i; \
	    i = tmp, \
	    tmp = list_get_next_item(i, member))

/*
 * tmp, i, start - a list item type var
 */
#define list_for_each_item_reverse_safe(tmp, i, start, member) \
	for(i = start, \
	    tmp = list_get_prev_item(i, member); \
	    i; \
	    i = tmp, \
	    tmp = list_get_prev_item(i, member))

#define list_add_item(new, old, member) \
	list_add(&(new)->member, &(old)->member)

#define list_rm_item(item, member) \
	list_rm(&(item)->member)

#endif /* __LIST_H__ */
