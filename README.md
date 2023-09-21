# Linked-List-C

I've implemented Linked List data structure all by myself in C, this is one of the first steps I take in my Embedded programming journey.

## What Are Linked Lists?
A linked list is a linear data structure that allows you to freely allocate data in discrete parts of the memory.

Unlike Arrays, data in a linked list isn't stored in the memory in a contigious fashion.
Rather, every element in a linked list is allocated in independant parts of the memory and linked to each other with pointers. 

Every element in a linked list is called a "Node" a node has 2 data fields, one for storing actual values and one for storing pointers that point to the location of the next node in the memory. This chain-like structure allows us to do perform some actions with less complexity than other data structures.

![image](https://github.com/kirki58/Linked-List-C/assets/129191293/8f6a1d52-bc3c-4328-bd04-a445fa824e87)

## My Implementation
Since this is a very basic project for educational purposes, My implementation is really not much different than a regular linked list implementation in C.

### Node Structure
First of, we need something to represent the elements in our list specifically, "Nodes". I've mentioned Nodes have 2 data fields, first one is for storing the actual data, I've called this struct field "data" and it is of type integer.

Then we have the field "next" that is a Node struct pointer that points to the next node in the list.

### void printList(`struct Node* firstNode`)
This function prints the whole linked list into the console. First of, we take Node pointer parameter, this is the first Node in our list which is usually called the "Head" this Node usually represents our whole list while working with functions.

In this function we've created a local variable of type Node pointer called "temp", and in the while loop we are printing out temp's data field, then assigning temp again to temp->next so the loop can continue on. Since the very last Node in a linked list points to a null pointer (NULL) we can say that the linked list is over when we stumble upon a NULL pointer which also ends the loop.

### struct Node* arrayToList(`int arr[],int length`)
this function is rather more complex, as you can understand from it's name this function converts arrays (built-in in C) into Linked List structures that we created.

Firmly, how it works is we take an array and it's length as parameters (there is really no way to calculate the length of an array passed as a parameter to a function.). And continue on if the length parameter passed is greater than 0 to ensure it is valid and avoid exceptions. We, again have 2 local variables called "first" and "next" which are both Node pointers. The reason that we seperate the two is, we need to keep track of which node is the first node since we are going to return it at the end of the function so we can access the list after we created it.

We have a for loop that is going from 0 to length. In the first iteration (runs only when next is still NULL indicating it is the first iteration) we assign first as temp then go on and set temp's data field, then since it is not the last iteration we create a new node and set it as the next node of temp. In the other iterations next will not be null and temp is going to be assigned as "next" from the previous iteration.

We go on until the last iteration, last iteration is basically the same as others except that we need to assign it's next value as NULL as it is in the logic of Linked Lists.

We return the first node in the end, as a starting point for traversing the linked list.

### int getLength(`struct Node* list`)
This is a basic function that return the length of the linked list it takes as a parameter.

We do it with a simple while loop traversing our linked list, with every iteration the value of "len" is increased by 1 and it is returned at the end of the function.

### void push(`struct Node** list, int val`)
This function is for inserting a node at the beginning of a list.

We create a new node, set it's next as the first node in our list, and data as "val" than make it the "head pointer" of our list.

### void append(`struct Node* list, int val`)
This function is for inserting a node at the end of a list.

We traverse the whole list to find the last node in it, we create a new node, set it's next as NULL and data as the value passed in, we connect the new node with updating the last node in the list's next pointer from NULL to the new node we created.

### void insertAt(`struct Node** list, int val, int pos`)
This function is for inserting a node at any position in a list.

We separate the function with conditions. If the request is to insert at the beginning we simply use push function we created, if it is to insert at the end of the list we similiarly use the append function.

However we still need to create functionality if the request is to insert in between. First we find the node that is right before the position we want to insert a new node at. We do that with a for loop that is going from 0 to pos-1 which initally makes the prev pointer to point to the node we want. After that we just create a new node, set it's data field as the value passed in, and the next field to prev's next node, lastly we update prev's next to point to the new node we created.

## Sources
So, that's basically how to implement linked lists in C. I really enjoyed making this little project and learnt about data structures a lot. If you're viewing this repository you are probably a new-learner for data structures too, below I left you some free sources that you can learn about them too.

- [Linked List GFG Article](https://www.geeksforgeeks.org/data-structures/linked-list/)
- [Data Structures freeCodeCamp](https://www.geeksforgeeks.org/data-structures/linked-list/)
- [Insertion In a Linked List](https://www.geeksforgeeks.org/insertion-in-linked-list/)
- [Programiz Linked List Article](https://www.programiz.com/dsa/linked-list)




