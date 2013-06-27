.. _gui_create_case:

La cr�ation d'un cas
####################
.. index:: single: cas

La d�finition du cas se fait par la donn�e des informations suivantes :

  - Un nom
  - Un r�pertoire
  - Le fichier du maillage initial
  - Le type de conformit� pour la s�rie d'adaptations envisag�es
  - Les �ventuelles fronti�res courbes � respecter

.. image:: images/create_case_1.png
   :align: center


Le nom du cas
*************
Un nom de cas est propos� automatiquement : Case_1, Case_2, etc. Ce nom peut �tre modifi�. Il ne doit pas avoir d�j� �t� utilis� pour un autre cas.

Le r�pertoire
*************
Le r�pertoire est celui qui contiendra les fichiers produits par les adaptations successives. Par d�faut, rien n'est propos�. Le choix est fait, soit en tapant le nom dans la zone de texte, soit en activant la fonction de recherche. C'est dans ce r�pertoire que seront export�s les maillages au format MED, dans des fichiers de nom ``maill.xx.med``, o� ``xx`` est un num�ro d'ordre cr�� automatiquement. Ces fichiers seront visibles dans l'arbre d'�tudes.

.. image:: images/create_case_2.png
   :align: center

.. index:: single: maillage;initial
.. index:: single: MED

Le maillage initial
*******************
Le maillage initial doit se trouver dans un fichier au format MED. Classiquement, il aura �t� produit par le logiciel de calcul avec lequel on travaille. Mais il peut �galement avoir �t� cr�� avec le module SMESH et export� au format MED. Le nom du fichier peut �tre fourni, soit en tapant le nom dans la zone de texte, soit en activant la fonction de recherche.

.. image:: images/create_case_3.png
   :align: center

.. note::
  Le fichier ne doit contenir qu'un seul maillage.

.. warning::
  Le maillage ne doit pas �tre lui-m�me le produit d'une adaptation de maillage par HOMARD, sous peine de perdre la coh�rence entre les diff�rents niveaux de raffinement/d�raffinement

.. index:: single: type de conformit�

Le type de conformit�
*********************
Les it�rations qui seront calcul�es pour ce cas devront toutes respecter le m�me comportement vis-�-vis de la conformit�.

L'option par d�faut, 'conforme', implique que les maillages produits par HOMARD seront conformes au sens des �l�ments finis. C'est le choix classique de la plupart des logiciels de simulation par �l�ments finis.

N�anmoins, si le calcul est possible avec des maillages non conformes, on a le choix entre 3 possibilit�s :

.. image:: images/create_case_4.png
   :align: center

* 1 noeud par maille : une maille ne peut poss�der qu'un seul noeud de non conformit� avec ses voisines.
* 1 noeud par ar�te : chaque ar�te d'une maille peut �tre d�coup�e sans que la maille voisine par cette ar�te ne le soit.
* quelconque : aucune limitation sur les raccords de conformit� d'une maille � l'autre.

.. index:: single: fronti�re

Les fronti�res courbes
**********************
Quand le bord du domaine est courbe, HOMARD sait placer les nouveaux noeuds sur ces fronti�res pour �viter des singularit�s artificielles. Cette technique est aussi applicable � une courbure int�rieure � un domaine.

Deux cas de figure sont pr�sents :

* courbe 1D : cette courbe peut �tre d�finie dans un plan, par exemple pour un calcul 2D. Elle peut �galement �tre d�finie dans l'espace 3D, par exemple pour l'intersection de deux surfaces. Une ligne � suivre est d�crite de mani�re discr�te.
* surface : une surface � suivre est d�crite de mani�re analytique.

On cochera le ou les boutons voulus :

.. image:: images/create_case_5.png
   :align: center

La d�finition des fronti�res est d�crite dans :ref:`gui_create_boundary`.

.. index:: single: pyramide

.. _options_avancees:

Les options avanc�es
********************
Par d�faut, aucune option avanc�e n'est active.

N�anmoins, on peut d�finir une oprion avanc�e :

.. image:: images/create_case_7.png
   :align: center

Par d�faut, HOMARD sait traiter des maillages en 2 ou 3 dimensions et comportant les mailles suivantes :
   - mailles-points
   - segments
   - triangles
   - quadrangles
   - t�tra�dres
   - hexa�dres
   - prismes

Si le maillage initial comporte des pyramides, il y a arr�t en erreur. Toutefois, si on est certain que les raffinements ult�rieurs ne toucheront aucune des ar�tes des pyramides, on cochera la case "Pyramides autoris�es". Les adaptations se d�rouleront normalement et les pyramides seront restitu�es telles quelles dans le maillage final.


La poursuite d'un cas
*********************
.. index:: single: poursuite
.. index:: single: yacs

La poursuite d'un cas correspond � la situation suivante :
Une s�rie d'adaptations ont �t� conduites sur un cas puis SALOME est ferm�. On a gard� les r�pertoires de travail de ces it�rations. On souhaite ensuite reprendre ces it�rations pour les poursuivre l� o� on s'est arr�t�. Cette fonctionnalit� est particuli�rement utile dans le cas de sch�mas YACS pour lesquels on scinde en plusieurs parties une longue s�rie d'adaptations.

La condition pour reprendre une it�ration est d'avoir conserv� dans un m�me r�pertoire deux fichiers :
   - le fichier de configuration qui a servi de donn�es au module ex�cutable de HOMARD ; ce fichier se pr�sente sous la forme ``HOMARD.Configuration.(n).vers.(n+1)``
   - le fichier au format MED qui conserve l'historique des adaptations r�alis�es ; ce fichier se pr�sente sous la forme ``maill.(n).hom.med``

On peut choisir de partir d'une it�ration archiv�e d�sign�e explicitement par son r�pertoire ou d'une it�ration rep�r�e dans le r�pertoire archivant un cas.

Pour poursuivre une it�ration connue par son r�pertoire d'archive, la d�finition du cas se fait par la donn�e des informations suivantes :

  - Un nom
  - Un r�pertoire
  - Le r�pertoire qui contient les archives

.. image:: images/pursue_case_1.png
   :align: center

On peut choisir de partir d'un cas d�j� calcul� ; par d�faut, le nouveau cas sera cr�� en partant de la derni�re it�ration pr�c�demment calcul�e.

.. image:: images/pursue_case_2.png
   :align: center

Si on souhaite partir d'une it�ration qui ne soit pas la derni�re, il suffit de le pr�ciser :

.. image:: images/pursue_case_3.png
   :align: center

.. note::
  Les param�trages du cas ainsi cr�� sont ceux de l'it�ration poursuivie : mode de conformit� identique par exemple.


L'arbre d'�tude
***************
A l'issue de cette cr�ation de cas, l'arbre d'�tudes a �t� enrichi de ce nouveau cas. On y trouve l'it�ration initiale, identifi�e par le nom du maillage qui a �t� lu dans le fichier fourni.

.. image:: images/create_case_6.png
   :align: center



M�thodes python correspondantes
*******************************
Consulter :ref:`tui_create_case`

