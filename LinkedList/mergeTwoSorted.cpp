#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* solve(ListNode* &first, ListNode* &second) {
        ListNode* curr1 = first;
        ListNode* next1 = first->next;
        ListNode* curr2 = second;
        ListNode* next2 = curr2->next;

        while (next1 != nullptr && curr2 != nullptr) {
            if (curr2->val >= curr1->val && curr2->val <= next1->val) {
                curr1->next = curr2;
                curr2->next = next1;
                next2 = curr2->next;
                curr1 = curr2;
                curr2 = next2;
            } else {
                curr1 = next1;
                next1 = next1->next;
                if (next1 == nullptr) {
                    curr1->next = curr2;
                    return first;
                }
            }
        }

        if (next1 == nullptr && curr2 != nullptr) {
            curr1->next = curr2;
        }

        return first;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        if (list1->val <= list2->val) {
            return solve(list1, list2);
        } else {
            return solve(list2, list1);
        }
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    for (int value : values) {
        if (head == nullptr) {
            head = new ListNode(value);
            curr = head;
        } else {
            curr->next = new ListNode(value);
            curr = curr->next;
        }
    }
    return head;
}

// Helper function to print the values of a linked list
void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Example inputs
    std::vector<int> values1 = {1, 2, 4};
    std::vector<int> values2 = {1, 3, 4};
    ListNode* list1 = createLinkedList(values1);
    ListNode* list2 = createLinkedList(values2);

    // Merge the two lists
    ListNode* merged = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    printLinkedList(merged);

    // Clean up memory
    ListNode* curr = merged;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
