.. _demarrage_rapide:

D�marrage rapide
================
.. index:: single: d�marrage
.. index:: single: exemple

L'ensemble des options de pilotage du module HOMARD dans SALOME est d�crit dans le :ref:`gui_usage`. Mais on trouvera ici le B.A. BA pour d�couvrir l'utilisation de HOMARD � partir d'un exemple simple.

Imaginons que l'on a effectu� un calcul de thermique sur un maillage donn�. On a r�cup�r� en sortie de ce calcul un fichier au format MED, contenant le maillage et le champ des temp�ratures aux noeuds. On aimerait adapter le maillage de telle sorte que l'�cart de temp�rature entre deux noeuds voisins soit inf�rieur � une valeur donn�e.

La premi�re action n�cessite de lancer le module HOMARD, en cr�ant une nouvelle �tude, selon le principe qui a �t� retenu pour tous les autres modules de SALOME.

.. image:: images/homard_1.png
   :align: center

Une fois le module HOMARD activ�, on cr�e un cas par le choix "*Nouveau cas*" dans le menu HOMARD.

.. image:: images/homard_2.png
   :align: center

La fen�tre suivante appara�t :

.. image:: images/intro_31.png
   :align: center

Il faut fournir deux informations : le r�pertoire qui contiendra les fichiers produits par les adaptations successives et le fichier MED issu du calcul que l'on vient de faire. On valide par "Appliquer et fermer".

.. image:: images/intro_32.png
   :align: center

L'arbre d'�tudes est enrichi de ce cas. On d�plie le cas jusqu'� afficher le maillage correspondant � l'it�ration 0. On d�signe cette it�ration initiale et on demande une nouvelle it�ration par "*Nouvelle it�ration*" dans le menu HOMARD ou � la souris.

.. image:: images/intro_331.png
   :align: center

La fen�tre suivante appara�t :

.. image:: images/intro_33.png
   :align: center

On d�signe le fichier issu du calcul que l'on vient de faire et qui contient le champ de temp�rature. C'est le m�me que celui qui a �t� donn� dans la d�finition du cas.

.. image:: images/intro_34.png
   :align: center

On clique sur "Nouveau" dans la rubrique hypoth�se. La fen�tre suivante appara�t :

.. image:: images/intro_35.png
   :align: center

On modifie les options par d�faut pour correspondre � notre choix de pilotage de l'adaptation. La s�lection d'un pilotage par les sauts entre �l�ments et d'un seuil absolu de 4.0 va demander le d�coupage de chaque ar�te de maille o� le temp�rature varie de plus de 4.0 degr�s entre les deux extr�mit�s de l'ar�te.

.. image:: images/intro_36.png
   :align: center

On valide par "Appliquer et fermer" cette cr�ation d'hypoth�se, puis la cr�ation de la nouvelle it�ration. On se retrouve avec un arbre d'�tudes enrichi avec la description de l'hypoth�se cr��e et de l'it�ration � calculer, rep�r�e par une icone "en attente".

Lancer l'adaptation s'obtient en s�lectionnant l'it�ration � calculer. On choisit ensuite "*Calculer*" dans le menu HOMARD ou � la souris. L'arbre d'�tudes s'enrichit de fichiers d'informations et du nom du fichier au format MED qui contient le nouveau maillage, ``maill.01.med``. On remarque qu'il est plac� dans le r�pertoire qui a �t� d�sign� � la cr�ation du cas.

.. image:: images/intro_37.png
   :align: center

A ce stade, on va utiliser ce nouveau maillage pour un deuxi�me calcul, dans les m�mes conditions que le premier. Une fois que ce nouveau calcul est achev�, on peut d�cider de poursuivre le processus d'adaptation. Pour cela on revient dans SALOME et on active le module HOMARD. On d�signe l'it�ration que l'avait calcul�e pr�c�demment "*Iter_1*" et on demande une nouvelle it�ration. La fen�tre suivante appara�t :

.. image:: images/intro_38.png
   :align: center

Comme on continue l'adaptation avec le m�me crit�re de saut de temp�rature entre noeuds voisins, on garde l'hypoth�se "*Hypo_1*". Il suffit de d�signer le fichier issu du calcul que l'on vient de faire et qui contient le nouveau champ de temp�rature.

.. image:: images/intro_39.png
   :align: center

Comme pr�c�demment, on lance l'adaptation et on r�cup�re les r�sultats dans le r�pertoire du cas, dont le maillage ``maill.02.med``.

.. image:: ../images/intro_40.png
   :align: center

On peut alors lancer un nouveau calcul sur ce nouveau maillage et poursuiver cette alternance calcul/adaptation jusqu'� l'obtention du r�sultat attendu.






