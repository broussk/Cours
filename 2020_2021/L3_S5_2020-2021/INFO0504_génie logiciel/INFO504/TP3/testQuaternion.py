# Permet d'avoir acces a la classe Quaternion du fichier quaternion.py
from quaternion import Quaternion

# Declaration d'une liste (1,2,3)
elements = [1,2,3]

# Permet de faire varier i de 1 a 10000000

for i in range(10000000):

    # Creation d'un quaternion
    quat1=Quaternion(elements)

    # Creation d'un autre quaternion
    quat2=Quaternion(elements)

    # Recuperation de la somme de 2 quaternions.
    quat3=quat1+quat2
