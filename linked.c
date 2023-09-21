#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node* firstNode){
    struct Node* temp;
    temp = firstNode;
    printf("[ ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("]");
}

struct Node* arrayToList(int arr[],int length){
    if(length > 0){
        struct Node* next = NULL;
        struct Node* first= NULL;

        for(int i = 0; i<length; i++){
            struct Node* temp;
            if(next == NULL){
                temp = (struct Node*) malloc(sizeof(struct Node));
                first = temp;
            }
            else{
                temp = next;
            }

            temp->data = arr[i];

            if(i!=length-1){
                next = (struct Node*) malloc(sizeof(struct Node));
                temp->next = next;
            }
            else{
                next = NULL;
            }
        }
        return first;
    }
    else{
        return NULL;
    }
}

int getLength(struct Node* list){
    int len = 0;
    struct Node* temp = list;

    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void push(struct Node** list, int val){
    struct Node* newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->next = *list;
    newNode->data = val;

    *list=newNode;

    return;
}
void append(struct Node* list, int val){
    struct Node* last = list;
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    while(last->next!=NULL){
        last = last->next;
    }
    newNode->data = val;
    newNode->next=NULL;
    last->next=newNode;
    return;
}

void insertAt(struct Node** list, int val, int pos){
    int length = getLength(*list);
    if(pos<0 || pos>=length){
        printf("invalid input for 'pos' variable");
    }
    if(pos==0){
        push(list,val);
    }
    if(pos==length-1){
        append(*list,val);
    }
    else{
        //in between
        struct Node* prev = *list;
        for(int i=0;i<pos-1;i++){
            prev = prev->next;
        }
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = prev->next;
        prev->next = newNode;
    }
    
}

int main(){

    int myArray[6] = {1,2,3,4,5,6};

    struct Node* linkedList = arrayToList(myArray,sizeof(myArray) / sizeof(int));

    insertAt(&linkedList,2,3);
    printList(linkedList);

    return 0;
}