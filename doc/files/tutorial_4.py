#!/usr/bin/env python
# -*- coding: iso-8859-1 -*-

# Copyright (C) 2011-2013  CEA/DEN, EDF R&D
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
#

"""
Exemple de couplage HOMARD-Salome
Copyright EDF-R&D 1996, 2011, 2013
"""
__revision__ = "V2.2"
#
import os
#
# ==================================
# Repertoire a personnaliser
# Ce repertoire contiendra les fichiers de resultats : maill.01.med, maill.02.med, maill.03.med
if os.environ.has_key("LOGNAME") :
  user = os.environ ["LOGNAME"]
else :
  user = "anonymous"
dircase = os.path.join( os.sep, "tmp", "HOMARD_"+user)
if not os.path.isdir(dircase) :
    os.mkdir (dircase)
# ==================================
# Ce repertoire contient les fichiers de donnees : tutorial_4.00.med, tutorial_4.fr.med
pathHomard = os.getenv('HOMARD_ROOT_DIR')
data_dir = os.path.join(pathHomard, "share/doc/salome/gui/HOMARD/fr/_downloads")
#
import salome
salome.salome_init()
import HOMARD
#
homard = salome.lcc.FindOrLoadComponent("FactoryServer", "HOMARD")
study_main = salome.myStudyManager.NewStudy("HOMARD")
homard.SetCurrentStudy(salome.myStudy)
#
# Creation of the boundaries
# ==========================
Boundary_1 = homard.CreateBoundaryDi('intersection', 'PIQUAGE', data_dir+'/tutorial_4.fr.med')
#
Boundary_2 = homard.CreateBoundaryCylinder('cyl_1_ext', 0.0, 25., -25., 25., 50., 75., 100.)
#
Boundary_3 = homard.CreateBoundaryCylinder('cyl_2_ext', 17.5, -2.5, -12.5, -100., -75., -25., 50.)
#
Boundary_4 = homard.CreateBoundaryCylinder('cyl_1_int', 0.0, 25., -25., 25., 50., 75., 75.)
#
Boundary_5 = homard.CreateBoundaryCylinder('cyl_2_int', 17.5, -2.5, -12.5, -100., -75., -25., 25.)
#
# Hypothesis
# ==========
# Creation of the hypothesis Hypo_1
Hypo_1 = homard.CreateHypothesis('Hypo_1')
Hypo_1.SetAdapRefinUnRef(-1, 1, 0)
Hypo_1.AddGroup('T1_INT_I')
Hypo_1.AddGroup('T1_INT_O')
Hypo_1.AddGroup('T2_INT')
# Creation of the hypothesis Hypo_2
Hypo_2 = homard.CreateHypothesis('Hypo_2')
Hypo_2.SetAdapRefinUnRef(-1, 1, 0)
Hypo_2.AddGroup('T1_EXT_I')
Hypo_2.AddGroup('T1_EXT_O')
Hypo_2.AddGroup('T2_EXT')
#
# Case "Case"
# =============
Case = homard.CreateCase('Case', 'PIQUAGE', data_dir+'/tutorial_4.00.med')
Case.SetDirName(dircase)
Case.AddBoundaryGroup( 'intersection', '' )
Case.AddBoundaryGroup( 'cyl_1_int', 'T1_INT_I' )
Case.AddBoundaryGroup( 'cyl_1_ext', 'T1_EXT_I' )
Case.AddBoundaryGroup( 'cyl_1_int', 'T1_INT_O' )
Case.AddBoundaryGroup( 'cyl_1_ext', 'T1_EXT_O' )
Case.AddBoundaryGroup( 'cyl_2_int', 'T2_INT' )
Case.AddBoundaryGroup( 'cyl_2_ext', 'T2_EXT' )
#
# Creation of the iterations
# ==========================
# Creation of the iteration Iter_1 : raffinement selon les faces internes
Iter_1 = Case.NextIteration('Iter_1')
Iter_1.SetMeshName('PIQUAGE_1')
Iter_1.SetMeshFile(dircase+'/maill.01.med')
Iter_1.AssociateHypo('Hypo_1')
codret = Iter_1.Compute(1, 2)
# Creation of the iteration Iter_2 : raffinement selon les faces externes
Iter_2 = Iter_1.NextIteration('Iter_2')
Iter_2.SetMeshName('PIQUAGE_2')
Iter_2.SetMeshFile(dircase+'/maill.02.med')
Iter_2.AssociateHypo('Hypo_2')
codret = Iter_2.Compute(1, 2)
# Creation of the iteration Iter_3 : second raffinement selon les faces externes
Iter_3 = Iter_2.NextIteration('Iter_3')
Iter_3.SetMeshName('PIQUAGE_3')
Iter_3.SetMeshFile(dircase+'/maill.03.med')
Iter_3.AssociateHypo('Hypo_2')
codret = Iter_3.Compute(1, 2)

if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
