Selection Sort code

void printArray(int arr[], int n) {
    // Just printing the array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 2, 4, 6, 5, 8, 9, 10, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    printArray(arr, size);

    selectionSort(arr, size);

    cout << "After Sorting: ";
    printArray(arr, size);

    return 0;
}

OUTPUT - 
Before Sorting: 1 3 2 4 6 5 8 9 10 7
After Sorting:  1 2 3 4 5 6 7 8 9 10


xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

🔢 Sorting Algorithms Complexity Table
Sorting Algorithm	Best Case Time	Average Case Time	Worst Case Time	Space Used
Bubble Sort	O(n)	O(n²)	O(n²)	O(1)
Selection Sort	O(n²)	O(n²)	O(n²)	O(1)
Insertion Sort	O(n)	O(n²)	O(n²)	O(1)
Merge Sort	O(n log n)	O(n log n)	O(n log n)	O(n)
Quick Sort	O(n log n)	O(n log n)	O(n²)	O(log n)*
Heap Sort	O(n log n)	O(n log n)	O(n log n)	O(1)
Counting Sort	O(n + k)	O(n + k)	O(n + k)	O(k)
Radix Sort	O(nk)	O(nk)	O(nk)	O(n + k)
Bucket Sort	O(n + k)	O(n + k)	O(n²)	O(n)
Tim Sort (used in Python/Java)	O(n)	O(n log n)	O(n log n)	O(n)

📝 Note:

n = number of elements in the array

k = range of input values (for counting/radix sort)

* Quick sort uses O(log n) space because of recursive function calls.

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

insertion sort 
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    // Step 1: Start from the second element (index 1) because the first one is already "sorted"
    for (int i = 1; i < n; i++) {
        int current = arr[i];      // Step 2: Pick up the current element
        int j = i - 1;             // Step 3: Compare it with the left elements

        // Step 4: Move the larger elements one step to the right
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];   // Shift the larger number to the right
            j--;                   // Move one step to the left
        }

        // Step 5: Place the current element at its correct position
        arr[j + 1] = current;
    }
}

int main() {
    int arr[] = {9, 5, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    insertionSort(arr, n); // Call the sorting function

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

Bubble Sort?

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    // Outer loop for passes
    for (int i = 0; i < n - 1; i++) {
        // Inner loop for each comparison in this pass
        for (int j = 0; j < n - i - 1; j++) {
            // If the left element is bigger than the right one, swap them
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "After sorting: ";
    printArray(arr, n);

    return 0;
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

binary search

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // If key is found at mid
        if (arr[mid] == key) {
            return mid;  // return index
        }
        // If key is greater, ignore left half
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        // If key is smaller, ignore right half
        else {
            high = mid - 1;
        }
    }

    // Key not found
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};  // sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int result = binarySearch(arr, size, key);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

#include <iostream>
using namespace std;

#define SIZE 100  // max size of queue

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue = Add element at rear
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue is Full! Cannot enqueue.\n";
            return;
        }

        if (front == -1) front = 0;  // First element

        rear++;
        arr[rear] = value;
        cout << value << " added to the queue.\n";
    }

    // Dequeue = Remove element from front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! Cannot dequeue.\n";
            return;
        }

        cout << arr[front] << " removed from the queue.\n";
        front++;

        if (front > rear) {  // Queue became empty
            front = rear = -1;
        }
    }

    // Peek = See front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty! Nothing to peek.\n";
        } else {
            cout << "Front of the queue is: " << arr[front] << endl;
        }
    }

    // isEmpty = check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Size = number of elements
    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.peek();       // Shows front element
    q.dequeue();    // Removes 10
    q.peek();       // Shows new front (20)

    cout << "Queue size is: " << q.size() << endl;

    return 0;
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

#include <iostream>
using namespace std;

#define SIZE 100  // max size of queue

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue = Add element at rear
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue is Full! Cannot enqueue.\n";
            return;
        }

        if (front == -1) front = 0;  // First element

        rear++;
        arr[rear] = value;
        cout << value << " added to the queue.\n";
    }

    // Dequeue = Remove element from front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! Cannot dequeue.\n";
            return;
        }

        cout << arr[front] << " removed from the queue.\n";
        front++;

        if (front > rear) {  // Queue became empty
            front = rear = -1;
        }
    }

    // Peek = See front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty! Nothing to peek.\n";
        } else {
            cout << "Front of the queue is: " << arr[front] << endl;
        }
    }

    // isEmpty = check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Size = number of elements
    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.peek();       // Shows front element
    q.dequeue();    // Removes 10
    q.peek();       // Shows new front (20)

    cout << "Queue size is: " << q.size() << endl;

    return 0;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
stack

public class StackArray {
    int maxSize;       // Maximum size of the stack
    int top;           // Index of the top element
    int[] stackArray;  // Array to store stack elements

    // Constructor to initialize stack
    StackArray(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1; // Stack is empty initially
    }

    // ✔️ Push operation
    void push(int value) {
        if (isFull()) {
            System.out.println("Stack Overflow! Cannot push " + value);
        } else {
            stackArray[++top] = value;
            System.out.println("Pushed: " + value);
        }
    }

    // ✔️ Pop operation
    int pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow! Cannot pop.");
            return -1;
        } else {
            int poppedValue = stackArray[top--];
            System.out.println("Popped: " + poppedValue);
            return poppedValue;
        }
    }

    // ✔️ Peek operation
    int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty. No top element.");
            return -1;
        } else {
            return stackArray[top];
        }
    }

    // ✔️ isEmpty operation
    boolean isEmpty() {
        return top == -1;
    }

    // ✔️ isFull operation
    boolean isFull() {
        return top == maxSize - 1;
    }

    // ✔️ Display stack elements
    void display() {
        if (isEmpty()) {
            System.out.println("Stack is empty.");
        } else {
            System.out.print("Stack elements (top to bottom): ");
            for (int i = top; i >= 0; i--) {
                System.out.print(stackArray[i] + " ");
            }
            System.out.println();
        }
    }

    // ✅ Main method to test stack operations
    public static void main(String[] args) {
        StackArray stack = new StackArray(5);

        stack.push(10);
        stack.push(20);
        stack.push(30);

        stack.display();

        stack.pop();

        System.out.println("Top element is: " + stack.peek());

        stack.display();

        stack.pop();
        stack.pop();
        stack.pop(); // Underflow
    }
}

