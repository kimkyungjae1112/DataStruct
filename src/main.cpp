#include "../Tree/Tree.h"
#include "../Array/Array.h"
#include "../List/List.h"
#include "../Stack/Stack.h"
#include "../Queue/Queue.h"
#include "../HashTable/HashTable.h"

int main()
{
    array_my::Array_Test();
    list_my::SinglyLinkedList_Test();
    list_my::DoublyLinkedList_Test();
    queue::Queue_Test();
    queue::Deque_Test();
    stack::Stack_Test();
    bst::BST_Test();
    hashtable::OpenAddressingHashTable_Test();

    return 0;
}