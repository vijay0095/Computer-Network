import sys
import random
import pandas as pd
import numpy as np

x=[]
Y=[]
Z=[]
class Net():

   def __init__(net, nodes):
     net.N = nodes
     net.network = [[0 for column in range(nodes)]
            for row in range(nodes)]
#Print distances
   def print(net, dist):
     for node in range(net.N):
       y=[]
       y.append(dist[node])
       Y.append(y)
       
   def minDist(net, dist, Set):
     min = sys.maxsize
     for b in range(net.N):
        if dist[b] < min and Set[b] == False:
           min = dist[b]
           min_index = b

     return min_index

   def algorithm(net, source):

     dist = [sys.maxsize] * net.N
     dist[source] = 0
     Set = [False] * net.N

     for i in range(net.N):
         a = net.minDist(dist, Set)
         Set[a] = True
         for b in range(net.N ):
           if net.network[a][b] > 0 and Set[b] == False and dist[b] > dist[a] + net.network[a][b]:
                  dist[b] = dist[a] + net.network[a][b]
                  net.print(dist)
n = Net(50)
#Create an array of distances to edges
c=[]
for i in range(0,50,1):
 c.append([random.randrange(0, 20, 1) for i in range(50)])
for j in range(0,50,1):
 c[j][j]=0
for i in range(0,50,1) :
      for j in range(0,50,1):
            c[j][i]=c[i][j]
n.network=c
for i in range(0,50,1):
 n.algorithm(i);m=[]
Z=np.reshape(Y,(50,50))
for i in range(0,50,1):
    m.append(i)
T=pd.DataFrame(Z, m, m)
print(T)
x=[]
for i in range(0,50,1):
    x.append(Z[0][i])
print(x)
