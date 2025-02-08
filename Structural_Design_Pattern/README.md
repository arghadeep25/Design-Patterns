# Structural Design Patterns Summary

## Overview
Structural design patterns focus on organizing different classes and objects to form larger structures while keeping these structures flexible and efficient.

## Structural Design Patterns Summary Table
| **Pattern**       | **Purpose** | **Key Characteristics** | **When to Use** |
|------------------|------------|------------------------|----------------|
| **Adapter** | Converts the interface of a class into another interface clients expect. | Acts as a wrapper; provides compatibility without modifying existing code. | When you need to integrate incompatible interfaces. |
| **Bridge** | Decouples an abstraction from its implementation so that the two can evolve independently. | Separates abstraction from implementation; avoids subclass explosion. | When you want to avoid a combinatorial explosion of subclasses. |
| **Composite** | Composes objects into tree structures to represent part-whole hierarchies. | Treats individual objects and compositions uniformly; recursive structure. | When objects should be treated uniformly regardless of hierarchy. |
| **Decorator** | Attaches additional responsibilities to an object dynamically. | Adds behavior dynamically without modifying the original class; flexible. | When you need to add behavior dynamically without modifying the object. |
| **Facade** | Provides a simplified interface to a complex subsystem. | Provides a high-level interface; hides complexity. | When you need to simplify interactions with a complex system. |
| **Flyweight** | Reduces memory usage by sharing objects instead of creating new ones. | Uses object sharing to minimize resource usage; maintains intrinsic and extrinsic states. | When a large number of similar objects exist and memory efficiency is required. |
| **Proxy** | Controls access to an object, adding security, caching, or lazy loading. | Acts as a surrogate; manages access control. | When you need controlled access to an expensive or sensitive object. |

## Similarities and Differences Table
| **Feature**        | **Adapter** | **Bridge** | **Composite** | **Decorator** | **Facade** | **Flyweight** | **Proxy** |
|-------------------|------------|------------|------------|------------|------------|------------|------------|
| **Main Purpose** | Converts incompatible interfaces. | Decouples abstraction from implementation. | Represents part-whole hierarchies. | Dynamically adds behavior to objects. | Simplifies interaction with complex systems. | Shares objects to save memory. | Controls access to an object. |
| **Structural Change** | Introduces a wrapper. | Splits abstraction from implementation. | Uses recursive tree-like structures. | Wraps an object to extend behavior. | Introduces a simplified interface. | Reduces object creation. | Acts as a gateway to another object. |
| **Primary Benefit** | Makes interfaces compatible. | Prevents subclass explosion. | Simplifies hierarchical structures. | Adds features without modifying the class. | Reduces complexity. | Improves memory efficiency. | Adds security, caching, or lazy initialization. |
| **Common Use Case** | Adapting third-party libraries. | Supporting multiple platforms. | Representing UI components. | Enhancing UI components like scrollbars. | Wrapping complex subsystems. | Managing text character objects. | Implementing virtual proxies or remote proxies. |

## Summary of Key Points
- **Structural design patterns** help structure classes and objects to improve code flexibility and efficiency.
- **Adapter, Bridge, and Facade** deal with modifying or simplifying interfaces.
- **Composite and Decorator** focus on organizing object hierarchies and dynamically adding behavior.
- **Flyweight and Proxy** optimize object usage by sharing instances or controlling access.
- These patterns ensure better **scalability, maintainability, and reusability** of software systems.


