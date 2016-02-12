#ifndef DRONE_H
#define DRONE_H

typedef unsigned int uint;

namespace hashcode {

  class Drone {

    private:
      uint id;
      uint weight;
      uint lifespan;
  
    public:
      Drone();
      Drone(uint, uint, uint);
      void setId(uint);
      void setWeight(uint);
      void setLifespan(uint);
      uint getId();
      uint getWeight();
      uint getLifespan();

      void load();
      void unload();
      void wait();
      void deliver();
      ~Drone();

  };

}

#endif
