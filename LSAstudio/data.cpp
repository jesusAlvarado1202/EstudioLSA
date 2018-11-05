#include "data.h"
#include "cmath"
Data::Data(QObject *parent) : QObject(parent)
{

}

void Data::initilizeData(int vector_length)
{
    vframe.clear();
    vcode.clear();

    for (int i=0; i<vector_length; ++i)
    {
        vframe.push_back(i);
        vcode.push_back(0);

    }
}

void Data::manageData(int frame_rate,int filter_sz)
{

//    for(int i=0;i<vcode.size();i++)
//    {
//        cout<< vcode[i] << " ";
//    }

    vector<double> vcode_tmp;

    vmed_code.clear();
    vtable_med_code.clear();

    /*
    z1.resize(y1.size()/size);
    for(int i = 0; i < z1.size(); i++)
        z1[i].resize(2);
        */

    double score_tmp = 0;

    QVector<int> vtable_med_code_tmp;

    double score = 0;

    vcode1 = filterData(vcode,filter_sz);


    for(int i=0;i<vcode1.size()/frame_rate;i++)
    {

    vcode_tmp.assign(vcode1.begin()+(frame_rate*i), vcode1.begin()+(frame_rate*(i+1)));
    sort(vcode_tmp.begin(),vcode_tmp.end());
    if (vcode_tmp.size() % 2 == 0)
    {
          score = ceil((vcode_tmp[vcode_tmp.size() / 2 - 1] + vcode_tmp[vcode_tmp.size() / 2]) / 2);
    }
    else
    {
          score = vcode_tmp[vcode_tmp.size() / 2];
    }
    vcode_tmp.clear();

    vtable_med_code_tmp.resize(2);

    if(score_tmp != score)
    {
        vtable_med_code_tmp[0]=i;
        vtable_med_code_tmp[1]=score;
        vtable_med_code.push_back(vtable_med_code_tmp);
        score_tmp=score;
    }

    vtable_med_code_tmp.clear();

    for(int e=0;e<frame_rate;e++)
        vmed_code.push_back( ((score == 0)? std::numeric_limits<double>::quiet_NaN(): score ) );

    }

    if(vcode1.size() != vmed_code.size())
    {
        int difsize = abs(vcode.size() - vmed_code.size());
        vcode.erase(vcode.end()-( difsize ), vcode.end());
        vcode1.erase(vcode1.end()-( difsize ), vcode1.end());
        vframe.erase(vframe.end()-( difsize ), vframe.end());

    }

}


QVector<double> Data::filterData(QVector<double> vdata,int w_size)
{
    QVector<double> vdata_tmp;

    if(w_size != 0)
    {
    int sum_of_elems = 0;
    for(int i=0;i<vdata.size()-w_size;i++)
    {
    sum_of_elems = std::accumulate(vdata.begin()+i, vdata.begin()+i+w_size, 0);
    if(sum_of_elems>0)
        vdata_tmp.push_back(1);
    else
        vdata_tmp.push_back(0);
    }

    for(int i=vdata.size()-w_size;i<vdata.size();i++)
    {
        vdata_tmp.push_back(vdata.at(i));
    }

    return vdata_tmp;

    }

return vdata;

}
