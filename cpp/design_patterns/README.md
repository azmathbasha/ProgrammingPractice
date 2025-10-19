# Design Patterns (C++)

This folder contains small, self-contained C++ examples demonstrating common design patterns, grouped by category.

Folders:
- `Creational/` — patterns for object creation
- `Structural/` — patterns for composing classes and objects
- `Behavioral/` — patterns for communication between objects

Each pattern directory contains a demo `.cpp` file you can compile with:

```bash
g++ -std=c++17 -O2 path/to/Example.cpp -o Example && ./Example
```

Mermaid overview diagram:

```mermaid
graph TB
  subgraph Creational
    A[FactoryMethod] --> B[AbstractFactory]
    A --> C[Builder]
    A --> D[Prototype]
    ````markdown
    # Design Patterns (C++)

    This folder contains small, self-contained C++ examples demonstrating common design patterns, grouped by category. Each example is a tiny, runnable demo that focuses on the pattern intent and a small real-world scenario.

    Folders:
    - `Creational/` — patterns for object creation
    - `Structural/` — patterns for composing classes and objects
    - `Behavioral/` — patterns for communication between objects

    Quick compile/run for an example:

    ```bash
    g++ -std=c++17 -O2 path/to/Example.cpp -o Example && ./Example
    ```

    Mermaid overview diagram:

    ```mermaid
    graph TB
      subgraph Creational
        A[FactoryMethod]
        B[AbstractFactory]
        C[Builder]
        D[Prototype]
        E[Singleton]
      end
      subgraph Structural
        F[Adapter]
        G[Bridge]
        H[Composite]
        I[Decorator]
        J[Facade]
        K[Flyweight]
        L[Proxy]
      end
      subgraph Behavioral
        M[ChainOfResponsibility]
        N[Command]
        O[Interpreter]
        P[Iterator]
        Q[Mediator]
        R[Memento]
        S[Observer]
        T[State]
        U[Strategy]
        V[TemplateMethod]
        W[Visitor]
      end
    ```

    Examples & short scenarios (one line each):

    - FactoryMethod: create documents of different kinds (Resume vs Report) depending on department.
    - AbstractFactory: build families of UI widgets for different OS themes.
    - Builder: construct complex objects step-by-step (e.g., house or HTTP request builder).
    - Prototype: clone expensive-to-create objects like pre-configured widgets.
    - Singleton: single shared resource like a configuration or logger.
    - Adapter: adapt a legacy API to your application's interface (e.g., media player adapter).
    - Bridge: separate abstraction from implementation (remote controls vs devices).
    - Composite: treat files and directories uniformly in a tree structure.
    - Decorator: add extra responsibilities to objects like coffee condiments.
    - Facade: provide a simple API to a complex subsystem (home-theater control).
    - Flyweight: share fine-grained objects such as glyphs to save memory.
    - Proxy: control access or lazy-load large resources (virtual proxy for images).
    - ChainOfResponsibility: route requests along handlers (support ticket triage).
    - Command: encapsulate actions as objects for undo/redo or remote invocations.
    - Interpreter: parse/interpret simple domain-specific expressions.
    - Iterator: iterate over a custom collection (playlist, tree traversal iterators).
    - Mediator: centralize communication between components (chatroom or UI dialog coordinator).
    - Memento: capture and restore state for undo operations (text editor snapshots).
    - Observer: publish/subscribe notifications (event bus, UI observers).
    - State: change behavior when object state changes (connection states).
    - Strategy: swap algorithms at runtime (payment or sorting strategies).
    - TemplateMethod: define an algorithm skeleton with overridable steps (data processing pipelines).
    - Visitor: perform type-specific operations across a collection of heterogeneous elements (tax calculation).

    Each subfolder contains a README with a focused mermaid diagram and usage notes for the patterns in that category.

    ````
