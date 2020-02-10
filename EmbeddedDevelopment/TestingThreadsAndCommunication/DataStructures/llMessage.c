/*
 * llMessate.c
 *
 *  Created on: Nov. 23, 2019
 *      Author: Andres Rogelio Cordoba
 *		Email: ancor1369@gmail.com
 */

#include <DataStructures/llMessage.h>
#include <stdlib.h>

do_message* addNode(do_message* pHead, message_t data)
{
    //Create new node
    do_message *pNode = createNode();
    pNode->message = data;

    //Find the attatchement point for the new node
    //to be inserted
    
    size_t counter = 1;

    do_message *pw = NULL; //working pointer
    pw = pHead;    
    while(pw->pNext != NULL)
    {
        counter += 1;
        pw = pw->pNext;
    }    
    pw->pNext = pNode;
    //Make all the ids equal to zero, I will manage this in a different way
    pw->pNext->message.objectID = counter;
    //Auto assing a counter to the object ID


    return pNode;
}

do_message* createHead(message_t data)
{
    //creates the head of the whole linked list
    do_message *pHead = createNode();
    pHead->message = data;
    return pHead;
}

do_message* createNode(void)
{
    //Creates a dynamic space of memory to hold the new node
    do_message* pNew = (do_message*)malloc(sizeof(do_message));
    pNew->pNext = NULL;
    return pNew;
}

void deleteNode(do_message* pHead, uint8_t target)
{
    do_message* pw= pHead; //Working pointer
    do_message* ppw=pHead; //Working parent's pointer
    
    while((pw->message.objectID != target))
    {
        ppw=pw;
        pw=pw->pNext;
    }    
    if((pw->pNext)!= NULL)    
    {
        do_message *pSave = pw->pNext;
        free((void*)pw);
        ppw->pNext = pSave;
    }
    else
    {
        printf("Node not found\n");
    }
}

void printNodes(do_message *pHead)
{

}

do_message* getNode(do_message* pHead, uint8_t target)
{
    do_message* pw = NULL; //Worker pointer
    pw = pHead;
    
    while(pw->message.objectID != target)
    {
        pw = pHead->pNext;
    }
    //Making sure the selected target is the one we are seeking
    if(pw->message.objectID == target)
    {
        return pw;
    }
    //It it is not, just return a null pointer.
    else
    {
        return NULL;
    }
}

size_t getLastNode(do_message* pHead)
{
    do_message* pw = NULL;
    pw = pHead;

    while(pw->pNext != NULL)
    {
        pw = pHead->pNext;
    }
    //Making sure we are talking about the the last node.
    if(pw->pNext == NULL)
    {
        return pw->message.objectID;
    }
}

