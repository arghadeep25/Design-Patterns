## Iterator

The Iterator pattern provides a way to access the elements of an aggregate object sequentially without exposing its underlying structure.

### Real-World Analogy
Think of a playlist on a music streaming app:

- You can navigate songs one-by-one (sequential access).
- You don’t need to know how the playlist is stored internally.
- You can rewind, skip, or loop over the songs easily.

### Components
- Iterator (Abstract Class/Interface) – Defines methods for iterating over a collection.
- Concrete Iterator – Implements the iterator interface to traverse a specific collection.
- Aggregate (Collection Interface) – Declares a method to create an iterator object.
- Concrete Aggregate (Concrete Collection) – Implements the collection interface and provides an iterator.

### Problem
Collections (like arrays, linked lists, and trees) have different structures. If we iterate over them differently in multiple places, our code becomes tightly coupled to specific data structures, making it hard to modify or extend.

### Solution
The Iterator pattern abstracts the traversal logic into a separate class, so the collection's internal structure remains hidden from the client.

```
+-------------------+          +---------------------+
|   Iterable        |          |  Iterator           |
|-------------------|<>------->|---------------------|
| +createIterator() |          | +hasNext()          |
+------------------+           | +next()             |
                               +---------------------+
                                          ▲
                                          │
                               +---------------------+
                               | ConcreteIterator    |
                               |---------------------|
                               | -collection         |
                               | -position           |
                               +---------------------+
                                         ▲
                                         │
                              +----------------------+
                              |  ConcreteCollection  |
                              |----------------------|
                              | -items               |
                              | +createIterator()    |
                              +----------------------+

```

### Advantages
- Encapsulates iteration logic, making it reusable.
- Decouples collection from traversal, making collections easier to modify.
- Supports multiple traversal methods (e.g., forward, backward, skipping elements).

### Disadvantages
- Adds complexity with extra classes.
- May reduce performance compared to direct iteration, especially for small collections.