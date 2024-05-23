#include "Assignment2/vector_operations.hh"
#include "base/trace.hh"
#include "debug/VECTOR.hh"
#include "debug/RESULTCROSS.hh"
#include "debug/NORMALIZE.hh"
#include "debug/RESULTSUB.hh"
#include <cmath>


namespace gem5
{

VectorOperations::VectorOperations(const VectorOperationsParams &params) :
    SimObject(params),
   
    
    vector_cross_product([this]{ VectorCrossProduct(); }, name()),
    normalize_vector([this]{ NormalizeVector(); }, name()),
    vector_subtraction([this]{ VectorSubtraction(); }, name()),
    CrossCycles(params.wait1),
    NormalizeCycles(params.wait2),
    SubtractionCycles(params.wait3),
    Vector1(params.Vector_1),
    Vector2(params.Vector_2)


{
 

    DPRINTF(VECTOR, "Vector1 elements: (%d, %d, %d)\n", Vector1[0], Vector1[1], Vector1[2]);
    DPRINTF(VECTOR, "Vector2 elements: (%d, %d, %d)\n", Vector2[0], Vector2[1], Vector2[2]);
}

void VectorOperations::VectorCrossProduct()
{
    float cross_product[3];

    cross_product[0] = Vector1[1] * Vector2[2] - Vector1[2] * Vector2[1];
    cross_product[1] = Vector1[2] * Vector2[0] - Vector1[0] * Vector2[2];
    cross_product[2] = Vector1[0] * Vector2[1] - Vector1[1] * Vector2[0];

    DPRINTF(RESULTCROSS, "Cross product result: (%d, %d, %d)\n",
            cross_product[0], cross_product[1], cross_product[2]);
}

void VectorOperations::NormalizeVector()
{
    double len1 = std::sqrt(Vector1[0] * Vector1[0] + Vector1[1] * Vector1[1] + Vector1[2] * Vector1[2]);
    double len2 = std::sqrt(Vector2[0] * Vector2[0] + Vector2[1] * Vector2[1] + Vector2[2] * Vector2[2]);

    vector<double> normal_vector_1(3);
    normal_vector_1[0] = double(Vector1[0]) / len1;
    normal_vector_1[1] = double(Vector1[1]) / len1;
    normal_vector_1[2] = double(Vector1[2]) / len1;

    vector<double> normal_vector_2(3);
    normal_vector_2[0] = double(Vector2[0]) / len2;
    normal_vector_2[1] = double(Vector2[1]) / len2;
    normal_vector_2[2] = double(Vector2[2]) / len2;

    DPRINTF(NORMALIZE, "Normalized Vector1: (%lf, %lf, %lf)\n", normal_vector_1[0], normal_vector_1[1], normal_vector_1[2]);
    DPRINTF(NORMALIZE, "Normalized Vector2: (%lf, %lf, %lf)\n", normal_vector_2[0], normal_vector_2[1], normal_vector_2[2]);
}

void VectorOperations::VectorSubtraction()
{
    DPRINTF(RESULTSUB, "Vector subtraction result: (%d, %d, %d)\n",
            Vector1[0] - Vector2[0], Vector1[1] - Vector2[1], Vector1[2] - Vector2[2]);
}

void VectorOperations::startup()
{
    schedule(vector_cross_product, CrossCycles);
    schedule(normalize_vector, NormalizeCycles);
    schedule(vector_subtraction, SubtractionCycles);
}

}