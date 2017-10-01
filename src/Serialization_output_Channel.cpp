/////////////////////////////////////////////////////////////////////////////
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

#include "Serialization_output_Channel.h"

Serialization_output_Channel
::Serialization_output_Channel
(std::string const& filename)
:
_filename(filename)
,oss(filename, std::ios::binary)
,oarchive(oss)
{
}

Serialization_output_Channel
::~Serialization_output_Channel()
{
	this->close();
}

void
Serialization_output_Channel
::close
(){
	oss.close();
}

int 
Serialization_output_Channel
::sendString
(int dbTag, int commitTag,  const std::string &theString, ChannelAddress *theAddress){
	oarchive(theString);
	return 0;
}

int 
Serialization_output_Channel
::sendDTensor1
(int dbTag, int commitTag,  const DTensor1 &theTensor, ChannelAddress *theAddress){
	oarchive(theTensor.dataCount);
	for (int i = 0; i < 1; ++i){oarchive(theTensor.size[i]);}
	for (int i = 0; i < 1; ++i){oarchive(theTensor.stride[i]);}
	for (int i = 0; i < theTensor.dataCount; ++i){oarchive( *(theTensor.data + i) );}
	return 0;
}

int 
Serialization_output_Channel
::sendDTensor2
(int dbTag, int commitTag,  const DTensor2 &theTensor, ChannelAddress *theAddress){
	oarchive(theTensor.dataCount);
	for (int i = 0; i < 2; ++i){oarchive(theTensor.size[i]);}
	for (int i = 0; i < 2; ++i){oarchive(theTensor.stride[i]);}
	for (int i = 0; i < theTensor.dataCount; ++i){oarchive( *(theTensor.data + i) );}
	return 0;
}

int 
Serialization_output_Channel
::sendDTensor3
(int dbTag, int commitTag,  const DTensor3 &theTensor, ChannelAddress *theAddress){
	oarchive(theTensor.dataCount);
	for (int i = 0; i < 3; ++i){oarchive(theTensor.size[i]);}
	for (int i = 0; i < 3; ++i){oarchive(theTensor.stride[i]);}
	for (int i = 0; i < theTensor.dataCount; ++i){oarchive( *(theTensor.data + i) );}
	return 0;
}

int 
Serialization_output_Channel
::sendDTensor4
(int dbTag, int commitTag,  const DTensor4 &theTensor, ChannelAddress *theAddress){
	oarchive(theTensor.dataCount);
	for (int i = 0; i < 4; ++i){oarchive(theTensor.size[i]);}
	for (int i = 0; i < 4; ++i){oarchive(theTensor.stride[i]);}
	for (int i = 0; i < theTensor.dataCount; ++i){oarchive( *(theTensor.data + i) );}
	return 0;
}

int 
Serialization_output_Channel
::sendObj
(int commitTag, MovableObject &theObj, ChannelAddress *theAddress){
	oarchive(theObj);
	return 0;
}

int 
Serialization_output_Channel
::sendVector
(int dbTag, int commitTag,  const Vector &theVector, ChannelAddress *theAddress){
	oarchive(theVector);
	return 0;
}

int 
Serialization_output_Channel
::sendID
(int dbTag, int commitTag,  const ID &theID, ChannelAddress *theAddress){
	oarchive(theID);
	return 0;
}

int 
Serialization_output_Channel
::sendMatrix
(int dbTag, int commitTag,  const Matrix &theMatrix, ChannelAddress *theAddress){
	oarchive(theMatrix);
	return 0;
}

int 
Serialization_output_Channel
::sendMsg
(int dbTag, int commitTag,  const Message &theMessage, ChannelAddress *theAddress){
	std::string tmp(theMessage.getData() , theMessage.getSize());
	oarchive(tmp);
	return 0;
}
