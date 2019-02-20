//
// Created by jyh on 1/5/2019.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {
//        cout<<"parameter constructor"<<endl;
    }
//    ListNode(const ListNode& a){
//        val=a.val;
//        next=a.next;
//        cout<<"copy constructor"<<endl;
//    }
//    ListNode &operator=(const ListNode &a){
//        val=a.val;
//        next=a.next;
//        cout<<"assign"<<endl;
//        return *this;
//    }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL || l2 == NULL)
            return NULL;
        ListNode *head = new ListNode(0);
        ListNode *currNode = head;
        int ten = 0;
        ListNode *tmp1 = new ListNode(0);
        ListNode *tmp2 = new ListNode(0);
        tmp1->next = l1;
        tmp2->next = l2;
        while (true) {
            int bitSum = tmp1->next->val + tmp2->next->val + ten;
            ten = bitSum / 10;
            bitSum = bitSum % 10;
            ListNode *x = new ListNode(bitSum);
            currNode->next = x;
            currNode = x;
            //if l1 and l2 are not the same length I pad it to the same length.
            //but I must declaim it is worse solution...However, it is a fast handling method.
            if (tmp1->next->next == NULL &&tmp2->next->next == NULL) break;
            else if(tmp1->next->next == NULL){
                ListNode *x = new ListNode(0);
                tmp1->next->next=x;
            }else if(tmp2->next->next == NULL){
                ListNode *x = new ListNode(0);
                tmp2->next->next=x;
            }

            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        if (ten == 1) {
            ListNode *x = new ListNode(1);
            currNode->next = x;
        }
        return head->next;
    }
};


//class Solution {
//public:
//    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
//        if (l1 == NULL || l2 == NULL)
//            return NULL;
//        ListNode *head = new ListNode(0);
//        ListNode *currNode = head;
//        int ten = 0;
//        ListNode *tmp1 = new ListNode(0);
//        ListNode *tmp2 = new ListNode(0);
//        tmp1->next = l1;
//        tmp2->next = l2;
//        while (true) {
//            int bitSum = tmp1->next->val + tmp2->next->val + ten;
//            ten = bitSum / 10;
//            bitSum = bitSum % 10;
//            ListNode x(bitSum);//it is wrong,beacuse I have copy x to output linkedList,but I will revise the value of x in the next loop
//                                //So that output will be corrupted by x.Here I can use new to create a new object 'x', which would not override output.
//            currNode->next = &x;
//            currNode = &x;
//            //if l1 and l2 are not the same length I pad it to the same length.
//            //but I must declaim it is worse solution...However, it is a fast handling method.
//            if (tmp1->next->next == NULL && tmp2->next->next == NULL) break;
//            else if (tmp1->next->next == NULL) {
//                ListNode x = ListNode(0);
//                tmp1->next->next = &x;
//            } else if (tmp2->next->next == NULL) {
//                ListNode x = ListNode(0);
//                tmp2->next->next = &x;
//            }
//
//            tmp1 = tmp1->next;
//            tmp2 = tmp2->next;
//        }
//        if (ten == 1) {
//            ListNode *x = new ListNode(1);
//            currNode->next = x;
//        }
//        return head->next;
//    }
//};


int main() {
//    for (int i = 0; i < 2; i++) {
//        int a = 1;
//        cout << a << endl;
//
//        int &b = a;
//        a = 10;
//        cout << b << endl;
//
//    }




//    ListNode l0(0);
    ListNode l1(9);
    ListNode l2(8);
    ListNode l3(3);
    ListNode l4(1);
    ListNode l5(6);
    ListNode l6(4);
//    ListNode l7(0);
//    l0.next = &l1;
    l1.next = &l2;
//    l2.next = &l3;

//    l7.next = &l4;
//    l4.next = &l5;
//    l5.next = &l6;
    Solution s;
    ListNode *tmp = s.addTwoNumbers(&l1, &l4);
    cout << tmp->val << tmp->next->val << endl;
    return 0;
}