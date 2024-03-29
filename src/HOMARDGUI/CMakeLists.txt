# Copyright (C) 2012-2014  CEA/DEN, EDF R&D
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
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

INCLUDE(UseQt4Ext)
INCLUDE(UsePyQt4)

# --- options ---
# additional include directories
INCLUDE_DIRECTORIES(
  ${QT_INCLUDES}
  ${CAS_INCLUDE_DIRS}
  ${PYTHON_INCLUDE_DIRS}
  ${MEDFILE_INCLUDE_DIRS}
  ${HDF5_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${OMNIORB_INCLUDE_DIR}
  ${KERNEL_INCLUDE_DIRS}
  ${GUI_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PROJECT_BINARY_DIR}
  ${PROJECT_BINARY_DIR}/idl
  ${PROJECT_BINARY_DIR}/adm_local/unix
  ${PROJECT_SOURCE_DIR}/src/HOMARD
  ${PROJECT_SOURCE_DIR}/src/HOMARD_I
)

# additional preprocessor / compiler flags
ADD_DEFINITIONS(
  ${BOOST_DEFINITIONS}
  ${OMNIORB_DEFINITIONS}
  ${CAS_DEFINITIONS}
  ${KERNEL_DEFINITIONS}
)

# libraries to link to
SET(_link_LIBRARIES
  ${MEDFILE_C_LIBRARIES}
  ${KERNEL_SalomeLifeCycleCORBA}
  ${KERNEL_SalomeDS}
  ${GUI_SalomeApp}
  SalomeIDLHOMARD
  HOMARDEngine
)

# --- headers ---

# header files / to be processed by moc
SET(_moc_HEADERS
  HOMARDGUI.h
  MonCreateBoundaryAn.h
  MonEditBoundaryAn.h
  MonCreateBoundaryDi.h
  MonEditBoundaryDi.h
  MonCreateCase.h
  MonEditCase.h
  MonCreateZone.h
  MonEditZone.h
  MonCreateHypothesis.h
  MonEditHypothesis.h
  MonCreateListGroup.h
  MonEditListGroup.h
  MonCreateIteration.h
  MonEditIteration.h
  MonPursueIteration.h
  MonMeshInfo.h
  MonIterInfo.h
  MonCreateYACS.h
  MonEditYACS.h
  MonEditFile.h
)

# header files / no moc processing
SET(_other_HEADERS
  CreateBoundaryAn.h
  CreateBoundaryDi.h
  CreateCase.h
  CreateZone.h
  CreateHypothesis.h
  CreateListGroup.h
  CreateIteration.h
  PursueIteration.h
  MeshInfo.h
  IterInfo.h
  CreateYACS.h
  HOMARDGUI_Utils.h
  EditFile.h
  HomardQtCommun.h
  HOMARDGUI_Exports.hxx
)

# header files / to install
SET(HOMARD_HEADERS ${_other_HEADERS} ${_moc_HEADERS})

# --- sources ---

# sources / moc wrappings
QT4_WRAP_CPP(_moc_SOURCES ${_moc_HEADERS})

# sources / static
SET(_other_SOURCES
  HOMARDGUI.cxx
  HOMARDGUI_Utils.cxx
  MonCreateBoundaryAn.cxx
  MonEditBoundaryAn.cxx
  MonCreateBoundaryDi.cxx
  MonEditBoundaryDi.cxx
  MonCreateCase.cxx
  MonEditCase.cxx
  MonCreateHypothesis.cxx
  MonEditHypothesis.cxx
  MonCreateListGroup.cxx
  MonEditListGroup.cxx
  MonCreateIteration.cxx
  MonEditIteration.cxx
  MonPursueIteration.cxx
  MonCreateZone.cxx
  MonEditZone.cxx
  MonMeshInfo.cxx
  MonIterInfo.cxx
  MonCreateYACS.cxx
  MonEditYACS.cxx
  MonEditFile.cxx
  HomardQtCommun.cxx
)

# sources / to compile
SET(HOMARD_SOURCES ${_other_SOURCES} ${_moc_SOURCES})

# --- resources ---

# resource files / to be processed by lrelease
SET(_ts_RESOURCES
  HOMARD_msg_en.ts
  HOMARD_msg_fr.ts
  HOMARD_msg_ja.ts
) 

# no install files
# uic files / to be processed by pyuic
SET(_pyuic_files
  CreateBoundaryAn.ui
  CreateBoundaryDi.ui
  CreateCase.ui
  CreateHypothesis.ui
  CreateIteration.ui
  CreateListGroup.ui
  CreateZone.ui
  PursueIteration.ui
  MeshInfo.ui
  IterInfo.ui
  CreateYACS.ui
  EditFile.ui
)

# scripts / pyuic wrappings
PYQT4_WRAP_UIC(_pyuic_SCRIPTS ${_pyuic_files})

# --- rules ---

ADD_LIBRARY(HOMARD ${HOMARD_SOURCES})
TARGET_LINK_LIBRARIES(HOMARD ${_link_LIBRARIES} )
INSTALL(TARGETS HOMARD EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})

INSTALL(FILES ${HOMARD_HEADERS} DESTINATION ${SALOME_INSTALL_HEADERS})
QT4_INSTALL_TS_RESOURCES("${_ts_RESOURCES}" "${SALOME_HOMARD_INSTALL_RES_DATA}")
