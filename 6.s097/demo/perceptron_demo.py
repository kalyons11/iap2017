import matplotlib.pyplot as plt
import random
import time


def main(n):
        points = generate_data(n)
        labeled = label_data(points)
        points = labeled[4]
        theta = [0.,0.]
        theta_0 = 0.

        plt.ion()
        
        fig = plt.figure()
        
        plt.axis([-n-1,n+1,-n-1,n+1])
        
        blue = fig.add_subplot(111)
        bluepts = blue.plot(labeled[0], labeled[1], 'bo')
        red = fig.add_subplot(111)
        redpts = red.plot(labeled[2], labeled[3], 'ro')

        line = ([-n-1,n+1],[0,0])
        ax = fig.add_subplot(111)
        l, = ax.plot(line[0], line[1], 'k-')
        fig.canvas.draw()

        correct = True
        i = 0

        #Perceptron algorithm
        while(True):
                p = points[i]
                if (theta[0]*p[0] + theta[1]*p[1] + theta_0)*p[2] <= 0:
                        correct = False
                        (theta,theta_0) = perceptron_update(p, theta, theta_0)
                        line = get_line(theta,theta_0,n)
                        l.set_xdata([line[0][0],line[1][0]])
                        l.set_ydata([line[0][1],line[1][1]])
                        fig.canvas.draw()
                        time.sleep(0.5)
                if i == n - 1:
                        if correct:
                                print("Completion")
                                break
                        correct = True
                i = (i+1)%n

#method to generate n data points
def generate_data(n):
        low = min(-3, -n)
        high = max(3, n)
        points = []
        for i in range(n):
                x = random.randint(low, high)
                y = random.randint(low, high)
                points.append([x,y])
        return points

#method that takes n data points and labels them
#ensures there exists a linear classifier
def label_data(points):
        n = len(points)
        low = min(-3, -n)
        high = max(3, n)
        
        dy = random.randint(low, high)
        dx = 0
        while dx == 0:
                dx = random.randint(low, high)
        m = float(dy/dx)
        b = random.randint(low/2, high/2)

        pos_xpts = []
        pos_ypts = []
        neg_xpts = []
        neg_ypts = []

        p = points
        
        for i in range(len(points)):
                point = points[i]
                if point[1] >= m*point[0] + b:
                        pos_xpts.append(point[0])
                        pos_ypts.append(point[1])
                        p[i].append(1)
                else:
                        neg_xpts.append(point[0])
                        neg_ypts.append(point[1])
                        p[i].append(-1)

        labeled = [pos_xpts, pos_ypts, neg_xpts, neg_ypts, p]
        return labeled

#updates perceptron
def perceptron_update(point, theta, theta_0):
        label = point[2]
        print("UPDATE")
        print(point)
        print(label)
        print(theta)
        theta[0] += label*point[0]
        theta[1] += label*point[1]
        theta_0 += label
        print(theta)
        return (theta, theta_0)

#gets line into format usable for plotting
def get_line(theta,theta_0,n):
        line = [None,None]
        i = 0
        a = theta[0]
        b = theta[1]
        c = theta_0

        if theta[0] != 0:
                x = -(b/a)*(n+1) - c/a
                if x >= -(n + 1) and x <= n + 1:
                        line[i] = [x, n+1]
                        i += 1

                x = (b/a)*(n+1) - c/a
                if x >= -(n + 1) and x <= n + 1:
                        if i < 2:
                                line[i] = [x, -n-1]
                                i += 1

        if theta[1] != 0:
                y = -(a/b)*(n+1) - c/b
                if y >= -(n + 1) and y <= n + 1:
                        if i < 2:
                                line[i] = [n+1, y]
                                i += 1

                y = (a/b)*(n+1) - c/b
                if y >= -(n + 1) and y <= n + 1:
                        if i < 2:
                                line[i] = [-n-1, y]
                                i += 1

        if i < 2:
                raise("Issue creating line")

        return line
        
#runs the method on 10 points.
#Would not recommend running on data larger than 15 pts as it is slow
print main(10)
