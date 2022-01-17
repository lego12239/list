#include "list.h"
#include <stdio.h>

struct part {
	struct list_item_head list; /* prev/next pointers */
	float mass; /* kg */
	char *article; /* part article */
	/* some other data */
	/* ... */
};

void
main(void)
{
	struct part p1, p2, p3, *p;

	p1.mass = 2;
	p1.article = "001";
	list_item_head_init(&p1.list);
	p2.mass = 0.3;
	p2.article = "002";
	list_item_head_init(&p2.list);
	p3.mass = 0.75;
	p3.article = "003";
	list_item_head_init(&p3.list);

	list_add(&p2.list, &p1.list);
	list_add(&p3.list, &p2.list);

	list_for_each_item(p, &p1, list) {
		if (p->mass > 1)
			printf("%s: %f\n", p->article, p->mass);
	}
}

