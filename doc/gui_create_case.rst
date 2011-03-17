.. _gui_create_case:

Le cas
======
.. index:: single: cas
La définition du cas se fait par la donnée des informations suivantes :

  - Un nom
  - Un répertoire
  - Le fichier du maillage initial
  - Le type de conformité pour la série d'adaptations envisagées

.. image:: images/create_case_1.png
   :align: center


Le nom du cas
"""""""""""""
Un nom de cas est proposé automatiquement : Case_0, Case_1, etc. Ce nom peut être modifié. Il ne doit pas avoir été utilisé pour un cas précédent.

Le répertoire
"""""""""""""
Le répertoire est celui qui contiendra les fichiers produits par les adaptations successives. Ce répertoire doit exister. Par défaut, Salome propose ``/tmp``. Ce choix peut être modifié, soit en tapant le nom dans la zone de texte, soit en activant la fonction de recherche. C'est dans ce répertoire que seront exportés les maillages au format MED, dans des fichiers de nom ``maill.xx.med``, où ``xx`` est un numéro d'ordre créé automatiquement ; ces noms de fichiers seront visibles dans l'arbre d'études.

.. image:: images/create_case_2.png
   :align: center

.. index:: single: maillage;initial
.. index:: single: MED
Le maillage initial
"""""""""""""""""""
Le maillage initial doit se trouver dans un fichier au format MED. Classiquement, il aura été produit par le logiciel de calcul avec lequel on travaille. Mais il peut également avoir été créé avec le module SMESH et exporté au format MED. Le nom du fichier peut être fourni, soit en tapant le nom dans la zone de texte, soit en activant la fonction de recherche.

.. image:: images/create_case_3.png
   :align: center

.. note::
  Le fichier ne doit contenir qu'un seul maillage.

.. warning::
  Le maillage ne doit pas être lui-même le produit d'une adaptation de maillage par HOMARD, sous peine de perdre la cohérence entre les différents niveaux de raffinement/déraffinement

.. index:: single: type de conformité
Le type de conformité
"""""""""""""""""""""
Les itérations qui seront définies pour ce cas devront respecter le même comportement vis-à-vis de la conformité.

L'option par défaut, 'conforme', implique que les maillages produits par HOMARD seront conformes au sens des éléments finis. C'est le choix classique de la plupart des logiciels de simulation par éléments finis.

Si le calcul est possible avec des maillages non conforme, on a le choix entre 3 possibilités :

.. image:: images/create_case_4.png
   :align: center

* 1 noeud par maille : une maille ne peut posséder qu'un seul noeud de non conformité avec ses voisines.
* 1 noeud par arête : chaque arête d'une maille peut être découpée sans que la maille voisine par cette arête ne le soit.
* quelconque : aucune limitation sur les raccords de conformité d'une maille à l'autre.

.. index:: single: arbre d'étude
L'arbre d'étude
"""""""""""""""
A l'issue de cette création de cas, l'arbre d'études a été enrichi de ce nouveau cas. On y trouve l'itération initiale, identifiée par le nom du maillage qui a été lu dans le fichier fourni.

.. image:: images/create_case_5.png
   :align: center


