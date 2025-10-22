#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node *newNode = new Node;
  newNode->s = new Student(s);
  newNode->next = NULL;

  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

std::string StudentRoll::toString() const {
  if (head == nullptr) {
    return "[]";
  }
  std::string result = "[";
  Node *current = head;

  while (current != nullptr) {
    result += current->s->toString();

    if (current->next != nullptr) {
      result += ",";
    }
    current = current->next;
  }
  result += "]";
  return result;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL;
  Node *current = orig.head; 
  while (current != nullptr) {
    this->insertAtTail(*(current->s));
    current = current->next; 
  }
}

StudentRoll::~StudentRoll() {
  Node *current = head;
  while(current != nullptr) {
    Node *toDelete = current;
    current = current->next;
    delete toDelete->s;
    delete toDelete;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  Node *curr = head;
  while (curr != nullptr) {
    Node *nextNode = curr->next;
    delete curr;
    curr = nextNode;
  }
  head = nullptr;
  tail = nullptr;

  Node *rCurr = right.head;
  while (rCurr != nullptr) {
    
    insertAtTail(*(rCurr->s));
    rCurr = rCurr->next;
  }


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





