
class Node {
    String name;
    int score;
    Node prev;
    Node next;

    public Node(String name, int score) {
        this.name = name;
        this.score = score;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList {
    Node head;
    Node tail;

    public DoublyLinkedList() {
        head = null;
        tail = null;
    }

    public void insert(String name, int score) {
        Node newNode = new Node(name, score);
        if (head == null) {
            head = newNode;
            tail = newNode;
        } else {
            Node current = head;
            while (current != null && current.score < score) {
                current = current.next;
            }
            if (current == null) {
                tail.next = newNode;
                newNode.prev = tail;
                tail = newNode;
            } else if (current == head) {
                newNode.next = head;
                head.prev = newNode;
                head = newNode;
            } else {
                newNode.next = current;
                newNode.prev = current.prev;
                current.prev.next = newNode;
                current.prev = newNode;
            }
        }
    }

    public void printList() {
        Node current = head;
        // while (current != null) {
        // System.out.println(current.name + ": " + current.score);
        // current = current.next;
        // }
        for (int i = 0; i < 10; i++) {
            System.out.println(current.name + ": " + current.score);
            current = current.next;
        }
    }
}

class Doubly {
    public static void main(String[] args) {
        DoublyLinkedList list = new DoublyLinkedList();

        // Insert student data into the list
        list.insert("John", 80);
        list.insert("Jane", 90);
        list.insert("Bob", 75);
        list.insert("Mary", 85);
        list.insert("Do", 99);
        list.insert("fluk", 96);
        list.insert("Poom", 45);
        list.insert("Folk", 67);
        list.insert("luv", 87);
        list.insert("tae", 63);
        list.insert("Bell", 10);

        // Sort and print the list
        System.out.println("Sorted student scores: ");
        list.printList();
    }
}