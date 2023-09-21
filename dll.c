#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
void printList(struct Node* list){
    printf("[ ");
    struct Node* temp = list;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }

    printf("]");
}
struct Node* arrayToList(int arr[],int len){
    if(len>0){
        struct Node* first;
        struct Node* next = NULL;
        struct Node* prev = NULL;
        struct Node* temp = (struct Node*) malloc(sizeof(struct Node));

        for(int i=0;i<len;i++){
            if(next==NULL){
                first = temp;
                temp->prev = NULL;
            }
            else{
                temp = next;
                temp->prev = prev;
            }

            temp->data = arr[i];
            
            if(i != len-1){
                next = (struct Node*) malloc(sizeof(struct Node));
                prev = temp;
                temp->next = next;
            }
            else{
                next=NULL;
            }
        }
        return first;
        
    }
    else{
        return NULL;
    }
}
void push(struct Node** list, int val){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *list;
    newNode->prev = NULL;
    (*list)->prev = newNode;
    (*list) = newNode;
    return;
}
void append(struct Node* list, int val){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next=NULL;

    struct Node* last = list;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newNode;
    newNode->prev = last;
    return;
}
int getLength(struct Node* list){
    int len= 0;
    struct Node* temp = list;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAt(struct Node** list, int val, int pos){
    int len = getLength(*list);
    if(pos<0 || pos >= len){
        printf("invalid pos variable passed in");
        return;
    }
    else if(pos==0){
        push(list,val);
    }
    else if(pos==len-1){
        append(*list,val);
    }
    else{
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        struct Node* before = *list;
        for(int i =0; i<pos-1;i++){
            before = before->next;
        }
        newNode->data = val;
        newNode->prev = before;
        newNode->next = before->next;
        before->next = newNode;
        newNode->next->prev = newNode;
    }
}
int main(){
    int myarray[5] = {2,4,6,8,10};
    struct Node* list =  arrayToList(myarray,5);
    insertAt(&list,3,1);
    printList(list);
    return 0;
}