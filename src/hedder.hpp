#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<cmath>
#include <iomanip>

class Laplas
{
    private:
        const int N=100;
        std::vector<std::vector<double>> p;
        double dt;
        double lx;
        double ly;
        double dx;
        double dy;
        double k;
        double sum;
        double memory;
    public:
        Laplas(){
            p.resize(N, std::vector<double>(N));
            p[N/2][N/2]=1.0;
            dt=0.001;
            lx=100.0;
            ly=100.0;
            dx=lx/(N-1);
            dy=ly/(N-1);
            k=dt/(dx*dx);
            sum=0.0;
            memory=0.0;
        }

        void GaussZider(){
            for(int i=1; i<N-1; i++){
                for(int j=1; j<N-1; j++){
                    p[i][j]=p[i][j]+k*(p[i+1][j]-4*p[i][j]+p[i-1][j]+p[i][j+1]+p[i][j-1]);
                }
            }
        }

        void NeumannCondition(){
            for(int i=0; i<N; i++){
                p[0][i]=p[1][i];
                p[N-1][i]=p[N-2][i];
                p[i][0]=p[i][1];
                p[i][N-1]=p[i][N-2];
            }
        }

        void Initialize(){
            p[N/2][N/2]=1.0;
        }

        bool ConvergenceJudge(){
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    sum+=p[i][j];
                }
            }
            
            std:: cout << fabs(memory-sum) << std::endl;
            if(double(fabs(memory-sum))<0.002){
                return true;
            }
            else{
                memory=sum;
                sum=0.0;
                return false;
            }
        }
        void Output(int count);
};