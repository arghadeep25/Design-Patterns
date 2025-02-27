# Flyweight: stores shared tree data
class TreeType:
    def __init__(self, name: str, color: str, texture: str) -> None:
        self.name: str = name
        self.color: str = color
        self.texture: str = texture

    def render(self, x: float, y: float):
        print(
            f"Rendering Tree: {self.name} of color: {self.color} and texture: {self.texture} at position x: {x}, y: {y}"
        )


# Flyweight factory: manages shared tree types
class TreeFactory:
    def __init__(self) -> None:
        self.tree_types = {}

    def get_tree_type(self, name: str, color: str, texture: str):
        key: str = name + "_" + color + "_" + texture
        if key not in self.tree_types:
            self.tree_types[key] = TreeType(name, color, texture)
        return self.tree_types[key]


# Unshared flyweight: Tree instance with unique position
class Tree:
    def __init__(self, x: float, y: float, type: TreeType) -> None:
        self.x: float = x
        self.y: float = y
        self.type = type

    def draw(self):
        self.type.render(self.x, self.y)


# client code
def main():
    tree_factory = TreeFactory()
    trees = []
    trees.append(Tree(10, 20, tree_factory.get_tree_type("oak", "green", "bark")))
    trees.append(Tree(10, 20, tree_factory.get_tree_type("pine", "dark green", "pine")))
    trees.append(Tree(50, 60, tree_factory.get_tree_type("oak", "green", "bark")))

    for tree in trees:
        tree.draw()


if __name__ == "__main__":
    main()
