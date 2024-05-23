import matplotlib.pyplot as plt

cache_miss_rate = [0.992201,0.990223,0.989613,0.989427,0.987463,0.985470,0.984840,0.984746,0.979320,0.977586,0.976224,0.976940,0.963995,0.964583,0.961608,
0.959723,0.930879,0.940462,0.926140, 0.925180,0.836640,0.845729,0.852489,0.852353,0.724489,0.724747,0.735865,0.736818,0.589730,0.594389,0.600862,0.604438,0.366380,0.385275,
0.423008,0.431481,
]

l2_size = []
i=2
while(i<11):
    for j in range(4):
        l2_size.append(2**i)
    i=i+1

l2_associativity = []

for i in range(9):
    k=0
    for j in range(4):
        l2_associativity.append(2**k)
        k+=1

data_dict = {1:[],2: [], 4: [], 8: []}
for i in range(36):
    data_dict[l2_associativity[i]].append((l2_size[i], cache_miss_rate[i]))
print(data_dict)
plt.figure(figsize=(10, 6))
for assoc, assoc_values in data_dict.items():
    sizes, miss_rates = zip(*assoc_values)
    plt.plot(sizes, miss_rates, marker='o', label=f'Associativity {assoc}')

plt.xlabel('Cache Size(in kB)')
plt.ylabel('Cache Miss Rate')
plt.title('Cache Miss Rate vs. Cache Size')
plt.xticks(sizes, sizes)  
plt.legend()
plt.tight_layout()
plt.show()
