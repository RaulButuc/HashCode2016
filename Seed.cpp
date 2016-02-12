#include "Seed.h"

typedef unsigned int uint;
typedef std::pair<double, double> pdd;

namespace hashcode {

  Seed::Seed() { }

  Seed::Seed(uint _clusterID, pdd _location) {
    clusterID = _clusterID;
    location = _location;
  }

  void Seed::setClusterID(uint _clusterID) {
    clusterID = _clusterID;
  }

  void Seed::setLocation(double _xLocation, double _yLocation) {
    location.first = _xLocation;
    location.second = _yLocation;
  }

  void Seed::setLocation(pdd _location) {
    location = _location;
  }

  uint Seed::getClusterID() {
    return clusterID;
  }

  pdd Seed::getLocation() {
    return location;
  }

  Seed::~Seed() { }

}
