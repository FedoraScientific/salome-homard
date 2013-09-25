.. _gui_create_yacs_aster:

Un sch�ma YACS pour Code_Aster
##############################
.. index:: single: YACS
.. index:: single: Code_Aster

Dans le cas o� le sch�ma implique un couplage entre *Code_Aster* et HOMARD, une fa�on de faire est d�crite ici. Les seules contraintes sont des conventions pour que le script de pilotage de *Code_Aster* fonctionne correctement au sein du sch�ma.

Pr�parations
************
Le r�pertoire de calcul
=======================
La premi�re phase consiste � cr�er un r�pertoire qui abritera les fichiers du calcul et les fichiers des maillages successifs.

Les commandes
=============
Les commandes du calcul sont � d�finir comme pour n'importe quel calcul. On particularisera uniquement la r�cup�ration de la valeur de test pour la convergence.

La valeur de test
-----------------
Pour r�cup�rer la valeur de test ``V_TEST``, le script va chercher dans le fichier ``resu``, la ligne de type :
::

    V_TEST    0.02071983

Pour cela, la meilleure fa�on consiste � placer la valeur � tester dans une table intitul�e ``V_TEST``, par exemple apr�s une extraction depuis un r�sultat :

.. literalinclude:: ../files/yacs_aster_01.comm
   :lines: 53-59

puis � imprimer cette table en se limitant aux deux param�tres ``INTITULE`` et composante retenue :

.. literalinclude:: ../files/yacs_aster_01.comm
   :lines: 63-64

Le pilotage de l'adaptation
---------------------------
Si on souhaite piloter l'adaptation par un champ, il faudra �crire ce champ dans le fichier MED de sortie. Ce peut �tre un indicateur d'erreur (commande CALC_ERREUR) ou un autre champ.

Par exemple :

.. literalinclude:: ../files/yacs_aster_01.comm
   :lines: 68-78

Le script
=========
Le script de pilotage de *Code_Aster* � fournir au sch�ma YACS est � t�l�charger ici : :download:`ScriptAster<../files/yacs_script.py>`. Ce fichier peut �tre plac� n'importe o�.

Comment proc�der ?
******************
Un premier calcul
=================
Une fois les commandes au point, il faut lancer un premier calcul. Cela permet de choisir le param�trage du calcul : version de *Code_Aster*, serveur de calcul, interactif/batch, etc. Ce sont ces param�tres qui seront utilis�s pour les calculs successifs dans le sch�ma. Le lancement de *Code_Aster* rassemble ces informations dans un fichier de type ``export``. Il faut copier ce fichier sous le nom ``calcul.ref.export`` dans le r�pertoire de calcul.

Cr�ation du sch�ma
==================
Quand le calcul est termin�, il faut encha�ner les �tapes suivante :

- v�rifier que le fichier de r�sultats au format MED a �t� cr�� et que le fichier de r�sultats de type ``resu`` contient la ligne donnant la valeur � tester ;
- activer le module HOMARD de SALOME ;
- cr�er un cas � partir du maillage initial ;
- cr�er une it�ration en se basant sur le champ que l'on a retenu ;
- �ventuellement calculer cette it�ration pour contr�ler les choix, mais ce n'est pas obligatoire ;
- cr�er le sch�ma bas� sur ce cas.

Lancer le sch�ma
================
Le sch�ma est �crit dans le fichier ``schema.xml`` dans le r�pertoire li� au cas qui en est le support. Ce fichier peut �tre d�plac� sans probl�me. On peut modifier les param�tres de contr�le par d�faut de la boucle de l'alternance (calcul/adaptation).

On active alors le module YACS, on importe le sch�ma et on l'ex�cute.






