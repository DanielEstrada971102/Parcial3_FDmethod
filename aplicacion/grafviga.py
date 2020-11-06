import matplotlib.pyplot as plt
import numpy as np

X,Y,YFD, YRK4 = np.loadtxt('aplicacion/viga.txt', unpack=True)

plt.plot(X,Y,"*")
plt.plot(X,YFD)
plt.xlabel("X")
plt.ylabel("Y")
plt.grid()
plt.show()
