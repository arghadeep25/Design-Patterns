## Singleton 

Singleton is a creational design pattern that lets you ensure that a class has only one instance, while providing a global access point to this instance.

### - Real-World Analogy

The government is an excellent example of the Singleton pattern. A country can have only one official government. Regardless of the personal identities of the individuals who form governments, the title, “The Government of X”, is a global point of access that identifies the group of people in charge.


### - Problem
- Ensuring that a class has just a single instance
- Provide a global access point to that instance

### - Solution

### - Advantages 
- Single instance :Ensures that a class has only one instance and provides a global point of access to that instance.
- Global access: Provides a single access point for the entire application, making it easy to control and manage resources.
- Resource sharing: Allows for the sharing of resources among multiple parts of the codebase, maintaining a single point of control.
- Thread safety: Can be designed to be thread-safe, ensuring that the instance is properly initialized in a multithreaded environment


### - Disadvantages
- Global State:
- Tight Coupling: 
- Testing Challenges
- Subclassing Problem