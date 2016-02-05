from opencog.utilities import initialize_opencog
from opencog.bindlink import execute_atom
from opencog.type_constructors import *
import numpy as np
import random
atomspace = AtomSpace()
initialize_opencog(atomspace) 



def string_to_array(x,y):
    mat = []
    row = []
    mat2 = []
    row2 = []
    atom = str(x.name)
    atom = atom.split(',') 
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

    atom2 = str(y.name)
    atom2 = atom2.split(',') 
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
        
    print mat
    print mat2
    res = np.dot(mat, mat2)
    print res
    res = ATOMSPACE.add_node(types.ArrayNode, str(res))  
    return res


