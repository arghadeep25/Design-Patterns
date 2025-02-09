#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

// Observer Interface
class Observer {
 public:
  virtual ~Observer() = default;
  virtual void update(const float &) = 0;
};

// Subject Interface
class Subject {
 public:
  virtual ~Subject() = default;
  virtual void attach(const std::shared_ptr<Observer> &) = 0;
  virtual void detach(const std::shared_ptr<Observer> &) = 0;
  virtual void notify() = 0;
};

// Concrete Subject
class WeatherStation : public Subject {
 private:
  std::vector<std::shared_ptr<Observer>> observers;
  float temperature;

 public:
  void set_temperature(const float &temperature) {
    this->temperature = temperature;
    this->notify();
  }

  void attach(const std::shared_ptr<Observer> &observer) override {
    this->observers.push_back(observer);
  }

  void detach(const std::shared_ptr<Observer> &observer) override {
    this->observers.erase(
        std::remove_if(this->observers.begin(), this->observers.end(),
                       [&observer](const std::shared_ptr<Observer> &obs) {
                         return obs == observer;
                       }),
        this->observers.end());
  }

  void notify() override {
    for (const auto &observer : this->observers) {
      observer->update(this->temperature);
    }
  }
};

// Concrete Observers
class Laptop : public Observer {
 public:
  void update(const float &temperature) {
    std::cout << "Laptop: " << temperature << std::endl;
  }
};

class Phone : public Observer {
 public:
  void update(const float &temperature) {
    std::cout << "Phone: " << temperature << std::endl;
  }
};

int main() {
  std::shared_ptr<WeatherStation> weather_station =
      std::make_shared<WeatherStation>();
  std::shared_ptr<Phone> phone = std::make_shared<Phone>();
  std::shared_ptr<Laptop> laptop = std::make_shared<Laptop>();

  weather_station->attach(phone);
  weather_station->attach(laptop);

  weather_station->set_temperature(20.3);
  weather_station->set_temperature(28.3);

  weather_station->detach(phone);
  weather_station->set_temperature(26.3);
}