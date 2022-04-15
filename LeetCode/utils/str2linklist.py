class ListNode:
    def __init__(self, val=0, next=None) -> None:
        self.val = val
        self.next = next

def get_linklist(data):
    data = data.strip('[').strip(']')
    data = list(map(int, data.split(',')))

    ans = ListNode(0)
    current = ans

    for item in data:
        new = ListNode(item)
        current.next = new
        current = new
    
    return ans.next

def printList(H):
    current = H
    while current is not None:
        print(current.val, end=' ')
        current = current.next
    print()

if __name__ == '__main__':
    data = input()
    List = get_linklist(data)
    printList(List)