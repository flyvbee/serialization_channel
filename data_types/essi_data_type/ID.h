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

// $Revision: 1.8 $
// $Date: 2004/04/12 19:11:51 $
// $Source: /usr/local/cvs/OpenSees/SRC/matrix/ID.h,v $


// Written: fmk
// Revision: A
//
// Description: This file contains the class definition for ID.
// ID is a concrete class implementing the integer array abstraction.
// ID objects are Vectors of integers which only need a few
// operators defined on them.
//
// What: "@(#) ID.h, revA"


#ifndef ID_h
#define ID_h

// #include <OPS_Globals.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h>

using namespace std;


class ID: public vector<int>
{
public:
    // constructors and destructor
    ID();
    ID(int);
    ID(int size, int arraySize, int fillValue = 0);
    ID(int *data, int size, bool cleanIt = false);
    // ID(const ID &);
    // ~ID();

    // utility methods
    int Size(void) const;
    void Zero(void);
    int setData(int *newData, int size, bool cleanIt = false);
    // int resize(int newSize);
    const int *getData() const;


    // overloaded operators
    inline int &operator()(int x);
    inline int operator()(int x) const;
    int &operator[](int);

    // ID &operator=(const ID  &V);
    // bool operator==(const ID &rhs) const;


    int getLocation(int value) const;
    int removeValue(int value);

    //        friend ostream& operator<<(ostream& s, const ID& V);
    friend ostream &operator<<(ostream &s, const ID &V);
    //    friend istream &operator>>(istream &s, ID &V);

    // friend class UDP_Socket;
    // friend class TCP_Socket;
    // // friend class TCP_SocketNoDelay;
    // friend class MPI_Channel;
    // friend class OutputWriter;
    // friend class H5OutputWriter;
    // friend class MySqlDatastore;
    // friend class MySqlDataRecorder;
    // friend class BerkeleyDbDatastore;

    // template<typename Archive>
    // void save(Archive& archive) const{
    //     archive(sz);
    //     archive(arraySize);
    //     archive(fromFree);
    //     for (int i = 0; i < arraySize; ++i){
    //         archive(*(data+i));
    //     }
    // }
    // template<typename Archive>
    // void load(Archive& archive) {
    //     int read_sz;
    //     archive(read_sz);
    //     if(read_sz!=sz){
    //         std::cerr<<"ERROR!!! During restart, the read ID size is different from the allocated ID size. \n";
    //         std::cerr<<"ERROR!!! Please allocated the correct ID size before receiveVector. \n";
    //         exit(-1);
    //     }

    //     archive(arraySize);
    //     archive(fromFree);
        
    //     for (int i = 0; i < arraySize; ++i){
    //         archive(*(data+i));
    //     }
    // }

private:
    // int *data;
    // static int ID_NOT_VALID_ENTRY;
    // int sz;
    // int arraySize;
    // int fromFree;
};


inline int
ID::Size(void) const
{
    return this->size() ;
}

inline int &
ID::operator()(int x)
{
// #ifdef _G3DEBUG
    // cout<<"x            = " << x <<endl;
    // cout<<"this->size() = " << this->size() <<endl;
    // cout<<"(*this)[x]   = " << (*this)[x] <<endl;
    // check if it is inside range [0,sz-1]
    if (x < 0 || x >= (int)(this->size()))
    {
        std::cerr << "ID::(loc) - loc " << x << " outside range 0 - " <<  this->size() - 1 << endl;
    }

// #endif


    return *((this->begin()) + x) ;
}

inline int
ID::operator()(int x) const
{
    //#ifdef _G3DEBUG
    // check if it is inside range [0,sz-1]
    if (x < 0 || x >= (int)(this->size()))
    {
        cerr << "ID::(loc) - loc " << x << " outside range 0 - " <<  this->size() - 1 << endl;
        return 0;
    }

    //#endif

    return *((this->cbegin()) + x) ;
}

inline const int *ID::getData() const
{
    return  &(*(this->cbegin())) ;
}


#endif


