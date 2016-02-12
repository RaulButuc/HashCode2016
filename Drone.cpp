#include "Drone.h"

namespace hashcode {
  
  Drone::Drone() { }

  Drone::Drone(uint _id, uint _weight, uint _lifespan) {
    id = _id;
    weight = _weight;
    lifespan = _lifespan;
  }

  void Drone::setId(uint _id) {
    id = _id;
  }

  void Drone::setWeight(uint _weight) {
    weight = _weight;
  }

  void Drone::setLifespan(uint _lifespan) {
    lifespan = _lifespan;
  }

  uint Drone::getId() {
    return id;
  }

  uint Drone::getWeight() {
    return weight;
  }

  uint Drone::getLifespan() {
    return lifespan;
  }

  void Drone::load() {
    lifespan--;
    // TODO: complete method
  }

  void Drone::unload() {
    lifespan--;
    // TODO: complete method
  }

  void Drone::wait() {
    // TODO: complete method
  }

  void Drone::deliver() {
    // TODO: complete method
  }

  Drone::~Drone() { }

}
