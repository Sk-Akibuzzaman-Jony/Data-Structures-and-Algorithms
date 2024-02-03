// https://www.codingninjas.com/studio/problems/1112655

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* merge(Node* list1, Node* list2){
	Node* dummyNode = new Node(-1);
	Node* res = dummyNode;
	while(list1 && list2){
		if(list1->data < list2->data){
			res->child = list1;
			res = list1;
			list1 = list1->child;
		} else {
			res->child = list2;
			res = list2;
			list2 = list2->child;
		}
		res->next = NULL;
	}
	if(list1) res->child = list1;
	else res->child = list2;
	return dummyNode->child;
}
Node* flattenLinkedList(Node* head) 
{
	if(!head || !head->next){
		return head;
	}

	Node* mergedList = flattenLinkedList(head->next);
	return merge(head, mergedList);
}
