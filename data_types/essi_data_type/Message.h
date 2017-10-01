/* ****************************************************************** **
**    OpenSees - Open System for Earthquake Engineering Simulation    **
**          Pacific Earthquake Engineering Research Center            **
**                                                                    **
**                                                                    **
** (C) Copyright 1999, The Regents of the University of California    **
** All Rights Reserved.                                               **
**                                                                    **
** Commercial use of this program without express permission of the   **
** University of California, Berkeley, is strictly prohibited.  See   **
** file 'COPYRIGHT'  in main directory for information on usage and   **
** redistribution,  and for a DISCLAIMER OF ALL WARRANTIES.           **
**                                                                    **
** Developed by:                                                      **
**   Frank McKenna (fmckenna@ce.berkeley.edu)                         **
**   Gregory L. Fenves (fenves@ce.berkeley.edu)                       **
**   Filip C. Filippou (filippou@ce.berkeley.edu)                     **
**                                                                    **
** ****************************************************************** */

// $Revision: 1.1.1.1 $
// $Date: 2000/09/15 08:23:16 $
// $Source: /usr/local/cvs/OpenSees/SRC/actor/message/Message.h,v $


// File: ~/actor/Message.h
//
// Written: fmk 11/96
// Revised:
//
// Purpose: This file contains the class definition for Message.

#ifndef Message_h
#define Message_h
#include <string>
#include <iostream>
class Message
{
    public:
        Message();
        Message(double*, int);
        Message(int*, int);
        Message(char*, int);
        virtual ~Message();

        virtual int putData(char* theData, int startLoc, int endLoc);
        virtual char* getData(void) const;
        virtual int getSize(void) const;
        // virtual int setSize(int );
        virtual int setData(const char* data_, int len_);
        // friend class TCP_Socket;
        // friend class TCP_SocketNoDelay;
        // friend class UDP_Socket;
        // friend class MPI_Channel;

        // template<typename Archive>
        // void save(Archive& archive) const{
        //     std::string tmp(data, length);
        //     archive(tmp);
        // }

        // template<typename Archive>
        // void load(Archive& archive) {
        //     std::string tmp;
        //     archive(tmp);
        //     std::cout<<"load msg is: " << tmp <<"\n";
        //     data   = const_cast<char*>( tmp.c_str() ) ;
        //     // data   = tmp.c_str()  ;
        //     length = tmp.size() ;

        //     std::string tran_msg(data, length);
        //     std::cout<<"tran_msg is: ";
        //     std::cout<< tran_msg <<"\n";
        // }

    private:
        int length;
        char* data;
};

#endif
    // Message msg1( const_cast<char*>(str.c_str()), str.size());