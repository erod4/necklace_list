#include "Necklace.h"
#include <iostream>
using namespace std;

int Menu ();

void beads();
void appendNode(Necklace&, string[]);

void insertNode(Necklace&, string[]);

void deleteNode(Necklace&);

void printNode(Necklace&);

void searchNode(Necklace&, string[]);

void exitFunction ();

void error ();

int main() 
{
  Necklace Beads;
  string color[numColor]={"turquoise", "coral", "gold", "copper"};
  int option = 0;
  while (option != 6)
    {
      option = Menu ();
      switch (option)
	     {
	       case 1:
	        appendNode(Beads, color);
	         break;
	       case 2:
	         insertNode(Beads,color);
	         break;
         case 3:
	         deleteNode(Beads);
	         break;
         case 4:
	         printNode(Beads);
	         break;
         case 5:
	         searchNode(Beads,color);
	         break;
	       case 6:
	         exitFunction ();
	       default:
	         error ();
	         break;

	}

    }
  
}
int Menu ()
{
  
  string title = "\nNecklace Creator\n";
  int option = 0;
  cout<<title<<endl;
  cout << "1. Append" << endl;
  cout << "2. Insert" << endl;
  cout << "3. Delete" << endl;
  cout << "4. Print" << endl;
  cout << "5. Search" << endl;
  cout << "6. Exit" << endl;

  
  cout << "Please Enter an Option (1-6) and hit return: ";
  cin >> option;
  return option;
}
void appendNode(Necklace &Beads,string color[])
{
  bool match=false;
  string beadColor;

  while (!match) {
  cout << "Please enter one of the following color options and hit return: turquoise, coral, gold, copper" << endl;
  cout << "Choice: ";
  cin >> beadColor;
  cin.ignore();

  for (int i = 0; i < numColor; i++) 
  {
    if (color[i] == beadColor) 
    {
      match = true;
      break;
    }
  }

  if (!match) {
    cout << "Sorry, incorrect bead color option. Please try again." << endl;
  }
}
    Beads.appendNode(beadColor);
  
}

void insertNode(Necklace &Beads,string color[])
{
bool match = false;
string beadColor;
int location;

while (!match) {
  cout << "Please enter one of the following color options and hit return: turquoise, coral, gold, copper" << endl;
  cout << "Choice: ";
  cin >> beadColor;
  cin.ignore();

  for (int i = 0; i < numColor; i++) 
  {
    if (color[i] == beadColor) 
    {
      match = true;
      break;
    }
  }

  if (!match) {
    cout << "Sorry, incorrect bead color option. Please try again." << endl;
  }
}

cout << "Please enter the location where you would like your bead placed" << endl;
cout << "Location: ";
cin >> location;


if(Beads.insertNode(beadColor, location)==-1)
{
  cout<<"\nError. No location found.\n";
}
  else 
  {
    cout<<"\nBead succesfully added.\n";
  }
    
}
void deleteNode(Necklace &Beads)
{
  
  int location;
  Beads.print();
  cout<<"Please select the location of the bead you would like deleted\n";
  cout<<"Location: ";
  cin>>location;
  
  if(Beads.deleteNode(location)==-1)
  {
    cout<<"\nError. No bead exists in this position.\n";
  }
  else 
  {
    cout<<"\nBead succesfully deleted\n";
  }
}

void printNode(Necklace &Beads)
{
  Beads.print();
}

void searchNode(Necklace &Beads, string color[])
{
  string beadColor;
  bool match=false;
  cout<<"Please enter bead color you would like found\n";
  cout<<"Choice: ";
  cin>>beadColor;
  cin.ignore();

  for(int i=0;i<numColor;i++)
    {
      if(color[i]==beadColor)
      {
        match=true;
      }
    }
  if(match==true)
  {
    cout<<"1\n";
    Beads.search(beadColor);
  }
  else
  {
   cout<<"Sorry, incorrect bead color option. Please try again."<<endl;
  }
}

void exitFunction ()
{
  cout << "\nExiting...\n";

  exit (0);
}

void error ()
{
  cout << "\nSorry, incorrect option. Please, try again.\n\n";
  
}
