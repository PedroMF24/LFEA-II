from math import cos
import matplotlib.pyplot as plt
import numpy as np

R = np.linspace(2.5,4,10000) # 1,3

X = []
Y = []

for a in R:
    X.append(a)

    x = np.random.random()
    for n in range(100):
        x = a*x*(1-x) # a*cos(x) # x=r*x*(1-x)

    for n in range(100):
        x = a*x*(1-x) # x=r*x*(1-x)

    Y.append(x)

plt.plot(X,Y, ls='', marker=',')
plt.show()
plt.savefig("/Chaos/BifurcMap.png")