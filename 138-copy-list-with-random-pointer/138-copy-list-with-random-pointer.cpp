/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

	Node* copyRandomList(Node* head) {

		// copying
		Node * copiedHead = new Node(0);
		Node * copiedTemp = copiedHead;
		Node * original = head;
		while (original != NULL) {
			copiedTemp->next = new Node(original->val);
			original = original->next;
			copiedTemp = copiedTemp->next;
		}
		copiedHead = copiedHead->next;


		// Mapping original -> CopiedHead
		map<Node *, Node*> mp;
		original = head;
		copiedTemp = copiedHead;
		while (original != NULL) {
			mp[original] = copiedTemp;

			original = original->next;
			copiedTemp = copiedTemp->next;
		}
		// Pointing Random
		original = head;
		copiedTemp = copiedHead;
		while (original != NULL) {
			// node that is stored correspoding
			//to the random will be Copied's random
			Node * CopiedHeadRandom = mp[original->random];
			if (mp.count(original->random)) {
				copiedTemp->random = CopiedHeadRandom;
			} else copiedTemp->random = NULL;

			original = original->next;
			copiedTemp = copiedTemp->next;
		}
		return copiedHead;
	}
};