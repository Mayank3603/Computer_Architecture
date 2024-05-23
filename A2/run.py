import m5
from m5.objects import *
root = Root(full_system = False)
root.result = VectorOperations()
root.result.wait1 = input("Enter cross time:")
root.result.wait2 = input("Enter normalize time:")
root.result.wait3 = input("Enter subtarction time:")


vec1=[]
vec2=[]
for i in range(3):
    val=input(f"Enter Vector1 element {i+1} : ")
    vec1.append(val)
for i in range(3):
    val=input(f"Enter Vector2 element {i+1} : ")
    vec2.append(val)

root.result.Vector_1=vec1
root.result.Vector_2=vec2
m5.instantiate()

print("Beginning simulation!")
exit_event = m5.simulate()
print('Exiting @ tick {} because {}'
      .format(m5.curTick(), exit_event.getCause()))
