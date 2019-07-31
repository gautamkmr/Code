#include <iostream>
#include <unordered_map>
using namespace std;



struct Node
{
   int val;
   struct Node *next;
   struct Node *prev;
};


unordered_map<string, struct Node*> mp;
int capacity;
int len;
struct Node *head, *tail;

void addFront(struct Node **t)
{
  Node *tmp = (*t);
  if(!head)
  {
     head = tail = tmp;
     head->prev = tmp;
     head->next = NULL;
     tail->next = head;
     tail->prev = NULL;
  }
  else
  {
    head->next = tmp;
    tmp->prev = head;
    head = tmp;
  }
}

void removeTail()
{
   if(head == tail)
   {
     delete(tail);
     head = tail = NULL;
   }
   else
   {
     struct Node *t = tail;
     tail = tail->next;
     tail->prev = NULL;
     delete(t);
   }
}

void bringFront(struct Node **tmp)
{
  struct Node *t = (*tmp);
   if(t==head)
    return;
  
   if(t==tail)
   {
      tail = tail->next;
      tail->prev = NULL;
      
      head->next = t;
      t->prev = head;
      head = t;
   }
   else
   {
      t->prev->next = t->next;
      t->next->prev = t->prev;
      addFront(&t);
   } 
     
}

void put(string key, int val)
{
   struct Node *tmp = new Node;
   tmp->val = val;
   mp[key] = tmp; 
  
   if(len<capacity)
   {
      addFront(&tmp);
      len++;
   }
  else //len==capacity
  {
    removeTail();
    addFront(&tmp);
  }
}

int get(string key)
{
   if(mp.find(key) == mp.end())
   {
     cout<<"Error case";
     return -1;
   }
   struct Node* tmp = mp[key];
   int ret = tmp->val;
   bringFront(&tmp);
   return ret; 
}

// To execute C++, please define "int main()"
int main() {
   capacity=3;
   len = 0;
   head=tail = NULL;
   put("adam", 1);
   cout<<get("adam")<<"\n";
   return 0;
}





/* 
Your previous Plain Text content is preserved below:

# Create a hashmap dict based LRU (least recently used) cache with size of N elements. 
Pretend you are a library developer. You should make a class so other developers can use your code. I’ve only used string keys and integer values for simplicity.

# Example: if N = 3

# put("adam", 1)  # number of beans
# put("jack", 2)
# put("mary", 8)
# get("adam") # returns 1
# put("jane", 11) - Evict jack
# get("jane") - Returns 11
# put("containerstore", 11) - Evict mary

# Add a full cache print after each operation so we can see the internal state of the cache.

 */
