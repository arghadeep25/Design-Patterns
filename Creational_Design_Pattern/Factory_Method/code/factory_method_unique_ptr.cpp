#include <iostream>
#include <memory>

/**
 * @brief abstract transportation class
 *
 */
class Transport {
 public:
  /**
   * @brief default constructor is explicitly defined and ensure
   *        no implicit conversion when creating derived class.
   *
   */
  explicit Transport() = default;

 public:
  /**
   * @brief default destructor. if not virtual not used it might
   *        lead to undefined behaviour. with virtual destructor
   *        the derived class's destructor is called first followed
   *        by base class destructor ensuring proper cleanup.
   *
   */
  virtual ~Transport() = default;

 public:
  /**
   * @brief pure virtual function
   *
   */
  virtual void deliver() const = 0;
};

/**
 * @brief transportation by truck class
 *
 */
class Truck : public Transport {
 public:
  /**
   * @brief default constructor but here explicit is not
   *        necessary as there are no parameters.
   *
   */
  explicit Truck() = default;

 public:
  /**
   * @brief default destructor. here virtual is not necessary
   *        as the base class destructor already has a virtual
   *        destructor. no need for redeclaration.
   *
   */
  virtual ~Truck() = default;

 public:
  void deliver() const override {
    std::cout << "delivering by land in a truck" << std::endl;
  }
};

/**
 * @brief transportation by ship class
 *
 */
class Ship : public Transport {
 public:
  Ship() = default;

 public:
  ~Ship() = default;

 public:
  void deliver() const override {
    std::cout << "delivering by sea in a ship" << std::endl;
  }
};

/**
 * @brief transportation by plane class
 *
 */
class Plane : public Transport {
 public:
  Plane() = default;

 public:
  ~Plane() = default;

 public:
  void deliver() const override {
    std::cout << "delivering by air in a plane" << std::endl;
  }
};

/**
 * @brief Logistics base class
 *
 */
class Logistics {
 public:
  explicit Logistics() = default;

 public:
  virtual ~Logistics() = default;

 public:
  /**
   * @brief pure virtual function
   *
   * @return Transport*
   */
  virtual std::unique_ptr<Transport> createTransport() const = 0;

 public:
  void planDelivery() const {
    auto transport = createTransport();
    transport->deliver();
  }
};

class RoadLogistics : public Logistics {
 public:
  RoadLogistics() = default;

 public:
  ~RoadLogistics() = default;

 public:
  std::unique_ptr<Transport> createTransport() const override {
    return std::make_unique<Truck>();
  }
};

class SeaLogistics : public Logistics {
 public:
  SeaLogistics() = default;

 public:
  ~SeaLogistics() = default;

 public:
  std::unique_ptr<Transport> createTransport() const override {
    return std::make_unique<Ship>();
  }
};

class AirLogistics : public Logistics {
 public:
  AirLogistics() = default;

 public:
  std::unique_ptr<Transport> createTransport() const override {
    return std::make_unique<Plane>();
  }
};

int main() {
  Logistics* logistics;

  // road delivery
  logistics = new RoadLogistics();
  logistics->planDelivery();

  // sea delivery
  logistics = new SeaLogistics();
  logistics->planDelivery();

  // air delivery
  logistics = new AirLogistics();
  logistics->planDelivery();
}
