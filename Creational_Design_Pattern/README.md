# Creational Design Pattern


## Summary of Creational Design Patterns

| Pattern              | Purpose                                                                                                                         | Key Characteristics                                                                                                | When to Use                                                                                                          |
| -------------------- | ------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------------- |
| **Singleton**        | Ensures a class has only one instance and provides a global point of access to it.                                              | - Single instance<br>- Global access<br>- Thread-safe implementation may be required.                              | - Managing shared resources (e.g., configuration, logging, thread pool).<br>- When only one instance is needed.      |
| **Factory Method**   | Provides an interface for creating objects in a superclass, but lets subclasses alter the type of objects that will be created. | - Uses inheritance<br>- Relies on polymorphism<br>- Subclasses decide object instantiation.                        | - When the client doesn't need to know the exact type of object.<br>- When new types might need to be added.         |
| **Abstract Factory** | Provides an interface to create families of related or dependent objects without specifying their concrete classes.             | - Groups related factories<br>- Returns multiple related products (family)<br>- Encapsulation of object creation.  | - When you need a family of related products.<br>- Ensures consistency across related objects.                       |
| **Prototype**        | Creates new objects by cloning existing ones (through deep or shallow copying).                                                 | - Avoids creating new instances from scratch.<br>- Cloning is central.<br>- Polymorphic cloning possible.          | - When object creation is costly or complex.<br>- When objects have similar states but minor differences.            |
| **Builder**          | Separates the construction of a complex object from its representation.                                                         | - Step-by-step object construction.<br>- Different representations of the same object.<br>- Focus on immutability. | - When creating objects with many parts or steps.<br>- When the same construction process creates different objects. |

---

## Similarities and Differences

| Feature             | Singleton                 | Factory Method         | Abstract Factory            | Prototype              | Builder                 |
| ------------------- | ------------------------- | ---------------------- | --------------------------- | ---------------------- | ----------------------- |
| **Object Creation** | No                        | Yes                    | Yes                         | Yes                    | Yes                     |
| **Polymorphism**    | No                        | Yes                    | Yes                         | Yes                    | No                      |
| **Complex Objects** | No                        | No                     | No                          | No                     | Yes                     |
| **Focus**           | Single instance           | Single object creation | Families of related objects | Cloning objects        | Complex object creation |
| **Reusability**     | Moderate (reuse instance) | High                   | High                        | High                   | High                    |
| **Decoupling**      | No                        | Yes                    | Yes                         | Moderate               | Yes                     |
| **When to Use**     | Shared resources          | Type decoupling        | Consistency in families     | Complex initialization | Complex construction    |

---

## Summary of Key Points

- **Singleton** ensures a single instance is used globally.
- **Factory Method** delegates object creation to subclasses for flexibility.
- **Abstract Factory** focuses on families of related objects.
- **Prototype** simplifies cloning objects.
- **Builder** structures complex object creation in a systematic way.

Use these patterns wisely based on the needs of your system, ensuring maintainability and extensibility.
