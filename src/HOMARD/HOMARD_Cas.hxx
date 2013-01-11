//  HOMARD HOMARD : implementaion of HOMARD idl descriptions
//
// Copyright (C) 2011-2012  CEA/DEN, EDF R&D
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
//
//  File   : HOMARD_Cas.hxx
//  Author : Paul RASCLE, EDF
//  Module : HOMARD

#ifndef _HOMARD_CAS_HXX_
#define _HOMARD_CAS_HXX_

#include <string>
#include <list>
#include <vector>

class HOMARD_Cas
{
public:
  HOMARD_Cas();
  ~HOMARD_Cas();

  void                          SetName( const char* Name );
  std::string                   GetName() const;

  void                          SetDirName( const char* NomDir );
  std::string                   GetDirName() const;

  void                          SetConfType( int ConfType );
  const int                     GetConfType() const;
  int                           GetNumber();

  void                          AddIteration( const char* NomIteration );
  const std::list<std::string>& GetIterations() const;
  void                          SupprIterations();

  std::string                   GetIter0Name() const;
  std::string                   GetDumpPython() const;

  void                          SetBoundingBox( const std::vector<double>& extremas );
  const std::vector<double>&    GetBoundingBox() const;

  void                          SetGroups( const std::list<std::string>& ListGroup );

  void                          AddGroup( const char* Group);
  const std::list<std::string>& GetGroups() const;
  void                          SupprGroups();

//   void                          SetBoundary( const std::list<std::string>& ListBoundary );

  void                          AddBoundaryGroup( const char* Boundary, const char* Group );
  const std::list<std::string>& GetBoundaryGroup() const;
  void                          SupprBoundaryGroup();

  void                          SetPyram( int Pyram );
  const int                     GetPyram() const;

private:
  std::string                   _Name;
  std::string                   _NomDir;
  int                           _ConfType;

  std::vector<double>           _Boite;         // cf HomardQTCommun pour structure du vecteur
  std::list<std::string>        _ListGroup;
  std::list<std::string>        _ListBoundaryGroup;

  int                           _Pyram;

  typedef std::string           IterName;
  typedef std::list<IterName>   IterNames;
  IterNames                     _ListIter;
};

#endif
