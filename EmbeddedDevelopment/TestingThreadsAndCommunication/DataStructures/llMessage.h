/*
 * llMessate.h
 *
 *  Created on: Nov. 23, 2019
 *      Author: Andres Rogelio Cordoba
 *		Email: ancor1369@gmail.com
 */


/*Definition of the functions to be used in the code*/

#include <string.h>
#include "ComQueue.h"

struct message_struct
{
    message_t message;
    struct message_struct *pNext;
};    
/*
 *  Name: node_t
 * Description:
 * This is the data structure to support a 
 * linked list for characters in the game.
 */
typedef struct message_struct do_message;


/*
 *  Name: addNodeE:
 *  Parameters:
 *  node_t* pHead, is a pointer to the head of the linked list
 *  data_struct  data, is the quantity of information of information required
 *  Description:
 *  This one is used to add one node once the 
 *  head exists, if the head has not been created, it is 
 *  better not to call this one. 
 * 
 */
message* addNode(message* pHead, character data);
/*
 * Name: CreateNode
 * Parameters:
 * None
 * Description:
 * This method is used to allocate the needed
 * resources for a new node on the heap. The node 
 * is exclusively of the type node_t. It returns a 
 * pointer to the created node.
 */
message* createNode(void);
/*
 * Name: CreateHead 
 * Parameters: an data_struct variable
 * Description:
 * Creates the space in the heap for the first 
 * node to be hosted, it attatches the information
 * passed as parameter. this method is intended to 
 * be called once per linked list to be created.
 */
message* createHead(character data);

void printNodes(message *pHead);
/*
 * Name:deleteNode
 * Parameters:
 * node_t * pHead: Pointer to the head of the linked list
 * character targed: Node with the information of the character
 * to be eliminated from the linked list
 * Description: The method goes
 */
void deleteNode(message * pHead,uint8_t target);
/*
 * Name: getNode
 * Parameters: node_t pHead
 * Description:
 * Retrieves the pointer of the target data that is passed to the
 * function.
 */
message* getNode(message* pHead, uint8_t target);
    


