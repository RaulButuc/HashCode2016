#include "MachineLearningHelper.h"

namespace hashcode {

  MachineLearningHelper::MachineLearningHelper() { }

  void MachineLearningHelper::getCentroids(vs &_centroids) {
    _centroids = centroids;
  }

  void MachineLearningHelper::getCostsForClusters(vi &_costsForClusters) {
    _costsForClusters = costsForClusters;
  }

  void MachineLearningHelper::getDistancesCentroidToWarehouse(vppiid &_distancesCentroidToWarehouse) {
    _distancesCentroidToWarehouse = distancesCentroidToWarehouse;
  }

  inline double MachineLearningHelper::getDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - y1, 2) + pow(x2 - y2, 2));
  }

  inline void MachineLearningHelper::K_means(uint K, vo orders) {
    bool changedOnThisPass = false;
    uint count = 0;
    vs seeds(K);

    for (auto it = orders.begin(); it != orders.end() && count < K; ++it, ++count) {
      seeds.at(count).setLocation(it->getLocation());
      seeds.at(count).setClusterID(count);
    }

    while (!changedOnThisPass) {
      for (auto it = orders.begin(); it != orders.end(); ++it) {
        hashcode::Seed bestFit = seeds.at(0);

        double x1 = static_cast<double>(it->getLocation().first);
        double y1 = bestFit.getLocation().first;
        double x2 = static_cast<double>(it->getLocation().second);
        double y2 = bestFit.getLocation().second;
        uint bestDist = getDistance(x1, y1, x2, y2);

        for (auto jt = seeds.begin() + 1; jt != seeds.end(); ++jt) {
          x1 = static_cast<double>(it->getLocation().first);
          y1 = static_cast<double>(jt->getLocation().first);
          x2 = static_cast<double>(it->getLocation().second);
          y2 = static_cast<double>(jt->getLocation().second);
          uint currDist = getDistance(x1, y1, x2, y2);

          if (bestDist > currDist) {
            bestDist = currDist;
            bestFit = *jt;
            changedOnThisPass = true;
          }
          else {
            changedOnThisPass = false;
          }
        }

        it->setClusterID(bestFit.getClusterID());
      }

      for (auto i = 0; i < K; ++i) {
        uint xSum = 0, ySum = 0, nrElem = 0;

        for (auto it = orders.begin(); it != orders.end(); ++it) {
          if (it->getClusterID() == i) {
            xSum += it->getLocation().first;
            ySum += it->getLocation().second;
            nrElem++;
          }
        }

        double currClusterX = static_cast<double>(xSum) / nrElem;
        double currClusterY = static_cast<double>(ySum) / nrElem;

        seeds.at(i).setLocation(currClusterX, currClusterY);
        seeds.at(i).setClusterID(i);
      }
    }

    centroids = seeds;
  }

  inline void MachineLearningHelper::computeCostsForClusters(vo orders, vw warehouses) {
    for (auto it = centroids.begin(); it != centroids.end(); ++it) {
      double costForThisCluster = 0;

      for (auto jt = orders.begin(); jt != orders.begin(); ++jt) {
        if (jt->getClusterID() == it->getClusterID()) {
          vi temp = jt->getItemTypes();
          sort(temp.begin(), temp.end());
          temp.erase(std::unique(temp.begin(), temp.end()), temp.end());
          costForThisCluster += temp.size();
          costForThisCluster += sqrt(pow(jt->getLocation().first - it->getLocation().first, 2) +
            pow(jt->getLocation().second - it->getLocation().second, 2));
        }
      }

      costsForClusters.push_back(costForThisCluster);
    }

    for (auto i = 0; i < costsForClusters.size(); ++i) {
      for (auto j = 0; j < warehouses.size(); ++j) {
        double x1, y1, x2, y2, bestDist;
        
        x1 = static_cast<double>(centroids.at(i).getLocation().first);
        y1 = static_cast<double>(warehouses.at(j).getLocation().first);
        x2 = static_cast<double>(centroids.at(i).getLocation().second);
        y2 = static_cast<double>(warehouses.at(j).getLocation().second);
        
        bestDist = costsForClusters.at(i) + MachineLearningHelper::getDistance(x1, y1, x2, y2);
        
        x1 = static_cast<double>(warehouses.at(j).getLocation().first);
        y1 = static_cast<double>(warehouses.at(0).getLocation().first);
        x2 = static_cast<double>(warehouses.at(j).getLocation().second);
        y2 = static_cast<double>(warehouses.at(0).getLocation().second);

        bestDist += MachineLearningHelper::getDistance(x1, y1, x2, y2);

        distancesCentroidToWarehouse.push_back(std::make_pair(std::make_pair(i, j), bestDist));
      }
    }

    sort(distancesCentroidToWarehouse.begin(), distancesCentroidToWarehouse.end(), ppiidGreaterThan());
  }

  MachineLearningHelper::~MachineLearningHelper() { }

}
