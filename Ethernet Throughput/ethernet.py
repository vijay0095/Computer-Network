import matplotlib.pyplot as plt
import numpy as np
import math

if __name__ == '__main__':
    distance = 2500
    bitsperframe = 1e4
    bandwidth = 1e7
    frameTime = bitsperframe / bandwidth
    minislotTime = 2 * distance / (3 * 1e8)
    minislotsperframe = frameTime / minislotTime
    n = 16
    no = 1
while (n <= 1024):
    transmitornot = []
    transmitornot = np.random.randint(2, size=(n))
    currenttransmitters = len(list(filter(lambda x: x == 0,transmitornot)))
    lmbda = 0.1
    totalthroughput = []
    totaltlambda = []
    slotswasted = []
while (lmbda < 1000):
    if (currenttransmitters > 1):
        t = 1
        wastedslot = 1
    else:
        t = 0
        wastedslot = 0
        frames = 0
        collisions = [0 for i in range(n)]
        noofminislotstowait = math.ceil(1 / (lmbda * minislotTime))
        backofftime = np.full(n, noofminislotstowait)
        i = 0
        while i < n:
            if (transmitornot[i] == 0):
                collisions[i] = collisions[i] + 1
                backofftime[i] = np.random.randint(0, 2 **collisions[i])
                i = i + 1
        while t < 1e3:
            i = 0
            nooftransmitters = 0
        while i < n:
            if backofftime[i] == 0:
                nooftransmitters = nooftransmitters + 1
                currenttransmitter = i
                i = i + 1
            if nooftransmitters == 1:
                frames = frames + 1
                collisions[currenttransmitter] = 0
                backofftime[currenttransmitter] = noofminislotstowait
                t = t + minislotsperframe 
                i = 0
        while i < n:
            backofftime[i] = backofftime[i] - minislotsperframe
            if backofftime[i] < 0:
                backofftime[i] = 0
                i = i + 1
            elif nooftransmitters > 1:
                wastedslot = wastedslot + 1
                t = t  + 1
                i = 0
        while i < n:
            if backofftime[i] == 0:
                collisions[i] = collisions[i] + 1
                backofftime[i] = np.random.randint(0, (2 **collisions[i]))
            else:
                backofftime[i] = backofftime[i] - 1
                i = i + 1
        else:
            t = t + 1
            wastedslot = wastedslot + 1
            i = 0
        while i < n:
            backofftime[i] = backofftime[i] - 1
            if backofftime[i] < 0:
                backofftime[i] = 0
                i = i + 1
            throughput = (bitsperframe * frames) / (t * minislotTime)
            totalthroughput.append(throughput)
            totaltlambda.append(lmbda)
            fractionwastedslot = wastedslot/t
            slotswasted.append(fractionwastedslot)
            lmbda = lmbda + 100
plt.figure(no)
plt.subplot(211)
plt.axis([0, 1000, 0, 1 * 10 ** 7])
plt.title(n)
plt.xlabel("lambda in frames per sec")
plt.ylabel("throughput in bits per sec")
plt.plot(totaltlambda, totalthroughput)
plt.subplot(212)
plt.plot(totaltlambda, slotswasted)
plt.axis([0, 1000, 0, 0.6])
plt.xlabel("lambda in frames per sec")
plt.ylabel("wasted fraction of slots")
n = n * 2
no = no + 1
plt.show()
