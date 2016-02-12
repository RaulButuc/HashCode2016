#include "Warehouse.h"

typedef unsigned int uint;
typedef std::pair<uint, uint> pii;
typedef std::vector<uint> vi;

namespace hashcode {

  Warehouse::Warehouse() { }

  Warehouse::Warehouse(pii _location, vi _cardinalityOfProducts) {
    location = _location;
    cardinalityOfProducts = _cardinalityOfProducts;
  }

  void Warehouse::setLocation(uint _xLocation, uint _yLocation) {
    location.first = _xLocation;
    location.second = _yLocation;
  }

  void Warehouse::setCardinalityOfProducts(vi _cardinalityOfProducts) {
    cardinalityOfProducts = _cardinalityOfProducts;
  }

  pii Warehouse::getLocation() {
    return location;
  }

  vi Warehouse::getCardinalityOfProducts() {
    return cardinalityOfProducts;
  }

  Warehouse::~Warehouse() { }

}
