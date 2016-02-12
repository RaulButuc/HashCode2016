#include <fstream>
#include "Drone.h"
#include "Order.h"
#include "Seed.h"
#include "Warehouse.h"
#include "MachineLearningHelper.h"

typedef unsigned int uint;
typedef std::pair<uint, uint> pii;
typedef std::pair<uint, double> pid;
typedef std::pair<pii, double> ppiid;
typedef std::vector<uint> vi;
typedef std::vector<pii> vpii;
typedef std::vector<pid> vpid;
typedef std::vector<ppiid> vppiid;
typedef std::vector<hashcode::Drone> vd;
typedef std::vector<hashcode::Order> vo;
typedef std::vector<hashcode::Seed> vs;
typedef std::vector<hashcode::Warehouse> vw;

void readData(uint&, uint&, uint&, uint&, uint&, uint&, uint&, uint&, vi&, vd&, vo&, vw&);
void solve(uint, uint);
void writeData(vo);

int main(int argc, char *argv[]) {
  uint rows, cols, nrDrones, lifespan, maxWeight, nrTypes, nrWarehouses, nrOrders;
  vi productWeights;
  vd drones;
  vo orders;
  vw warehouses;

  readData(rows, cols, nrDrones, lifespan, maxWeight, nrTypes, nrWarehouses, nrOrders, productWeights, drones, orders, warehouses);
  hashcode::MachineLearningHelper::K_means(nrWarehouses, orders);
  hashcode::MachineLearningHelper::computeCostsForClusters(orders, warehouses);
  solve(nrDrones, maxWeight);
  writeData(orders);

  return 0;
}

void readData(uint &rows, uint &cols, uint &nrDrones, uint &lifespan, uint &maxWeight, uint &nrTypes, 
    uint &nrWarehouses, uint &nrOrders, vi &productWeights, vd &drones, vo &orders, vw &warehouses) {
  std::fstream in("input.txt", std::ios::in);

  in >> rows >> cols >> nrDrones >> lifespan >> maxWeight;
  
  for (auto i = 0; i < nrDrones; ++i) {
    hashcode::Drone drone(i, maxWeight, lifespan);
    drones.push_back(drone);
  }

  in >> nrTypes;
  
  for (auto i = 0; i < nrTypes; ++i) {
    uint x;
    in >> x;
    productWeights.push_back(x);
  }

  in >> nrWarehouses;

  for (auto i = 0; i < nrWarehouses; ++i) {
    uint x, y;
    vi cardinalityOfProducts;

    in >> x >> y;

    for (auto j = 0; j < nrTypes; ++j) {
      uint z;
      in >> z;
      cardinalityOfProducts.push_back(z);
    }
  
    hashcode::Warehouse warehouse(std::make_pair(x, y), cardinalityOfProducts);
    warehouses.push_back(warehouse);
  }

  in >> nrOrders;

  for (auto i = 0; i < nrOrders; ++i) {
    uint x, y, nrItems;
    vi productTypes;

    in >> x >> y >> nrItems;

    for (auto j = 0; j < nrItems; ++j) {
      uint z;
      in >> z;
      productTypes.push_back(z);
    }

    hashcode::Order order(0, std::make_pair(x, y), nrItems, productTypes);
    orders.push_back(order);
  }

  in.close();
}

void solve(uint nrDrones, uint maxWeight) {
  vi costsForClusters;
  vs centroids;
  vppiid distancesCentroidToWarehouse;

  hashcode::MachineLearningHelper::getCostsForClusters(costsForClusters);
  hashcode::MachineLearningHelper::getCentroids(centroids);
  hashcode::MachineLearningHelper::getDistancesCentroidToWarehouse(distancesCentroidToWarehouse);

  while (nrDrones > 0 || centroids.size() > 0) {
    hashcode::Seed localCluster = centroids.at(distancesCentroidToWarehouse.at(0).first.first);
    double minDist = distancesCentroidToWarehouse.at(0).second;
    uint dronesToBeRemoved = minDist / maxWeight;
    uint droneIndex = 0;
    vpid distancesOrderToCentroid;

    nrDrones -= dronesToBeRemoved;    
    
    // TODO: complete method

  }
}

void writeData(vo orders) {
  std::fstream out("output.txt", std::ios::out);

  for (auto it = orders.begin(); it != orders.end(); ++it) {
    out << it->getLocation().first << " " << it->getLocation().second << " " << it->getClusterID() << "\n";
  }

  // TODO: output the required commands
  
  out.close();
}
