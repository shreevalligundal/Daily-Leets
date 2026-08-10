/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2)
{
    vector<int> arr;

    ListNode* temp = head1;

    while(temp != NULL)
    {
        arr.push_back(temp->val);
        temp = temp->next;
    }

    temp = head2;

    while(temp != NULL)
    {
        arr.push_back(temp->val);
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    if(arr.empty())
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for(int i = 1; i < arr.size(); i++)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}
};