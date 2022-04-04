/*Implement following operations on Stack using Linked List. Handle two more operations as well... Splitting of Stack in which the formed stack will be split into two stacks each of length p and q in which p + q = n...
Given two stacks p and q, combine the two split stacks into the original stack...*/
#include <iostream>
using namespace std;
class Node              // Node class for defining attributes of the Node data type
{
    public:     // Data members
    int data;
    Node* next;
    public: 
    Node (int value)    // Parametrized constructor
    {
        data = value; next = NULL;
    }
};
class Stack       // Stack class created for Implementation of Stack Data Structure
{
    public:
    Node* top;
    public:
    Stack ()    // deafult Constructor
    {
        top = NULL;
    }
    void Push(int value)     // Adding the element at the Top of the Stack
    {
        Node* n = new Node(value);   // Addition of Nodes is done from the Left side of the Stack
        if(top == NULL)
        {
            top = n;
            return;
        }
        n -> next = top;   // Top pointer reference updated
        top = n;
    }
    int Pop()   // Removing the Top most Node from the Stack
    {
        if(top == NULL)
        {
            cout << "The Stack is now Empty, so nothing can be popped Out !!" << endl;
            return -1;
        }
        Node* temp = top;
        top = temp -> next;
        return temp -> data;
    }
    void DisplayStack()   // Displaying all Nodes of Stack.. O(n) time
    {
        Node* temp = top;
        int iter = 1;             // Counter variable
        if(temp -> next == NULL)         // If there is only one Node in Stack
        {
            cout << temp -> data << " ---> Top" << endl;
            return;          // Control moving out of the function
        }
        for( ; temp -> next != NULL; temp = temp -> next, iter++)
        {
            if(iter == 1)          // Conditional statement for proper printing of Nodes
                cout << temp -> data << " ---> Top" << endl;
            if(iter != 1)          // Conditional statement for proper printing of Nodes
            {
                cout << "^" << endl;
                cout << temp -> data << endl;
            }
        }
        cout << "^" << endl;
        cout << temp -> data << " ---> Base" << endl;
    }
    int SizeOfStack()    // Evaluating Size of Stack by top pointer.. O(n) time
    {
        Node* temp = top;
        int iter = 0;
        for( ; temp -> next != NULL; temp = temp -> next, iter++);   // Traversing loop
        cout << "The Size of the Stack currently is : " << iter+1 << endl;
        return iter+1;
    }
};
int main()
{
    Stack basicStack, stack1, stack2;   // Objects creation of Stack class
    int x, s, size;
    cout << "Enter total values to be entered in the Primary Stack : ";
    cin >> s;
    for(int i = 0; i < s; i++)   // Adding elements
    {
        cout << "Enter the Value to be Stored in the Stack : ";
        cin >> x;
        basicStack.Push(x);         // Adding elements to the basic Stack
        basicStack.DisplayStack();
    }
    cout << "Enter the Breakpoint of the Stack created : ";   
    cin >> s;    // Entering the breakpoint, where to divide the Stack in two
    size = basicStack.SizeOfStack();     // Calculating size of the Stack
    for(int i = 0; i < size; i++)
    {
        x = basicStack.Pop();    // Popping the element of the primary Stack Iteratively
        if(i < s)
            stack1.Push(x);  // Adding to 1st Stack until the breakpoint is reached
        else
            stack2.Push(x);  // Adding to 2nd Stack after the breakpoint is reached
    }
    cout << "The First Stack created after Breakpoint is : " << endl;
    stack1.DisplayStack();   // Displaying the First Stack
    cout << "The Second Stack created after Breakpoint is : " << endl;
    stack2.DisplayStack();   // Displaying the Second Stack
    for(int i = 0; i < size; i++)   // Iterating through the size of the Primary Stack,
    {                               // since we will be creating the Original Stack
        if(i < size - s)
            x = stack2.Pop();   // We will add the Elements of the Second Stack first
        else
            x = stack1.Pop();   // We will add the Elements of Firs Stack later
        basicStack.Push(x);             // Adding the Elements to the Primary Stack as per the decision
    }
    cout << "Generating the Original Stack after combining the two Broken Stacks : " << endl;
    basicStack.DisplayStack();    // Displaying the Original Stack after combining the Two Stacks
    return 0;        // End of the Program
}