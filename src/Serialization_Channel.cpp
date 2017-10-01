///////////////////////////////////////////////////////////////////////////////
//
// COPYRIGHT (C):      Version of a Creative Commons License,
//                     for details contact Boris Jeremic, jeremic@ucdavis.edu
// PROJECT:            Real ESSI Simulator
// PROGRAMMER:         Yuan Feng and Boris Jeremic 
// DATE:               Sep. 2017
// UPDATE HISTORY:     Full update history in git repository.
// QUALITY ASSURANCE:  Developers have worked really hard to develop
//                     an extensive verification of developed implementation
//                     and with that can claim quality and fitness for intended
//                     purpose (modeling and simulation of Real ESSI Problems)
//                     within confines of verification effort
//
// LEGACY/DEFUNCT COPYLEFT (C):
//                     Woody's viral GPL-like license (adapted by BJ):
//                     ``This    source  code is Copyrighted in
//                     worldwide for  an  indefinite  period,  and anybody
//                     caught  using it without our permission, will be
//                     mighty good friends of ourn, cause we don't give
//                     a  darn.  Hack it. Compile it. Debug it. Run it.
//                     Yodel  it.  Enjoy it. We wrote it, that's all we
//                     wanted to do.''
//
/////////////////////////////////////////////////////////////////////////////

#include "Serialization_Channel.h"

Serialization_Channel
::Serialization_Channel
()
{
}

Serialization_Channel
::~Serialization_Channel()
{
}


int 
Serialization_Channel
::sendString
(int dbTag, int commitTag,  const std::string &theString, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::sendString should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::receiveString
(int dbTag, int commitTag,  std::string &theString, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::receiveString should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::sendDTensor1
(int dbTag, int commitTag,  const DTensor1 &theTensor, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::sendDTensor1 should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::receiveDTensor1
(int dbTag, int commitTag,  DTensor1 &theTensor, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::receiveDTensor1 should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::sendDTensor2
(int dbTag, int commitTag,  const DTensor2 &theTensor, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::sendDTensor2 should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::receiveDTensor2
(int dbTag, int commitTag,  DTensor2 &theTensor, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::receiveDTensor2 should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::sendDTensor3
(int dbTag, int commitTag,  const DTensor3 &theTensor, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::sendDTensor3 should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::receiveDTensor3
(int dbTag, int commitTag,  DTensor3 &theTensor, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::receiveDTensor3 should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::sendDTensor4
(int dbTag, int commitTag,  const DTensor4 &theTensor, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::sendDTensor4 should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::receiveDTensor4
(int dbTag, int commitTag,  DTensor4 &theTensor, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::receiveDTensor4 should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::sendObj
(int commitTag, MovableObject &theObj, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::sendObj should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::receiveObj
(int commitTag,  MovableObject &theObj, FEM_ObjectBroker &theBroker, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::receiveObj should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::sendVector
(int dbTag, int commitTag,  const Vector &theVector, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::sendVector should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::receiveVector
(int dbTag, int commitTag,  Vector &theVector, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::receiveVector should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::sendID
(int dbTag, int commitTag,  const ID &theID, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::sendID should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::receiveID
(int dbTag, int commitTag,  ID &theID, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::receiveID should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::sendMatrix
(int dbTag, int commitTag,  const Matrix &theMatrix, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::sendMatrix should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::receiveMatrix
(int dbTag, int commitTag,  Matrix &theMatrix, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::receiveMatrix should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::sendMsg
(int dbTag, int commitTag,  const Message &theMessage, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::sendMsg should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int 
Serialization_Channel
::receiveMsg
(int dbTag, int commitTag,  Message &theMessage, ChannelAddress *theAddress){
	std::cerr<<"Serialization_Channel::::receiveMsg should not be called!\n";
	std::cerr<<"subclass responsibility!\n";
	return -1;
}

int Serialization_Channel
::sendnDarray
(int dbTag, int commitTag, const nDarray &theNDarray, ChannelAddress *theAddress){
	return -1;
}
int Serialization_Channel
::receivenDarray
(int dbTag, int commitTag, nDarray &theNDarray, ChannelAddress *theAddress){
	return -1;
}

char *
Serialization_Channel
::addToProgram
(){
    cerr << "Serialization_Channel::addToProgram() - ";
    cerr << "should not be called \n";
    // char *newStuff = (char *)malloc(10 * sizeof(char));
    // for (int i = 0; i < 10; i++)
    // {
    //     newStuff[i] = ' ';
    // }
    return nullptr ;
}

int
Serialization_Channel
::setUpConnection
(){
	cerr << "Serialization_Channel::setUpConnection() - ";
	cerr << "should not be called \n";
    return -1;
}
ChannelAddress *
Serialization_Channel
::getLastSendersAddress
(){
    cerr << "Serialization_Channel::getLastSendersAddress() - ";
    cerr << "should not be called \n";
    return nullptr;
}

int
Serialization_Channel
::setNextAddress
(const ChannelAddress &theAddress){
	cerr << "Serialization_Channel::setNextAddress(const ChannelAddress &theAddress) - ";
	cerr << "should not be called \n";
    return -1;
}