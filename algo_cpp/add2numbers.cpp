#include <iostream>
#include <vector>
#include <unordered_map>



 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
 ListNode* addtwoNumbers(ListNode* l1, ListNode* l2)
 {
     ListNode* dummy = new ListNode(0);
     ListNode* l3 = dummy;
     int carry = 0;

     while(l1 != nullptr && l2 != nullptr)
     {
         ListNode * node = new ListNode((l1->val + l2->val + carry) % 10);
         carry = (l1->val + l2->val + carry) / 10;
         l3->next = node;
         l3 = l3->next;
         l1 = l1->next;
         l2 = l2->next;
     }

     while( l1 != nullptr)
     {
         ListNode* node = new ListNode((l1->val + carry) % 10);
         carry = (l1->val + carry) / 10;
         l3->next = node;
         l3 = l3->next;
         l1 = l1->next;
     }

     while( l2 != nullptr)
     {
         ListNode* node = new ListNode((l2->val + carry) % 10);
         carry = (l2->val + carry) / 10;
         l3->next = node;
         l3 = l3->next;
         l2 = l2->next;
     }

     if(carry != 0)
     {
         ListNode* node = new ListNode(carry % 10);
         l3->next = node;
         l3 = l3->next;
     }

     return dummy->next;
 }

int main()
{
    //driver code to generate linked list
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* fin = addtwoNumbers(l1, l2);

    while(fin != nullptr)
    {
        std::cout << fin->val << ", ";
        fin = fin->next;
    }
    std::cout << "\n";
    return 0;
}
