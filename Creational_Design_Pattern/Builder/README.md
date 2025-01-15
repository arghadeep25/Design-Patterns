## Builder

### Real World Analogy

### Problem

### Solution

```
          +------------------------+
          |  ConstructionDirector  |
          +------------------------+
                    |
                    | Uses
                    v
          +----------------+
          | HouseBuilder   |<---------------------+
          | (Abstract)     |                      |
          +----------------+                      |
                    ^                             |
                    | Implements                  |
     +-------------------------------+            |
     |                               |            |
+-------------------+       +-------------------+ |
|   WoodenBuilder   |       |    OtherBuilder   | |
+-------------------+       +-------------------+ |
          |                                    |
          +------------------------------------+
                    |
                    v
          +----------------+
          |     House      |
          +----------------+
          |  - walls       |
          |  - roof        |
          |  - doors       |
          |  - windows     |
          +----------------+

```

### Advantages

### Disadvantages