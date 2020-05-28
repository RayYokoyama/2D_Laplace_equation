#include"hedder.hpp"
using namespace std;

void Laplace::Output(int count){
    struct stat st;
    const char* dir = "../../output";
    int ret = stat(dir, &st);
    if(ret !=0) {
        mkdir(dir,S_IRWXG | S_IRWXU | S_IRWXO);
    }

    stringstream filename;
    filename << "pressure" << count << ".vtk";
    string result = "../../output/"+filename.str();
    ofstream output;
    output.open(result.c_str());
    output << "# vtk DataFile Version 3.0" << endl;
    output << "vtk output" << endl;
    output << "ASCII" << endl;
    output << "DATASET STRUCTURED_POINTS" << endl;
    output << "DIMENSIONS " << N << " " << N << " " << 1 << endl;
    output << "ORIGIN " << 0.0 << " " << 0.0 << " " <<0.0 << endl;
    output << "SPACING " << dx << " " << dy << " " << 0 << endl;
    output << "POINT_DATA " << N*N << endl;
    output << "SCALARS " << "pressure " << "double" << endl;
    output << "LOOKUP_TABLE " << "default" << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            output << setprecision(5) << p[i][j] << endl;
        }
    }
    output.close();            
}
