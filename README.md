# Noeud test

## Description
Petit projet visant à comprendre le fonctionnement d'un réseau de neurone

## Commande de compilation
```bash
g++ *.cpp source/*.cpp -o noeud
```

## Fonction utilisable
1. RELU
2. SIG (sigmoïde)
3. TANH (tangente hyperbolique)

## Exemple de réseau
```cpp
Reseau r(l, c);
r.genReseau();
r.setReseau(nbEntree, &entree[0][0], poidsMax);

r.calcule(TANH);
r.retroPropag();
r.affiche();

r.apprend(apprend);

r.calcule(TANH);
r.retroPropag();
r.affiche();
```

