# Aide-Saint-Nicolas
Ce projet vise à aider saint-Nicolas à optimiser sa tournée dans la ville de Liège. En terme de programmation.

Problème du voyage de commerce : https://en.wikipedia.org/wiki/Travelling_salesman_problem.

  Pour cela : il existe deux heuristiques possible

  1. On fixe arbitrairement un ordre des adresses (maisons). On crée un premier tour qui ne contient que l' adresse seule. On ajoute ensuite les adresses une par une au tour courant suivant l'ordre initial et en ajoutant chaque nouvelle adresse dans le tour juste après l'adresse du tour dont elle est la plus proche (En terme de distance Euclidienne).

  2. On procède exactement comme pour l'algorithme précédent si ce n'est qu'on ajoute la nouvelle adresse à la position dans le tour qui minimmise l'augmentation de la longueur du tour.



