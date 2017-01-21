import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import random

def radial(n):
        low = min(-3, -2*n)
        high = max(3, 2*n)
        points = []
        for i in range(3*n):
                x = random.randint(low, high)
                y = random.randint(low, high)
                points.append([x, y])

        pos_xpts = []
        pos_ypts = []
        neg_xpts = []
        neg_ypts = []
        
        pos_rpts = []
        neg_rpts = []
        
        for i in range(len(points)):
                x = points[i][0]
                y = points[i][1]
                r = x**2 + y**2
                if r < 1.4*(n**2):
                        pos_xpts.append(x)
                        pos_ypts.append(y)
                        pos_rpts.append(r)
                else:
                        neg_xpts.append(x)
                        neg_ypts.append(y)
                        neg_rpts.append(r)
        
        fig = plt.figure()
        
        ax = plt.subplot(211)
        ax.plot(pos_xpts, pos_ypts, 'bo')
        ax.plot(neg_xpts, neg_ypts, 'ro')

        bx = plt.subplot(212, projection = '3d')
        bx.scatter(pos_xpts, pos_ypts, pos_rpts, c = 'b')
        bx.scatter(neg_xpts, neg_ypts, neg_rpts, c = 'r')

        plt.show()

radial(20)
