from opencog.utilities import initialize_opencog
from opencog.bindlink import execute_atom
from opencog.type_constructors import *
import numpy as np
import random
atomspace = AtomSpace()
initialize_opencog(atomspace) 



def simneu(X,Y):

# change input dataset to matrix format
    print X,Y
    mat = []
    row = []
    
    atom = str(X.name)
    atom = atom.split(',') 


    mat2 = []
    row2 = []         
    atom2 = str(Y.name)
    atom2 = atom2.split(',') 


    for i in range(0, len(atom)):
        if '(' in atom[i]:
            atom[i] = atom[i].replace("(", "")
            row.append(float(atom[i]))
        elif ')' in atom[i]:
            atom[i] = atom[i].replace(")", "")
            
            row.append(float(atom[i]))
            mat.append(row)
            
            row = []
        else:            
            row.append(float(atom[i]))


# change output dataset to matrix format  
    
    for i in range(0, len(atom2)):
        if '(' in atom2[i]:
            atom2[i] = atom2[i].replace("(", "")
            row2.append(float(atom2[i]))
        elif ')' in atom2[i]:
            atom2[i] = atom2[i].replace(")", "")
            
            row2.append(float(atom2[i]))
            mat2.append(row2)
            
            row2 = []
        else:            
            row2.append(float(atom2[i]))
    

    y = np.array(mat2).T
    print y

# seed random numbers to make calculation

# deterministic 

    np.random.seed(1)

# initialize weights randomly with mean 0

    syn0 = 2*np.random.random((3,4)) - 1
    syn1 = 2*np.random.random((4,1)) - 1
    for j in xrange(60000):


    # forward propagation

        l0 = np.array(mat)

        t = np.dot(l0,syn0)
        l1 = 1/(1+np.exp(-t))
        t2 = np.dot(l1,syn1)
        l2 = 1/(1+np.exp(-t2))

    # how much did we miss?

        l2_error = y - l2
        if (j% 10000) == 0:

            print "Error:" + str(np.mean(np.abs(l2_error)))

    # multiply how much we missed by the

    # slope of the sigmoid at the values in l1

        l2_delta = l2_error * (l2*(1-l2))

        # how much did each l1 value contribute to the l2 error (according to the weights)?

        l1_error = l2_delta.dot(syn1.T)
 
# in what direction is the target l1?

# were we really sure? if so, don't change too much.

        l1_delta = l1_error * (l1*(1-l1))

    # update weights

        syn1 += l1.T.dot(l2_delta)

        syn0 += l0.T.dot(l1_delta)
    
    h = ATOMSPACE.add_node(types.ArrayNode, str(l2))
    print h
    

    #h1 = ATOMSPACE.add_node(types.ArrayNode, str(syn1)) 
 
    #h2 = ATOMSPACE.add_node(types.ArrayNode, str(l2)) 
    #return {'weight1':h, 'weight2':h1 ,'output':h2 }
    return h
