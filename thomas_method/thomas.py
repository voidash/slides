#! /bin/python3


# thomas method to solve 4 *4 matrix
import numpy as np

# solving for 4 equations
n = 4
lhs = np.array([[2,-1,0,0],[-1,2,-1,0],[0,-1,2,-1],[0,0,-1,2]])
# r1, r2, r3, r4
rhs = [1,0,0,1]


b = []
d = []
a = []

# extract b,d and a from the lhs  
for row_index,row in enumerate(lhs):
    for col_index,val in enumerate(row):
        if row_index == col_index:
            d.append(val)
        elif row_index == col_index + 1:
            b.append(val)
        elif row_index + 1 == col_index:
            a.append(val)


# there are 4 iterations because we have 4 equations   
a_val = []
r_val = []
for i in range(0, 4):
    if i != 0:
        x = a[i] / (d[i] - b[i]*a[i-1])
        y = (rhs[i] - b[i]*rhs[i-1])/(d[i] - b[i]*a[i-1])
    else:
        x = a[i] / d[i]
        y = rhs[i] / d[i]

    print("{} iteration a = {} , r = {}".format(i,x,y))

    a_val.append(x)
    r_val.append(y)

    # use the updated value instead of old one in next iteration
    a[i] = x
    rhs[i] = r_val[i]

# to actually calculate the values of x 
# xn = rn 
x = np.zeros(n)
x[n-1] = r_val[n-1]

for i in range(n-2,0,-1):
    x[i] = (r_val[i] - a_val[i]*x[i+1])

print(x)
