// #include "LTensor.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

vector<double> v1(6,0.) ;

// void test(){
// 	double cc{1.} ;
// 	v1[0] = cc;
// 	cout<< "v1[0] " << v1[0] <<endl<<endl;
// }

int main(void)
  {
 //  	vector<DTensor2> a(2, DTensor2(3,3,0.));
 //  	vector<DTensor2> converge_commit_alpha_vec(0) ;
 //  	cout<< a[0] <<endl;

 //  	int TNYS = 8 ;
 //  	cout<<"converge_commit_alpha_vec  " <<endl;
 //  	// b = vector<DTensor2>(2,DTensor2(3,3,0.));

 //  	converge_commit_alpha_vec = vector<DTensor2>(TNYS+1, DTensor2(3,3,0.));
	// double* pointer_test;
	// pointer_test = (double*)malloc(3 * sizeof(double));
 //  	cout<< "1step : " << converge_commit_alpha_vec[0] <<endl;
 //  	cout<< "2step : " << converge_commit_alpha_vec.size() <<endl;
 //  	delete pointer_test;

    vector<double>* test = new vector<double>(3,0.);
    (*test)[0] = 99 ;
    cout<<"test value "<< (*test)[0] <<endl;
    delete test; 
  //       Index<'i'> i;
  //       Index<'j'> j;
  //       Marray<double,1> q(2);
		// Marray<double,1> p(2);
		// Marray<double,2> A(2,2);
		// q(i)=A(i,j)*p(j);
		// cout<<q;
		// //p(i)=q(i)+p(i);
		// A(0,0) = 2.3;
		// A(0,1) = 3.3;
		// cout<<A(0,i);

		// p(i) = A(0,i);

		// vector<Marray<double,2> > tensor_vector(10) ;
		// tensor_vector.push_back(A);
		// // tensor_vector[1] = A;
		// cout<< "tensor_vector.size " << tensor_vector.size()<<endl;
		// cout<< "tensor_vector[0] " << tensor_vector[0]<<endl;
		// tensor_vector[0] = A;
		// cout<< "tensor_vector[0] " << tensor_vector[0]<<endl;


		// cout<<p;

		// std::vector<vector<double> > v(3,std::vector<double>(3,0.) ) ;
		// cout<<v[0][0] <<endl ;
		// v[0][2] = 6;
		// // std::vector<double> v1;
		// v1 = v[0]  ;

		// cout<<v1[2]<<endl ;

		// for (int ro = 0; ro < 3; ++ro)
		// {
		// 	fill(v[ro].begin(), v[ro].begin(), 0.);
		// }

		// for (int i = 0; i < 3; ++i)
		// {
		// 	test();
		// }


		// vector<double> radius{
		// 	2.7, 2.74, 2.8, 2.82, 2.85, 
	 //     	2.9, 3.0, 3.1,  3.25, 3.5, 
	 //     4.2, 5.3, 6.5, 7.5, 10.0, 12.65
		// };

		// cout<<radius[3]<<endl;

		// v = { { 1, 1, 1 },
  //             { 2, 2, 2 },
  //             { 2, 2, 2 } };

		return 0;
  }
