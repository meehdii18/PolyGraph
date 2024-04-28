# Affichage de graphes

## Afficher un graphe avec ses sommets et ses arcs

Pour afficher l'entiereté des données d'un graphe, on peut utiliser la méthode AFHAfficherGraphe qui prend en paramètre le graphe à afficher.

```cpp
PGraphOrient<CArc, CSommet> GPOGraphe;
CAffichage::AFHAfficherGraphe(GPOGraphe);
```

## Afficher les informations d'un sommet en particulier

Pour afficher toutes les informations d'un sommet en particulier (ses arcs entrants et sortants), on peut utiliser la méthode AFHAfficherSommetAvecArc, qui prend commme paramètre le graphe auquel le sommet à afficher appartient, ainsi que l'identifiant de celui-ci

```cpp
PGraphOrient<CArc, CSommet> GPOGraphe;
CAffichage::AFHAfficherSommetAvecArc(GPOGraphe,"Sommet 1");
```
