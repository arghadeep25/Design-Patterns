#include <iostream>
#include <memory>

// Component (Base Interface)
class TextEditor {
 public:
  virtual ~TextEditor() = default;
  virtual void write() const = 0;
};

// Concrete Component (Original Object)
class BasicTextEditor : public TextEditor {
 public:
  void write() const override {
    std::cout << "Writing plain text... " << std::endl;
  }
};

// Decorator (Abstract Wrapper)
class TextEditorDecorator : public TextEditor {
 protected:
  std::shared_ptr<TextEditor> editor_ptr;

 public:
  explicit TextEditorDecorator(std::shared_ptr<TextEditor> editor)
      : editor_ptr(std::move(editor)) {}
  void write() const override { editor_ptr->write(); }
};

// Concrete Decorators (Extensions)
class SpellChecker : public TextEditorDecorator {
 public:
  using TextEditorDecorator::TextEditorDecorator;
  void write() const override {
    editor_ptr->write();
    std::cout << "Checking spelling..." << std::endl;
  }
};

class GrammarCheck : public TextEditorDecorator {
 public:
  using TextEditorDecorator::TextEditorDecorator;
  void write() const override {
    editor_ptr->write();
    std::cout << "Checking grammar..." << std::endl;
  }
};

class AutoSuggest : public TextEditorDecorator {
 public:
  using TextEditorDecorator::TextEditorDecorator;
  void write() const override {
    editor_ptr->write();
    std::cout << "Providing auto-suggestion..." << std::endl;
  }
};

// Client Code
int main() {
  std::shared_ptr<TextEditor> basic_editor =
      std::make_shared<BasicTextEditor>();

  std::shared_ptr<TextEditor> spell_check =
      std::make_shared<SpellChecker>(basic_editor);
  std::shared_ptr<TextEditor> grammar_check =
      std::make_shared<GrammarCheck>(spell_check);
  std::shared_ptr<TextEditor> auto_suggest =
      std::make_shared<AutoSuggest>(grammar_check);

  std::cout << " -- Basic Editor: -- " << std::endl;
  basic_editor->write();

  std::cout << " -- Basic Editor with Spell Check: -- " << std::endl;
  spell_check->write();

  std::cout << " -- Basic Editor with Grammar Check: -- " << std::endl;
  grammar_check->write();

  std::cout << " -- Basic Editor with Auto-Suggest: -- " << std::endl;
  auto_suggest->write();
}
