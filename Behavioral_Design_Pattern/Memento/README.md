## Memento
The Memento Pattern is a behavioral design pattern that allows capturing an object's state and restoring it later without exposing its internal structure. It enables undo/redo functionality.

### Real-World Analogy
Think of a video game save system:

- Before entering a difficult battle, the player saves their game state.
- If they lose, they can reload the saved state and try again.
- The player doesn’t need to know how the game internally manages health, inventory, or position—just that the previous state is restored.

### Components
- Originator – The object whose state needs to be saved and restored.
- Memento – Stores the internal state of the Originator.
- Caretaker – Manages the memento objects (e.g., keeps a history stack for undo functionality).

### Problem
Imagine a text editor that allows undo/redo functionality. Without a proper structure, we might expose internal variables, making the system complex and error-prone.

We need a mechanism to store and restore the editor’s state without exposing its internal details.

### Solution
The Memento Pattern allows us to:
- Store the object's state in a Memento.
- Keep multiple Mementos in a Caretaker for undo/redo.
- Restore the Originator to a previous state when needed.

```
+---------------+       +---------------+       +----------------+
|   Originator  |       |   Memento     |       |   Caretaker    |
+---------------+       +---------------+       +----------------+
| - state       |       | - state       |       | - history[]    |
| + save()      |------>| + get_state() |       | + add_memento()|
| + restore()   |<------|               |       | + get_memento()|
+---------------+       +---------------+       +----------------+

```

### Advantages
- Encapsulation – Internal state remains hidden.
- Undo/Redo support – Easily revert to previous states.
- Separation of Concerns – The Originator doesn’t need to manage history.

### Disadvantages
- Memory Overhead – Storing multiple states can consume memory.
- Complexity – Requires careful handling of mementos to avoid issues.