## Software Design Patterns

### What is a Design Pattern
Design Pattern is a reusable solution to a common problem in software design. It provides best practices and guidelines to improve code maintainability, scalability, and flexibility.

### Key Concepts to Know Before Learning Design Patterns
Before diving into design patterns, it's essential to understand core object-oriented principles:

- `Encapsulation` – Bundling data and methods that operate on the data into a single unit (class), restricting direct access to certain details.
- `Abstraction` – Hiding implementation details and exposing only the necessary functionalities.
- `Inheritance` – Enabling a class to acquire properties and behavior from another class.
- `Polymorphism` – Allowing objects to be treated as instances of their parent type, enabling dynamic behavior.
- `Open/Closed Principle` – A class should be open for extension but closed for modification, meaning new features should be added without altering existing code.
- `Single Responsibility Principle` – A class should have only one reason to change, meaning it should have a single responsibility.
- `Dependency Inversion Principle` – High-level modules should not depend on low-level modules; both should depend on abstractions.
- `Composition Over Inheritance` – Prefer object composition (combining objects) over class inheritance to create flexible and reusable code.


### Types of Design Patterns

- [Creational Design Pattern](Creational_Design_Pattern/)
    - [Abstract Factory Method](Creational_Design_Pattern/Abstract_Factory/) Imagine you’re designing a home automation system that supports different "smart device ecosystems," such as Alexa and Google Home
    - [Builder](Creational_Design_Pattern/Builder/) The Builder Pattern is like a chef in a restaurant. The chef is given instructions (via a recipe) to build a dish step by step, using the same set of ingredients (components). The client (restaurant customer) doesn’t need to know how the dish is prepared—only that they will get the dish with the desired components (e.g., wooden house or stone house). Each chef (builder) might use a slightly different process to prepare the dish, but the customer always receives the final product (house).
    - [Factory Method](Creational_Design_Pattern/Factory_Method/) Logistics company is a base class. Different modes of transport are the transport class. Clients only interact with the logistic company with the requirement of mode of transport without worrying about the implementation details of the transport.
    - [Prototype](Creational_Design_Pattern/Prototype/) you work in a company that produces custom rubber stamps. Instead of carving a new stamp for every similar order, you create a prototype stamp for each design. When a customer requests a similar design, you use the prototype to create a copy and tweak the details.
    - [Singleton](Creational_Design_Pattern/Singleton_Pattern/) The government is an excellent example of the Singleton pattern. A country can have only one official government. Regardless of the personal identities of the individuals who form governments, the title, “The Government of X”, is a global point of access that identifies the group of people in charge.

- [Structural Design Pattern](Structural_Design_Pattern/)
   - [Adapter](Structural_Design_Pattern/Adapter/)
   - [Bridge](Structural_Design_Pattern/Bridge/)
   - [Composite](Structural_Design_Pattern/Composite/)
   - [Decorator](Structural_Design_Pattern/Decorator/)
   - [Facade](Structural_Design_Pattern/Facade/)
   - [Flyweight](Structural_Design_Pattern/Flyweight/)
   - [Proxy](Structural_Design_Pattern/Proxy/)

- [Behavioral Design Pattern](Behavioral_Design_Pattern/)
  - [Chain of Responsibility](Behavioral_Design_Pattern/Chain%20of%20Responsibility/)
  - [Command](Behavioral_Design_Pattern/Command/)
  - [Iterator](Behavioral_Design_Pattern/Iterator/)
  - [Mediator](Behavioral_Design_Pattern/Mediator/)
  - [Memento](Behavioral_Design_Pattern/Memento/)
  - [Observer](Behavioral_Design_Pattern/Observer/)
  - [State](Behavioral_Design_Pattern/State/)
  - [Strategy](Behavioral_Design_Pattern/Strategy/)
  - [Template](Behavioral_Design_Pattern/Template/)
  - [Visitor](Behavioral_Design_Pattern/Visitor/)