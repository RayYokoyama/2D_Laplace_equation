#include"hedder.hpp"
using namespace std;

int main()
{
    Laplace DS;
    int count=0;
    while(1){
        DS.GaussZider();

        DS.NeumannCondition();
        
        if(count%500==0){
            DS.Output(count/500);
        }

        DS.Initialize();
        if(DS.ConvergenceJudge()){
            break;
        }
        count++;
    }
}
