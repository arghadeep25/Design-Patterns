# Behavioral Design Pattern


## Summary of Behavioral Design Patterns

| **Pattern**          | **Purpose**                                                 | **Key Characteristics**                                        | **When to Use**                                                                 |
|----------------------|-------------------------------------------------------------|----------------------------------------------------------------|--------------------------------------------------------------------------------|
| **Chain of Responsibility** | Passes requests along a chain of handlers. | Decouples sender & receiver, allows multiple handlers. | When multiple objects may handle a request, but the exact handler is unknown. |
| **Command**         | Encapsulates a request as an object. | Supports undo/redo, deferred execution, and queuing. | When you need to parameterize requests, log them, or implement undo. |
| **Interpreter**     | Defines a grammar and interprets sentences. | Used for parsing & evaluating expressions. | When designing a language, scripting engine, or rule-based system. |
| **Iterator**        | Provides a way to access elements sequentially without exposing details. | Supports different traversal methods, encapsulates iteration logic. | When you need to iterate over a collection without exposing its internals. |
| **Mediator**        | Reduces direct communication between objects by centralizing interactions. | Promotes loose coupling, reduces dependencies. | When multiple objects interact and a centralized controller simplifies the design. |
| **Memento**         | Captures and restores an object’s state without violating encapsulation. | Supports undo/rollback, stores snapshots. | When you need to implement history, undo, or checkpoint features. |
| **Observer**        | Defines a one-to-many dependency where updates are automatically broadcasted. | Supports event-driven programming, maintains consistency. | When multiple objects depend on changes in a single object (e.g., event listeners). |
| **State**           | Allows an object to change behavior dynamically based on its state. | Encapsulates state logic inside dedicated classes. | When an object has complex state-dependent behavior and avoids if-else chains. |
| **Strategy**        | Encapsulates interchangeable algorithms inside separate classes. | Promotes code reusability, makes algorithms interchangeable. | When you need to switch between multiple algorithms dynamically. |
| **Template Method** | Defines the structure of an algorithm but lets subclasses implement specific steps. | Uses inheritance, enforces a predefined workflow. | When you want to enforce a sequence of steps but allow customization. |
| **Visitor**         | Allows adding new operations to an object structure without modifying its classes. | Separates data structure and behavior, double dispatch. | When object structure is stable but new operations need to be added frequently. |

## Similarities and Differences Between Behavioral Patterns

| **Feature**          | **Chain of Responsibility** | **Command** | **Observer** | **State** | **Strategy** |
|----------------------|--------------------------|-------------|-------------|----------|------------|
| **Purpose**          | Passes request through handlers | Encapsulates requests as objects | One-to-many dependency | Changes behavior based on state | Encapsulates algorithms |
| **Decouples Sender & Receiver** | Yes | Yes | No (not fully) | No | Yes |
| **Encapsulates Behavior** | No | Yes | No | Yes | Yes |
| **Supports Undo/Redo** | No | Yes | No | No | No |
| **Uses Inheritance** | No | No | No | Yes | Yes |
| **Uses Composition** | Yes | Yes | Yes | Yes | Yes |
| **When to Use** | Dynamic request handling | Command execution, undo | Event-driven behavior | State-dependent logic | Switchable algorithms |

## 3. Key Takeaways

### 1. **Encapsulation of Behavior:**
   - **Strategy, Command, and State** encapsulate behavior and allow it to be changed dynamically.

### 2. **Request Handling & Control Flow:**
   - **Chain of Responsibility** ensures flexible handling of requests.
   - **Command** encapsulates actions and supports undo functionality.
   - **Mediator** simplifies communication between objects.

### 3. **State Management:**
   - **Observer** is useful for event-driven updates.
   - **Memento** allows restoring previous states (undo functionality).
   - **State** pattern helps manage complex state-based behavior.

### 4. **Algorithm Structuring:**
   - **Template Method** enforces a structure for algorithms.
   - **Visitor** allows adding new operations without modifying object structure.
   - **Interpreter** helps parse and evaluate expressions.
