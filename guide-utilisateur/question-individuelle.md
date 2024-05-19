# Question individuelle

Il est désormais possible de créer des graphes orientés pondérés, c'est à dire que les arcs de ce graphe auront un poids (float). Il faut absolument utilisé la classe CArcPondere lors de la création de ces graphes, sinon le compilateur renverra une erreur.

La manière de créer un graphe à été modifiée. Il faut désormais utilisé la classe CCreateurGraph pour importer les données d'un fichier dans un graphe :&#x20;

```cpp
PGraphOrientPondere<CArcPondere, CSommet> GPOGraphe = CCreateurGraph::CCGCreerGrapheOrientPondereFichier("./donnees.txt");
```

Il est toujours possible d'afficher le graphe avec la classe CAffichage, mais également d'afficher le cycle hamiltonien concernant un sommet :&#x20;

```cpp
CAffichage::AFHAfficherGraphe(GPOGraphe);
CAffichage::AFHAfficherCycleHamiltonien(GPOGraphe, "O"); // Affiche le cycle hamiltonien avec le sommet "O"
```

Toutes les anciennes méthodes sont toujours compatible comme l'inversion des arcs :&#x20;

```cpp
PGraphOrientPondere<CArcPondere, CSommet> GPOGraphe = CCreateurGraph::CCGCreerGrapheOrientPondereFichier(argv[1]);
COperationsSurGraphe::OSGInverserArcs(GPOGraphe);
```

Et on peut également appeler la méthode permettant d'afficher le cycle hamiltonien du graphe à partir d'un sommet, ce qui affichera le coût total du cycle en même temps :&#x20;

```cpp
CAffichage::AFHAfficherCycleHamiltonien(GPOGraphe, "O");

/*
Exemple de résultat à la compilation
------------------------------------------
Cycle hamiltonien : O -> E -> A -> C -> B -> D -> O
Cout total du cycle : 17
*/
```
