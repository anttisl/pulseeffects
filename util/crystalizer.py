#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt

f1, f2 = 50.0, 60.0  # frequencias

x = 100.0
t1, t2 = 0.0, 100.0

# frequencia angular
omega1, omega2 = 2.0 * np.pi * f1, 2.0 * np.pi * f2


def y1(x, t): return np.cos(omega1 * t)


def y2(x, t): return np.cos(omega2 * t)


def y(x, t): return y1(x, t) + y2(x, t)


t = np.linspace(t1, t2, 1000)
original = y(x, t)
modified = np.copy(original)

intensity = 20.0
last_v = modified[0]

for n in range(modified.size):
    v = modified[n]

    # print("before: ", v)

    modified[n] = v + (v - last_v) * intensity

    # print("after: ", v)

    last_v = v

fig = plt.figure()

p1 = plt.plot(t, original, label='original')
p2 = plt.plot(t, modified, label='modified')

fig.legend()

plt.xlabel('t [ s ]', fontsize=18)
plt.ylabel('y [ m ]', fontsize=18)
plt.grid()

plt.show()
