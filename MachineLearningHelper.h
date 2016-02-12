#ifndef MACHINE_LEARNING_HELPER_H
#define MACHINE_LEARNING_HELPER_H

#include <vector>
#include <utility>
#include <algorithm>
#include "Order.h"
#include "Seed.h"
#include "Warehouse.h"

typedef unsigned int uint;
typedef std::pair<uint, uint> pii;
typedef std::pair<pii, double> ppiid;
typedef std::vector<uint> vi;
typedef std::vector<ppiid> vppiid;
typedef std::vector<hashcode::Order> vo;
typedef std::vector<hashcode::Seed> vs;
typedef std::vector<hashcode::Warehouse> vw;

namespace hashcode {

  class MachineLearningHelper {
    
    private:
      struct ppiidGreaterThan {
        bool operator()(const ppiid &left, const ppiid &right) {
          return left.second > right.second;
        }
      };

      static vs centroids;
      static vi costsForClusters;
      static vppiid distancesCentroidToWarehouse;

    public:
      MachineLearningHelper();
      static void getCentroids(vs&);
      static void getCostsForClusters(vi&);
      static void getDistancesCentroidToWarehouse(vppiid&);
      static inline double getDistance(double, double, double, double);
      static inline void K_means(uint, vo);
      static inline void computeCostsForClusters(vo, vw);
      ~MachineLearningHelper();

  };

}

#endif
