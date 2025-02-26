## Chain of Responsibility
The Chain of Responsibility pattern allows multiple objects to handle a request without the sender needing to know which object will process it. The request is passed along a chain of handlers until one of them processes it.

### Real-World Analogy
Consider a customer service support system:

- A customer submits a request.
- The request is first checked by a junior support agent.
- If the junior agent can't resolve it, the request is forwarded to a senior agent.
- If needed, it goes to the manager.
- The request is handled by the first capable person in the chain.

### Components

- Handler (Abstract Class/Interface) – Defines an interface for processing requests and setting the next handler.
- Concrete Handlers – Specific classes that handle requests or pass them to the next handler.
- Client – Sends requests to the first handler in the chain.

### Problem
A system needs to process requests dynamically based on availability, priority, or hierarchy. Hardcoding request handling logic leads to tight coupling and reduced flexibility.

### Solution
Implement a chain of handlers where each one decides whether to process the request or pass it to the next. This reduces coupling and improves scalability.

### UML Diagram
<p align="center">
  <img src="../../out/Behavioral_Design_Pattern/Chain of Responsibility/chain_of_responsibility/chain_of_responsibility.png">
</p>

### Advantages
- Decouples sender and receiver.
- Flexible request processing (handlers can be modified or extended without affecting clients).
- Supports dynamic behavior (chains can be constructed at runtime).

### Disadvantages
- Can make debugging harder if the request passes through multiple handlers.
- Potential performance overhead if the chain is long and inefficiently structured.