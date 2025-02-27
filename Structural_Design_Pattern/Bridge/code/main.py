from abc import ABC, abstractmethod


# Abstract Renderer
class Renderer(ABC):
    @abstractmethod
    def render(self, shape: str) -> None:
        pass


# Concrete Renderer: OpenGL
class OpenGLRenderer(Renderer):
    def render(self, shape: str) -> None:
        print(f"Rendering Shape: {shape} using OpenGL")


# Concrete Renderer: DirectX
class DirectXRenderer(Renderer):
    def render(self, shape: str) -> None:
        print(f"Rendering Shape: {shape} using DirectX")


# Abstract Shape
class Shape(ABC):
    def __init__(self, renderer: Renderer) -> None:
        self.renderer: Renderer = renderer

    @abstractmethod
    def draw(self):
        pass


# Concrete Shape: Circle
class Circle(Shape):
    def draw(self) -> None:
        self.renderer.render("circle")


# Concrete Shape: Rectangle
class Rectangle(Shape):
    def draw(self) -> None:
        self.renderer.render("rectangle")


def main():
    opengl_renderer = OpenGLRenderer()
    directx_renderer = DirectXRenderer()

    circle_opengl = Circle(opengl_renderer)
    rectangle_opengl = Rectangle(opengl_renderer)
    circle_opengl.draw()
    rectangle_opengl.draw()

    circle_directx = Circle(directx_renderer)
    rectangle_directx = Rectangle(directx_renderer)
    circle_directx.draw()
    rectangle_directx.draw()


if __name__ == "__main__":
    main()
