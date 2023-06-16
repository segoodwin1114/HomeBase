#include <stdio.h>
#include <stdlib.h>

typedef struct node {                     
    char letter;
    struct node *next;
} node;

// Returns number of nodes in the linkedList.
int length (node *head) {
    //initialize length to 0
    int length = 0;
    //while the head is not null we increment length by 1 and then move to next node
    while (head!=NULL) {                           
        length++;
        head = head->next;
    }    
    return length;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char *toCString (node *head) {
    int stringlength = length (head) + 1;                  
    int i = 0;
    char *cstring = calloc (stringlength, sizeof (char));

    while (head!=NULL) 
    {
        cstring [i++] = head->letter;                 
        head = head->next;
    }
    cstring [i] = '\0';                         
    return cstring;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar (node** pHead, char c) {
    //make tempnode 
    node *tempnode = calloc (1, sizeof (node)); 
          
    tempnode->letter = c;
    tempnode->next = NULL;           
    if (*pHead == NULL)                              
        *pHead = tempnode;      
    else 
    {
        node *ptr = *pHead;                        
        while (ptr->next) ptr = ptr->next;         
        ptr->next = tempnode;                     
    }
}

//deletes all nodes in the linked list 
void deleteList (node **pHead) {
    while (*pHead!=NULL) {                             
        node *temp = *pHead;
        *pHead = (*pHead)->next;
        free (temp);
    }
}

int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
        FILE* inFile = fopen("input.txt","r");
        fscanf(inFile, " %d\n", &numInputs);
        while (numInputs-- > 0)
        {
            fscanf(inFile, " %d\n", &strLen);
            for (i = 0; i < strLen; i++)
            {
                fscanf(inFile," %c", &c);
                insertChar(&head, c);
            }
            str = toCString(head);
            printf("String is : %s\n", str);
            free(str);
            deleteList(&head);
            if (head != NULL)
            {
                printf("deleteList is not correct!");
                break;
            }
        }
fclose(inFile);
}