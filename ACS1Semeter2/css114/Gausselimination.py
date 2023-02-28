import numpy as np
# mj = 0.0
metrix = [[2, 6, 1,7],
        [1, 2, -1,-1],
        [5,7,-4,9]
]

for i in range(1,len(metrix)):
    for j in range(len(metrix[i])):
        metrix[1][0] = (metrix[i][j] - metrix[0][j]*(metrix[i][0]/metrix[0][0]))

print(np.asmatrix(metrix))