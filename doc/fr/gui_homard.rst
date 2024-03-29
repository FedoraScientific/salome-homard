.. _gui_homard:

Le calcul
#########
.. index:: single: it�ration
.. index:: single: calcul
.. index:: single: SMESH

Lancer une adaptation
*********************
Lancer une adaptation s'obtient en s�lectionnant l'it�ration � calculer. Elle est rep�r�e par une icone "en attente". On choisit ensuite "*Calculer*" ou "*Calculer et publier*" dans le menu HOMARD ou � la souris. Dans le premier cas, l'adaptation sera r�alis�e et les fichiers MED seront �crits. Dans le second cas, le nouveau maillage sera publi� dans SMESH. On notera que si on a seulement utilis� "*Calculer*", il est toujours possible de publier a posteriori le maillage produit en s�lectionnant le choix "*Publier*".

.. image:: images/lancement_1.png
   :align: center

.. index:: single: arbre d'�tude

L'arbre d'�tude
***************

A l'issue de ce calcul, l'arbre d'�tudes a �t� enrichi. L'icone devant l'it�ration est valid�e. Sous l'it�ration, on trouve la r�f�rence aux fichiers de r�sultats cr��s, identifi�s par leur nom dans le r�pertoire *rep* qui a �t� d�fini � la cr�ation du cas :

  - *rep*/I(n+1)/Liste.n.vers.(n+1).log
  - *rep*/I(n+1)/apad.n.vers.(n+1).bilan
  - *rep*/maill.(n+1).med

Les deux premiers fichiers sont des fichiers de texte, �ditables. Liste.n.vers.(n+1).log contient des informations sur le d�roulement de l'adaptation : r�capitulatif du mode d'adaptation, pourcentage de mailles concern�es, etc. Le fichier apad.n.vers.(n+1).bilan est un r�sum� des caract�ristiques du maillage obtenu.

Le fichier maill.(n+1).med est celui qui contient le maillage produit au format MED. Si on a demand� la publication, on retrouve ce maillage dans la section de l'arbre d'�tudes du module SMESH. Il est alors visible dans ce module et utilisable ensuite comme tout autre maillage.


.. image:: images/lancement_2.png
   :align: center

Consulter le r�sultat d'une adaptation
**************************************
Les deux fichiers de texte, Liste.n.vers.(n+1).log et apad.n.vers.(n+1).bilan, sont visibles en les s�lectionnant. On choisit ensuite "*Afficher le fichier*" dans le menu HOMARD ou � la souris.

.. image:: images/lancement_3.png
   :align: center


.. note::
  Par d�faut, le calcul est lanc� avec l'ex�cutable de HOMARD install� avec SALOME. Si on souhaite utiliser une version priv�e de HOMARD, pour tester une �volution par exemple, il faut pr�ciser o� le nouvel ex�cutable est disponible. Pour cela, il faut renseigner deux variables d'environnement.
  "*HOMARD_REP_EXE_PRIVATE*" d�finit le r�pertoire dans lequel se trouve l'ex�cutable voulu.
  "*HOMARD_EXE_PRIVATE*" d�finit le nom de l'ex�cutable dans ce r�pertoire, si ce nom est diff�rent de "*homard*".

M�thodes python correspondantes
*******************************
Consulter :ref:`tui_create_iteration`

