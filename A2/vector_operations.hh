#ifndef __VECTOR_OPERATIONS_HH__
#define __VECTOR_OPERATIONS_HH__

#include "params/VectorOperations.hh"
#include "sim/sim_object.hh"
#include <iostream>
#include <vector>
using namespace std;

namespace gem5
{

class VectorOperations : public SimObject
{
  private:
    
    void VectorCrossProduct();
    void NormalizeVector();
    void VectorSubtraction();

    

    EventFunctionWrapper vector_cross_product;
    EventFunctionWrapper normalize_vector;
    EventFunctionWrapper vector_subtraction;

    const Tick CrossCycles;
    const Tick NormalizeCycles;
    const Tick SubtractionCycles;

    vector<int> Vector1;
    vector<int> Vector2;
  public:
    VectorOperations(const VectorOperationsParams &p);

    void startup() override;
};

} 

#endif 