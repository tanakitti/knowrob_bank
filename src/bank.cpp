// STD
#include <iostream>
#include "include/header/Matrix4.h"
#include "include/header/Vec3.h"
#include "include/header/SphereTree.h"
#include "include/header/Matrix4.h"
#include "include/header/SphereNode.h"
#include "include/header/Bankhelper.h"
#include "include/header/test.h"
// ROS
// SWI prolog
#define PL_SAFE_ARG_MACROS
#include <SWI-cpp.h>
PREDICATE(createMesh, 1)
{ 
	std::cout << "Hello " << (char *)PL_A1 << std::endl;
  

	// register tooth
    	auto M = pd::Matrix4<float>::IDENTITY();
   	//test::registerIdealEnvIST("./../../../knowrob/knowrob_bank/src/input/framefull.log",1,M,1,"./../../../knowrob/knowrob_bank/src/input/framediff46.log");

        test::registerIdealEnvIST("./../../../knowrob_bank/src/input/0.log",1,M,1,(int)PL_A1*60);
    
    	// Dimentional Setting
    	Vec3<float> m_min( -90, -90, -90);
    	Vec3<float> m_max( 90, 90, 90);

    	Vec3<float> m_wd( m_max - m_min );
    	Vec3<float> m_d(  100,100,100 );
    	Vec3<float> m_df( m_d.x, m_d.y, m_d.z );
    	Vec3<float> m_cellDim( m_wd/m_df );
    	float *m_scalarFieldRaw = new float[(int)(m_d.x*m_d.y*m_d.z)];
    	Vec3<float> max(m_df);
    	Vec3<float> min( 0, 0, 0);
	
	
	// Compute ScalarField
    	test::cpukern_scalarField(m_min,m_max,m_wd,
                              m_cellDim, min, max, m_df,
                              m_scalarFieldRaw, true, test::g_idealEnvLeafCount, test::g_idealEnvLeafX,
                              test::g_idealEnvLeafY, test::g_idealEnvLeafZ, test::g_idealEnvLeafR,true);
    	
        int n = sizeof(m_scalarFieldRaw) / sizeof(m_scalarFieldRaw);
    	std::reverse(m_scalarFieldRaw,m_scalarFieldRaw+n);

    
        int N2 = 7/2;
        Vec3<float> lo( N2, N2, N2 );
        Vec3<float> hi( m_df.x-N2, m_df.y-N2, m_df.z-N2 );
        int m_padding = (7/2) + (7/2)*m_df.x + (7/2)*m_df.x*m_df.y;
    
        test::kern_scalarFieldProcess( m_min, m_max, m_wd, m_cellDim, min, max, m_df, m_scalarFieldRaw+m_padding, m_scalarFieldProcessed, N2, 3.5, 3.5);
        test::MarchCubes(m_scalarFieldProcessed,m_df,m_wd,m_wd);
    
        test::writeFile(test::m_gridToTriangles);
    
        test::convertObjtoDea();

        return TRUE;
};






