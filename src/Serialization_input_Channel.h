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
#include "Serialization_Channel.h"

class Serialization_input_Channel: public Serialization_Channel
{
public:
	std::string _filename;
	std::ifstream iss ; 
	cereal::BinaryInputArchive iarchive;


public:
	Serialization_input_Channel(std::string const& filename);
	~Serialization_input_Channel();
	void close() final;

	template <typename val_type>
	int receive_single_POD(int dbTag, int commitTag, val_type& val, ChannelAddress* theAddress = 0 ){
		iarchive(val);
		return 0;
	}

	template <typename val_type>
	int receive_std_vector(int dbTag, int commitTag, std::vector<val_type> & theVector, ChannelAddress* theAddress = 0){
		iarchive(theVector);
		return 0;
	}

	int receiveString(int dbTag, int commitTag,  std::string &theString, ChannelAddress* theAddress = 0) final;
	int receiveDTensor1(int dbTag, int commitTag,  DTensor1 &theTensor, ChannelAddress* theAddress = 0) final;
	int receiveDTensor2(int dbTag, int commitTag,  DTensor2 &theTensor, ChannelAddress* theAddress = 0) final;
	int receiveDTensor3(int dbTag, int commitTag,  DTensor3 &theTensor, ChannelAddress* theAddress = 0) final;
	int receiveDTensor4(int dbTag, int commitTag,  DTensor4 &theTensor, ChannelAddress* theAddress = 0) final;
	int receiveObj(int commitTag,  MovableObject &theObj, FEM_ObjectBroker &theBroker, ChannelAddress* theAddress = 0) final;
	int receiveVector(int dbTag, int commitTag, Vector& theVector, ChannelAddress* theAddress = 0) final;
	int receiveID(int dbTag, int commitTag, ID& theID, ChannelAddress* theAddress = 0) final;
	int receiveMatrix(int dbTag, int commitTag, Matrix& theMatrix, ChannelAddress* theAddress = 0) final;
	int receiveMsg(int dbTag, int commitTag, Message& theMessage, ChannelAddress* theAddress = 0) final;

};