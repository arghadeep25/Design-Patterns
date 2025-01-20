## Prototype

Prototype Design Pattern is a creational design pattern that allows you to create new objects by copying an existing object. It avoids the cost of creating objects from scratch and simplifies object creation, especially when dealing with complex objects.

### Components

1. Abstract Class or Interface
2. Concrete Prototype
3. Client

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

### Real World Analogy

Imagine you work in a company that produces custom rubber stamps. Instead of carving a new stamp for every similar order, you create a prototype stamp for each design. When a customer requests a similar design, you use the prototype to create a copy and tweak the details.

### Problem

Say you have an object and want to create the copy of it. To do that, we can simple create a new object of the same class and go through all the fields of the original object and copy their values over to new object.

Some object's field may be private and not visible from outside of the object itself.

Also copying an object with the default constructor creates a shallow copy. If the object comprises of complex resources then shallow copy will lead to resource sharing issue.

### Solution


### Advantages 

manage different derived objects through a common interface and clone then without knowing their specific interface

class with complex resource (raw pointers, dynamically allocated memory, file handles) default constructor perform a shallow copy

runtime object creation

### Disadvantages
-Cloning complex objects that have circular references might be very tricky
