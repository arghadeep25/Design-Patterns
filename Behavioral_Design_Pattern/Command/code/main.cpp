#include <iostream>
#include <memory>
#include <vector>

// Receiver
class Light {
 public:
  void turn_on() { std::cout << "Light is ON" << std::endl; }

  void turn_off() { std::cout << "Light is OFF" << std::endl; }
};

// Command Interface
class Command {
 public:
  virtual ~Command() = default;
  virtual void execute() const = 0;
};

// Concrete commands
class TunONCommand : public Command {
 private:
  std::shared_ptr<Light> light_ptr;

 public:
  explicit TunONCommand(std::shared_ptr<Light> light)
      : light_ptr(std::move(light)) {}
  void execute() const override { light_ptr->turn_on(); }
};

class TunOFFCommand : public Command {
 private:
  std::shared_ptr<Light> light_ptr;

 public:
  explicit TunOFFCommand(std::shared_ptr<Light> light)
      : light_ptr(std::move(light)) {}
  void execute() const override { light_ptr->turn_off(); }
};

// Invoker
class RemoteControl {
 private:
  std::vector<std::shared_ptr<Command>> command_ptrs;

 public:
  void set_command(const std::shared_ptr<Command> &command) {
    command_ptrs.push_back(command);
  }

  void press_button() {
    for (const auto &command : command_ptrs) command->execute();
  }
};

int main() {
  std::shared_ptr<Light> light = std::make_shared<Light>();
  std::shared_ptr<Command> turn_on = std::make_shared<TunONCommand>(light);
  std::shared_ptr<Command> turn_off = std::make_shared<TunOFFCommand>(light);

  RemoteControl remote;
  remote.set_command(turn_on);
  

  std::cout << "Pressing Remote Button" << std::endl;
  remote.press_button();
  remote.set_command(turn_off);
}