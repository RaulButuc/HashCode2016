#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <utility>

typedef unsigned int uint;
typedef std::pair<uint, uint> pii;
typedef std::vector<uint> vi;

namespace hashcode {

  class Order {

    private:
      uint clusterID;
      pii location;
      uint itemCount;
      vi itemTypes;

    public:
      Order();
      Order(uint, pii, uint, vi);
      void setClusterID(uint);
      void setLocation(uint, uint);
      void setItemCount(uint);
      void setItemTypes(vi);
      uint getClusterID();
      pii getLocation();
      uint getItemCount();
      vi getItemTypes();
      ~Order();

  };

}

#endif ORDER_H
