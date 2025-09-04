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
    queue_my::Queue_Test();
    queue_my::Deque_Test();
    stack::Stack_Test();
    bt::BT_Test();
    bst::BST_Test();
<<<<<<< HEAD
    hashtable::HashTableTest();
=======
    heap::Heap_Test();
    hashtable::OpenAddressingHashTable_Test();
>>>>>>> 720c39733c4af7476125b63f26e07993ca1f582a

    return 0;
}