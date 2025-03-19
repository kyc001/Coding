public class ArrayDeque<T> {
    private int initialCapacity = 8;
    private int capacity;
    private int eFactor = 2;
    private double usageFactor;
    private int mCapacity = 16;
    private double mRatio = 0.25;
    private int cFactor = 2;
    private T[] items;
    private int size;
    private int nextFirst;
    private int nextLast;

    public ArrayDeque() {
        capacity = initialCapacity;
        items = (T[]) new Object[initialCapacity];
        size = 0;
        nextFirst = 4;
        nextLast = 5;
    }

    private int oneMinus(int index) {
        if(index == 0) {
            index = capacity - 1;
        }
        else {
            index -= 1;
        }
        return index;
    }

    private int onePlus(int index) {
        if(index == capacity - 1) {
            index = 0;
        }
        else {
            index += 1;
        }
        return index;
    }

    private void resize(int newCapacity) {
        T[] a = (T[]) new Object[newCapacity];

        int currentFirst = onePlus(nextFirst);
        int currentLast = oneMinus(nextLast);

        if (currentFirst < currentLast) {
            int length = currentLast - currentFirst + 1;
            System.arraycopy(items, currentFirst, a, 0, length);
            nextFirst = newCapacity - 1;
            nextLast = length;
        } else {
            int firstRightCount = capacity - currentFirst;
            int firstLeftCount = capacity - firstRightCount;
            System.arraycopy(items, currentFirst, a, 0, firstRightCount);
            System.arraycopy(items, 0, a, firstRightCount, firstLeftCount);

            nextFirst = newCapacity - 1;
            nextLast = capacity;
        }

        capacity = newCapacity;
        items = a;

    }

    public void addFirst(T item) {
        items[nextFirst] = item;
        size += 1;
        nextFirst = oneMinus(nextFirst);

        if (size == capacity) {
            resize(size * eFactor);
        }
    }


    public void addLast(T item) {
        items[nextLast] = item;
        size += 1;
        nextLast = onePlus(nextLast);

        if (size == capacity) {
            resize(size * eFactor);
        }
    }

    public boolean isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }

    public int size() {
        return size;
    }

    public void printDeque() {
        if (isEmpty()) {
            return;
        }
        int index = onePlus(nextFirst);
        while (index != nextLast) {
            System.out.print(items[index] + " ");
            index = onePlus(index);
        }
    }

    private void contract() {
        usageFactor = (double) size / capacity;
        if (usageFactor <= mRatio && capacity >= mCapacity) {
            int newCapacity = capacity / cFactor;
            resize(newCapacity);
        }
    }


    public T removeFirst() {
        if (isEmpty()) {
            return null;
        }

        int currentFirst = onePlus(nextFirst);
        T currentFirstItem = items[currentFirst];
        nextFirst = currentFirst;
        items[nextFirst] = null;
        size -= 1;

        contract();

        return currentFirstItem;
    }


    public T removeLast() {
        if (isEmpty()) {
            return null;
        }

        int currentLast = oneMinus(nextLast);
        T currentLastItem = items[currentLast];
        nextLast = currentLast;
        items[nextLast] = null;
        size -= 1;

        return currentLastItem;
    }


    public T get(int index) {
        if (index >= size) {
            return null;
        }

        int indexFromFirst = nextFirst + 1 + index;
        if (indexFromFirst >= capacity) {
            indexFromFirst -= capacity;
        }

        return items[indexFromFirst];
    }
}