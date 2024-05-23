from m5.params import *
from m5.SimObject import SimObject

class VectorOperations(SimObject):
    type = 'VectorOperations'
    cxx_header = "Assignment2/vector_operations.hh"
    cxx_class = "gem5::VectorOperations"

    wait1= Param.Latency("150")

    wait2 = Param.Latency("1500")

    wait3 = Param.Latency("15000")

    Vector_1=VectorParam.Int([2.0,5.0,6.0])

    Vector_2=VectorParam.Int([1.0,2.0,3.0])

  
