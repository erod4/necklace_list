#include "Necklace.h"

void Necklace::appendNode(string mat)//end of list
{
  //Validation
  string color[numColor]={"turquoise", "coral", "gold", "copper"};
  bool match=false;
  
  for(int i=0;i<numColor;i++)
    {
      if(color[i]==mat)
      {
        match=true;
      }
    }

if(match==false)
{
  exit(EXIT_FAILURE);
}
  
else
{
  Node *newNode;//new node
  Node *nodePtr;//traverses

  newNode= new Node;//create a node
  newNode->material=mat;//assign metal
  
  newNode->next=nullptr;//since new node is going at the end it points to null
  if(!head)//if there are no nodes make new node head node
  {
    newNode->num=newNode->num++;
    head=newNode;
    cout<<"\nBead succesfully added!\n";
  }
  else//if nodes exist traverse to end and add new node
  {
   nodePtr=head;
    while(nodePtr->next)
      {
        nodePtr=nodePtr->next;
        
      }
    
    nodePtr->next=newNode;
    newNode->num=nodePtr->num+1;
    cout<<"\nBead succesfully added!\n";
  }
}
 
}

int Necklace::insertNode(string mat, int n)
{
  //Validation
  string color[numColor]={"turquoise", "coral", "gold", "copper"};
  bool match=false;
  
  for(int i=0;i<numColor;i++)
    {
      if(color[i]==mat)
      {
        match=true;
      }
    }

if(match==false)
{
  exit(EXIT_FAILURE);
}
  
  if (n < 0) {
    return -1; // Return an error code if the selected position is out of bounds
  }
  
  Node *prevNode = nullptr;
  Node *newNode = new Node; // Initialize newNode to nullptr
  Node *tempNode = head;


  
  newNode->material = mat;
  newNode->num = n;

  
  if (head == nullptr || n == 0)
  {
    newNode->next = head;
    head = newNode;
    
    // Update the num values of all nodes after the newly inserted node
    tempNode = head->next;
    while (tempNode != nullptr) {
      tempNode->num++;
      tempNode = tempNode->next;
    }
    
    return 0;
    
  }
  else if (n > head->num)
  {
    tempNode=head;//starts at head
    //cout<<endl<<tempNode->material<<endl;
    while (tempNode != nullptr && tempNode->num < n)//traverses through nodes until right before desired spot
    {
      prevNode = tempNode;//holds node before desired position
      tempNode = tempNode->next;//holds node after desired position
    }
 if (tempNode == nullptr)
    {
      return -1;
    }
    prevNode->next = newNode;//prev node points to newly added node
    newNode->next = tempNode;//newly added node points to node held after desired position
    
    // Update the num values of all nodes after the newly inserted node
    tempNode = newNode->next;
    while (tempNode != nullptr) {
      tempNode->num++;
      tempNode = tempNode->next;
    }

    return 0;
  }
  else 
  {
    
    return -1;
  }
}


int Necklace::deleteNode (int n)
{
  Node *currNode = head;
  Node *prevNode = nullptr;
  
  while (currNode != nullptr && currNode->num < n)
    {
      prevNode = currNode;
      currNode = currNode->next;
      
    }
  if (currNode == nullptr)
    {
      return -1;
    }
  else
    {
      if (prevNode == nullptr)
	{
	  head = head->next;
	  delete currNode;
	  
	}
      else
	{
	  prevNode->next = currNode->next;
	  delete currNode;
	}
	    // Renumber all nodes starting from the head node
    int i = 0;
    currNode = head;
    while (currNode != nullptr)
    {
        currNode->num = i;
        currNode = currNode->next;
        i++;
    }

    return 0;
    }
}


void Necklace::print() const
{
 Node *printNode;//traverses through nodes
 

 printNode=head;//starts at head node

while(printNode)//displays data for each node until it reaches null
  {
    cout<<"("<<printNode->num<<") "<<printNode->material<<endl;
    printNode=printNode->next;
  }



}

void Necklace::search(string mat)
{
  //validation
  string color[numColor]={"turquoise", "coral", "gold", "copper"};
  bool match=false;
  for(int i=0; i<numColor;i++)
    {
      if(color[i]==mat)
      {
        match=true;
      }
    }
  if(match==false)
  {
    exit(EXIT_FAILURE);
  }

  else
  {
    Node *currNode;//traverses node
  
    currNode=head;//starts at head node
    bool exists=false;

    while(currNode!=nullptr)//while traversing node doesn't reach end of list
    {
      if(currNode->material==mat)//if material of node matches what is being searched
      {
        exists=true;
        cout<<"\nBead can be found in position: "<<currNode->num<<endl;//show location of bead
        break;
      }
      else
      {
        cout<<"\nBead color does not exist yet\n"; 
        
      }
      currNode=currNode->next;
      
      
    }
  }
  
 
  
}
