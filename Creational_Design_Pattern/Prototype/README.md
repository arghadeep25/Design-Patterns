## Prototype

Prototype Design Pattern is a creational design pattern that allows you to create new objects by copying an existing object. It avoids the cost of creating objects from scratch and simplifies object creation, especially when dealing with complex objects.

### Components

- Abstract Class or Interface: Defines the cloning method (e.g., clone() in most implementations).
- Concrete Prototype: Implements the clone() method and allows object duplication.
- Client: Requests new objects using cloning instead of direct instantiation.

### Real World Analogy

Imagine you work in a company that produces custom rubber stamps. Instead of carving a new stamp for every similar order, you create a prototype stamp for each design. When a customer requests a similar design, you use the prototype to create a copy and tweak the details.

### Problem

Creating objects from scratch can be costly due to:
- Complex initialization logic
- Database calls, API requests, or expensive computations
- Recurring overhead from object construction

Example:

- Suppose we are developing a graphic editor where different shapes (circles, squares) are created repeatedly.
- Creating a new shape from scratch each time is inefficient.
- Instead, we can copy an existing shape and modify only what’s needed.

### Solution
Instead of instantiating a new object, the prototype pattern allows cloning an existing object using a clone() method.

- This method creates a shallow or deep copy of the object.
- The cloned object can then be modified as needed without affecting the original.


```
+--------------------+
|     Prototype      |<--------------------+
|--------------------|                     |
|+ clone():Prototype |                     |
+--------------------+                     |
          ^                                |
          | Implements                     |
+--------------------+        +--------------------+
| ConcretePrototype1 |        | ConcretePrototype2 |
|--------------------|        |--------------------|
|+ clone(): Prototype|        |+ clone():Prototype |
+--------------------+        +--------------------+
          ^                                ^
          | Uses                           | Uses
          +--------------------------------+
                         Client


```

### Advantages 

- Reduces initialization costs – Avoids expensive object creation.
- Encapsulates object construction – Clients don’t need to worry about how objects are created.
- Simplifies complex object structures – Particularly useful for hierarchical structures or deeply nested objects.
- Supports runtime object creation – Objects can be cloned dynamically at runtime.

### Disadvantages
- Shallow copy issues – If the object contains references, a simple copy may lead to unintended shared states.
- Increased memory usage – Cloning creates additional objects, which may increase memory consumption.
- Complex deep cloning – Implementing deep copy logic can be challenging for objects with multiple references.
