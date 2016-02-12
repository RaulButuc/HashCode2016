#include "Order.h"

typedef unsigned int uint;
typedef std::pair<uint, uint> pii;
typedef std::vector<uint> vi;

namespace hashcode {

  Order::Order() { }

  Order::Order(uint _clusterID, pii _location, uint _itemCount, vi _itemTypes) {
    clusterID = _clusterID;
    location = _location;
    itemCount = _itemCount;
    itemTypes = _itemTypes;
  }

  void Order::setClusterID(uint _clusterID) {
    clusterID = _clusterID;
  }

  void Order::setLocation(uint _xLocation, uint _yLocation) {
    location.first = _xLocation;
    location.second = _yLocation;
  }

  void Order::setItemCount(uint _itemCount) {
    itemCount = _itemCount;
  }

  void Order::setItemTypes(vi _itemTypes) {
    itemTypes = _itemTypes;
  }

  uint Order::getClusterID() {
    return clusterID;
  }

  pii Order::getLocation() {
    return location;
  }

  uint Order::getItemCount() {
    return itemCount;
  }

  vi Order::getItemTypes() {
    return itemTypes;
  }

  Order::~Order() { }

}
