#ifndef SEED_H
#define SEED_H

#include <vector>
#include <utility>

typedef unsigned int uint;
typedef std::pair<double, double> pdd;

namespace hashcode {

  class Seed {
  
    private:
      uint clusterID;
      pdd location;
    
    public:
      Seed();
      Seed(uint, pdd);
      void setClusterID(uint);
      void setLocation(double, double);
      void setLocation(pdd);
      uint getClusterID();
      pdd getLocation();
      ~Seed();

  };

}

#endif
