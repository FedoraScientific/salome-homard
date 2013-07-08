.. _yacs:

YACS
####
.. index:: single: yacs

Introduction
************

L'utilisation de sch�mas YACS va permettre de coupler un calcul et une adaptation comme il est d�crit dans :ref:`intro`. Ce couplage peut �tre r�p�t� au sein d'une boucle jusqu'� l'obtention d'un crit�re de convergence par exemple. Il existe de nombreuses fa�ons de programmer un sch�ma YACS. La solution propos�e ici fonctionne mais on peut tr�s bien faire autrement !

On va d�crire ici un sch�ma s'appliquant � un calcul pour lequel on cherche � stabiliser une valeur. Le calcul d�marre sur un maillage initial puis HOMARD encha�ne avec une adaptation. On refait un calcul sur ce nouveau maillage et son r�sultat est analys�. En fonction de cette analyse, le couplage continue ou non. L'allure g�n�rale du sch�ma est la suivante :

.. image:: ../images/yacs_01.png
   :align: center
   :alt: yacs - allure g�n�rale
   :width: 535
   :height: 362

.. note::
  Parmi l'ensemble des donn�es manipul�es, certaines sont immuables : le nom du r�pertoire de calcul, le nom du cas, le nom de l'hypoth�se d'adaptation, etc. Il a �t� choisi de les imposer 'en dur' dans les diff�rents param�tres de service ou au sein des scripts python. On pourrait �galement les d�finir a priori dans un noeud PresetNode et ensuite les transmettre par des liens. Nous n'avons pas retenu cette solution car elle augmente fortement le nombre de param�tres et de liens attach�s � chaque noeud. Cela est tr�s p�nalisant pour la lisibilit� du sch�ma. Les seules donn�es qui vont circuler sont celles impos�es par la description du service et celles qui �voluent au cours de l'ex�cution du sch�ma.

Les bo�tes
**********

Les bo�tes principales sont :

- DataInit : initialisation du maillage initial
- Etude_Initialisation : lancement du module HOMARD dans SALOME
- Tant_que_le_calcul_n_a_pas_converge : gestion de la boucle d'alternance calcul/adaptation
- Bilan : affichage final

DataInit
========
.. image:: ../images/yacs_a_01.png
   :align: center
   :alt: DataInit
   :width: 158
   :height: 61

Cette bo�te est un noeud �l�mentaire de type PresetNode. Sa seule fonction est d'initialiser la variable MeshFile qui contient le nom du fichier du maillage initial.

.. literalinclude:: ../files/yacs_01.xml
   :lines: 70-74

Etude_Initialisation
====================
La bo�te Etude_Initialisation lance le composant HOMARD dans SALOME. C'est un bloc compos� de deux parties, qui sont invariables quelle que soit l'application envisag�e :

- StudyCreation : noeud python
- SetCurrentStudy : service du composant HOMARD

.. image:: ../images/yacs_b_01.png
   :align: center
   :alt: Etude_Initialisation
   :width: 323
   :height: 97

Le noeud python StudyCreation sert � initialiser l'�tude SALOME qui est fournie en sortie :

.. literalinclude:: ../files/yacs_01.xml
   :lines: 39-57

Le service SetCurrentStudy affecte cette �tude � une instance de HOMARD.

.. literalinclude:: ../files/yacs_01.xml
   :lines: 58-63


Tant_que_le_calcul_n_a_pas_converge
===================================
La bo�te Tant_que_le_calcul_n_a_pas_converge est une boucle de type WhileLoop. La condition est initialis�e � 1 : le bloc interne Alternance_Calcul_HOMARD est ex�cut�. Au sein de ce bloc, on calcule et on adapte le maillage ; quand le processus doit s'arr�ter soit par suite d'erreur, soit par convergence, la condition passe � 0. La boucle s'ach�ve et on passe � la bo�te suivante, Bilan.

.. image:: ../images/yacs_c_01.png
   :align: center
   :alt: Boucle
   :width: 195
   :height: 142

Bilan
=====
.. image:: ../images/yacs_d_01.png
   :align: center
   :alt: Bilan
   :width: 158
   :height: 63

Cette bo�te est un noeud python qui prend en entr�e une cha�ne de caract�res, MessInfo. Si tout s'est bien pass�, ce message est vide. Une fen�tre QT appara�t pour confirmer la convergence. S'il y a eu un probl�me, le message contient les messages �mis au cours des calculs. La fen�tre QT affiche ce message.

.. literalinclude:: ../files/yacs_01.xml
   :lines: 424-437


La boucle de calculs
********************
.. image:: ../images/yacs_c_02.png
   :align: center
   :alt: Boucle
   :width: 323
   :height: 158

Cette bo�te est un bloc qui g�re le calcul, l'adaptation et l'analyse.

Calcul
======
.. image:: ../images/yacs_c_03.png
   :align: center
   :alt: Calcul
   :width: 155
   :height: 87

Cette bo�te est un noeud python qui va piloter le calcul. En entr�e, on trouve le num�ro du calcul (0 au d�part) et le nom du fichier qui contient le maillage sur lequel calculer. En sortie, on trouve un entier qui repr�sente l'erreur sur ce calcul (0 si tout va bien) et un dictionnaire python rassemblant les r�sultats du calcul. Le corps du noeud est constitu� par le lancement d'un script python qui active le calcul.

.. literalinclude:: ../files/yacs_01.xml
   :lines: 155-182

Dans cet exemple, il faut d�finir :

- rep_calc : le r�pertoire dans lequel sera ex�cut� le calcul.
- rep_script : le r�pertoire dans lequel se trouve le python qui lancera le calcul. Ce r�pertoire est � ajouter au PATH. Depuis ce r�pertoire, on importera LanceCas depuis le fichier LanceCas.py

Le python LanceCas est programm� comme l'utilisateur le souhaite pour que le calcul puisse �tre effectu� sur le maillage courant. Selon le mode de lancement du code de calcul, on peut avoir besoin d'autres informations, comme le num�ro du calcul ou le r�pertoire du calcul par exemple. La libert� est totale. Dans notre cas, les arguments d'entr�e sont le nom du fichier de maillage, le num�ro du calcul et le r�pertoire de calcul sous la forme de la liste python ["--rep_calc=rep_calc", "--numero=numCalc", "--mesh_file=MeshFile"]
].

En revanche la sortie du script doit ob�ir � la r�gle suivante. On r�cup�re un code d'erreur, un message d'erreur et un dictionnaire. Ce dictionnaire contient obligatoirement les cl�s suivantes :

- "FileName" : le nom du fichier qui contient les r�sultats du calcul
- "MeshName" : le nom du maillage utilis�
- "V00" : la valeur dont on veut tester la convergence

Adaptation
==========
.. image:: ../images/yacs_c_04.png
   :align: center
   :alt: Adaptation
   :width: 672
   :height: 569

La bo�te Adaptation est un noeud Switch pilot� par le code d'erreur du calcul pr�c�dent. Si ce code est nul, YACS activera la bo�te Adaptation_HOMARD qui lancera l'adaptation. Si le code n'est pas nul, on passe directement dans la bo�te Arret_boucle.

Adaptation_HOMARD
-----------------
La premi�re t�che � ex�cuter concerne l'initialisation des donn�es n�cessaires � HOMARD dans la bo�te HOMARD_Initialisation. Cette bo�te est un noeud switch pilot� par le num�ro du calcul. Au d�marrage, le num�ro est nul et YACS active la bo�te Homard_init_au_debut.

Homard_init_au_debut
^^^^^^^^^^^^^^^^^^^^
.. image:: ../images/yacs_c_06.png
   :align: center
   :alt: Homard_init_au_debut
   :width: 481
   :height: 150

Cette bo�te commence par cr�er le cas HOMARD en appelant le service CreateCase.

.. literalinclude:: ../files/yacs_01.xml
   :lines: 220-227

Le nom du cas CaseName est impos� � "Calcul". Les param�tres d'entr�e MeshName et FileName sont issus de la sortie du calcul pr�c�dent. Le param�tre de sortie est une instance de cas.

.. literalinclude:: ../files/yacs_01.xml
   :lines: 461-464

Les options de ce cas doivent maintenant �tre renseign�es. C'est fait par le noeud python CaseOptions. Il est imp�ratif de renseigner le r�pertoire de calcul. On regardera la description des fonctions dans :ref:`tui_create_case`. En sortie, on r�cup�re l'instance de l'it�ration correspondant � l'�tat initial du cas.

.. literalinclude:: ../files/yacs_01.xml
   :lines: 228-242

Enfin, une hypoth�se est cr��e en appelant le service CreateHypoth�se. Le param�tre de sortie est une instance d'hypoth�se.

Homard_Exec
^^^^^^^^^^^
Une fois initialis�e, l'adaptation peut �tre calcul�e. C'est le but de la bo�te Homard_Exec, sous forme d'un script python.

.. image:: ../images/yacs_c_09.png
   :align: center
   :alt: Homard_Exec
   :width: 153
   :height: 141

Le r�pertoire de calcul est r�cup�r�.

.. literalinclude:: ../files/yacs_01.xml
   :lines: 258-263

../..

.. literalinclude:: ../files/yacs_01.xml
   :lines: 339-347

L'hypoth�se transmise en param�tre d'entr�e est caract�ris�e (voir :ref:`tui_create_hypothese`) :

.. literalinclude:: ../files/yacs_01.xml
   :lines: 267-291

Il faut �tablir un nom pour la future it�ration. Pour s'assurer que le nom n'a jamais �t� utilis�, on met en place un m�canisme de nommage incr�mental � partir du nom de l'it�ration initiale. Comme ce nom initial est le nom du maillage initial, on obtient une succession de noms sous la forme : M_001, M_002, M_003, etc.

.. literalinclude:: ../files/yacs_01.xml
   :lines: 293-303

L'it�ration est compl�t�e : hypoth�se, futur maillage, champ (voir :ref:`tui_create_iteration`) :

.. literalinclude:: ../files/yacs_01.xml
   :lines: 305-325

L'it�ration est calcul�e. Si tout s'est bien pass�, la variable OK vaut 1 : on pourra continuer l'ex�cution du sch�ma. S'il y a eu un probl�me, la variable OK vaut 0 pour signifier que le calcul doit s'arr�ter ; on donne alors un message d'erreur.

.. literalinclude:: ../files/yacs_01.xml
   :lines: 327-338

Apr�s cette ex�cution, le processus sort du noeud Adaptation_HOMARD, puis du noeud Adaptation. On arrive alors au noeud d'analyse.

Homard_init_ensuite
^^^^^^^^^^^^^^^^^^^
.. image:: ../images/yacs_c_07.png
   :align: center
   :alt: Homard_init_ensuite
   :width: 323
   :height: 97

Aux passages suivants dans le bloc d'adaptation, il faut r�cup�rer :

- la derni�re it�ration cr��e pour la poursuivre : service LastIteration (voir :ref:`tui_create_iteration`)
- l'hypoth�se cr��e : service GetHypothesis (voir :ref:`tui_create_hypothese`)

On passe ensuite dans le noeud Homard_Exec pour calculer le nouveau maillage.

Arret_boucle
------------
.. image:: ../images/yacs_c_08.png
   :align: center
   :alt: Arret_boucle
   :width: 163
   :height: 152

Le bloc Arret_boucle n'est pr�sent que pour faire transiter des variables car les param�tres d'entr�e des noeuds doivent toujours �tre remplis. C'est un python tr�s simple :

.. literalinclude:: ../files/yacs_01.xml
   :lines: 185-196

Analyse
=======
.. image:: ../images/yacs_c_05.png
   :align: center
   :alt: Analyse
   :width: 155
   :height: 169

Le bloc Analyse est un script python qui assure le contr�le complet du processus en examinant successivement les causes d'erreur possible.

.. literalinclude:: ../files/yacs_01.xml
   :lines: 77-90

../..

.. literalinclude:: ../files/yacs_01.xml
   :lines: 145-154

On commence par analyser le retour du code de calcul :

.. literalinclude:: ../files/yacs_01.xml
   :lines: 92-97

V�rification de la pr�sence du nom du maillage dans le dictionnaire des r�sultats :

.. literalinclude:: ../files/yacs_01.xml
   :lines: 99-106

V�rification de la pr�sence du nom du fichier de r�sultats dans le dictionnaire des r�sultats :

.. literalinclude:: ../files/yacs_01.xml
   :lines: 108-115

V�rification de la convergence. Cela suppose que la valeur � tester est pr�sente dans le dictionnaire sous la cl� 'V00'. Ici, on a mis en place un test sur la variation de la valeur d'un calcul � l'autre. Au premier passage, on ne teste rien. Aux passages suivants, on teste si la variation relative est inf�rieure � 1 milli�me. On aurait pu mettre en place un test absolu si on avait r�cup�r� un niveau global d'erreur par exemple.

.. literalinclude:: ../files/yacs_01.xml
   :lines: 117-135

Enfin, on v�rifie que l'on ne d�passe pas un nomber maximal d'adaptations :

.. literalinclude:: ../files/yacs_01.xml
   :lines: 137-142


Utiliser ce sch�ma
******************
Pour reproduire cet exemple, voici le :download:`sch�ma � t�l�charger <../files/yacs_01.xml>`. Il faut l'adapter � la simulation envisag�e. En particulier, il faut :

- ajuster les noms des fichiers et des r�pertoires
- fournir un script de lancement du calcul respectant les consignes �voqu�es ci-avant
- choisir les hypoth�ses de pilotage de l'adaptation
- mettre en place le test d'arr�t


