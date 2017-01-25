'''

from keras.layers.core import *

# Model is a NN.

model = Sequential()

model.add(Dense(dim = 128)) # Number of input neurons?

# What is the function used on each neuron

model.add(Activation('softmax'))

# Optimization - chose GD for you

'''

# Testing with numpy.

import numpy as np

# Avoid for loops!!! Change your data instead.

# np.hstack(), np.vstack(), np.repeat(), np.tile()

# repeat - repeats rows

# Figure out matrix multiplication on two numpy arrays.

a = np.matrix([[2, 3], [4, 5]])

b = np.matrix([[1, 4], [5, 6]])

print(a)

# Masking in numpy - some errors, gaps, etc.

# np.masked(parameters to mask)

# Notion of axis in np

# np.shape() and np.reshape()
