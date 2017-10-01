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

#include "Serialization_input_Channel.h"

Serialization_input_Channel
::Serialization_input_Channel
(std::string const& filename)
:
_filename(filename)
,iss(filename, std::ios::binary)
,iarchive(iss)
{
}

Serialization_input_Channel
::~Serialization_input_Channel()
{
	this->close();
}

void
Serialization_input_Channel
::close
(){
	iss.close();
}


int 
Serialization_input_Channel
::receiveString
(int dbTag, int commitTag,  std::string &theString, ChannelAddress *theAddress){
	iarchive(theString);
	return 0;
}


int 
Serialization_input_Channel
::receiveDTensor1
(int dbTag, int commitTag,  DTensor1 &theTensor, ChannelAddress *theAddress){
	int read_sz;
	iarchive(read_sz);
	if(read_sz!=theTensor.dataCount){
	    std::cerr<<"ERROR!!! During restart, the read DTensor1 size is different from the allocated DTensor1 size. \n";
	    std::cerr<<"ERROR!!! Please allocated the correct DTensor1 size before receiveVector. \n";
	    exit(-1);
	}
	for (int i = 0; i < 1; ++i){iarchive(theTensor.size[i]);}
	for (int i = 0; i < 1; ++i){iarchive(theTensor.stride[i]);}
	// theTensor.data = new double[theTensor.dataCount];
	for (int i = 0; i < theTensor.dataCount; ++i){iarchive( *(theTensor.data + i) );}
	return 0;
}

int 
Serialization_input_Channel
::receiveDTensor2
(int dbTag, int commitTag,  DTensor2 &theTensor, ChannelAddress *theAddress){
	int read_sz;
	iarchive(read_sz);
	if(read_sz!=theTensor.dataCount){
	    std::cerr<<"ERROR!!! During restart, the read DTensor2 size is different from the allocated DTensor2 size. \n";
	    std::cerr<<"ERROR!!! Please allocated the correct DTensor2 size before receiveVector. \n";
	    exit(-1);
	}
	for (int i = 0; i < 2; ++i){iarchive(theTensor.size[i]);}
	for (int i = 0; i < 2; ++i){iarchive(theTensor.stride[i]);}
	// theTensor.data = new double[theTensor.dataCount];
	for (int i = 0; i < theTensor.dataCount; ++i){iarchive( *(theTensor.data + i) );}
	return 0;
}

int 
Serialization_input_Channel
::receiveDTensor3
(int dbTag, int commitTag,  DTensor3 &theTensor, ChannelAddress *theAddress){
	int read_sz;
	iarchive(read_sz);
	if(read_sz!=theTensor.dataCount){
	    std::cerr<<"ERROR!!! During restart, the read DTensor3 size is different from the allocated DTensor3 size. \n";
	    std::cerr<<"ERROR!!! Please allocated the correct DTensor3 size before receiveVector. \n";
	    exit(-1);
	}
	for (int i = 0; i < 3; ++i){iarchive(theTensor.size[i]);}
	for (int i = 0; i < 3; ++i){iarchive(theTensor.stride[i]);}
	// theTensor.data = new double[theTensor.dataCount];
	for (int i = 0; i < theTensor.dataCount; ++i){iarchive( *(theTensor.data + i) );}
	return 0;
}



int 
Serialization_input_Channel
::receiveDTensor4
(int dbTag, int commitTag,  DTensor4 &theTensor, ChannelAddress *theAddress){
	int read_sz;
	iarchive(read_sz);
	if(read_sz!=theTensor.dataCount){
	    std::cerr<<"ERROR!!! During restart, the read DTensor4 size is different from the allocated DTensor4 size. \n";
	    std::cerr<<"ERROR!!! Please allocated the correct DTensor4 size before receiveVector. \n";
	    exit(-1);
	}
	for (int i = 0; i < 4; ++i){iarchive(theTensor.size[i]);}
	for (int i = 0; i < 4; ++i){iarchive(theTensor.stride[i]);}
	// theTensor.data = new double[theTensor.dataCount];
	for (int i = 0; i < theTensor.dataCount; ++i){iarchive( *(theTensor.data + i) );}
	return 0;
}


int 
Serialization_input_Channel
::receiveObj
(int commitTag,  MovableObject &theObj, FEM_ObjectBroker &theBroker, ChannelAddress *theAddress){
	iarchive(theObj);
	return 0;
}

int 
Serialization_input_Channel
::receiveVector
(int dbTag, int commitTag,  Vector &theVector, ChannelAddress *theAddress){
	iarchive(theVector);
	return 0;
}

int 
Serialization_input_Channel
::receiveID
(int dbTag, int commitTag,  ID &theID, ChannelAddress *theAddress){
	iarchive(theID);
	return 0;
}

int 
Serialization_input_Channel
::receiveMatrix
(int dbTag, int commitTag,  Matrix &theMatrix, ChannelAddress *theAddress){
	iarchive(theMatrix);
	return 0;
}

int 
Serialization_input_Channel
::receiveMsg
(int dbTag, int commitTag,  Message &theMessage, ChannelAddress *theAddress){
	std::string tmp;
	iarchive(tmp);
	theMessage.setData(tmp.c_str(), tmp.size());
	
	string channel_msg(theMessage.getData(), theMessage.getSize());
	// std::cout<<"channel_msg is: " ;
	// std::cout<< channel_msg <<"\n";

	return 0;
}

