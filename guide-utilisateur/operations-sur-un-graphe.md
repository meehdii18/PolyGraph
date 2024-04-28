# Opérations sur un graphe

Les opérations décrient ici seront expliquées avec des graphes non orientées mais fonctionnent également avec des graphes orientées

## Ajouter un sommet

La méthode GPOAjouterSommet prenant en paramètre un string étant l'identifiant du sommet, ajoutera un sommet au graphe sur lequel on appel la méthode

```cpp
PGraphOrient<CArc, CSommet> GPOGraphe;
GPOGraphe.GPOAjouterSommet("Sommet 2");
```

## Modifier l'identifiant d'un sommet existant

Il est possible de renommer un sommet en utilisant la méthode GPOModifierIdentifiantSommet prenant en paramètre l'identifiant du sommet à renommer et son nouvel identifiant

```cpp
GPOGraphe.GPOModifierIdentifiantSommet("Sommet 1", "Sommet A");
```

## Ajouter un arc

Pour relier deux sommets entre eux dans le graphe, il est possible d'ajouter un arc, selon le type de graphe sur lequel la méthode est appelé le résultat sera différent

```cpp
PGraphOrient<CArc, CSommet> Graphe;

Graphe.GPOAjouterSommet("Sommet 1");
Graphe.GPOAjouterSommet("Sommet 2");
Graphe.GPOAjouterArc("Sommet 1", "Sommet 2");
```

Ici nous somme sur un graphe orienté donc l'arc n'ira que de Sommet 1 vers Sommet 2&#x20;

```cpp
PGraph<CArc, CSommet> Graphe;

Graphe.GPOAjouterSommet("Sommet 1");
Graphe.GPOAjouterSommet("Sommet 2");
Graphe.GPOAjouterArc("Sommet 1", "Sommet 2");
```

Ici sur un cas de graphe non orienté, l'arc créer reliera Sommet 1 et Sommet 2 dans les deux sens, mais la méthode pour créer l'arc reste la même

## Supprimer un arc

Il est possible de supprimer un arc dans un graphe, dans les deux cas du graphe orienté et non orienté l'arc sera supprimé dans les deux sens

```cpp
PGraph<CArc, CSommet> Graphe("./donnees.txt");
Graphe.GPOSupprimerArc("1", "2");
```

```cpp
PGraphOrient<CArc, CSommet> Graphe("./donnees.txt");
Graphe.GPOSupprimerArc("1", "2");
```

## Inverser tout les arcs d'un graphe orienté

Dans le cas d'un graphe orienté il est possible d'inverser l'origine et la destination de tout ses arcs grâce à la méthode OSGInverserArcs dans la classe COperationsSurGraphe

<pre class="language-cpp"><code class="lang-cpp">PGraphOrient&#x3C;CArc, CSommet> Graphe("./donnees.txt");
<strong>COperationsSurGraphe::OSGInverserArcs(Graphe);
</strong></code></pre>

