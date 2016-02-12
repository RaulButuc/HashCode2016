#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include <utility>

typedef unsigned int uint;
typedef std::pair<uint, uint> pii;
typedef std::vector<uint> vi;

namespace hashcode {

  class Warehouse {

    private:
      pii location;
      vi cardinalityOfProducts;

    public:
      Warehouse();
      Warehouse(pii, vi);
      void setLocation(uint, uint);
      void setCardinalityOfProducts(vi);
      pii getLocation();
      vi getCardinalityOfProducts();
      ~Warehouse();
  };

}

#endif
