## Template

Template Method Pattern is a behavioral design pattern that defines the skeleton of an algorithm in a base class but lets subclasses override specific steps without changing the overall structure.

### Real-World Analogy
Imagine you are making tea and coffee. Both processes share common steps:

- Boil water
- Brew the drink (tea leaves or coffee grounds)
- Pour into a cup
- Add extras (lemon for tea, milk/sugar for coffee)

Instead of implementing the full process in separate classes, we can define a template in a base class and let subclasses customize only the unique steps (brewing and adding extras).

### Components
- Abstract Class (CaffeineBeverage) → Defines the template method with steps.
- Concrete Classes (Tea, Coffee) → Override specific steps but follow the overall algorithm.
- Template Method (prepareBeverage()) → Defines the sequence of steps.

### Problem
A software system needs to execute a series of steps, where some steps are common and some need to be customized for different implementations.

- Without the Template Method Pattern, developers may duplicate the same logic across multiple classes.
- This leads to code duplication and is hard to maintain.

Issues with a Naïve Approach
- Code Duplication: Every subclass re-implements the same steps.
- Violation of Open-Closed Principle: Changes to common steps require modifying all subclasses.

### Solution
Use the Template Method Pattern:

- Define the common steps in a base class.
- Allow subclasses to override only the necessary steps.
- Ensure that the algorithm structure remains consistent.

```
        +--------------------------+
        |   CaffeineBeverage       |  (Abstract Class)
        |--------------------------|
        | + prepareBeverage()      |
        | + boilWater()            |
        | + pourInCup()            |
        | + brew() (abstract)      |
        | + addExtras() (abstract) |
        +--------------------------+
                     ▲
                     │
        ---------------------------------
        |                               |
        |                               |
  +---------------+              +---------------+
  |    Tea        |              |   Coffee      |  (Concrete Classes)
  +---------------+              +---------------+
  | + brew()      |              | + brew()      |
  | + addExtras() |              | + addExtras() |
  +---------------+              +---------------+

```

### Advantages
- Eliminates Code Duplication → Common steps are in one place.
- Promotes Reusability → Subclasses reuse base class logic.
- Encapsulates Algorithm Structure → Enforces a consistent process.

### Disadvantages
- Limited Flexibility → If the template method is too rigid, it might not fit all scenarios.
- Subclass Dependency → Changes in the base class can affect all subclasses.
