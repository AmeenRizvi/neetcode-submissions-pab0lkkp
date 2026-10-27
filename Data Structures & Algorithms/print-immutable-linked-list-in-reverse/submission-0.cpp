/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        ImmutableListNode *curr = head;
        stack<ImmutableListNode*>st;

        while(curr)
        {
            st.push(curr);
            curr = curr->getNext();
        }

        while(!st.empty())
        {
            ImmutableListNode *node = st.top();
            st.pop();

            node->printValue();
        }
    }
};
