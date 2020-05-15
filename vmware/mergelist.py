'''
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
'''

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
        

def mergeList(listA, listB):
    if listA is None:
        return listB
    if listB is None:
        return listA
    if listA.val < listB.val: 
        listA.next = mergeList(listA.next, listB)
        return listA
    else:
        listB.next = mergeList(listA, listB.next)
        return listB

def mergeListIterative(listA, listB):
    if listA is None:
        return listB
    if listB is None:
        return listA
    head = None
    if listA.val < listB.val:
        head = listA
        listA = listA.next
    else:
        head = listB
        listB = listB.next
    curr = head
    while listA is not None or listB is not None:
        if listA is None:
           curr.next = listB
           listB = listB.next
        elif listB is None:
           curr.next = listA
           listA = listA.next  
        else:
            if listA.val < listB.val:
                curr.next = listA
                listA = listA.next
            else:
                curr.next = listB
                listB = listB.next
        curr = curr.next
    return head
                           
    
def printList(arr):
    if arr is None:
        print("empty")
    curr = arr
    while curr:
        print(curr.val)
        curr = curr.next
        
def main():
    one = Node(1)
    two = Node(2)
    three = Node(3)
    four = Node(4)
    one.next = two
    two.next = four
    listA = one
    oneCopy = Node(1)
    fourCopy = Node(4)
    oneCopy.next = three
    three.next = fourCopy
    listB = oneCopy
    #printList(listA)
    #printList(listB)
    
    listC = mergeListIterative(listA, listB)
    while listC:
        print(listC.val)
        listC = listC.next
    return 0
    
main()
