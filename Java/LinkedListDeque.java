public class LinkedListDeque<T> {
    private class LinkedNode {
        private LinkedNode prev;
        private T item;
        private LinkedNode next;
    
        public LinkedNode(LinkedNode p, T i, LinkedNode n) {

            prev = p;
            item = i;
            next = n;
        }
    }
    private LinkedNode sentinel;
    private int size;

    public LinkedListDeque() {
        sentinel = new LinkedNode(null, null, null);
        sentinel.prev = sentinel;
        sentinel.next = sentinel;
        size = 0;
    }

    public void addFirst(T item) {
        LinkedNode first = new LinkedNode(sentinel, item, sentinel.next);
        sentinel.next.prev = first;
        sentinel.next = first;
        size += 1;
    }

    public void addLast(T item) {
        LinkedNode last = new LinkedNode(sentinel.prev, item, sentinel);
        sentinel.prev.next = last;
        sentinel.prev = last;
        size += 1;
    }

    public boolean isEmpty() {
        if(sentinel.next == sentinel) {
            return true;
        }
        return false;
    }

    public int size() {
        return size;
    }

    public void printDeque() {
        LinkedNode p = sentinel;
        while(p.next != sentinel) {
            System.out.println(p.next.item + " ");
            p = p.next;
        }
    }

    public T removeFirst() {
        if(isEmpty()) {
            return null;
        }
        T firstItem = sentinel.next.item;
        sentinel.next.next.prev = sentinel;
        sentinel.next = sentinel.next.next;
        size -= 1;
        return firstItem;
    }

    public T removeLast() {
        if(isEmpty()) {
            return null;
        }
        T lastItem = sentinel.prev.item;
        sentinel.prev.prev.next = sentinel;
        sentinel.prev = sentinel.prev.prev;
        size -= 1;
        return lastItem;
    }

    public T get(int index) {
        if(index > size - 1) {
            return null;
        }

        LinkedNode p = sentinel.next;
        int  i = 0;
        while(i != index) {
            p = p.next;
            i += 1;
        }
        return p.item;
    }

    private T getRecursionHelper(LinkedNode currentNode, int index) {
        if(index == 0) {
            return currentNode.item;
        }
        return getRecursionHelper(currentNode.next, index - 1);
    }
    public T getRecursive(int index) {
        if(index > size - 1) {
            return null;
        }
        return getRecursionHelper(sentinel.next, index);
    }
}