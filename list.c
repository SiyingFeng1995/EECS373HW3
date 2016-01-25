#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	if (new_element->index <= head->index) {
		new_element->next = head;
		head = new_element;
	}
	else {
		struct list_t* curr = head;
		while((curr->next != NULL) && (new_element->index > curr->next->index)) {
			curr = curr->next;
		}
		new_element->next = curr->next;
		curr->next = new_element;
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t* prev = NULL;
	list_t* curr;

	while (head != NULL) {
		curr = head;
		head = head->next;
		curr->next = prev;
		prev = curr;
	}

	head = curr;

	return head;
}

