.. _gui_mesh_info:

Analyse de maillage
###################
.. index:: single: analyse
.. index:: single: information

La demande d'analyse d'un maillage se fait par la donn�e des informations suivantes :

  - Un r�pertoire
  - Le fichier du maillage

Si le maillage fait partie d'un cas enregistr�, son analyse est faite � partir de son it�ration dans l'arbre d'�tudes. Voir plus loin.


Maillage � importer
*******************
La s�lection de la fonction d'analyse est faite par le menu de la barre sup�rieure de la fen�tre :

.. image:: images/mesh_info_1.png
   :align: center

La fen�tre de choix s'affiche.

.. image:: images/mesh_info_2.png
   :align: center

Le nom du cas
=============
Un nom de cas est propos� automatiquement : Case_1, Case_2, etc. Ce nom peut �tre modifi�. Il ne doit pas avoir d�j� �t� utilis� pour un autre cas.

Le r�pertoire
=============
Le r�pertoire est celui qui contiendra les fichiers produits par l'information. Par d�faut, rien n'est propos�. Le choix est fait, soit en tapant le nom dans la zone de texte, soit en activant la fonction de recherche. C'est dans ce r�pertoire que seront export�s les fichiers d'information de nom ``Liste.log`` et ``info_av.00.bilan``. Ces fichiers seront visibles dans l'arbre d'�tudes.

.. image:: images/create_case_2.png
   :align: center

.. index:: single: maillage;initial
.. index:: single: MED

Le maillage � analyser
======================
Le maillage � analyser doit se trouver dans un fichier au format MED. Le nom du fichier peut �tre fourni, soit en tapant le nom dans la zone de texte, soit en activant la fonction de recherche.

.. image:: images/create_case_3.png
   :align: center

.. note::
  Le fichier ne doit contenir qu'un seul maillage.

.. warning::
  Le maillage ne doit pas �tre lui-m�me le produit d'une adaptation de maillage par HOMARD, sous peine de perdre l'analyse des diff�rents niveaux de raffinement/d�raffinement.

Options d'analyse
=================
L'analyse est faite selon les options coch�es.
  - qualit� des mailles
  - diam�tre des mailles
  - connexit� du domaine ; en un seul morceau, combien de trous, etc.
  - tailles des constituants du domaine, groupe par groupe
  - interp�n�tration des mailles, par dimension

Le r�sultat de l'analyse est contenu dans le fichier ``info_av.00.bilan`` ; ce fichier est � consulter en l'affichant apr�s sa d�signation avec "*Afficher le fichier*" dans le menu HOMARD ou � la souris.

L'arbre d'�tude
===============
A l'issue de cette demande d'information, l'arbre d'�tudes a �t� enrichi de ce nouveau cas. On y trouve l'it�ration initiale, identifi�e par le nom du maillage qui a �t� lu dans le fichier fourni, et les deux fichiers d'information de nom ``Liste.log`` et ``info_av.00.bilan``.

.. image:: images/mesh_info_3.png
   :align: center


It�ration calcul�e
******************

Pour analyser le maillage produit par une it�ration d'adaptation de maillage, on d�signe � la souris cette it�ration dans l'arbre d'�tudes et on lance l'analyse. On retrouve le menu similaire au cas initial :

.. image:: images/mesh_info_4.png
   :align: center

Comme pour un maillage import�, l'arbre d'�tudes a �t� enrichi avec les deux fichiers d'information de nom ``Liste.log`` et ``info_ap.xx.bilan``, o� xx est le num�ro de l'it�ration dans le cas.

.. image:: ../images/mesh_info_5.png
   :align: center



M�thodes python correspondantes
*******************************
Consulter :ref:`tui_create_case` et :ref:`tui_create_iteration`

