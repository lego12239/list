#include "list.h"
#include <string.h>
#include <stdio.h>

struct part {
	struct list_item_head list; /* prev/next pointers */
	float mass; /* kg */
	char *article; /* part article */
	/* some other data */
	/* ... */
};

void
part_init(struct part *p, char *article, float mass)
{
	p->article = strdup(article);
	p->mass = mass;
	list_item_head_init(&p->list);
}

void
part_add(struct part *phead, struct part *p)
{
	list_add_tail(&p->list, &phead->list);
}

void
parts_show(struct part *phead)
{
	struct part *p;

	list_for_each_item(p, phead, list) {
		printf("%s: %f\n", p->article, p->mass);
	}
}

void
main(void)
{
	struct part p1, p2, p3;

	part_init(&p1, "001", 2);
	part_init(&p2, "002", 0.3);
	part_init(&p3, "003", 0.75);

	part_add(&p1, &p2);
	part_add(&p1, &p3);

	parts_show(&p1);
}

