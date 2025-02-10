## Visitor

Visitor Pattern is a behavioral design pattern that lets you add further operations to objects without modifying their structures. It allows you to define new operations on a set of objects by separating the algorithm from the object structure.

### Real-World Analogy

Think of a museum with different types of exhibits. Instead of modifying each exhibit when a new type of visitor (e.g., student, tourist, researcher) comes in, we define a visitor interface that applies different behaviors depending on the visitor type.

### Components
- Visitor: Declares visit methods for each type of element.
- ConcreteVisitor: Implements the visit methods, defining specific behaviors.
- Element: Declares an accept(Visitor&) method to accept visitors.
- ConcreteElement: Implements accept(Visitor&) and calls the appropriate visit() method.
- ObjectStructure: A collection of elements that can be visited.

### Problem
You need to perform different types of operations on objects without modifying their structure. Adding new operations directly to the objects would violate the Open/Closed Principle, making the code harder to maintain.

### Solution
Use the Visitor pattern to separate algorithms from object structures, allowing new behaviors to be added without modifying existing classes.

```
  +------------------+
  |     Visitor      |
  |------------------|
  | + visit(Element) |
  +------------------+
           ▲
           │
+---------------------+
|  ConcreteVisitor    |
|---------------------|
| + visit(Element)    |
+---------------------+

  +------------------+
  |     Element      |
  |------------------|
  | + accept(Visitor)|
  +------------------+
           ▲
           │
+---------------------+
|  ConcreteElement    |
|---------------------|
| + accept(Visitor)   |
+---------------------+

+----------------------+
|   ObjectStructure    |
|----------------------|
| + add(Element)       |
| + accept(Visitor)    |
+----------------------+

```

### Advantages
- Allows adding new operations without modifying existing object structures.
- Follows the Single Responsibility Principle by separating operations.
- Promotes Open/Closed Principle by enabling extension.

### Disadvantages
- Can lead to code duplication if there are too many variations.
- Breaks encapsulation since visitors need access to internal elements.
