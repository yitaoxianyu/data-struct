// Copyright [2023] <Water Wang>

#include <iostream>


enum Status { OK = 0, ERROR = -1, OVER_FLOW = -2 };


typedef struct LNode {

  int data;

  struct LNode *next;

} LNode, *LinkList;  // LinkList is the pointer type which point to struct LNode


void InputDataAsLinkList(LinkList const &link_list);

void OutputDataInLinkList(LinkList const &link_list);

Status InitList(LinkList *link_list);

Status DestroyList(LinkList *link_list);

void Inverse(LinkList const &la);


int main() {

  LinkList la;

  int maximum;


  InitList(&la);


  InputDataAsLinkList(la);

  Inverse(la);

  OutputDataInLinkList(la);


  DestroyList(&la);


  return 0;

}


/// @brief accept data from console, and store data in link list.

/// @param link_list link list which stores input data from console.

void InputDataAsLinkList(LinkList const &link_list) {

  using std::cin;

  cin >> link_list->data;

  LinkList temp_link_list = link_list;


  for (int i = 0; i < link_list->data; i++) {

    LNode *temp_lnode_ptr = new LNode;

    temp_lnode_ptr->next = NULL;

    cin >> temp_lnode_ptr->data;

    temp_link_list->next = temp_lnode_ptr;

    temp_link_list = temp_link_list->next;

  }


  return;

}


/// @brief output data in link list to console

/// @param link_list  link list which stores all input data from console.

void OutputDataInLinkList(LinkList const &link_list) {

  using std::cout;

  using std::endl;

  LinkList temp_link_list = link_list->next;


  cout << link_list->data << endl;


  while (NULL != temp_link_list) {

    if (NULL != temp_link_list->next) {

      cout << temp_link_list->data << " ";

    } else {

      cout << temp_link_list->data << endl;

    }


    temp_link_list = temp_link_list->next;

  }


  return;

}


/// @brief initiate link list.

/// @param link_list link list to be initiated.

Status InitList(LinkList *link_list) {

  Status result = ERROR;


  *link_list = new LNode;

  (*link_list)->data = 0;

  (*link_list)->next = NULL;

  result = OK;


  return result;

}


/// @brief destroy link list.

/// @param link_list link list to be destroyed.

Status DestroyList(LinkList *link_list) {

  while (NULL != (*link_list)) {

    LNode *p = *link_list;

    *link_list = (*link_list)->next;

    delete p;

  }


  return OK;

}

void Inverse(LinkList &la){
	if(la == nullptr || la -> next == NULL)	return ;
	LNode *prev = NULL;
	LNode *current = la -> next;
	LNode *next = NULL;
	
	while(current != NULL){
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	
	la -> next = prev;
}


/// @brief inverse the order of elements in link list.

///

/// @param la link list to be inversed.

/* 请在这里填写答案 */
