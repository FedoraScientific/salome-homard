// Copyright (C) 2011-2014  CEA/DEN, EDF R&D
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
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

// Remarques :
// L'ordre de description des fonctions est le meme dans tous les fichiers
// HOMARD_aaaa.idl, HOMARD_aaaa.hxx, HOMARD_aaaa.cxx, HOMARD_aaaa_i.hxx, HOMARD_aaaa_i.cxx :
// 1. Les generalites : Name, Delete, DumpPython, Dump, Restore
// 2. Les caracteristiques
// 3. Le lien avec les autres structures
//
// Quand les 2 fonctions Setxxx et Getxxx sont presentes, Setxxx est decrit en premier
//

#include "HOMARD_Cas_i.hxx"
#include "HOMARD_Gen_i.hxx"
#include "HOMARD_Cas.hxx"
#include "HOMARD_DriverTools.hxx"
#include "HOMARD.hxx"

#include "utilities.h"
#include <vector>
#include <sys/stat.h>

#ifdef WIN32
#include <direct.h>
#endif

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Cas_i::HOMARD_Cas_i()
{
  MESSAGE( "Default constructor, not for use" );
  ASSERT( 0 );
}

//=============================================================================
/*!
 *  standard constructor
 */
//=============================================================================
HOMARD_Cas_i::HOMARD_Cas_i( CORBA::ORB_ptr orb,
                            HOMARD::HOMARD_Gen_var engine )
{
  MESSAGE( "HOMARD_Cas_i" );
  _gen_i = engine;
  _orb = orb;
  myHomardCas = new ::HOMARD_Cas();
  ASSERT( myHomardCas );
}

//=============================================================================
/*!
 *  standard destructor
 */
//=============================================================================
HOMARD_Cas_i::~HOMARD_Cas_i()
{
}
//=============================================================================
//=============================================================================
// Generalites
//=============================================================================
//=============================================================================
void HOMARD_Cas_i::SetName( const char* Name )
{
  ASSERT( myHomardCas );
  myHomardCas->SetName( Name );
}
//=============================================================================
char* HOMARD_Cas_i::GetName()
{
  ASSERT( myHomardCas );
  return CORBA::string_dup( myHomardCas->GetName().c_str() );
}
//=============================================================================
CORBA::Long  HOMARD_Cas_i::Delete( CORBA::Long Option )
{
  ASSERT( myHomardCas );
  char* CaseName = GetName() ;
  MESSAGE ( "Delete : destruction du cas " << CaseName << ", Option = " << Option );
  return _gen_i->DeleteCase(CaseName, Option) ;
}
//=============================================================================
char* HOMARD_Cas_i::GetDumpPython()
{
  ASSERT( myHomardCas );
  return CORBA::string_dup( myHomardCas->GetDumpPython().c_str() );
}
//=============================================================================
std::string HOMARD_Cas_i::Dump() const
{
  return HOMARD::Dump( *myHomardCas );
}
//=============================================================================
bool HOMARD_Cas_i::Restore( const std::string& stream )
{
  return HOMARD::Restore( *myHomardCas, stream );
}
//=============================================================================
//=============================================================================
// Caracteristiques
//=============================================================================
//=============================================================================
void HOMARD_Cas_i::SetDirName( const char* NomDir )
{
  ASSERT( myHomardCas );
  int codret ;
  // A. recuperation du nom ; on ne fait rien si c'est le meme
  char* oldrep = GetDirName() ;
  if ( strcmp(oldrep,NomDir) == 0 )
  {
   return ;
  }
  MESSAGE ( "SetDirName : passage de oldrep = "<< oldrep << " a NomDir = "<<NomDir);
  // B. controle de l'usage du repertoire
  char* CaseName = GetName() ;
  char* casenamedir = _gen_i->VerifieDir(NomDir) ;
  if ( ( std::string(casenamedir).size() > 0 ) & ( strcmp(CaseName,casenamedir)!=0 ) )
  {
    INFOS ( "Le repertoire " << NomDir << " est deja utilise pour le cas "<< casenamedir );
    SALOME::ExceptionStruct es;
    es.type = SALOME::BAD_PARAM;
    std::string text ;
    text = "The directory " + std::string(NomDir) + " is already used for the case " + std::string(casenamedir) ;
    es.text = CORBA::string_dup(text.c_str());
    throw SALOME::SALOME_Exception(es);
  }
  // C. Changement/creation du repertoire
  codret = myHomardCas->SetDirName( NomDir );
  if ( codret != 0 )
  {
    SALOME::ExceptionStruct es;
    es.type = SALOME::BAD_PARAM;
    std::string text ;
    if ( codret == 1 ) { text = "The directory for the case cannot be modified because some iterations are already defined." ; }
    else               { text = "The directory for the case cannot be reached." ; }
    es.text = CORBA::string_dup(text.c_str());
    throw SALOME::SALOME_Exception(es);
  }
  // D. En cas de reprise, deplacement du point de depart
  if ( GetState() != 0 )
  {
    MESSAGE ( "etat : " << GetState() ) ;
    // D.1. Nom local du repertoire de l'iteration de depart dans le repertoire actuel du cas
    HOMARD::HOMARD_Iteration_ptr Iter = GetIter0() ;
    char* DirNameIter = Iter->GetDirNameLoc() ;
    MESSAGE ( "SetDirName : nom actuel pour le repertoire de l iteration, DirNameIter = "<< DirNameIter);
    // D.2. Recherche d'un nom local pour l'iteration de depart dans le futur repertoire du cas
    char* nomDirIter = _gen_i->CreateDirNameIter(NomDir, 0 );
    MESSAGE ( "SetDirName : nom futur pour le repertoire de l iteration, nomDirIter = "<< nomDirIter);
    // D.3. Creation du futur repertoire local pour l'iteration de depart
    std::string nomDirIterTotal ;
    nomDirIterTotal = std::string(NomDir) + "/" + std::string(nomDirIter) ;
#ifndef WIN32
    if (mkdir(nomDirIterTotal.c_str(), S_IRWXU|S_IRGRP|S_IXGRP) != 0)
#else
    if (_mkdir(nomDirIterTotal.c_str()) != 0)
#endif
    {
      MESSAGE ( "nomDirIterTotal : " << nomDirIterTotal ) ;
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      std::string text = "The directory for the starting iteration cannot be created." ;
      es.text = CORBA::string_dup(text.c_str());
      throw SALOME::SALOME_Exception(es);
    }
    // D.4. Deplacement du contenu du repertoire
    std::string oldnomDirIterTotal ;
    oldnomDirIterTotal = std::string(oldrep) + "/" + std::string(DirNameIter) ;
    std::string commande = "mv " + std::string(oldnomDirIterTotal) + "/*" + " " + std::string(nomDirIterTotal) ;
    codret = system(commande.c_str()) ;
    if ( codret != 0 )
    {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      std::string text = "The starting point for the case cannot be moved into the new directory." ;
      es.text = CORBA::string_dup(text.c_str());
      throw SALOME::SALOME_Exception(es);
    }
    commande = "rm -rf " + std::string(oldnomDirIterTotal) ;
    codret = system(commande.c_str()) ;
    if ( codret != 0 )
    {
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      std::string text = "The starting point for the case cannot be deleted." ;
      es.text = CORBA::string_dup(text.c_str());
      throw SALOME::SALOME_Exception(es);
    }
    // D.5. Memorisation du nom du repertoire de l'iteration
    Iter->SetDirNameLoc(nomDirIter) ;
  }
  return ;
}
//=============================================================================
char* HOMARD_Cas_i::GetDirName()
{
  ASSERT( myHomardCas );
  return CORBA::string_dup( myHomardCas->GetDirName().c_str() );
}
//=============================================================================
CORBA::Long HOMARD_Cas_i::GetState()
{
  ASSERT( myHomardCas );
// Nom de l'iteration initiale
  char* Iter0Name = GetIter0Name() ;
  HOMARD::HOMARD_Iteration_ptr Iter = _gen_i->GetIteration(Iter0Name) ;
  int state = Iter->GetNumber() ;
  return state ;
}
//=============================================================================
CORBA::Long HOMARD_Cas_i::GetNumberofIter()
{
  ASSERT( myHomardCas );
  return myHomardCas->GetNumberofIter();
}
//=============================================================================
void HOMARD_Cas_i::SetConfType( CORBA::Long ConfType )
{
  ASSERT( myHomardCas );
//   VERIFICATION( (ConfType>=1) && (ConfType<=4) );
  myHomardCas->SetConfType( ConfType );
}
//=============================================================================
CORBA::Long HOMARD_Cas_i::GetConfType()
{
  ASSERT( myHomardCas );
  return myHomardCas->GetConfType();
}
//=============================================================================
void HOMARD_Cas_i::SetBoundingBox( const HOMARD::extrema& LesExtrema )
{
  ASSERT( myHomardCas );
  std::vector<double> VExtrema;
  ASSERT( LesExtrema.length() == 10 );
  VExtrema.resize( LesExtrema.length() );
  for ( int i = 0; i < LesExtrema.length(); i++ )
  {
    VExtrema[i] = LesExtrema[i];
  }
  myHomardCas->SetBoundingBox( VExtrema );
}
//=============================================================================
HOMARD::extrema* HOMARD_Cas_i::GetBoundingBox()
{
  ASSERT(myHomardCas );
  HOMARD::extrema_var aResult = new HOMARD::extrema();
  std::vector<double> LesExtremes = myHomardCas->GetBoundingBox();
  ASSERT( LesExtremes.size() == 10 );
  aResult->length( 10 );
  for ( int i = 0; i < LesExtremes.size(); i++ )
  {
    aResult[i] = LesExtremes[i];
  }
  return aResult._retn();
}
//=============================================================================
void HOMARD_Cas_i::AddGroup( const char* Group)
{
  ASSERT( myHomardCas );
  myHomardCas->AddGroup( Group );
}
//=============================================================================
void HOMARD_Cas_i::SetGroups( const HOMARD::ListGroupType& ListGroup )
{
  ASSERT( myHomardCas );
  std::list<std::string> ListString ;
  for ( int i = 0; i < ListGroup.length(); i++ )
  {
    ListString.push_back(std::string(ListGroup[i]));
  }
  myHomardCas->SetGroups( ListString );
}
//=============================================================================
HOMARD::ListGroupType* HOMARD_Cas_i::GetGroups()
{
  ASSERT(myHomardCas );
  const std::list<std::string>& ListString = myHomardCas->GetGroups();
  HOMARD::ListGroupType_var aResult = new HOMARD::ListGroupType();
  aResult->length( ListString.size() );
  std::list<std::string>::const_iterator it;
  int i = 0;
  for ( it = ListString.begin(); it != ListString.end(); it++ )
  {
    aResult[i++] = CORBA::string_dup( (*it).c_str() );
  }
  return aResult._retn();
}
//=============================================================================
void HOMARD_Cas_i::AddBoundaryGroup( const char* BoundaryName, const char* Group)
{
  MESSAGE ("AddBoundaryGroup : BoundaryName = "<< BoundaryName << ", Group = " << Group );
  ASSERT( myHomardCas );
  // A. La liste des frontiere+groupes
  const std::list<std::string>& ListBoundaryGroup = myHomardCas->GetBoundaryGroup();
  std::list<std::string>::const_iterator it;
  // B. La frontiere
  // B.1. La frontiere est-elle deja enregistree pour ce cas ?
  bool existe = false ;
  for ( it = ListBoundaryGroup.begin(); it != ListBoundaryGroup.end(); it++ )
  {
//     MESSAGE ("..  Frontiere : "<< *it );
    if ( *it == BoundaryName ) { existe = true ; }
    it++ ;
  }
  // B.2. Pour une nouvelle frontiere, publication dans l'arbre d'etudes sous le cas
  if ( !existe )
  {
    char* CaseName = GetName() ;
    MESSAGE ( "AddBoundaryGroup : insertion de la frontiere dans l'arbre de " << CaseName );
    _gen_i->PublishBoundaryUnderCase(CaseName, BoundaryName) ;
  }
  // C. Le groupe est-il deja enregistre pour une frontiere de ce cas ?
  for ( it = ListBoundaryGroup.begin(); it != ListBoundaryGroup.end(); it++ )
  {
    std::string boun = *it ;
    it++ ;
//     MESSAGE ("..  Group : "<< *it );
    if ( *it == Group )
    { INFOS ("Frontiere " << boun << " Un groupe est deja associe " << Group ) ;
      SALOME::ExceptionStruct es;
      es.type = SALOME::BAD_PARAM;
      es.text = "Invalid AddBoundaryGroup";
      throw SALOME::SALOME_Exception(es);
      return ;
    }
  }
  // D. Enregistrement du couple (frontiere,groupe) dans la reference du cas
  myHomardCas->AddBoundaryGroup( BoundaryName, Group );
}
//=============================================================================
HOMARD::ListBoundaryGroupType* HOMARD_Cas_i::GetBoundaryGroup()
{
  MESSAGE ("GetBoundaryGroup");
  ASSERT(myHomardCas );
  const std::list<std::string>& ListBoundaryGroup = myHomardCas->GetBoundaryGroup();
  HOMARD::ListBoundaryGroupType_var aResult = new HOMARD::ListBoundaryGroupType();
  aResult->length( ListBoundaryGroup.size() );
  std::list<std::string>::const_iterator it;
  int i = 0;
  for ( it = ListBoundaryGroup.begin(); it != ListBoundaryGroup.end(); it++ )
  {
    aResult[i++] = CORBA::string_dup( (*it).c_str() );
  }
  return aResult._retn();
}
//=============================================================================
void HOMARD_Cas_i::SupprBoundaryGroup()
{
  MESSAGE ("SupprBoundaryGroup");
  ASSERT(myHomardCas );
  myHomardCas->SupprBoundaryGroup();
}
//=============================================================================
void HOMARD_Cas_i::SetPyram( CORBA::Long Pyram )
{
  MESSAGE ("SetPyram, Pyram = " << Pyram );
  ASSERT( myHomardCas );
  myHomardCas->SetPyram( Pyram );
}
//=============================================================================
CORBA::Long HOMARD_Cas_i::GetPyram()
{
  MESSAGE ("GetPyram");
  ASSERT( myHomardCas );
  return myHomardCas->GetPyram();
}
//=============================================================================
void HOMARD_Cas_i::MeshInfo(CORBA::Long Qual, CORBA::Long Diam, CORBA::Long Conn, CORBA::Long Tail, CORBA::Long Inte)
{
  MESSAGE ( "MeshInfo : information sur le maillage initial du cas" );
  ASSERT( myHomardCas );
//
// Nom de l'iteration
  char* IterName = GetIter0Name() ;
  CORBA::Long etatMenage = -1 ;
  CORBA::Long modeHOMARD = 7 ;
  CORBA::Long Option1 = 1 ;
  CORBA::Long Option2 = 1 ;
  if ( Qual != 0 ) { modeHOMARD = modeHOMARD*5 ; }
  if ( Diam != 0 ) { modeHOMARD = modeHOMARD*19 ; }
  if ( Conn != 0 ) { modeHOMARD = modeHOMARD*11 ; }
  if ( Tail != 0 ) { modeHOMARD = modeHOMARD*13 ; }
  if ( Inte != 0 ) { modeHOMARD = modeHOMARD*3 ; }
  CORBA::Long codret = _gen_i->Compute(IterName, etatMenage, modeHOMARD, Option1, Option2) ;
  MESSAGE ( "MeshInfo : codret = " << codret );
  return ;
}
//=============================================================================
//=============================================================================
// Liens avec les autres structures
//=============================================================================
//=============================================================================
char* HOMARD_Cas_i::GetIter0Name()
{
  ASSERT( myHomardCas );
  return CORBA::string_dup( myHomardCas->GetIter0Name().c_str() );
}
//=============================================================================
HOMARD::HOMARD_Iteration_ptr HOMARD_Cas_i::GetIter0()
{
// Nom de l'iteration initiale
  char* Iter0Name = GetIter0Name() ;
  MESSAGE ( "GetIter0 : Iter0Name      = " << Iter0Name );
  return _gen_i->GetIteration(Iter0Name) ;
}
//=============================================================================
HOMARD::HOMARD_Iteration_ptr HOMARD_Cas_i::NextIteration( const char* IterName )
{
// Nom de l'iteration parent
  char* NomIterParent = GetIter0Name() ;
  MESSAGE ( "NextIteration : IterName      = " << IterName );
  MESSAGE ( "NextIteration : NomIterParent = " << NomIterParent );
  return _gen_i->CreateIteration(IterName, NomIterParent) ;
}
//=============================================================================
HOMARD::HOMARD_Iteration_ptr HOMARD_Cas_i::LastIteration( )
{
  HOMARD::HOMARD_Iteration_ptr Iter ;
  HOMARD::listeIterFilles_var ListeIterFilles ;
  char* IterName ;
// Iteration initiale du cas
  IterName = GetIter0Name() ;
// On va explorer la descendance de cette iteration initiale
// jusqu'a trouver celle qui n'a pas de filles
  int nbiterfilles = 1 ;
  while ( nbiterfilles == 1 )
  {
// L'iteration associee
//     MESSAGE ( ".. IterName = " << IterName );
    Iter = _gen_i->GetIteration(IterName) ;
// Les filles de cette iteration
    ListeIterFilles = Iter->GetIterations() ;
    nbiterfilles = ListeIterFilles->length() ;
//     MESSAGE ( ".. nbiterfilles = " << nbiterfilles );
// S'il y a au moins 2 filles, arret : on ne sait pas faire
    VERIFICATION( nbiterfilles <= 1 ) ;
// S'il y a une fille unique, on recupere le nom de la fille et on recommence
    if ( nbiterfilles == 1 )
    { IterName = ListeIterFilles[0] ; }
  }
//
  return Iter ;
}
//=============================================================================
void HOMARD_Cas_i::AddIteration( const char* NomIteration )
{
  ASSERT( myHomardCas );
  myHomardCas->AddIteration( NomIteration );
}
//=============================================================================
//=============================================================================
// YACS
//=============================================================================
//=============================================================================
//=============================================================================
// Creation d'un schema YACS
// YACSName : nom du schema
// ScriptFile : nom du fichier contenant le script de lancement du calcul
// DirName : le repertoire de lancement des calculs du sch?ma
// MeshFile : nom du fichier contenant le maillage pour le premier calcul
//=============================================================================
HOMARD::HOMARD_YACS_ptr HOMARD_Cas_i::CreateYACSSchema( const char* YACSName, const char* ScriptFile, const char* DirName, const char* MeshFile )
{
// Nom du cas
  const char* CaseName = GetName() ;
  MESSAGE ( "CreateYACSSchema : Schema YACS pour le cas " << YACSName);
  MESSAGE ( "nomCas     : " << CaseName);
  MESSAGE ( "ScriptFile : " << ScriptFile);
  MESSAGE ( "DirName    : " << DirName);
  MESSAGE ( "MeshFile   : " << MeshFile);
  return _gen_i->CreateYACSSchema(YACSName, CaseName, ScriptFile, DirName, MeshFile) ;
}
