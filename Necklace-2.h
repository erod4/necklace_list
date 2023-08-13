//Enrique Rodriguez
//Chapter 18
//04/05/2022



#ifndef NECKLACE_H
#define NECKLACE_H
#include <iostream>
#include <string>
using namespace std;
const int numColor=4;
class Necklace
{
private:
  struct Node
{
  string material;//stores bead material
  int num=0;//stores location
  struct Node *next; //points to next node
};

Node *head; //points to head
public:

  Necklace(){head=nullptr;}//constructor

 

  void appendNode(string);
  int insertNode(string, int);
  int deleteNode(int);
  void print() const;
  void search(string);

};


#endif
