/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        // deep copy of the linked list
        // val
        // next pointer
        // random pointer
        if (head == null) return null;
        
        HashMap<Node, Node> oldToNew = new HashMap<>();
        oldToNew.put(null, null);
        Node curr = head;
        // first pass to create new nodes from original linked list
        while (curr != null) {
            Node copyNode = new Node(curr.val);
            oldToNew.put(curr, copyNode);
            curr = curr.next;
        }

        // second pass to copy the pointer from original linked list onto copy linked list
        curr = head;
        while (curr != null) {
            Node copyNode = oldToNew.get(curr);
            copyNode.next = oldToNew.get(curr.next);
            copyNode.random = oldToNew.get(curr.random);
            curr = curr.next;
        }
        return oldToNew.get(head);

    }
}
