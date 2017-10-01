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

class Serialization_output_Channel: public Serialization_Channel
{
public:
	std::string _filename;
	std::ofstream oss ;  
	cereal::BinaryOutputArchive oarchive;

public:
	Serialization_output_Channel(std::string const& filename);
	~Serialization_output_Channel();
	void close() final;

	template <typename val_type>
	int send_single_POD(int dbTag, int commitTag, val_type& val, ChannelAddress* theAddress = 0 ){
		oarchive(val);
		return 0;
	}

	template <typename val_type>
	int send_std_vector(int dbTag, int commitTag, const std::vector<val_type> & theVector, ChannelAddress* theAddress = 0) {
		oarchive(theVector);
		return 0;
	}

	int sendString(int dbTag, int commitTag,  const std::string &theString, ChannelAddress* theAddress = 0) final;
	int sendDTensor1(int dbTag, int commitTag,  const DTensor1 &theTensor, ChannelAddress* theAddress = 0) final;
	int sendDTensor2(int dbTag, int commitTag,  const DTensor2 &theTensor, ChannelAddress* theAddress = 0) final;
	int sendDTensor3(int dbTag, int commitTag,  const DTensor3 &theTensor, ChannelAddress* theAddress = 0) final;
	int sendDTensor4(int dbTag, int commitTag,  const DTensor4 &theTensor, ChannelAddress* theAddress = 0) final;
	int sendObj(int commitTag,  MovableObject &theObj, ChannelAddress* theAddress = 0) final;
	int sendVector(int dbTag, int commitTag, const Vector& theVector, ChannelAddress* theAddress = 0) final;
	int sendID(int dbTag, int commitTag, const ID& theID, ChannelAddress* theAddress = 0) final;
	int sendMatrix(int dbTag, int commitTag, const Matrix& theMatrix, ChannelAddress* theAddress = 0) final;
	int sendMsg(int dbTag, int commitTag, const Message& theMessage, ChannelAddress* theAddress = 0) final;

};