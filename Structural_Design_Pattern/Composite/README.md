## Composite
The Composite Pattern is a structural design pattern that lets clients treat individual objects and compositions of objects uniformly by defining a common interface for both.

### Real-World Analogy
Imagine we have two different object, `Boxes` and `Products`. Inside a box there could be a product or a box. Inside the product there could a box and so on. As one is wrapped under another, counting the number of objects will be difficult. 

One approach will be unwrapping all the boxes and counting the products separately but this is a lot of effort. In coding practice, this approach will be either too awkward or even impossible.

### Problem
A file system consists of both files and folders.

- Files are single entities (e.g., Report.pdf).
- Folders can contain both files and other folders, forming a tree structure.
- We need a uniform way to interact with both files and folders.

### Solution
The Composite Pattern allows us to treat both files and folders the same way by designing a common interface (FileSystemComponent).

- Both File and Folder classes inherit from FileSystemComponent.
- A Folder contains a list of FileSystemComponent objects, allowing it to store both File and Folder objects.

This way, we can apply operations like showDetails() uniformly, whether it's a file or a folder.

### Advantages
- Uniformity: Clients can treat files and folders consistently.
- Extensibility: New file types or folders can be added without changing existing code.
- Scalability: The pattern naturally supports hierarchical structures like a file system or organizational chart.

### Disadvantages
- Complexity – Adds an extra layer of abstraction, which may be unnecessary for simpler cases.
- Overhead – If the hierarchy is small, the pattern may introduce unnecessary complexity.