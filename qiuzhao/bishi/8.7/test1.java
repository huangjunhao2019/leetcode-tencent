import java.util.*;

class ListNode {
    int val;
    ListNode next;

    ListNode() {
        val = 0;
        next = null;
    }

    ListNode(int _val) {
        val = _val;
        next = null;
    }

    ListNode(int _val, ListNode _next) {
        val = _val;
        next = _next;
    }
}

class LittleTrain {
    ListNode dummyHead;
    int size;
    int len;

    LittleTrain() {
        dummyHead = new ListNode(0);
        size = 0;
        len = 0;
    }

    LittleTrain(int _size) {
        dummyHead = new ListNode(0);
        size = _size;
        len = 0;
    }

    boolean insertFront(int val) {
        if (len >= size) {
            return false;
        }
        ListNode temp = new ListNode(val);
        temp.next = dummyHead.next;
        dummyHead.next = temp;
        len++;
        return true;
    }

    boolean insertLast(int val) {
        if (len >= size) {
            return false;
        }
        ListNode temp = new ListNode(val);
        ListNode ptr = dummyHead;
        while (ptr.next != null) {
            ptr = ptr.next;
        }
        ptr.next = temp;
        len++;
        return true;
    }

    boolean deleteFront() {
        if (len <= 0) {
            return false;
        }
        dummyHead.next = dummyHead.next.next;
        len--;
        return true;
    }

    boolean deleteLast() {
        if (len <= 0) {
            return false;
        }
        ListNode ptr = dummyHead;
        while (ptr.next.next != null) {
            ptr = ptr.next;
        }
        ptr.next = null;
        len--;
        return true;
    }

    int getFront() {
        if (len <= 0) {
            return -1;
        }
        return dummyHead.next.val;
    }

    int getRear() {
        if (len <= 0) {
            return -1;
        }
        ListNode ptr = dummyHead;
        while (ptr.next != null) {
            ptr = ptr.next;
        }
        return ptr.val;
    }

    boolean isEmpty() {
        return len == 0;
    }

    boolean isFull() {
        return len == size;
    }

    void printVal() {
        ListNode ptr = dummyHead.next;
        while (ptr != null) {
            System.out.print(ptr.val + " ");
            ptr = ptr.next;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();

        LittleTrain lt = new LittleTrain(3);
        lt.printVal();
        boolean b1 = lt.insertFront(a);
        lt.printVal();
        boolean b2 = lt.insertLast(b);
        lt.printVal();
        boolean b3 = lt.insertFront(c);
        lt.printVal();
        boolean b4 = lt.insertFront(d);
        lt.printVal();
        boolean b5 = lt.deleteFront();
        lt.printVal();
        boolean b7 = lt.deleteLast();
        lt.printVal();
        int b9 = lt.getFront();
        lt.printVal();
        int b10 = lt.getRear();
        lt.printVal();
        boolean b11 = lt.isEmpty();
        lt.printVal();
        boolean b12 = lt.isFull();
        lt.printVal();

        System.out.print(b1 + " " + b2 + " " + b3 + " " + b4 + " " + b5 + " " + b7 + " " + b9 + " ");
        System.out.println(b10 + " " + b11 + " " + b12);
    }
}