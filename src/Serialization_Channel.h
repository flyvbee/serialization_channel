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

#pragma once

// #include <Channel.h>
#include <LTensor.h>
#include <MovableObject.h>
#include <Vector.h>
#include <ID.h>
#include <Matrix.h>
#include <Message.h>

#include <cereal/archives/binary.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <ChannelAddress.h>
#include <nDarray.h>
#include <FEM_ObjectBroker.h>

// class Serialization_Channel: public Channel
class Serialization_Channel
{
public:


public:
	Serialization_Channel();
	~Serialization_Channel();
	virtual void close()=0;
	
	// template <typename val_type>
	// virtual int send_single_POD(int dbTag, int commitTag, val_type val, ChannelAddress* theAddress = 0 );
	// template <typename val_type>
	// virtual int receive_single_POD(int dbTag, int commitTag, val_type val, ChannelAddress* theAddress = 0 ) ;

	// template <typename val_type>
	// virtual int send_std_vector(int dbTag, int commitTag, const std::vector<val_type> & theVector, ChannelAddress* theAddress = 0) ;
	// template <typename val_type>
	// virtual int receive_std_vector(int dbTag, int commitTag, std::vector<val_type> & theVector, ChannelAddress* theAddress = 0) ;

	virtual int sendString(int dbTag, int commitTag,  const std::string &theString, ChannelAddress* theAddress = 0);
	virtual int receiveString(int dbTag, int commitTag,  std::string &theString, ChannelAddress* theAddress = 0);

	virtual int sendDTensor1(int dbTag, int commitTag,  const DTensor1 &theTensor, ChannelAddress* theAddress = 0);
	virtual int receiveDTensor1(int dbTag, int commitTag,  DTensor1 &theTensor, ChannelAddress* theAddress = 0);

	virtual int sendDTensor2(int dbTag, int commitTag,  const DTensor2 &theTensor, ChannelAddress* theAddress = 0);
	virtual int receiveDTensor2(int dbTag, int commitTag,  DTensor2 &theTensor, ChannelAddress* theAddress = 0);

	virtual int sendDTensor3(int dbTag, int commitTag,  const DTensor3 &theTensor, ChannelAddress* theAddress = 0);
	virtual int receiveDTensor3(int dbTag, int commitTag,  DTensor3 &theTensor, ChannelAddress* theAddress = 0);

	virtual int sendDTensor4(int dbTag, int commitTag,  const DTensor4 &theTensor, ChannelAddress* theAddress = 0);
	virtual int receiveDTensor4(int dbTag, int commitTag,  DTensor4 &theTensor, ChannelAddress* theAddress = 0);

	virtual int sendObj(int commitTag,  MovableObject &theObj, ChannelAddress* theAddress = 0);
	virtual int receiveObj(int commitTag,  MovableObject &theObj, FEM_ObjectBroker &theBroker, ChannelAddress* theAddress = 0);

	virtual int sendVector(int dbTag, int commitTag, const Vector& theVector, ChannelAddress* theAddress = 0);
	virtual int receiveVector(int dbTag, int commitTag, Vector& theVector, ChannelAddress* theAddress = 0);

	virtual int sendID(int dbTag, int commitTag, const ID& theID, ChannelAddress* theAddress = 0);
	virtual int receiveID(int dbTag, int commitTag, ID& theID, ChannelAddress* theAddress = 0);

	virtual int sendMatrix(int dbTag, int commitTag, const Matrix& theMatrix, ChannelAddress* theAddress = 0);
	virtual int receiveMatrix(int dbTag, int commitTag, Matrix& theMatrix, ChannelAddress* theAddress = 0);

	virtual int sendMsg(int dbTag, int commitTag, const Message& theMessage, ChannelAddress* theAddress = 0);
	virtual int receiveMsg(int dbTag, int commitTag, Message& theMessage, ChannelAddress* theAddress = 0);

	int sendnDarray(int dbTag, int commitTag, const nDarray &theNDarray, ChannelAddress* theAddress = 0);
	int receivenDarray(int dbTag, int commitTag, nDarray &theNDarray, ChannelAddress* theAddress = 0);

	char* addToProgram();
	int setUpConnection();
	ChannelAddress* getLastSendersAddress();
	int setNextAddress(const ChannelAddress& otherChannelAddress);
};