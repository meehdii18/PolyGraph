# Question individuelle

## CCreateurGraphe

Nous avons modifié la manière de créer des graphes à partir d'un fichier. Le constructeur prenant en entrée un chemin vers le fichier à été supprimer pour laisser place à différentes méthodes pour créer des graphes depuis un fichier ou alors pour importer les données d'un fichier dans un graphe déjà existant car cela faisait plus de sens qu'un constructeur de graphe.

## COperationSurGraphe

La méthode OSGInverserArcs à été modifiée pour fonctionner sur tout les différents types de graphes.\
Nous avons intégré la méthode OSGVerifierGrapheComplet, utile pour ma réalisation de la méthode OSGCycleHamiltonienInsertionMinMax, algorithme principal de notre question. Finalement, la méthode OSGCourtParcoursSommets permet de réaliser l'objectif principal de la question renvoyant le plus cours chemin. Pour la réalisation du cycle hamiltonien nous avons intégré l'utilisation de fonction lambda dans le code pour le simplifier.

## PGraphOrientPondere

Nous avons utilisé un static\_assert au début de la classe qui empêche la compilation si le TArc entré est différent d'un CArcPondere ou toute autre classe dérivée.  Nous avons également intégré une méthode permettant de renvoyer le poids d'un arc à partir de son origine et sa destination (renvoyant -1 s'il n'existe pas).\
