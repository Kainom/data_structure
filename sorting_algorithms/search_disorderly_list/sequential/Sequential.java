package search_ordered_list.sequential;

import java.util.Random;

public class Sequential {
    private static final int SIZE = 20000;
    private int[] list = new int[SIZE];
    private Random random;

    public void randomArray() {
        random = new Random();
        for (int i = 0; i < SIZE; i++) {
            list[i] = random.nextInt(SIZE);
        }
    }

    public static void main(String[] args) {
        Sequential sequential = new Sequential();
        InnerSequential innerSequential = sequential.new InnerSequential();
        sequential.randomArray();
        int value;
        // value = innerSequential.search(542, 0); // i don't know,but the recursive method crash in some moments,then,the second is most safe
        // In my research,i come  to the conclusion.Maybe the java doesn't handle many calls
        // to the stack and cause a stack overflow.
        // In this case, you can use the non-recursive method.
        // Example: value = innerSequential.searchNoRecursive(0, 542);

        value = innerSequential.searchNoRecursive(0, 542);

        if (value == -1) {
            System.out.println("Value not found.");
        } else {
            System.out.println("Value found at index: " + value);
        }
    }

    private class InnerSequential {

        public InnerSequential() {

        }

        public int search(int key, int i) {
            if (i >= SIZE)
                return -1;

            if (list[i] == key) {
                return i;
            }
            return search(key, (++i));

        }

        public int searchNoRecursive(int x, int key) {
            for (; x < list.length; x++) {
                if (x == list[key]) {
                    return x;
                }
            }
            return -1;
        }

    }
}
