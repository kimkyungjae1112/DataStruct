# 📚 C++ 자료구조 직접 구현하기

C++로 다양한 기본 자료구조를 직접 구현하고 정리한 프로젝트입니다. 각 자료구조의 핵심 특징과 시간복잡도를 요약하고, 구현 코드는 링크를 통해 확인할 수 있습니다.

---

## 📌 1. 배열 (Array)

- **특징**:
  - 고정된 크기의 연속된 메모리 공간
  - 추가적인 메모리 오버헤드가 거의 없음
  - Cache hit rate가 높음
  - 메모리 상 연속된 구간 확보가 필요하므로 할당 제약 있음

- **시간복잡도**:
  - 검색: `O(1)` (인덱스를 통한 접근)
  - 삽입/삭제: `O(N)` (중간 요소 이동 필요)

🔗 [소스 코드 보기](https://github.com/kimkyungjae1112/DataStruct/blob/master/src/Array.h)

---

## 🔗 2. 연결 리스트 (Linked List)

- **특징**:
  - 동적 메모리 할당 가능, 크기 가변
  - 메모리 비연속 → Cache hit rate 낮음
  - 노드를 위한 추가 포인터 메모리 필요

- **종류**:
  - 단일 연결 리스트 (Singly Linked List)
  - 이중 연결 리스트 (Doubly Linked List)
  - 원형 연결 리스트 (Circular Linked List)

- **시간복잡도**:
  - 검색: `O(N)`
  - 삽입/삭제: `O(1)` *(단, 노드를 찾는 데는 `O(N)`)*
  
🔗 [소스 코드 보기](https://github.com/kimkyungjae1112/DataStruct/blob/master/src/List.h)

---

## 🥞 3. 스택 (Stack)

- **특징**:
  - 후입선출 (LIFO: Last In First Out)
  - Top 위치에서만 삽입/삭제 가능
  - Top 확인: `O(1)`  
  - 특정 원소 접근: `O(N)`

- **시간복잡도**:
  - 삽입/삭제: `O(1)`
  - 조회: `O(N)`

🔗 [소스 코드 보기](https://github.com/kimkyungjae1112/DataStruct/blob/master/src/Stack.h)

---

## 🚶‍♂️ 4. 큐 (Queue)

- **특징**:
  - 선입선출 (FIFO: First In First Out)
  - Front, Back 위치에서만 삽입/삭제 가능
  - Front, Back 확인: `O(1)` 
  
- **종류**:
  - 일반 큐 (Queue)
  - 덱 (Deque, 양방향 큐)
  - 우선순위 큐 (Priority Queue)

- **시간복잡도**:
  - 삽입/삭제: `O(1)`
  - 검색: `O(N)`

🔗 [소스 코드 보기](https://github.com/kimkyungjae1112/DataStruct/blob/master/src/Queue.h)

---

## 🔑 5. 해시 테이블 (Hash Table)

- **특징**:
  - 키-값 (Key-Value) 매핑 구조
  - 충돌이 발생할 수 있으며 해결 방식 필요 (체이닝, 오픈 어드레싱 등)

- **시간복잡도**:
  - 평균: 검색/삽입/삭제 `O(1)`
  - 최악: `O(N)` (충돌 심한 경우)

🔗 [소스 코드 보기](#)

---

## 🌳 6. 트리 (Tree)

- **특징**:
  - 계층적 구조 (부모-자식 관계)

- **종류**:
  - 이진 트리 (Binary Tree)
  - 이진 탐색 트리 (BST)
  - AVL 트리 / 레드-블랙 트리 (균형 트리)
  - 힙 (Heap)
  - 트라이 (Trie)

- **시간복잡도** *(균형 트리 기준)*:
  - 검색/삽입/삭제: `O(log N)`

🔗 [소스 코드 보기](https://github.com/kimkyungjae1112/DataStruct/blob/master/src/BinarySearchTree.h)
