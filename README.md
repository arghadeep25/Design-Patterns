# <p style='color:#ffc95c'>Software Design Patterns</p>

### <p style='color:orange'>What is a Design Pattern?</p>
Design Pattern is a reusable solution to a common problem in software design. It provides best practices and guidelines to improve code maintainability, scalability, and flexibility.


### <p style='color:orange'>Key Concepts to Know Before Learning Design Patterns</p>
Before diving into design patterns, it's essential to understand core object-oriented principles:


- $\color{orange}{Encapsulation}$ –  Bundling data and methods that operate on the data into a single unit (class), restricting direct access to certain details.
  ```cpp
  class Account {
    private:
      // prevents unintended modification of the data and
      // ensures controlled access
      double balance;

    public:
      Account(double initial_balance) : balance(initial_balance) {}

      // allowing interaction of variable balance in a controlled manner
      // ensures data security and better maintainability
      void deposit(double amount) { balance += amount; }

      void withdraw(double amount) {
        if (amount <= balance) balance -= amount;
      }

      double get_balance() const { return balance; }
  };
  ```
- $\color{orange}{Abstraction}$ – Hiding implementation details and exposing only the necessary functionalities.
  ```cpp
  // Abstract class
  class Shape {
    public:
      virtual void draw() const = 0; // Pure virtual function (abstract method)
      virtual ~Shape() = default;
  };

  // Concrete example
  class Circle : public Shape {
    public:
      void draw() const override { std::cout << "Drawing a Circle" << std::endl; }
  };
  ```
- $\color{orange}{Inheritance}$ – Enabling a class to acquire properties and behavior from another class.
  ```cpp
  class Animal {
    public:
      void makeSound() const { std::cout << "Animal makes a sound" << std::endl; }
  };

  class Dog : public Animal {
    public:
      void bark() const { std::cout << "Dog barks" << std::endl; }
  };
  ```
- $\color{orange}{Polymorphism}$ – Allowing objects to be treated as instances of their parent type, enabling dynamic behavior.
  ```cpp
  class Animal {
    public:
      virtual void makeSound() const { std::cout << "Animal makes a sound" << std::endl; }
  };

  class Dog : public Animal {
    public:
      void makeSound() const override { std::cout << "Dog barks" << std::endl; }
  };

  class Cat : public Animal {
    public:
      void makeSound() const override { std::cout << "Cat meows" << std::endl; }
  };
  ```
- $\color{orange}{Open\ /Closed\ Principle}$ – A class should be open for extension but closed for modification, meaning new features should be added without altering existing code.
  ```cpp
  // Base class (Open for extension)
  class Shape {
    public:
      virtual double area() const = 0; // Abstract method
      virtual ~Shape() = default;
  };
  // Extended classes (Closed for modification)
  class Rectangle : public Shape {
      double width, height;
    public:
      Rectangle(double w, double h) : width(w), height(h) {}
      double area() const override { return width * height; }
  };
  class Circle : public Shape {
      double radius;
    public:
      Circle(double r) : radius(r) {}
      double area() const override { return 3.14159 * radius * radius; }
  };
  ```
- $\color{orange}{Single\ Responsibility\ Principle}$ – A class should have only one reason to change, meaning it should have a single responsibility.
  ```cpp
  // Class handling user data (Single Responsibility: Managing user details)
  class User {
      std::string name;
    public:
      User(std::string n) : name(n) {}
      std::string getName() const { return name; }
  };

  // Class handling user-related database operations (Separate Responsibility)
  class UserRepository {
    public:
      void saveUser(const User& user) {
          std::cout << "Saving user: " << user.getName() << std::endl;
      }
  };
  ```
- $\color{orange}{Dependency\ Inversion\ Principle}$ – High-level modules should not depend on low-level modules; both should depend on abstractions.
  ```cpp
  // High-level module (depends on abstraction, not a concrete class)
  class IMessageService {
    public:
      virtual ~IMessageService() = default;
      virtual void sendMessage(const std::string& msg) const = 0;
  };

  // Low-level module (implements the abstraction)
  class EmailService : public IMessageService {
    public:
      void sendMessage(const std::string& msg) const override {
          std::cout << "Sending Email: " << msg << std::endl;
      }
  };

  // High-level module depends on the abstraction, not the concrete class
  class Notification {
      std::shared_ptr<IMessageService> messageService;
    public:
      explicit Notification(std::shared_ptr<IMessageService> service)
          : messageService(std::move(service)) {}

      void notifyUser(const std::string& msg) {
          messageService->sendMessage(msg);
      }
  };
  ```
- $\color{orange}{Composition\ Over\ Inheritance}$ – Prefer object composition (combining objects) over class inheritance to create flexible and reusable code.
  ```cpp
  // Composition: Separate class for behavior
  class Engine {
    public:
      void start() const { std::cout << "Engine started" << std::endl; }
  };

  // Car uses Engine via composition instead of inheritance
  class Car {
    private:
      std::shared_ptr<Engine> engine;  // Composition

    public:
      explicit Car(std::shared_ptr<Engine> eng) : engine(std::move(eng)) {}

      void startCar() {
          engine->start();
          std::cout << "Car is running" << std::endl;
      }
  };
  ```


### <p style='color:orange'>Types of Design Patterns</p>

- [Creational Design Pattern](Creational_Design_Pattern/) Focus on object creation mechanisms, ensuring that objects are created in a controlled and efficient manner. They improve code flexibility and reusability.
    - [Abstract Factory Method](Creational_Design_Pattern/Abstract_Factory/) Imagine you’re designing a home automation system that supports different "smart device ecosystems," such as Alexa and Google Home

    - [Builder](Creational_Design_Pattern/Builder/) The Builder Pattern is like a chef in a restaurant. The chef is given instructions (via a recipe) to build a dish step by step, using the same set of ingredients (components). The client (restaurant customer) doesn’t need to know how the dish is prepared—only that they will get the dish with the desired components (e.g., wooden house or stone house). Each chef (builder) might use a slightly different process to prepare the dish, but the customer always receives the final product (house).

    - [Factory Method](Creational_Design_Pattern/Factory_Method/) Logistics company is a base class. Different modes of transport are the transport class. Clients only interact with the logistic company with the requirement of mode of transport without worrying about the implementation details of the transport.

    - [Prototype](Creational_Design_Pattern/Prototype/) you work in a company that produces custom rubber stamps. Instead of carving a new stamp for every similar order, you create a prototype stamp for each design. When a customer requests a similar design, you use the prototype to create a copy and tweak the details.

    - [Singleton](Creational_Design_Pattern/Singleton_Pattern/) The government is an excellent example of the Singleton pattern. A country can have only one official government. Regardless of the personal identities of the individuals who form governments, the title, “The Government of X”, is a global point of access that identifies the group of people in charge.

- [Structural Design Pattern](Structural_Design_Pattern/) Concerned with organizing classes and objects to form larger structures while keeping them flexible and efficient. They focus on relationships between objects.
   - [Adapter](Structural_Design_Pattern/Adapter/) Imagine you have a phone charger plug designed for U.S. outlets, but you are in Europe, where outlets are different. The Adapter is the socket converter that makes them compatible.

   - [Bridge](Structural_Design_Pattern/Bridge/) Consider a remote control (abstraction) and a television (implementation). Different remote control can operate different TVs without being tightly coupled.

   - [Composite](Structural_Design_Pattern/Composite/) Imagine we have two different object, `Boxes` and `Products`. Inside a box there could be a product or a box. Inside the product there could a box and so on. As one is wrapped under another, counting the number of objects will be difficult.

   - [Decorator](Structural_Design_Pattern/Decorator/) Wearing clothes is an example of using decorators. When you’re cold, you wrap yourself in a sweater. If you’re still cold with a sweater, you can wear a jacket on top. If it’s raining, you can put on a raincoat. All of these garments “extend” your basic behavior but aren’t part of you, and you can easily take off any piece of clothing whenever you don’t need it.

   - [Facade](Structural_Design_Pattern/Facade/) Imagine using a home theater system with multiple components (TV, speakers, DVD player, gaming console, etc.). Instead of manually operating each device separately, you have a universal remote (Facade) that provides a single point of control. Pressing one button turns everything on and sets it up without needing to interact with each component individually.

   - [Flyweight](Structural_Design_Pattern/Flyweight/) A game engine needs to render thousands of trees in a large open-world game. Each tree has a unique position but shares the same model, texture, and colors. Storing a separate object for each tree wastes memory since most properties are identical.

   - [Proxy](Structural_Design_Pattern/Proxy/) The ATM machine (Proxy) acts as an intermediary between the customer and the bank's central system (Real Subject). Instead of giving customers direct access to the bank’s core systems, the ATM verifies identity, processes transactions, and provides limited access. This ensures security, controlled access, and optimized performance.

- [Behavioral Design Pattern](Behavioral_Design_Pattern/) Deal with object interaction and responsibility distribution, defining how objects communicate while maintaining loose coupling.
  - [Chain of Responsibility](Behavioral_Design_Pattern/Chain%20of%20Responsibility/) A customer submits a request. The request is first checked by a junior support agent. If the junior agent can't resolve it, the request is forwarded to a senior agent. If needed, it goes to the manager. The request is handled by the first capable person in the chain.

  - [Command](Behavioral_Design_Pattern/Command/) A waiter takes an order (command) from a customer. The order is placed in the kitchen queue. The chef executes the order when ready. The waiter doesn't need to know how the food is prepared, only that the order needs to be executed.

  - [Iterator](Behavioral_Design_Pattern/Iterator/) Playlist on a music streaming app. You can navigate songs one-by-one (sequential access). You don’t need to know how the playlist is stored internally. You can rewind, skip, or loop over the songs easily.

  - [Mediator](Behavioral_Design_Pattern/Mediator/) Imagine an air traffic control (ATC) tower at an airport. Planes (colleagues) do not communicate directly with each other; instead, they send messages to the ATC (mediator), which coordinates takeoffs, landings, and other operations.

  - [Memento](Behavioral_Design_Pattern/Memento/) Before entering a difficult battle, the player saves their game state. If they lose, they can reload the saved state and try again. The player doesn’t need to know how the game internally manages health, inventory, or position—just that the previous state is restored.

  - [Observer](Behavioral_Design_Pattern/Observer/) A YouTuber (Subject) uploads a new video. All Subscribers (Observers) get notified. If someone unsubscribes, they stop receiving updates.

  - [State](Behavioral_Design_Pattern/State/) Traffic Light. It can be red, yellow, or green. When the light changes, its behavior changes accordingly (cars stop, prepare, or go). The light follows a predefined transition between states.

  - [Strategy](Behavioral_Design_Pattern/Strategy/) Navigation app that allows a user to select different transportation modes. Car navigation, Bike navigation, Walking navigation.

  - [Template](Behavioral_Design_Pattern/Template/) Making tea and coffee. Both processes share common steps. Boil water. Brew the drink (tea leaves or coffee grounds). Pour into a cup. Add extras (lemon for tea, milk/sugar for coffee)

  - [Visitor](Behavioral_Design_Pattern/Visitor/) Think of a museum with different types of exhibits. Instead of modifying each exhibit when a new type of visitor (e.g., student, tourist, researcher) comes in, we define a visitor interface that applies different behaviors depending on the visitor type.



## <p style='color:orange'>Most Commonly Used</p>

### <p style='color:orange'>Creational Patterns</p>
- `Singleton` – Ensures only one instance of a class exists and provides a global access point.

- `Factory Method` – Provides an interface for creating objects in a superclass but allows subclasses to alter the type of objects that will be created.

- `Builder` – Separates the construction of a complex object from its representation.

### <p style='color:orange'>Structural Patterns</p>
- `Adapter` – Allows incompatible interfaces to work together.

- `Facade` – Provides a simplified interface to a complex subsystem.

- `Decorator` – Dynamically adds behavior to objects without modifying their code.

### <p style='color:orange'>Behavioral Patterns</p>
- `Observer` – Defines a dependency between objects so that when one changes state, all its dependents are notified.

- `Strategy` – Allows selecting an algorithm's behavior at runtime.

- `State` – Allows an object to change its behavior when its internal state changes.


## <p style='color:orange'>SOLID Principle</p>
SOLID principle comprised of 5 techniques namely
- Single Responsibility Principle
- Open-Closed Principle
- Liskov Substitution Principle
- Interface Segregation Principle
- Dependency Inversion Principle

### <p style='color:orange'>Single Responsibility Principle</p>
Each class handling one single responsibility

#### <p style='color:green'>Good Example</p>
```cpp
class Report {
public:
    std::string generateReport() {
        return "Report Data";
    }
};

class ReportPrinter {
public:
    void printReport(const std::string& report) {
        std::cout << report << std::endl;
    }
};
```

#### <p style='color:red'>Bad Example</p>
```cpp
class Report {
public:
    std::string generateReport() {
        return "Report Data";
    }

    void printReport() {  // Printing logic mixed with report generation
        std::cout << generateReport() << std::endl;
    }
};
```

### <p style='color:orange'>Open-Closed Principle</p>

A class should be open for extension but closed for modification.

#### <p style='color:green'>Good Example</p>
```cpp
class Shape {
public:
    virtual double area() const = 0;  // Abstract method
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.1415 * radius * radius;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};
```

#### <p style='color:red'>Bad Example</p>
```cpp
class Shape {
public:
    enum ShapeType { CIRCLE, RECTANGLE };
    ShapeType type;

    double getArea() {
        if (type == CIRCLE) return 3.1415 * 5 * 5;
        if (type == RECTANGLE) return 10 * 20;
        return 0;
    }
};
```

### <p style='color:orange'>Liskov Substitution Principle</p>
Subtypes must be substitutable for their base types without changing behavior.

#### <p style='color:green'>Good Example</p>
```cpp
class Bird {
public:
    virtual void fly() const {
        std::cout << "Bird is flying" << std::endl;
    }
};

class Sparrow : public Bird {};  // Inherits correct behavior

void makeBirdFly(const Bird& bird) {
    bird.fly();
}

Sparrow sparrow;
makeBirdFly(sparrow);  // Works correctly
```
#### <p style='color:red'>Bad Example</p>
```cpp
// Penguin inherits from Bird but does not support fly(), violating expectations. Instead, Penguin should not inherit Bird, but rather a NonFlyingBird class.
class Bird {
public:
    virtual void fly() const = 0;
};

class Penguin : public Bird {
public:
    void fly() const override {
        throw std::runtime_error("Penguins cannot fly!");
    }
};
```

### <p style='color:orange'>Interface Segregation Principle</p>
A class should not be forced to implement interfaces it does not use.
#### <p style='color:green'>Good Example</p>
```cpp
class Printer {
public:
    virtual void print() const = 0;
};

class Scanner {
public:
    virtual void scan() const = 0;
};

//Classes implement only the methods they need.
class MultiFunctionPrinter : public Printer, public Scanner {
public:
    void print() const override {
        std::cout << "Printing document" << std::endl;
    }
    void scan() const override {
        std::cout << "Scanning document" << std::endl;
    }
};
```
#### <p style='color:red'>Bad Example</p>
```cpp
// SimplePrinter is forced to implement scan(), even though it cannot scan.
class Machine {
public:
    virtual void print() const = 0;
    virtual void scan() const = 0;
};

class SimplePrinter : public Machine {
public:
    void print() const override {
        std::cout << "Printing document" << std::endl;
    }

    void scan() const override {
        throw std::runtime_error("This printer cannot scan!");
    }
};
```

### <p style='color:orange'>Dependency Inversion Principle</p>
High-level modules should not depend on low-level modules. Both should depend on abstractions.
#### <p style='color:green'>Good Example</p>
```cpp
class Logger {
public:
    virtual void log(const std::string& message) const = 0;
};

class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) const override {
        std::cout << "Log: " << message << std::endl;
    }
};

class Application {
    Logger& logger;
public:
    Application(Logger& log) : logger(log) {}
    void run() {
        logger.log("Application started");
    }
};
```
#### <p style='color:red'>Bad Example</p>
```cpp
class Application {
    ConsoleLogger logger;  // Hardcoded dependency
public:
    void run() {
        logger.log("Application started");
    }
};
```

### <p style='color:orange'>Why SOLID?</p>
- Better maintainability – Code is easier to read, modify, and extend.
- Reusability – Components can be reused without unnecessary dependencies.
- Testability – Code is loosely coupled, making unit testing easier.

## <p style='color:orange'>The Rule of Three in C++</p>
If a class in C++ defines any one of the followings:
- Destructor
- Copy Constructor
- Copy Assignment Operator

Then it **should define all three**.

These three manage resource ownership (e.g dynamic memory allocation, file handles, mutexes etc.). If one of them is defined to perform custom cleanup, then others should also be defined in order to ensure consistent and safe behavior.

```cpp
class MyClass {
private:
    int* data;

public:
    // default constructor
    MyClass(int val) {
        data = new int(val); // dynamic allocation
    }
    //default destructor
    ~MyClass() {
        delete data; // custom destructor
    }
    // copy constructor
    MyClass(const MyClass& other) {
        data = new int(*other.data);
    }
    // copy assignment
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
};
```

If any one of them is missed, then it might lead to **shallow copies** or **double deletion**.
