import random
import numpy as np
import matplotlib.pyplot as plt

def k_means(data,k):
        zd = zip(*data)
        low = min(min(zd[0]),min(zd[1]))
        high = max(max(zd[0]),max(zd[1]))
        means = []
        for i in range(k):
                   means.append((random.randint(low,high),random.randint(low,high)))
        labels = [-1]*len(data)
        dist = [[0.]*k]*len(data)
        diff = True
        while(diff):
                   num_points = [0.]*k
                   new_means = [(0,0)]*k
                   old_labels = list(labels)
                   for i in range(len(data)):
                           (x,y) = data[i]
                           min_d = float('inf')
                           ind = -1
                           for j in range(k):
                                   (a,b) = means[j]
                                   d = (a-x)**2 + (b-y)**2
                                   if d < min_d:
                                           min_d = d
                                           ind = j
                                   dist[i][j] = d
                           labels[i] = ind
                           num_points[ind] += 1
                           new_means[ind] = (x + new_means[ind][0],y + new_means[ind][1])
                   for j in range(k):
                           if num_points[j] == 0:
                                   new_means[j] = (float('inf'),float('inf'))
                           else:
                                   new_means[j] = (new_means[j][0]/num_points[j],
                                           new_means[j][1]/num_points[j])
                   means = new_means
                   print "means: " + str(means)
                   if old_labels == labels:
                           diff = False
        print data
        print means
        print labels
        return labels

#similar to k_means except the "means" are points in the data set
#this is why it is called k medians
def k_medians(data,k):
        #fill in

def generate_data(n,low,high):
        points = []
        for i in range(n):
                x = random.randint(low,high)
                y = random.randint(low,high)
                points.append((x,y))
        return points

p = generate_data(15,-15,15)
k_means(p,4)
