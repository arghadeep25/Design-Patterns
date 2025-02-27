#include <iostream>
#include <memory>

/**
 * @brief Abstract product: Smart Speaker
 *
 */
class SmartSpeaker {
 public:
  explicit SmartSpeaker() = default;

 public:
  virtual ~SmartSpeaker() = default;

 public:
  virtual void playMusic() const = 0;
};

/**
 * @brief Abstract product: Smart Light
 *
 */
class SmartLight {
 public:
  explicit SmartLight() = default;

 public:
  virtual ~SmartLight() = default;

 public:
  virtual void turnOn() const = 0;
};

// Alexa-Compatible Speaker
class EchoSpeaker : public SmartSpeaker {
 public:
  EchoSpeaker() = default;

 public:
  ~EchoSpeaker() = default;

 public:
  void playMusic() const override {
    std::cout << "Playing music on Echo Speaker" << std::endl;
  }
};

// Alexa-Compatible Light
class AlexaLight : public SmartLight {
 public:
  AlexaLight() = default;

 public:
  ~AlexaLight() = default;

 public:
  void turnOn() const override {
    std::cout << "Turning on Alexa light" << std::endl;
  }
};

// Google Home Compatible Speaker
class NestSpeaker : public SmartSpeaker {
 public:
  NestSpeaker() = default;

 public:
  ~NestSpeaker() = default;

 public:
  void playMusic() const override {
    std::cout << "Playing music on Nest Speaker" << std::endl;
  }
};

// Google Light
class GoogleLight : public SmartLight {
 public:
  GoogleLight() = default;

 public:
  ~GoogleLight() = default;

 public:
  void turnOn() const override {
    std::cout << "Turning on Google light" << std::endl;
  }
};

// Smart Device Factory
class SmartDeviceFactory {
 public:
  explicit SmartDeviceFactory() = default;

 public:
  virtual ~SmartDeviceFactory() = default;

 public:
  virtual std::unique_ptr<SmartSpeaker> createSpeaker() const = 0;

 public:
  virtual std::unique_ptr<SmartLight> createLight() const = 0;
};

// Alexa Device Factory
class AlexaDeviceFactory : public SmartDeviceFactory {
 public:
  AlexaDeviceFactory() = default;

 public:
  ~AlexaDeviceFactory() = default;

 public:
  std::unique_ptr<SmartSpeaker> createSpeaker() const override {
    return std::make_unique<EchoSpeaker>();
  }

 public:
  std::unique_ptr<SmartLight> createLight() const override {
    return std::make_unique<AlexaLight>();
  }
};

// Google Device Factory
class GoogleDeviceFactory : public SmartDeviceFactory {
 public:
  GoogleDeviceFactory() = default;

 public:
  ~GoogleDeviceFactory() = default;

 public:
  std::unique_ptr<SmartSpeaker> createSpeaker() const override {
    return std::make_unique<NestSpeaker>();
  }

 public:
  std::unique_ptr<SmartLight> createLight() const override {
    return std::make_unique<GoogleLight>();
  }
};

void userSmartHome(const SmartDeviceFactory& factory) {
  auto speaker = factory.createSpeaker();
  auto light = factory.createLight();

  speaker->playMusic();
  light->turnOn();
}

int main() {
  AlexaDeviceFactory alexa_device;
  GoogleDeviceFactory google_device;

  userSmartHome(alexa_device);
  userSmartHome(google_device);
}
