## Singleton

Singleton is a creational design pattern that lets you ensure that a class has only one instance, while providing a global access point to this instance.

[<img src="https://refactoring.guru/images/patterns/content/singleton/singleton.png">]()
Source: [Refactoring Guru](https://refactoring.guru/design-patterns/singleton)

### - Real-World Analogy

The government is an excellent example of the Singleton pattern. A country can have only one official government. Regardless of the personal identities of the individuals who form governments, the title, “The Government of X”, is a global point of access that identifies the group of people in charge.


### - Problem
- Ensuring that a class has just a single instance
- Provide a global access point to that instance

### - Solution
- Making default constructor private to prevent other objects from using `new` operator with the Singleton class
- Create a static creation method that acts as a constructor

### Structure
[<img src="https://refactoring.guru/images/patterns/diagrams/singleton/structure-en.png">]()

### - Advantages
- Single instance :Ensures that a class has only one instance and provides a global point of access to that instance.
- Global access: Provides a single access point for the entire application, making it easy to control and manage resources.
- Resource sharing: Allows for the sharing of resources among multiple parts of the codebase, maintaining a single point of control.
- Thread safety: Can be designed to be thread-safe, ensuring that the instance is properly initialized in a multithreaded environment


### - Disadvantages
- Global State: Introduces a global state in the application, which might make it difficult to identify and manage dependencies.
- Tight Coupling: Creates a tight coupling between the Singleton instance and the classes that depend on it, making the code less modular and harder to test.
- Testing Challenges: Unit testing can become challenging since the Singleton instance is often accessed directly, making it difficult to substitute with mock objects.
- Subclassing Problem: Subclassing a Singleton class can be problematic, especially when the subclass requires its own instance or different initialization.
