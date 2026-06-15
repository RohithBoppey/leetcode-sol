# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow, fast, prev = head, head, head
        if fast.next == None: 
            return None
        
        while fast != None and fast.next != None:
            fast = fast.next.next
            prev = slow  
            slow = slow.next
        
        prev.next = slow.next
        return head

        

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna