#include"hedder.hpp"
using namespace std;

void Laplas::Output(int count){
    stringstream filename;
    filename << "pressure" << count << ".vtp";
    string result = "../../output/"+filename.str();
    ofstream output;
    output.open(result.c_str());
    output << "# vtk DataFile Version 3.0" << endl;
    output << "vtk output" << endl;
    output << "ASCII" << endl;
    output << "DATASET STRUCTURED_POINTS" << endl;
    output << "DIMENSIONS " << N << " " << N << endl;
    output << "ORIGIN " << 0.0 << " " << 0.0 << endl;
    output << "SPACING " << dx << " " << dy << endl;
    output << "POINT_DATA " << N*N << endl;
    output << "SCALARS " << "pressure " << "double" << endl;
    output << "LOOKUP_TABLE " << "default" << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            output << p[i][j] << endl;
        }
    }
    output.close();            
}