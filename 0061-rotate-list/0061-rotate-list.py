# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
def ll_count(h):
    head = h
    count = 0
    while head != None: 
        count += 1
        head = head.next
    return count 

# rotate first k elements and return new head
def rotate(h, k):
    head = h
    if head == None or head.next == None or k == 0: 
        # 0,1 elements
        return head

    # only reverse the first k 
    prev, curr, next = None, None, None
    curr = head

    while curr != None and k > 0: 
        next = curr.next
        curr.next = prev
        prev = curr    
        curr = next
        k -= 1

    return prev

def printL(head):
    while head != None:
        print(head.val,'->',end='')
        head = head.next
    print('\n')

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head == None or head.next == None or k == 0: 
            # 0,1 elements
            return head

        # find count
        cnt = ll_count(head)
        k = k % cnt
        # print(k)

        # split point for h2
        temp = head
        for i in range(cnt - k - 1):
            temp = temp.next 

        h2 = temp.next
        temp.next = None # breaking connection

        # now rotate first n-k elements
        h1 = rotate(head, cnt - k)

        # now rotate last k elements
        h2 = rotate(h2, k)

        # connect tail of h1 to h2
        temp = h1
        while temp.next:
            temp = temp.next

        temp.next = h2

        # printL(h1)
        h1 = rotate(h1, cnt)
        # printL(h1)

        return h1
