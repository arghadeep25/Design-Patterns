from abc import ABC, abstractmethod

# Base Interface
class TextEditor(ABC):
    @abstractmethod
    def write(self) -> None:
        pass

# Original Object
class BasicTextEditor(TextEditor):
    def write(self) -> None:
        print(f"Writing plain text...")

# Decorator: Abstract Wrapper
class TextEditorDecorator(TextEditor):
    def __init__(self, editor: TextEditor):
        self.editor = editor

    def write(self) -> None:
        self.editor.write()

# Concrete Decorator: Spell checker
class SpellChecker(TextEditorDecorator):
    def __init__(self, editor: TextEditorDecorator) -> None:
        self.editor: TextEditorDecorator = editor

    def write(self) -> None:
        self.editor.write()
        print(f"Checking spelling...")


# Concrete Decorator: Grammar checker
class GrammarCheck(TextEditorDecorator):
    def __init__(self, editor: TextEditorDecorator) -> None:
        self.editor: TextEditorDecorator = editor

    def write(self) -> None:
        self.editor.write()
        print(f"Checking grammar...")

# Concrete Decorator: Auto suggestion
class AutoSuggest(TextEditorDecorator):
    def __init__(self, editor: TextEditorDecorator) -> None:
        self.editor: TextEditorDecorator = editor

    def write(self) -> None:
        self.editor.write()
        print(f"Providing auto-suggestion...")

# Client code
def main() -> None:
    basic_editor = BasicTextEditor()
    print(f"--- Basic Editor ---")
    basic_editor.write()

    spell_checker = SpellChecker(basic_editor)
    print(f"--- Basic Editor with Spell Check ---")
    spell_checker.write()

    grammar_check = GrammarCheck(spell_checker)
    print(f"--- Basic Editor with Spell Check and Grammar check ---")
    grammar_check.write()

    auto_suggest = AutoSuggest(grammar_check)
    print(f"--- Basic Editor with Spell Check, Grammar check, and Auto-suggest ---")
    auto_suggest.write()


if __name__ == "__main__":
    main()
