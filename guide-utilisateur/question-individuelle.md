# Question individuelle

## Utilisation de l'éxécutable

Il y a 3 manières cas possible dans l'utilisation de l'éxécutable :&#x20;

```
./PolyGraph.exe
```

Ce cas là renverra le message d'erreur suivant (mais également le cas ou trop de paramètre auront été entré) : \


<figure><img src="../.gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

Il est ici indiqué que vous n'avez pas indiqué le bon nombre de paramètre attendu et également les instructions pour bien utilisé l'exécutable, détaillant les deux autres cas possible.

Le deuxième cas est le suivant :&#x20;

```
./PolyGraph.exe donnees.txt
```

Ce cas là lira le fichier donnees.txt et affichera le graphe pondere inversé:

<figure><img src="../.gitbook/assets/image (1).png" alt=""><figcaption></figcaption></figure>

Le dernier cas concerne l'ajout d'un deuxième paramètre, permettant toujours de créer un graphe pondéré à partir d'un fichier mais en ajoutant l'identifiant d'un sommet derrière :&#x20;

```
./PolyGraph.exe donnees.txt O
```

<figure><img src="../.gitbook/assets/image (2).png" alt=""><figcaption></figcaption></figure>

Ainsi vous obtiendrez l'affichage du graphe mais également à la fin l'affichage du cycle hamiltonien et son coût total.\
Si vous entrez un sommet qui n'est pas dans le graphe vous obtiendrez une logic error : ![](<../.gitbook/assets/image (3).png>)

## Autres fonctionnalités

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
