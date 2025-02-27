## State
The State pattern allows an object to alter its behavior when its internal state changes. The object appears to change its class at runtime.

### Real-World Analogy
Think of a traffic light:

- It can be red, yellow, or green.
- When the light changes, its behavior changes accordingly (cars stop, prepare, or go).
- The light follows a predefined transition between states.

Similarly, the State pattern allows an object to change its behavior dynamically by transitioning between different states.

### Components
- Context: Maintains the current state and delegates behavior to it.
- State Interface: Declares common behavior for all states.
- Concrete States: Implement different behaviors depending on the current state.

### Problem
Imagine a Document Editor with different editing modes (View, Edit, Read-Only).

- Without the State pattern, we might rely on `if-else` or `switch` statements everywhere to check the current mode.
- This becomes hard to maintain when new states are added.

### Solution
Instead of using multiple conditionals, define separate classes for each state and let the context delegate behavior to the current state.

```
+----------------+
|    Context     |
| - state        |<-------------------+
| + set_state()  |                    |
| + request()    |                    |
+----------------+                    |
       |                              |
       v                              |
+----------------+      +-----------------+
|  State         |      | ConcreteStateA  |
| + handle()     |      | + handle()      |
+----------------+      +-----------------+
       |                               |
       v                               |
+----------------+       +-----------------+
| ConcreteStateB |       | ConcreteStateC  |
| + handle()     |       | + handle()      |
+----------------+       +-----------------+

```

### Advantages
- Encapsulates state-specific behavior: Makes code cleaner.
- Easier to add new states: Just create a new state class.
- Eliminates complex conditional logic.

### Disadvantages
- Can increase the number of classes: More structure needed.
- Requires careful state transition management.
