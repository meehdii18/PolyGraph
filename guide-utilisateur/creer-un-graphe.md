# Créer un graphe (orienté ou non)

## Création d'un graphe vide



Pour créer un graphe vide il faut utiliser le constructeur par défaut en instanciant une classe grâce aux templates PGraph ou PGraphOrient et les classes CArc et CSommet.

```cpp
// Création d'un graphe non orienté 
PGraph<CArc, CSommet> GPOGraphe;
```

```cpp
// Création d'un graphe orienté
PGraphOrient<CArc, CSommet> GPOGraphe;
```

## Création d'un graphe depuis un fichier de données

Il est possible d'importer les données d'un fichier texte pour créer un graphe, ce fichier doit ressembler à cet exemple :&#x20;

{% code title="donnees.txt" %}
```
nbsommets=3
nBaRcs=	4
Sommets=[
Numero=1
Numero=2
Numero=3
]
Arcs=[
	DEBUT        =       1,Fin=2   
debut=2, Fin=3
Debut=   3  , Fin=1
debut = 3, fin = 3
]
```
{% endcode %}

Il suffit ensuite de créer un graphe (orienté ou non) depuis le constructeur défini prenant en paramètre un chemin vers le fichier texte

{% code title="main.cpp" %}
```cpp
PGraph<CArc, CSommet> Graphe("./donnees.txt");
```
{% endcode %}

Il est également possible d'importer les données du fichier après avoir créer le graphe grâce à la classe CCreateurGraph&#x20;

{% code title="main.cpp" %}
```cpp
PGraph<CArc, CSommet> Graphe;
CCreateurGraph::CCGImporterGrapheFichier(Graphe, "./donnees.txt");
```
{% endcode %}

## Création d'un graphe orienté par recopie

Pour créer un nouveau graphe par recopie d'un autre graphe déjà existant, il est possible d'utiliser le constructeur de recopie de la classe PGraphOrient

{% code title="main.cpp" %}
```cpp
PGraphOrient<CArc, CSommet> Graphe;
CCreateurGraph::CCGImporterGrapheFichier(Graphe, "./donnees.txt");

PGraphOrient<CArc, CSommet> GrapheCopie(Graphe);
```
{% endcode %}
