Face-It is in early stages of development. It is a part of graduation thesis on Artifitial Neural Networks.
The current state of the code is a little bit better than "crap", with lots of work on cleaning the code, fixing memory leaks and writing documentation pending.

The neural network implementation is in fairly usable state, allowing for computation and training.
The network is implemented in standart C++. This covers only the classes Network, Layer and Neuron. The rest of the project is QT specific (including Backpropagation, which implements a backpropagation alorithm into a QThread successor.


Requirements:
QT 4.3 - Possibly would work with 4.1 or 4.2, but not tested.
Fast CPU - The code is not very optimized yet and the neural networks are computational heavy. At least 1Ghz is needed for adequate work.